搭建测试环境
----------------------------

射频非信令测试固件环境主要包括电脑、测试仪器、USB-to-UART 转接板、待测设备与屏蔽箱等。

.. figure:: ../../../_static/rf_test_tool/rf_non_signaling_setup.png
    :align: center
    :scale: 120%

    测试环境搭建示意图

- **电脑 (PC)** 通过 USB 与 USB-to-UART 转接板连接，通过网线与测试仪器连接。电脑上需安装 EspRFTestTool 工具包、测试仪器控制软件、以及 USB-to-UART 转接板驱动。
- **测试仪器 (Tester)** 通常为 WT-328/IQXel 综测仪，用于测试待测设备在不同模式下的射频性能。
- **USB-to-UART 转接板 (USB-to-UART Board)** 用于实现电脑和待测设备之间的通信。
- **待测设备 (DUT)** 为基于 {IDF_TARGET_NAME} 芯片或模组设计的产品。待测设备通过 UART 与 USB-to-UART 转接板连接，并通过射频连接线与测试仪器连接。待测设备通常放在屏蔽箱中。
- **屏蔽箱 (Shield Box)** 用于隔离外部射频干扰，保证测试环境的稳定性。

.. note::

    - 待测设备的 CHIP_EN 管脚默认上拉，如果产品设计中未拉高，需要手动将 CHIP_EN 接到 3V3 管脚。
    - 部分串口通信板内部已交换 RXD 和 TXD，无需反接，需根据实际情况调整接线。
    - {IDF_TARGET_NAME} 具有上电自校准功能，待测设备上电测试前需先将射频连接线连接至测试仪器。

传导测试
^^^^^^^^^^^^^^^^^^

- 对于没有板载 PCB 天线的模组，直接将射频连接线焊接至模组的天线馈电点即可（如上述示意图所示）。

- 对于带有板载 PCB 天线的模组，需将 PCB 天线馈电点后的天线割断，焊接射频连接线，并使射频线的屏蔽金属层充分焊锡后接入模组 GND。GND 焊接点可选择屏蔽盖或 PCB 板材上去除绿油层的 GND 层，且尽量靠近馈电点。

.. figure:: ../../../_static/rf_test_tool/pcb_antenna_conducted_test.png
    :align: center
    :scale: 70%

    带有板载 PCB 天线的模组焊接射频连接线示意图

烧录固件
------------------

{IDF_TARGET_RF_NON_SIGNALING_FIRMWARE:default="Not Updated", esp32="|ESP32 射频非信令测试固件|", esp32c2="|ESP32-C2 射频非信令测试固件 (26 MHz) or ESP32-C2 射频非信令测试固件 (40 MHz)|", esp32c3="|ESP32-C3 射频非信令测试固件|", esp32c6="|ESP32-C6 射频非信令测试固件|", esp32s2="|ESP32-S2 射频非信令测试固件|", esp32s3="|ESP32-S3 射频非信令测试固件|", esp8266="|ESP8266 射频非信令测试固件 (26 MHz) or ESP8266 射频非信令测试固件 (40 MHz)|", esp32h2="|ESP32-H2 射频非信令测试固件|"}

1. 打开 :ref:`esp-rf-test-tool`。

2. 设置 ``ChipType``, ``COM``, ``BaudRate``, 点击 ``Open``，打开串口。

.. note::

    .. only:: esp8266 or esp32c2

        如果主晶振为 26 MHz，``BaudRate`` 设置为 74880；如果主晶振为 40 MHz，``BaudRate`` 设置为 115200。

    .. only:: not esp32c2 and not esp8266

        ``BaudRate`` 设置为 115200

3. 将 {IDF_TARGET_RF_NON_SIGNALING_FIRMWARE} 通过 ``UART`` 烧录至 ``Flash``。

.. figure:: ../../../_static/rf_test_tool/nonsignaling_firmware_flash.png
    :align: center
    :scale: 80%

    ESPRFTestTool 工具配置

4. 固件烧录完成后，将 boot 管脚拉高或悬空，芯片掉电重启后进入工作模式。

.. |ESP32 射频非信令测试固件| replace:: `ESP32 射频非信令测试固件 <https://dl.espressif.com/RF/ESP32_RFTest_V191_482eb73_20230724.bin>`__
.. |ESP32-C2 射频非信令测试固件 (26 MHz) or ESP32-C2 射频非信令测试固件 (40 MHz)| replace:: `ESP32-C2 射频非信令测试固件 (26 MHz) <https://dl.espressif.com/RF/ESP32-C2_RFTest_V203_26M_7a8831de_20240730.bin>`__ or `ESP32-C2 射频非信令测试固件 (40 MHz) <https://dl.espressif.com/RF/ESP32-C2_RFTest_V203_40M_7a8831de_20240730.bin>`__
.. |ESP32-C3 射频非信令测试固件| replace:: `ESP32-C3 射频非信令测试固件 <https://dl.espressif.com/RF/ESP32-C3_RFTest_V117_402fb258_20240902.bin>`__
.. |ESP32-C6 射频非信令测试固件| replace:: `ESP32-C6 射频非信令测试固件 <https://dl.espressif.com/RF/ESP32-C6_RFTest_V106_d12e5a3_20250711.bin>`__
.. |ESP32-S2 射频非信令测试固件| replace:: `ESP32-S2 射频非信令测试固件 <https://dl.espressif.com/RF/ESP32-S2_RFTest_V207_545e2ab_20230829.bin>`__
.. |ESP32-S3 射频非信令测试固件| replace:: `ESP32-S3 射频非信令测试固件 <https://dl.espressif.com/RF/ESP32-S3_RFTest_V112_b7bc9b9_20240430.bin>`__
.. |ESP8266 射频非信令测试固件 (26 MHz) or ESP8266 射频非信令测试固件 (40 MHz)| replace:: `ESP8266 射频非信令测试固件 (26 MHz) <https://dl.espressif.com/RF/ESP8266_RFTest_153_20231018_26M.bin>`__ or `ESP8266 射频非信令测试固件 (40 MHz) <https://dl.espressif.com/RF/ESP8266_RFTest_153_20231020_40M.bin>`__
.. |ESP32-H2 射频非信令测试固件| replace:: `ESP32-H2 射频非信令测试固件 <https://dl.espressif.com/RF/ESP32-H2_RFTest_V203_596642e_20250221.bin>`__
