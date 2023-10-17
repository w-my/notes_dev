//
//  main.swift
//  POP
//
//  Created by WTW on 2021/4/25.
//  Copyright © 2021 Mac. All rights reserved.
//



import Foundation

// MARK: 面向协议编程

// 字符串中数字的个数
let str = "abc123456"

// 全局函数
//func numberCount(_ str:String) -> Int {
//
//
//    var count = 0
//
//    for item in str where ("0"..."9").contains(item) {
//        count += 1
//    }
//
//    return count
//}
//print(numberCount(str))

// 扩展方法或者计算属性
//extension String {
//
//    func numberCount() -> Int {
//
//        var count = 0
//
//        for item in self where ("0"..."9").contains(item) {
//            count += 1
//        }
//
//        return count
//    }
//
//    var numberCount1: Int  {
//
//        var count = 0
//
//        for item in self where ("0"..."9").contains(item) {
//            count += 1
//        }
//
//        return count
//    }
//}
//
//print(str.numberCount())
//print(str.numberCount1)

// 前缀的方式
//struct MJ {
//
//    var string: String
//
//    init(_ string: String) {
//        self.string = string
//    }
//
//    var numberCount: Int {
//
//        var count = 0
//
//        for item in string where ("0"..."9").contains(item) {
//            count += 1
//        }
//
//        return count
//    }
//}
//
//extension String {
//
//    var mj: MJ { return MJ(self) }
//}
//
//print(str.mj.numberCount)


// 抽取base 泛型
//struct MJ<Base> {
//
//    var base: Base
//    init(_ base: Base) {
//        self.base = base
//    }
//}
//
//extension String {
//
//    // 实例属性
//    var mj: MJ<String> { return MJ(self) }
//
//    // 类属性
//    static var mj: MJ<String>.Type { return MJ<String>.self }
//}
//
//// 给类添加方法或者计算属性
//extension MJ where Base == String {
//
//    // 扩展计算属性
//    var numberCount: Int {
//        var count = 0
//
//        for item in base where ("0"..."9").contains(item) {
//            count += 1
//        }
//        return count
//    }
//
//    // 扩展方法
//    func test()  {
//        print("===test() 实例方法====")
//    }
//
//    // 扩展类方法
//    static func Test() {
//        print("===Test() 类方法====")
//    }
//}
//
//print(str.mj.numberCount)
//print(str.mj.test())
//print(str.mj)
//print(String.mj.Test())


// 最终通过协议来实现
// 1、定义前缀
//struct MJ<Base> {
//
//    var base: Base
//    init(_ base: Base) {
//        self.base = base
//    }
//}
//
//// 2、利用协议扩展前缀
//protocol MJCompatible {}
//extension MJCompatible {
//
//    // 实例属性
//    var mj:MJ<Self> {
//        set {}
//        get { MJ(self) }
//    }
//
//    // 类属性
//    static var mj:MJ<Self>.Type {
//        set {}
//        get { MJ<Self>.self }
//    }
//}
//
//// 3、扩展前缀
//extension String : MJCompatible {}
//extension Array: MJCompatible {}
//
//
////4、 String 中使用
//extension MJ where Base == String {
//
//    // 扩展计算属性
//   var numberCount: Int {
//       var count = 0
//
//       for item in base where ("0"..."9").contains(item) {
//           count += 1
//       }
//       return count
//   }
//
//   // 扩展方法
//   func test()  {
//       print("===test() 实例方法====")
//   }
//
//   // 扩展类方法
//   static func Test() {
//       print("===Test() 类方法====")
//   }
//}
//
//print(str.mj.numberCount)
//print(str.mj.test())
//print(str.mj)
//print(String.mj.Test())
//
//// MARK: Swift关联对象 给扩展添加存储属性 (Associated Object)
//// 只有 class 才可以使用关联对象，默认情况下扩展是不可以添加存储属性的
//class Person { }
//extension Person {
//
//    static var K_AGE_KEY: Void?
//    var age: Int {
//
//        get {
//            (objc_getAssociatedObject(self, &Self.K_AGE_KEY) as? Int) ?? 0
//        }
//
//        set {
//            objc_setAssociatedObject(self, &Self.K_AGE_KEY, newValue, .OBJC_ASSOCIATION_ASSIGN)
//        }
//    }
//}
//
//var p = Person()
//p.age = 10000
//print(p.age)

protocol RandomNumberGenerator {
    func random() -> Double
}

// MARK: 协议作为类型使用
class Dice {
    
    let sides: Int
    let generator: RandomNumberGenerator
    // 初始化器中传入任意一个实现了RandomNumberGenerator协议的实例
    init(sides:Int,generator:RandomNumberGenerator) {
        self.sides = sides
        self.generator = generator
    }
    
    func roll() -> Int {
        return Int(generator.random() * Double(sides)) + 1
    }
    
}
