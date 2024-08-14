Setting Up the Test Environment
-------------------------------

The RF non-signaling test firmware environment mainly includes a PC, tester, a USB-to-UART board, a device under test (DUT), and a shield box.

.. figure:: ../../../_static/rf_test_tool/rf_non_signaling_setup.png
    :align: center
    :scale: 120%

    Test Environment Setup

- **PC** is connected to the USB-to-UART board via USB and to the tester via an Ethernet cable. The PC needs to have the `EspRFTestTool package <https://dl.espressif.com/RF/EspRFTestTool_v3.6_Manual.zip>`_, tester control software, and USB-to-UART board driver installed.
- **Tester** is usually the WT-328/IQXel tester, used to test the RF performance of the DUT in different modes.
- **USB-to-UART board** is used to facilitate communication between the PC and the DUT.
- **Device under test (DUT)** is a product designed based on the {IDF_TARGET_NAME} chip or module. It is connected to the USB-to-UART board via UART and to the tester via an RF connection cable. The DUT is usually placed inside a shield box.
- **Shield Box** is used to isolate external RF interference and ensure the stability of the test environment.

.. note::

    - The CHIP_EN pin of the DUT is pulled up by default. If it is not pulled high in the product design, you need to manually connect the CHIP_EN to the 3V3 pin.
    - Some serial communication boards have already swapped RXD and TXD internally, so there is no need to reverse the connection. Adjust the wiring according to the actual situation.
    - {IDF_TARGET_NAME} has a power-on self-calibration function, so the RF connection cable must be connected to the tester before the DUT is powered on for testing.

Conduction Test
^^^^^^^^^^^^^^^^^^

- For modules without an onboard PCB antenna, the RF connection cable can be directly soldered to the antenna feed point of the module (as shown in the schematic diagram above).

- For modules with an onboard PCB antenna, cut the trace that connect to the PCB antenna feed point and solder the RF connection cable. The RF cable's shielding metal layer must be thoroughly soldered before connecting to the module's GND. The GND soldering point can be either the shield cover or the exposed GND layer on the PCB (after removing the green solder mask). Besides, it should be as close to the feed point as possible.

.. figure:: ../../../_static/rf_test_tool/pcb_antenna_conducted_test.png
    :align: center
    :scale: 70%

    Soldering RF Connection Cable to Module with Onboard PCB Antenna

Firmware Flashing
------------------

{IDF_TARGET_RF_NON_SIGNALLING_FIRMWARE:default="Not Updated", esp32="`ESP32 RF Non-Signaling Test Firmware <https://dl.espressif.com/rf/esp32/ESP32_RFTest_190_8cac24c_20230710.bin>`_", esp32c2="`ESP32-C2 RF Non-Signaling Test Firmware <https://dl.espressif.com/rf/esp32c2/ESP32-C2_RFTest_Bin_26M_98a091b_20230621.bin>`_", esp32c3="`ESP32-C3 RF Non-Signaling Test Firmware <https://dl.espressif.com/rf/esp32c3/ESP32-C3_RF_TEST_BIN_V114_1ac85ea_20230504.bin>`_", esp32c6="`ESP32-C6 RF Non-Signaling Test Firmware <https://dl.espressif.com/rf/esp32c6/ESP32-C6_RFTest_Bin_26f46b0_20230621.bin>`_", esp32s2="`ESP32-S2 RF Non-Signaling Test Firmware <https://dl.espressif.com/rf/esp32s2/ESP32-S2_RF_TEST_BIN_20220902_05bde8b.bin>`_", esp32s3="`ESP32-S3 RF Non-Signaling Test Firmware <https://dl.espressif.com/rf/esp32s3/ESP32-S3_RF_TEST_BIN_V110_25c811a_20230504.bin>`_", esp8266="`ESP8266 RF Non-Signaling Test Firmware (26 MHz) <https://dl.espressif.com/RF/ESP8266_RFTest_153_20231018_26M.bin>`_ or `ESP8266 RF Non-Signaling Test Firmware (40 MHz) <https://dl.espressif.com/RF/ESP8266_RFTest_153_20231020_40M.bin>`_"}

1. Open :ref:`download-tool`.

2. Set ``ChipType``, ``Com Port``, ``Baud Rate``, click and ``Open``. Select ``Flash`` for download.

.. figure:: ../../../_static/rf_test_tool/phyinit_download_flash.png
    :align: center
    :scale: 80%

    DownloadTool Configuration

.. only:: esp32 or esp32s2

    3. Flash {IDF_TARGET_RF_NON_SIGNALLING_FIRMWARE} to 0x1000 via UART, and flash the phy init bin firmware to 0x1fc000 via UART. For how to generate the phy init bin firmware, please see `PowerLimitTool <power-limit-tool>`_.

.. only:: not esp32 and not esp32s2

    3. Flash {IDF_TARGET_RF_NON_SIGNALLING_FIRMWARE} to 0x0 via UART, and flash the phy init bin firmware to 0x1fc000 via UART. For how to generate the phy init bin firmware, please see `PowerLimitTool <power-limit-tool>`_.

.. figure:: ../../../_static/rf_test_tool/phyinit_download_start.png
    :align: center
    :scale: 80%

    Firmware Flashing

Starting Testing
-----------------

Serial Port Configuration
^^^^^^^^^^^^^^^^^^^^^^^^^

- **ChipType**: Select the corresponding chip type
- **COM**: Select the corresponding COM port

.. only:: esp8266

  - **BaudRate**: If the main crystal oscillator is 26 MHz, set the baud rate to 74880; if the main crystal oscillator is 40 MHz, set the baud rate to 115200.

.. only:: esp32c2

  - **BaudRate**: Select 74880

.. only:: not esp32c2 and not esp8266

  - **BaudRate**: Select 115200

- **Open**: Open the COM port
