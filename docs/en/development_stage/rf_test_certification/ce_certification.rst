CE Certification
================

:link_to_translation:`zh_CN:[中文]`

CE Certification (Conformité Européene Mark) is a mandatory certification for products in European Union (EU) countries, indicating that the product meets the basic requirements of relevant EU directives, including safety, health, and environmental protection.

The CE certification of RF products requires non-signaling, adaptivity, and blocking tests:

.. only:: not esp32h2

    - For the test steps of the Wi-Fi Non-Signaling Test, please refer to :doc:`../rf_test_items/wifi_non_signaling_test`.
    - For the test steps of the Wi-Fi Adaptivity Test, please refer to :doc:`../rf_test_items/wifi_adaptivity_test`.
    - For the test steps of the Wi-Fi Blocking Test, please refer to :doc:`../rf_test_items/wifi_blocking_test`.

.. only:: not esp8266 and not esp32s2

    - For the test steps of the Bluetooth/Bluetooth LE Non-Signaling Test, please refer to :doc:`../rf_test_items/bt_ble_non_signaling_test`.

.. only:: not esp8266 and not esp32 and not esp32s2

    - For the test steps of the Bluetooth LE DTM Test, please refer to :doc:`../rf_test_items/ble_dtm_test`.
    - For the test steps of the Bluetooth LE Adaptivity Test, please refer to :doc:`../rf_test_items/ble_adaptivity_test`.
    - For the test steps of the Bluetooth LE Blocking Test, please refer to :doc:`../rf_test_items/ble_blocking_test`.

.. only:: esp32h2 or esp32c6

    - For the test steps of the 802.15.4 Non-Signaling Test, please refer to :doc:`../rf_test_items/zigbee_non_signaling_test`.
