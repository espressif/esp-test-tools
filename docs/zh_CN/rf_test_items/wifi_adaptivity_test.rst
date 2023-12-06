Wi-Fi 自适应测试
===========================

本章介绍基于 ESP 芯片或模组的产品在 CE 认证中的 Adaptivity 测试（自适应测试）。

搭建环境
----------------

本测试的硬件环境与定频测试的相同，请参考 :ref:`环境搭建 <environment_setup>`。

运行固件
-----------------

- 下载完 bin 以后，待测样机 RF cable 线先连接到测试设备的同轴线。
- EspRFTestTool 的波特率选择 115200。
- 断开样机的 IO0，然后再拨动串口板电源开关重新上电。
- 对于工作在 Wi-Fi Station Mode 的样机，在下载时打开的 EspRFTestTool 中点击 WiFi Adaptivity，进去后点击左边的 STA，输入实验室 AP 的名称和密码，名称和密码尽量简单，点击 Connect AP，EspRFTestTool 状态栏会显示连接 log。连接成功后，将 packet num 改成 900000 以便长时间跑流，将 packet delay 改成 1，选择芯片对应的 socket ID，然后点击 Send Data 即可认证测试，图 9 为 ESP32 的自适应测试界面，图 10 为 ESP32-C3 自适应测试界面。

  * ESP32、ESP32-S2、ESP32-C3 的 socket ID：54
  * ESP8266 的 socket ID：0

- 对于工作在 Wi-Fi AP Mode 的样机，在下载时打开的 EspRFTestTool 中点击 WiFi Adaptivity，然后点击左边的 AP，输入待测样机 AP 的名称和密码、信道和模式后点击 create，然后认证实验室的 STA 会连接到刚创建的 AP。接成功后跑流设置和上述 Wi-Fi Station Mode 相同。

.. figure:: ../../_static/rf_test_tool/esp32_adaptive_test.png
    :align: center

    ESP32 自适应测试界面

.. figure:: ../../_static/rf_test_tool/esp32c3_adaptive_test.jpg
    :align: center
    :scale: 120%

    ESP32-C3 自适应测试界面

