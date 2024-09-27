Bluetooth LE Adaptivity Test
============================

:link_to_translation:`zh_CN:[中文]`

The Bluetooth LE Adaptivity Test ensures that the device operates using frequency hopping and the Power Spectral Density (PSD) of the Bluetooth LE signal exceeds 10 dBm/MHz, meeting specific parameter requirements to prevent interference with other wireless devices.

.. note::

  - If the PSD of the Bluetooth LE signal transmitted by the device is less than 10 dBm/MHz, the interference mitigation techniques with the equivalent occupancy rate of no more than 10% can be applied. In this case, the Bluetooth LE Adaptivity Test is not required.
  - If the PSD of the Bluetooth LE signal transmitted by the device exceeds 10 dBm/MHz, the Listen Before Talk (LBT) mechanism based on frequency hopping can be used to perform the Bluetooth LE Adaptivity Test.

Set Up Test Environment
-----------------------

.. figure:: ../../../_static/rf_test_tool/ble_adaptive_connection.png
    :align: center
    :scale: 80%

    Test Environment Setup

- In the test, the {IDF_TARGET_NAME} module is used as the test device (Slave) to establish a connection with the device under test (Master). Both the Slave and Master are flashed with the same firmware, but they can be distinguished using the serial port commands.

- The **Test System** refers to the system that performs adaptivity test. Once the Master and Slave are successfully connected via the serial port command, the test can begin.

.. note::

    - The CHIP_EN pin of the device under test is pulled up by default. If it is not pulled up in the product design, you need to manually connect the CHIP_EN to the 3V3 pin.
    - Some serial communication boards have already swapped RXD and TXD internally, so there is no need to reverse the connection. Adjust the wiring according to the actual situation.
    - {IDF_TARGET_NAME} has a power-on self-calibration function, so the RF connection cable must be connected to the tester before the device under test is powered on for testing.

Flash Firmware
--------------

{IDF_TARGET_BLE_ADAPTIVITY_FIRMWARE:default="Not updated", esp32c2="`ESP32-C2 Bluetooth LE Adaptivity Test Firmware <https://dl.espressif.com/rf/esp32c2/ESP32C2_BLE_Adaptivity_bin_20230704.bin>`_", esp32c3="`ESP32-C3 Bluetooth LE Adaptivity Test Firmware <https://dl.espressif.com/rf/esp32c3/ESP32C3_BLE_Adaptivity_bin_20230704.bin>`_", esp32c6="`ESP32-C6 Bluetooth LE Adaptivity Test Firmware <https://dl.espressif.com/rf/esp32c6/ESP32C6_BLE_Adaptivity_bin_20230704.bin>`_", esp32s3="`ESP32-S3 Bluetooth LE Adaptivity Test Firmware <https://dl.espressif.com/rf/esp32s3/ESP32S3_BLE_Adaptivity_bin_20230704.bin>`_", esp32h2="`ESP32-H2 Bluetooth LE Adaptivity Test Firmware <https://dl.espressif.com/rf/esp32h2/ESP32H2_BLE_Adaptivity_bin_20230704.bin>`_"}

1. Open :ref:`download-tool`.

2. Set ``ChipType``, ``Com Port``, ``Baud Rate``, click ``Open``, and select to download to ``Flash``.

3. Flash {IDF_TARGET_BLE_ADAPTIVITY_FIRMWARE} to ``0x0`` via ``UART``.

.. figure:: ../../../_static/rf_test_tool/ble_adaptivity_firmware.png
    :align: center
    :scale: 80%

    Flash Firmware

After the flashing is completed, continue the following steps for testing.

Start Testing
-------------

Bluetooth LE Adaptivity Test requires inputting corresponding serial port commands in both Mater and Slave devices to establish a connection for testing.

Enter the commands in the Slave and Master devices in order:

1. **Slave Device**

::

  //Start advertising on the test device
  bleadve -C -z start -t 19 -u 13


2. **Master Device**

::

  //Establish a connection with a data rate of 1 Mbps (to configure 2 Mbps, change parameters to "-x 2 -y 2"), set power level to 13
  bleconn -T -z start -x 1 -y 1 -n 1 -i 0x6-0x6 -v 13

  //Configure power, default is set to level 13 (the parameter after "-e" should be consistent with the one after "-v" in the previous command)
  ble -S -z etxp -t 4 -h 1 -e 13

  //Set MTU
  gattc -C -m 512 -p 0x10 -r c0:11:11:11:11:11 -b 1

  //Send data
  gattc -W -z char -p 0x10 -s 0xA002 -c 0xC317 -l 490 -n 0xFFFFFFFF -w 1 -r c0:11:11:11:11:11 -g 1 -b 1

3. **Other Operation Commands**

::

  //Disconnect
  bleconn -D -z all

  //Reboot the module
  reboot

After entering the above commands, you can continue with the Bluetooth LE Adaptivity Test.
