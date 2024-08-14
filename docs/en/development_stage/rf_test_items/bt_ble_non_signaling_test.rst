{IDF_TARGET_BT_BLE_OPTION: default="Bluetooth LE", esp32="Bluetooth and Bluetooth LE"}

{IDF_TARGET_BT_BLE_OPTION} Non-Signaling Test
==============================================

:link_to_translation:`zh_CN:[中文]`

This document introduces how to conduct a {IDF_TARGET_BT_BLE_OPTION} non-signaling test (also known as a fixed frequency test) on products based on {IDF_TARGET_NAME} chips or modules.

.. include:: rf_non_signalling_test_setup.inc

.. _ble-non-signalling-test:

.. only:: esp32

    Bluetooth/Bluetooth LE TX Performance Test
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    - **Test Mode**:

      * BT TX: Used for Bluetooth TX performance tests;
      * BLE TX: Used for Bluetooth LE TX performance tests.

    - **Power Level**: Set the Bluetooth power level, supporting 0~7 levels of testing
    - **Channel**: Set the Bluetooth test channel
    - **Hoppe**: Enable the hopping function. Default: Disabled.
    - **Ulap**: Set the Bluetooth address, use the default value, only supported by Bluetooth
    - **Itaddr**: Set the logical TX address. Default value is used. Only supported by Bluetooth
    - **Syncw**: Set the identity code of the packet file. Default: syncw=0x71764129
    - **Payload length**: Set the payload length. Default: 250
    - **Data Rate**: Set the packet TX rate and encoding sequence. It supports four rates, including BT 1M, 2M, 3M and BLE 1M. It supports three encoding sequences, including 1010, 11110000, and prbs9

    After clicking ``start``, the Bluetooth TX parameter description is displayed in the log window, similar to the following:

    ::

        fcc_bt_tx:txpwr=4,hoppe=0,chan=18,rate=1,DH_type=1,data_type=1

    This indicates that the Bluetooth packet TX is normal, and the TX performance can be tested with the tester.

    .. figure:: ../../../_static/rf_test_tool/esp32_bt_tx_on.png
        :align: center
        :scale: 80%

        Bluetooth/Bluetooth LE TX Performance

    Bluetooth RX Performance Test
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    - **Test Mode**: Set to BT RX for Bluetooth RX performance tests
    - **Channel**: Set the Bluetooth test channel
    - **Ulap**: Set the Bluetooth address. The default value is used. Only supported by Bluetooth
    - **Itaddr**: Set the logical TX address. The default value is used. Only supported by Bluetooth
    - **Data Rate**: Set the packet RX rate, supporting BT 1M, 2M, 3M. The default encoding sequence is prbs9

    After clicking ``start``, use the tester to send packets on the test channel. Click ``stop`` after completion. The packet RX information is displayed in the log window, similar to the following:

    ::

        3e8 3e8 0 0 0 0 0 0 w 0 0 0 0 0 0 0 0 p 4176 45cf ddfd b 7ca240 0

    Where:

    - The 1st parameter Res[0] (hexadecimal) represents the total number of packets received in this test. In this test, the total number of packets is 3e8.
    - The 2nd parameter Res[1] (hexadecimal) represents the number of packets of the corresponding rate received in this test. In this test, the number of packets of the corresponding rate is 3e8.
    - The second to last parameter Res[22] (hexadecimal) represents the total number of codes of the corresponding rate received in this test. In this test, the total number of codes of the corresponding rate is 7ca240.
    - The last parameter Res[23] (hexadecimal) represents the total number of error codes received in this test. In this test, the number of error codes is 0.

    Based on the above parameters, you can calculate:

    - Bit error rate BT_BER = Res[23]/Res[22]
    - BT_RSSI = (-Res[18]]-Res[20])/Res[0]

    .. figure:: ../../../_static/rf_test_tool/esp32_bt_rx_on.png
        :align: center
        :scale: 80%

        Bluetooth RX Performance Test

    Bluetooth LE RX Performance Test
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    - **Test Mode**: Select BLE RX for Bluetooth LE RX performance test
    - **Channel**: Set the Bluetooth LE test channel
    - **Syncw**: Set the identity code of the packet file. Default: syncw=0x71764129
    - **Data Rate**: Set the packet RX rate. Default rate: BLE 1M.Default encoding sequence: prbs9

    After clicking ``start``, use the tester to send packets on the test channel. Click ``stop`` after completion. The packet RX information is displayed in the log window, similar to the following:

    ::

        3e8 3e8 0 0 0 0 0 0 0 0 w 0 0 0 0 0 0 0 0 p 5b83 58cf 6acb

    Where:

    - The 1st parameter Res[0] (hexadecimal) represents the total number of packets received in this test. In this test, the total number of packets is 3e8.
    - The 2nd parameter Res[1] (hexadecimal) represents the number of packets received at the corresponding rate in this test. In this test, the number of packets at the corresponding rate is 3e8.
    - The third last parameter Res[20] (hexadecimal) represents the in-band power of all packets in this test. In this test, the in-band power of all packets is 5b83.
    - The last parameter Res[22] (hexadecimal) represents the gain of all packets in this test. In this test, the gain of all packets is 6acb.

    Based on the above parameters, we can calculate:

    - Packet loss rate BLE_PER = [1-(Res[1]/Sent_Packet_Numbers)]*100%<=30.8%
    - BLE_RSSI = (-Res[20]-Res[22])/Res[0]

    .. figure:: ../../../_static/rf_test_tool/esp32_ble_rx_on.png
        :align: center
        :scale: 80%

        Bluetooth LE RX Performance Test

.. only:: not esp32

    Bluetooth LE TX Performance Test
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    - **Test Mode**:

      * BLE50 TX: Used for TX performance tests;
      * BLE50 TX continue: Used for certification tests.

    - **Power Level**: Set the Bluetooth LE TX power level, supporting 0~15 level test
    - **Channel**: Set the Bluetooth LE test channel
    - **Hoppe**: Enable hopping function. Default: disabled
    - **Ulap**: Set the Bluetooth address. Default: disabled
    - **Itaddr**: Set the logical TX address. Default: disabled
    - **Syncw**: Set the identity code of the packet file. Default: syncw=0x71764129
    - **Payload length**: Set the payload length. Default: 250
    - **Data Rate**: Set the packet TX rate and encoding sequence. It supports four rates, including BLE 1M, 2M, 125K, and 500K. It supports three encoding sequences, including 1010, 11110000, prbs9.

    After clicking ``start``, the Bluetooth LE TX parameter description is displayed in the log window, similar to the following:

    ::

        fcc_le_tx_syncw:txpwr=12,chan=0,len=250,data_type=0,syncw=0x71764129,rate=0,tx_num=0,contin_en=0,delay=0,hopp_en=0

    This indicates that the Bluetooth LE packet TX is normal, and at this point, the tester can be used to test the TX performance.

    .. figure:: ../../../_static/rf_test_tool/esp32c6_ble_test_on.png
        :align: center
        :scale: 80%

        Bluetooth LE TX Performance Test

    Bluetooth LE RX Performance Test
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    {IDF_TARGET_TWELFTH_PARA:default="received correct package", esp32c3="all packages", esp32s3="all packages"}

    {IDF_TARGET_RSSI:default="Res[11]/(Res[1])", esp32c3="Res[11]/(Res[1]+Res[4])", esp32s3="Res[11]/(Res[1]+Res[4])"}

    - **Test Mode**: Select BLE50 RX for Bluetooth LE RX performance test.
    - **Channel**: Set the Bluetooth LE test channel.
    - **Syncw**: Set the identity code of the package file. Default :syncw=0x71764129.
    - **Data Rate**: Set the package RX rate. The default encoding sequence is prbs9.

    After clicking ``start``, use the tester to send packages on the test channel. Click ``stop`` after completion. The package RX information is displayed in the log window, similar to the following:

    ::

        3e8 3e8 0 0 0 0 0 0 0 0 p -61009 -20424 0 40581

    Among them:

    - The 1st parameter Res[0] (hexadecimal) represents the total number of packages received in this test. In this test, the total number of packages is 3e8.
    - The 2nd parameter Res[1] (hexadecimal) represents the number of packages received at the corresponding rate in this test. In this test, the number of packages at the corresponding rate is 3e8.
    - The 12th parameter Res[11] (decimal) represents the RSSI of {IDF_TARGET_TWELFTH_PARA} in this test. In this test, the RSSI is -61009.

    Based on the above parameters, you can calculate:

    - Packet loss rate PER = [1-(Res[1]/Sent_Packet_Numbers)]*100%<=30.8%
    - RSSI of each package = {IDF_TARGET_RSSI}


      .. figure:: ../../../_static/rf_test_tool/esp32s3_ble_rx_on.png
          :align: center
          :scale: 80%

          Bluetooth LE RX Performance Test

Appendix
--------

This appendix is mainly used to explain the power level and corresponding target power of {IDF_TARGET_BT_BLE_OPTION} of {IDF_TARGET_NAME}, which is used for RF debugging or test reference.

.. only:: esp32

  .. list-table:: {IDF_TARGET_NAME} Bluetooth/Bluetooth LE TX Power Level
    :widths: 40 60

    * - Power Level
      - ESP32 Bluetooth/Bluetooth LE TX Power (dBm)
    * - 0
      - -12
    * - 1
      - -9
    * - 2
      - -6
    * - 3
      - -3
    * - 4
      - 0
    * - 5
      - 3
    * - 6
      - 6
    * - 7
      - 9

.. only:: not esp32

    Bluetooth LE TX Power Level
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. list-table:: {IDF_TARGET_NAME} Bluetooth LE TX Power Level
        :widths: 40 60

        * - Power Level
          - Bluetooth LE TX Power (dBm)
        * - 0
          - -24
        * - 1
          - -21
        * - 2
          - -18
        * - 3
          - -15
        * - 4
          - -12
        * - 5
          - -9
        * - 6
          - -6
        * - 7
          - -3
        * - 8
          - 0
        * - 9
          - 3
        * - 10
          - 6
        * - 11
          - 9
        * - 12
          - 12
        * - 13
          - 15
        * - 14
          - 18
        * - 15
          - 20

    Bluetooth LE 5.0 PHY Channels and Indexes
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    - For Bluetooth LE, the EspRFTestTool toolkit uses the Channel Index to identify channels.

    .. list-table::  {IDF_TARGET_NAME} Bluetooth LE 5.0 PHY Channels and Indexes
        :widths: 50 60 50

        * - PHY Channel
          - RF Center Frequency (MHz)
          - Channel Index
        * - 0
          - 2402
          - 37
        * - 1
          - 2404
          - 0
        * - 2
          - 2406
          - 1
        * - ...
          - ...
          - ...
        * - 11
          - 2424
          - 10
        * - 12
          - 2426
          - 38
        * - 13
          - 2428
          - 11
        * - 14
          - 2430
          - 12
        * - ...
          - ...
          - ...
        * - 38
          - 2478
          - 36
        * - 39
          - 2480
          - 39
