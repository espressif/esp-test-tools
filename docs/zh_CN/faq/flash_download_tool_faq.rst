Flash 下载工具
=============================

:link_to_translation:`en:[English]`

**1. 打开工具后，在 COM 下拉菜单中找不到对应串口？**

首先查看设备管理器，确认串口已经安装成功。若没有成功，检查驱动是否有问题。

**2. “连接串口失败”，如下图所示：**

.. figure:: ../../_static/flash_download_tool/serial_port_connection_failure.jpg
    :align: center
    :scale: 90%

    串口连接失败

- 确认选择的 COM 口是否为需要下载的 COM 口
- 检查串口是否被其他线程占用

**3. 工具一直停留在以下界面，该怎么解决？**

.. figure:: ../../_static/flash_download_tool/download_panel.jpg
    :align: center
    :scale: 90%

    下载界面

工具停留在同步过程中可能有以下几种原因：

- 硬件原因：设备没有处于下载模式
- 软件原因：待下载的设备选择错误

**4. 点击 START 后出现以下问题，是什么原因？**

.. figure:: ../../_static/flash_download_tool/efuse_error.jpg
    :align: center
    :scale: 100%

    eFuse 错误

若下载命令行框中出现 ``ESP8266 Chip efuse check error esp_check_mac_and_efuse``，代表设备的 eFuse 出现错误，可能有以下原因：

- 设备的 eFuse 没有问题，待下载设备选择有误。此时，请重新选择待下载设备。
- 设备的 eFuse 确有错误。此时，请联系乐鑫获取 esptool.exe 以及操作指令，并将 eFuse 读出后交由乐鑫进行调试。

**5. 下载过程出现错误，什么原因？**

出现下载问题，请首先确认：

- 设备的 TX/RX 没有与其他软件复用
- 设备实际的 flash 不小于固件的大小
- 若出现 MD5 校验错误，请首先擦除整片 flash，然后尝试再次下载

**6. 固件下载完成后，重新上电 crash。**

请首先确认烧录的固件本身没有问题，而后确认以下方面：

- 待下载设备的选择是否正确
- Flash 启动模式的配置是否正确
- Flash 下载模式的选择是否正确
