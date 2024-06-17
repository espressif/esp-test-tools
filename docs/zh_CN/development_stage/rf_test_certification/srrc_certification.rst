SRRC 认证
================

SRRC 中国[129]新规认证需要非信令、自适应测试需求：

.. only:: not esp32h2

    - Wi-Fi，BLE，Zigbee 非信令测试，参考如下章节：

      :doc:`../rf_test_items/wifi_non_signaling_test`

.. only:: not esp8266 and not esp32s2

    - 低功耗蓝牙非信令测试，参考如下章节：

      :doc:`../rf_test_items/bt_ble_non_signaling_test`

.. only:: esp32h2 or esp32c6

    - 802.15.4 非信令测试，参考如下章节：

      :doc:`../rf_test_items/zigbee_non_signaling_test`

.. only:: not esp32h2

    - Wi-Fi 自适应测试参考如下章节：

        :doc:`../rf_test_items/wifi_adaptivity_test`
