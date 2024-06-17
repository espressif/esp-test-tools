ESP Test Tools and Guide
************************

:link_to_translation:`zh_CN:[中文]`

This repository provides RF test tools and test steps for the development stage, as well as tools and instructions for the production stage.

For the development stage, this repository mainly provides the test tool, test steps, and required firmware for the following RF test items:

.. only:: not esp32h2

   - :doc:`Wi-Fi Non-Signaling Test </development_stage/rf_test_items/wifi_non_signaling_test>`
   - :doc:`Wi-Fi Signaling Test </development_stage/rf_test_items/wifi_signaling_test>`
   - :doc:`Wi-Fi Adaptivity Test </development_stage/rf_test_items/wifi_adaptivity_test>`
   - :doc:`Wi-Fi Blocking Test </development_stage/rf_test_items/wifi_blocking_test>`

.. only:: not esp8266 and not esp32s2

   - :doc:`Bluetooth/Bluetooth LE Non-Signaling Test </development_stage/rf_test_items/bt_ble_non_signaling_test>`

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
      * - Bluetooth/Bluetooth LE Non-Signaling Test
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
      * - Bluetooth/Bluetooth LE Non-Signaling Test
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
      * - Bluetooth/Bluetooth LE Non-Signaling Test
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
      * - Bluetooth/Bluetooth LE Non-Signaling Test
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
- :doc:`Test Fixture Manufacturing Instructions </production_stage/instructions/test_fixture_mfg_inst>`

.. toctree::
   :hidden:

   Get-Started <get-started/index>

.. toctree::
   :hidden:
   :caption: Development

   RF Test Guide <development_stage/rf_test_guide/index>
   RF Test Items <development_stage/rf_test_items/index>
   RF Test Certification <development_stage/rf_test_certification/index>

.. toctree::
   :hidden:
   :caption: Production

   Flash Download Tool <production_stage/tools/flash_download_tool/index>
   Espressif Production Testing Guide <production_stage/tools/esp_production_testing_guide/index>
   Matter QR Code Generator <production_stage/tools/matter_qr_code_generator/index>
   Test Fixture Manufacturing Instruction <production_stage/instructions/test_fixture_mfg_inst>

.. toctree::
   :hidden:
   :caption: Others

   FAQ <faq/index>
   Related Documentation <resources>
   Disclaimer and Copyright <copyright>