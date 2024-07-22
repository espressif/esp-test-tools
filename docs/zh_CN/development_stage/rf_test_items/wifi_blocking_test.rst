
Wi-Fi 接收阻塞测试
==============================

:link_to_translation:`en:[English]`

Wi-Fi 接收阻塞测试（RX Blocking）用于在外部干扰状态下评估待测设备接收能力，主要用于 CE 认证。

搭建测试环境
---------------------------

.. figure:: ../../../_static/rf_test_tool/usb_to_uart_connection.png
    :align: center
    :scale: 80%

    UART 连接说明

**待测设备 (DUT)** 为基于乐鑫芯片或模组设计的产品。待测设备通过 UART 与 USB-to-UART 转接板连接。

.. note::

    - 待测设备的 CHIP_EN 管脚默认上拉，如果产品设计中未拉高，需要手动将 CHIP_EN 接到 3V3 管脚。
    - 部分串口通信板内部已交换 RXD 和 TXD，无需反接，需根据实际情况调整接线。
    - 乐鑫芯片具有上电自校准功能，因此待测设备上电测试前需先将射频连接线连接至测试仪器。

烧录固件
------------------

{IDF_TARGET_WIFI_RX_BLOCKING_FIRMWARE:default="未更新", esp32="`ESP32 Wi-Fi 接收阻塞测试固件 <https://dl.espressif.com/rf/esp32/ESP32_wifi_Adaptivity&Blocking_20210420.bin>`__", esp32c2="`ESP32-C2 Wi-Fi 接收阻塞测试固件 <https://dl.espressif.com/rf/esp32c2/ESP32C2_WiFi_Adaptivity&Blocking_26M_20240416.bin>`__", esp32c3="`ESP32-C3 Wi-Fi 接收阻塞测试固件 <https://dl.espressif.com/rf/esp32c3/ESP32C3_wifi_Adaptivity&Blocking_20220627.bin>`__", esp32c6="`ESP32-C6 Wi-Fi 接收阻塞测试固件 <https://dl.espressif.com/rf/esp32c6/ESP32C6_wifi_Adaptivity&Blocking_20230704.bin>`__", esp32s2="`ESP32-S2 Wi-Fi 接收阻塞测试固件 <https://dl.espressif.com/rf/esp32s2/ESP32S2_wifi_Adaptivity&Blocking_20220826.bin>`__", esp32s3="`ESP32-S3 Wi-Fi 接收阻塞测试固件 <https://dl.espressif.com/rf/esp32s3/ESP32S3_wifi_Adaptivity&Blocking_20230328.bin>`__", esp8266="`ES8266 Wi-Fi 接收阻塞测试固件 <https://dl.espressif.com/RF/ESP8266&8285_adaptivity&blocking_bin_20220824_115200.bin>`__"}

{IDF_TARGET_FLASH_ADDRESS:default="0x0", esp32="0x1000", esp32s2="0x1000"}

1. 打开 DownloadTool 工具。

2. 设置 ChipType，Com Port，Baud Rate，点击 Open，选择下载到 Flash。

3. 将 {IDF_TARGET_WIFI_RX_BLOCKING_FIRMWARE} 通过 UART 烧录至 {IDF_TARGET_FLASH_ADDRESS}。

烧录完成后，继续以下步骤进行自适应测试。

开始测试
---------------------------

查看上电打印
^^^^^^^^^^^^^^^^^^^^^

使用串口通信工具，如 `友善串口助手 <http://alithon.com/downloads>`_，配置端口号，波特率设置为 115200，待测设备重新上电后串口如果打印类似如下信息，则可确认测试状态 OK：

.. figure:: ../../../_static/rf_test_tool/esp32c2_wifi_signaling.png
    :align: center
    :scale: 80%

    设备上电串口打印日志

接下来可选择 `使用串口指令测试`_ 或者 `使用 EspRFTestTool 工具测试`_。

使用串口指令测试
^^^^^^^^^^^^^^^^^^^^^

在串口中依次输入以下指令以进行配网：

::

  \\设备配网
  \\配置样机进入 station 模式
  op -S -o 1

  \\连接 AP，SSID 为 CMW-AP，密码为 12345678
  sta -C -s CMW-AP -p 12345678

.. note::

    - ``-p`` 参数用于设置 AP 密码。如果 AP 无密码，则无需使用该参数。

串口中打印如下信息，表明连接成功，可进行 Wi-Fi 接收阻塞测试。

.. figure:: ../../../_static/rf_test_tool/wifi_blocking_log.png
    :align: center
    :scale: 80%

    设备配网串口打印日志

使用 ESPRFTestTool 工具测试
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- 打开 `EspRFTestTool 工具包 <https://dl.espressif.com/RF/EspRFTestTool_v3.6_Manual.zip>`_，配置 ChipType 与 COM，波特率选择 115200，打开端口后，选择 WiFi Adaptivity 测试界面。

- 在 STA 模式输入 AP ssid 和 AP pwd, 点击 Connect AP 连接。

- 如果打印类似如下 log，则表明配网成功：

.. figure:: ../../../_static/rf_test_tool/wifi_adptive_connection.png
    :align: center
    :scale: 80%

    设备配网

配网成功后即可开始 Wi-Fi 接收阻塞测试。
