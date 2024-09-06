研发阶段
***************

:link_to_translation:`en:[English]`

{IDF_TARGET_BT_BLE_OPTION: default="低功耗蓝牙", esp32="蓝牙及低功耗蓝牙"}

针对研发阶段，该仓库主要提供了以下射频测试项目所需的测试工具、测试步骤和所需固件：

.. only:: not esp32h2

   - :doc:`Wi-Fi 非信令测试 <rf_test_items/wifi_non_signaling_test>`：该测试在不建立实际数据连接的情况下，直接控制设备发射特定信号，用于评估设备的射频性能，如发射功率、频谱质量和误码率等，以确保设备在各种环境中的无线通信质量。

   - :doc:`Wi-Fi 信令测试 <rf_test_items/wifi_signaling_test>`：该测试用于评估和验证无线网络设备 Wi-Fi 信令功能，主要用于确保设备在各种操作环境中能够稳定可靠地通信。Wi-Fi 信令测试通常用于设备的 OTA (Over-The-Air) 性能评估，包括 TRP（Total Radiated Power，总辐射功率）和 TIS（Total Isotropic Sensitivity，总各向同性灵敏度）测试。

   - :doc:`Wi-Fi 自适应测试 <rf_test_items/wifi_adaptivity_test>`：该测试模拟不同的网络条件和负载情况，测试设备在实时调整传输速率、信道和功率等参数时的响应能力，从而优化无线网络性能和稳定性。

   - :doc:`Wi-Fi 接收阻塞测试 <rf_test_items/wifi_blocking_test>`：该测试评估设备在强干扰信号环境下的接收性能，通过引入高强度的干扰信号，测试设备的接收灵敏度和抗干扰能力，以确保其在复杂无线环境中的可靠运行。

.. only:: not esp8266 and not esp32s2

   - :doc:`{IDF_TARGET_BT_BLE_OPTION}非信令测试 <rf_test_items/bt_ble_non_signaling_test>`：该测试控制设备发射特定信号，无需建立实际连接，用于评估其发射功率、频谱特性和误码率等关键性能指标，确保设备的无线通信质量。

.. only:: not esp8266 and not esp32 and not esp32s2

   - :doc:`低功耗蓝牙 DTM 测试 <rf_test_items/ble_dtm_test>`：该测试通过直接控制设备进入特定的发射或接收模式，评估低功耗蓝牙设备射频性能，如发射功率、接收灵敏度和频谱特性等。

   - :doc:`低功耗蓝牙自适应测试 <rf_test_items/ble_adaptivity_test>`：该测试确保设备以跳频方式工作且低功耗蓝牙信号的功率谱密度 (Power Spectral Density, PSD) 大于 10 dBm/MHz 时，满足一定的参数要求，从而避免对其他无线设备造成干扰。

   - :doc:`低功耗蓝牙阻塞测试 <rf_test_items/ble_blocking_test>`：该测试评估无线设备在存在其他无线信号干扰的环境中的性能和稳定性，以确保其符合相关标准。

.. only:: esp32c6 or esp32h2

    - :doc:`802.15.4 非信令测试 <rf_test_items/zigbee_non_signaling_test>`：该测试直接控制设备发射特定信号，无需建立网络连接。它评估发射功率、频谱特性和误码率等性能，以确保设备在物联网应用中的通信质量。

以便您的产品可以通过下列认证：

- :doc:`CE 认证 <rf_test_certification/ce_certification>`：欧盟的强制性认证，表明产品符合欧盟相关指令的基本要求，包括安全性、健康性和环境保护标准。

- :doc:`FCC 认证 <rf_test_certification/fcc_certification>`：美国联邦通信委员会的强制性认证，表明产品符合美国相关法规的要求，包括无线电频谱使用、电磁兼容性和射频辐射等。

- :doc:`SRRC 认证 <rf_test_certification/srrc_certification>`：中国针对无线电设备的强制性认证，确保产品符合国家无线电管理的相关法规和技术标准，以避免对电磁环境和其他无线电设备的干扰。

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

    除此之外，本仓库还提供了 :doc:`WFA 认证与测试指南 <rf_test_items/wfa_certification_test>`。
