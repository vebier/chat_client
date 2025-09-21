# chat_client

一个基于 Qt 6 开发的跨平台实时聊天客户端应用程序。

## 📋 项目简介

本项目是一个基于 C/S 架构的即时通讯软件客户端，使用 Qt 框架进行开发。它实现了文本聊天、文件传输、好友管理等功能，提供了美观且用户友好的交互界面。

## ✨ 功能特性

- **实时通讯**: 支持一对一文本消息发送与接收。
- **好友系统**: 添加、删除、搜索好友。
- **群组聊天**: 创建和管理群组，进行群聊。
- **文件传输**: 支持点对点文件传输。
- **美观UI**: 使用 Qt Widgets/QML 构建的现代化界面。
- **跨平台**: 支持 Windows, Linux (理论上也可支持 macOS)。

## 🛠️ 技术栈

- **框架**: [Qt 6.9.0](https://www.qt.io/)
- **编译器**: MSVC 2022 (Microsoft Visual C++)
- **语言**: C++17
- **构建系统**: qmake 
- **操作系统**: 主要开发环境为 Windows

## 📦 环境依赖与构建指南

### 前提条件

在构建本项目之前，请确保您的开发环境中已安装以下软件：

1. **Qt**: 版本 **6.9.0**。
   - 建议通过 [Qt Online Installer](https://www.qt.io/download-open-source) 安装。
   - 安装时务必勾选以下组件：
     - `MSVC 2022 64-bit`
     - `Qt Widgets` (如果您的项目是 Widgets-based)
     - `Qt Network`
     - (以及其他您的项目所依赖的模块，如 `Qt WebSockets`， `Qt Multimedia` 等)
2. **Visual Studio 2022**:
   - 安装 **Desktop development with C++** 工作负载。
   - 确保包含了 **Windows 10/11 SDK**。
3. **可选 - Qt Creator**: 推荐的集成开发环境。

### 获取源代码

bash

```
git clone https://github.com/vebier/chat_client.git
cd chat_client
```



### 构建项目

#### 方法一：使用 Qt Creator (推荐)

1. 打开 Qt Creator。
2. 选择 `文件` -> `打开文件或项目...`。
3. 导航到项目目录，打开 `.pro` 文件 (qmake) 。
4. Qt Creator 会自动配置套件(Kit)。请确保选择的套件是 **Desktop Qt 6.9.0 MSVC2022 64-bit**。
5. 点击左下角的 `构建` 按钮 (锤子图标) 或按 `Ctrl+B` 进行构建。
6. 点击 `运行` 按钮 (绿色三角形) 或按 `Ctrl+R` 启动应用程序。

#### 方法二：使用命令行 (qmake)

1. 打开 **x64 Native Tools Command Prompt for VS 2022** (在开始菜单中搜索即可)。
2. 导航到您的项目目录。
3. 执行以下命令：

bash

```
# 设置 Qt 环境变量 (路径请根据您的实际安装位置修改)
set PATH=C:\Qt\6.9.0\msvc2022_64\bin;%PATH%

# 使用 qmake 生成 Makefile
qmake -makefile

# 或者如果您的 .pro 文件名称不是默认的，请指定
# qmake YourProjectName.pro -spec win32-msvc -tp vc

# 运行编译好的程序
debug\client.exe
# 或者 
release\client.exe
```



## 🚀 如何使用

1. **启动客户端**: 运行编译生成的可执行文件。
2. **连接服务器**: 确保聊天服务器正在运行，并在客户端界面中输入正确的服务器地址和端口。
3. **登录/注册**: 使用您的账号登录或注册新账号。
4. **开始聊天**: 在好友列表中选择好友或群组，开始发送消息。

## 📁 项目结构

```
client/
├── include/                 # 头文件目录
│   ├── global.h            # 全局定义和声明
│   ├── login_dialog.h      # 登录对话框类
│   ├── mainwindow.h        # 主窗口类
│   └── register_dialog.h   # 注册对话框类
├── src/                    # 源文件目录
│   ├── global.cpp          # 全局实现
│   ├── login_dialog.cpp    # 登录对话框实现
│   ├── mainwindow.cpp      # 主窗口实现
│   └── register_dialog.cpp # 注册对话框实现
├── ui/                     # UI 设计文件
│   ├── login_dialog.ui     # 登录界面
│   ├── mainwindow.ui       # 主窗口界面
│   └── register_dialog.ui  # 注册界面
├── resource/               # 资源文件
│   ├── icon-2141481_1920.png
│   └── OIP.png
├── style/                  # 样式表
│   └── stylesheet.qss      # QSS样式文件
├── rc.qrc                  # 资源集合文件
├── client.pro              # qmake项目文件
├── client.pro.user         # Qt Creator用户配置
└── main.cpp                # 应用程序入口
```



## 🤝 参与贡献

我们欢迎任何形式的贡献！

1. Fork 本仓库。
2. 创建您的特性分支 (`git checkout -b feature/AmazingFeature`)。
3. 提交您的更改 (`git commit -m 'Add some AmazingFeature'`)。
4. 推送到分支 (`git push origin feature/AmazingFeature`)。
5. 打开一个 Pull Request。

## 📄 许可证

本项目采用 [[Apache-2.0 license](https://github.com/vebier/chat_client#)] 
