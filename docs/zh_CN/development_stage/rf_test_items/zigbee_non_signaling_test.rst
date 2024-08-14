802.15.4 非信令测试
===========================

:link_to_translation:`en:[English]`

本章介绍基于 {IDF_TARGET_NAME} 芯片或模组的产品如何进行 802.15.4 非信令测试（非信令测试也称为定频测试），由于使用同一套射频链路，因此仅需测试 Zigbee 即可。

.. include:: rf_non_signalling_test_setup.inc

Zigbee 发射性能测试
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- **Test Mode**：

  * ZB TX packet：用于发射性能测试；
  * ZB TX continue：用于认证测试。

- **Power Level**：设置 Zigbee 发射功率等级，支持 0~15 档测试。
- **Channel**：设置 Zigbee 测试信道。
- **Payload Length**：设置 Payload 长度，支持手动输入，范围 3~127，默认为 127。

点击 ``start`` 后在 log 窗口中显示 Zigbee 发射参数说明，参考如下：

::

    ZB TX start: len=127, chan=18, pwr=12, tx_num=0, contin_en=0

表明 Zigbee 发包正常，此时可使用综测仪检测发射性能。

  .. figure:: ../../../_static/rf_test_tool/esp32h2_zigbee_tx_on.png
      :align: center
      :scale: 80%

      Zigbee 发射性能测试

Zigbee 接收性能测试
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- **Test Mode**：设置为 ZB RX 用于 Zigbee 接收性能测试。
- **Channel**：设置 Zigbee 测试信道。

点击 ``start`` 后使用仪器在测试信道发包，完成后点击 ``stop``，在 log 窗口中显示收包信息如下：

::

    RX 1000 1 0 0 0 1 -52029 0 -27116 34913

其中：

- 第 1 个参数 Res[0] 返回字符串 “RX”。
- 第 2 个参数 Res[1]（10 进制）表示本次测试在对应速率下收到的包的数量。本次测试中，Res[1] 为 1000。
- 倒数第 4 个参数 Res[7]（10 进制）表示本次测试在对应速率下收到的包的 RSSI 总和。本次测试中，Res[7] 为 -52029。

根据上述参数，可计算出：

- 丢包率 PER = [1-(Res[1]/Sent_Packet_Numbers)]*100%<=1%
- 每个包的 RSSI = Res[7]/(Res[1])

  .. figure:: ../../../_static/rf_test_tool/esp32h2_zigbee_rx_on.png
      :align: center
      :scale: 80%

      Zigbee 接收性能测试

附录
----------------

本附录主要用于说明 {IDF_TARGET_NAME} 802.15.4 的输出目标功率，用于射频调试或测试对照。

.. list-table:: {IDF_TARGET_NAME} 802.15.4 发射功率等级
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
