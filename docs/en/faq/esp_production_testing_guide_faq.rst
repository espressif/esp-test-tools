Espressif Production Testing Guide
==================================

:link_to_translation:`zh_CN:[中文]`

**1. Why it is necessary to set up an evaluating environment?**

  To ensure smooth mass production testing, the test environment must be evaluated beforehand. This is to confirm several aspects: stable power supply (including power to the DUT and the signal board), that the signal board and production test baseboard meet requirements, and to eliminate potential interference from the surrounding environment.

**2. What should be done if RX FAIL occurs after testing and fb_rssi and dut_rssi are outside the normal range?**

  If RX FAIL occurs after testing and fb_rssi and dut_rssi are greater than 60 or less than -30, the following measures can be taken: increase the distance between the signal board and the module under test, or add a 30 dB attenuator on the signal board side.

**3. How often does the signal board need to be calibrated? How can interference between signal boards be avoided?**

  The MAC address and production date of the board are given at the back of the signal board. Note that the signal board must be recalibrated every year, because the long operating time of components, such as crystal oscillators, may lead to measurement deviations. Only ONE signal board must be used in an independent environment or RF-shielded environment to avoid interference.
