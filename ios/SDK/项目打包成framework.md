# iOS项目打包成.framework

## 创建项目

两个项目 `Demo` 和 `Test`  ，一个Framework `DeomSDK` :

- `Demo` 将要被打包成 SDK 的项目

- `DemoFramework` 将项目打包成的 Framework

- `Test` 测试打包成的 Framework

三个项目都添加 `Podfile` 文件，`pod install` 初始化三方库，用来测试三方库的打包。

`Demo` 中使用pod引入的三方库，在 `DemoSDK` 和 `Test` 中同样需要通过pod引入。

```sh
inhibit_all_warnings!

platform :ios, '9.0'

target 'XXXx' do
  pod 'Masonry'
  pod 'SVProgressHUD'
end
```



## Demo

包含内容：三方库、pch文件、图片 xib 等文件



## DemoFramework

#### 导入项目

打开被打包项目目录，将与 `.xcodeproj` 同级的项目文件夹，直接拖进 `framework` 项目中。

#### 修改设置

##### General

- Deployment Info ：设置支持的版本，支持的设备

##### Build Settings

- Architectures
  - Build Active Architecture Only ：设置为NO（YES打包的Framework，只能用于当前打包所选设备使用）
- Linking
  - Mach-O Type ：设置为 Static Library（非官方Framework只能使用静态模式）

- Apple Clang - Language
  - Prefix Header ：设置 pch 文件路径（如： `DemoFramework/Demo/PrefixHeader.pch`）

###### Build Phases

- Headers 
  - Public ：设置对外暴露的接口（需要暴露的 `.h` 文件，同时需要在创建 Framework 项目自动生成的 `.h` 头文件中，按指定格式 `import` 。如：`#import <DemoFramework/PublicHeader.h>` ）
  - Project ：设置需要引入 framework 的文件，删除 `AppDelegate.h` ，否则 framework 被导入项目中，和项目中的 `AppDelegate.h` 文件冲突。
- Link Binary With Libraries ：手动添加项目使用到的未自动添加进来的库
- Copy Bundle Resources ：删除 `info.plist` 文件

#### 修改项目

##### 三方库

`framework` 和使用 `framework` 的项目同样需要导入 `被打包项目` 中使用的三方库

##### pch 文件

需要在 `framework` 中，配置 `pch` 文件路径

##### 图片、xib 等

需要打包成 `Bundle` ，同样需要导入到 `framework` 和使用 `framework` 的项目

```objective-c
[UIImage imageNamed:@"DemoFramework.bundle/nav_goback"];
```

```objective-c
```



## Test

