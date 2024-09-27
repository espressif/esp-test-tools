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

- **电脑 (PC)** 通过 USB 与 USB-to-UART 转接板连接。电脑上需安装 `EspRFTestTool 工具包 <https://dl.espressif.com/RF/EspRFTestTool_v3.6_Manual.zip>`_、测试仪器控制软件、以及 USB-to-UART 转接板驱动。
- **测试仪器 (Tester)** 用于测试待测设备在不同模式下的射频性能。测试仪器通过射频连接线与待测设备连接传输射频信号，通常为 CMW500、CMW270、蓝牙测试仪 CBT 等。
- **USB-to-UART 转接板 (USB-to-UART Board)** 用于实现电脑和待测设备之间的通信以及综测仪和待测设备之间的通信。
- **待测设备 (DUT)** 为基于 {IDF_TARGET_NAME} 芯片或模组设计的产品。

.. note::

    - 待测设备的 CHIP_EN 管脚默认上拉，如果产品设计中未拉高，需要手动将 CHIP_EN 接到 3V3 管脚。
    - 部分串口通信板内部已交换 RXD 和 TXD, 无需反接，需根据实际情况调整接线。
    - {IDF_TARGET_NAME} 具有上电自校准功能，因此待测设备上电测试前需先将射频连接线连接至测试仪器。

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

{IDF_TARGET_BLE_DTM_FIRMWARE:default="未更新", esp32c2="`ESP32-C2 低功耗蓝牙 DTM 测试固件 <https://dl.espressif.com/rf/esp32c2/ESP32C2_DTM_HCI_CMD_26M_20230301.zip>`_", esp32c3="`ESP32-C3 低功耗蓝牙 DTM 测试固件 <https://dl.espressif.com/rf/esp32c3/ESP32C3_DTM_HCI_20230724.zip>`_", esp32c6="`ESP32-C6 低功耗蓝牙 DTM 测试固件 <https://dl.espressif.com/rf/esp32c6/ESP32C6-ECO1_DTM_HCI_d1caf30_20230407.zip>`_", esp32s3="`ESP32-S3 低功耗蓝牙 DTM 测试固件 <https://dl.espressif.com/rf/esp32s3/ESP32S3_BLE_HCI_cb74f83_20220518.zip>`_", esp32h2="`ESP32-H2 低功耗蓝牙 DTM 测试固件 <https://dl.espressif.com/rf/esp32h2/ESP32H2_BLE_DTM_Bin_20230811.bin>`_"}

1. 打开 :ref:`download-tool`。

2. 设置 ``ChipType``，``Com Port``，``Baud Rate``，点击 ``Open``，选择下载到 ``Flash``。

3. {IDF_TARGET_BLE_DTM_FIRMWARE} 包括 **bootloader.bin**， **partition-table.bin** 与 **ssc.bin** 3 个 bin 文件。将 {IDF_TARGET_BLE_DTM_FIRMWARE} 解压后，分别将 3 个 bin 文件通过 ``UART`` 烧录至以下地址。

.. list-table::
   :header-rows: 1

   * - bin 文件
     - 烧录地址
   * - bootloader.bin
     - 0x0
   * - partition-table.bin
     - 0x8000
   * - ssc.bin
     - 0x10000

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

烧录完成后，继续以下步骤进行测试。

开始测试
---------------------------

待测设备与测试仪器的连接方式有 HCI 和 2-wire 两种，默认使用 HCI 方式。

依照上述硬件连接方式，可通过 UART0 串口打印信息确认固件烧录成功；

上电默认以 Power 12 dBm，无流控，波特率 115200 完成初始化过程，无需输入指令，可直接开始 DTM 测试；

如需调整 UART1 的相关设置，可通过 UART0 端输入相应的指令实时调整：

::

    //配置 UART1，将 TX 管脚设置为 GPIO4，将 RX 管脚设置为 GPIO5
    bqb -z reconfig_uart1_pin -t 4 -r 5

    //配置 TX 输出功率，支持 0~15 档功率调整
    bqb -z set_ble_tx_power -i 15

    //配置流控关闭，波特率设置为 115200
    bqb -z set_uart_param -f 0 -b 115200
