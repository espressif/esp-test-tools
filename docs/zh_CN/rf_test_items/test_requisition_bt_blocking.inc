.. test-requisition

硬件
^^^^^^^^

需准备的硬件有三种，分别是待测样机、串口板和 USB 线，硬件说明如下表所示。

.. list-table:: 硬件说明
  :widths: 20 40 10 30

  * - 名称
    - 图片
    - 数量
    - 描述
  * - 待测样机
    - N/A
    - 6
    - 基于 ESP 芯片或模组设计的产品
  * - 串口板
    - .. figure:: ../../_static/rf_test_tool/serial_board.jpg
    - 2
    - 连接 PC 的 USB 线和待测样机接出来的杜邦线，用于 USB-UART 转换，使 PC 端和待测样机通信
  * - USB 线
    - .. figure:: ../../_static/rf_test_tool/usb_cable.jpg
    - 2
    - 连接 PC 和串口板

软件
^^^^^^^^

.. list-table:: 软件说明
    :header-rows: 1
    :widths: 40 60
    :align: left

    * - 名称
      - 描述
    * - ESP_RF_test_tool.zip
      - 该压缩包包含了测试 bin，用于下载和运行测试 bin 的工具
    * - BQB
      - 用于蓝牙 Blocking 测试
