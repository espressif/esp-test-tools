802.15.4 Non-Signaling Test
===========================

:link_to_translation:`zh_CN:[中文]`

802.15.4 Non-Signaling Test directly controls the device to transmit specific signals without requiring a network connection. It evaluates key performance metrics such as transmit power, spectrum characteristics, and error rate, ensuring reliable communication quality in IoT applications.

.. include:: rf_non_signalling_test_setup.inc

Start Testing
-------------

Zigbee TX Performance Test
^^^^^^^^^^^^^^^^^^^^^^^^^^

- **Test Mode**:

  * ZB TX packet: Used for TX performance tests;
  * ZB TX continue: High packet duty cycle used for certification testing.

- **Power Level**: Set the Zigbee TX power level, supporting 0~15 levels for testing.
- **Channel**: Set the Zigbee test channel.
- **Payload Length**: Set the payload length. Manual input is supported. Range: 3~127. Default: 127.

After clicking ``start``, the Zigbee TX parameter description is displayed in the log window, similar to the following:

::

    ZB TX start: len=127, chan=11, pwr=15, tx_num=0, contin_en=0

This indicates that Zigbee is sending packets normally, and the TX performance can be detected using the tester.

  .. figure:: ../../../_static/rf_test_tool/esp32h2_zigbee_tx_on.png
      :align: center
      :scale: 80%

      Zigbee TX Performance Test

Zigbee RX Performance Test
^^^^^^^^^^^^^^^^^^^^^^^^^^

- **Test Mode**: Set to ZB RX for Zigbee RX performance test.
- **Channel**: Set the Zigbee test channel.

After clicking ``start``, use the tester to send packets on the test channel. Click ``stop`` after completion. The packet RX information is displayed in the log window, similar to the following:

::

    RX 1000 1 1 0 0 0 -60058 0 -21398 38679

Among them:

- The first parameter Res[0] returns the string "RX".
- The second parameter Res[1] (decimal) indicates the number of packets received at the corresponding rate in this test. In this test, Res[1] is 1000.
- The fourth last parameter, Res[7] (in decimal), represents the total RSSI of the packets received at the corresponding rate in this test. In this test, Res[7] is -60058.

Based on the above parameters, you can calculate:

- Packet loss rate PER = [1-(Res[1]/Sent_Packet_Numbers)]*100%<=1%
- RSSI per packet = Res[7]/(Res[1])

  .. figure:: ../../../_static/rf_test_tool/esp32h2_zigbee_rx_on.png
      :align: center
      :scale: 80%

      Zigbee RX Performance Test

Appendix
--------

This appendix is mainly used to explain the output target power of {IDF_TARGET_NAME} 802.15.4, which is used for RF debugging or test reference.

.. only:: esp32c6 or esp32c5

  .. list-table:: {IDF_TARGET_NAME} 802.15.4 TX Power Level
      :widths: 30 50

      * - Power Level
        - 802.15.4 Power (dBm)
      * - 0
        - -15
      * - 1
        - -15
      * - 2
        - -15
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

.. only:: esp32h2

  .. list-table:: {IDF_TARGET_NAME} 802.15.4 TX Power Level
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
