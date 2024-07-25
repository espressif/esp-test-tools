CE 认证
================

:link_to_translation:`en:[English]`

CE 认证（Conformité Européene Mark）是欧盟国家对产品的一种强制性认证标志，表明产品符合欧盟相关指令的基本要求，包括安全性、健康性和环境保护。

射频产品的 CE 认证需要通过非信令、自适应、阻塞测试：

.. only:: not esp32h2

    - :doc:`../rf_test_items/wifi_non_signaling_test`
    - :doc:`../rf_test_items/wifi_adaptivity_test`
    - :doc:`../rf_test_items/wifi_blocking_test`

.. only:: not esp8266 and not esp32s2

    - :doc:`../rf_test_items/bt_ble_non_signaling_test`

.. only:: not esp8266 and not esp32 and not esp32s2

    - :doc:`../rf_test_items/ble_dtm_test`
    - :doc:`../rf_test_items/ble_adaptivity_test`
    - :doc:`../rf_test_items/ble_blocking_test`

.. only:: esp32h2 or esp32c6

    - :doc:`../rf_test_items/zigbee_non_signaling_test`