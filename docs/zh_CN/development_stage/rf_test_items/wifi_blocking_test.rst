
Wi-Fi 接收阻塞测试
==============================

:link_to_translation:`en:[English]`

Wi-Fi 接收阻塞测试（RX Blocking）是一种在外部干扰状态下评估待测设备接收能力的测试方法，主要用于 CE 认证。

测试准备
---------------------------

硬件连接
^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/usb_to_uart_connection4.png
    :align: center
    :scale: 80%

    UART 连接说明

使用串口板与 ESP 产品串口连接：

- 待测设备 (DUT) CHIP_EN 需默认上拉，如产品设计中未拉高，需将 CHIP_EN 接到 3V3。
- 部分串口通信板内部已交换 RXD 和 TXD, 无需反接，需根据实际情况调整接线。
- ESP 芯片具有上电自校准功能，因此 DUT 上电测试前需先将射频连接线连接至综测仪。


WI-Fi 测试固件烧录
^^^^^^^^^^^^^^^^^^^^^
.. only:: esp32

  - 请参考 EspRFTestTool 工具包中的 DownloadTool 章节，并烧录 ESP32_Wi-Fi_Blocking_BIN，烧录地址：0x1000。

.. only:: esp32c2

  - 请参考 EspRFTestTool 工具包中的 DownloadTool 章节，并烧录 ESP32C2_Wi-Fi_Blocking_BIN，烧录地址：0x0。

.. only:: esp32c3

  - 请参考 EspRFTestTool 工具包中的 DownloadTool 章节，并烧录 ESP32C3_Wi-Fi_Blocking_BIN，烧录地址：0x0。

.. only:: esp32c6

  - 请参考 EspRFTestTool 工具包中的 DownloadTool 章节，并烧录 ESP32C6_Wi-Fi_Blocking_BIN，烧录地址：0x0。

.. only:: esp32s2

  - 请参考 EspRFTestTool 工具包中的 DownloadTool 章节，并烧录 ESP32S2_Wi-Fi_Blocking_BIN，烧录地址：0x1000。

.. only:: esp32s3

  - 请参考 EspRFTestTool 工具包中的 DownloadTool 章节，并烧录 ESP32S3_Wi-Fi_Blocking_BIN，烧录地址：0x0。

.. only:: esp8266

  - 请参考 EspRFTestTool 工具包中的 DownloadTool 章节，并烧录 ESP8266_Wi-Fi_Blocking_BIN，烧录地址：0x0。

- 已烧录固件的样机，可继续往下进行自适应测试。


WI-Fi RX Blocking 测试
---------------------------

查看上电打印
^^^^^^^^^^^^^^^^^^^^^
使用串口通信工具，如友善串口助手（下载页：http://alithon.com/downloads）。
配置端口号，波特率选择 115200，ESP 重新上电后串口打印如下类似信息，表明测试固件 OK：


.. figure:: ../../../_static/rf_test_tool/esp32c2_wifi_signaling.png
    :align: center
    :scale: 80%

    Wi-Fi RX Blocking Power On Logs


Wi-Fi RX Blocking 测试可选择使用串口指令或者使用射频测试工具任意一种方式：

使用串口指令测试
^^^^^^^^^^^^^^^^^^^^^
在串口中依次输入以下指令完成配网、跑流等过程：

::

  op -S -o 1
  sta -C -s CMW-AP -p 12345678


- 第一条指令为配置样机进入 station 模式; 
- 第二条指令为连接AP，SSID 为 CMW-AP ，密码为12345678; 

串口中打印如下信息，表明连接成功，可开始 Wi-Fi RX Blocking 测试。


.. figure:: ../../../_static/rf_test_tool/wifi_blocking_log.png
    :align: center
    :scale: 80%

    Wi-Fi Blocking Connection Logs


使用 ESPRFTestTool 工具测试
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
打开 ESPRFTestTool，配置 ChipType 和 COM，波特率选择115200，打开端口后， 选择 WiFi Adaptivity 测试界面；
在 STA 模式输入 AP SSID 和 AP Password, 点击 Connect AP 连接，连接成功后显示如下打印：

.. figure:: ../../../_static/rf_test_tool/wifi_adptive_connection.png
    :align: center
    :scale: 80%

    Wi-Fi RX Blocking AP Connection

连接成功后即可开始 Wi-Fi RX Blocking 测试。


