{IDF_TARGET_BT_BLE_OPTION: default="低功耗蓝牙", esp32="蓝牙及低功耗蓝牙"}

低功耗蓝牙 DTM 测试
===============================

:link_to_translation:`en:[English]`

低功耗蓝牙 DTM 测试通过直接控制设备进入特定的发射或接收模式，评估低功耗蓝牙设备射频性能，如发射功率、接收灵敏度和频谱特性等。

搭建测试环境
---------------------------

.. figure:: ../../../_static/rf_test_tool/dtm_uart_connection.png
    :align: center
    :scale: 60%

    测试环境示意图

- **电脑 (PC)** 通过 USB 与 USB-to-UART 转接板连接。电脑上需安装 EspRFTestTool 工具包、测试仪器控制软件、以及 USB-to-UART 转接板驱动。
- **测试仪器 (Tester)** 用于测试待测设备在不同模式下的射频性能。测试仪器通过射频连接线与待测设备连接传输射频信号，通常为 CMW500、CMW270、蓝牙测试仪 CBT 等。
- **USB-to-UART 转接板 (USB-to-UART Board)** 用于实现电脑和待测设备之间的通信以及综测仪和待测设备之间的通信。
- **待测设备 (DUT)** 为基于 {IDF_TARGET_NAME} 芯片或模组设计的产品。

.. note::

    - 待测设备的 CHIP_EN 管脚默认上拉，如果产品设计中未拉高，需要手动将 CHIP_EN 接到 3V3 管脚。
    - 部分串口通信板内部已交换 RXD 和 TXD, 无需反接，需根据实际情况调整接线。
    - {IDF_TARGET_NAME} 具有上电自校准功能，待测设备上电测试前需先将射频连接线连接至测试仪器。

传导测试
^^^^^^^^^^^^^^^^^^

- 对于没有板载 PCB 天线的模组，直接将射频连接线焊接至模组的天线馈电点即可（如上述示意图所示）。

- 对于带有板载 PCB 天线的模组，需将 PCB 天线馈电点后的天线割断，焊接射频连接线，并使射频线的屏蔽金属层充分焊锡后接入模组 GND。GND 焊接点可选择屏蔽盖或 PCB 板材上去除绿油层的 GND 层，且尽量靠近馈电点。

.. figure:: ../../../_static/rf_test_tool/pcb_antenna_conducted_test.png
    :align: center
    :scale: 70%

    带有板载 PCB 天线的模组焊接射频连接线示意图

烧录固件
------------------

{IDF_TARGET_BLE_DTM_FIRMWARE:default="联系乐鑫获取最新固件", esp32="|ESP32 低功耗蓝牙 DTM 测试固件|", esp32c2="|ESP32-C2 低功耗蓝牙 DTM 测试固件 (26 MHz) or ESP32-C2 低功耗蓝牙 DTM 测试固件 (40 MHz)|", esp32c3="|ESP32-C3 低功耗蓝牙 DTM 测试固件|", esp32c6="|ESP32-C6 低功耗蓝牙 DTM 测试固件|", esp32s3="|ESP32-S3 低功耗蓝牙 DTM 测试固件|", esp32h2="|ESP32-H2 低功耗蓝牙 DTM 测试固件|"}

1. 打开 :ref:`download-tool`。

2. 设置 ``ChipType``，``Com Port``，``Baud Rate``，点击 ``Open``，选择下载到 ``Flash``。

3. 将 {IDF_TARGET_BLE_DTM_FIRMWARE} bin 文件通过 ``UART`` 烧录至以下地址。

.. only:: esp32

    .. list-table::
      :header-rows: 1
      :align: center

      * - bin 文件
        - 烧录地址
      * - {IDF_TARGET_BLE_DTM_FIRMWARE}
        - 0x1000

.. only:: not esp32

    .. list-table::
      :header-rows: 1
      :align: center

      * - bin 文件
        - 烧录地址
      * - {IDF_TARGET_BLE_DTM_FIRMWARE}
        - 0x0


.. only:: esp32

    .. figure:: ../../../_static/rf_test_tool/ble_dtm_firmware_esp32.png
        :align: center
        :scale: 80%

        烧录固件示意图

.. only:: not esp32

    .. figure:: ../../../_static/rf_test_tool/ble_dtm_firmware_others.png
        :align: center
        :scale: 80%

        烧录固件示意图

烧录完成后，拉高或悬空 boot 管脚，芯片重启后进入工作模式，继续以下步骤进行测试。

开始测试
---------------------------

待测设备与测试仪器的连接方式有 HCI 和 2-wire 两种，默认使用 HCI 方式。

依照上述硬件连接方式，可通过 UART0 串口打印信息确认固件烧录成功；

.. only:: esp32

    上电默认以 Power 6 dBm、无流控、波特率 115200 完成初始化过程，无需输入指令，可直接开始 DTM 测试；

.. only:: not esp32

    上电默认以 Power 12 dBm，无流控，波特率 115200 完成初始化过程，无需输入指令，可直接开始 DTM 测试；

    如需调整 UART1 的相关设置，可通过 UART0 端输入相应的指令实时调整：

    ::

        //配置 TX 输出功率，支持 0~15 档功率调整
        set_ble_tx_power -i 15

        //获取当前 BLE 的配置功率
        get_ble_tx_power

        //配置 UART1，将 TX 管脚设置为 GPIO4，将 RX 管脚设置为 GPIO5
        reconfig_dtm_uart_pin -t 4 -r 5

.. |ESP32 低功耗蓝牙 DTM 测试固件| replace:: `ESP32 低功耗蓝牙 DTM 测试固件 <https://dl.espressif.com/RF/ESP32_BLE_DTM_HCI_02e0d70_20250325.bin>`__
.. |ESP32-C2 低功耗蓝牙 DTM 测试固件 (26 MHz) or ESP32-C2 低功耗蓝牙 DTM 测试固件 (40 MHz)| replace:: `ESP32-C2 低功耗蓝牙 DTM 测试固件 (26 MHz) <https://dl.espressif.com/RF/ESP32C2_DTM_HCI_1babaa3_26M_20250319.bin>`__ or `ESP32-C2 低功耗蓝牙 DTM 测试固件 (40 MHz) <https://dl.espressif.com/RF/ESP32C2_DTM_HCI_1babaa3_40M_20250319.bin>`__
.. |ESP32-C3 低功耗蓝牙 DTM 测试固件| replace:: `ESP32-C3 低功耗蓝牙 DTM 测试固件 <https://dl.espressif.com/RF/ESP32C3_DTM_HCI_01f2a49_20250319.bin>`__
.. |ESP32-C6 低功耗蓝牙 DTM 测试固件| replace:: `ESP32-C6 低功耗蓝牙 DTM 测试固件 <https://dl.espressif.com/RF/ESP32C6_ECO1_DTM_HCI_5b89037_20250319.bin>`__
.. |ESP32-S3 低功耗蓝牙 DTM 测试固件| replace:: `ESP32-S3 低功耗蓝牙 DTM 测试固件 <https://dl.espressif.com/RF/ESP32S3_DTM_HCI_a6008b2_20250319.bin>`__
.. |ESP32-H2 低功耗蓝牙 DTM 测试固件| replace:: `ESP32-H2 低功耗蓝牙 DTM 测试固件 <https://dl.espressif.com/RF/ESP32H2_DTM_HCI_823e7f8_20250319.bin>`__



附录
----------------

本附录主要用于说明 {IDF_TARGET_NAME} 的功率等级及对应的目标功率，用于射频调试或测试对照。

.. only:: esp32

  .. list-table:: {IDF_TARGET_NAME} 蓝牙/低功耗蓝牙发射功率等级
    :widths: 40 60

    * - 功率等级
      - ESP32 蓝牙/低功耗蓝牙发射功率 (dBm)
    * - 0
      - -12
    * - 1
      - -9
    * - 2
      - -6
    * - 3
      - -3
    * - 4
      - 0
    * - 5
      - 3
    * - 6
      - 6
    * - 7
      - 9

.. only:: esp32c2 or esp32c3 or esp32s3 or esp32h2

    低功耗蓝牙发射功率等级
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. list-table:: {IDF_TARGET_NAME} 低功耗蓝牙发射功率等级
        :widths: 40 60

        * - 功率等级
          - 低功耗蓝牙发射功率 (dBm)
        * - 0
          - -24
        * - 1
          - -21
        * - 2
          - -18
        * - 3
          - -15
        * - 4
          - -12
        * - 5
          - -9
        * - 6
          - -6
        * - 7
          - -3
        * - 8
          - 0
        * - 9
          - 3
        * - 10
          - 6
        * - 11
          - 9
        * - 12
          - 12
        * - 13
          - 15
        * - 14
          - 18
        * - 15
          - 20



.. only:: esp32c6 or esp32c61 or esp32c5

    低功耗蓝牙发射功率等级
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    下表主要用于说明 {IDF_TARGET_NAME} 的 {IDF_TARGET_BT_BLE_OPTION} 的功率等级及对应的目标功率，用于射频调试或测试对照。

    .. list-table:: {IDF_TARGET_NAME} 低功耗蓝牙发射功率等级
        :widths: 40 60

        * - 功率等级
          - 低功耗蓝牙发射功率 (dBm)
        * - 0
          - -15
        * - 1
          - -15
        * - 2
          - -15
        * - 3
          - -15
        * - 4
          - -12
        * - 5
          - -9
        * - 6
          - -6
        * - 7
          - -3
        * - 8
          - 0
        * - 9
          - 3
        * - 10
          - 6
        * - 11
          - 9
        * - 12
          - 12
        * - 13
          - 15
        * - 14
          - 18
        * - 15
          - 20