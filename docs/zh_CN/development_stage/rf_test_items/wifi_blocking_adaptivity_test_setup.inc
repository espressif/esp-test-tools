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

{IDF_TARGET_WIFI_BLOCKING_ADAPTIVITY_FIRMWARE:default="联系乐鑫获取最新固件", esp32="|ESP32 Wi-Fi 自适应测试/阻塞测试固件|", esp32c2="|ESP32-C2 Wi-Fi 自适应测试/阻塞测试固件 (26 MHz) or ESP32-C2 Wi-Fi 自适应测试/阻塞测试固件 (40 MHz)|", esp32c3="|ESP32-C3 Wi-Fi 自适应测试/阻塞测试固件|", esp32c6="|ESP32-C6 Wi-Fi 自适应测试/阻塞测试固件|", esp32s2="|ESP32-S2 Wi-Fi 自适应测试/阻塞测试固件|", esp32s3="|ESP32-S3 Wi-Fi 自适应测试/阻塞测试固件|", esp8266="|ES8266 Wi-Fi 自适应测试/阻塞测试固件|"}

{IDF_TARGET_FLASH_ADDRESS:default="0x0", esp32="0x1000", esp32s2="0x1000", esp32c5="0x2000"}

1. 打开 :ref:`download-tool`。

2. 设置 ``ChipType``，``Com Port``，``Baud Rate``，点击 ``Open``，选择下载到 ``Flash``。

3. 将 {IDF_TARGET_WIFI_BLOCKING_ADAPTIVITY_FIRMWARE} 通过 ``UART`` 烧录至 {IDF_TARGET_FLASH_ADDRESS}。

.. only:: esp32 or esp32s2

    .. figure:: ../../../_static/rf_test_tool/wifi_adaptivity_blocking_firmware_esp32_esp32s2.png
        :align: center
        :scale: 80%

        烧录固件示意图

.. only:: not esp32 and not esp32s2

    .. figure:: ../../../_static/rf_test_tool/wifi_adaptivity_blocking_firmware_others.png
        :align: center
        :scale: 80%

        烧录固件示意图

烧录完成后，继续以下步骤进行自适应测试。

开始测试
---------------------------

.. note::

    .. only:: esp8266 or esp32c2

        如果主晶振为 26 MHz，``BaudRate`` 设置为 74880；如果主晶振为 40 MHz，``BaudRate`` 设置为 115200。

    .. only:: not esp32c2 and not esp8266

        ``BaudRate`` 设置为 115200。

查看上电打印
^^^^^^^^^^^^^^^^^^^^^

使用串口通信工具，如 `友善串口助手 <http://alithon.com/downloads>`__，配置端口号和波特率，待测设备重新上电后串口如果打印类似如下信息，则可确认测试状态 OK：

.. figure:: ../../../_static/rf_test_tool/esp32c2_wifi_signaling.png
    :align: center
    :scale: 80%

    设备上电串口打印日志

.. |ESP32 Wi-Fi 自适应测试/阻塞测试固件| replace:: `ESP32 Wi-Fi 自适应测试/阻塞测试固件 <https://dl.espressif.com/rf/esp32/ESP32_wifi_Adaptivity&Blocking_20210420.bin>`__
.. |ESP32-C2 Wi-Fi 自适应测试/阻塞测试固件 (26 MHz) or ESP32-C2 Wi-Fi 自适应测试/阻塞测试固件 (40 MHz)| replace:: `ESP32-C2 Wi-Fi 自适应测试/阻塞测试固件 (26 MHz) <https://dl.espressif.com/RF/ESP32C2_wifi_Adaptivity&Blocking_26M_20250408.bin>`__ or `ESP32-C2 Wi-Fi 自适应测试/阻塞测试固件 (40 MHz) <https://dl.espressif.com/RF/ESP32C2_wifi_Adaptivity&Blocking_40M_20250408.bin>`__
.. |ESP32-C3 Wi-Fi 自适应测试/阻塞测试固件| replace:: `ESP32-C3 Wi-Fi 自适应测试/阻塞测试固件 <https://dl.espressif.com/RF/ESP32C3_wifi_Adaptivity&Blocking_20250722.bin>`__
.. |ESP32-C6 Wi-Fi 自适应测试/阻塞测试固件| replace:: `ESP32-C6 Wi-Fi 自适应测试/阻塞测试固件 <https://dl.espressif.com/RF/ESP32C6_wifi_Adaptivity&Blocking_20250807.bin>`__
.. |ESP32-S2 Wi-Fi 自适应测试/阻塞测试固件| replace:: `ESP32-S2 Wi-Fi 自适应测试/阻塞测试固件 <https://dl.espressif.com/rf/esp32s2/ESP32S2_wifi_Adaptivity&Blocking_20220826.bin>`__
.. |ESP32-S3 Wi-Fi 自适应测试/阻塞测试固件| replace:: `ESP32-S3 Wi-Fi 自适应测试/阻塞测试固件 <https://dl.espressif.com/rf/esp32s3/ESP32S3_wifi_Adaptivity&Blocking_20230328.bin>`__
.. |ES8266 Wi-Fi 自适应测试/阻塞测试固件| replace:: `ES8266 Wi-Fi 自适应测试/阻塞测试固件 <https://dl.espressif.com/RF/ESP8266&8285_adaptivity&blocking_bin_20220824_115200.bin>`__
