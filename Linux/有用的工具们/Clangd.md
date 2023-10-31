# clangd 代码服务器

普通使用 vscode 中intelligence  ，使用体验并不算太好，代码分析慢，有时候提供的报错信息少，动不动就头文件波形曲线报错。

clangd作为一款强大的代码分析器，具有许多神奇特性，比如说clangd可以自动补充头文件。

clangd的杀手特性莫过于clang-tidy集成和全局补全功能。clangd集成了clang-tidy并且完成了clang-tidy的quick fix功能，你可以直接在clangd中使用quickfix来完成clang-tidy的改动。

另外一个杀手级功能就是可以直接补全没有include的内容，并且会自动增加include比如我们在这个文件里补全array，clangd会将array用实心圆标出，如果补全，会自动增加头文件

当然代价就是你需要配置clangd 的头文件引用位置 ，操作上手有一丢丢门槛。



## Vscode-clangd

特性拉满：

```json
 "clangd.arguments": [
    // 在后台自动分析文件（基于complie_commands)
    "--background-index",
    // 标记compelie_commands.json文件的目录位置
    // 关于complie_commands.json如何生成可见我上一篇文章的末尾
    // https://zhuanlan.zhihu.com/p/84876003
    "--compile-commands-dir=build",
    // 同时开启的任务数量
    "-j=12",
    // 告诉clangd用那个clang进行编译，路径参考which clang++的路径
    "--query-driver=/usr/bin/clang++",
    // clang-tidy功能
    "--clang-tidy",
    "--clang-tidy-checks=performance-*,bugprone-*",,
    // 全局补全（会自动补充头文件）
    "--all-scopes-completion",
    // 更详细的补全内容
    "--completion-style=detailed",
    // 补充头文件的形式
    "--header-insertion=iwyu",
    // pch优化的位置
    "--pch-storage=disk",
  ],
```



别人的配置：

```json
  "clangd.arguments": [
    "--background-index",
    "--compile-commands-dir=build",
    "-j=12",
    // "--folding-ranges",
    "--query-driver=/usr/bin/clang++",
    "--clang-tidy",
    "--all-scopes-completion",
    "--completion-style=detailed",
    "--function-arg-placeholders",
    "--header-insertion=iwyu",
    "--pch-storage=disk",
  ],
  "clangd.path": "/Users/panxueqian/develop/clangd_snapshot_20210328/bin/clangd"
"editor.semanticTokenColorCustomizations": {
    "enabled": true,
    "rules": {
      "parameter": "#306b72",
      "class": {
        "fontStyle": "bold",
        "foreground": "#729de3"
      },
      "type.fileScope": {
        "fontStyle": "bold",
        "foreground": "#729de3"
      },
      // for auto
      "type": {
        "fontStyle": "bold",
        "foreground": "#729de3"
      },
      "function": {
        "foreground": "#e5b124"
      },
      "typeParameter": {
        "foreground": "#729de3",
        "fontStyle": "italic bold",
      },
      "variable": "#26cdca",
      "variable.static": {
        "foreground": "#8f5daf",
        "fontStyle": "bold"
      },
      "enum": {
        "fontStyle": "bold",
        "foreground": "#729de3"
      },
      "enumMember": "#397797",
      "macro": {
        "foreground": "#8f5daf",
        "fontStyle": "bold"
      },
      "method": {
        "foreground": "#e5b124",
        "fontStyle": "underline"
      },
      // 只读量加粗
      "*.readonly": {
        "fontStyle": "bold"
      },
      // 只读量等效为宏
      "*.fileScope": {
        "foreground": "#8f5daf",
        "fontStyle": "bold"
      },
      "comment": "#505050",
      "namespace": {
        "foreground": "#00d780",
        "fontStyle": "bold"
      },
      "property": {
        "foreground": "#7ca6b7",
        "fontStyle": "underline"
      },
    }
  },
```



如果你想在 Nvim 中使用clangd ，请参考 本目录下 好用的工具们： Nvim 一文的配置。

