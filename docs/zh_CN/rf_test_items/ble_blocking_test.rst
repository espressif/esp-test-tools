低功耗蓝牙 Blocking 测试
======================================

本节介绍使用 BQB 测试蓝牙 Blocking。

搭建环境
^^^^^^^^^^^^^^

蓝牙 Blocking 测试需要用到两个串口板，DUT 部分的硬件环境连接见图 11。TXD0 和 RXD0 连接 ESP 模组的 TXD0 和 RXD0 引脚，TXD1 和 RXD1 连接 ESP 模组的 IO5 和 IO18 引脚。RF cable 线接到 ESP 模组 RF 匹配后面，如果 RF 后面同时连接 PCB 天线，则需要断开 PCB 天线。

.. figure:: ../../_static/rf_test_tool/bt_blocking_test_setup.jpg
    :align: center
    :scale: 90%

    蓝牙 Blocking 测试环境搭建

.. note::

    UART 配置说明：用户可以通过 UART0 输入命令配置 UART1 所使用的引脚，而不使用默认引脚（即 IO5、IO18、IO19、IO23）。
    例如，将 IO21、IO22、IO19 和 IO5 用于 UART1 的 TXD、RXD、RTS、CTS 引脚，则需要进行如下设置：

    - 将 IO21 连接到 USB 串口 RXD
    - 将 IO22 连接到 USB 串口 TXD
    - 将 IO19 连接到 USB 串口 CTS
    - 将 IO5 连接到 USB 串口 RTS

    上电后，通过 UART0 输入以下命令： ``bqb -z set_uart_pin -t 21 -r 22 -q 19 -c 5``

    详情可参考 BQB 文件夹下 BQB_test_tool_user_guide.pdf。

运行固件
^^^^^^^^^^^^^^

运行经典蓝牙 Blocking 测试固件
""""""""""""""""""""""""""""""""""""""""""""""

- 下载完 bin 以后，待测样机 RF cable 线先连接到测试设备的同轴线。
- ESP 的 IO0 断开。
- PC 端打开串口工具，COM 号选择 ESP 的串口板 1 对应的 COM，波特率 115200，以友善串口工具为例，如图 12 所示。
- 重新上电 ESP 模组。
- 在串口工具输入以下命令：

  .. code:: bash

    bqb -z set_ble_tx_power -i 4         //设置 Bluetooth LE TX power, i 的范围：[0~7]。

    bqb -z set_power_class -i 3 -a 4     //设置 Classic Power Class, i[Min_powe_level_index], range[0~7], a[Max_power_level_index], range[0~7]

    bqb -z set_pll_track -e 0            //关掉 PLL track 功能

    bqb -z init                          //初始化 Bluetooth controller dual mode

.. figure:: ../../_static/rf_test_tool/uart_serial_config.jpg
    :align: center
    :scale: 120%

    UART0 串口设置

- 设置 UART1，在 /tools/HCI_host/config/dev0.conf 中将 UART_PORT 改为串口板 2 对应的 com 值。
- 在 /tools/HCI_host/ 打开 tinyBH.exe，在 tinyBH.exe 输入下述指令，正常 log 见图 13。

  .. code:: bash

    hci reset                 //初始化所有的蓝牙 controller
    hci set_evt_mask          //设置 legacy event mask
    hci set_name ESPRESSIF    //设置待测物的名称
    hci dut                   //使蓝牙进入 Under test mode
    hci ipscan                //使蓝牙进入 scan 状态

- 这时可以搜到蓝牙 ESPRESSIF，连上信令测试仪器进行经典蓝牙 Blocking 测试。

.. figure:: ../../_static/rf_test_tool/uart_log.jpg
    :align: center
    :scale: 120%

    UART1 运行 log

运行 Bluetooth LE Blocking 测试固件
""""""""""""""""""""""""""""""""""""""""""""""""

LE Blocking 测试可以参考经典蓝牙部分，测试中只需要经典蓝牙测试步骤的前 5 步，然后将串口板 2 的 USB 线连接到测试设备，例如 CMW500，将测试设备 CMW500 设置成 LE 模式，连接成功即可信令测试。