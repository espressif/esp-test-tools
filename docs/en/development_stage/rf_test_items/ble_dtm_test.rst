Bluetooth LE DTM Test
=====================

:link_to_translation:`zh_CN:[中文]`

The Bluetooth LE DTM Test evaluates the RF performance of devices by directly controlling the device to enter specific transmit or receive modes, accessing key metrics like transmit power, reception sensitivity, and spectrum characteristics.

Set Up Test Environment
-----------------------

.. figure:: ../../../_static/rf_test_tool/dtm_uart_connection.png
    :align: center
    :scale: 60%

    Test Environment Setup

- **PC** is connected to the USB-to-UART board via USB. The PC needs to have the EspRFTestTool toolkit, tester control software, and the driver for the USB-to-UART board installed.
- **Tester** is used to test the RF performance of the device under test (DUT) in different modes. It connects to DUT via an RF connection cable to transmit RF signals. Typically, it is CMW500, CMW270, or Bluetooth tester CBT.
- **USB-to-UART board** is used to communicate between the computer and the DUT, as well as between the tester and the DUT.
- **Device under test (DUT)** refers to a product designed based on the {IDF_TARGET_NAME} chip or module.

.. note::

    - The CHIP_EN pin of the DUT is pulled up by default. If it is not pulled up in the product design, you need to manually connect the CHIP_EN to the 3V3 pin.
    - Some serial communication boards have already swapped RXD and TXD internally, so there is no need to reverse the connection. Adjust the wiring according to the actual situation.
    - {IDF_TARGET_NAME} has a power-on self-calibration feature. The RF connection cable must be connected to the tester before the DUT is powered on for testing.

Conduction Test
^^^^^^^^^^^^^^^

- For modules without an onboard PCB antenna, the RF connection cable can be directly soldered to the antenna feed point of the module (as shown in the schematic diagram above).

- For modules with an onboard PCB antenna, cut the trace that connects to the PCB antenna feed point and solder the RF connection cable. The RF cable’s shielding metal layer must be thoroughly soldered before connecting to the module’s GND. The GND soldering point can be either the shield cover or the exposed GND layer on the PCB (after removing the green solder mask). Besides, it should be as close to the feed point as possible.

.. figure:: ../../../_static/rf_test_tool/pcb_antenna_conducted_test.png
    :align: center
    :scale: 70%

    Soldering RF Connection Cable to Module with Onboard PCB Antenna

Flash Firmware
--------------

{IDF_TARGET_BLE_DTM_FIRMWARE:default="Not Updated", esp32="|ESP32 Bluetooth LE DTM Test Firmware|", esp32c2="|ESP32-C2 Bluetooth LE DTM Test Firmware (26 MHz) or ESP32-C2 Bluetooth LE DTM Test Firmware (40 MHz)|", esp32c3="|ESP32-C3 Bluetooth LE DTM Test Firmware|", esp32c6="|ESP32-C6 Bluetooth LE DTM Test Firmware|", esp32s3="|ESP32-S3 Bluetooth LE DTM Test Firmware|", esp32h2="|ESP32-H2 Bluetooth LE DTM Test Firmware|"}

1. Open :ref:`download-tool`.

2. Set ``ChipType``, ``Com Port``, ``Baud Rate``, click ``Open``, and select to download to ``Flash``.

3. Flash the {IDF_TARGET_BLE_DTM_FIRMWARE} bin file to the following address via ``UART``.

.. only:: esp32

    .. list-table::
      :header-rows: 1
      :align: center

      * - Bin File
        - Flash Address
      * - {IDF_TARGET_BLE_DTM_FIRMWARE}
        - 0x1000

.. only:: not esp32

    .. list-table::
      :header-rows: 1
      :align: center

      * - Bin File
        - Flash Address
      * - {IDF_TARGET_BLE_DTM_FIRMWARE}
        - 0x0


.. only:: esp32

    .. figure:: ../../../_static/rf_test_tool/ble_dtm_firmware_esp32.png
        :align: center
        :scale: 80%

        Flash Firmware

.. only:: not esp32

    .. figure:: ../../../_static/rf_test_tool/ble_dtm_firmware_others.png
        :align: center
        :scale: 80%

        Flash Firmware

After the flash process is completed, pull up or leave the boot pin unconnected. After the chip restarts and enters the working mode, continue with the following steps for testing.

Start Testing
-------------

The connection methods between the DUT and the tester includes HCI and 2-wire, with HCI being the default option.

Based on the hardware connections described above, you can verify whether the firmware flashing was successful by checking the output from the UART0 serial port.

.. only:: esp32

    Upon powering on, the device defaults to a power level of 6 dBm, operates without flow control, and uses a baud rate of 115200 for initialization. No commands are required, so you can directly begin the DTM test.

.. only:: not esp32

    Upon powering on, the device defaults to a power level of 12 dBm, operates without flow control, and uses a baud rate of 115200 for initialization. No commands are required, so you can directly begin the DTM test.

    To adjust the relevant settings of UART1, you can input the corresponding commands in real time through the UART0 port:

    ::

        // Configure TX output power. The supported power adjustment range is from 0 to 15 levels.
        set_ble_tx_power -i 15

        // Get the current configuration power of BLE.
        get_ble_tx_power

        // Configure UART1, set TX pin to GPIO4 and RX pin to GPIO5.
        reconfig_dtm_uart_pin -t 4 -r 5

.. |ESP32 Bluetooth LE DTM Test Firmware| replace:: `ESP32 Bluetooth LE DTM Test Firmware <https://dl.espressif.com/RF/ESP32_BLE_DTM_HCI_02e0d70_20250325.bin>`__
.. |ESP32-C2 Bluetooth LE DTM Test Firmware (26 MHz) or ESP32-C2 Bluetooth LE DTM Test Firmware (40 MHz)| replace:: `ESP32-C2 Bluetooth LE DTM Test Firmware (26 MHz) <https://dl.espressif.com/RF/ESP32C2_DTM_HCI_1babaa3_26M_20250319.bin>`__ or `ESP32-C2 Bluetooth LE DTM Test Firmware (40 MHz) <https://dl.espressif.com/RF/ESP32C2_DTM_HCI_1babaa3_40M_20250319.bin>`__
.. |ESP32-C3 Bluetooth LE DTM Test Firmware| replace:: `ESP32-C3 Bluetooth LE DTM Test Firmware <https://dl.espressif.com/RF/ESP32C3_DTM_HCI_01f2a49_20250319.bin>`__
.. |ESP32-C6 Bluetooth LE DTM Test Firmware| replace:: `ESP32-C6 Bluetooth LE DTM Test Firmware <https://dl.espressif.com/RF/ESP32C6_ECO1_DTM_HCI_5b89037_20250319.bin>`__
.. |ESP32-S3 Bluetooth LE DTM Test Firmware| replace:: `ESP32-S3 Bluetooth LE DTM Test Firmware <https://dl.espressif.com/RF/ESP32S3_DTM_HCI_a6008b2_20250319.bin>`__
.. |ESP32-H2 Bluetooth LE DTM Test Firmware| replace:: `ESP32-H2 Bluetooth LE DTM Test Firmware <https://dl.espressif.com/RF/ESP32H2_DTM_HCI_823e7f8_20250319.bin>`__



Appendix
----------------

This appendix provides the mapping of power levels and target power of {IDF_TARGET_NAME} for RF debugging or testing reference.

.. only:: esp32

  .. list-table:: {IDF_TARGET_NAME} Bluetooth/Bluetooth LE Transmit Power Levels
    :widths: 40 60

    * - Power Level
      - ESP32 Bluetooth/Bluetooth LE Transmit Power (dBm)
    * - 0
      - -12
    * - 1
      - -9
    * - 2
      - -6
    * - 3
      - -3
    * - 4
      - 0
    * - 5
      - 3
    * - 6
      - 6
    * - 7
      - 9

.. only:: not esp32

    Bluetooth LE Transmit Power Level
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. list-table:: {IDF_TARGET_NAME} Bluetooth LE Transmit Power Levels
        :widths: 40 60

        * - Power Level
          - Bluetooth LE Transmit Power (dBm)
        * - 0
          - -24
        * - 1
          - -21
        * - 2
          - -18
        * - 3
          - -15
        * - 4
          - -12
        * - 5
          - -9
        * - 6
          - -6
        * - 7
          - -3
        * - 8
          - 0
        * - 9
          - 3
        * - 10
          - 6
        * - 11
          - 9
        * - 12
          - 12
        * - 13
          - 15
        * - 14
          - 18
        * - 15
          - 20
