Set Up Test Environment
-----------------------

.. figure:: ../../../_static/rf_test_tool/usb_to_uart_connection.png
    :align: center
    :scale: 80%

    UART Connection Description

The **Device Under Test (DUT)** is a product designed based on Espressif chips or modules. The DUT is connected to the USB-to-UART adapter board via UART.

.. note::

    - The CHIP_EN pin of the DUT is pulled up by default. If it is not pulled up in the product design, you need to manually connect the CHIP_EN to the 3V3 pin.
    - Some serial communication boards have already swapped RXD and TXD internally, so there is no need to reverse them. The wiring should be adjusted according to the actual situation.
    - Espressif chips have a power-on self-calibration function, so the RF connection line must be connected to the test instrument before the DUT is powered on for testing.

Flash Firmware
--------------

{IDF_TARGET_WIFI_BLOCKING_ADAPTIVITY_FIRMWARE:default="Contact Espressif for the latest firmware", esp32="|ESP32 Wi-Fi Adaptivity Test/Blocking Test Firmware|", esp32c2="|ESP32-C2 Wi-Fi Adaptivity Test/Blocking Test Firmware (26 MHz) or ESP32-C2 Wi-Fi Adaptivity Test/Blocking Test Firmware (40 MHz)|", esp32c3="|ESP32-C3 Wi-Fi Adaptivity Test/Blocking Test Firmware|", esp32c6="|ESP32-C6 Wi-Fi Adaptivity Test/Blocking Test Firmware|", esp32s2="|ESP32-S2 Wi-Fi Adaptivity Test/Blocking Test Firmware|", esp32s3="|ESP32-S3 Wi-Fi Adaptivity Test/Blocking Test Firmware|", esp8266="|ES8266 Wi-Fi Adaptivity Test/Blocking Test Firmware|"}

{IDF_TARGET_FLASH_ADDRESS:default="0x0", esp32="0x1000", esp32s2="0x1000", esp32c5="0x2000"}

1. Open :ref:`download-tool`.

2. Set ``ChipType``, ``Com Port``, ``Baud Rate``, click ``Open``, select to download to ``Flash``.

3. Flash {IDF_TARGET_WIFI_BLOCKING_ADAPTIVITY_FIRMWARE} to {IDF_TARGET_FLASH_ADDRESS} via ``UART``.

.. only:: esp32 or esp32s2

    .. figure:: ../../../_static/rf_test_tool/wifi_adaptivity_blocking_firmware_esp32_esp32s2.png
        :align: center
        :scale: 80%

        Flashing Firmware

.. only:: not esp32 and not esp32s2

    .. figure:: ../../../_static/rf_test_tool/wifi_adaptivity_blocking_firmware_others.png
        :align: center
        :scale: 80%

        Flashing Firmware

After the flashing is completed, continue with the following steps for the adaptivity test.

Start Testing
-------------

.. note::

    .. only:: esp8266 or esp32c2

        If the main crystal oscillator is 26 MHz, set ``BaudRate`` to 74880; if the main crystal oscillator is 40 MHz, set ``BaudRate`` to 115200.

    .. only:: not esp32c2 and not esp8266

        Set ``BaudRate`` to 115200.

Check Power-on log
^^^^^^^^^^^^^^^^^^

Use a serial communication tool, such as `SerialPortUtility <http://alithon.com/downloads>`__, and configure the port number and the baud rate. If the device under test prints similar information as below after being powered on again, you can confirm that the test status is OK:

.. figure:: ../../../_static/rf_test_tool/esp32c2_wifi_signaling.png
    :align: center
    :scale: 80%

    Device Power-on Serial Port Print Log

.. |ESP32 Wi-Fi Adaptivity Test/Blocking Test Firmware| replace:: `ESP32 Wi-Fi Adaptivity Test/Blocking Test Firmware <https://dl.espressif.com/rf/esp32/ESP32_wifi_Adaptivity&Blocking_20210420.bin>`__
.. |ESP32-C2 Wi-Fi Adaptivity Test/Blocking Test Firmware (26 MHz) or ESP32-C2 Wi-Fi Adaptivity Test/Blocking Test Firmware (40 MHz)| replace:: `ESP32-C2 Wi-Fi Adaptivity Test/Blocking Test Firmware (26 MHz) <https://dl.espressif.com/RF/ESP32C2_wifi_Adaptivity&Blocking_26M_20250408.bin>`__ or `ESP32-C2 Wi-Fi Adaptivity Test/Blocking Test Firmware (40 MHz) <https://dl.espressif.com/RF/ESP32C2_wifi_Adaptivity&Blocking_40M_20250408.bin>`__
.. |ESP32-C3 Wi-Fi Adaptivity Test/Blocking Test Firmware| replace:: `ESP32-C3 Wi-Fi Adaptivity Test/Blocking Test Firmware <https://dl.espressif.com/RF/ESP32C3_wifi_Adaptivity&Blocking_20250722.bin>`__
.. |ESP32-C6 Wi-Fi Adaptivity Test/Blocking Test Firmware| replace:: `ESP32-C6 Wi-Fi Adaptivity Test/Blocking Test Firmware <https://dl.espressif.com/RF/ESP32C6_wifi_Adaptivity&Blocking_20250807.bin>`__
.. |ESP32-S2 Wi-Fi Adaptivity Test/Blocking Test Firmware| replace:: `ESP32-S2 Wi-Fi Adaptivity Test/Blocking Test Firmware <https://dl.espressif.com/rf/esp32s2/ESP32S2_wifi_Adaptivity&Blocking_20220826.bin>`__
.. |ESP32-S3 Wi-Fi Adaptivity Test/Blocking Test Firmware| replace:: `ESP32-S3 Wi-Fi Adaptivity Test/Blocking Test Firmware <https://dl.espressif.com/rf/esp32s3/ESP32S3_wifi_Adaptivity&Blocking_20230328.bin>`__
.. |ES8266 Wi-Fi Adaptivity Test/Blocking Test Firmware| replace:: `ES8266 Wi-Fi Adaptivity Test/Blocking Test Firmware <https://dl.espressif.com/RF/ESP8266&8285_adaptivity&blocking_bin_20220824_115200.bin>`__
