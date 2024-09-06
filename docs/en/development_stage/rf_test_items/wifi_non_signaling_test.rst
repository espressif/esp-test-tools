Wi-Fi Non-Signaling Test
========================

:link_to_translation:`zh_CN:[中文]`

Wi-Fi Non-Signaling Test directly controls the device to transmit specific signals without establishing a data connection. It evaluates key RF performance metrics, such as transmit power, spectrum quality, and error rate, ensuring wireless communication quality in various scenarios.

.. include:: rf_non_signalling_test_setup.inc

Start Testing
-------------

Wi-Fi TX Performance Test
^^^^^^^^^^^^^^^^^^^^^^^^^

- **Test Mode**:

  * TX packet: Packet transmission duty cycle less than 50%, used for TX performance tests
  * TX continues: Packet duty cycle close to 100%, used for certification tests;
  * TX tone: Used for single-carrier tests.

- **Wi-Fi Rate**: Set Wi-Fi test rate
- **BandWidth**: Set Wi-Fi test bandwidth
- **Channel**: Set Wi-Fi test channel
- **Atteunuation (0.25 dB)**: Set power attenuation

  * 0 means no attenuation, which is the default value;
  * 2 means 0.5 dB attenuation;
  * 4 means 1 dB attenuation, and so on.

- **Duty Cycle**: Set the packet duty cycle in TX packet tests. The default duty cycle is around 30%. Supported values: 10%, 50%, 90%.
- **Certification EN**: Not enabled by default. Used only when verifying Power Limit function.
- **Certification Code**: Not enabled by default. Used only when verifying Power Limit function.

After clicking ``start``, the log window should print Wi-Fi transmission parameters similar to the following:

::

    Wifi tx out: channel=1, rate=0x0, BK=0, length=50, delay=1200, packet_num=0

The above parameters indicate that Wi-Fi packet transmission is normal, and the transmission performance can be detected with tester at this time.

.. figure:: ../../../_static/rf_test_tool/esp32s3_wifi_test_on.png
    :align: center
    :scale: 80%

    Wi-Fi TX Performance Test

Wi-Fi RX Performance Test
^^^^^^^^^^^^^^^^^^^^^^^^^

- **Test Mode**: Set to ``RX packet`` for RX performance tests.
- **Wi-Fi Rate**: Set Wi-Fi test rate.
- **BandWidth**: Set Wi-Fi test bandwidth.
- **Channel**: Set Wi-Fi test channel.

After clicking ``start``, the tester sends packets on the test channel. Click ``stop`` after completion. The log window should display packet RX information similar to the following:

::

    Correct:1000 Desired:1000 RSSI:-614 noise:-960 gain:0 paral:0 para2:0 freq:0

Where:

- **Correct**: The total number of packets received this time.
- **Desired**: The number of packets received at the corresponding rate this time.
- **RSSI**: Represents the average RSSI of the received Desired packets. For example, "RSSI: -614" means the RSSI value is -61.4.

.. note::

    - If ``Desired`` is 0, no packets were received from the tester. Please check the tester's packet settings and packet file to ensure the packet RX link is normal;
    - If ``Desired`` is not 0 and ``Correct`` is greater than ``Desired``, there is interference in the environment. Please retest in a shielded environment;
    - Other parameters in the packet RX information are only used for RD debug and have no actual meaning.

.. figure:: ../../../_static/rf_test_tool/esp32c6_wifi_rx_on.png
    :align: center
    :scale: 80%

    Wi-Fi RX Performance Test

Appendix
--------

This appendix is mainly used to explain the target output power of the chip's Wi-Fi, which is used for RF debugging or test reference.

.. only:: esp8266

    .. list-table:: ESP8266 Wi-Fi Target TX Power
        :widths: 30 40

        * - Rate
          - ESP8266 Wi-Fi Target Power (dBm)
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

    .. list-table:: ESP32 Wi-Fi Target TX Power
        :widths: 30 40

        * - Rate
          - ESP32 Wi-Fi Target Power (dBm)
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

    .. list-table:: ESP32-C2 Wi-Fi Target TX Power
        :widths: 30 40

        * - Rate
          - ESP8684 Wi-Fi Target Power (dBm)
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

    .. list-table:: ESP32-C3 Wi-Fi Target TX Power
        :widths: 50 50 50

        * - Rate
          - ESP32-C3 Wi-Fi Target Power (dBm)
          - ESP8685 Wi-Fi Target Power (dBm)
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

    .. list-table:: ESP32-C6 Wi-Fi Target TX Power
        :widths: 30 50

        * - Rate
          - ESP32-C6 Wi-Fi Target Power (dBm)
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

    .. list-table:: ESP32-S2 Wi-Fi Target TX Power
        :widths: 30 50

        * - Rate
          - ESP32-S2 Wi-Fi Target Power (dBm)
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

    .. list-table:: ESP32-S3 Wi-Fi Target TX Power
        :widths: 30 50

        * - Rate
          - ESP32-S3 Wi-Fi Target Power (dBm)
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
