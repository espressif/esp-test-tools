Wi-Fi Non-Signaling Test
===========================

:link_to_translation:`zh_CN:[中文]`

This chapter introduces how to conduct a Wi-Fi Non-Signaling Test (also known as Fixed Frequency Test) on products based on Espressif chips or modules.

.. include:: rf_non_signalling_test_setup.inc

Wi-Fi Transmission Performance Test
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- **Test Mode**: Set to

  * Tx packet for transmission performance test, packet duty cycle is less than 50%;
  * Tx continues for certification test, packet duty cycle is close to 100%;
  * Tx tone for single carrier test.

- **Wi-Fi Rate**: Set Wi-Fi test rate
- **BandWidth**: Set Wi-Fi test bandwidth
- **Channel**: Set Wi-Fi test channel
- **Atteunuation (0.25 dB)**: Set power attenuation,

  * 0 means no attenuation, which is the default value;
  * 2 means 0.5 dB attenuation;
  * 4 means 1 dB attenuation, and so on.

- **Duty Cycle**: Used to set the packet duty cycle during the Tx packet test, default is default (about 30%), can be configured to 10%, 50%, 90%.
- **Certification EN**: Not enabled by default, only used when verifying the Power Limit function.
- **Certification Code**: Not enabled by default, only used when verifying the Power Limit function.

After clicking start, the log window should print similar Wi-Fi transmission parameter descriptions as follows:

::

    Wifi tx out: channel=1, rate=0x0, BK=0, length=50, delay=1200, packet_num=0

The above parameters indicate that Wi-Fi packet sending is normal, and the transmission performance can be detected with test equipment at this time.

.. figure:: ../../../_static/rf_test_tool/esp32s3_wifi_test_on.png
    :align: center
    :scale: 80%

    Wi-Fi Transmission Performance Test

Wi-Fi Reception Performance Test
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- **Test Mode**: Set to RX packet for reception performance test.
- **Wi-Fi Rate**: Set Wi-Fi test rate.
- **BandWidth**: Set Wi-Fi test bandwidth.
- **Channel**: Set Wi-Fi test channel.

After clicking start, the instrument sends packets on the test channel, click stop after completion, the log window should display similar packet receiving information as follows:

::

    Correct:1000 Desired:1000 RSSI:-614 noise:-960 gain:0 paral:0 para2:0 freq:0

Where:

- **Correct**: The total number of packets received this time.
- **Desired**: The number of packets received at the corresponding rate this time.
- **RSSI**: Represents the average RSSI of the received Desired packets, such as "RSSI: -614" means the RSSI value is -61.4.

.. note::

    - Desired being 0 indicates that the instrument's packets were not received, please check the instrument's packet sending settings and packet files to ensure the packet receiving link is normal;
    - Desired is not 0 and Correct is greater than Desired indicates that there is interference in the environment, please retest in a shielded environment;
    - Other parameters in the packet receiving information are only used for RD debug and have no actual meaning.

.. figure:: ../../../_static/rf_test_tool/esp32c6_wifi_rx_on.png
    :align: center
    :scale: 80%

    Wi-Fi Reception Performance Test

Appendix
----------------

This appendix is mainly used to explain the target output power of the chip's Wi-Fi, which is used for RF debugging or test reference.

.. only:: esp8266

    .. list-table:: ESP8266 Wi-Fi Target Transmit Power
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

    .. list-table:: ESP32 Wi-Fi Target Transmit Power
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

    .. list-table:: ESP32-C2 Wi-Fi Target Transmit Power
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

    .. list-table:: ESP32-C3 Wi-Fi Target Transmit Power
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

    .. list-table:: ESP32-C6 Wi-Fi Target Transmit Power
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

    .. list-table:: ESP32-S2 Wi-Fi Target Transmit Power
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

    .. list-table:: ESP32-S3 Wi-Fi Target Transmit Power
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
