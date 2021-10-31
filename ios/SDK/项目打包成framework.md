# iOS项目打包成.framework

## 创建项目

两个项目 `Demo` 和 `Test`  ，一个Framework `DeomSDK` :

- `Demo` 将要被打包成 SDK 的项目

- `DemoSDK` 将项目打包成的 Framework

- `Test` 测试打包成的 Framework

三个项目都添加 `Podfile` 文件，`pod install` 初始化三方库，用来测试三方库的打包。

`Demo` 中使用pod引入的三方库，在 `DemoSDK` 和 `Test` 中同样需要通过pod引入。

```sh
inhibit_all_warnings!

platform :ios, '9.0'

target 'Demo' do
  pod 'Masonry'
  pod 'SVProgressHUD'
end
```



## Demo

包含内容：三方库、图片、pch文件



## DemoSDK

#### 设置

###### General

- Deployment Info ：设置支持的版本，支持的设备

###### Build Settings

- Architectures
  - Build Active Architecture Only ：设置为NO（YES打包的Framework，只能用于当前打包所选设备使用）
  - Mach-O Type ：设置为 Static Library（非官方Framework只能使用静态模式）
- Build Phases
  - Headers ：设置对外暴露的接口

对外暴露的文件需要-----