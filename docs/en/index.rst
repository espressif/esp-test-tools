ESP Test Tools and Guidelines
************************************

:link_to_translation:`zh_CN:[中文]`

This repository provides comprehensive resources to support the development and production of products based on `Espressif chips <https://www.espressif.com/en/products/socs>`__ and `modules <https://www.espressif.com/en/products/modules>`__.

For the development stage, it provides an RF testing tool and detailed test guidelines to ensure your product meets the necessary performance and certification standards. Additionally, for the production stage, the repository includes essential tools and instructions to streamline the manufacturing process, ensuring efficient testing, validation, and quality control of your products.

=========================    =========================    =========================
   |RF Test Guide|_              |RF Test Items|_         |Production-stage Tools|_
-------------------------    -------------------------    -------------------------
   `RF Test Guide`_              `RF Test Items`_         `Production-stage Tools`_
=========================    =========================    =========================

.. |RF Test Guide| image:: ../_static/rf_test_guide_index.png
.. _RF Test Guide: development_stage/rf_test_guide/rf_test_guide.html

.. |RF Test Items| image:: ../_static/rf_test_items_index.png
.. _RF Test Items: development_stage/rf_test_items/index.html

.. |Production-stage Tools| image:: ../_static/production_stage_index.png
.. _Production-stage Tools: production_stage/index.html

.. toctree::
   :hidden:
   :caption: Development Stage

   Introduction <development_stage/index>
   RF Test Guide <development_stage/rf_test_guide/rf_test_guide>
   RF Test Items <development_stage/rf_test_items/index>
   RF Test Certification <development_stage/rf_test_certification/index>
   :esp32 or esp32c2 or esp32c3 or esp32c6 or esp32s3: WFA Certification and Testing Guide <development_stage/wfa_certification_test/wfa_certification_test>

.. toctree::
   :hidden:
   :caption: Production Stage

   Introduction <production_stage/index>
   Flash Download Tool <production_stage/tools/flash_download_tool>
   :not esp32h2: Espressif Production Testing Guide <production_stage/tools/esp_production_testing_guide>
   Module Fixture Manufacturing Instructions <production_stage/instructions/test_fixture_mfg_inst>
   :esp32 or esp32c2 or esp32c3 or esp32c6 or esp32s3 or esp32h2: Matter QR Code Generator <production_stage/tools/matter_qr_code_generator>

.. toctree::
   :hidden:
   :caption: Others

   FAQ <faq/index>
   Related Documents and Resources <resources>
   Disclaimer and Copyright Notice <copyright>
