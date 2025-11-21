Production Stage
****************

:link_to_translation:`zh_CN:[中文]`

For the production stage, this repository provides the following tools and resources designed to streamline the manufacturing process:

.. list::

    - :doc:`Flash Download Tool <tools/flash_download_tool>` is used to flash firmware onto flash. It supports multiple targets and configurations, enabling users to efficiently update firmware and debug devices.

    :not esp32h2: - :doc:`Espressif Production Testing Guide <tools/esp_production_testing_guide>` outlines the production testing schemes available for Espressif Wi-Fi products, thus providing reference for testing customer products during manufacturing.

    - :doc:`Test Fixture Manufacturing Instruction <instructions/test_fixture_mfg_inst>` provides guidelines for manufacturing test fixtures used with Espressif's Wi-Fi modules. These standardized fixtures help prevent issues that may arise during production and testing.

    :esp32 or esp32c2 or esp32c3 or esp32c5 or esp32c6 or esp32c61 or esp32s3 or esp32h2: - :doc:`Matter QR Code Generator <tools/matter_qr_code_generator>` is used to generate Matter device networking QR codes, allowing users to quickly add devices to the smart home network by scanning the QR code, simplifying the device configuration and connection process.
