# Flutter



## Mac 安装 Flutter 环境

#### 配置 Flutter SDK

##### 1. 下载 Flutter SDK

[Flutter 官网](https://flutter.dev) -> Docs -> Get started -> Install ，选择 MacOS，有详细的官网安装教程

##### 2. 提取 SDK

```sh
cd ~/Library/Flutter
unzip ~/Downloads/flutter_macos_2.5.1-stable.zip
```

##### 3. 添加到环境变量

```sh
export PATH="$PATH:`pwd`/flutter/bin"
```

```sh
# 编辑配置文件
vim ~/.bash_profile
# 添加 flutter 环境变量
export PATH="$PATH:~/Library/Flutter/bin"
# 保存后刷新配置，使配置生效
source .bash_profile
```

##### 4. 查看 flutter 配置依赖

```sh
flutter doctor -v
```



## iOS setup

#### 安装 Xcode

##### 1. 苹果官网或 App Store 安装 Xcode

##### 2. 配置 Xcode

```sh
$ sudo xcode-select --switch /Applications/Xcode.app/Contents/Developer
$ sudo xcodebuild -runFirstLaunch
```

##### 3. 启动一次 Xcode 或者运行一下命令行： `sudo xcodebuild -license`

##### 错误：

```
CocoaPods installed but not working.
  You appear to have CocoaPods installed but it is not working.
  This can happen if the version of Ruby that CocoaPods was installed with is different from the one being used to invoke it.
	This can usually be fixed by re-installing CocoaPods.
To re-install see https://guides.cocoapods.org/using/getting-started.html#installation for instructions.
```

解决：





#### 配置 iOS simulator

##### 1. 启动模拟器

```sh
open -a Simulator
```



## 创建&运行一个简单的 Flutter app

##### 1. 创建 Flutter app

```sh
flutter create my_app
```

##### 2. 进入项目目录

```sh
cd my_app
```

##### 3. 运行项目

```sh
flutter run
```

Flutter run key commands：

```sh
r # Hot reload. 🔥🔥🔥
R # Hot restart.
h # List all available interactive commands.
d # Detach (terminate "flutter run" but leave application running).
c # Clear the screen
q # Quit (terminate the application on the device).
```



## Android setup

#### 安装 Android Studio

##### 1. [官网](https://developer.android.google.cn/studio/#downloads) 下载安装

##### 2. 配置 Android Studio

启动 Android Studio，出现配置代理的地方，可以不配置，一路点下去 Finish。

进入主界面后，左上角 Android Studio -> Preferences -> Plugins，

搜索 Flutter，点击安装 Install，然后 Restart IDE。

然后检查 Flutter 依赖。

```sh
flutter doctor -v
```

##### 错误：

```sh
cmdline-tools component is missing
Run `path/to/sdkmanager --install "cmdline-tools;latest"`
See https://developer.android.com/studio/command-line for more details.
```

解决：

Android Status -> Preferences... -> Appearance & Behavior -> System Settings -> Android SDK -> SDK Tools

必须勾选以下4项：

```sh
Android SDK Build-Tools 31
Android SDK Command-line Tools (latest)
Android SDK Platform-Tools
Android SDK Tools
```

Apply，重新运行 `flutter doctor -v` 。

##### 错误：

安卓许可证问题

```sh
Some Android licenses not accepted.  To resolve this, run: flutter doctor --android-licenses
```

执行以下命令，一路 `y` 就可以了。

```sh
flutter doctor --android-licenses
```



#### 配置 Android emulator

























