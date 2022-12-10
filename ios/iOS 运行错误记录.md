# 运行错误记录



## M1 Mac 引用 YYKit 模拟器运行报错

> In /Users/xxx/Pods/YYKit/Vendor/WebP.framework/WebP(anim_decode.o), building for iOS Simulator, but linking in object file built for iOS, file '/Users/xxx/Pods/YYKit/Vendor/WebP.framework/WebP' for architecture arm64

解决方法：

1. 项目添加 `arm64`：打开路径：`左侧项目名一级目录` -> `PROJECT` -> `项目名` -> `Build Settings` -> `Excluded Architectures` 里面在 `Debug` 和 `Release` 模式下，分别添加：`Any iOS Simulator SDK` ->  `arm64`；
2. `Pod` 添加 `arm64`：打开路径：`左侧Pods一级目录` -> `PROJECT` -> `Pods` -> `Build Settings` -> `Excluded Architectures` 里面在`Debug`和`Release`模式下，分别添加：`Any iOS Simulator SDK` -> `arm64`；



