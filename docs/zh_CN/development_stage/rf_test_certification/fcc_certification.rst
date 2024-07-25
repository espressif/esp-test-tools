FCC 认证
=================

:link_to_translation:`en:[English]`

FCC 认证（Federal Communications Commission Certification）是指产品在美国市场销售和使用前，必须经过美国联邦通信委员会（FCC）的审核和批准。

射频产品的 FCC 认证需要通过相关非信令测试：

.. only:: not esp32h2

    - :doc:`../rf_test_items/wifi_non_signaling_test`

.. only:: not esp8266 and not esp32s2

    - :doc:`../rf_test_items/bt_ble_non_signaling_test`

.. only:: esp32h2 or esp32c6

    - :doc:`../rf_test_items/zigbee_non_signaling_test`