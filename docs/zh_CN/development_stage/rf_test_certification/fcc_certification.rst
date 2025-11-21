FCC 认证
=================

:link_to_translation:`en:[English]`

FCC 认证（Federal Communications Commission Certification）是美国联邦通信委员会的强制性认证，表明产品符合美国相关法规的要求，包括无线电频谱使用、电磁兼容性和射频辐射等。

射频产品的 FCC 认证需要通过相关非信令测试：

.. only:: not esp32h2

    - :doc:`../rf_test_items/wifi_non_signaling_test`

.. only:: not esp8266 and not esp32s2

    - :doc:`../rf_test_items/bt_ble_non_signaling_test`

.. only:: esp32h2 or esp32c6 or esp32c5

    - :doc:`../rf_test_items/zigbee_non_signaling_test`