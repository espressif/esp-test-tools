Wi-Fi 接收阻塞测试
==============================

:link_to_translation:`en:[English]`

Wi-Fi 接收阻塞测试评估设备在强干扰信号环境下的接收性能，通过引入高强度的干扰信号，测试设备的接收灵敏度和抗干扰能力，以确保其在复杂无线环境中的可靠运行。

.. include:: wifi_blocking_adaptivity_test_setup.inc

使用串口指令测试
^^^^^^^^^^^^^^^^^^^^^

在串口中依次输入以下指令以进行配网：

::

  //设备配网
  //配置样机进入 station 模式
  op -S -o 1

  //连接 AP，SSID 为 CMW-AP，密码为 12345678
  sta -C -s CMW-AP -p 12345678

.. note::

    - ``-p`` 参数用于设置 AP 密码。如果 AP 无密码，则无需使用该参数。

串口中打印如下信息，表明连接成功，可进行 Wi-Fi 接收阻塞测试。

.. figure:: ../../../_static/rf_test_tool/wifi_blocking_log.png
    :align: center
    :scale: 80%

    设备配网串口打印日志

使用 ESPRFTestTool 工具测试
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- 打开 `EspRFTestTool 工具包 <https://dl.espressif.com/RF/EspRFTestTool_v3.6_Manual.zip>`_，配置 ``ChipType`` 与 ``COM``，波特率选择 115200，打开端口后，选择 ``WiFi Adaptivity`` 测试界面。

- 在 ``STA`` 模式输入 ``AP ssid`` 和 ``AP pwd``, 点击 ``Connect AP`` 连接。

- 如果打印类似如下 log，则表明配网成功：

.. figure:: ../../../_static/rf_test_tool/wifi_adptive_connection.png
    :align: center
    :scale: 80%

    设备配网

配网成功后即可开始 Wi-Fi 接收阻塞测试。
