CE Certification
================

:link_to_translation:`zh_CN:[中文]`

CE Certification (Conformité Européene Mark) is a mandatory certification mark for products in European Union countries, indicating that the product meets the basic requirements of relevant EU directives, including safety, health, and environmental protection.

The CE certification of RF products requires non-signaling, adaptivity, and blocking tests:

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
