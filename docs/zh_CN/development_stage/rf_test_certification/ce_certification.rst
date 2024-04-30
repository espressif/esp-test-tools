CE 认证
================

CE 欧盟认证需要非信令、自适应、阻塞测试：

.. only:: not esp32h2

    - Wi-Fi，BLE，Zigbee 非信令测试，参考如下章节：

      :doc:`../rf_test_items/wifi_non_signaling_test`

-  低功耗蓝牙非信令测试，参考如下章节：

   :doc:`../rf_test_items/ble_non_signaling_test`

.. only:: esp32h2 or esp32c6

    - 802.15.4 非信令测试，参考如下章节：

      :doc:`../rf_test_items/zigbee_non_signaling_test`

.. only:: not esp32h2

    - Wi-Fi 自适应测试参考如下章节：

        :doc:`../rf_test_items/wifi_adaptivity_test`

.. only:: not esp32 and not esp32s2

    - BLE 自适应测试参考如下章节：

        :doc:`../rf_test_items/ble_adaptivity_test`

.. only:: not esp32h2

    - Wi-Fi Blocking 测试参考如下章节：

        :doc:`../rf_test_items/wifi_blocking_test`

.. only:: not esp32 and not esp32s2

    - BLE Blocking 测试参考如下章节：

        :doc:`../rf_test_items/ble_blocking_test`
