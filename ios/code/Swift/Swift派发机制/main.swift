//
//  main.swift
//  Swift派发机制
//
//  Created by WTW on 2022/3/4.
//  Copyright © 2022 WTW. All rights reserved.
//  https://www.jianshu.com/p/91bfe3f11eec

import Foundation

print("Hello, World!")

/*
 swift 和 OC 的区别：
                    Swift                           OC
 语言特性           静态语言，更加安全                动态语言不那么安全
 语法              更精简                          冗长
 命名空间           有                             无
 方法调用           直接调用/函数表调用/消息转发        消息转发
 元组/高阶函数       有                             无
 语言效率           性能更高，速度更快                 略低
 编程特性           更好的实现函数编程/响应式编程        面向对象编程

 
 常见的派发机制有4种：
  内联派发 (最快)
  静态派发(又称直接派发)：缺乏动态性，无法实现继承
  函数表派发
  动态派发 (最慢)
 由编译器决定使用哪种派发机制
 
 swift 和 OC 的派发机制：
    OC 的派发机制：
        默认支持动态派发机制(消息转发)，动态派发以一定的运行时开销为代价，提高了语言的灵活性；意味着动态派发机制下，每个方法的调用，编译器必须在方法列表中查找方法的实现
        编译器需要判断调用方是父类还是子类的实现，而且所有对象的内存都是在运行时分配的，因此编译器只能在运行时执行检查；
 
    swift 的派发机制：
        静态派发(直接派发)：编译的时候就知道某个方法调用某个实现，编译器会执行某些优化，甚至在可能的情况下会转化为内联函数，所以执行速度很快,(没办法支持继承）
        函数表派发：
        消息派发：

    如何在swift 中实现动态派发：
        要实现动态派发，可以使用继承和重写父类的方法，可以使用 dynamic 关键字，并且需要在@objc前加上关键字，以便将方法公开给OC的runtime 对象 (swift4 之后只需要 @objc 即可)；
        要实现静态派发，可以使用final 和 static 关键字，保证不会被覆写；
 
    静态派发：
        编译器可以在编译期定位到函数的位置。当函数被调用时，编译器能通过函数的内存地址，直接找到它的函数实现。这极大的提高了性能，可以到达类似inline的编译期优化。
    
    动态派发：
        在运行时而不是编译时查找实现方法；之所以用他是因为灵活性，实际上大多数 OOP 语言都支持动态派发，因为动态派发允许多态；
        动态派发有两种方式：
            函数表派发：
                这种方式利用一个表，该表存储的是类声明的每个函数的指针(大部分语言叫虚函数表，swift叫witness table)，以查找特性方法的实现
                     每个子类都有它自己的表结构，记录着类的所有的函数，如果父类函数被 override 的话, 表里面只会保存被 override 之后的函数
                     当子类添加新方法时，这些方法指针会添加在表数组的末尾
                     最后，运行时使用此表来查找调用函数的实现
                由于编译器必须从表中读取方法实现的内存地址，然后跳转到该地址，因此它需要两条附加指令，因此它比静态分派慢，但仍比消息分派快。
            消息派发：
                这种派发方式是最动态的的方式，开发者可以在运行时改变函数的行为
 
 */


//MARK: - 函数表派发
/*
 函数表派发：
 编译器会创建两个函数表，一个是 ParentClass，另外一个是 ChildClass
 
 offset
              0xA00  ParentClass     0xB00  ChildClass
  0           0x121  method1         0x121  method1
  1           0x122  method2         0x222  method2
  2                                  0x223  method3
 */
class ParentClass {

    func method1(){}
    func method2(){}
}

class ChildClass: ParentClass {
    
    override func method2() {}
    func method3() {}
}

/// 调用过程
/// 1、读取对象 0xB00 的函数表
/// 2、读取函数指针的索引，在这里, method2 的索引是1(偏移量), 也就是 0xB00 + 1.
/// 3、跳到 0x222 (函数指针指向 0x222)
///
/// 这种方式还是比直接派发慢一点，多了两次读和一次跳转，因此带来性能损耗
/// 另外一个满的原因：编译器可能会由于函数内执行的任务导致无法优化(如果函数带有副作用的话)
///
/// 缺陷：函数表无法扩展，子类只会在虚函数表的最后插入新的函数，没有位置可能让extension安全地插入函数
let obj = ChildClass()
obj.method2()


// MARK: - 消息派发
/*
 消息派发机制：
 运作方式的关键在于开发者可以在运行时改变函数的行为.
 不止可以通过 swizzling 来改变, 甚至可以用 isa-swizzling 修改对象的继承关系, 可以在面向对象的基础上实现自定义派发.

 对于上面的继承结构，Swift 会用树来构建这种继承关系：
    
        ParentClass
        super        <--------
 0x121  method1               |
 0x122  method2               |            ChildClass
                              ----------   super
                                   0x222   method2
                                   0x223   method3

     当一个消息被派发, 运行时会顺着类的继承关系向上查找应该被调用的函数.
     如果你觉得这样做效率很低, 它确实很低! 然而, 只要缓存建立了起来, 这个查找过程就会通过缓存来把性能提高到和函数表派发一样快.
 */

// MARK: - Swift 的派发机制
/*
 swift 的派发方式与四个因素有关系：
     声明的位置
     引用类型: 值类型都会采用直接派发
     特定的行为
     Swift 的显示优化
 
        类型           类型声明作用域     extension
    Value Type          static          static
    Protocol            table           static
    Class               table           static
    NSObject class      table           Message
 */

// 声明的位置
// 在Swift 中一个函数有两个可以声明的位置，类的声明作用域 和 extension ,声明位置不同派发方式也不同:
class MyClass {
    func mainMethod(){}  // 函数表派发
}

extension MyClass {
    func extensionMethod(){}  // 静态派发
}

// 引用的类型
protocol MyProtocol { }
struct MyStruct: MyProtocol { }

extension MyStruct {
    func extensionMethod() {
        print("结构体")
    }
}
extension MyProtocol {
    func extensionMethod() {
        print("协议")
    }
}
 
let myStruct = MyStruct()
let protcol: MyProtocol = myStruct
 
myStruct.extensionMethod() // -> “结构体”
protcol.extensionMethod() // -> “协议”

// 指定派发方式 （swift 中的修饰符可以指定派发方式）
/*
final 允许类里面的函数使用直接派发。
dynamic 可以让类里面的函数使用消息机制派发。
@objc 和 @nonobjc 显示声明一个函数能否被 Objective-C 的运行时捕获到。
@inline 告诉编译器可以使用直接派发
*/

// swift 的显示优化：
/*
 https://developer.apple.com/swift/blog/?id=27
 比如一个函数没有 override ，swift 就会检查并且在可能的情况下就使用直接派发；
 比如target/action 的使用 @objc 和 dynamic
 如果 没有 @objc dynamic 的话，这个优化默认让KVO 失效，如果一个对象的属性绑定了KVO 的话，那么 setter 和 getter 会被优化为直接派发，代码依旧可以通过编译，但是动态生成的KVO 函数就不会被触发
 */

//let btn = UIButton()
//btn.addTarget(self, action: #selector(btnClick), for: .touchUpInside)
//@objc func btnClick(){   //  必须加上@objc 或者 dynamic
//    print(" ==== btnClick ==== ")
//}

// MARK: - 静态语言 动态语言


