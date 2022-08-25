# Flutter



## Mac 安装 Flutter 环境

#### 配置 Flutter SDK

##### 1. 下载 Flutter SDK

[Flutter 官网](https://flutter.dev) > Docs > Get started > Install ，选择 MacOS，有详细的官网安装教程

##### 2. 提取 SDK

```sh
cd ~/development
unzip ~/Downloads/flutter_macos_2.5.1-stable.zip
```

##### 3. 添加到环境变量

国内访问Flutter可能受限，使用国内开发者搭建的临时镜像 `vim ~/.bash_profile`

```sh
# flutter 国内镜像
export PUB_HOSTED_URL=https://pub.flutter-io.cn
export FLUTTER_STORAGE_BASE_URL=https://storage.flutter-io.cn
# flutter
export PATH=~/development/flutter/bin:$PATH
```

保存后刷新配置，使配置生效

```sh
source ~/.bash_profile
```

##### 4. 查看 flutter 配置依赖

```sh
flutter doctor -v
```

运行以下命令查看是否需要安装其它依赖项来完成安装

```sh
flutter doctor
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

下载地址：https://www.androiddevtools.cn/#android-studio

##### 2. 配置 Android Studio

启动 Android Studio，出现配置代理的地方，可以不配置，一路点下去 Finish。

进入主界面后，左上角 Android Studio > Preferences > Plugins，

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

Android Status > Preferences... > Appearance & Behavior > System Settings > Android SDK > SDK Tools

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

##### 1. 启用 VM acceleration。

##### 2. 创建模拟器

启动 `Android Studio` > `Tools` > `AVD Manager` (需要打开项目才有此选项)

选择 `Create Virtual Device` > `Next` > `建议选择Pie` > `Next` 

在 `Emulated Performance` 下，选择 **Hardware - GLES 2.0** 以启用硬件加速，或者 Automatic > Finish 。

##### 3. 启动模拟器

在 Android Virtual Device Manager 中, 点击 **Run** 。

##### 4. 运行 flutter 项目

进入 flutter 项目目录，执行命令：

```sh
flutter run
```



























