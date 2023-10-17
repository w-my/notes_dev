//
//  ViewController.swift
//  OC 到 Swift
//
//  Created by WTW on 2020/5/25.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        //MARK: - 条件编译
        
        /*
         在 Build Settings ->swift compiler -Custom Flags 下进行配置
         */
        
        // 操作系统 macOS\iOS\watchOS\Linux\Android\Windows\FreeBSD
        #if os(macOS) || os(iOS)
        
        // CPU 架构 i386\X86_64\arm\arm64
        #elseif arch(x86_64) || arch(arm64)
        
        //swift 版本
        #elseif swift(<5) || swift(>=3)
        
        // 模拟器
        #elseif targetEnvironment(simulator)
        
        // 可以导入某模块
        #elseif canImport(Foundation)
        
        #else
        #endif
        
        // 测试 (可以在 Product ->Scheme ->Edite Scheme 中修改 debug 还是 release)
        print("release模式")
        #if DEBUG
            print("DEBUG模式")
        #else
        #endif
        
        #if TEST
            print("TEST模式")
        #endif
        
        #if OTHER
            print("OTHER模式")
        #endif
        
        //MARK: - 打印
        log("hello")
        
        // MARK: - 系统版本检查
        
        if #available(iOS 10,macOS 10.12, *){
            // iOS 平台只在 iOS 10 及以上系统执行
            // 对于与macOS平台,只在 macOS 10.12 及以上系统执行
            // * 代表在其他所有平台都执行
        }
        
        // MARK: API 可用性说明
        // https://docs.swift.org/swift-book/ReferenceManual/Attributes.html
        /*
        @available(iOS 10,macOS 10.15,*)
        class Person {}
        
        struct Person {
            
            @available(*,unavailable,renamed: "study")
            func study_()  { }
            func study()  { }
            
            @available(iOS,deprecated: 11)
            @available(macOS,deprecated: 10.12)
            func run() { }
        }
        */
        
        // MARK:- iOS 程序的入口
        /*
         @UIApplicationMain 表示编译器自动生成入口代码(main 函数代码)，自动设置 AppDelegate  为App的代理
         也可以删掉，自定义入口函数(自定义代理)：新建一个 main.swift 文件
         
         class MyApplication: UIApplication {}

         UIApplicationMain(CommandLine.argc,
                           CommandLine.unsafeArgv,
                           NSStringFromClass(MyApplication.self),
                           NSStringFromClass(AppDelegate.self))
         */
        
        // MARK: - Swift 调用 OC
        /*
         新建一个桥接头文件，文件名格式默认为  {targetName}-Bridging-Header.h
         配置文件路径：
         Build Settings -> Objective-C Bridging Header -> 文件路径
         
         在 .h 头文件中加入需要 swift 用到的 OC 文件即可
         
         如果C 语言暴露给Swift 的函数名和Swift中的其他函数名冲突了，可以在 Swift 中使用 @_silgen_name() 修改 C 语言的函数名
         
         int sum(int a,int b){
             return a + b;
         }
         
         // 这种方法可以用来调用底层的一些函数
         @_silgen_name("sum")
            func swift_sum(_ v1: Int32,_
                             v2: Int32) ->Int32
            print(swift_sum(10,20))
         */
        
        
        // MARK:- OC 调用 Swift
        /*
         Xcode已经默认生成一个用于OC调用Swift的头文件，文件名格式是: {targetName}-Swift.h
         Build Settings -> Swift Compiler -General -> OBjective-C General Interface Header Name xxxx.swift.h
         
         Swift 暴露给 OC 的类最终继承自 NSObject
         
         使用 @objc 修饰需要暴露给 OC 的成员
         
         使用@objcMembers修饰类
            代表默认所有成员都会暴露给OC(包括扩展中定义的成员)
            最终是否成功暴露，还需要考虑成员自身的访问级别
         
         import Foundation
         
         @objcMembers class Car: NSObject {
             var price: Double
             var band: String
             init(price: Double, band: String) {
                     self.price = price
                     self.band = band
             }
         func run() { print(price, band, "run") }
         
         static func run() { print("Car run") } }
         
         extension Car {
            func test() { print(price, band, "test") }
         }
         */
        
        
        //MARK: 单例模式
        
//        public class FileManager {
//            public static let shared = FileManager()
//            private init() {}
//        }
        
//        public class FileManager {
//            public static let shared = {
//
//                // ......
//                return FileManager()
//            }()
//
//            private init() {}
//        }
        
        
    }

    // 打印工具
    func log<T>(_ msg: T,
                file: NSString = #file,
                line: Int = #line,
                fn: String = #function) {
        
        #if DEBUG
        let prefix = "\(file.lastPathComponent)_\(line)_\(fn):"
        print(prefix,msg)
        #endif
    }
    
}

