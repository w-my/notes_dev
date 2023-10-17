//
//  ViewController.swift
//  特性修饰词
//
//  Created by WTW on 2022/2/19.
//  Copyright © 2022 WTW. All rights reserved.
//  https://blog.csdn.net/zfqh111/article/details/107082018

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        // MARK: - @available
        
        /// 可用来标识计算属性、函数、类、协议、结构体、枚举等类型的生命周期。（依赖于特定的平台版本 或 Swift 版本)
//        @available (iOS 11.0,*) {
//
//        }else {
//
//        }
        
        // 放在结构体/函数/枚举/类/协议之前，表示只适用某一平台
//        @available(iOS 12.0, *)
//        func adjustDarkMode() {
//          /* code */
//        }
//        @available(iOS 12.0, *)
//        struct DarkModeConfig {
//          /* code */
//        }
//        @available(iOS 12.0, *)
//        protocol DarkModeTheme {
//          /* code */
//        }
        
        // 版本和平台的限定可以写多个
//        @available(OSX 10.15, iOS 13, tvOS 13, watchOS 6, *)
//        public func applying(_ difference: CollectionDifference<Element>) -> ArraySlice<Element>?
        
        // 可选参数还有
//        deprecated：从指定平台标记为过期，可以指定版本号
//        obsoleted=版本号：从指定平台某个版本开始废弃（注意弃用的区别，deprecated是还可以继续使用，只不过是不推荐了，obsoleted是调用就会编译错误）该声明
//        message=信息内容：给出一些附加信息
//        unavailable：指定平台上是无效的
//        renamed=新名字：重命名声明
        
        // 比如下面的例子：
        /*
        @available(swift, deprecated: 4.1, renamed: "compactMap(_:)", message: "Please use compactMap(_:) for the case where closure returns an optional value")
        public func flatMap<ElementOfResult>(_ transform: (Element) throws -> ElementOfResult?) rethrows -> [ElementOfResult]
        
        extension RLMNotificationToken {
            @available(*, unavailable, renamed: "invalidate()")
            @nonobjc public func stop() { fatalError() }
        */
        
        
        // MARK: - @discardableResult
        
      //带返回的函数如果没有处理返回值会被编译器警告⚠️。但有时我们就是不需要返回值的，这个时候我们可以让编译器忽略警告，就是在方法名前用@discardableResult声明一下
        /*
         @discardableResult
         public func request(
             _ url: URLConvertible,
             method: HTTPMethod = .get,
             parameters: Parameters? = nil,
             encoding: ParameterEncoding = URLEncoding.default,
             headers: HTTPHeaders? = nil)
             -> DataRequest
         {
             return SessionManager.default.request(
                 url,
                 method: method,
                 parameters: parameters,
                 encoding: encoding,
                 headers: headers
             )
         }
         */
        
        //MARK: - @inlinable
        // 可内联的声明，它来源于C语言中的inline。C中一般用于函数前，做内联函数
        // 目的是防止当某一函数多次调用造成函数栈溢出的情况。因为声明为内联函数，会在编译时将该段函数调用用具体实现代替，这么做可以省去函数调用的时间
        // Swift中的@inlinable和C中的inline基本相同，它在标准库的定义中也广泛出现，可用于方法，计算属性，下标，便利构造方法或者deinit方法中
        // 当应用某一处调用该方法时，编译器会将调用处用具体实现代码替换
        // 注意内联声明不能用于标记为private或者fileprivate的地方。
        
        
        // MARK: - @objcMembers
        // Swift中定义的方法默认是不能被OC调用的，除非我们手动添加@objc标识。但如果一个类的方法属性较多，这样会很麻烦，于是有了这样一个标识符@objcMembers
        // 它可以让整个类的属性方法都隐式添加@objc，不光如此对于类的子类、扩展、子类的扩展都也隐式的添加 @objc
    }

    
    
    

}

