Wi-Fi Blocking Test
===================

:link_to_translation:`zh_CN:[中文]`

The Wi-Fi Blocking Test evaluates the device's reception performance in environments with strong interference. By introducing high-intensity interference signals, it measures the reception sensitivity and anti-interference capability of a device, ensuring reliable operation in complex wireless environments.

.. include:: wifi_blocking_adaptivity_test_setup.inc

Test with Serial Port Commands
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Enter the following commands in the serial port in sequence to set up the network:

::

  // Device Provisioning
  // Configure the prototype to enter station mode
  op -S -o 1

  // Connect to AP, SSID is CMW-AP, password is 12345678
  sta -C -s CMW-AP -p 12345678

.. note::

    - The ``-p`` parameter is used to set the AP password. If the AP has no password, this parameter is not needed.

If the following information is printed on the serial port, the connection is successful and the Wi-Fi Blocking Test can be performed.

.. figure:: ../../../_static/rf_test_tool/wifi_blocking_log.png
    :align: center
    :scale: 80%

    Serial Port Log for Device Provisioning

Test with ESPRFTestTool
^^^^^^^^^^^^^^^^^^^^^^^

- Open the `EspRFTestTool package <https://dl.espressif.com/RF/EspRFTestTool_v3.6_Manual.zip>`__, configure ``ChipType`` and ``COM``, select 115200 for ``BaudRate``, open the port, and select the ``WiFi Adaptivity`` test interface.

- In ``STA`` mode, enter ``AP ssid`` and ``AP pwd``, and click ``Connect AP`` to connect.

- After successful connection, the following log should be printed:

.. figure:: ../../../_static/rf_test_tool/wifi_adptive_connection.png
    :align: center
    :scale: 80%

    Serial Port Log for Device Provisioning

After successful connection, you can start the Wi-Fi Blocking Test.
