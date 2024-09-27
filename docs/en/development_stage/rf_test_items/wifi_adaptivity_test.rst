Wi-Fi Adaptivity Test
==============================

:link_to_translation:`zh_CN:[中文]`

The Wi-Fi Adaptivity Test simulates various network conditions and loads to access device's real-time adjustments in transmission rate, channel selection, and power levels, optimizing overall network performance and stability.

.. note::

  If the power spectral density (PSD) of the Wi-Fi signal is higher than 10 dBm/MHz, the adaptivity test should choose the Listen Before Talk (LBT) mechanism based on non-hopping load.

.. include:: wifi_blocking_adaptivity_test_setup.inc

.. _wifi-adaptivity-test:

Next, you can choose to `test using serial port commands`_ or `test using EspRFTestTool tool`_.

Test Using Serial Port Commands
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Enter the following commands in the serial port in sequence for network configuration and traffic testing:

::

  //Device networking
  //Configure the prototype to enter station mode
  op -S -o 1

  //Connect to AP, SSID is CMW-AP, password is 12345678
  sta -C -s CMW-AP -p 12345678

  //Traffic test
  //Clear socket
  soc -T

  //Create UDP, port is 8080, default socket ID is 54
  soc -B -t UDP -p 8080

  //Perform traffic test on AP device with socket ID 54
  soc -S -s 54 -i 192.168.1.1 -p 8080 -l 2000 -n 200000000 -j 1

.. note::

    The ``-p`` parameter is used to set the AP password. If the AP has no password, this parameter is not needed.

If the following similar information is printed in the serial port, it means that the traffic test has been successfully completed and the Wi-Fi adaptivity test can be started.

.. figure:: ../../../_static/rf_test_tool/wifi_adptive_log.png
    :align: center
    :scale: 80%

    Device Networking Serial Port Print Log

Test Using EspRFTestTool Tool
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- Open the `EspRFTestTool toolkit <https://dl.espressif.com/RF/EspRFTestTool_v3.6_Manual.zip>`_, configure ``ChipType`` and ``COM``, select 115200 for ``BaudRate``, open the port, and select the ``WiFi Adaptivity`` test interface.

- In ``STA`` mode, enter ``AP ssid`` and ``AP pwd``, and click ``Connect AP`` to connect.

- After successful connection, the following log should be printed:

.. figure:: ../../../_static/rf_test_tool/wifi_adptive_connection.png
    :align: center
    :scale: 80%

    Device Networking

- After successful connection, set ``Pakcet Num`` to a sufficiently large value, such as 20000000, to meet the long traffic test time.

- Set ``Server PORT`` to 8080, ``Socket ID`` to 54, and change ``Packet Delay`` to 1 to meet certification requirements.

- After the above settings are completed, click ``Send Data``. If the log is similar to the following figure, it means that the traffic test is successful and the Wi-Fi adaptivity test can be started.

.. figure:: ../../../_static/rf_test_tool/wifi_adptive_senddata.png
    :align: center
    :scale: 80%

    Wi-Fi Adaptivity Traffic Test
