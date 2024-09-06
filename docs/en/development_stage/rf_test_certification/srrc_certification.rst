SRRC Certification
==================

The SRRC (State Radio Regulatory Commission) Certification is a mandatory certification for radio equipment in China, ensuring compliance with national radio management regulations to avoid electromagnetic interference.

The SRRC certification of RF products requires related non-signaling and adaptivity tests:

.. only:: not esp32h2

    - :doc:`../rf_test_items/wifi_non_signaling_test`
    - :doc:`../rf_test_items/wifi_adaptivity_test`

.. only:: not esp8266 and not esp32s2

    - :doc:`../rf_test_items/bt_ble_non_signaling_test`

.. only:: esp32h2 or esp32c6

    - :doc:`../rf_test_items/zigbee_non_signaling_test`
