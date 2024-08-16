Bluetooth LE DTM Test
===============================

:link_to_translation:`zh_CN:[中文]`

The Bluetooth LE DTM test is used for direct testing of the RF performance of wireless devices, allowing the transmission and reception functions to be tested at the physical level without the support of a complete protocol stack. This test is mainly used for low-power BQB certification and CE and other related certifications.

Setting up the test environment
-------------------------------

.. figure:: ../../../_static/rf_test_tool/dtm_uart_connection.png
    :align: center
    :scale: 60%

    Test environment schematic

- **Computer (PC)** is connected to the USB-to-UART adapter board via USB. The computer needs to install the `EspRFTestTool package <https://dl.espressif.com/RF/EspRFTestTool_v3.6_Manual.zip>`_, test instrument control software, and USB-to-UART adapter board driver.
- **Test instrument (Tester)** is used to test the RF performance of the device under test in different modes. The test instrument is connected to the device under test via an RF connection line to transmit RF signals.
- **USB-to-UART adapter board (USB-to-UART Board)** is used to implement communication between the computer and the device under test, as well as between the tester and the device under test.
- **Device Under Test (DUT)** is a product designed based on Espressif chips or modules.

.. note::

    - The CHIP_EN pin of the device under test is pulled up by default. If it is not pulled up in the product design, you need to manually connect the CHIP_EN to the 3V3 pin.
    - Some serial communication boards have already swapped RXD and TXD internally, no need to reverse, and the wiring needs to be adjusted according to the actual situation.
    - Espressif chips have a power-on self-calibration function, so the RF connection line must be connected to the test instrument before the device under test is powered on for testing.
    - Test instruments are usually CMW500, CMW270, Bluetooth tester CBT, etc.

Conduction test
^^^^^^^^^^^^^^^^^^

- For modules without an onboard PCB antenna, directly solder the RF connection line to the antenna feed point of the module (as shown in the schematic above).

- For modules with an onboard PCB antenna, you need to cut off the antenna after the PCB antenna feed point, solder the RF connection line, and solder the shielding metal layer of the RF line to the module GND after sufficient soldering. The GND soldering point can choose the shielding cover or the GND layer of the PCB board with the green oil layer removed, and it should be as close to the feed point as possible.

.. figure:: ../../../_static/rf_test_tool/pcb_antenna_conducted_test.png
    :align: center
    :scale: 70%

    Schematic diagram of soldering RF connection line to module with onboard PCB antenna

Firmware burning
------------------

{IDF_TARGET_BLE_DTM_FIRMWARE:default="Not updated", esp32c2="`ESP32-C2 Bluetooth LE DTM Test Firmware <https://dl.espressif.com/rf/esp32c2/ESP32C2_DTM_HCI_CMD_26M_20230301.zip>`_", esp32c3="`ESP32-C3 Bluetooth LE DTM Test Firmware <https://dl.espressif.com/rf/esp32c3/ESP32C3_DTM_HCI_20230724.zip>`_", esp32c6="`ESP32-C6 Bluetooth LE DTM Test Firmware <https://dl.espressif.com/rf/esp32c6/ESP32C6-ECO1_DTM_HCI_d1caf30_20230407.zip>`_", esp32s3="`ESP32-S3 Bluetooth LE DTM Test Firmware <https://dl.espressif.com/rf/esp32s3/ESP32S3_BLE_HCI_cb74f83_20220518.zip>`_", esp32h2="`ESP32-H2 Bluetooth LE DTM Test Firmware <https://dl.espressif.com/rf/esp32h2/ESP32H2_BLE_DTM_Bin_20230811.bin>`_"}

1. Open the DownloadTool tool.

2. Set ChipType, Com Port, Baud Rate, click Open, and select to download to Flash.

3. {IDF_TARGET_BLE_DTM_FIRMWARE} includes **bootloader.bin**, **partition-table.bin**, and **ssc.bin** 3 bin files. After decompressing {IDF_TARGET_BLE_DTM_FIRMWARE}, burn the 4 bin files to the following addresses via UART.

.. list-table::
   :header-rows: 1

   * - bin file
     - Burn address
   * - bootloader.bin
     - 0x0
   * - partition-table.bin
     - 0x8000
   * - ssc.bin
     - 0x10000

After the burning is completed, continue with the following steps for testing.

Start Testing
---------------------------

The connection methods between the device under test and the test instrument are HCI and 2-wire, and the default is the HCI method.

According to the above hardware connection method, you can confirm the successful firmware burning through the UART0 serial port print information;

The power is turned on by default at Power 12 dBm, no flow control, and the baud rate is 115200 to complete the initialization process. No need to input instructions, you can directly start the DTM test;

If you need to adjust the related settings of UART1, you can input the corresponding instructions in real time through the UART0 port:

::

    \\Configure UART1, set the TX pin to GPIO4, and set the RX pin to GPIO5
    bqb -z reconfig_uart1_pin -t 4 -r 5

    \\Configure TX output power, support 0~15 gear power adjustment
    bqb -z set_ble_tx_power -i 15

    \\Configure flow control off, baud rate set to 115200
    bqb -z set_uart_param -f 0 -b 115200
