Production Stage
****************

:link_to_translation:`zh_CN:[中文]`

For the production stage, this repository provides the following tools:

- :doc:`Flash Download Tool <tools/flash_download_tool>` is used to flash firmware onto Espressif chips. It supports multiple targets and configurations, enabling users to efficiently update firmware and debug devices.

.. only:: not esp32h2

  - :doc:`Espressif Production Testing Guide <tools/esp_production_testing_guide>` outlines the production testing schemes available for Espressif Wi-Fi products, thus providing reference for testing customer products during manufacturing.

- :doc:`Test Fixture Manufacturing Instruction <instructions/test_fixture_mfg_inst>` provides guidelines for manufacturing test fixtures used with Espressif's Wi-Fi modules. These standardized fixtures help prevent issues that may arise during production and testing.

- :doc:`Matter QR Code Generator <tools/matter_qr_code_generator>` generates QR codes for Matter devices. It allows users to connect devices to their smart home network by simply scanning the code, simplifying the device setup and connection process.
