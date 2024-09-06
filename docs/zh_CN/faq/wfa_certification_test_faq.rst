WFA 认证测试常见问题
=====================================

:link_to_translation:`en:[English]`

**1. 如何确定 USB 端口号**

  可以使用命令 ``ls /dev/ttyUSB*`` 查看

**2. 如何获取 DUT MAC 地址**

  - 进入 minicom: ``minicom -D /dev/ttyUSB*``
  - 输入命令 ``query``，打印出的 ``dut_mac`` 即为 ``DUT MAC``

**3. 如何烧录企业级证书**

  目前证书包含在固件中，无需烧入

**4. 工具无法启动**

  请检查 python 版本，以及工具是否完整

**5. 工具脚本启动后无法监听 UCC 命令**

  检查是否在 PC 上正确配置 IP 地址

**6. dut 出现乱码，无法正确读写**

  请检查 dut 是否正确烧录了 bin 文件，以及供电是否正常