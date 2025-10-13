Wi-Fi 信令测试
==============================

:link_to_translation:`en:[English]`

Wi-Fi 信令测试用于评估和验证无线网络设备 Wi-Fi 信令功能，主要用于确保设备在各种操作环境中能够稳定可靠地通信。Wi-Fi 信令测试通常用于设备的 OTA (Over-The-Air) 性能评估，包括 TRP（Total Radiated Power，总辐射功率）和 TIS（Total Isotropic Sensitivity，总各向同性灵敏度）测试。

搭建测试环境
------------------------

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

{IDF_TARGET_WIFI_SIGNALLING_SINGLE_FIRMWARE:default="联系乐鑫获取最新固件", esp32="|ESP32 Wi-Fi 信令测试固件（单国）|", esp32c2="|ESP32-C2 Wi-Fi 信令测试固件（单国）|", esp32c6="|ESP32-C6 Wi-Fi 信令测试固件（单国）|", esp32c3="|ESP32-C3 Wi-Fi 信令测试固件（单国）|", esp32s3="|ESP32-S3 Wi-Fi 信令测试固件（单国）|", esp32s2="|ESP32-S2 Wi-Fi 信令测试固件（单国）|"}

{IDF_TARGET_WIFI_SIGNALLING_MULTIPLE_FIRMWARE:default="联系乐鑫获取最新固件", esp32="|ESP32 Wi-Fi 信令测试固件（多国）|", esp32c2="|ESP32-C2 Wi-Fi 信令测试固件（多国）|", esp32c6="|ESP32-C6 Wi-Fi 信令测试固件（多国）|", esp32c3="|ESP32-C3 Wi-Fi 信令测试固件（多国）|", esp32s3="|ESP32-s3 Wi-Fi 信令测试固件（多国）|", esp32s2="|ESP32-S2 Wi-Fi 信令测试固件（多国）|"}

{IDF_TARGET_FLASH_ADDRESS:default="0x0", esp32="0x1000", esp32s2="0x1000"}

1. 打开 :ref:`download-tool`。

2. 设置 ``ChipType``，``Com Port``，``Baud Rate``，点击 ``Open``，选择下载到 ``Flash``。

3. {IDF_TARGET_WIFI_SIGNALLING_SINGLE_FIRMWARE} 支持单国国家码，{IDF_TARGET_WIFI_SIGNALLING_MULTIPLE_FIRMWARE} 支持多国国家码。它们分别都包括 **bootloader.bin**， **partition-table.bin**， **phy_init_data.bin** 与 **ssc.bin** 4 个 bin 文件。

将 {IDF_TARGET_WIFI_SIGNALLING_SINGLE_FIRMWARE} 或 {IDF_TARGET_WIFI_SIGNALLING_MULTIPLE_FIRMWARE} 解压后，分别将 4 个 bin 文件通过 UART 烧录至以下地址。

.. list-table::
   :header-rows: 1

   * - bin 文件
     - 烧录地址
   * - bootloader.bin
     - {IDF_TARGET_FLASH_ADDRESS}
   * - partition-table.bin
     - 0x8000
   * - phy_init_data.bin
     - 0xF000
   * - ssc.bin
     - 0x10000

.. only:: esp32 or esp32s2

    .. figure:: ../../../_static/rf_test_tool/wifi_signaling_firmware_esp32_esp32s2.png
        :align: center
        :scale: 80%

        烧录固件示意图

.. only:: not esp32 and not esp32s2

    .. figure:: ../../../_static/rf_test_tool/wifi_signaling_firmware_others.png
        :align: center
        :scale: 80%

        烧录固件示意图

烧录完成后，继续以下步骤进行信令测试。

.. _wifi-signalling-test:

开始测试
---------------

查看上电打印日志
^^^^^^^^^^^^^^^^^^^^^

.. note::

    .. only:: esp8266 or esp32c2

        如果主晶振为 26 MHz，``BaudRate`` 设置为 74880；如果主晶振为 40 MHz，``BaudRate`` 设置为 115200。

    .. only:: not esp32c2 and not esp8266

        ``BaudRate`` 设置为 115200。


使用串口通信工具，如 `友善串口助手 <http://alithon.com/downloads>`__，配置端口号和波特率。待测设备重新上电后，如果串口输出类似如下信息，则可确认测试状态正常：

.. figure:: ../../../_static/rf_test_tool/esp32c2_wifi_signaling.png
    :align: center
    :scale: 80%

    设备上电串口打印日志

设备配网
^^^^^^^^^^^^^^^^^^^^^

在串口中依次输入以下两条指令以完成配网。

::

  //设备配网
  //配置样机进入 station 模式
  op -S -o 1

  //连接 AP，SSID 为 CMW-AP，密码为 12345678
  sta -C -s CMW-AP -p 12345678

.. note::

    ``-p`` 参数用于设置 AP 密码。如果 AP 无密码，则无需使用该参数。

station 设备分配到 IP 地址后，表明 Wi-Fi 连接成功，会打印如下所示 log：

.. figure:: ../../../_static/rf_test_tool/esp32c2_wifi_signaling_connection.png
    :align: center
    :scale: 80%

    设备配网串口打印日志

待测设备配网成功后，即可使用射频测试仪器进行 Wi-Fi 信令测试。


.. |ESP32 Wi-Fi 信令测试固件（单国）| replace:: `ESP32 Wi-Fi 信令测试固件（单国） <https://dl.espressif.com/rf/esp32/ESP32ECO3_Signaling_V4.3_SinglePhy_20230525.zip>`__

.. |ESP32 Wi-Fi 信令测试固件（多国）| replace:: `ESP32 Wi-Fi 信令测试固件（多国） <https://dl.espressif.com/rf/esp32/ESP32ECO3_Signaling_V4.3_MultiPhy_20230525.zip>`__

.. |ESP32-C2 Wi-Fi 信令测试固件（单国）| replace:: `ESP32-C2 Wi-Fi 信令测试固件（单国） <https://dl.espressif.com/RF/ESP32C2_v5.0_e255ce0_26M_singlephy_20250430.zip>`__

.. |ESP32-C2 Wi-Fi 信令测试固件（多国）| replace:: `ESP32-C2 Wi-Fi 信令测试固件（多国） <https://dl.espressif.com/RF/ESP32C2_v5.0_e255ce0_26M_multiphy_20250430.zip>`__

.. |ESP32-C3 Wi-Fi 信令测试固件（单国）| replace:: `ESP32-C3 Wi-Fi 信令测试固件（单国） <https://dl.espressif.com/RF/ESP32C3_v5.5_402fb258_singlephy_20250722.zip>`__

.. |ESP32-C3 Wi-Fi 信令测试固件（多国）| replace:: `ESP32-C3 Wi-Fi 信令测试固件（多国） <https://dl.espressif.com/RF/ESP32C3_v5.5_402fb258_multiphy_20250722.zip>`__

.. |ESP32-C6 Wi-Fi 信令测试固件（单国）| replace:: `ESP32-C6 Wi-Fi 信令测试固件（单国） <https://dl.espressif.com/RF/ESP32-C6_v5.4.2_d12e5a3_SinglePhy_20250808.zip>`__

.. |ESP32-C6 Wi-Fi 信令测试固件（多国）| replace:: `ESP32-C6 Wi-Fi 信令测试固件（多国） <https://dl.espressif.com/RF/ESP32-C6_v5.4.2_d12e5a3_MultiplePhy_20250808.zip>`__

.. |ESP32-S2 Wi-Fi 信令测试固件（单国）| replace:: `ESP32-S2 Wi-Fi 信令测试固件（单国） <https://dl.espressif.com/RF/ESP32S2_V5.3.3_f8f9319_SinglePhy_20250915.zip>`__

.. |ESP32-S2 Wi-Fi 信令测试固件（多国）| replace:: `ESP32-S2 Wi-Fi 信令测试固件（多国） <https://dl.espressif.com/RF/ESP32S2_V5.3.3_f8f9319_MultiplePhy_20250915.zip>`__

.. |ESP32-S3 Wi-Fi 信令测试固件（单国）| replace:: `ESP32-S3 Wi-Fi 信令测试固件（单国） <https://dl.espressif.com/RF/ESP32S3_V4.4.4_a5d905b_SinglePhy_20250915.zip>`__

.. |ESP32-S3 Wi-Fi 信令测试固件（多国）| replace:: `ESP32-S3 Wi-Fi 信令测试固件（多国） <https://dl.espressif.com/RF/ESP32S3_V4.4.4_a5d905b_MultiplePhy_20250915.zip>`__