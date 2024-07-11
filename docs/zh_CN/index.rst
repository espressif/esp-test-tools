ESP 测试工具与指南
************************************

:link_to_translation:`en:[English]`

{IDF_TARGET_BT_BLE_OPTION: default="低功耗蓝牙", esp32="蓝牙及低功耗蓝牙"}

该仓库主要提供了用于产品研发阶段的射频测试工具、射频测试项目以及用于生产阶段的工具和产测指南。

针对研发阶段，该仓库主要提供了以下射频测试项目的测试工具、测试步骤和所需固件：

.. only:: not esp32h2

   - :doc:`Wi-Fi 非信令测试 </development_stage/rf_test_items/wifi_non_signaling_test>`
   - :doc:`Wi-Fi 信令测试 </development_stage/rf_test_items/wifi_signaling_test>`
   - :doc:`Wi-Fi 自适应测试 </development_stage/rf_test_items/wifi_adaptivity_test>`
   - :doc:`Wi-Fi 接收阻塞测试 </development_stage/rf_test_items/wifi_blocking_test>`

.. only:: not esp8266 and not esp32s2

   - :doc:`{IDF_TARGET_BT_BLE_OPTION}非信令测试 </development_stage/rf_test_items/bt_ble_non_signaling_test>`

.. only:: not esp8266 and not esp32 and not esp32s2

   - :doc:`低功耗蓝牙 DTM 测试 </development_stage/rf_test_items/ble_dtm_test>`
   - :doc:`低功耗蓝牙自适应测试 </development_stage/rf_test_items/ble_adaptivity_test>`
   - :doc:`低功耗蓝牙阻塞测试 </development_stage/rf_test_items/ble_blocking_test>`

.. only:: esp32c6 or esp32h2

    - :doc:`802.15.4 非信令测试 </development_stage/rf_test_items/zigbee_non_signaling_test>`

以便您的产品可以通过下列认证：

.. only:: esp32

   .. list-table::
      :header-rows: 1

      * -
        - CE 认证
        - FCC 认证
        - SRRC 认证
      * - Wi-Fi 非信令测试
        - Y
        - Y
        - Y
      * - Wi-Fi 自适应测试
        - Y
        - --
        - Y
      * - Wi-Fi 接收阻塞测试
        - Y
        - --
        - --
      * - {IDF_TARGET_BT_BLE_OPTION}非信令测试
        - Y
        - Y
        - Y

.. only:: esp8266 or esp32s2

   .. list-table::
      :header-rows: 1

      * -
        - CE 认证
        - FCC 认证
        - SRRC 认证
      * - Wi-Fi 非信令测试
        - Y
        - Y
        - Y
      * - Wi-Fi 自适应测试
        - Y
        - --
        - Y
      * - Wi-Fi 接收阻塞测试
        - Y
        - --
        - --

.. only:: not esp8266 and not esp32 and not esp32s2 and not esp32c6 and not esp32h2

   .. list-table::
      :header-rows: 1

      * -
        - CE 认证
        - FCC 认证
        - SRRC 认证
      * - Wi-Fi 非信令测试
        - Y
        - Y
        - Y
      * - Wi-Fi 自适应测试
        - Y
        - --
        - Y
      * - Wi-Fi 接收阻塞测试
        - Y
        - --
        - --
      * - {IDF_TARGET_BT_BLE_OPTION}非信令测试
        - Y
        - Y
        - Y
      * - 低功耗蓝牙 DTM 测试
        - Y
        - --
        - --
      * - 低功耗蓝牙自适应测试
        - Y
        - --
        - --
      * - 低功耗蓝牙阻塞测试
        - Y
        - --
        - --

.. only:: esp32c6

   .. list-table::
      :header-rows: 1

      * -
        - CE 认证
        - FCC 认证
        - SRRC 认证
      * - Wi-Fi 非信令测试
        - Y
        - Y
        - Y
      * - Wi-Fi 自适应测试
        - Y
        - --
        - Y
      * - Wi-Fi 接收阻塞测试
        - Y
        - --
        - --
      * - {IDF_TARGET_BT_BLE_OPTION}非信令测试
        - Y
        - Y
        - Y
      * - 低功耗蓝牙 DTM 测试
        - Y
        - --
        - --
      * - 低功耗蓝牙自适应测试
        - Y
        - --
        - --
      * - 低功耗蓝牙阻塞测试
        - Y
        - --
        - --
      * - 802.15.4 非信令测试
        - Y
        - Y
        - Y

.. only:: esp32h2

   .. list-table::
      :header-rows: 1

      * -
        - CE 认证
        - FCC 认证
        - SRRC 认证
      * - {IDF_TARGET_BT_BLE_OPTION}非信令测试
        - Y
        - Y
        - Y
      * - 低功耗蓝牙 DTM 测试
        - Y
        - --
        - --
      * - 低功耗蓝牙自适应测试
        - Y
        - --
        - --
      * - 低功耗蓝牙阻塞测试
        - Y
        - --
        - --
      * - 802.15.4 非信令测试
        - Y
        - Y
        - Y

.. only:: not esp32h2

    除此之外，本仓库还提供了 :doc:`WFA 认证与测试指南 </development_stage/rf_test_items/wfa_certification_test>`。

针对生产阶段，本仓库提供了如下工具：

- :doc:`Flash 下载工具 </production_stage/tools/flash_download_tool/index>`
- :doc:`乐鑫产测指南 </production_stage/tools/esp_production_testing_guide/index>`
- :doc:`Matter QR 二维码生成工具 </production_stage/tools/matter_qr_code_generator/index>`
- :doc:`模组冶具制作规范 </production_stage/instructions/test_fixture_mfg_inst>`

.. toctree::
   :hidden:

   快速入门 <get-started/index>

.. toctree::
   :hidden:
   :caption: 研发阶段

   RF 测试指南 <development_stage/rf_test_guide/rf_test_guide>
   RF 测试项目 <development_stage/rf_test_items/index>
   RF 测试认证 <development_stage/rf_test_certification/index>

.. toctree::
   :hidden:
   :caption: 生产阶段

   Flash 下载工具 <production_stage/tools/flash_download_tool/index>
   乐鑫产测指南 <production_stage/tools/esp_production_testing_guide/index>
   Matter QR 二维码生成工具 <production_stage/tools/matter_qr_code_generator/index>
   模组治具制作规范 <production_stage/instructions/test_fixture_mfg_inst>

.. toctree::
   :hidden:
   :caption: 其他

   FAQ <faq/index>
   相关文档和资源 <resources>
   免责声明和版权公告 <copyright>
