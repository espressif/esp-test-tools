SRRC 认证
================

SRRC（State Radio Regulatory Commission，国家无线电管理委员会）认证是中国针对无线电设备的一项强制性认证。该认证旨在确保无线电设备符合国家无线电管理的相关法规和技术标准，以避免对电磁环境和其他无线电设备的干扰。获得 SRRC 认证的产品才能合法进入中国市场销售和使用。

射频产品的 SRRC 认证需要通过相关非信令、自适应测试：

.. only:: not esp32h2

    - :doc:`../rf_test_items/wifi_non_signaling_test`
    - :doc:`../rf_test_items/wifi_adaptivity_test`

.. only:: not esp8266 and not esp32s2

    - :doc:`../rf_test_items/bt_ble_non_signaling_test`

.. only:: esp32h2 or esp32c6

    - :doc:`../rf_test_items/zigbee_non_signaling_test`
