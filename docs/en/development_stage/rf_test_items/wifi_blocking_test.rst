Wi-Fi Blocking Test
==============================

:link_to_translation:`zh_CN:[中文]`

The Wi-Fi Blocking Test is used to evaluate the receiving capability of the device under test in the presence of external interference, mainly for CE certification.

.. include:: wifi_blocking_adaptivity_test_setup.inc

Testing with Serial Port Commands
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Enter the following commands in the serial port in sequence to set up the network:

::

  \\Device networking
  \\Configure the prototype to enter station mode
  op -S -o 1

  \\Connect to AP, SSID is CMW-AP, password is 12345678
  sta -C -s CMW-AP -p 12345678

.. note::

    - The ``-p`` parameter is used to set the AP password. If the AP has no password, this parameter is not needed.

The following information is printed in the serial port, indicating a successful connection and the Wi-Fi Blocking Test can be performed.

.. figure:: ../../../_static/rf_test_tool/wifi_blocking_log.png
    :align: center
    :scale: 80%

    Device Networking Serial Port Print Log

Testing with ESPRFTestTool
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- Open the `EspRFTestTool package <https://dl.espressif.com/RF/EspRFTestTool_v3.6_Manual.zip>`_, configure ``ChipType`` and ``COM``, select a baud rate of 115200, after opening the port, select the ``WiFi Adaptivity`` test interface.

- In ``STA`` mode, enter ``AP ssid`` and ``AP pwd``, then click ``Connect AP`` to connect.

- If a log similar to the following is printed, it indicates that the network is successfully set up:

.. figure:: ../../../_static/rf_test_tool/wifi_adptive_connection.png
    :align: center
    :scale: 80%

    Device Networking

After the network is successfully set up, you can start the Wi-Fi Blocking Test.
