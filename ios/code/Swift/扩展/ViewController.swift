

//
//  ViewController.swift
//  扩展
//
//  Created by WTW on 2020/1/20.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        // MARK: 概念
        // 扩展，OC 中称为类别 (Category)
        // 虽然可以通过继承从父类继承一下方法和属性，在子类添加一些方法和属性，这样就可以达到增强功能的新类了，但是继承过程比较繁琐，类继承可能被禁止，有些功能继承就无法实现。
        // Swift 中类扩展，在原始类型(类、结构体和枚举)的基础上添加新功能，扩展是一种轻量级的”继承机制“，即使原始类被限制继承，仍然可以通过扩展机制”继承“原始类型的功能。
        // 扩展的另外一个优势，它扩展的类型可以是类、结构体、枚举。而继承只能是类，不能是结构体和枚举。
        // 开发中优先考虑扩展机制是否能够满足需求，不能再考虑继承机制。
        
        
        /* 声明扩展
        extension 类型名 {
            // 添加新功能
        }
        */
        
        // 也可以扩展整型、布尔、浮点型、字符串等基本数据类型(因为基本数据类型本质上还是结构体类型)
        /*
        Swift 中的扩展机制可以在原始类中添加新功能包括：
         1、实例计算属性和静态计算属性 (还可以定义读写计算属性，但是不能定义存储属性)
         2、实例方法和静态方法
         3、构造函数
         4、下标
         嵌套类型也可以扩展，扩展还可以遵从协议
         */
        
        // MARK: 扩展计算属性 和 静态属性
        
        // 扩展计算属性
        let message = (-7).errorMeaasage
        print("Error Message :\(message)")
        
        // 扩展静态属性
        print(Account.interestRate)
        
        
        // MARK: 扩展实例方法和静态方法
        let interest1 = (10000.00).interestBy1()
        print("利息1:\(interest1)")
        
        var interest2 = 10000.00
        interest2.interestBy2()  // 调用可变方法
        print("利息2：\(interest2)")
        
        var interest3  = Double.interestBy3(amount: 10000)  // 调用静态方法
        print("利息3：\(interest3)")

        
        // MARK:扩展构造函数
        // 值类型和引用类型有所区别。值类型包括了除类以外的其他类型，主要是枚举类型和结构类型
        
        // 值类型扩展构造函数
        var rect = Rectangle(width: 320, height: 480)
        print("长方形 ： \(rect.width) * \(rect.height)")
        
        var square = Rectangle(length: 500)
        print("正方形 ： \(square.width) * \(square.height)")

        // 引用类型扩展构造函数
        // 引用类型只包含一个类型，即类的类型
        // 能向类中添加新的便利构造函数，但是不能添加新的指定构造函数或析构函数，指定构造函数和析构函数只能由原始类提供
        let p1 = Person(name: "xiaoli")
        print("Person1: \(p1.desc())" )
        let p2 = Person(name: "xiaohua", age: 10)
        print("Person2: \(p2.desc())")
        
        // MARK:扩展下标
        // 下标可以认为是特殊的属性，可以实现索引访问属性
        let s = "The quick brown fox jumps over the lazy dog"
        print(s[0])
        print("ABC"[2])
        
    }
}

// 扩展下标
// 字符串本身没有提供下标访问字符的功能
extension String {
    subscript(index:Int) ->String {  // 定义下标
        if index > self.characters.count {  // 判断是否越界
            return ""
        }
        var c : String = ""
        var i = 0
        
        for character in self.characters {
            if(i == index){
                c = String(character)
                break
            }
            i+=1
        }
        return c
    }
}


// 扩展构造函数 (引用类型构造函数)
class Person {
    var name : String
    var age : Int
    func desc() -> String {
        return "\(name) 年龄是 \(age)"
    }
    init(name:String,age:Int) {
        self.name = name
        self.age = age
    }
}
extension Person {
    convenience init(name: String) {
        self.init(name: name, age: 8)
    }
}

// 扩展构造函数(值类型的扩展构造函数)
struct Rectangle {
    var width : Double
    var height: Double
    
    init(width:Double,height:Double) {
        self.width = width
        self.height = height
    }
}
extension Rectangle {
    init(length:Double) {
        self.init(width:length,height:length)
    }
}

// 扩展实例方法和静态方法
extension Double {
    static var interestRate:Double = 0.068  // 静态属性
    func interestBy1() -> Double {  // 实例方法
        return self * Double.interestRate
    }
    mutating func interestBy2(){    // 实例方法 无返回值 （mutating代表可变方法，避免枚举和结构体类型报错）
        self = self * Double.interestRate
    }
    static func interestBy3(amount:Double)->Double {    // 静态方法
        return interestRate * amount
    }
}




struct Account {
    var amount : Double = 0.0
    var owner : String = ""
}
// 扩展静态属性
extension Account {
    static var interestRate : Double {  //  interestRate 汇率，对所有的账户都是一样的，所以定义为静态属性
        return 0.068
    }
}

// 扩展计算属性
extension Int { // Int 类型扩展
    var errorMeaasage : String {  // 定义只读计算属性
        var errorStr = ""
        switch self {   // self 代表当前实例
        case -7:
            errorStr = "没有数据"
        case -6:
            errorStr = "日期没有输入"
        case -5:
            errorStr = "内容没有输入"
        case -4:
            errorStr = "ID 没有输入"
        case -3:
            errorStr = "数据访问失败"
        default:
            errorStr = ""
        }
        return errorStr
    }
}
