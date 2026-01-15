# 为 ESP 测试工具与指南贡献力量

- [English](CONTRIBUTING.md)

本项目使用 reStructuredText (RST) 格式编写文档，并通过 Sphinx 工具构建为 HTML 和 PDF 格式。

欢迎您为 `docs/` 目录下的 `.rst` 文件提交改进！


## 贡献指南

1. 使用 reStructuredText 编写文档内容。

   > 有关 RST 语法的说明，请参见 [ESP-Docs User Guide > Writing Documentation（编写文档）](https://docs.espressif.com/projects/esp-docs/en/latest/writing-documentation/index.html)。

2. 在本地构建文档，预览修改效果。

   > 有关如何构建文档，请参见 [ESP-Docs User Guide > Building Documentation（构建文档）](https://docs.espressif.com/projects/esp-docs/en/latest/building-documentation/index.html)。

3. 按以下规范用英文编写提交说明 (commit message)：

   ```
   <类型>[可选范围]: <简要说明>

   <详细说明（可选）>
   ```

   `<类型>` 可取以下值之一：

   * `bugfix`：修正拼写、语法、格式错误、失效链接、翻译缺失或其他小问题。
   * `docs`: 新增文档或更新现有内容。

   `[可选范围]` 填写涉及的芯片型号。

   例如：

   ```
   bugfix(esp32): fix a typo in flash download tool document
   ```

4. 提交 Pull Request (PR)。

5. 签署 [贡献者许可协议 (CLA)](https://cla-assistant.io/espressif/esp-test-tools)。CLA 助手将在 PR 评论区引导签署流程。


## PR 提交后的处理流程

Pull Request (PR) 被采纳后：

* 修改内容将同步至内部仓库进行最终审核，审核包括自动测试和代码所有者评审。
* 审核通过并入内部仓库默认分支后，您的修改将：

  * 发布至 [官方文档网站](https://docs.espressif.com/projects/esp-test-tools/zh_CN/latest/esp32/index.html)。
  * 同步回此 GitHub 公共仓库。
