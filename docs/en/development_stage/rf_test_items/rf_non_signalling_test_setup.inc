Set Up Test Environment
-----------------------

The RF non-signaling test firmware environment mainly includes a PC, tester, a USB-to-UART board, a device under test (DUT), and a shield box.

.. figure:: ../../../_static/rf_test_tool/rf_non_signaling_setup.png
    :align: center
    :scale: 120%

    Test Environment Setup

- **PC** is connected to the USB-to-UART board via USB and to the tester via an Ethernet cable. The PC needs to have the EspRFTestTool toolkit, tester control software, and the driver for the USB-to-UART board installed.
- **Tester** is used to test the RF performance of the DUT in different modes. Typically, it is the WT-328/IQXel tester.
- **USB-to-UART board** is used to communicate between the PC and the DUT.
- **Device under test (DUT)** refers to a product designed based on the {IDF_TARGET_NAME} chip or module. It is connected to the USB-to-UART board via UART and to the tester via an RF connection cable. The DUT is usually placed inside a shield box.
- **Shield Box** is used to isolate external RF interference and ensure the stability of the test environment.

.. note::

    - The CHIP_EN pin of the DUT is pulled up by default. If it is not pulled up in the product design, you need to manually connect the CHIP_EN to the 3V3 pin.
    - Some serial communication boards have already swapped RXD and TXD internally, so there is no need to reverse the connection. Adjust the wiring according to the actual situation.
    - {IDF_TARGET_NAME} has a power-on self-calibration feature. The RF connection cable must be connected to the tester before the DUT is powered on for testing.

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

{IDF_TARGET_RF_NON_SIGNALING_FIRMWARE:default="Not Updated", esp32="|ESP32 RF Non-Signaling Test Firmware|", esp32c2="|ESP32-C2 RF Non-Signaling Test Firmware (26 MHz) or ESP32-C2 RF Non-Signaling Test Firmware (40 MHz)|", esp32c3="|ESP32-C3 RF Non-Signaling Test Firmware|", esp32c6="|ESP32-C6 RF Non-Signaling Test Firmware|", esp32s2="|ESP32-S2 RF Non-Signaling Test Firmware|", esp32s3="|ESP32-S3 RF Non-Signaling Test Firmware|", esp8266="|ESP8266 RF Non-Signaling Test Firmware (26 MHz) or ESP8266 RF Non-Signaling Test Firmware (40 MHz)|", esp32h2="|ESP32-H2 RF Non-Signaling Test Firmware|"}

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

4. After the firmware flashing is completed, pull the boot pin high or leave it floating. The chip will enter the working mode after power-off restart.

.. |ESP32 RF Non-Signaling Test Firmware| replace:: `ESP32 RF Non-Signaling Test Firmware <https://dl.espressif.com/RF/ESP32_RFTest_V191_482eb73_20230724.bin>`__
.. |ESP32-C2 RF Non-Signaling Test Firmware (26 MHz) or ESP32-C2 RF Non-Signaling Test Firmware (40 MHz)| replace:: `ESP32-C2 RF Non-Signaling Test Firmware (26 MHz) <https://dl.espressif.com/RF/ESP32-C2_RFTest_V203_26M_7a8831de_20240730.bin>`__ or `ESP32-C2 RF Non-Signaling Test Firmware (40 MHz) <https://dl.espressif.com/RF/ESP32-C2_RFTest_V203_40M_7a8831de_20240730.bin>`__
.. |ESP32-C3 RF Non-Signaling Test Firmware| replace:: `ESP32-C3 RF Non-Signaling Test Firmware <https://dl.espressif.com/RF/ESP32-C3_RFTest_V117_402fb258_20240902.bin>`__
.. |ESP32-C6 RF Non-Signaling Test Firmware| replace:: `ESP32-C6 RF Non-Signaling Test Firmware <https://dl.espressif.com/RF/ESP32-C6_RFTest_V106_d12e5a3_20250711.bin>`__
.. |ESP32-S2 RF Non-Signaling Test Firmware| replace:: `ESP32-S2 RF Non-Signaling Test Firmware <https://dl.espressif.com/RF/ESP32-S2_RFTest_V207_545e2ab_20230829.bin>`__
.. |ESP32-S3 RF Non-Signaling Test Firmware| replace:: `ESP32-S3 RF Non-Signaling Test Firmware <https://dl.espressif.com/RF/ESP32-S3_RFTest_V112_b7bc9b9_20240430.bin>`__
.. |ESP8266 RF Non-Signaling Test Firmware (26 MHz) or ESP8266 RF Non-Signaling Test Firmware (40 MHz)| replace:: `ESP8266 RF Non-Signaling Test Firmware (26 MHz) <https://dl.espressif.com/RF/ESP8266_RFTest_153_20231018_26M.bin>`__ or `ESP8266 RF Non-Signaling Test Firmware (40 MHz) <https://dl.espressif.com/RF/ESP8266_RFTest_153_20231020_40M.bin>`__
.. |ESP32-H2 RF Non-Signaling Test Firmware| replace:: `ESP32-H2 RF Non-Signaling Test Firmware <https://dl.espressif.com/RF/ESP32-H2_RFTest_V203_596642e_20250221.bin>`__
