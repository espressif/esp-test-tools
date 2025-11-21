Development Stage
*****************

:link_to_translation:`zh_CN:[中文]`

{IDF_TARGET_BT_BLE_OPTION: default="Bluetooth LE", esp32="Bluetooth and Bluetooth LE"}

To ensure your product meets requirements for related `RF Certifications`_, this repository provides the testing tools and guidelines to facilitate RF testing, ensuring compliance with global standards and industry certifications.

RF Test Tool
============

:doc:`EspRFTestTool Toolkit <rf_test_guide/rf_test_guide>` is a comprehensive tool that allows you to control devices and evaluate key RF performance metrics. It supports the following `RF Test Items`_.

RF Test Items
=============

.. only:: not esp32h2

   Wi-Fi Test
   ----------

   - :doc:`Wi-Fi Non-Signaling Test <rf_test_items/wifi_non_signaling_test>` also known as fixed frequency test, directly controls the device to transmit specific signals without establishing a data connection. It evaluates key RF performance metrics, such as transmit power, spectrum quality, and error rate, ensuring wireless communication quality in various scenarios.

.. only:: not esp32h2 and not esp8266

   - :doc:`Wi-Fi Signaling Test </development_stage/rf_test_items/wifi_signaling_test>` assesses and verifies the Wi-Fi signaling functions of wireless network devices, focusing on stable and reliable communication across different operating scenarios. It evaluates the Over-The-Air (OTA) performance, including Total Radiated Power (TRP) and Total Isotropic Sensitivity (TIS).

.. only:: not esp32h2

   - :doc:`Wi-Fi Adaptivity Test </development_stage/rf_test_items/wifi_adaptivity_test>` simulates various network conditions and loads to access device's real-time adjustments in transmission rate, channel selection, and power levels, optimizing overall network performance and stability.

   - :doc:`Wi-Fi Blocking Test </development_stage/rf_test_items/wifi_blocking_test>` evaluates the device's reception performance in environments with strong interference. By introducing high-intensity interference signals, it measures reception sensitivity and anti-interference capability, ensuring reliable operation in complex wireless environments.

.. only:: not esp8266 and not esp32s2

   Bluetooth Test
   --------------

   - :doc:`{IDF_TARGET_BT_BLE_OPTION} Non-Signaling Test </development_stage/rf_test_items/bt_ble_non_signaling_test>` controls the device to transmit specific signals without establishing a connection, evaluating performance metrics such as transmit power, spectrum characteristics, and error rate to ensure communication quality.

.. only:: not esp8266 and not esp32s2

   - :doc:`Bluetooth LE DTM Test </development_stage/rf_test_items/ble_dtm_test>` evaluates the RF performance of Bluetooth LE devices by directly controlling the device to enter specific transmission or reception modes, accessing key metrics like transmit power, reception sensitivity, and spectrum characteristics.

   - :doc:`Bluetooth LE Blocking Test </development_stage/rf_test_items/ble_blocking_test>` assesses device stability and performance in environments with interference from other wireless signals, ensuring compliance with relevant standards.

.. only:: not esp8266 and not esp32 and not esp32s2

   - :doc:`Bluetooth LE Adaptivity Test </development_stage/rf_test_items/ble_adaptivity_test>` ensures the device meets performance criteria during frequency hopping, particularly when the Power Spectral Density (PSD) of the Bluetooth LE signal exceeds 10 dBm/MHz, avoiding interference with other wireless devices.

.. only:: esp32c6 or esp32h2

   802.15.4 Test
   -------------

   - :doc:`802.15.4 Non-Signaling Test </development_stage/rf_test_items/zigbee_non_signaling_test>` directly controls the device to transmit specific signals without requiring a network connection. It evaluates key performance metrics such as transmit power, spectrum characteristics, and error rate, ensuring reliable communication quality in IoT applications.

RF Certifications
=================

The `RF Test Items`_ outlined above are designed to ensure your product complies with the standards required for the following certifications:

- :doc:`CE Certification <rf_test_certification/ce_certification>`: A mandatory certification by the EU, confirming compliance with safety, health, and environmental protection standards.

- :doc:`FCC Certification <rf_test_certification/fcc_certification>`: A mandatory certification by the U.S. Federal Communications Commission, ensuring compliance with regulations on radio spectrum use, electromagnetic compatibility, and RF radiation.

- :doc:`SRRC Certification <rf_test_certification/srrc_certification>`: A mandatory certification for radio equipment in China, ensuring compliance with national radio management regulations to avoid electromagnetic interference.

Test items for each certification are listed in the following table.

.. only:: esp32

   .. list-table:: Test Items for RF Certifications
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

   .. list-table:: Test Items for RF Certifications
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

   .. list-table:: Test Items for RF Certifications
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

   .. list-table:: Test Items for RF Certifications
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

   .. list-table:: Test Items for RF Certifications
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

.. only:: not esp32h2 and not esp8266

   .. note::

      :doc:`Wi-Fi Signaling Test </development_stage/rf_test_items/wifi_signaling_test>` is not typically required for standard RF certifications; it is primarily used to evaluate the OTA performance of devices.

.. only:: esp32 or esp32c2 or esp32c3 or esp32c5 or esp32c6 or esp32c61 or esp32s3

   WFA Certification and Testing Guideline
   =======================================

   In addition, this repository also provides :doc:`WFA Certification and Testing Guide <wfa_certification_test/wfa_certification_test>`, which provides detailed information about the WFA certification process and testing requirements to help you pass the Wi-Fi Alliance certification.
