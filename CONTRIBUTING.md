# Contributing to ESP Test Tools and Guidelines

- [中文](CONTRIBUTING_CN.md)

The documentation hosted in this project is written in reStructuredText (RST), and built into HTML and PDF using Sphinx.

We welcome contributions to the `.rst` files in the `docs/` directory!


## How to Contribute

1. Write your contributions using reStructuredText.

    > For instruction on the RST Syntax, see the [ESP-Docs User Guide > Writing Documentation](https://docs.espressif.com/projects/esp-docs/en/latest/writing-documentation/index.html).

2. Build the documentation locally to check your changes.

    > For how to build docs, see [ESP-Docs User Guide > Building Documentation](https://docs.espressif.com/projects/esp-docs/en/latest/building-documentation/index.html).

3. Write the commit message in the following format:

   ```
   <type>[optional scope]: <short description>

   <optional longer description>
   ```

   `<type>` can be one of the following values:

    - `bugfix`: Fix typos, grammar, formatting error, broken links, missing translations, or other minor issues.
    - `docs`: Add new or update existing content.

    `[optional scope]` is the affected chip.

    For example:

    ```
    bugfix(esp32): fix a typo in flash download tool document
    ```

4. Create a pull request with your changes.

5. Sign the [Contributor License Agreement (CLA)](https://cla-assistant.io/espressif/esp-test-tools). The CLA assistant will guide you how to do this in the pull request comment.


## What Happens After You Submit a PR

Once your pull request (PR) is accepted:

- The changes will be synchronized to our internal codebase for final review, including automated testing and code owner approval.
- After the changes are approved and merged into the default branch of our internal codespace, they will be

    - Published to the [documentation site](https://docs.espressif.com/projects/esp-test-tools/en/latest/esp32/index.html)
    - Propagated back to this public GitHub repository.
