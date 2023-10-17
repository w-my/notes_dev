//
//  ViewController.swift
//  Swift KVO
//
//  Created by WTW on 2022/3/7.
//  Copyright © 2022 WTW. All rights reserved.
//
/*
 Swift 中 KVO 有两种方式：
 1、使用OC的KVO
     class 必须继承自 NSObject
     属性必须加上 @objc dynamic 前缀
     用后必须在合适的地方调用 remove 方法
 2、swift 方式 KeyPath 表达式
 不需要 remove (ios 11 以下需要手动移除)
 */

import UIKit

class MyClass: NSObject {

    @objc dynamic var age = 10;
}

class ViewController: UIViewController{

    /// 观察者
    var observation: NSKeyValueObservation?

    @objc dynamic var myclass = MyClass()

    override func viewDidLoad() {
        super.viewDidLoad()
        
        /// OC 的 KVO change 是从字典中取出值，然后 转换到特定的类型
        /// KeyPath 不是，而是直接在 change.newValue 中取
        observation = observe(\.myclass.age, options: .new, changeHandler: { _, change in
            if let age = change.newValue  {
                
                print(age)
            }
        })
    }

    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        myclass.age = 100
    }

    // iOS11 以下 keypath 这种还是需要手动移除的，否则会崩溃
    deinit {
        if #available(iOS 11.0,*) {} else if let ob = observation {
            ob.removeObserver(self, forKeyPath: "age")
        }
    }
}

//class MyClass: NSObject {
//
//    @objc dynamic var age = 10
//
//}
//
//class ViewController: UIViewController {
//
//    var myClass: MyClass = {
//        let myclsss = MyClass()
//        return myclsss
//    }()
//
//    override func viewDidLoad() {
//        super.viewDidLoad()
//
//        // 添加观察值
//        myClass.addObserver(self, forKeyPath: "age", options: .new, context: nil)
//
//    }
//
//    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
//        myClass.age = 100
//    }
//
//    /// 添加监听
//    override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey : Any]?, context: UnsafeMutableRawPointer?) {
//
//        print(keyPath,change)
//
//    }
//
//    deinit {
//        /// 移除观察者
//        myClass.removeObserver(self, forKeyPath: "age",context: nil)
//    }
//
//}

