WFA 认证与测试指南
==========================================

:link_to_translation:`en:[English]`

概述
----------

本文档介绍了如何为基于乐鑫芯片的产品获得 Wi-Fi Alliance（WFA）认证，重点介绍了 QuickTrack 流程，以便高效通过 WFA 认证。

所需工具与固件：

.. list::

   - :doc:`Flash 下载工具 <../../production_stage/tools/flash_download_tool>`
   - `espsigma 工具与固件  <https://dl.espressif.com/Authentication/WFA/WFA_TEST.zip>`__

WFA 认证介绍
-------------------------

认证流程
^^^^^^^^^^^^^^^^^^

WFA 认证标准流程如下所示：

.. figure:: ../../../_static/wfa_certification_test_guide/wfa_certification_process.png
    :align: center
    :scale: 75%

    WFA 标准流程

1. 提交认证申请并选择 ATL (Authorized Test Laboratory)，ATL 获取 CID (Certification ID)
2. 将待测设备发送至 ATL
3. ATL 进行必要的测试
4. ATL 提供测试结果
5. WFA 颁发认证证书

认证类型
^^^^^^^^^^^^^^^^^

1. **全新认证 (New Certification)**

   如果产品之前未获得 Wi-Fi 认证，选择此选项。

2. **追加认证 (Additional Certification)**

   如果产品已获得认证，但需要测试新功能，选择此选项。

3. **重认证 (Re-Certification)**

   如果固件或软件发生了影响 Wi-Fi 功能的变化，则需要重新认证。具体包括：

   .. list::

      - 硬件的微小变更或设备软件的更新（例如操作系统或驱动程序）
      - 影响 Wi-Fi 操作的固件更改或小的软件修改（包括小更新或错误修复）
      - 不影响 Wi-Fi 功能的更改需由 ATL 审核确定是否需要测试

4. **派生认证 (Derivative Certification)**

   此项适用于基于源认证的衍生产品，衍生产品必须在功能上与源产品功能一致，需要提供技术细节以验证产品资格。

.. note::

    需要做 WFA 认证的产品主要是运行 Wi-Fi 802.11a/b/g/n 模式的设备，通常使用 2.4 GHz 或 5 GHz 射频频段，包括无线路由器、智能手机、家电、计算机、网络基础设施及消费电子产品等。

乐鑫产品认证流程
-------------------------------

认证方式
^^^^^^^^^^^^^^^

- **乐鑫模组**：通常采用 **全新认证**
- **基于乐鑫芯片的产品**：推荐使用 **QuickTrack**

二者之间的关系如下：

.. figure:: ../../../_static/wfa_certification_test_guide/new_certification_and_quicktrack.png
   :align: center
   :scale: 100%

   全新认证与 QuickTrack

一款乐鑫模组完成全新认证后，乐鑫会保存测试数据，并生成 **合格解决方案**，可利用该方案加快认证流程。

全新认证
^^^^^^^^^^^^^^^^

乐鑫模组测试项如下图所示。

.. figure:: ../../../_static/wfa_certification_test_guide/full_test_items.png
    :align: center
    :scale: 100%

    full-test 测试项

WFA 测试包括两部分，**WTS（Sigma 工具测试项）** 与 **QTT（QuickTrack 测试项）**。二者部分测试项相同，但是测试用例不同。

QuickTrack
^^^^^^^^^^

QuickTrack 是一种简化的 Wi-Fi 认证方法，旨在减少测试和认证成本并加快认证速度。此方法适用于基于 **合格解决方案** 构建的产品。

要完成 QuickTrack，需要完成以下步骤：

1. 从多个 **合格解决方案** 中选择适合产品需求的组件或方案
2. 进行一致性测试，确保产品使用的组件或方案是 **合格解决方案**
3. 使用 WFA 提供的工具自行测试或通过 ATL 进行测试
4. 提交测试结果
5. WFA 确认测试结果后即可获得认证

.. figure:: ../../../_static/wfa_certification_test_guide/quicktrack_process_cn.png
    :align: center
    :scale: 100%

    QuickTrack 过程

QuickTrack 的优势
"""""""""""""""""""""""""""""""

QuickTrack 可以降低成本并缩短测试时间，帮助你更快获得 WFA 认证。例如，ESP32-C2 模组的完整认证测试大约需要 7.5 天。

.. figure:: ../../../_static/wfa_certification_test_guide/fulltest_time.png
    :align: center
    :scale: 100%

    full-test 测试时间

如果你选择 QuickTrack，首先需要确认下面的产品信息：

.. figure:: ../../../_static/wfa_certification_test_guide/product_information.png
    :align: center
    :scale: 90%

    产品信息

- 如果你的产品与 ESP32-C2 不同，只需进行 QTT 测试，测试时间为 1.5 天。
- 如果没有变化，则无需测试，只需支付认证费用即可获得证书。

QuickTrack 与普通认证方式对比如下：

.. figure:: ../../../_static/wfa_certification_test_guide/normal_scheme_quicktrack_comparison.png
    :align: center
    :scale: 100%

    普通认证与 QuickTrack 对比

.. note::

    此处的测试时间仅指测试部分的时间，WFA 完整认证流程包括提交和审批，可能需要长达 40 天的时间。QuickTrack 可以将整个流程缩短至约 10 天，节省约 70% 的时间。

乐鑫芯片 QuickTrack 认证现状
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

目前，ESP32-C2 和 ESP32-C6 已通过 QuickTrack **合格解决方案** 认证。

WFA 测试
---------------

1. 填写 CID 信息
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

根据需求填写 CID 信息，参考 `Wi-Fi 联盟 CID 填写指导 <https://www.wi-fi.org/file-member/flextrack-new-product-application-training>`__ 和 `乐鑫模组填写方式 <https://www.cert.wi-fi.org/#/application/lisrshok/new?step=1>`__。

2. 烧录固件
^^^^^^^^^^^^^^^^^^

在 Windows 上烧录
""""""""""""""""""""""""""""""""

- 打开 ``flash_download_tool_3.9.2.exe`` 应用程序
- 将 ``chipType`` 设置为对应芯片名称，``workMode`` 设置为 ``develop``，点击 ``OK``
- 选择固件并指定烧录地址，选择端口号，将 ``baud`` 设置为 ``115200``，点击 ``START`` 开始烧录
- 烧录完成后，页面会显示 ``finish``

.. figure:: ../../../_static/wfa_certification_test_guide/flash_configuration.png
   :align: center
   :scale: 90%

   烧录配置

固件烧录地址：

.. list::

    :esp32: - bootloader.bin  0x1000
    :not esp32: - bootloader.bin  0x0
    - espsigma.bin     0x10000
    - partition.bin     0x8000

.. figure:: ../../../_static/wfa_certification_test_guide/flash_firmware.png
    :align: center
    :scale: 90%

    烧录固件

在 Ubuntu 上烧录
""""""""""""""""""""""""""""""

- 安装 Python 3.7

  .. code-block:: bash

     cd espsigma_qt/espsigma
     ./tools/setup/setup_pyenv_python.sh
     source ~/.pyenv/activate

- 安装烧录工具

  .. code-block:: bash

     pip install esptool

- 开始烧录

  .. only:: esp32

      .. code-block:: bash

        esptool.py -p /dev/ttyUSB0 --chip=auto write_flash 0x1000 bootloader.bin 0x8000 partition-table.bin 0x10000 espsigma.bin

  .. only:: not esp32

      .. code-block:: bash

        esptool.py -p /dev/ttyUSB0 --chip=auto write_flash 0x0 bootloader.bin 0x8000 partition-table.bin 0x10000 espsigma.bin

3. 安装测试环境
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- 使用 Ubuntu 16.04 或更高版本

- 安装 Python 3.7

  .. code-block:: bash

     cd espsigma_qt/espsigma
     ./tools/setup/setup_pyenv_python.sh
     source ~/.pyenv/activate

安装成功后，可通过 ``python -v`` 查看 Python 版本。

.. note::

    Ubuntu 系统的电脑在烧录固件时，已经安装了 Python 环境，无需再次安装。只有 Windows 系统的电脑需要进行这一步以安装 Python 环境。

.. note::

    Python 版本必须为 3.7 或更高，如果终端显示的版本不正确，请重复运行上述命令进行安装。

4. 开始测试
^^^^^^^^^^^^^^^^^^^^^^

测试 WTS 部分
""""""""""""""""""""""""""

- 打开终端窗口，进入 Sigma 工具目录

  .. code:: bash

     cd /espsigma_qt/espsigma/esp_sigma_ca

- 开始测试

  .. code:: bash

     python espsigma.py --dut /dev/ttyUSB*

.. note::

   ``*`` 指的是串口号。

.. figure:: ../../../_static/wfa_certification_test_guide/wts_test.png
    :align: center
    :scale: 90%

    WTS 测试

测试 QuickTrack 部分
""""""""""""""""""""""""""""""""

- 打开终端窗口，进入 Sigma 工具目录

  .. code:: bash

     cd /espsigma_qt/espsigma/esp_sigma_ca

- 开始测试：

  .. code:: bash

     python espsigma.py --quicktrack --dut/dev/ttyUSB *

  .. note::

     ``*`` 指的是串口号。

.. figure:: ../../../_static/wfa_certification_test_guide/quicktrack_test_1.png
    :align: center
    :scale: 90%

    QuickTrack 测试-1

- 打开另一个终端窗口，进入控制应用程序目录

  .. code:: bash

     cd /espsigma_qt/controlappc-2.0.0.9

- 启动控制应用程序

  .. code:: bash

     ./app -p *

  .. note::

     ``*`` 指的是 QuickTrack 测试端口，例如 9005。

.. figure:: ../../../_static/wfa_certification_test_guide/quicktrack_test_2.png
    :align: center
    :scale: 90%

    QuickTrack 测试-2

有关 Quicktrack 设置，请参考以下图片

.. figure:: ../../../_static/wfa_certification_test_guide/quicktrack_configuration_1.png
    :align: center
    :scale: 75%

    QuickTrack 设置-1

.. figure:: ../../../_static/wfa_certification_test_guide/quicktrack_configuration_2.png
    :align: center
    :scale: 75%

    QuickTrack 设置-2

.. figure:: ../../../_static/wfa_certification_test_guide/quicktrack_configuration_3.png
    :align: center
    :scale: 100%

    QuickTrack 设置-3

.. figure:: ../../../_static/wfa_certification_test_guide/quicktrack_configuration_4.png
    :align: center
    :scale: 100%

    QuickTrack 设置-4

.. figure:: ../../../_static/wfa_certification_test_guide/quicktrack_configuration_5.png
    :align: center
    :scale: 100%

    QuickTrack 设置-5
