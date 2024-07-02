搭建测试环境
----------------------------

射频非信令测试固件环境主要包括电脑、测试仪器、USB-to-UART 转接板、待测设备与屏蔽箱等。

.. figure:: ../../../_static/rf_test_tool/rf_non_signaling_setup.png
    :align: center
    :scale: 120%

    射频非信令测试固件示意图

- **电脑 (PC)** 通过 USB 与 USB-to-UART 转接板连接，通过网线与测试仪器连接。电脑上需安装 ESPRFTestTool 工具、测试仪器控制软件、以及 USB-to-UART 转接板驱动。
- **测试仪器 (Tester)** 通常为 WT-328/IQXel 综测仪，用于测试待测设备在不同模式下的射频性能。
- **USB-to-UART 转接板 (USB-to-UART Board)** 用于实现电脑和待测设备之间的通信。
- **待测设备 (DUT)** 为基于乐鑫芯片或模组设计的产品。待测设备通过 UART 与 USB-to-UART 转接板连接，并通过射频连接线与测试仪器连接。待测设备通常放在屏蔽箱中。
- **屏蔽箱 (Shield Box)** 用于隔离外部射频干扰，保证测试环境的稳定性。

.. note::

    - 待测设备的 CHIP_EN 管脚默认上拉，如果产品设计中未拉高，需要手动将 CHIP_EN 接到 3V3 管脚。
    - 部分串口通信板内部已交换 RXD 和 TXD, 无需反接，需根据实际情况调整接线。
    - 乐鑫芯片具有上电自校准功能，因此待测设备上电测试前需先将射频连接线连接至测试仪器。

传导测试
^^^^^^^^^^^^^^^^^^

- 对于没有板载 PCB 天线的模组，直接将射频连接线焊接至模组的天线馈电点即可（如上述示意图所示）。

- 对于带有板载 PCB 天线的模组，需将 PCB 天线馈电点后的天线割断，焊接射频连接线，并使射频线的屏蔽金属层充分焊锡后接入模组 GND。GND 焊接点可选择屏蔽盖或 PCB 板材上去除绿油层的 GND 层，且尽量靠近馈电点。

.. figure:: ../../../_static/rf_test_tool/pcb_antenna_conducted_test.png
    :align: center
    :scale: 80%

    带有板载 PCB 天线的模组焊接射频连接线示意图

烧录固件
------------------

{IDF_TARGET_RF_NON_SIGNALLING_FIRMWARE:default="未更新", esp32="`ESP32 射频非信令测试固件 <https://dl.espressif.com/rf/esp32/ESP32_RFTest_190_8cac24c_20230710.bin>`_", esp32c2="`ESP32-C2 射频非信令测试固件 <https://dl.espressif.com/rf/esp32c2/ESP32-C2_RFTest_Bin_26M_98a091b_20230621.bin>`_", esp32c3="`ESP32-C3 射频非信令测试固件 <https://dl.espressif.com/rf/esp32c3/ESP32-C3_RF_TEST_BIN_V114_1ac85ea_20230504.bin>`_", esp32c6="`ESP32-C6 射频非信令测试固件 <https://dl.espressif.com/rf/esp32c6/ESP32-C6_RFTest_Bin_26f46b0_20230621.bin>`_", esp32s3="`ESP32-S3 射频非信令测试固件 <https://dl.espressif.com/rf/esp32s3/ESP32-S3_RF_TEST_BIN_V110_25c811a_20230504.bin>`_", esp32s2="`ESP32-S2 射频非信令测试固件 <https://dl.espressif.com/rf/esp32s2/ESP32-S2_RF_TEST_BIN_20220902_05bde8b.bin>`_", esp8266="`ES8266 射频非信令测试固件 (26 MHz) <https://dl.espressif.com/RF/ESP8266_RFTest_153_20231018_26M.bin>`_ 或 `ES8266 射频非信令测试固件 (40 MHz) <https://dl.espressif.com/RF/ESP8266_RFTest_153_20231020_40M.bin>`_"}

1. 打开 DownloadTool 工具
2. 设置 ChipType，Com Port，Baud Rate，点击 Open，选择下载到 Flash

.. figure:: ../../../_static/rf_test_tool/phyinit_download_flash.png
    :align: center
    :scale: 80%

    DownloadTool 工具配置

.. only:: esp32 or esp32s2

    3. 将 {IDF_TARGET_RF_NON_SIGNALLING_FIRMWARE} 通过 UART 烧录至 0x1000，将 phy init bin 固件通过 UART 烧录至 0x1fc000。phy init bin 固件的生成方法请见 `PowerLimitTool 工具 <power-limit-tool>`_。

.. only:: not esp32 and not esp32s2

    3. 将 {IDF_TARGET_RF_NON_SIGNALLING_FIRMWARE} 通过 UART 烧录至 0x0，将 phy init bin 固件通过 UART 烧录至 0x1fc000。phy init bin 固件的生成方法请见 `PowerLimitTool 工具 <power-limit-tool>`_。

.. figure:: ../../../_static/rf_test_tool/phyinit_download_start.png
    :align: center
    :scale: 80%

    烧录非信令固件

开始测试
----------------

串口配置
^^^^^^^^^^^^^^^

- **ChipType**：选择对应的芯片类型
- **COM**：选择对应的 COM 口

.. only:: esp8266

  - **BaudRate**：如果主晶振为 26 MHz，波特率设置为 74880； 如果主晶振为 40 MHz，波特率设置为 115200。

.. only:: esp32c2

  - **BaudRate**：74880

.. only:: not esp32c2 and not esp8266

  - **BaudRate**：波特率选择 115200

- **Open**：打开串口