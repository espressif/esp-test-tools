EspRFTestTool Toolkit
=====================

:link_to_translation:`zh_CN:[中文]`

The **EspRFTestTool toolkit** is an RF test tool provided by Espressif. It contains EspRFTestTool, DownloadTool, and PowerLimitTool.

- `EspRFTestTool`_: Used to perform RF tests;
- `DownloadTool`_: Used to download the firmware required for RF tests;
- `PowerLimitTool`_: Used to generate customized phy_init_data firmware.

**Download Link**: `EspRFTestTool toolkit <https://dl.espressif.com/RF/EspRFTestTool_v4.6_Manual.zip>`__

The zip file not only includes the EspRFTestTool toolkit but also contains all the necessary firmware for :doc:`RF Test Items <../rf_test_items/index>`, allowing users familiar with the testing process to directly use the firmware for testing.

.. note::

   In this document, the **EspRFTestTool toolkit** refers to the collection of the three tools, while the **EspRFTestTool** refers to this single tool.

.. _esp-rf-test-tool:

EspRFTestTool
---------------------------------

The main interface of the EspRFTestTool toolkit is the EspRFTestTool, which includes the ``COM Port Configuration`` area, the ``Download Configuration`` area, the ``RF Test Configuration`` area, and the ``Log`` window.

.. figure:: ../../../_static/rf_test_tool/esprftesttool_tool.png
    :align: center
    :scale: 80%

    EspRFTestTool

COM Port Configuration Area
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/esprftesttool_com.png
    :align: center
    :scale: 80%

    EspRFTestTool COM Port Configuration Area

- **ChipType**: Select the chip;
- **COM**: Select the serial port number;
- **BaudRate**: Select the baud rate;
- **Open**: Open the serial port;
- **Close**: Close the serial port.

After configuring the serial port, you can perform quick flashing and RF tests.

Download Configuration Area
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/esprftesttool_download.png
    :align: center
    :scale: 80%

    EspRFTestTool Download Configuration Area

Generally, the `DownloadTool`_ is used to download the firmware required for RF tests. However, for some simple firmware, such as non-signaling test firmware and adaptivity test firmware, EspRFTestTool can be used for quick flashing.

- Pull down the Boot pin and re-power the chip to enter download mode;
- By default, flashing is conducted through ``UART``;
- Select ``flash`` to download to the flash;
- Click ``Select Bin`` to select the bin file to be flashed;
- Click ``Load Bin`` to start flashing;
- After flashing is completed, pull up the Boot pin and re-power the chip to enter operation mode.

RF Test Configuration Area
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/esprftesttool_rftest.png
    :align: center
    :scale: 80%

    EspRFTestTool RF Test Configuration Area

After flashing the firmware, you can perform the corresponding RF tests:

- **Wi-Fi Test**: Used for Wi-Fi Non-Signaling Test;
- **BT Test**: Used for Bluetooth and Bluetooth LE Non-Signaling Test;
- **Wi-Fi Adaptivity**: Used for Wi-Fi Adaptivity Test;
- **Zigbee Test**: Used for 802.15.4 Non-Signaling Test;
- **Manual**: Used to enter serial port commands.

For specific parameter configuration, please refer to the corresponding RF test document.

Log Window
^^^^^^^^^^

The Log window is used to display the status of the tool. To view the log printed via the chip serial port, please use a general serial port assistant, such as `SerialPortUtility <http://alithon.com/downloads>`__.

.. _download-tool:

DownloadTool
---------------------------------

Click ``Tool`` in the toolbar and select ``DownloadTool`` to enter the DownloadTool interface.

.. figure:: ../../../_static/rf_test_tool/downloadtool_main.png
    :align: center
    :scale: 80%

    Entry to DownloadTool

Follow the steps below to flash the firmware:

- Set the ``Chip Type``, ``COM Port``, and ``Baud Rate``. Then, click ``Open`` to open the serial port;
- Select ``flash`` to download to the flash;
- Select the firmware and flash it to the specified address;
- Check whether the chip has entered download mode. If yes, click ``Start Load`` to start flashing. After flashing is completed, the ``SUCC`` sign shows up;
- After flashing is completed, click ``Close`` to close the serial port.

.. figure:: ../../../_static/rf_test_tool/downloadtool_select.png
    :align: center
    :scale: 80%

    DownloadTool Interface

.. note::

  How to check whether the chip has entered download mode:

  1. Close the serial port of DownloadTool and open a general serial port assistant, such as `SerialPortUtility <http://alithon.com/downloads>`__;
  2. Configure the serial port number and baud rate, pull down the Boot pin, re-power the chip, and the serial port assistant will print the log like ``waiting for download``;
  3. Close the serial port assistant, open DownloadTool, and start flashing;
  4. After the flashing is completed, pull up the Boot pin, and re-power the chip to enter operation mode. If there are any abnormal behaviors, use the serial port assistant to check.

.. note::

    By default, DownloadTool flashes to RAM. To specify a flash address, you need to switch to flashing to flash first.

.. _power-limit-tool:

PowerLimitTool
---------------------------------

PowerLimitTool generates single-country and multi-country phy_init_bin files by configuring Wi-Fi output power to ensure your products meet the regulatory requirements of different countries or regions.

.. note::

  The following methods can be used to limit Wi-Fi power. If multiple methods are used together, the minimum power value will be taken:

  1. Use the API (``esp_wifi_set_max_tx_power``) to limit the maximum output power.
  2. Configure ``Max Wi-Fi TX Power`` in Menuconfig, which serves the same function as the API mentioned above and can limit the maximum output power.
  3. Use the ``Phy Init Bin`` function to modify the phy_init_data.h file in ESP-IDF.
  4. Use the ``Phy Init Bin`` function to generate the phy_init_data.bin file by referring to the introduction in this document.

Under the main interface of EspRFTestTool, click ``Tool``, and select ``PowerLimitTool`` from the dropdown box to open PowerLimitTool.

.. figure:: ../../../_static/rf_test_tool/powerlimit_open.png
    :align: center
    :scale: 80%

    Entry to PowerLimitTool

1. In the main interface of PowerLimitTool, click the ``Chip`` dropdown box to view the chips supported by the tool and select a chip (This section takes ESP32-C3 as an example).

.. figure:: ../../../_static/rf_test_tool/powerlimit_main.png
    :align: center
    :scale: 80%

    PowerLimitTool Main Interface

2. Click ``Select Table`` and select the TX Power Setting table for your chip.

.. figure:: ../../../_static/rf_test_tool/powerlimit_select.png
    :align: center
    :scale: 80%

    Importing TX Power Setting Table

3. Click ``Open Table``, modify the power value in the corresponding country code table, and select the desired country code in the ``Certification Code`` dropdown box.

.. figure:: ../../../_static/rf_test_tool/powerlimit_country.png
    :align: center
    :scale: 80%

    Modifying TX_Power_Setting

.. note::

  Description of TX Power Setting Table parameters:

  1. **Config_Switch**: Enable ``Power_By_Rate`` and ``Power_Limit``. Both are set to ``Yes`` by default, indicating they can be adjusted.
  2. **PowerByRate_TargetPower**: Target power for each rate. It is recommended to keep the default value.
  3. **Country_Table**: Currently supported countries (regions). It is extensible.
  4. **Actual_Result**: Actual power of the module. The target power is used by default.
  5. **Default**: Power configuration in the "Default" country code, usually used to identify the power configuration before setting the country code.
  6. **SRRC_1**: Power configuration of the "SRRC" country code, applicable to Mainland China.
  7. **FCC_2**: Power configuration of the "FCC" country code, applicable to the United States.
  8. **CE_3**: Power configuration of the "CE" country code, applicable to Europe.
  9. **NCC_4**: Power configuration of the "NCC" country code, applicable to Taiwan.
  10. **KCC_5**: Power configuration of the "KCC" country code, applicable to South Korea.
  11. **MIC_6**: Power configuration of the "MIC" country code, applicable to Japan.
  12. **IC_7**: Power configuration of the "IC" country code, applicable to Canada.

.. note::

  How to modify power values:

  1. Fill in the power value based on the certification result (the certification provides the power attenuation value) (Power value = Target power - Attenuation value/4).
  2. If ``Actual_Result`` is modified, the Target power in the above formula needs to be changed to ``Actual_Result``.
  3. Adding or deleting table content is not allowed. For example, FCC only supports channels 1~11, so it is recommended to keep the power values of channels 12~13 in this table the same as channel 11 instead of deleting them;
  4. Except for low and high channels, the power values of other channels should be set to the same as the middle channel;
  5. The NA section cannot be modified. If the ``Certification Code`` cannot be selected from the dropdown box , it indicates that the table has been modified and needs to be restored.

4. Click ``Save Table`` to save the settings. Select the required certification from the ``Certification Code`` dropdown, then click ``Generate`` to create the phy_init_bin file for the corresponding country code.

.. figure:: ../../../_static/rf_test_tool/powerlimit_generate.png
    :align: center
    :scale: 80%

    Generate phy_init_bin File

.. note::

    1. The dropdown list of `Certification Code` includes options for a single certification, ``Multiple Country``, and ``Custom``.
    2. Selecting a single certification will generate a single phy_init_bin file for that certification, which contains a total of 128 bytes except the verification control information.
    3. Selecting ``Multiple Country`` will generate Combined phy_init_bin files, including a Default bing file and seven others for SRRC, FCC, CE, NCC, KCC, MIC, and IC. The combined files contain 8*128 bytes.
    4. Selecting `Custom` will generate a single or multiple certification bin files based on your choice.

{IDF_TARGET_RF_NON_SIGNALING_FIRMWARE_COPY:default="Not Updated", esp32="|ESP32 RF Non-Signaling Test Firmware|", esp32c2="|ESP32-C2 RF Non-Signaling Test Firmware (26 MHz) or ESP32-C2 RF Non-Signaling Test Firmware (40 MHz)|", esp32c3="|ESP32-C3 RF Non-Signaling Test Firmware|", esp32c6="|ESP32-C6 RF Non-Signaling Test Firmware|", esp32s2="|ESP32-S2 RF Non-Signaling Test Firmware|", esp32s3="|ESP32-S3 RF Non-Signaling Test Firmware|", esp8266="|ESP8266 RF Non-Signaling Test Firmware (26 MHz) or ESP8266 RF Non-Signaling Test Firmware (40 MHz)|", esp32h2="|ESP32-H2 RF Non-Signaling Test Firmware|"}

{IDF_TARGET_RF_NON_SIGNALING_FIRMWARE_ADDRESS:default="0x0", esp32="0x1000", esp32s2="0x1000"}

5. Verify whether phy_init_bin is effective using Non-Signaling or Signaling Test. Taking Non-Signaling Test as an example, first use the `DownloadTool`_ to download the generated phy_init_bin file to the testing product.

- Select ``DownloadTool`` from ``Tool`` dropdown list to enter the ``DownloadTool`` interface.
- Flash the phy_init_bin file and corresponding RF test firmware to ``flash`` by referring to the instructions stated `DownloadTool`_.
- The flash address for phy_init_bin is ``0x1fc000`` and the flash address for the RF test firmware {IDF_TARGET_RF_NON_SIGNALING_FIRMWARE_COPY} is {IDF_TARGET_RF_NON_SIGNALING_FIRMWARE_ADDRESS}.

.. note::

    Regarding the Signaling Test, you can simply replace the original phy_init_bin. Please refer to the relevant documents in :doc:`RF Test Items <../rf_test_items/index>`.

.. figure:: ../../../_static/rf_test_tool/phyinit_download_start.png
    :align: center
    :scale: 80%

    Flash phy_init_bin File

6. Use a Wi-Fi tester to measure the output power and check whether phy_init_bin is effective.

- Open `EspRFTestTool`_.
- Select corresponding ``ChipType``, ``COM``, ``BaudRate``, and click ``Open`` to open the serial port.
- Open the ``WiFi Test`` tab, and select ``Test Mode``, ``Rate``, ``BandWidth`` and ``Channel``.
- Set ``Attenuation`` to 0, and ``Duty Cycle`` to 10%.
- With ``Certification EN`` unchecked, i.e., Phy init not enabled, the tool tests the initial performance of modules.
- With ``Certification EN`` checked, i.e., Phy init enabled, the tool tests the performance for certification.
- The default address for flashing phy_init_bin is 0x1fc000. If the flashing address changes, update it here.
- For Multiple Country, you can select the certification country codes it includes in the ``Certification Code``.

.. figure:: ../../../_static/rf_test_tool/powerlimittool_rf_test_setting.png
    :align: center
    :scale: 80%

    RF Test Configuration

.. only:: esp32

    Typical Average Output power of {IDF_TARGET_NAME}
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. list-table::
        :header-rows: 1
        :widths: 20 20
        :align: center

        * - Rates
          - Typical Average Output power (dBm)
        * - 11b 1 Mbps
          - 19.5
        * - 11b 11 Mbps
          - 19.5
        * - 11g 6 Mbps
          - 18
        * - 11g 54 Mbps
          - 14
        * - 11n-20 MCS0
          - 18
        * - 11n-20 MCS7
          - 13
        * - 11n-40 MCS0
          - 18
        * - 11n-40 MCS7
          - 13

.. only:: esp32c2

    Typical Average Output Power Value of {IDF_TARGET_NAME}
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. list-table::
        :header-rows: 1
        :widths: 20 20
        :align: center

        * - Rates
          - Typical Average Output Power (dBm)
        * - 11b 1M
          - 21
        * - 11b 11M
          - 21
        * - 11g 6M
          - 21
        * - 11g 54M
          - 19
        * - HT20-11n MCS0
          - 19
        * - HT20-11n MCS7
          - 18

.. only:: esp32s2

    Typical Average Output power of {IDF_TARGET_NAME}
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. list-table::
        :header-rows: 1
        :widths: 20 20
        :align: center

        * - Rates
          - Typical Average Output power (dBm)
        * - 11b 1 Mbps
          - 19.5
        * - 11b 11 Mbps
          - 19.5
        * - 11g 6 Mbps
          - 18
        * - 11g 54 Mbps
          - 15
        * - 11n-20 MCS0
          - 18
        * - 11n-20 MCS7
          - 13.5
        * - 11n-40 MCS0
          - 18
        * - 11n-40 MCS7
          - 13.5

.. only:: esp32s3

    Typical Average Output Power Value of {IDF_TARGET_NAME}
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. list-table::
        :header-rows: 1
        :widths: 20 20
        :align: center

        * - Rates
          - Typical Average Output Power (dBm)
        * - 11b 1M
          - 20.5
        * - 11b 11M
          - 20.5
        * - 11g 6M
          - 20
        * - 11g 54M
          - 18
        * - HT20-11n MCS0
          - 19
        * - HT20-11n MCS7
          - 17.5
        * - HT40-11n MCS0
          - 18.5
        * - HT40-11n MCS7
          - 17


.. only:: esp32c3

    Typical Average Output power of {IDF_TARGET_NAME}
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. list-table::
        :header-rows: 1
        :widths: 20 20
        :align: center

        * - Rates
          - Typical Average Output power (dBm)
        * - 11b 1 Mbps
          - 20.5
        * - 11b 11 Mbps
          - 20.5
        * - 11g 6 Mbps
          - 20
        * - 11g 54 Mbps
          - 18
        * - 11n-20 MCS0
          - 19
        * - 11n-20 MCS7
          - 17.5
        * - 11n-40 MCS0
          - 18.5
        * - 11n-40 MCS7
          - 17

.. only:: esp32c6

    Typical average output power value of {IDF_TARGET_NAME}
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. list-table::
        :header-rows: 1
        :widths: 20 20
        :align: center

        * - Rates
          - Typical Average Output Power (dBm)
        * - 11b 1M
          - 21
        * - 11b 11M
          - 21
        * - 11g 6M
          - 20
        * - 11g 54M
          - 19
        * - HT20-11n MCS0
          - 19
        * - HT20-11n MCS7
          - 18
        * - HT40-11n MCS0
          - 19
        * - HT40-11n MCS7
          - 18
        * - HE20-11ax MCS0
          - 19
        * - HE20-11ax MCS7
          - 18
        * - HE20-11ax MCS9
          - 15



.. |ESP32 RF Non-Signaling Test Firmware| replace:: `ESP32 RF Non-Signaling Test Firmware <https://dl.espressif.com/RF/ESP32_RFTest_V191_482eb73_20230724.bin>`__
.. |ESP32-C2 RF Non-Signaling Test Firmware (26 MHz) or ESP32-C2 RF Non-Signaling Test Firmware (40 MHz)| replace:: `ESP32-C2 RF Non-Signaling Test Firmware (26 MHz) <https://dl.espressif.com/RF/ESP32-C2_RFTest_V203_26M_7a8831de_20240730.bin>`__ or `ESP32-C2 RF Non-Signaling Test Firmware (40 MHz) <https://dl.espressif.com/RF/ESP32-C2_RFTest_V203_40M_7a8831de_20240730.bin>`__
.. |ESP32-C3 RF Non-Signaling Test Firmware| replace:: `ESP32-C3 RF Non-Signaling Test Firmware <https://dl.espressif.com/RF/ESP32-C3_RFTest_V117_402fb258_20240902.bin>`__
.. |ESP32-C6 RF Non-Signaling Test Firmware| replace:: `ESP32-C6 RF Non-Signaling Test Firmware <https://dl.espressif.com/RF/ESP32-C6_RFTest_V105_b0352c7_20240827.bin>`__
.. |ESP32-S2 RF Non-Signaling Test Firmware| replace:: `ESP32-S2 RF Non-Signaling Test Firmware <https://dl.espressif.com/RF/ESP32-S2_RFTest_V207_545e2ab_20230829.bin>`__
.. |ESP32-S3 RF Non-Signaling Test Firmware| replace:: `ESP32-S3 RF Non-Signaling Test Firmware <https://dl.espressif.com/RF/ESP32-S3_RFTest_V112_b7bc9b9_20240430.bin>`__
.. |ESP8266 RF Non-Signaling Test Firmware (26 MHz) or ESP8266 RF Non-Signaling Test Firmware (40 MHz)| replace:: `ESP8266 RF Non-Signaling Test Firmware (26 MHz) <https://dl.espressif.com/RF/ESP8266_RFTest_153_20231018_26M.bin>`__ or `ESP8266 RF Non-Signaling Test Firmware (40 MHz) <https://dl.espressif.com/RF/ESP8266_RFTest_153_20231020_40M.bin>`__
.. |ESP32-H2 RF Non-Signaling Test Firmware| replace:: `ESP32-H2 RF Non-Signaling Test Firmware <https://dl.espressif.com/RF/ESP32-H2_RFTest_V203_596642e_20250221.bin>`__

