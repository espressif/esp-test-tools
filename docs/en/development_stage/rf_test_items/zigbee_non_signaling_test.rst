802.15.4 Non-Signaling Test
===========================

:link_to_translation:`zh_CN:[中文]`

This chapter introduces how to conduct 802.15.4 non-signaling tests (also known as fixed frequency tests) on products based on ESP chips or modules. Since the same RF link is used, it is only necessary to test Zigbee.

.. include:: rf_non_signalling_test_setup.inc

Zigbee Transmission Performance Test
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- **Test Mode**: Set to

  * ZB TX packet for transmission performance test;
  * ZB TX continue for certification test.

- **Power Level**: Set the Zigbee transmission power level, supporting 0~15 levels of testing.
- **Channel**: Set the Zigbee test channel.
- **Payload Length**: Set the Payload length, manual input is supported, the range is 3~127, default is 127.

After clicking start, the Zigbee transmission parameter description is displayed in the log window, as follows:

::

    ZB TX start: len=127, chan=18, pwr=12, tx_num=0, contin_en=0

This indicates that Zigbee is sending packets normally, and the transmission performance can be detected with a comprehensive tester at this time.

  .. figure:: ../../../_static/rf_test_tool/esp32h2_zigbee_tx_on.png
      :align: center
      :scale: 80%

      Zigbee Transmission Performance Test

Zigbee Reception Performance Test
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- **Test Mode**: Set to ZB RX for Zigbee reception performance test.
- **Channel**: Set the Zigbee test channel.

After clicking start, use the instrument to send packets on the test channel, click stop after completion, and the packet reception information is displayed in the log window as follows:

::

    RX 1000 1 0 0 0 1 -52029 0 -27116 34913

Among them:

- The first parameter Res[0] returns the string "RX".
- The second parameter Res[1] (decimal) indicates the number of packets received at the corresponding rate in this test. In this test, Res[1] is 1000.
- The fourth parameter from the end Res[7] (decimal) indicates the total RSSI of the packets received at the corresponding rate in this test. In this test, Res[7] is -52029.

Based on the above parameters, you can calculate:

- Packet loss rate PER = [1-(Res[1]/Sent_Packet_Numbers)]*100%<=1%
- RSSI per packet = Res[7]/(Res[1])

  .. figure:: ../../../_static/rf_test_tool/esp32h2_zigbee_rx_on.png
      :align: center
      :scale: 80%

      Zigbee Reception Performance Test

Appendix
----------------

This appendix is mainly used to explain the output target power of {IDF_TARGET_NAME} 802.15.4, which is used for RF debugging or test reference.

.. list-table:: {IDF_TARGET_NAME} 802.15.4 Transmission Power Level
    :widths: 30 50

    * - Power Level
      - 802.15.4 Power (dBm)
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
