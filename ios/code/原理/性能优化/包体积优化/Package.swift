//
//  Package.swift
//  性能优化
//
//  Created by WTW on 2022/5/27.
//  Copyright © 2022 wtw. All rights reserved.
//
// https://mp.weixin.qq.com/s/LoupXSq27ht89LwpheoAJw
// https://juejin.cn/post/7072196942045904933#heading-12

import Foundation

/// 包体积优化

/**
 * 一、资源优化
 *
 * 1、资源清理
 *   清理不再使用的资源，图片、配置文件、音视频文件等。
 *
 * 2、资源整理
 *   比较小的图片(5K以内)放到 Asset 动图和大图单独放，因为动图在压缩和合成的过程中可能会出现问题，体积比较大的图在压缩合成后，体积可能会更大
 *   以下命令获取资源编译后的信息：xcrun --sdk iphoneos assetutil --info Assets.car
 *
 * 3、资源压缩 （减少大小根据图片的多少和大小确定）
 *   pngquant、tinypng 等工具进行压缩
 *
 * 4、资源目录优化 (减少约1M左右)
 *  Build Settings-Asset Catalog Compiler Options-Optimization设置为space；
 *  这个选项可以改变actool在构建Assets.car时选取的编码压缩算法，减少包大小。
 *  使用以下命令检查Assets.car中图片的编码压缩算法：xcrun --sdk iphoneos assetutil --info Assets.car > Assets.json     zip/lzfse
 *
 * 5、资源云端迁移
 *    部分大资源(50kb以上的)考虑云端迁移
 *
 * 二、二进制优化
 *
 *  1、无用代码检测
 *      手动删除无用的代码
 *      Build Settings-Dead Code Stripping 设置为 Yes ，消除无用代码 （默认是开启的，没看到效果）
 *
 *
 *  2、二三方库下线
 *      删除不在使用的二三方库
 *
 *  3、 代码优化
 *      Build Settings-Optimization Level 发布模式修改为 [-Oz]
 *
 *  4、调试符号
 *
 *
 *  5、无用符号
 *  Build Settings-Deployment Postprocessing，调试模式下NO，发布模式下YES
 *  Deployment Postprocessing是Strip的总开关。
 *  也就是说，只有Deployment Postprocessing这里设置了YES，Strip Debug Symbols During Copy和Strip Linked Product设置为YES才会生效，其余情况均不生效
 *
 *  Strip Linked Product：对最终的二进制文件是否进行去除无用符号
 *  Strip Debug Symbols During Copy：文件拷贝编译阶段是否进行strip，设置为YES之后，会把拷贝进项目的第三方库、资源或者Extension的调试符号剥离
 *
 *  第三个符号的优化：Build Settings-Symbols Hidden by Default，调试模式下为NO，发布模式下为YES
 *  该选项的意思是当启用时，所有的符号多被声明为私有的extern，除非在代码中使用attribute((visibility("default")))明确标记为导出；反之，则所有符号都会被导出
 *
 *  6、复用字符串
 *  Build Settings-Make Strings Read-Only设置为YES；就是复用字符串字面
 *
 * 三、Xcode 编译优化
 *
 *1、查看编译指令集 (生产只打 arm64 效果还是很明显的)
 *  lipo -info xxx
 *  Architectures in the fat file: sohunews are: armv7 arm64
 *
 *  armv7s: iPhone 5, iPhone 5c, iPad 4
 *  模拟器64位处理器：x86_64
 *  模拟器32位处理器：i386
 *
 *  不需要32位架构armv7的，打包的时候只打 arm64 即可
 *
 *  方法1： Build Settings-Architectures 需要的打包标识符下的设置为 arm64 ,编译出多个指令集的代码包，ipa 就会变大；
 *  方法2：Build Settings-Excluded Arcitectures 需要的打包标识符下增加两个配置项目：Any iOS SDK 和 Any iOS Simulator SDK，然后分别设置为 armv7 和 arm64 (Release模式下针对真机armv7指令集排除，针对模拟器把arm64排除)
 *
 *
 *编译选项       _CodeSignature    Assets.car    embedded.mobileprovision    Info.plist    Plugins    Iproj    exec    图片资源    others    ipa    解压缩包
  初始配置        1.8MB     518KB    55KB    16KB    2.7MB    2KB    104.9MB    16.7MB    13.4MB    76.5MB    140.1MB
  Architectures    1.8MB    518KB    55KB    17KB    1.8MB    2KB    56.6MB    16.7MB    12.6MB    51.4MB    90.1MB
  Optimization    1.8MB    469KB    55KB    17KB    1.8MB    2KB    56.6MB    16.7MB    13.4MB    51.3MB    90.8MB
  Optimization Level    1.8MB    469KB    55KB    17KB    1.8MB    2KB    53.6MB    16.7MB    13.5MB    51MB    87.9MB

 *
 */





