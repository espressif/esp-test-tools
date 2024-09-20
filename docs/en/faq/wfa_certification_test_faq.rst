WFA Certification Test
======================

:link_to_translation:`zh_CN:[中文]`

**1. How can I get the USB port name of the device?**

  Run the command ``ls /dev/ttyUSB*`` in the terminal to see the USB port name.

**2. How can I get the MAC address of the DUT?**

  - Open minicom with the command ``minicom -D /dev/ttyUSB*``;
  - Type ``query`` and the MAC address of the DUT will be shown as ``dut_mac``.

**3. How do I flash the enterprise certificate?**

  The certificate is already included in the firmware, so you do not need to flash it separately.

**4. Why isn't the tool starting?**

  Check the Python version and ensure the toolchain is fully installed.

**5. Why is the tool script not detecting UCC commands after starting?**

  Ensure that the IP address is correctly configured on your computer.

**6. What should I do if the DUT shows garbled output and is unresponsive to read/write commands?**

  Confirm that the DUT is flashed with the correct bin files and check that the power supply is working properly.
