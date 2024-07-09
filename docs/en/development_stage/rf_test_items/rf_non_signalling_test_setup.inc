Test Environment Setup
----------------------------

The RF non-signaling test environment mainly includes a computer, test instruments, a USB-to-UART adapter board, a device under test (DUT), and a shield box.

.. figure:: ../../../_static/rf_test_tool/rf_non_signaling_setup.png
    :align: center
    :scale: 120%

    RF non-signaling test schematic diagram

- **Computer (PC)** is connected to the USB-to-UART adapter board via USB and to the test instrument via Ethernet. The PC needs to have the ESPRFTestTool, test instrument control software, and USB-to-UART adapter board driver installed.
- **Test Instrument (Tester)** is typically a WT-328/IQXel comprehensive tester, used to test the RF performance of the DUT in different modes.
- **USB-to-UART Adapter Board (USB-to-UART Board)** is used to facilitate communication between the PC and the DUT.
- **Device Under Test (DUT)** is a product designed based on Espressif chips or modules. The DUT is connected to the USB-to-UART adapter board via UART and to the test instrument via an RF connection cable. The DUT is usually placed inside a shield box.
- **Shield Box** is used to isolate external RF interference and ensure the stability of the test environment.

.. note::

    - The CHIP_EN pin of the DUT is pulled up by default. If it is not pulled high in the product design, you need to manually connect CHIP_EN to the 3V3 pin.
    - Some serial communication boards have already swapped RXD and TXD internally, so no reverse connection is needed. Adjust the wiring according to the actual situation.
    - Espressif chips have a power-on self-calibration function, so the RF connection cable must be connected to the test instrument before the DUT is powered on for testing.

Conduction Test
^^^^^^^^^^^^^^^^^^

- For modules without an onboard PCB antenna, the RF connection cable can be directly soldered to the antenna feed point of the module (as shown in the schematic diagram above).

- For modules with an onboard PCB antenna, the antenna after the PCB antenna feed point needs to be cut off, the RF connection cable soldered, and the shielding metal layer of the RF cable fully soldered before connecting to the module GND. The GND soldering point can be chosen from the shield cover or the GND layer of the PCB material with the green oil layer removed, and it should be as close to the feed point as possible.

.. figure:: ../../../_static/rf_test_tool/pcb_antenna_conducted_test.png
    :align: center
    :scale: 80%

    Schematic diagram of soldering RF connection cable to module with onboard PCB antenna

Firmware Burning
------------------

{IDF_TARGET_RF_NON_SIGNALLING_FIRMWARE:default="Not Updated", esp32="`ESP32 RF Non-Signaling Test <https://dl.espressif.com/rf/esp32/ESP32_RFTest_190_8cac24c_20230710.bin>`_", esp32c2="`ESP32-C2 RF Non-Signaling Test <https://dl.espressif.com/rf/esp32c2/ESP32-C2_RFTest_Bin_26M_98a091b_20230621.bin>`_", esp32c3="`ESP32-C3 RF Non-Signaling Test <https://dl.espressif.com/rf/esp32c3/ESP32-C3_RF_TEST_BIN_V114_1ac85ea_20230504.bin>`_", esp32c6="`ESP32-C6 RF Non-Signaling Test <https://dl.espressif.com/rf/esp32c6/ESP32-C6_RFTest_Bin_26f46b0_20230621.bin>`_", esp32s3="`ESP32-S3 RF Non-Signaling Test <https://dl.espressif.com/rf/esp32s3/ESP32-S3_RF_TEST_BIN_V110_25c811a_20230504.bin>`_", esp32s2="`ESP32-S2 RF Non-Signaling Test <https://dl.espressif.com/rf/esp32s2/ESP32-S2_RF_TEST_BIN_20220902_05bde8b.bin>`_", esp8266="`ES8266 RF Non-Signaling Test (26 MHz) <https://dl.espressif.com/RF/ESP8266_RFTest_153_20231018_26M.bin>`_ or `ES8266 RF Non-Signaling Test (40 MHz) <https://dl.espressif.com/RF/ESP8266_RFTest_153_20231020_40M.bin>`_"}

1. Open the DownloadTool
2. Set ChipType, Com Port, Baud Rate, click Open, select download to Flash

.. figure:: ../../../_static/rf_test_tool/phyinit_download_flash.png
    :align: center
    :scale: 80%

    DownloadTool Configuration

.. only:: esp32 or esp32s2

    3. Burn {IDF_TARGET_RF_NON_SIGNALLING_FIRMWARE} to 0x1000 via UART, and burn phy init bin to 0x1fc000 via UART. For the generation method of phy init bin, please see `PowerLimitTool <power-limit-tool>`_.

.. only:: not esp32 and not esp32s2

    3. Burn {IDF_TARGET_RF_NON_SIGNALLING_FIRMWARE} to 0x0 via UART, and burn phy init bin to 0x1fc000 via UART. For the generation method of phy init bin, please see `PowerLimitTool <power-limit-tool>`_.

.. figure:: ../../../_static/rf_test_tool/phyinit_download_start.png
    :align: center
    :scale: 80%

    Burning Non-Signaling Firmware

Start Testing
----------------

Serial Port Configuration
^^^^^^^^^^^^^^^^^^^^^^^^^

- **ChipType**: Select the corresponding chip type
- **COM**: Select the corresponding COM port

.. only:: esp8266

  - **BaudRate**: If the main crystal oscillator is 26 MHz, set the baud rate to 74880; If the main crystal oscillator is 40 MHz, set the baud rate to 115200.

.. only:: esp32c2

  - **BaudRate**: 74880

.. only:: not esp32c2 and not esp8266

  - **BaudRate**: Select baud rate 115200

- **Open**: Open the serial port
