ESP Test Tools and Guidelines
************************************

:link_to_translation:`zh_CN:[中文]`

{IDF_TARGET_BT_BLE_OPTION: default="Bluetooth LE", esp32="Bluetooth and Bluetooth LE"}

This repository mainly provides RF test tools, RF test items, and tools and production test guidelines for the product development stage.

For the development stage, this repository mainly provides test tools, test steps, and required firmware for the following RF test items:

.. only:: not esp32h2

   - :doc:`Wi-Fi Non-Signaling Test </development_stage/rf_test_items/wifi_non_signaling_test>`
   - :doc:`Wi-Fi Signaling Test </development_stage/rf_test_items/wifi_signaling_test>`
   - :doc:`Wi-Fi Adaptivity Test </development_stage/rf_test_items/wifi_adaptivity_test>`
   - :doc:`Wi-Fi Blocking Test </development_stage/rf_test_items/wifi_blocking_test>`

.. only:: not esp8266 and not esp32s2

   - :doc:`{IDF_TARGET_BT_BLE_OPTION} Non-Signaling Test </development_stage/rf_test_items/bt_ble_non_signaling_test>`

.. only:: not esp8266 and not esp32 and not esp32s2

   - :doc:`Bluetooth LE DTM Test </development_stage/rf_test_items/ble_dtm_test>`
   - :doc:`Bluetooth LE Adaptivity Test </development_stage/rf_test_items/ble_adaptivity_test>`
   - :doc:`Bluetooth LE Blocking Test </development_stage/rf_test_items/ble_blocking_test>`

.. only:: esp32c6 or esp32h2

    - :doc:`802.15.4 Non-Signaling Test </development_stage/rf_test_items/zigbee_non_signaling_test>`

So that your product can pass the following certifications:

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

For the production stage, this repository provides the following tools:

- :doc:`Flash Download Tool </production_stage/tools/flash_download_tool/index>`
- :doc:`Espressif Production Testing Guide </production_stage/tools/esp_production_testing_guide/index>`
- :doc:`Matter QR Code Generator </production_stage/tools/matter_qr_code_generator/index>`
- :doc:`Module Fixture Manufacturing Instructions </production_stage/instructions/test_fixture_mfg_inst>`

.. toctree::
   :hidden:

   Quick Start <get-started/index>

.. toctree::
   :hidden:
   :caption: Development Stage

   RF Testing Guide <development_stage/rf_test_guide/rf_test_guide>
   RF Testing Items <development_stage/rf_test_items/index>
   RF Testing Certification <development_stage/rf_test_certification/index>

.. toctree::
   :hidden:
   :caption: Production Stage

   Flash Download Tool <production_stage/tools/flash_download_tool/index>
   Espressif Production Testing Guide <production_stage/tools/esp_production_testing_guide/index>
   Matter QR Code Generator <production_stage/tools/matter_qr_code_generator/index>
   Module Fixture Manufacturing Instructions <production_stage/instructions/test_fixture_mfg_inst>

.. toctree::
   :hidden:
   :caption: Others

   FAQ <faq/index>
   Related Documents and Resources <resources>
   Disclaimer and Copyright Notice <copyright>
