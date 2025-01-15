EspRFTestTool 工具包
=============================

:link_to_translation:`en:[English]`

**EspRFTestTool 工具包** 是乐鑫提供的射频测试工具，包含 EspRFTestTool 工具、DownloadTool 工具和 PowerLimitTool 工具。

- `EspRFTestTool 工具`_：用于相关射频测试；
- `DownloadTool 工具`_：用于下载射频测试中所需的固件；
- `PowerLimitTool 工具`_：用于生成定制化 phy_init_data 固件。

**下载地址**：`EspRFTestTool 工具包 <https://dl.espressif.com/RF/EspRFTestTool_v4.6_Manual.zip>`__

该压缩包不仅包含 EspRFTestTool 工具包，还附带全部 :doc:`RF 测试项目 <../rf_test_items/index>` 所需的测试固件，方便熟悉测试流程的用户直接使用固件进行操作。

.. note::

   在本文中， **EspRFTestTool 工具包** 指的是三个工具的集合，而 **EspRFTestTool 工具** 指的是该单一工具。

.. _esp-rf-test-tool:

EspRFTestTool 工具
---------------------------------

EspRFTestTool 工具包主界面就是 EspRFTestTool 工具，包含串口配置区、下载配置区、射频测试配置区，以及 log 窗口。

.. figure:: ../../../_static/rf_test_tool/esprftesttool_tool.png
    :align: center
    :scale: 80%

    EspRFTestTool 工具

串口配置区
^^^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/esprftesttool_com.png
    :align: center
    :scale: 80%

    EspRFTestTool 串口配置区

- **ChipType**：选择芯片型号；
- **COM**：选择串口号；
- **BaudRate**：选择波特率；
- **Open**：打开串口；
- **Close**：关闭串口。

串口配置完成后，可进行快速烧录和射频测试。

下载配置区
^^^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/esprftesttool_download.png
    :align: center
    :scale: 80%

    EspRFTestTool 下载配置区

一般使用 `DownloadTool 工具`_ 下载射频测试中所需的固件，但是对于一些简单的固件，如非信令测试固件与自适应测试固件，可直接使用 EspRFTestTool 工具进行快速烧录。

- 拉低 Boot 管脚后对芯片重新上电使芯片进入下载模式；
- 默认通过 ``UART`` 进行烧录；
- 选择烧录至 ``flash`` 中；
- 点击 ``Select Bin`` 选择要烧录的 bin 文件；
- 点击 ``Load Bin`` 即可开始烧录；
- 烧录完成后，拉高 Boot 管脚对芯片重新上电使芯片进入工作模式。

射频测试配置区
^^^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/esprftesttool_rftest.png
    :align: center
    :scale: 80%

    EspRFTestTool 射频测试配置区

烧录固件后，可进行相应的射频测试：

- **Wi-Fi Test**：用于 Wi-Fi 非信令测试；
- **BT Test**：用于蓝牙及低功耗蓝牙非信令测试；
- **Wi-Fi Adaptivity**：用于 Wi-Fi 自适应测试；
- **Zigbee Test**：用于 802.15.4 非信令测试；
- **Manual**：用于输入串口指令。

具体参数配置可参考对应的射频测试文档。

Log 窗口
^^^^^^^^^^^^^

Log 窗口中用于展示工具状态，如需查看芯片串口打印 log，请使用通用串口助手，如 `友善串口助手 <http://alithon.com/downloads>`__。

.. _download-tool:

DownloadTool 工具
---------------------------------

在工具栏中点击 ``Tool``，选择 ``DownloadTool``，进入 DownloadTool 工具界面。

.. figure:: ../../../_static/rf_test_tool/downloadtool_main.png
    :align: center
    :scale: 80%

    DownloadTool 工具入口

按照以下步骤进行固件烧录：

- 设置芯片类型 ``Chip Type``、串口 ``COM Port``、波特率 ``Baud Rate``，然后点击 ``Open`` 打开串口；
- 选择烧录到 ``flash``；
- 选择要烧录的固件，并下载到指定地址；
- 确认芯片已进入下载模式，点击 ``Start Load`` 开始烧录。烧录完成后显示 ``SUCC`` 标志；
- 烧录完成后，点击 ``Close`` 关闭串口。

.. figure:: ../../../_static/rf_test_tool/downloadtool_select.png
    :align: center
    :scale: 80%

    DownloadTool 界面

.. note::

  如何确认芯片进入下载模式：

  1. 关闭 DownloadTool 串口，打开通用串口助手，如 `友善串口助手 <http://alithon.com/downloads>`__；
  2. 配置串口号和波特率，拉低 Boot 管脚，芯片重新上电，串口助手中会打印 ``waiting for download`` 等 log;
  3. 关闭串口助手，打开 DownloadTool，可开始烧录；
  4. 烧录完成后，拉高 Boot 管脚，芯片重新上电，可进入工作模式。如有异常，使用串口助手确认。

.. note::

    DownloadTool 工具默认烧录到 ``RAM``，如需填写烧录地址，需先切换到烧录至 ``flash``。

.. _power-limit-tool:

PowerLimitTool 工具
---------------------------------

PowerLimitTool 可用于配置 Wi-Fi 输出功率，生成单国和多国的 phy_init_bin 文件，满足客户产品在不同国家或地区的法规需求。

.. note::

  可使用以下几种方式来限制 Wi-Fi 功率，如多种方式共用，则取其功率的最小值：

  1. 使用 API (``esp_wifi_set_max_tx_power``)，可限制最大输出功率；
  2. 在 Menuconfig 中配置 ``Max Wi-Fi TX Power``，与上述 API 功能相同，可限制最大输出功率；
  3. 使用 ``Phy Init Bin`` 功能，在 ESP-IDF 中修改 phy_init_data.h 文件；
  4. 使用 ``Phy Init Bin`` 功能，生成 phy_init_data.bin 文件，参考本文介绍。

在 EspRFTestTool 主界面下，点击 ``Tool``，选择下拉框中的 ``PowerLimitTool``，打开 PowerLimitTool 工具。

.. figure:: ../../../_static/rf_test_tool/powerlimit_open.png
    :align: center
    :scale: 80%

    PowerLimitTool 工具入口

1. 进入 PowerLimitTool 主界面，``Chip`` 下拉框中显示当前工具版本支持的芯片型号，选择对应的芯片（以 ESP32-C3 为例）。

.. figure:: ../../../_static/rf_test_tool/powerlimit_main.png
    :align: center
    :scale: 80%

    PowerLimitTool 工具主界面

2. 点击 ``Select Table``，选择对应芯片的 TX Power Setting 表格。

.. figure:: ../../../_static/rf_test_tool/powerlimit_select.png
    :align: center
    :scale: 80%

    导入 TX Power Setting 表格

3. 点击 ``Open Table``，在对应国家码表中修改期望的功率值，在 ``Certification Code`` 下拉框中选择期望的国家码。

.. figure:: ../../../_static/rf_test_tool/powerlimit_country.png
    :align: center
    :scale: 80%

    修改 TX_Power_Setting

.. note::

  TX Power Setting 表格参数说明：

  1. **Config_Switch**：使能 ``Power_By_Rate`` 和 ``Power_Limit``，默认均选择 ``Yes``，表示均可调整；
  2. **PowerByRate_TargetPower**：各速率目标功率，建议保持默认值；
  3. **Country_Table**：当前默认支持的国家（地区），可扩展；
  4. **Actual_Result**：模组实测功率，默认使用目标功率；
  5. **Default**：国家码中 Default 功率配置，通常用于识别国家码前的功率配置；
  6. **SRRC_1**：国家码中 SRRC 的功率配置，适用于中国大陆；
  7. **FCC_2**：国家码中 FCC 的功率配置，适用于美国；
  8. **CE_3**：国家码中 CE 的功率配置，适用于欧洲；
  9. **NCC_4**：国家码中 NCC 的功率配置，适用于台湾地区；
  10. **KCC_5**：国家码中 KCC 的功率配置，适用于韩国；
  11. **MIC_6**：国家码中 MIC 的功率配置，适用于日本；
  12. **IC_7**：国家码中 IC 的功率配置，适用于加拿大；

.. note::

  关于如何修改功率值：

  1. 根据认证结果（认证提供功率衰减值）填写功率值（功率值 = 目标功率 - 衰减值/4）；
  2. 如果修改了 ``Actual_Result``，上述公式中的目标功率需改为 ``Actual_Result``；
  3. 不能增删表格内容，例如 FCC 仅支持 1~11 信道，此表中 12~13 信道功率值建议与 11 信道保持相同，但不可删除；
  4. 除低高信道外，其它信道功率与中间信道保持一致；
  5. NA 的部分不可修改。如果 ``Certification Code`` 无法下拉选择，表明表格被改动，需还原。

4. 点击 ``Save Table`` 保存设置，在 ``Certification Code`` 下拉项中选择需要的认证，点击 ``Generate`` 生成对应国家码的 phy_init_bin 文件。

.. figure:: ../../../_static/rf_test_tool/powerlimit_generate.png
    :align: center
    :scale: 80%

    生成 phy_init_bin 文件

.. note::

    1. 下拉选项 ``Certification Code`` 中包含单个认证和 ``Multiple Country`` 及 ``Custom``。
    2. 选择单认证会生成对应认证的单独 phy_init_bin 文件，文件包含除校验控制信息外共 128 字节。
    3. 选择 ``Multiple Country`` 会生成包含 Default 和 SRRC、FCC、CE、NCC、KCC、MIC 与 IC 七国认证的 Combined phy_init_bin 文件，包含了 8*128 字节。
    4. 选择 ``Custom``，根据自定义选择生成单个或多国认证 phy_init_bin 文件。

{IDF_TARGET_RF_NON_SIGNALING_FIRMWARE_COPY:default="Not Updated", esp32="|ESP32 射频非信令测试固件|", esp32c2="|ESP32-C2 射频非信令测试固件 (26 MHz) or ESP32-C2 射频非信令测试固件 (40 MHz)|", esp32c3="|ESP32-C3 射频非信令测试固件|", esp32c6="|ESP32-C6 射频非信令测试固件|", esp32s2="|ESP32-S2 射频非信令测试固件|", esp32s3="|ESP32-S3 射频非信令测试固件|", esp8266="|ESP8266 射频非信令测试固件 (26 MHz) or ESP8266 射频非信令测试固件 (40 MHz)|", esp32h2="|ESP32-H2 射频非信令测试固件|"}

{IDF_TARGET_RF_NON_SIGNALING_FIRMWARE_ADDRESS:default="0x0", esp32="0x1000", esp32s2="0x1000"}

5. 使用非信令或信令测试验证 phy_init_bin 是否生效。以非信令测试为例, 首先使用 `DownloadTool 工具`_ 将生成的 phy_init_bin 文件下载到待测产品。

- 从 ``Tool`` 选项栏中选择 ``DownloadTool``，进入 ``DownloadTool`` 界面
- 参考 `DownloadTool 工具`_ 操作步骤，将 phy_init_bin 文件与相应的 RF 测试固件烧录至 ``flash``。
- 其中 phy_init_bin 的烧录地址为 ``0x1fc000``, RF 测试固件 {IDF_TARGET_RF_NON_SIGNALING_FIRMWARE_COPY} 的烧录地址为 {IDF_TARGET_RF_NON_SIGNALING_FIRMWARE_ADDRESS}。

.. note::

    关于信令测试，替换原有的 phy_init_bin 即可，请参考 :doc:`RF 测试项目 <../rf_test_items/index>` 中相关文档。

.. figure:: ../../../_static/rf_test_tool/phyinit_download_start.png
    :align: center
    :scale: 80%

    烧录 phy_init_bin 文件

6. 使用 Wi-Fi 仪器测试输出功率，确认 phy_init_bin 是否生效。

- 打开 `EspRFTestTool 工具`_
- 选择对应的 ``ChipType``、``COM``、``BaudRate``、点击 ``Open`` 打开串口；
- 选择 ``WiFi Test`` 界面，选择 ``Test Mode``、``Rate``、``BandWidth``、``Channel``；
- 设置 ``Attenuation`` 默认值 0，选择 ``Duty Cycle`` 为 10%；
- 不勾选 ``Certification EN`` 代表不使能 Phy init，此时 start 发包测试代表模组的初始性能。
- 勾选 ``Certification EN`` 代表使能 Phy init，此时 start 发包测试代表模组的认证功率性能。
- 默认地址为 phy_init_bin 的烧录地址 0x1fc000，如烧录地址变动，此处需做相应改变。
- 对于 Multiple Country，在 ``Certification Code`` 中可选择其所包含的认证国家代码。

.. figure:: ../../../_static/rf_test_tool/powerlimittool_rf_test_setting.png
    :align: center
    :scale: 80%

    RF Test 设置界面

.. only:: esp32

    {IDF_TARGET_NAME} 平均输出功率典型值
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. list-table::
        :header-rows: 1
        :widths: 20 20
        :align: center

        * - 传输速率
          - 平均输出功率典型值 (dBm)
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

    {IDF_TARGET_NAME} 平均输出功率典型值
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. list-table::
        :header-rows: 1
        :widths: 20 20
        :align: center

        * - 传输速率
          - 平均输出功率典型值 (dBm)
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

    {IDF_TARGET_NAME} 平均输出功率典型值
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. list-table::
        :header-rows: 1
        :widths: 20 20
        :align: center

        * - 传输速率
          - 平均输出功率典型值 (dBm)
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

    {IDF_TARGET_NAME} 平均输出功率典型值
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. list-table::
        :header-rows: 1
        :widths: 20 20
        :align: center

        * - 传输速率
          - 平均输出功率典型值 (dBm)
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

    {IDF_TARGET_NAME} 平均输出功率典型值
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. list-table::
        :header-rows: 1
        :widths: 20 20
        :align: center

        * - 传输速率
          - 平均输出功率典型值 (dBm)
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

    {IDF_TARGET_NAME} 平均输出功率典型值
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. list-table::
        :header-rows: 1
        :widths: 20 20
        :align: center

        * - 传输速率
          - 平均输出功率典型值 (dBm)
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



.. |ESP32 射频非信令测试固件| replace:: `ESP32 射频非信令测试固件 <https://dl.espressif.com/RF/ESP32_RFTest_V191_482eb73_20230724.bin>`__
.. |ESP32-C2 射频非信令测试固件 (26 MHz) or ESP32-C2 射频非信令测试固件 (40 MHz)| replace:: `ESP32-C2 射频非信令测试固件 (26 MHz) <https://dl.espressif.com/RF/ESP32-C2_RFTest_V203_26M_7a8831de_20240730.bin>`__ or `ESP32-C2 射频非信令测试固件 (40 MHz) <https://dl.espressif.com/RF/ESP32-C2_RFTest_V203_40M_7a8831de_20240730.bin>`__ 
.. |ESP32-C3 射频非信令测试固件| replace:: `ESP32-C3 射频非信令测试固件 <https://dl.espressif.com/RF/ESP32-C3_RFTest_V117_402fb258_20240902.bin>`__
.. |ESP32-C6 射频非信令测试固件| replace:: `ESP32-C6 射频非信令测试固件 <https://dl.espressif.com/RF/ESP32-C6_RFTest_V105_b0352c7_20240827.bin>`__
.. |ESP32-S2 射频非信令测试固件| replace:: `ESP32-S2 射频非信令测试固件 <https://dl.espressif.com/RF/ESP32-S2_RFTest_V207_545e2ab_20230829.bin>`__
.. |ESP32-S3 射频非信令测试固件| replace:: `ESP32-S3 射频非信令测试固件 <https://dl.espressif.com/RF/ESP32-S3_RFTest_V112_b7bc9b9_20240430.bin>`__
.. |ESP8266 射频非信令测试固件 (26 MHz) or ESP8266 射频非信令测试固件 (40 MHz)| replace:: `ESP8266 射频非信令测试固件 (26 MHz) <https://dl.espressif.com/RF/ESP8266_RFTest_153_20231018_26M.bin>`__ or `ESP8266 射频非信令测试固件 (40 MHz) <https://dl.espressif.com/RF/ESP8266_RFTest_153_20231020_40M.bin>`__
.. |ESP32-H2 射频非信令测试固件| replace:: `ESP32-H2 射频非信令测试固件 <https://dl.espressif.com/RF/ESP32-H2_RFTest_V203_596642e_20250221.bin>`__

