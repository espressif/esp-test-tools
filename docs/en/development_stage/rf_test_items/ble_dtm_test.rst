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

- **PC** is connected to the USB-to-UART board via USB. The PC needs to have the `EspRFTestTool toolkit <https://dl.espressif.com/RF/EspRFTestTool_v3.6_Manual.zip>`_, tester control software, and the driver for the USB-to-UART board installed.
- **Tester** is used to test the RF performance of the device under test (DUT) in different modes. It connects to DUT via an RF connection cable to transmit RF signals. Typically, it is CMW500, CMW270, or Bluetooth tester CBT.
- **USB-to-UART board** is used to communicate between the computer and the DUT, as well as between the tester and the DUT.
- **Device under test (DUT)** refers to a product designed based on the {IDF_TARGET_NAME} chip or module.

.. note::

    - The CHIP_EN pin of the DUT is pulled up by default. If it is not pulled up in the product design, you need to manually connect the CHIP_EN to the 3V3 pin.
    - Some serial communication boards have already swapped RXD and TXD internally, so there is no need to reverse the connection. Adjust the wiring according to the actual situation.
    - {IDF_TARGET_NAME} has a power-on self-calibration function, so the RF connection cable must be connected to the tester before the DUT is powered on for testing.

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

{IDF_TARGET_BLE_DTM_FIRMWARE:default="Not Updated", esp32c2="`ESP32-C2 Bluetooth LE DTM Test Firmware <https://dl.espressif.com/rf/esp32c2/ESP32C2_DTM_HCI_CMD_26M_20230301.zip>`_", esp32c3="`ESP32-C3 Bluetooth LE DTM Test Firmware <https://dl.espressif.com/rf/esp32c3/ESP32C3_DTM_HCI_20230724.zip>`_", esp32c6="`ESP32-C6 Bluetooth LE DTM Test Firmware <https://dl.espressif.com/rf/esp32c6/ESP32C6-ECO1_DTM_HCI_d1caf30_20230407.zip>`_", esp32s3="`ESP32-S3 Bluetooth LE DTM Test Firmware <https://dl.espressif.com/rf/esp32s3/ESP32S3_BLE_HCI_cb74f83_20220518.zip>`_", esp32h2="`ESP32-H2 Bluetooth LE DTM Test Firmware <https://dl.espressif.com/rf/esp32h2/ESP32H2_BLE_DTM_Bin_20230811.bin>`_"}

1. Open :ref:`download-tool`.

2. Set ``ChipType``, ``Com Port``, ``Baud Rate``, click ``Open``, and select to download to ``Flash``.

3. {IDF_TARGET_BLE_DTM_FIRMWARE} includes **bootloader.bin**, **partition-table.bin** and **ssc.bin** files. After decompressing {IDF_TARGET_BLE_DTM_FIRMWARE}, flash the three bin files to the following addresses via ``UART``.

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

After the flashing is completed, continue the following steps for testing.

Start Testing
-------------

The connection methods between the DUT and the tester includes HCI and 2-wire, with HCI being the default option.

Based on the hardware connections described above, you can verify whether the firmware flashing was successful by checking the output from the UART0 serial port.

Upon powering on, the device defaults to a power level of 12 dBm, operates without flow control, and uses a baud rate of 115200 for initialization. No commands are required, so you can directly begin the DTM test.

If you need to adjust the UART1 settings, you can input the corresponding commands in real time via the UART0 port:

::

    //Configure UART1, set the TX pin to GPIO4 and the RX pin to GPIO5
    bqb -z reconfig_uart1_pin -t 4 -r 5

    //Configure TX output power, supporting power adjustments from level 0 to 15
    bqb -z set_ble_tx_power -i 15

    //Configure flow control to be disabled and set the baud rate to 115200
    bqb -z set_uart_param -f 0 -b 115200
