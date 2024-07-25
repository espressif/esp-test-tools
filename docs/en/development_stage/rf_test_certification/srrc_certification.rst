SRRC Certification
==================

The SRRC (State Radio Regulatory Commission) certification is a mandatory certification in China for radio equipment. This certification aims to ensure that radio equipment complies with the relevant laws and technical standards of national radio management, to avoid interference with the electromagnetic environment and other radio equipment. Only products that have obtained SRRC certification can legally enter the Chinese market for sale and use.

The SRRC certification of RF products requires related non-signaling and adaptivity tests:

.. only:: not esp32h2

    - :doc:`../rf_test_items/wifi_non_signaling_test`
    - :doc:`../rf_test_items/wifi_adaptivity_test`

.. only:: not esp8266 and not esp32s2

    - :doc:`../rf_test_items/bt_ble_non_signaling_test`

.. only:: esp32h2 or esp32c6

    - :doc:`../rf_test_items/zigbee_non_signaling_test`
