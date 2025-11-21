FCC Certification
=================

:link_to_translation:`zh_CN:[中文]`

FCC Certification (Federal Communications Commission Certification) is a mandatory certification by the U.S. Federal Communications Commission, ensuring compliance with regulations on radio spectrum use, electromagnetic compatibility, and RF radiation.

The FCC certification of RF products requires passing relevant non-signaling tests:

.. only:: not esp32h2

    - :doc:`../rf_test_items/wifi_non_signaling_test`

.. only:: not esp8266 and not esp32s2

    - :doc:`../rf_test_items/bt_ble_non_signaling_test`

.. only:: esp32h2 or esp32c6 or esp32c5

    - :doc:`../rf_test_items/zigbee_non_signaling_test`
