Matter 二维码生成工具
============================================

:link_to_translation:`en:[English]`

**Matter 二维码生成工具** 能够生成、配置和打印二维码，这些二维码用于乐鑫 Matter 设备的配网。该工具集成 BarTender 软件以设计和打印标签。通过 Matter 二维码生成工具，用户可灵活配置标签模板、打印机选择和数据源，满足多种场景的二维码生成和打印需求。同时，该工具支持在局域网环境下与镭雕机适配以便于集成。

**下载地址**：:download:`Matter 二维码生成工具 <https://dl.espressif.com/public/esp_matter_printer.zip>`

软件目录结构
--------------

Matter 二维码生成工具的目录结构如下：

- ``bartender``：存放调用库依赖文件
- ``configure``：存放工具配置文件
- ``data_output``：存放数据输出临时文件
- ``data_source``：存放本地打印时的数据文件
- ``files``：存放打印模板文件及扫描板固件
- ``esp_printer_main.exe``：主程序

.. figure:: ../../../_static/qr_tool/dir.png
    :align: center
    :scale: 70%

    工具主界面（点击放大）


准备工作
--------------

安装 BarTender
^^^^^^^^^^^^^^

BarTender 是乐鑫 Matter 二维码生成工具的中间件。目前，Matter 二维码生成工具仅支持 `BarTender <https://www.seagullscientific.com/cn/software/>`__ 2022 和 2016 64 位版本。安装时，注意选择默认路径，模块仅选择 BarTender Designer 即可。

.. figure:: ../../../_static/qr_tool/bar_1.png
    :align: center
    :scale: 60%

    模块选择（点击放大）

具体安装流程参考 `附录二：BarTender (2022) 安装示例`_。

编辑标签模板
^^^^^^^^^^^^^^

标签模板用于定义打印出的标签内容及格式，使用 BarTender 软件编辑。乐鑫 Matter 二维码生成工具使用的默认标签模板参见 `\\files\\matter` 目录。如需更改默认模板的字体、标签尺寸、标签布局，可自行编辑模板。

注意：

* 不可更改模板文件名。
* 未和数据源绑定的元素，例如图片，方框等，可随意增删。
* 不可增删具名数据源。

.. figure:: ../../../_static/qr_tool/bar_val.png
    :align: center
    :scale: 70%

    模板内具名数据源（点击放大）

* 打印界面中的示例仅为静态图像，你的更改不会显示在界面上。

工具配置
^^^^^^^^^^^^^^

配置文件位于 `configure/config.conf`，可使用记事本打开并进行编辑。

.. Flat-table::
    :header-rows: 1
    :widths: 1 1 1 2

    * - 主项
      - 子项
      - 可选值
      - 说明
    * - :rspan:`2` facConfig
      - rssiLimit
      - 建议 -30 ~ -80
      - 周围待打印产品信号强度达到此阈值时，方可被扫描
    * - getMacType
      - [devboard, scan]
      - 提供两种录入设备信息的方式：
          - devboard：通过扫描板接收蓝牙广播来获取 MAC
          - scan：直接使用扫描枪获取设备信息
    * - print_enable
      - [0, 1]
      - 控制打印机启用状态：
          - 0：仅获取信息，不启动打印功能
          - 1：打印标签
    * - :rspan:`1` SerialConfig
      - devPort
      - COM*
      - 扫描板串口号
    * - devBaud
      - 115200
      - 扫描板波特率
    * - :rspan:`1` v2_scanboard（仅用于 V2 类型扫描板）
      - scan_timeout
      - 默认为 10
      - 扫描超时时间
    * - case_command
      - 2
      - 固定值
    * - bartender
      - version
      - [2022, 2016]
      - BarTender 软件版本 [#]_

.. [#] 目前仅支持 2016 及 2022 版本。


开始打印
--------------

工具界面
^^^^^^^^^^^^^^

.. figure:: ../../../_static/qr_tool/ui_main.png
    :align: center
    :scale: 50%

    高级选项（点击放大）

界面配置说明
^^^^^^^^^^^^^^

- ``Printer selection``：默认显示系统打印机，可根据需要选择对应打印机
- ``Template`` ：选择打印使用的模板文件
- ``Method of get data``: 设备信息的获取方式

  * ``Scanner get``: 使用扫码枪

    * ``Scan info Data Type``: 扫码枪扫描内容的格式

      * ``Module label``: 乐鑫模组屏蔽盖二维码
      * ``Device label``：已打印出的设备标签
      * ``MAC``：乐鑫产品的 MAC 地址
  * ``BLE Broadcast``: 使用扫描板
- ``Print Label Num``: 执行打印时，打印此数量的标签。目前最大打印数量为 6
- ``Data Base``：数据源

  * ``ESP Server``: 从乐鑫服务器获取二维码数据
  * ``Local excel``：从本地的表格中查询数据，并按格式要求复制到 `data_source/matter_qrcode_data.xlsx` 中。数据按如下格式存放:

    .. figure:: ../../../_static/qr_tool/xlsx_data.png
        :align: center
        :scale: 90%

        数据存放样式

  * ``Scanner data``：从扫描数据中获取信息（目前仅 Cyprus 方案支持此配置，因为其设备广播信息自带 MAC 及二维码信息）。


常见打印方式
^^^^^^^^^^^^^^

- 扫描屏蔽盖二维码打印：

.. figure:: ../../../_static/qr_tool/devl.png
    :align: center
    :scale: 50%

    扫描屏蔽盖二维码打印（点击放大）

- 扫描已打印的标签打印：

.. figure:: ../../../_static/qr_tool/devl_to_devl.png
    :align: center
    :scale: 50%

    扫描已打印标签打印（点击放大）


打印标签检查
--------------

打印标签检查的目的是确保设备和已打印的二维码信息一致。因此，需使用扫描板来扫描设备的蓝牙广播信号。

.. figure:: ../../../_static/qr_tool/qr_check.png
    :align: center
    :scale: 50%

    二维码检查（点击放大）

- 二维码检查时，需要使用扫描板的配置方式，对应到界面 ``Print Label`` 中的 ``Method of get data``: ``BLE boardcase``。

  * 配置文件里的 ``facConfig`` 下的 ``getMacType = devboard``。

- 根据要检查的设备码数量勾选复选框，使能对应数量的 device label。
- 如需进行 DSN 检查（仅适用于 Cyprus 方案），可勾选复选框来使能该功能。


镭雕机适配
--------------

目前支持通过局域网获取二维码功能，以便于镭雕集成。

配置方式
^^^^^^^^^^^^^^

.. list-table:: TCPserverConfig
    :header-rows: 1
    :align: center
    :widths: 1 1 2

    * - 配置项
      - 配置值
      - 说明
    * - server_enable
      - 1
      - 是否使能局域网获取功能
    * - ip
      - 127.0.0.1
      - 局域网地址，若镭雕上位机和此上位机在同一 PC，可以使用回环地址
    * - port
      - 6000
      - TCP 通信端口
    * - qr_req_string
      - get_qrcode
      - 请求 qrcode 指令，可根据镭雕机配置调整
    * - manual_req_string
      - get_manualcode
      - 请求 manual 指令，可根据镭雕机配置调整
    * - dsn_req_string
      - get_dsncode
      - 请求 dsn 指令，可根据镭雕机配置调整


附录一：扫描板固件烧录
-----------------------

- 扫描板固件烧录需使用 ESP32-C3 芯片类开发板，请根据具体的方案类型选择对应的开发板。
- bin 文件路径：``./files``
- 烧录地址：``0x0``

烧录工具下载：:download:`点此下载烧录工具 <https://dl.espressif.com/public/flash_download_tool.zip>`


附录二：BarTender (2022) 安装示例
----------------------------------

BarTender 安装过程如下图所示（以 BarTender 2022 版本为例）：

#. 选择 `指定高级安装选项`。

    .. figure:: ../../../_static/qr_tool/bar_2.png
      :align: center
      :scale: 90%

      指定高级安装选项（点击放大）

#. 使用默认安装路径。

    .. figure:: ../../../_static/qr_tool/bar_3.png
      :align: center
      :scale: 90%

      默认安装路径（点击放大）

#. 安装过程如下图所示。

    .. figure:: ../../../_static/qr_tool/bar_4.png
      :align: center
      :scale: 90%

      安装过程（点击放大）

    .. figure:: ../../../_static/qr_tool/bar_5.png
      :align: center
      :scale: 90%

      安装完成（点击放大）

#. 输入序列号进行激活，安装完成。

    .. figure:: ../../../_static/qr_tool/bar_6.png
      :align: center
      :scale: 90%

      输入序列号（点击放大）
