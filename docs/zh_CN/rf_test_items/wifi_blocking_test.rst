Wi-Fi 阻塞测试
======================

本章介绍基于 ESP 芯片或模组的产品，在 CE 认证中的 Blocking 测试（接收阻塞测试）。Blocking 测试分为两部分：Wi-Fi Blocking 测试和蓝牙 Blocking 测试，蓝牙 Blocking 测试使用 BQB 来测试。由于 ESP32-S2 和 ESP8266 系列没有蓝牙功能，所以无需蓝牙 Blocking 测试。

Wi-Fi Blocking 测试
------------------------------

搭建环境
^^^^^^^^^^^^^^^^^

本测试的硬件环境与定频测试的相同，请参考 :ref:`环境搭建 <environment_setup>`。

Blocking 通常是传导信令测试，待测样机的 RF cable 线需要连接到认证实验室的测试设备，例如 CMW500。

运行固件
^^^^^^^^^^^^^^^^

- 下载完 bin 以后，待测样机 RF cable 线先连接到测试设备的同轴线。
- 打开 EspRFTestTool 工具，选择波特率：

  * ESP32、ESP32-S2、ESP32-C3：115200
  * ESP8266：74880

- 断开样机的 IO0，然后再拨动串口板电源开关重新上电。
- 对于工作在 Wi-Fi Station Mode 的样机，在下载时打开的 EspRFTestTool 中点击 WiFi Adaptivity，进去后点击左边的 STA，输入实验室测试设备 AP 的名称和密码，名称和密码尽量简单，点击 Connect AP，EspRFTestTool 状态栏会显示连接成功 log。连接成功后测试设备即可控制 DUT 进行接收测试。
- 对于工作在 Wi-Fi AP Mode 的样机，在下载时打开的 EspRFTestTool 中点击 WiFi Adaptivity，然后点击左边的 AP，输入待测样机 AP 的名称和密码，信道和模式后点击 create，然后认证实验室的 STA 会连接到此 AP 即可测试。