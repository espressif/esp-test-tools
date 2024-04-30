蓝牙及低功耗蓝牙非信令测试
==============================================

:link_to_translation:`en:[English]`

本章介绍基于 ESP 芯片或模组的产品如何进行蓝牙或低功耗蓝牙非信令测试（非信令测试也称为定频测试）。

测试准备
---------------------------

测试环境搭建
^^^^^^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/ble_non-signaling_test_setup.png
    :align: center
    :scale: 80%

    环境搭建示意图

- 待测设备 (DUT) 为基于 ESP 系列芯片设计的产品。
- PC 端通过 UART 与 DUT 进行通讯，使用 ESPRFTestTool 工具实现各种测试模式的配置。
- 测试仪器常见为 WT-328/IQXel 等综测仪，用于测试 DUT 在不同模式下的射频性能。

硬件连接
^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/usb_to_uart_connection_ble.png
    :align: center
    :scale: 80%

    UART 连接说明

使用串口板与 ESP 产品串口连接：

- 待测设备 (DUT) CHIP_EN 需默认上拉，如产品设计中未拉高，需将 CHIP_EN 接到 3V3。
- 部分串口通信板内部已交换 RXD 和 TXD, 无需反接，需根据实际情况调整接线。
- ESP 芯片具有上电自校准功能，因此 DUT 上电测试前需先将射频连接线连接至综测仪。

PCB 天线模组做传导测试
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/pcb_antenna_conducted_test.png
    :align: center
    :scale: 80%

    PCB 天线模组焊接 RF Cable

将带有 PCB 天线的产品改为传导方式需注意：

- 将 PCB 天线馈电点后的天线割断，焊接射频连接线，并使射频线的屏蔽金属层充分焊锡后接入模组 GND。
- GND 焊接点可选择屏蔽盖或 PCB 板材上去除绿油层的 GND 层，且尽量靠近馈电点。

非信令测试固件烧录
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

{IDF_TARGET_RF_NON_SIGNALLING_FIRMWARE:default="未更新", esp32="ESP32_RF_BIN", esp32c2="ESP32C2_RF_BIN", esp32c3="ESP32C3_RF_BIN", esp32c6="ESP32C6_RF_BIN", esp32s3="ESP32S3_RF_BIN", esp32h2="ESP32H2_RF_BIN"}

- 如果未烧录测试固件，请参考 EspRFTestTool 工具包中的 DownloadTool 章节，并烧录 {IDF_TARGET_RF_NON_SIGNALLING_FIRMWARE}。

- 已烧录固件的样机，可继续往下进行射频测试。

ESPRFTestTool 工具
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/esprftesttool_main.png
    :align: center
    :scale: 80%

    ESPRFTestTool 界面

串口配置

.. only:: esp32c2

    - ChipType：选择对应的 ESP 芯片。
    - COM：选择对应的 COM 口。
    - BaudRate：如果主晶振为 26 MHz，则烧录 26M RF 测试固件，波特率设置为 74880； 如果主晶振为 40 MHz，则需要烧录 40M RF 测试固件，波特率设置为 115200。
    - Open：打开串口。

.. only:: not esp32c2

    - ChipType：选择对应的 ESP 芯片。
    - COM：选择对应的 COM 口。
    - BaudRate：波特率选择 115200。
    - Open：打开串口。

.. _ble-non-signalling-test:

.. only:: esp32

    经典蓝牙/低功耗蓝牙非信令测试
    ----------------------------------------------------

    经典蓝牙/低功耗蓝牙发射性能测试
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    - Test Mode：

      * BT TX 用于经典蓝牙发射性能测试；
      * BLE TX 用于低功耗蓝牙发射性能测试。

    - Power Level：设置蓝牙功率等级，支持 0~7 档测试。
    - Channel: 设置蓝牙测试信道。
    - Hoppe：跳频功能，默认关闭。
    - Ulap：蓝牙地址，使用默认值，仅经典蓝牙支持。
    - Itaddr：逻辑传输地址，使用默认值，仅经典蓝牙支持。
    - Syncw：包文件的身份识别码，默认选择 syncw=0x71764129。
    - Payload length：payload 长度，默认使用 250。
    - Data Rate：设置发包速率和编码序列，支持 BT 1M，2M，3M 和 BLE 1M 四种速率，支持 1010，11110000，prbs9 三种编码序列。

    点击 start 后在 log 窗口中显示蓝牙发射参数说明，参考如下：

    ::

        fcc_bt_tx:txpwr=4,hoppe=0,chan=18,rate=1,DH_type=1,data_type=1

    表明蓝牙发包正常，此时可使用综测仪检测发射性能。

    .. figure:: ../../../_static/rf_test_tool/esp32_bt_tx_on.png
        :align: center
        :scale: 80%

        经典蓝牙/低功耗蓝牙发射性能

    经典蓝牙接收性能测试
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    - Test Mode：选择 BT RX 用于经典蓝牙接收性能测试。
    - Channel：设置蓝牙测试信道。
    - Ulap：蓝牙地址，使用默认值，仅经典蓝牙支持。
    - Itaddr：逻辑传输地址，使用默认值，仅经典蓝牙支持。
    - Data Rate：设置收包速率，支持 BT 1M，2M，3M，默认 prbs9 编码序列。

    点击 start 后使用仪器在测试信道发包，完成后点击 stop，在 log 窗口中显示收包信息如下：

    ::

        3e8 3e8 0 0 0 0 0 0 w 0 0 0 0 0 0 0 0 p 4176 45cf ddfd b 7ca240 0

    其中：

    - 返回打印的第 1 个参数 Res[0]（16 进制）表示本次测试收到的总包数。
    - 返回打印的第 2 个参数 Res[1]（16 进制）表示本次测试收到的对应速率包的数量。
    - 返回打印的倒数第 2 个参数 Res[22]（16 进制）表示本次测试收到的对应速率的总码数。
    - 返回打印的最后 1 个参数 Res[23]（16 进制）表示本次测试总共收到的误码个数。

    计算：

    - 误码率 BT_BER = Res[23]/Res[22]
    - BT_RSSI = (-Res[18]]-Res[20])/Res[0]

    .. figure:: ../../../_static/rf_test_tool/esp32_bt_rx_on.png
        :align: center
        :scale: 80%

        BT Rx Test

    低功耗蓝牙接收性能测试
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    - Test Mode：选择 BLE RX 用于低功耗蓝牙接收性能测试。
    - Channel：设置低功耗蓝牙测试信道。
    - Syncw：包文件的身份识别码，默认选择 syncw=0x71764129。
    - Data Rate：设置收包速率，默认为 BLE 1M 速率，prbs9 编码序列。

    点击 start 后使用仪器在测试信道发包，完成后点击 stop，在 log 窗口中显示收包信息如下：

    ::

        3e8 3e8 0 0 0 0 0 0 0 0 w 0 0 0 0 0 0 0 0 p 5b83 58cf 6acb

    其中：

    - 返回打印的第 1 个参数 Res[0]（16 进制）表示本次测试收到的总包数。
    - 返回打印的第 2 个参数 Res[1]（16 进制）表示本次测试在对应速率下收到的包的数量。
    - 返回打印的倒数第 3 个参数 Res[20]（16 进制）表示本次测试所有包的带内功率。
    - 返回打印的最后 1 个参数 Res[22]（16 进制）表示本次测试所有包的增益。

    计算：

    - 丢包率 BLE_PER = [1-(Res[1]/Sent_Packet_Numbers)]*100%<=30.8%
    - BLE_RSSI = (-Res[20]-Res[22])/Res[0]

    .. figure:: ../../../_static/rf_test_tool/esp32_ble_rx_on.png
        :align: center
        :scale: 80%

        低功耗蓝牙接收性能测试

.. only:: not esp32

    低功耗蓝牙非信令测试
    ---------------------------------------

    低功耗蓝牙发射性能测试
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    - Test Mode：

      * BLE50 TX 用于发射性能测试；
      * BLE50 TX continue 用于认证测试。

    - Power Level：设置低功耗蓝牙发射功率等级，支持 0~15 档测试。
    - Channel：设置低功耗蓝牙测试信道。
    - Hoppe：跳频功能，默认关闭。
    - Ulap：蓝牙地址，默认不使能，仅经典蓝牙支持。
    - Itaddr：逻辑传输地址，默认不使能，仅经典蓝牙支持。
    - Syncw：包文件的身份识别码，默认选择 syncw=0x71764129。
    - Payload length：payload 长度，默认使用 250。
    - Data Rate：设置发包速率和编码序列，支持 BLE 1M，2M，125K，500K 四种速率，支持 1010，11110000，prbs9 三种编码序列。

    点击 start 后在 Log 窗口中显示低功耗蓝牙发射参数说明，参考如下：

    ::

        fcc_le_tx_syncw:txpwr=12,chan=0,len=250,data_type=0,syncw=0x71764129,rate=0,tx_num=0,contin_en=0,delay=0,hopp_en=0

    表明低功耗蓝牙发包正常，此时可使用综测仪检测发射性能。

    .. figure:: ../../../_static/rf_test_tool/esp32c6_ble_test_on.png
        :align: center
        :scale: 80%

        BLE Tx Test

    低功耗蓝牙接收性能测试
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    {IDF_TARGET_TWELFTH_PARA:default="未更新", esp32c2="收到正确包", esp32c3="所有包", esp32c6="收到正确包", esp32s3="所有包", esp32h2="收到正确包"}

    {IDF_TARGET_RSSI:default="未更新", esp32c2="Res[11]/(Res[1])", esp32c3="Res[11]/(Res[1]+Res[4])", esp32c6="Res[11]/(Res[1])", esp32s3="Res[11]/(Res[1]+Res[4])", esp32h2="Res[11]/(Res[1])"}


    - Test Mode：选择 BLE50 RX 用于低功耗蓝牙接收性能测试。
    - Channle：设置低功耗蓝牙测试信道。
    - Syncw：包文件的身份识别码，默认选择 syncw=0x71764129。
    - Data Rate：设置收包速率，默认为 prbs9 编码序列数据。

    点击 start 后使用仪器在测试信道发包，完成后点击 stop，在 log 窗口中显示收包信息如下：

    ::

        3e8 3e8 0 0 0 0 0 0 0 0 p -61009 -20424 0 40581

    其中：

    - 返回打印的第 1 个参数 Res[0]（16 进制）表示本次测试收到的总包数。
    - 返回打印的第 2 个参数 Res[1]（16 进制）表示本次测试在对应速率下收到的包的数量。
    - 返回打印的第 12 个参数 Res[11]（10 进制）表示本次测试{IDF_TARGET_TWELFTH_PARA}的 RSSI。

    计算:

    - 丢包率 PER = [1-(Res[1]/Sent_Packet_Numbers)]*100%<=30.8%
    - 每个包的 RSSI = {IDF_TARGET_RSSI}


      .. figure:: ../../../_static/rf_test_tool/esp32s3_ble_rx_on.png
          :align: center
          :scale: 80%

          低功耗蓝牙接收性能测试

附录
----------------

本附录主要用于说明芯片的蓝牙或低功耗蓝牙的功率等级及对应的目标功率，用于射频调试或测试对照。

.. only:: esp32

  ESP32 经典蓝牙/低功耗蓝牙发射功率等级
  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

  .. list-table:: ESP32 经典蓝牙/低功耗蓝牙发射功率等级
    :widths: 40 60

    * - 功率等级
      - ESP32 经典蓝牙/低功耗蓝牙发射功率 (dBm)
    * - 0
      - -12
    * - 1
      - -9
    * - 2
      - -6
    * - 3
      - -3
    * - 4
      - 0
    * - 5
      - 3
    * - 6
      - 6
    * - 7
      - 9

.. only:: not esp32

    低功耗蓝牙发射功率等级
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. list-table:: 低功耗蓝牙发射功率等级
        :widths: 40 60

        * - 功率等级
          - 低功耗蓝牙发射功率 (dBm)
        * - 0
          - -24
        * - 1
          - -21
        * - 2
          - -18
        * - 3
          - -15
        * - 4
          - -12
        * - 5
          - -9
        * - 6
          - -6
        * - 7
          - -3
        * - 8
          - 0
        * - 9
          - 3
        * - 10
          - 6
        * - 11
          - 9
        * - 12
          - 12
        * - 13
          - 15
        * - 14
          - 18
        * - 15
          - 20

    低功耗蓝牙 5.0 PHY 信道与索引
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    - 对于 BLE，EspRFTestTool 工具使用信道索引（Channel Index）来识别信道。

    .. list-table::  低功耗蓝牙 5.0 PHY 信道与索引
        :widths: 50 60 50

        * - PHY 信道
          - 射频中心频率（MHz）
          - 信道索引
        * - 0
          - 2402
          - 37
        * - 1
          - 2404
          - 0
        * - 2
          - 2406
          - 1
        * - ...
          - ...
          - ...
        * - 11
          - 2424
          - 10
        * - 12
          - 2426
          - 38
        * - 13
          - 2428
          - 11
        * - 14
          - 2430
          - 12
        * - ...
          - ...
          - ...
        * - 38
          - 2478
          - 36
        * - 39
          - 2480
          - 39
