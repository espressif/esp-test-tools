低功耗蓝牙自适应测试
=================================

:link_to_translation:`en:[English]`

低功耗蓝牙自适应测试确保设备以跳频方式工作且低功耗蓝牙信号的功率谱密度 (Power Spectral Density, PSD) 大于 10 dBm/MHz 时，满足一定的参数要求，从而避免对其他无线设备造成干扰。

.. note::

  - 如果设备的低功耗蓝牙信号 PSD 低于 10 dBm/MHz，可采用干扰缓解技术（等效占用率 ≤ 10%），这样就无需进行低功耗蓝牙自适应测试。
  - 如果设备的低功耗蓝牙信号 PSD 高于 10 dBm/MHz，可选择基于跳频的发射前搜寻机制 (Listen Before Talk, LBT) 进行低功耗蓝牙自适应测试。

搭建测试环境
---------------------------

.. figure:: ../../../_static/rf_test_tool/ble_adaptive_connection.png
    :align: center
    :scale: 80%

    测试环境连接示意图

- 在测试中，使用 {IDF_TARGET_NAME} 模组作为配测设备 (Slave)，与待测设备 (Master) 建立连接。Slave 与 Master 烧录相同的固件，使用串口指令区分。

- Test System 指自适应测试系统，Master 与 Slave 通过串口指令连接成功后即可开始测试。

.. note::

    - 待测设备的 CHIP_EN 管脚默认上拉，如果产品设计中未拉高，需要手动将 CHIP_EN 接到 3V3 管脚。
    - 部分串口通信板内部已交换 RXD 和 TXD, 无需反接，需根据实际情况调整接线。
    - {IDF_TARGET_NAME} 具有上电自校准功能，因此待测设备上电测试前需先将射频连接线连接至测试仪器。

烧录固件
------------------

{IDF_TARGET_BLE_ADAPTIVITY_FIRMWARE:default="未更新", esp32c2="`ESP32-C2 低功耗蓝牙自适应测试固件 <https://dl.espressif.com/rf/esp32c2/ESP32C2_BLE_Adaptivity_bin_20230704.bin>`_", esp32c3="`ESP32-C3 低功耗蓝牙自适应测试固件 <https://dl.espressif.com/rf/esp32c3/ESP32C3_BLE_Adaptivity_bin_20230704.bin>`_", esp32c6="`ESP32-C6 低功耗蓝牙自适应测试固件 <https://dl.espressif.com/rf/esp32c6/ESP32C6_BLE_Adaptivity_bin_20230704.bin>`_", esp32s3="`ESP32-S3 低功耗蓝牙自适应测试固件 <https://dl.espressif.com/rf/esp32s3/ESP32S3_BLE_Adaptivity_bin_20230704.bin>`_", esp32h2="`ESP32-H2 低功耗蓝牙自适应测试固件 <https://dl.espressif.com/rf/esp32h2/ESP32H2_BLE_Adaptivity_bin_20230704.bin>`_"}

1. 打开 :ref:`download-tool`。

2. 设置 ``ChipType``，``Com Port``，``Baud Rate``，点击 ``Open``，选择下载到 ``Flash``。

3. 将 {IDF_TARGET_BLE_ADAPTIVITY_FIRMWARE} 通过 ``UART`` 烧录至 ``0x0``。

.. figure:: ../../../_static/rf_test_tool/ble_adaptivity_firmware.png
    :align: center
    :scale: 80%

    烧录固件示意图

烧录完成后，继续以下步骤进行测试。

开始测试
---------------------------

低功耗蓝牙自适应测试需在 Mater 与 Slave 设备中输入相应串口指令建立连接后测试。

依次在 Slave 和 Master 设备输入相应指令：

1. **Slave 设备**

::

  //开启配测设备广播
  bleadve -C -z start -t 19 -u 13


2. **Master 设备**

::

  //建立连接，配置速率为 1 Mbps（如需配置为 2 Mbps，参数修改为 "-x 2 -y 2"），设置功率等级为 13
  bleconn -T -z start -x 1 -y 1 -n 1 -i 0x6-0x6 -v 13

  //配置功率，默认设置为 13（"-e" 后面的参数应与上一条指令 "-v" 后面的参数保持一致）
  ble -S -z etxp -t 4 -h 1 -e 13

  //设置 MTU
  gattc -C -m 512 -p 0x10 -r c0:11:11:11:11:11 -b 1

  //发送数据
  gattc -W -z char -p 0x10 -s 0xA002 -c 0xC317 -l 490 -n 0xFFFFFFFF -w 1 -r c0:11:11:11:11:11 -g 1 -b 1

3. **其他操作指令**

::

  //断开连接
  bleconn -D -z all

  //重启模组
  reboot

输入上述指令后，可继续进行低功耗蓝牙自适应测试。
