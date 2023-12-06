射频非信令测试
===========================

:link_to_translation:`en:[English]`

Wi-Fi 定频测试
---------------------------

本章介绍如何在基于 ESP 芯片或模组的产品中运行定频测试固件。

.. _environment_setup:

搭建环境
^^^^^^^^^^^^^^^^^^^^^

在硬件上，ESP 芯片的 EN 脚通常在设计时通过 RC 延时电路连接到电源线 3V3 上。将芯片 TXD0、RXD0、Boot 键、3V3 和 GND 通过杜邦线焊接出来，用于连接串口板对应的 pin 脚。串口板通过 USB 线连接到 PC，PC 通过串口板与待测样机通信并供电串口板。待测样机的环境搭建框图见图 4。

.. figure:: ../../_static/rf_test_tool/environment_setup_cn.jpg
    :align: center
    :scale: 120%

    环境搭建框图

当测试传导时，RF cable 接到 ESP RF 匹配后面，若 Π 型匹配后面同时有连接天线，则需要将天线断开。当 RF 匹配包含在模组屏蔽罩内，RF cable 应焊接到屏蔽罩外，见图 5。
当测试辐射时，RF 匹配后面直接接天线，并保证样机的天线附近无遮挡。

.. figure:: ../../_static/rf_test_tool/rf_cable_connection.jpg
    :align: center
    :scale: 90%

    模组传导测试 RF cable 接线图

表 8 所示为运行各芯片测试固件的硬件环境，与下载固件的硬件环境有细微差异（粗体标出）。

.. list-table:: 运行测试固件硬件连接
  :widths: 30 70

  * - 芯片型号
    - 连接说明
  * - | ESP8266
      | ESP8285
    - | • 3V3/CH_EN 管脚连接到 3.3 V 电源
      | • RXD/TXD/GND 管脚连接到串口模块的对应引脚上，使 PC 与设备通信
      | • MTDO (GPIO15) 管脚下拉
      | • **GPIO0 管脚悬空**
  * - | ESP32
      | ESP32-S2
      | ESP32-S3
    - | • 3V3/CH_EN 管脚连接到 3.3 V 电源
      | • RXD/TXD/GND 管脚连接到串口模块的对应引脚上，使 PC 与设备通信
      | • **GPIO0 管脚悬空**
  * - | ESP32-C3
      | ESP32-C6
      | ESP32-H2
    - | • 3V3/CH_EN 管脚连接到 3.3 V 电源
      | • RXD/TXD/GND 管脚连接到串口模块的对应引脚上，使 PC 与设备通信
      | • **GPIO9 管脚悬空**，GPIO8 管脚上拉时

运行固件
^^^^^^^^^^^^^^^^^^

运行 Wi-Fi 定频测试固件
""""""""""""""""""""""""""""""""""""""""""

- 断开样机的 IO0，然后再拨动串口板电源开关重新上电。
- 在下载时打开的 EspRFTestTool 中点击 WiFi Test，Test Mode 选择 TX continues。
- 认证如果需要降功率，在 Attenuation(0.25dB) 里填写数值来实现，单位为 0.25 dB，如填写 20，则表示从默认最大功率降低 20x0.25=5dB，Attenuation 的默认数值是 0，表示不衰减。
- 其它选项根据实验室测试需要进行选择，选择完参数点击 start 即可定频测试，工具里会有相应的 log 显示，图 6 所示为 ESP32 的定频测试界面。

.. figure:: ../../_static/rf_test_tool/wifi_fixed_frequency_test.jpg
    :align: center
    :scale: 90%

    ESP32 Wi-Fi 定频测试界面

- 如果测试接收，Test Mode 选择 RX packet，其它根据测试需要进行相应选择。ESP32 Wi-Fi 接收测试界面如图 7 所示。

.. figure:: ../../_static/rf_test_tool/wifi_receive_test.jpg
    :align: center
    :scale: 120%

    ESP32 Wi-Fi 接收测试界面

运行蓝牙定频测试固件
"""""""""""""""""""""""""""""""""""""

蓝牙定频测试固件与 Wi-Fi 定频测试固件相同。

- 打开 EspRFTestTool 测试工具，选择待测试的芯片类型。ESP8266、ESP32-S2 系列芯片没有蓝牙功能，所以无需测试。ESP32-C3 系列芯片的蓝牙只支持 BLUETOOTH LE。
- 打开 BT Test 页面，配置相关参数：Power Level 一般选择 4，其它设置根据实测需要来选择，图 8 显示的为 ESP32 蓝牙定频测试界面。

.. figure:: ../../_static/rf_test_tool/bt_test.jpg
    :align: center
    :scale: 120%

    蓝牙测试界面


蓝牙/低功耗蓝牙定频测试
-------------------------------------------


Zigbee 定频测试
----------------------------