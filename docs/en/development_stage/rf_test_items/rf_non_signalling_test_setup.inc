Set Up Test Environment
-----------------------

The RF non-signaling test firmware environment mainly includes a PC, tester, a USB-to-UART board, a device under test (DUT), and a shield box.

.. figure:: ../../../_static/rf_test_tool/rf_non_signaling_setup.png
    :align: center
    :scale: 120%

    Test Environment Setup

- **PC** is connected to the USB-to-UART board via USB and to the tester via an Ethernet cable. The PC needs to have the `EspRFTestTool toolkit <https://dl.espressif.com/RF/EspRFTestTool_v3.6_Manual.zip>`_, tester control software, and the driver for the USB-to-UART board installed.
- **Tester** is used to test the RF performance of the DUT in different modes. Typically, it is the WT-328/IQXel tester.
- **USB-to-UART board** is used to communicate between the PC and the DUT.
- **Device under test (DUT)** refers to a product designed based on the {IDF_TARGET_NAME} chip or module. It is connected to the USB-to-UART board via UART and to the tester via an RF connection cable. The DUT is usually placed inside a shield box.
- **Shield Box** is used to isolate external RF interference and ensure the stability of the test environment.

.. note::

    - The CHIP_EN pin of the DUT is pulled up by default. If it is not pulled up in the product design, you need to manually connect the CHIP_EN to the 3V3 pin.
    - Some serial communication boards have already swapped RXD and TXD internally, so there is no need to reverse the connection. Adjust the wiring according to the actual situation.
    - {IDF_TARGET_NAME} has a power-on self-calibration function, so the RF connection cable must be connected to the tester before the DUT is powered on for testing.

Conduction Test
^^^^^^^^^^^^^^^

- For modules without an onboard PCB antenna, the RF connection cable can be directly soldered to the antenna feed point of the module (as shown in the schematic diagram above).

- For modules with an onboard PCB antenna, cut the trace that connects to the PCB antenna feed point and solder the RF connection cable. The RF cable's shielding metal layer must be thoroughly soldered before connecting to the module's GND. The GND soldering point can be either the shield cover or the exposed GND layer on the PCB (after removing the green solder mask). Besides, it should be as close to the feed point as possible.

.. figure:: ../../../_static/rf_test_tool/pcb_antenna_conducted_test.png
    :align: center
    :scale: 70%

    Soldering RF Connection Cable to Module with Onboard PCB Antenna

Flash Firmware
--------------

{IDF_TARGET_RF_NON_SIGNALING_FIRMWARE:default="Not Updated", esp32="`ESP32 RF Non-Signaling Test Firmware <https://dl.espressif.com/rf/esp32/ESP32_RFTest_190_8cac24c_20230710.bin>`__", esp32c2="`ESP32-C2 RF Non-Signaling Test Firmware <https://dl.espressif.com/rf/esp32c2/ESP32-C2_RFTest_Bin_26M_98a091b_20230621.bin>`__", esp32c3="`ESP32-C3 RF Non-Signaling Test Firmware <https://dl.espressif.com/rf/esp32c3/ESP32-C3_RF_TEST_BIN_V114_1ac85ea_20230504.bin>`__", esp32c6="`ESP32-C6 RF Non-Signaling Test Firmware <https://dl.espressif.com/rf/esp32c6/ESP32-C6_RFTest_Bin_26f46b0_20230621.bin>`__", esp32s2="`ESP32-S2 RF Non-Signaling Test Firmware <https://dl.espressif.com/rf/esp32s2/ESP32-S2_RF_TEST_BIN_20220902_05bde8b.bin>`__", esp32s3="`ESP32-S3 RF Non-Signaling Test Firmware <https://dl.espressif.com/rf/esp32s3/ESP32-S3_RF_TEST_BIN_V110_25c811a_20230504.bin>`__", esp8266="`ESP8266 RF Non-Signaling Test Firmware (26 MHz) <https://dl.espressif.com/RF/ESP8266_RFTest_153_20231018_26M.bin>`__ or `ESP8266 RF Non-Signaling Test Firmware (40 MHz) <https://dl.espressif.com/RF/ESP8266_RFTest_153_20231020_40M.bin>`__", esp32h2="`ESP32-H2 RF Non-Signaling Test Firmware <https://dl.espressif.com/rf/esp32h2/ESP32-H2_RFTest_Bin_5b55c8f_20231010.bin>`__"}

1. Open :ref:`esp-rf-test-tool`.

2. Set ``ChipType``, ``COM``, ``BaudRate``, and click ``Open`` to open the COM port.

.. note::

    .. only:: esp8266 or esp32c2

        If the main crystal oscillator is 26 MHz, set ``BaudRate`` to 74880; if the main crystal oscillator is 40 MHz, set ``BaudRate`` to 115200.

    .. only:: not esp32c2 and not esp8266

        Set ``BaudRate`` to 115200

3. Flash {IDF_TARGET_RF_NON_SIGNALING_FIRMWARE} to ``Flash`` via ``UART``.

.. figure:: ../../../_static/rf_test_tool/nonsignaling_firmware_flash.png
    :align: center
    :scale: 80%

    ESPRFTestTool Configuration