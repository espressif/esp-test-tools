EspRFTestTool Toolkit
=============================

:link_to_translation:`zh_CN:[中文]`

The `EspRFTestTool toolkit <https://dl.espressif.com/RF/EspRFTestTool_v3.6_Manual.zip>`_ is a radio frequency test tool provided by Espressif. It contains EspRFTestTool, DownloadTool, and PowerLimitTool.

- `EspRFTestTool <esp-rf-test-tool>`_: Used to perform RF tests;
- `DownloadTool <download-tool>`_: Used to download the firmware required for RF tests;
- `PowerLimitTool <power-limit-tool>`_: Used to generate customized phy_init_data firmware.

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

Generally, the `DownloadTool <download-tool>`_ is used to download the firmware required for RF tests, but for some simple firmware, such as non-signaling test firmware and adaptivity test firmware, the EspRFTestTool can be used for quick flashing.

- Pull down the Boot pin and re-power the chip to enter download mode;
- Select ``UART`` for flashing by default;
- Select ``flash`` to download to the flash;
- Click ``Select Bin`` to select the bin file to be flashed;
- Click ``Load Bin`` to start flashing;
- After flashing is completed, pull up the Boot pin and re-power the chip to enter the working mode.

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
- **Manual**: Can be used to enter serial port commands.

For specific parameter configuration, please refer to the corresponding RF test document.

Log Window
^^^^^^^^^^

The Log window is used to display the status of the tool. To view the chip serial port print log, please use a general serial port assistant.

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

  1. Close the DownloadTool serial port and open a general serial port assistant, such as `SerialPortUtility <http://alithon.com/downloads>`__;
  2. Configure the serial port number and baud rate, pull down the Boot pin, re-power the chip, and the serial port assistant will print the log like ``waiting for download``;
  3. Close the serial port assistant, open DownloadTool, and start flashing;
  4. After the flashing is completed, pull up the Boot pin, and re-power the chip to enter the working mode. If there are any abnormal behaviors, use a serial port assistant to check.

.. _power-limit-tool:

PowerLimitTool
---------------------------------

PowerLimitTool generates single-country and multi-country phy init bin files by configuring Wi-Fi output power to ensure your products meet the regulatory requirements of different countries or regions.

.. note::

  The following methods can be used to limit Wi-Fi power. If multiple methods are used together, the minimum power value will be taken:

  1. Use the API (``esp_wifi_set_max_tx_power``) to limit the maximum output power;
  2. Configure ``Max Wi-Fi TX Power`` in Menuconfig, which has the same function as the above API, and can limit the maximum output power;
  3. Use the ``Phy Init Bin`` function to modify the phy_init_data.h file in ESP-IDF;
  4. Use the ``Phy Init Bin`` function to generate the phy_init_data.bin file by referring to the introduction in this document.

Generate phy_init_data.bin File
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Under the main interface of EspRFTestTool, click ``Tool``, and select ``PowerLimitTool`` from the dropdown box to open PowerLimitTool.

.. figure:: ../../../_static/rf_test_tool/powerlimit_open.png
    :align: center
    :scale: 80%

    Entry to PowerLimitTool

In the main interface of PowerLimitTool, click the ``Chip`` dropdown box to view the chips supported by the current tool version and select a chip (This section takes ESP32-C3 as an example).

.. figure:: ../../../_static/rf_test_tool/powerlimit_main.png
    :align: center
    :scale: 80%

    PowerLimitTool Main Interface

Click ``Select Table`` and select the TX Power Setting table for your chip.

.. figure:: ../../../_static/rf_test_tool/powerlimit_select.png
    :align: center
    :scale: 80%

    Importing TX Power Setting Table

.. note::

  Description of TX Power Setting Table parameters:

  1. **Config_Switch**: Enable ``Power_By_Rate`` and ``Power_Limit``. Both are set to ``Yes`` by default, indicating they can be adjusted;
  2. **PowerByRate_TargetPower**: Target power for each rate. It is recommended to keep the default value;
  3. **Country_Table**: Currently supported countries (regions). It is extensible;
  4. **Actual_Result**: Actual power of the module. The target power is used by default;
  5. **Default**: Power configuration in the "Default" country code, usually used to identify the power configuration before the country code;
  6. **SRRC_1**: Power configuration in the "SRRC" country code, applicable to mainland China;
  7. **FCC_2**: Power configuration in the "FCC" country code, applicable to the United States;
  8. **CE_3**: Power configuration in the "CE" country code, applicable to Europe;
  9. **NCC_4**: Power configuration in the "NCC" country code, applicable to Taiwan;
  10. **KCC_5**: Power configuration in the "KCC" country code, applicable to Korea;
  11. **MIC_6**: Power configuration in the "MIC" country code, applicable to Japan;
  12. **IC_7**: Power configuration in the "IC" country code, applicable to Canada;

Click ``Open Table``, modify the power value in the corresponding country code table, and select the desired country code in the ``Certification Code`` dropdown box.

.. figure:: ../../../_static/rf_test_tool/powerlimit_country.png
    :align: center
    :scale: 80%

    Modifying TX_Power_Setting

.. note::

  How to modify power values:

  1. Fill in the power value based on the certification result (the certification provides the power attenuation value) (Power value = Target power - Attenuation value/4);
  2. If ``Actual_Result`` is modified, the target power in the above formula needs to be changed to ``Actual_Result``;
  3. Adding or deleting table content is not allowed. For example, FCC only supports channels 1~11, so it is recommended to keep the power values of channels 12~13 in this table the same as channel 11 instead of deleting them;
  4. Except for the low channel and the high channel, the power values of other channels can be set to the same as the middle channel;
  5. The NA part cannot be modified. If the ``Certification Code`` dropdown box is not available, it indicates that the table has been modified and needs to be restored.

Click ``Save Table`` to save the settings and ``Generate`` to generate the phy_init_bin file for the corresponding country code.

.. figure:: ../../../_static/rf_test_tool/powerlimit_generate.png
    :align: center
    :scale: 80%

    Generating phy_init_bin File