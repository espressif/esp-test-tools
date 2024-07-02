EspRFTestTool Toolkit
=============================

:link_to_translation:`zh_CN:[中文]`

The `EspRFTestTool Toolkit <https://dl.espressif.com/RF/EspRFTestTool_v3.6_Manual.zip>`_ toolkit is a radio frequency test tool provided by Espressif, which includes the EspRFTestTool, DownloadTool, and PowerLimitTool.

- `EspRFTestTool <esp-rf-test-tool>`_: Used for related radio frequency tests;
- `DownloadTool <download-tool>`_: Used to download the firmware required for radio frequency testing;
- `PowerLimitTool <power-limit-tool>`_: Used to generate customized phy_init_data firmware.

.. note::

   In this article, the **EspRFTestTool toolkit** refers to the collection of the three tools, while the **EspRFTestTool** refers to this single tool.

.. _esp-rf-test-tool:

EspRFTestTool
---------------------------------

The main interface of the EspRFTestTool toolkit is the EspRFTestTool, which includes the serial port configuration area, download configuration area, radio frequency test configuration area, and log window.

.. figure:: ../../../_static/rf_test_tool/esprftesttool_tool.png
    :align: center
    :scale: 80%

    EspRFTestTool

Serial Port Configuration Area
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/esprftesttool_com.png
    :align: center
    :scale: 80%

    EspRFTestTool Serial Port Configuration Area

- **ChipType**: Select the chip model;
- **COM**: Select the serial port number;
- **BaudRate**: Select the baud rate;
- **Open**: Open the serial port;
- **Close**: Close the serial port.

After configuring the serial port, you can perform quick burning and radio frequency testing functions.

Download Configuration Area
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/esprftesttool_download.png
    :align: center
    :scale: 80%

    EspRFTestTool Download Configuration Area

Generally, the `DownloadTool <download-tool>`_ is used to download the firmware required for radio frequency testing, but for some simple firmware, such as non-signaling test firmware and adaptivity test firmware, the EspRFTestTool can be used for quick burning.

- Pull down the Boot pin and re-power the chip to enter download mode;
- Burning is done by default through UART;
- Select to burn to flash;
- Click Select Bin to select the bin file to be burned;
- Click Load Bin to start burning;
- After burning is completed, pull up the Boot pin and re-power the chip to enter the working mode.

Radio Frequency Test Configuration Area
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/esprftesttool_rftest.png
    :align: center
    :scale: 80%

    EspRFTestTool Radio Frequency Test Configuration Area

After burning the firmware, you can perform the corresponding radio frequency tests:

- **Wi-Fi Test**: Used for Wi-Fi Non-Signaling Test;
- **BT Test**: Used for Bluetooth/Bluetooth LE Non-Signaling Test;
- **Wi-Fi Adaptivity**: Used for Wi-Fi Adaptivity Test;
- **Zigbee Test**: Used for 802.15.4 Non-Signaling Test;
- **Manual**: Can be used for serial port command input.

For specific parameter configuration, please refer to the corresponding radio frequency test document.

Log Window
^^^^^^^^^^

The Log window is used to display the status of the tool. To view the chip serial port print log, please use the general serial port assistant.

.. _download-tool:

DownloadTool Tool
---------------------------------

Click on Tool in the toolbar, select DownloadTool, and enter the DownloadTool tool interface.

.. figure:: ../../../_static/rf_test_tool/downloadtool_main.png
    :align: center
    :scale: 80%

    DownloadTool Tool Entry

Follow the steps below to burn the firmware:

- Set the Chip Type, COM Port, Baud Rate, then click Open to open the serial port;
- Choose to burn to flash;
- Select the firmware to be burned and download it to the specified address;
- Confirm that the chip has entered download mode, click Start Load to start burning, and the SUCC sign is displayed after burning is completed;
- After the burning is completed, click Close to close the serial port.

.. figure:: ../../../_static/rf_test_tool/downloadtool_select.png
    :align: center
    :scale: 80%

    DownloadTool Interface

.. note::

  How to confirm that the chip has entered download mode:

  1. Close the DownloadTool serial port, open the general serial port assistant, such as Friendly Serial Port Assistant (download page: http://alithon.com/downloads);
  2. Configure the serial port number and baud rate, pull down the Boot pin, the chip re-powers, and the serial port assistant will print logs such as waiting for download;
  3. Close the serial port assistant, open DownloadTool, and start burning;
  4. After the burning is completed, pull up the Boot pin, the chip re-powers, and can enter the working mode. If there are any abnormalities, confirm with the serial port assistant.

.. _power-limit-tool:

PowerLimitTool Tool
---------------------------------

PowerLimitTool can be used to configure Wi-Fi output power, generate single-country and multi-country phy init bin files, and meet the regulatory requirements of customer products in different countries or regions.

.. note::

  The following methods can be used to limit Wi-Fi power. If multiple methods are used together, the minimum power value will be taken:

  1. Use the API (esp_wifi_set_max_tx_power) to limit the maximum output power;
  2. Configure Max Wi-Fi TX Power in Menuconfig, which has the same function as the above API, and can limit the maximum output power;
  3. Use the Phy Init Bin function to modify the phy_init_data.h file in ESP-IDF;
  4. Use the Phy Init Bin function to generate the phy_init_data.bin file, refer to the introduction in this article.

Generate phy_init_data.bin file
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Under the main interface of ESPRFTestTool, click Tool, select PowerLimitTool from the drop-down box, and open the PowerLimitTool tool.

.. figure:: ../../../_static/rf_test_tool/powerlimit_open.png
    :align: center
    :scale: 80%

    PowerLimitTool Tool Entry

Enter the main interface of PowerLimitTool, the Chip drop-down box displays the chip models supported by the current tool version, select the corresponding chip (take ESP32-C3 as an example).

.. figure:: ../../../_static/rf_test_tool/powerlimit_main.png
    :align: center
    :scale: 80%

    PowerLimitTool Main Interface

Click Select Table, select the TX Power Setting table for the corresponding chip.

.. figure:: ../../../_static/rf_test_tool/powerlimit_select.png
    :align: center
    :scale: 80%

    Import TX Power Setting Table

.. note::

  Explanation of TX Power Setting Table parameters:

  1. **Config_Switch**: Enable Power_By_Rate and Power_Limit, both are set to Yes by default, indicating they can be adjusted;
  2. **PowerByRate_TargetPower**: Target power for each rate, it is recommended to keep the default value;
  3. **Country_Table**: Currently supported countries (regions), can be expanded;
  4. **Actual_Result**: Actual power measured by the module, the target power is used by default;
  5. **Default**: Power configuration in the "Default" country code, usually used to identify the power configuration before the country code;
  6. **SRRC_1**: Power configuration in the "SRRC" country code, applicable to mainland China;
  7. **FCC_2**: Power configuration in the "FCC" country code, applicable to the United States;
  8. **CE_3**: Power configuration in the "CE" country code, applicable to Europe;
  9. **NCC_4**: Power configuration in the "NCC" country code, applicable to Taiwan;
  10. **KCC_5**: Power configuration in the "KCC" country code, applicable to Korea;
  11. **MIC_6**: Power configuration in the "MIC" country code, applicable to Japan;
  12. **IC_7**: Power configuration in the "IC" country code, applicable to Canada;

Click Open Table, modify the desired power value in the corresponding country code table, and select the desired country code in the Certification Code dropdown box.

.. figure:: ../../../_static/rf_test_tool/powerlimit_country.png
    :align: center
    :scale: 80%

    Modify TX_Power_Setting

.. note::

  How to modify power values:

  1. Fill in the power value based on the certification result (the certification provides the power attenuation value) (Power value = Target power - Attenuation value/4);
  2. If Actual_Result is modified, the target power in the above formula needs to be changed to Actual_Result;
  3. You cannot add or delete table content, for example, FCC only supports channels 1~11, it is recommended that the power values of channels 12~13 in this table remain the same as channel 11, but cannot be deleted;
  4. Except for low and high channels, the power values of other middle channels can be set to be consistent with the middle channels;
  5. The NA part cannot be modified. If the Certification Code cannot be selected from the dropdown, it indicates that the table has been modified and needs to be restored.

Click Save Table to save the settings, click Generate to generate the phy_init_bin file for the corresponding country code.

.. figure:: ../../../_static/rf_test_tool/powerlimit_generate.png
    :align: center
    :scale: 80%

    Generate phy_init_bin file