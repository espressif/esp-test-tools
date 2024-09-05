Wi-Fi 自适应测试
==============================

:link_to_translation:`en:[English]`

Wi-Fi 自适应测试用于评估 Wi-Fi 设备在干扰环境下的主动适应能力，主要用于 SRRC、CE 等认证。

.. note::

  如果 Wi-Fi 信号的功率谱密度 (Power Spectral Density, PSD) 高于 10 dBm/MHz，自适应测试应选择基于负载非跳频的发射前搜寻机制 (Listen Before Talk, LBT)。

.. include:: wifi_blocking_adaptivity_test_setup.inc

.. _wifi-adaptivity-test:

接下来可选择 `使用串口指令测试`_ 或者 `使用 EspRFTestTool 工具测试`_。

使用串口指令测试
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

在串口中依次输入以下指令进行配网与流量测试：

::

  \\设备配网
  \\配置样机进入 station 模式
  op -S -o 1

  \\连接 AP，SSID 为 CMW-AP，密码为 12345678
  sta -C -s CMW-AP -p 12345678

  \\流量测试
  \\清空 socket
  soc -T

  \\创建 UDP, 端口为 8080，默认 socket ID 为 54
  soc -B -t UDP -p 8080

  \\对 socket ID 为 54 的 AP 设备进行流量测试
  soc -S -s 54 -i 192.168.1.1 -p 8080 -l 2000 -n 200000000 -j 1

.. note::

    ``-p`` 参数用于设置 AP 密码。如果 AP 无密码，则无需使用该参数。

如果串口中打印以下类似信息，则表明流量测试已成功完成，可以开始进行 Wi-Fi 自适应测试。

.. figure:: ../../../_static/rf_test_tool/wifi_adptive_log.png
    :align: center
    :scale: 80%

    设备配网串口打印日志

使用 EspRFTestTool 工具测试
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- 打开 `EspRFTestTool 工具包 <https://dl.espressif.com/RF/EspRFTestTool_v3.6_Manual.zip>`_，配置 ``ChipType`` 与 ``COM``，波特率 ``BaudRate`` 选择 115200，打开端口后，选择 ``WiFi Adaptivity`` 测试界面。

- 在 ``STA`` 模式输入 ``AP ssid`` 和 ``AP pwd``, 点击 ``Connect AP`` 连接。

- 连接成功后应打印如下 log：

.. figure:: ../../../_static/rf_test_tool/wifi_adptive_connection.png
    :align: center
    :scale: 80%

    设备配网

- 连接成功后，将 ``Pakcet Num`` 设置为一个足够大的数值，例如 20000000，以满足较长流量测试时间。

- 将 ``Server PORT`` 设置为 8080，``Socket ID`` 设置为 54，将 ``Packet Delay`` 改为 1，以满足认证需求。

- 上述设置完成后，点击 ``Send Data``。如果 log 类似下图所示，则表示流量测试成功，可开始进行 Wi-Fi 自适应测试。

.. figure:: ../../../_static/rf_test_tool/wifi_adptive_senddata.png
    :align: center
    :scale: 80%

    Wi-Fi 自适应流量测试
