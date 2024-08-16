
Wi-Fi Signaling Test
==============================

:link_to_translation:`zh_CN:[中文]`

The Wi-Fi Signaling Test is used to evaluate and verify the Wi-Fi signaling function of wireless network devices, mainly to ensure that the device can communicate stably and reliably in various operating environments. The Wi-Fi Signaling Test is commonly used for the OTA (Over-The-Air) performance evaluation of devices, including TRP (Total Radiated Power) and TIS (Total Isotropic Sensitivity) tests.

Setting Up the Test Environment
-------------------------------

.. figure:: ../../../_static/rf_test_tool/usb_to_uart_connection.png
    :align: center
    :scale: 80%

    UART Connection Description

The **Device Under Test (DUT)** is a product designed based on Espressif chips or modules. The device under test is connected to the USB-to-UART adapter board via UART.

.. note::

    - The CHIP_EN pin of the device under test is pulled up by default. If it is not pulled high in the product design, you need to manually connect the CHIP_EN to the 3V3 pin.
    - Some serial communication boards have already swapped RXD and TXD internally, so there is no need to reverse the connection. The wiring should be adjusted according to the actual situation.
    - Espressif chips have a power-on self-calibration function, so the RF connection line must be connected to the test instrument before the device under test is powered on for testing.

Firmware Burning
------------------

{IDF_TARGET_WIFI_SIGNALLING_SINGLE_FIRMWARE:default="Not updated", esp32="`ESP32 Wi-Fi Signaling Test Firmware (Single Country) <https://dl.espressif.com/rf/esp32/ESP32ECO3_Signaling_V4.3_SinglePhy_20230525.zip>`_", esp32c2="`ESP32-C2 Wi-Fi Signaling Test Firmware (Single Country) <https://dl.espressif.com/rf/esp32c2/ESP32C2_v5.2_ae9dde6_SinglePhy_20240416.zip>`_", esp32c3="`ESP32-C3 Wi-Fi Signaling Test Firmware (Single Country) <https://dl.espressif.com/rf/esp32c3/ESP32C3_V4.3_891217b_SinglePhy_20220627.zip>`_"}

{IDF_TARGET_WIFI_SIGNALLING_MULTIPLE_FIRMWARE:default="Not updated", esp32="`ESP32 Wi-Fi Signaling Test Firmware (Multiple Countries) <https://dl.espressif.com/rf/esp32/ESP32ECO3_Signaling_V4.3_MultiPhy_20230525.zip>`_", esp32c2="`ESP32-C2 Wi-Fi Signaling Test Firmware (Multiple Countries) <https://dl.espressif.com/rf/esp32c2/ESP32C2_v5.2_ae9dde6_MultiplePhy_20240416.zip>`_", esp32c3="`ESP32-C3 Wi-Fi Signaling Test Firmware (Multiple Countries) <https://dl.espressif.com/rf/esp32c3/ESP32C3_V4.3_891217b_MultiPhy_20220627.zip>`_"}

{IDF_TARGET_FLASH_ADDRESS:default="0x0", esp32="0x1000", esp32s2="0x1000"}

1. Open the DownloadTool tool.

2. Set the ChipType, Com Port, Baud Rate, click Open, and select to download to flash.

3. {IDF_TARGET_WIFI_SIGNALLING_SINGLE_FIRMWARE} supports a single country code, {IDF_TARGET_WIFI_SIGNALLING_MULTIPLE_FIRMWARE} supports multiple country codes. They each include **bootloader.bin**, **partition-table.bin**, **phy_init_data.bin**, and **ssc.bin** 4 bin files. After unzipping {IDF_TARGET_WIFI_SIGNALLING_SINGLE_FIRMWARE} or {IDF_TARGET_WIFI_SIGNALLING_MULTIPLE_FIRMWARE}, burn the 4 bin files to the following addresses via UART.

.. list-table::
   :header-rows: 1

   * - bin file
     - Burn address
   * - bootloader.bin
     - {IDF_TARGET_FLASH_ADDRESS}
   * - partition-table.bin
     - 0x8000
   * - phy_init_data.bin
     - 0xF000
   * - ssc.bin
     - 0x10000

After the burning is completed, continue the following steps for the signaling test.

.. _wifi-signalling-test:

Start the test
---------------

View the power-on print
^^^^^^^^^^^^^^^^^^^^^^^

Use a serial communication tool, such as `Friendly Serial Assistant <http://alithon.com/downloads>`_, configure the port number, set the baud rate to 115200, if the serial port prints similar information after the device to be tested is powered on again, you can confirm that the test status is OK:

.. figure:: ../../../_static/rf_test_tool/esp32c2_wifi_signaling.png
    :align: center
    :scale: 80%

    Device power-on serial port print log

Device networking
^^^^^^^^^^^^^^^^^^^^^

Enter the following two commands in the serial port in turn to complete the networking. The first command is to configure the prototype to enter station mode:

::

  \\Device networking
  \\Configure the prototype to enter station mode
  op -S -o 1

  \\Connect to AP, SSID is CMW-AP, password is 12345678
  sta -C -s CMW-AP -p 12345678

.. note::

    The ``-p`` parameter is used to set the AP password. If the AP has no password, this parameter is not needed.

After the station device is assigned an IP address, it indicates that the Wi-Fi connection is successful, and the following log will be printed:

.. figure:: ../../../_static/rf_test_tool/esp32c2_wifi_signaling_connection.png
    :align: center
    :scale: 80%

    Device networking serial port print log

After the device to be tested is successfully networked, you can use the RF test instrument for Wi-Fi signaling test.

.. note::

  In addition to routers, common AP devices' RF test instruments are usually CMW500 or CMW270.
