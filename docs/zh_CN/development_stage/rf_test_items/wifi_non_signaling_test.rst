Wi-Fi 非信令测试
===========================

:link_to_translation:`en:[English]`

本章介绍基于 ESP 芯片或模组的产品如何进行 Wi-Fi 非信令测试（非信令测试也称为定频测试）。

测试准备
---------------------------

测试环境搭建
^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/wifi_non-signaling_test_setup.png
    :align: center
    :scale: 80%

    环境搭建示意图

- 待测设备 (DUT) 为基于 ESP 系列芯片设计的产品。
- PC 端通过 UART 与 DUT 进行通讯，使用 ESPRFTestTool 工具实现各种测试模式的配置。
- 测试仪器常见为 WT-328/IQXel 等综测仪，用于测试 DUT 在不同模式下的射频性能。

硬件连接
^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/usb_to_uart_connection_wifi.png
    :align: center
    :scale: 80%

    UART 连接说明

使用串口板与 ESP 产品串口连接：

- 待测设备 (DUT) CHIP_EN 需默认上拉，如产品设计中未拉高，需将 CHIP_EN 接到 3V3。
- 部分串口通信板内部已交换 RXD 和 TXD, 无需反接，需根据实际情况调整接线。
- ESP 芯片具有上电自校准功能，因此 DUT 上电测试前需先将射频连接线连接至综测仪。

PCB 天线模组做传导测试
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/pcb_antenna_conducted_test.png
    :align: center
    :scale: 80%

    PCB 天线模组焊接 RF Cable

将带有 PCB 天线的产品改为传导方式需注意：

- 将 PCB 天线馈电点后的天线割断，焊接射频连接线，并使射频线的屏蔽金属层充分焊锡后接入模组 GND。
- GND 焊接点可选择屏蔽盖或 PCB 板材上去除绿油层的 GND 层，且尽量靠近馈电点。

非信令测试固件烧录
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

{IDF_TARGET_RF_NON_SIGNALLING_FIRMWARE:default="未更新", esp32="ESP32_RF_BIN", esp32c2="ESP32C2_RF_BIN", esp32c3="ESP32C3_RF_BIN", esp32c6="ESP32C6_RF_BIN", esp32s3="ESP32S3_RF_BIN", esp32h2="ESP32H2_RF_BIN"}

- 如果未烧录测试固件，请参考 EspRFTestTool 工具包中的 DownloadTool 章节，并烧录 {IDF_TARGET_RF_NON_SIGNALLING_FIRMWARE}。

- 已烧录固件的样机，可继续往下进行射频测试。

ESPRFTestTool 工具
^^^^^^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/esprftesttool_main.png
    :align: center
    :scale: 80%

    ESPRFTestTool 界面

串口配置

.. only:: esp32c2

  - ChipType：选择对应的 ESP 芯片。
  - COM：选择对应的 COM 口。
  - BaudRate：如果主晶振为 26MHz，则烧录 26M RF 测试固件，波特率设置为 74880； 如果主晶振为 40MHz，则需要烧录 40M RF 测试固件，波特率设置为 115200。
  - Open：打开串口。

.. only:: not esp32c2

  - ChipType：选择对应的 ESP 芯片。
  - COM：选择对应的 COM 口。
  - BaudRate：波特率选择 115200。
  - Open：打开串口。

.. _wifi-non-signaling-test:

Wi-Fi 非信令测试
---------------------------

Wi-Fi 发射性能测试
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- Test Mode：

  * Tx packet 用于发射性能测试，发包占空比低于 50%；
  * Tx continue 用于认证测试，发包占空比接近 100%；
  * 选择 Tx Tone 用于单载波测试。

- Wi-Fi Rate：设置 Wi-Fi 测试速率。
- BandWidth：设置 Wi-Fi 测试带宽。
- Channel：设置 Wi-Fi 测试信道。
- Atteunuation(0.25 dB)：设置功率衰减，

  * 0 表示无衰减，为默认值；
  * 2 表示衰减 0.5 dB；
  * 4 表示衰减 1 dB，依次类推。

- Duty Cycle：在 Tx packet 测试时用于设置发包占空比，默认选择 default（约 30%），可配置 10%，50%，90%。
- Certification EN：默认不使能，仅在验证 Power Limit 功能时使用。
- Certification Code：默认不使能，仅在验证 Power Limit 功能时使用。

点击 start 后在 log 窗口中显示 Wi-Fi 发射参数说明，参考如下：

::

    Wifi tx out:channel=1,rate=0x0,BK=0,length=50,delay=1200,packet_num=0

表明 Wi-Fi 发包正常，此时可使用综测仪检测发射性能。

.. figure:: ../../../_static/rf_test_tool/esp32s3_wifi_test_on.png
    :align: center
    :scale: 80%

    Wi-Fi 发射性能测试

Wi-Fi 接收性能测试
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- Test Mode：设置为 RX packet 用于接收性能测试。
- WiFi Rate：设置 Wi-Fi 测试速率。
- BandWidth：设置 Wi-Fi 测试带宽。
- Channel：设置 Wi-Fi 测试信道。

点击 start 后，仪器在测试信道发包，完成后点击 stop，在 log 窗口中显示收包信息如下：

::

    Correct:1000 Desired:1000 RSSI:-614 noise:-960 gain:0 paral:0 para2:0 freq:0

其中：

- Correct：本次总共收到的包个数。
- Desired：本次收到的对应速率的包个数。
- RSSI：表示收到 Desired 包的平均 RSSI，如 “RSSI：-614” 表示 RSSI 值为 -61.4。

Note：

- 如 Desired 为 0，表明未收到仪器发包，需确认仪器发包设置、包文件，确认收包链路正常；
- 如 Desired 不为 0，且 Correct 多于 Desired，表明环境存在干扰，可在屏蔽环境下复测；
- 收包信息中的其它参数仅用于 RD debug，无实际意义。

.. figure:: ../../../_static/rf_test_tool/esp32c6_wifi_rx_on.png
    :align: center
    :scale: 80%

    Wi-Fi 接收性能测试

附录
----------------

本附录主要用于说明芯片的 Wi-Fi 目标输出功率，用于射频调试或测试对照。

Wi-Fi 目标发射功率
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. only:: esp8266

    .. list-table:: ESP8266 Wi-Fi 目标发射功率
        :widths: 30 40

        * - 速率
          - ESP8266 Wi-Fi 目标功率 (dBm)
        * - 11b 1M
          - 19.5
        * - 11b 11M
          - 19.5
        * - 11g 6M
          - 19.5
        * - 11g 54M
          - 15
        * - HT20-11n MCS0
          - 19.5
        * - HT20-11n MCS7
          - 14

.. only:: esp32

    .. list-table:: ESP32 Wi-Fi 目标发射功率
        :widths: 30 40

        * - 速率
          - ESP32 Wi-Fi 目标功率 (dBm)
        * - 11b 1M
          - 19.5
        * - 11b 11M
          - 19.5
        * - 11g 6M
          - 18
        * - 11g 54M
          - 14
        * - HT20-11n MCS0
          - 18
        * - HT20-11n MCS7
          - 13
        * - HT40-11n MCS0
          - 18
        * - HT40-11n MCS7
          - 13

.. only:: esp32c2

    .. list-table:: ESP32-C2 Wi-Fi 目标发射功率
        :widths: 30 40

        * - 速率
          - ESP8684 Wi-Fi 目标功率 (dBm)
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

.. only:: esp32c3

    .. list-table:: ESP32-C3 Wi-Fi 目标发射功率
        :widths: 50 50 50

        * - 速率
          - ESP32-C3 Wi-Fi 目标功率 (dBm)
          - ESP8685 Wi-Fi 目标功率 (dBm)
        * - 11b 1M
          - 20.5
          - 20.5
        * - 11b 11M
          - 20.5
          - 20.5
        * - 11g 6M
          - 20
          - 20
        * - 11g 54M
          - 18
          - 18
        * - HT20-11n MCS0
          - 19
          - 19
        * - HT20-11n MCS7
          - 17.5
          - 17.5
        * - HT40-11n MCS0
          - 18.5
          - 18.5
        * - HT40-11n MCS7
          - 17
          - 17

.. only:: esp32c6

    .. list-table:: ESP32-C6 Wi-Fi 目标发射功率
        :widths: 30 50

        * - 速率
          - ESP32-C6 Wi-Fi 目标功率 (dBm)
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

.. only:: esp32s2

    .. list-table:: ESP32-S2 Wi-Fi 目标发射功率
        :widths: 30 50

        * - 速率
          - ESP32-S2 Wi-Fi 目标功率 (dBm)
        * - 11b 1M
          - 19.5
        * - 11b 11M
          - 19.5
        * - 11g 6M
          - 18
        * - 11g 54M
          - 18
        * - HT20-11n MCS0
          - 18
        * - HT20-11n MCS7
          - 17
        * - HT40-11n MCS0
          - 18
        * - HT40-11n MCS7
          - 16.5

.. only:: esp32s3

    .. list-table:: ESP32-S2 Wi-Fi 目标发射功率
        :widths: 30 50

        * - 速率
          - ESP32-S3 Wi-Fi 目标功率 (dBm)
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
