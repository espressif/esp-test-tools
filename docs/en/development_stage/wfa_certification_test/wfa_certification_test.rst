WFA Certification and Testing Guide
===================================

:link_to_translation:`zh_CN:[中文]`

Overview
--------

This section provides guidance on obtaining Wi-Fi Alliance (WFA) certification for products based on Espressif chips. It focuses on the QuickTrack process to help you efficiently achieve WFA certification.

Required tools and firmware:

.. list::

   - :doc:`Flash Download Tool <../../production_stage/tools/flash_download_tool>`
   - :download:`espsigma tool and firmware  <https://dl.espressif.com/Authentication/WFA/WFA_TEST.zip>`

Introduction to WFA Certification
---------------------------------

Certification Process
^^^^^^^^^^^^^^^^^^^^^

The WFA certification typically follows these steps:

.. figure:: ../../../_static/wfa_certification_test_guide/wfa_certification_process.png
    :align: center
    :scale: 70%

    Standard Process

1. Submit the certification application and choose an Authorized Test Laboratory (ATL), which receives the Certification ID (CID).
2. Send the device to ATL for testing.
3. ATL conducts the necessary test.
4. ATL provides the test results.
5. WFA issues the certification.

Certification Types
^^^^^^^^^^^^^^^^^^^

1. **New Certification**

   Choose this option if the product has not been Wi-Fi certified before.

2. **Additional Certification**

   Choose this option if the product is already certified but needs to test new features.

3. **Re-Certification**

   If there are changes to the firmware or software that affect Wi-Fi functionality, re-certification is needed, This includes:

   .. list::

      - Small hardware changes or updates to device software (e.g., operating system or drivers)
      - Firmware changes or minor software modifications that affect Wi-Fi operation (even small updates or bug fixes)
      - Changes that don't affect Wi-Fi functionality must be reviewed by ATL to determine if testing is required

4. **Derivative Certification**

   This applies to derivative products based on a source certification. The derivative product must be functionally consistent with the source product, and technical details must be provided to verify eligibility.

.. note::

    WFA certification primarily targets products operating in Wi-Fi 802.11a/b/g/n modes, typically using 2.4 GHz or 5 GHz radio frequency bands. This includes devices like wireless routers, smartphones, home appliances, computers, network infrastructure, and consumer electronics.

Espressif Product Certification Process
---------------------------------------

Certification Method
^^^^^^^^^^^^^^^^^^^^

- **Espressif Modules**: Generally, these follow the **New Certification** path.
- **Products based on Espressif Chips**: **QuickTrack** path is recommended.

The relationship between the two is as follows:

.. figure:: ../../../_static/wfa_certification_test_guide/new_certification_and_quicktrack_en.png
   :align: center
   :scale: 100%

   New Certification and QuickTrack

Once an Espressif module completes a new certification, Espressif stores the test data and generates a **Qualified Solution**. You can leverage this solution to streamline your certification process.

New Certification
^^^^^^^^^^^^^^^^^

The test items for Espressif modules are shown in the figure below.

.. figure:: ../../../_static/wfa_certification_test_guide/full_test_items.png
    :align: center
    :scale: 100%

    Full-test Test Items

The WFA testing includes two parts: **WTS (Sigma Tool Test Items)** and **QTT (QuickTrack Test Items)**. While some test items are same, the test cases differ between the two.

QuickTrack
^^^^^^^^^^

QuickTrack is a streamlined Wi-Fi certification method aimed at reducing testing and certification costs while speeding up the process. This method is designed for products built using a **Qualified Solution**.

To achieve QuickTrack:

1. Select components or solutions from a list of **Qualified Solutions** that meet your product requirements.
2. Perform consistency tests to ensure the components or solutions meet the **Qualified Solution** criteria.
3. Complete testing using tools provided by WFA, either in-house or through ATL.
4. Submit the test results for review by WFA.
5. Once the test results are approved by WFA, the product will receive Wi-Fi certification.

.. figure:: ../../../_static/wfa_certification_test_guide/quicktrack_process_en.png
    :align: center
    :scale: 75%

    Quick Certification Process

Advantages of QuickTrack
""""""""""""""""""""""""

QuickTrack reduces costs and testing time, helping you achieve WFA certification faster. For example, the ESP32-C2 module's full certification test takes about 7.5 days.

.. figure:: ../../../_static/wfa_certification_test_guide/fulltest_time_en.png
    :align: center
    :scale: 100%

    Full-test Testing Time

If you choose QuickTrack, you must first confirm the product information below:

.. figure:: ../../../_static/wfa_certification_test_guide/product_information.png
    :align: center
    :scale: 90%

    Product Information

- Using QuickTrack, you need only 1.5 days for QTT testing if your product differs from ESP32-C2.
- If no changes are made, certification can be obtained without further testing by simply paying the certification fee.

The comparison between QuickTrack and the ordinary certification method is as follows:

.. figure:: ../../../_static/wfa_certification_test_guide/normal_scheme_quicktrack_comparison_en.png
    :align: center
    :scale: 100%

    Comparison Between Ordinary Certification and QuickTrack

.. note::

    The test items mentioned refer only to the testing portion of the certification process. The full WFA certification process, including submission and approval, can take up to 40 days for standard certification. QuickTrack reduces this to approximately 10 days, saving around 70% of the time.

Current QuickTrack Status for Espressif Chips
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Currently, both ESP32-C2 and ESP32-C6 have completed QuickTrack **Qualified Solution** certification.

WFA Testing
-----------

1. Submit CID Information
^^^^^^^^^^^^^^^^^^^^^^^^^

You can fill in CID information according to requirements by referring to `Wi-Fi Alliance CID Filling Guide <https://www.wi-fi.org/file-member/flextrack-new-product-application-training>`__ and `Espressif Module Filling Method <https://www.cert.wi-fi.org/#/application/lisrshok/new?step=1>`__.

2. Flash Firmware
^^^^^^^^^^^^^^^^^

Flashing on Windows
"""""""""""""""""""

- Open the ``flash_download_tool_3.9.2.exe`` application.
- Set ``chipType`` to the corresponding chip name and ``workMode`` to ``develop``, then click ``OK``.
- Choose the firmware and specify the flashing address. Select the port number, set ``baud`` to ``115200``, and click ``START`` to begin flashing.
- Once flashing is complete, ``finish`` will be displayed.

.. figure:: ../../../_static/wfa_certification_test_guide/flash_configuration.png
    :align: center
    :scale: 90%

    Flash Configuration

Flash the following firmware to the corresponding address:

.. list::

    :esp32: - bootloader.bin  0x1000
    :not esp32: - bootloader.bin  0x0
    - espsigma.bin    0x10000
    - partition.bin   0x8000

.. figure:: ../../../_static/wfa_certification_test_guide/flash_firmware.png
    :align: center
    :scale: 90%

    Flash Firmware

Flashing on Ubuntu
""""""""""""""""""

- Install Python 3.7

  .. code-block:: bash

     cd espsigma_qt/espsigma
     ./tools/setup/setup_pyenv_python.sh
     source ~/.pyenv/activate

- Install the flash tool

  .. code-block:: bash

     pip install esptool

- Start flashing

  .. only:: esp32

      .. code-block:: bash

        esptool.py -p /dev/ttyUSB0 --chip=auto write_flash 0x1000 bootloader.bin 0x8000 partition-table.bin 0x10000 espsigma.bin

  .. only:: not esp32

      .. code-block:: bash

        esptool.py -p /dev/ttyUSB0 --chip=auto write_flash 0x0 bootloader.bin 0x8000 partition-table.bin 0x10000 espsigma.bin

3. Set Up the Test Environment
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- Use Ubuntu 16.04 or higher

- Install Python 3.7

  .. code-block:: bash

     cd espsigma_qt/espsigma
     ./tools/setup/setup_pyenv_python.sh
     source ~/.pyenv/activate

After installation, you can verify the Python version with ``python -v``.

.. note::

    When flashing firmware on a computer with an Ubuntu OS, the Python environment is already installed in the step of flashing firmware, so no further installation is needed. Only computers running Windows require this step to install the Python environment.

.. note::

    The Python version must be 3.7 or higher. If the version displayed in the terminal is incorrect, please the above command.

4. Start Testing
^^^^^^^^^^^^^^^^

Test the WTS Part
"""""""""""""""""

- Open a terminal and navigate to the Sigma test tool directory

  .. code:: bash

     cd /espsigma_qt/espsigma/esp_sigma_ca

- Start the test

  .. code:: bash

     python espsigma.py --dut /dev/ttyUSB*

.. note::

   ``*`` refers to the serial port number.

.. figure:: ../../../_static/wfa_certification_test_guide/wts_test.png
    :align: center
    :scale: 90%

    WTS Test

Test the QuickTrack Part
""""""""""""""""""""""""

- Open a terminal and navigate to the Sigma test tool directory

  .. code:: bash

     cd /espsigma_qt/espsigma/esp_sigma_ca

- Start the test

  .. code:: bash

     python espsigma.py --quicktrack --dut/dev/ttyUSB *

  .. note::

     ``*`` refers to the serial port number.

.. figure:: ../../../_static/wfa_certification_test_guide/quicktrack_test_1.png
    :align: center
    :scale: 90%

    QuickTrack Test-1

- Open another terminal and navigate to the control app directory

  .. code:: bash

     cd /espsigma_qt/controlappc-2.0.0.9

- Start the control app

  .. code:: bash

     ./app -p *

  .. note::

     ``*`` refers to the QuickTrack Test (QTT) port, e.g., 9005.

.. figure:: ../../../_static/wfa_certification_test_guide/quicktrack_test_2.png
    :align: center
    :scale: 90%

    QuickTrack Test-2

Please refer to the pictures for Quicktrack page settings

.. figure:: ../../../_static/wfa_certification_test_guide/quicktrack_configuration_1.png
    :align: center
    :scale: 75%

    QuickTrack Settings-1

.. figure:: ../../../_static/wfa_certification_test_guide/quicktrack_configuration_2.png
    :align: center
    :scale: 75%

    QuickTrack Settings-2

.. figure:: ../../../_static/wfa_certification_test_guide/quicktrack_configuration_3.png
    :align: center
    :scale: 100%

    QuickTrack Settings-3

.. figure:: ../../../_static/wfa_certification_test_guide/quicktrack_configuration_4.png
    :align: center
    :scale: 100%

    QuickTrack Settings-4

.. figure:: ../../../_static/wfa_certification_test_guide/quicktrack_configuration_5.png
    :align: center
    :scale: 100%

    QuickTrack Settings-5
