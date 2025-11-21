Wi-Fi 非信令测试
===========================

:link_to_translation:`en:[English]`

Wi-Fi 非信令测试，也叫定频测试，是在不建立实际数据连接的情况下，直接控制设备发射特定信号，用于评估设备的射频性能，如发射功率、频谱质量和误码率等，以确保设备在各种环境中的无线通信质量。

.. include:: rf_non_signalling_test_setup.inc

开始测试
----------------

Wi-Fi 发射性能测试
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- **Test Mode**：

  * TX packet：用于发射性能测试，发包占空比低于 50%；
  * TX continues：用于认证测试，发包占空比接近 100%；
  * TX tone：用于单载波测试。

- **Wi-Fi Rate**：设置 Wi-Fi 测试速率
- **BandWidth**：设置 Wi-Fi 测试带宽
- **Channel**：设置 Wi-Fi 测试信道
- **Atteunuation (0.25 dB)**：设置功率衰减

  * 0 表示无衰减，为默认值；
  * 2 表示衰减 0.5 dB；
  * 4 表示衰减 1 dB，依次类推。

- **Duty Cycle**：在 TX packet 测试时用于设置发包占空比，默认选择 default（约 30%），可配置为 10%、50%、90%。
- **Certification EN**：默认不使能，仅在验证 Power Limit 功能时使用。
- **Certification Code**：默认不使能，仅在验证 Power Limit 功能时使用。

点击 ``start`` 后在 log 窗口中应打印类似如下 Wi-Fi 发射参数说明：

::

    Wifi tx out: channel=1, rate=0x0, BK=0, length=50, delay=1200, packet_num=0

上述参数表明 Wi-Fi 发包正常，此时可使用测试仪器检测发射性能。

.. figure:: ../../../_static/rf_test_tool/esp_wifi_tx_on.png
    :align: center
    :scale: 80%

    Wi-Fi 发射性能测试

Wi-Fi 接收性能测试
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- **Test Mode**：设置为 ``RX packet`` 用于接收性能测试。
- **Wi-Fi Rate**：设置 Wi-Fi 测试速率。
- **BandWidth**：设置 Wi-Fi 测试带宽。
- **Channel**：设置 Wi-Fi 测试信道。

点击 ``start`` 后，仪器在测试信道发包，完成后点击 ``stop``，在 log 窗口中应显示类似如下收包信息：

::

    Correct:1000 Desired:1000 RSSI:-614 noise:-960 gain:0 paral:0 para2:0 freq:0

其中：

- **Correct**：本次收到的总的包个数。
- **Desired**：本次收到的对应速率的包个数。
- **RSSI**：表示收到 Desired 包的平均 RSSI，如 “RSSI：-614” 表示 RSSI 值为 -61.4。

.. note::

    - ``Desired`` 为 0 表明未收到仪器发包，请检查仪器发包设置、包文件，以确保收包链路正常；
    - ``Desired`` 不为 0 而且 ``Correct`` 大于 Desired 表明环境存在干扰，请在屏蔽环境下复测；
    - 收包信息中的其它参数仅用于 RD debug，无实际意义。

.. figure:: ../../../_static/rf_test_tool/esp_wifi_rx_on.png
    :align: center
    :scale: 80%

    Wi-Fi 接收性能测试

附录
----------------

本附录主要用于说明芯片的 Wi-Fi 目标输出功率，用于射频调试或测试对照。

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

    .. list-table:: ESP32-S3 Wi-Fi 目标发射功率
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


.. only:: esp32c61

    .. list-table:: ESP32-C61 Wi-Fi 目标发射功率
        :widths: 30 50

        * - 速率
          - ESP32-C61 Wi-Fi 目标功率 (dBm)
        * - 11b 1M
          - 20.5
        * - 11b 11M
          - 20.5
        * - 11g 6M
          - 20
        * - 11g 54M
          - 19
        * - HT20-11n MCS0
          - 19
        * - HT20-11n MCS7
          - 18
        * - HT40-11n MCS0
          - 18.5
        * - HT40-11n MCS7
          - 17.5
        * - HE20-11ax MCS0
          - 19
        * - HE20-11ax MCS7
          - 18
        * - HE20-11ax MCS9
          - 15.5



.. only:: esp32c5

    .. list-table:: ESP32-C5 2.4G Wi-Fi 目标发射功率
        :widths: 30 50

        * - 速率
          - ESP32-C5 2.4G Wi-Fi 目标功率 (dBm)
        * - 11b 1M
          - 19.5
        * - 11b 11M
          - 19.5
        * - 11g 6M
          - 18.5
        * - 11g 54M
          - 16.5
        * - HT20-11n MCS0
          - 18.5
        * - HT20-11n MCS7
          - 16.5
        * - HT40-11n MCS0
          - 17.5
        * - HT40-11n MCS7
          - 15.5
        * - HE20-11ax MCS0
          - 18.5
        * - HE20-11ax MCS7
          - 16.5
        * - HE20-11ax MCS9
          - 14.5


    .. list-table:: ESP32-C5 5G Wi-Fi 目标发射功率
        :widths: 30 50

        * - 速率
          - ESP32-C5 5G Wi-Fi 目标功率 (dBm)
        * - 11a 6M
          - 18.5
        * - 11a 54M
          - 16.5
        * - HT20-11n MCS0
          - 18.5
        * - HT20-11n MCS7
          - 15.5
        * - HT40-11n MCS0
          - 17.5
        * - HT40-11n MCS7
          - 14.5
        * - VHT20-11ac MCS0
          - 18.5
        * - VHT20-11ac MCS7
          - 15.5
        * - HE20-11ax MCS0
          - 18.5
        * - HE20-11ax MCS7
          - 15.5
