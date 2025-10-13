Wi-Fi Adaptivity Test
==============================

:link_to_translation:`zh_CN:[中文]`

The Wi-Fi Adaptivity Test evaluates a device's ability to make real-time adjustments to parameters, such as transmission rate, channel selection, and power levels, by simulating varying network conditions and loads. This test aims to optimize the overall network performance and stability.

.. note::

  If the power spectral density (PSD) of the Wi-Fi signal is higher than 10 dBm/MHz, the adaptivity test should choose the Listen Before Talk (LBT) mechanism based on non-hopping load.

.. include:: wifi_blocking_adaptivity_test_setup.inc

.. _wifi-adaptivity-test:

Next, you can choose to `test using serial port commands`_ or `test using EspRFTestTool tool`_.


Test Using Serial Port Commands
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Enter the following commands in the serial port in sequence for network configuration and traffic testing:

::

  //Device provisioning
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

If the following similar information is printed in the serial port, it indicates that the traffic has been started and the Wi-Fi Adaptivity Test can be initiated.

.. figure:: ../../../_static/rf_test_tool/wifi_adptive_log.png
    :align: center
    :scale: 80%

    Serial Port Log for Device Provisioning

Test Using EspRFTestTool Tool
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- Open the EspRFTestTool toolkit, configure ``ChipType``, ``COM``, and  ``BaudRate``, open the port, and select the ``WiFi Adaptivity`` test interface.

- In ``STA`` mode, enter ``AP ssid`` and ``AP pwd``, and click ``Connect AP`` to connect.

- After successful connection, the following log should be printed:

.. figure:: ../../../_static/rf_test_tool/wifi_adptive_connection.png
    :align: center
    :scale: 80%

    Device Network Provisioning

- After a successful connection, set ``Pakcet Num`` to a sufficiently large value—such as 20000000—to ensure the traffic can run for a long duration.

- Set ``Server PORT`` to 8080, ``Socket ID`` to 54, and change ``Packet Delay`` to 1 to meet certification requirements.

- After the above settings are completed, click ``Send Data``. If the log is similar to the figure below, it indicates that the traffic has been started, and the Wi-Fi Adaptivity Test can be initiated.

.. figure:: ../../../_static/rf_test_tool/wifi_adptive_senddata.png
    :align: center
    :scale: 80%

    Wi-Fi Adaptivity Traffic Test
