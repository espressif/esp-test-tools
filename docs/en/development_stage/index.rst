Development Stage
*****************

:link_to_translation:`zh_CN:[中文]`

{IDF_TARGET_BT_BLE_OPTION: default="Bluetooth LE", esp32="Bluetooth and Bluetooth LE"}

For the development stage, this repository provides test tools, procedures, and necessary firmware for the following RF test items:

.. only:: not esp32h2

   - :doc:`Wi-Fi Non-Signaling Test </development_stage/rf_test_items/wifi_non_signaling_test>`: This test directly controls the device to transmit specific signals without establishing a data connection. It evaluates key RF performance metrics, such as transmit power, spectrum quality, and error rate, ensuring wireless communication quality in various scenarios.

   - :doc:`Wi-Fi Signaling Test </development_stage/rf_test_items/wifi_signaling_test>`: This test assesses and verifies the Wi-Fi signaling functions of wireless network devices, focusing on stable and reliable communication across different operating scenarios. It evaluates the Over-The-Air (OTA) performance, including Total Radiated Power (TRP) and Total Isotropic Sensitivity (TIS).

   - :doc:`Wi-Fi Adaptivity Test </development_stage/rf_test_items/wifi_adaptivity_test>`: This test simulates various network conditions and loads to access device's real-time adjustments in transmission rate, channel selection, and power levels, optimizing overall network performance and stability.

   - :doc:`Wi-Fi Blocking Test </development_stage/rf_test_items/wifi_blocking_test>`: This test evaluates the device's reception performance in environments with strong interference. By introducing high-intensity interference signals, it measures reception sensitivity and anti-interference capability, ensuring reliable operation in complex wireless environments.

.. only:: not esp8266 and not esp32s2

   - :doc:`{IDF_TARGET_BT_BLE_OPTION} Non-Signaling Test </development_stage/rf_test_items/bt_ble_non_signaling_test>`: This test controls the device to transmit specific signals without establishing a connection, evaluating performance metrics such as transmit power, spectrum characteristics, and error rate to ensure communication quality.

.. only:: not esp8266 and not esp32 and not esp32s2

   - :doc:`Bluetooth LE DTM Test </development_stage/rf_test_items/ble_dtm_test>`: This test evaluates the RF performance of Bluetooth LE devices by directly controlling the device to enter specific transmission or reception modes, accessing key metrics like transmit power, reception sensitivity, and spectrum characteristics.

   - :doc:`Bluetooth LE Adaptivity Test </development_stage/rf_test_items/ble_adaptivity_test>`: This test ensures the device meets performance criteria during frequency hopping, particularly when the Power Spectral Density (PSD) of the Bluetooth LE signal exceeds 10 dBm/MHz, avoiding interference with other wireless devices.

   - :doc:`Bluetooth LE Blocking Test </development_stage/rf_test_items/ble_blocking_test>`: This test assesses device stability and performance in environments with interference from other wireless signals, ensuring compliance with relevant standards.

.. only:: esp32c6 or esp32h2

    - :doc:`802.15.4 Non-Signaling Test </development_stage/rf_test_items/zigbee_non_signaling_test>`: This test directly controls the device to transmit specific signals without requiring a network connection. It evaluates key performance metrics such as transmit power, spectrum characteristics, and error rate, ensuring reliable communication quality in IoT applications.

So that your product can pass the following certifications:

- :doc:`CE Certification <rf_test_certification/ce_certification>`: A mandatory certification by the EU, confirming compliance with safety, health, and environmental protection standards.

- :doc:`FCC Certification <rf_test_certification/fcc_certification>`: A mandatory certification by the U.S. Federal Communications Commission, ensuring compliance with regulations on radio spectrum use, electromagnetic compatibility, and RF radiation.

- :doc:`SRRC Certification <rf_test_certification/srrc_certification>`: A mandatory certification for radio equipment in China, ensuring compliance with national radio management regulations to avoid electromagnetic interference.

.. only:: esp32

   .. list-table::
      :header-rows: 1

      * -
        - CE Certification
        - FCC Certification
        - SRRC Certification
      * - Wi-Fi Non-Signaling Test
        - Y
        - Y
        - Y
      * - Wi-Fi Adaptivity Test
        - Y
        - --
        - Y
      * - Wi-Fi Blocking Test
        - Y
        - --
        - --
      * - {IDF_TARGET_BT_BLE_OPTION} Non-Signaling Test
        - Y
        - Y
        - Y

.. only:: esp8266 or esp32s2

   .. list-table::
      :header-rows: 1

      * -
        - CE Certification
        - FCC Certification
        - SRRC Certification
      * - Wi-Fi Non-Signaling Test
        - Y
        - Y
        - Y
      * - Wi-Fi Adaptivity Test
        - Y
        - --
        - Y
      * - Wi-Fi Blocking Test
        - Y
        - --
        - --

.. only:: not esp8266 and not esp32 and not esp32s2 and not esp32c6 and not esp32h2

   .. list-table::
      :header-rows: 1

      * -
        - CE Certification
        - FCC Certification
        - SRRC Certification
      * - Wi-Fi Non-Signaling Test
        - Y
        - Y
        - Y
      * - Wi-Fi Adaptivity Test
        - Y
        - --
        - Y
      * - Wi-Fi Blocking Test
        - Y
        - --
        - --
      * - {IDF_TARGET_BT_BLE_OPTION} Non-Signaling Test
        - Y
        - Y
        - Y
      * - Bluetooth LE DTM Test
        - Y
        - --
        - --
      * - Bluetooth LE Adaptivity Test
        - Y
        - --
        - --
      * - Bluetooth LE Blocking Test
        - Y
        - --
        - --

.. only:: esp32c6

   .. list-table::
      :header-rows: 1

      * -
        - CE Certification
        - FCC Certification
        - SRRC Certification
      * - Wi-Fi Non-Signaling Test
        - Y
        - Y
        - Y
      * - Wi-Fi Adaptivity Test
        - Y
        - --
        - Y
      * - Wi-Fi Blocking Test
        - Y
        - --
        - --
      * - {IDF_TARGET_BT_BLE_OPTION} Non-Signaling Test
        - Y
        - Y
        - Y
      * - Bluetooth LE DTM Test
        - Y
        - --
        - --
      * - Bluetooth LE Adaptivity Test
        - Y
        - --
        - --
      * - Bluetooth LE Blocking Test
        - Y
        - --
        - --
      * - 802.15.4 Non-Signaling Test
        - Y
        - Y
        - Y

.. only:: esp32h2

   .. list-table::
      :header-rows: 1

      * -
        - CE Certification
        - FCC Certification
        - SRRC Certification
      * - {IDF_TARGET_BT_BLE_OPTION} Non-Signaling Test
        - Y
        - Y
        - Y
      * - Bluetooth LE DTM Test
        - Y
        - --
        - --
      * - Bluetooth LE Adaptivity Test
        - Y
        - --
        - --
      * - Bluetooth LE Blocking Test
        - Y
        - --
        - --
      * - 802.15.4 Non-Signaling Test
        - Y
        - Y
        - Y

.. only:: not esp32h2

    In addition to this, this repository also provides :doc:`WFA Certification and Testing Guide </development_stage/rf_test_items/wfa_certification_test>`.
