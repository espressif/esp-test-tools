ESP 测试工具与指南
************************************

:link_to_translation:`en:[English]`

为支持基于 `乐鑫芯片 <https://www.espressif.com/zh-hans/products/socs>`__ 和 `模组 <https://www.espressif.com/zh-hans/products/modules>`__ 的产品开发和生产，本仓库提供了丰富的资源。

在开发阶段，仓库提供了 RF 测试工具和详细的测试指南，确保您的产品符合必要的性能和认证标准。此外，在生产阶段，仓库还包含了相应的工具和指导，以简化生产流程，确保高效的测试、验证和质量控制。

=======================    =======================    =======================
|RF 测试指南|_               |RF 测试项目|_              |生产阶段工具|_
-----------------------    -----------------------    -----------------------
`RF 测试指南`_               `RF 测试项目`_              `生产阶段工具`_
=======================    =======================    =======================

.. |RF 测试指南| image:: ../_static/rf_test_guide_index.png
.. _RF 测试指南: development_stage/rf_test_guide/rf_test_guide.html

.. |RF 测试项目| image:: ../_static/rf_test_items_index.png
.. _RF 测试项目: development_stage/rf_test_items/index.html

.. |生产阶段工具| image:: ../_static/production_stage_index.png
.. _生产阶段工具: production_stage/index.html

.. toctree::
   :hidden:
   :caption: 研发阶段

   简介 <development_stage/index>
   RF 测试指南 <development_stage/rf_test_guide/rf_test_guide>
   RF 测试项目 <development_stage/rf_test_items/index>
   RF 测试认证 <development_stage/rf_test_certification/index>
   :esp32 or esp32c2 or esp32c3 or esp32c6 or esp32s3: WFA 认证与测试指南 <development_stage/wfa_certification_test/wfa_certification_test>

.. toctree::
   :hidden:
   :caption: 生产阶段

   简介 <production_stage/index>
   Flash 下载工具 <production_stage/tools/flash_download_tool>
   :not esp32h2: 乐鑫产测指南 <production_stage/tools/esp_production_testing_guide>
   模组治具制作规范 <production_stage/instructions/test_fixture_mfg_inst>
   :esp32 or esp32c2 or esp32c3 or esp32c6 or esp32s3 or esp32h2: Matter QR 二维码生成工具 <production_stage/tools/matter_qr_code_generator>

.. toctree::
   :hidden:
   :caption: 其他

   FAQ <faq/index>
   相关文档和资源 <resources>
   免责声明和版权公告 <copyright>
