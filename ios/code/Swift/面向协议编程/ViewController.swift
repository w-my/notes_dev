//
//  ViewController.swift
//  面向协议编程
//
//  Created by WTW on 2020/7/21.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class Person {}

// 需求:计算字符串中数字的个数
let str = "123abcdef89"

// MARK: 常规写法1 提供一个全局函数
/*
 func numberCount(_ str: String) -> Int {
     
     var count = 0
     
     for item in str where ("0"..."9").contains(item) {
         count += 1
     }
     
     return count
 }
 */

// MARK: 常规写法 2 给字符串提供一个分类
/*
 extension String {
     
     func numberCount() -> Int {
         
         var count = 0
         
         for item in self where ("0"..."9").contains(item) {
             count += 1
         }
         
         return count
     }
     
 }
 
 // 还可以写成计算属性的形式
 extension String {
     
     var numberCount: Int {
         
         var count = 0
         
         for item in self where ("0"..."9").contains(item) {
             count += 1
         }
         
         return count
     }
     
 }
 */

// MARK: 写法3 尝试实现前缀的方式
// 可以避免分类方法或者计算属性覆盖父类的方法或者属性，实现类似OC的前缀的方式
// print(str.mj.numberCount)
/*
 struct MJ {

     var string: String

     init(_ string: String){
         self.string = string
     }

     // 计算属性
     var numberCount: Int {

         var count = 0

         for c in string where ("0"..."9").contains(c){
             count += 1
         }

         return count
     }

 }

 // 给字符串扩充 mj 属性 (计算属性)
 // MJ(self) 返回的是一个 MJ 实例
 extension String {
    
     var mj: MJ { return MJ(self) }
 }
 */

// MARK: 如果也想给除了 String 之外的类扩展，实现以上类似的功能时，就需要用到泛型
// 三步实现

/*
struct MJ<Base> {

    var base: Base
    init(_ base: Base) {
        self.base = base
    }
}

// 对不同的类进行扩展
// 对 String 类型进行扩展 mj 属性
extension String {
    // 实例属性
    var mj: MJ<String> { MJ(self) }
    // 类属性
    static var mj: MJ<String>.Type { MJ<String>.self }
}

// 对Array 类型进行扩展 mj 属性
extension Array {
    var mj: MJ<Array> { MJ(self) }
}

// 对Person 类扩展 mj 属性
extension Person {
    var mj: MJ<Person> { MJ(self) }
}

// 给类添加方法或者计算属性 通过给 MJ 添加扩展来实现
extension MJ where Base == String {

    var numberCount: Int {

        var count = 0
        for c in base where ("0"..."9").contains(c){
            count += 1
        }

        return count
    }

    mutating func run() {}

    // 扩展类方法
    static func test(){
        print("String 的类方法")
    }
}

extension MJ where Base == Array<Any> {

    func run() {
        print("run")
    }
}

// 不要用等号 因为等号表示只是Person
// : 表示Person 子类也拥有此扩展的方法或者属性
extension MJ where Base: Person {
    
    func run() {
        
        print("person run")
    }
}

*/

// MARK: 上面方式可以使用协议来优化
// 三步走

// 1、前缀类型
struct MJ<Base> {

    var base: Base
    init(_ base: Base) {
        self.base = base
    }
}

// 2、利用协议扩展前缀属性
/// 为了能够使用 mutating 必须要加上 set
protocol MJCompatible { }
extension MJCompatible {
    // 实例属性
    var mj: MJ<Self> {
        set {}
        get { MJ(self) }
    }
    // 类属性
    static var mj: MJ<Self>.Type {
        set {}
        get { MJ<Self>.self }
    }
}

// 3、给字符串扩展功能 让String 拥有mj 前缀属性
extension String: MJCompatible { }
extension NSString: MJCompatible { }

extension Array: MJCompatible { }

extension Person: MJCompatible{ }

// 4、给 String.mj 前缀扩展功能
//extension MJ where Base == String {
//
//    var numberCount: Int {
//
//        var count = 0
//        for c in base where ("0"..."9").contains(c){
//            count += 1
//        }
//
//        return count
//    }
//
//    mutating func run() {
//        print("String run")
//    }
//
//    // 扩展类方法
//    static func test(){
//        print("String 的类方法")
//    }
//}

// 考虑到 NSString NSMutableString 和 String
extension MJ where Base: ExpressibleByStringLiteral {

    var numberCount: Int {

        var count = 0
        for c in (base as! String) where ("0"..."9").contains(c){
            count += 1
        }

        return count
    }

    mutating func run() {
        print("String run")
    }

    // 扩展类方法
    static func test(){
        print("String 的类方法")
    }
}


//struct Dog { }
//extension Dog: MJCompatible {}


class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
    }

    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
       
        // 常规写法1 调用
//        print(numberCount(str))
        
        // 常规写法2 调用
//        print(str.numberCount()) // 函数的形式
//        print(str.numberCount)  // 计算属性的形式
           
        //  写法3 尝试实现前缀的方式
//        print(str.mj.numberCount)
        
                
//        let person = Person()
//        person.mj.run()
//
//        String.mj.test()
//
//        // 实例调用
//        print("1234,,,,,889jjj".mj.numberCount)
        
        
        // 最终方案使用协议来实现
        
//         str.mj.run() // mutating 必须不能是常量
        var str1 = "hello"
        str1.mj.run()
        
        print(str.mj.numberCount)
        String.mj.test()
      
    }
}

