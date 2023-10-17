//
//  ViewController.swift
//  泛型
//
//  Created by WTW on 2020/1/20.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        // 泛型 ：可以定义一些可变的部分，在运行的时候指定（将类型参数化，提高代码复用率，减少代码量）
        // 使用泛型可以最大限度地重用代码、保护类型的安全以及提高性能
        // Swift 中数组、Set、字典都是泛型集合
        
        // MARK:泛型问题引入
        // 引入：怎么定义一个函数来判断两个参数是否相等
        func isEqualsInt(a:Int,b:Int) ->Bool { // 比较两个整型参数是否相等
            return (a == b)
        }
        func isEqualsDouble(a:Double,b:Double) ->Bool { // 比较两个整型参数是否相等
            return (a == b)
        }
        func isEqualsString(a:String,b:String) ->Bool { // 比较两个整型参数是否相等
            return (a == b)
        }
        
        // 上面定义了三个函数来实现，能否只定义一个函数呢？
        
        //MARK: 泛型函数
        // 如果有多种类型，可以使用其他字母，一般习惯私使用字母U
        // 函数在每次调用的时候传入实际类型能决定T代表的类型
        // 并不是所有的类型都具有可比性，T必须遵守Comparable 协议的类型，在Swift中基本数据类型和字符串都遵从Comparable 协议的
        // T 后添加 : 和 协议类型，这种方式，称为泛型约束
        func isEquals<T:Comparable>(a:T,b:T) -> Bool {
            return (a == b)
        }
        
        let n1 = 200
        let n2 = 200
        
        let s1 = "ABC"
        let s2 = "ABC1"
        
        print(isEquals(a: n1, b: n2))
        print(isEquals(a: s1, b: s2))
        
        // 多类型参数
        // 上面的例子只使用了一种类型参数，事实上可以用时使用多种类型参数，需要提供多个占位符，使用逗号隔开
//        func isEquals<T,U>(a:T,b:U) ->Bool {....}
        // 占位符不仅可以替代参数类型，还可以替代返回值类型
//        func isEquals<T>(a:T,b:T)->T {...}
        
        //MARK:泛型类型
        // 泛型不仅仅可以使用在函数中，还可以运用在类、结构体和枚举等类型定义，这些类型就是泛型类型
        // 泛型类型一般都是与集合有关的类型，比如数组 字典 和 Set
        var strQueue = StringQueue()
        strQueue.queue(item: "A")
        strQueue.queue(item: "B")
        strQueue.queue(item: "C")
        print(strQueue.dequeue()!)
        
        //泛型优化后
        var genericQueue = Queue<Int>()
        genericQueue.queue(item: 1)
        genericQueue.queue(item: 2)
        genericQueue.queue(item: 3)
        genericQueue.queue(item: 4)
        
        print(genericQueue.dequeue()!)
        print(genericQueue.dequeue()!)
        print(genericQueue.dequeue()!)
        
        
        //MARK: 泛型扩展
        // 泛型扩展和普通扩展没区别
//        var genericDoubleQueue = Queue<Double>()
//        genericDoubleQueue.queue(item: 10)
//        genericDoubleQueue.queue(item: 20)
//        genericDoubleQueue.queue(item: 30)
//
//        print(genericDoubleQueue.peek(position: 0)!)
        
    }
}

// 泛型允许自定义泛型类型
// 泛型扩展
/*
struct Queue<T> {
    var items = [T]()
    
    mutating func queue(item:T) {
        items.append(item)
    }
    
    mutating func dequeue() ->T?{
        if items.isEmpty {
            return nil
        }else {
            return items.remove(at: 0)
        }
    }
}

extension Queue {
    func peek(position:Int) -> T? {
        if position < 0 || position > items.count {
            return nil
        } else {
            return items[position]
        }
    }
}
*/

// 泛型类型
// String 类型的结构体队列
struct StringQueue {
    var items  = [String]()
    
    mutating func queue(item:String) {
        items.append(item)
    }
    
    mutating func dequeue() -> String? {
        if items.isEmpty {
            return nil
        }else {
            return items.remove(at: 0)
        }
    }
}

// StringQueue 结构体队列 缺点只能存放 String 类型 ,使用泛型优化如下：
struct Queue<T> {
    var items  = [T]()
    
    mutating func queue(item:T) {
        items.append(item)
    }
    
    mutating func dequeue() -> T? {
        if items.isEmpty {
            return nil
        }else {
            return items.remove(at: 0)
        }
    }
}
