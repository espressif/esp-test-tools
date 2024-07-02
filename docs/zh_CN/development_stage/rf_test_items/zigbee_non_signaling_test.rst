802.15.4 非信令测试
===========================

:link_to_translation:`en:[English]`

本章介绍基于 ESP 芯片或模组的产品如何进行 802.15.4 非信令测试（非信令测试也称为定频测试），由于使用同一套射频链路，因此仅需测试 Zigbee 即可。

测试准备
---------------------------

测试环境搭建
^^^^^^^^^^^^^^^^^^^^^
.. figure:: ../../../_static/rf_test_tool/zigbee_non-signaling_test_setup.png
    :align: center
    :scale: 80%

    环境搭建示意图

- 待测设备 (DUT) 为基于 ESP 系列芯片设计的产品。
- PC 端通过 UART 与 DUT 进行通讯，使用 ESPRFTestTool 工具实现各种测试模式的配置。
- 测试仪器常见为 WT-328/IQXel 等综测仪，用于测试 DUT 在不同模式下的射频性能。

硬件连接
^^^^^^^^^^^^^^^^^^^^^

.. figure:: ../../../_static/rf_test_tool/usb_to_uart_connection_zigbee.png
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
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

{IDF_TARGET_RF_NON_SIGNALLING_FIRMWARE:default="未更新", esp32c6="ESP32C6_RF_BIN", esp32h2="ESP32H2_RF_BIN"}

- 如果未烧录测试固件，请参考 EspRFTestTool 工具包中的 DownloadTool 章节，并烧录 {IDF_TARGET_RF_NON_SIGNALLING_FIRMWARE}。

ESPRFTestTool 工具
^^^^^^^^^^^^^^^^^^^^^^^

Zigbee 非信令测试
---------------------------------------

Zigbee 发射性能测试
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- Test Mode：

  * ZB TX packet 用于发射性能测试；
  * ZB TX continue 用于认证测试。

- Power Level：设置 Zigbee 发射功率等级，支持 0~15 档测试。
- Channel：设置 Zigbee 测试信道。
- Payload Lenght：设置 Payload 长度，支持手动输入，范围 3~127，默认为 127。

点击 start 后在 log 窗口中显示 Zigbee 发射参数说明，参考如下：

::

    ZB TX start: len=127, chan=18, pwr=12, tx_num=0, contin_en=0

表明 Zigbee 发包正常，此时可使用综测仪检测发射性能。

  .. figure:: ../../../_static/rf_test_tool/esp32h2_zigbee_tx_on.png
      :align: center
      :scale: 80%

      Zigbee 发射性能测试

Zigbee 接收性能测试
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- Test Mode：选择 ZB RX 用于 Zigbee 接收性能测试。
- Channel：设置 Zigbee 测试信道。

点击 start 后使用仪器在测试信道发包，完成后点击 stop，在 log 窗口中显示收包信息如下：

::

    RX 1000 1 0 0 0 1 -52029 0 -27116 34913

其中：

- 返回打印的第 1 个参数 Res[0] 返回字符串 'RX'。
- 返回打印的第 2 个参数 Res[1]（10 进制）表示本次测试在对应速率下收到的包的数量。
- 返回打印的倒数第 4 个参数 Res[7]（10 进制）表示本次测试在对应速率下收到的包的 RSSI 总和。

计算:

- 丢包率 PER = [1-(Res[1]/Sent_Packet_Numbers)]*100%<=1%
- 每个包的 RSSI = Res[7]/(Res[1])

  .. figure:: ../../../_static/rf_test_tool/esp32h2_zigbee_rx_on.png
      :align: center
      :scale: 80%

      Zigbee 接收性能测试

附录
----------------

本附录主要用于说明芯片 802.15.4 的输出目标功率，用于射频调试或测试对照。

802.15.4 发射功率等级
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. list-table:: 802.15.4 发射功率等级
    :widths: 30 50

    * - 功率等级
      - 802.15.4 功率 (dBm)
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
