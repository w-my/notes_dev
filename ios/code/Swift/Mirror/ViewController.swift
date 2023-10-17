//
//  ViewController.swift
//  反射机制 Mirror
//
//  Created by WTW on 2020/5/24.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit
import Foundation

struct Person {
    var age: Int = 0
    var name: String = ""
}

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        //MARK:- 根据字符串创建对象
        let cls = NSClassFromString("ViewController")
        // Mirror 即为命名空间
        print(self)  // <Mirror.ViewController: 0x7fa9bfd10ef0>
        print(cls) // nil  这样是反射不出来的
        
        // 获取命名空间
        guard let nameSpace = Bundle.main.infoDictionary!["CFBundleExecutable"] as? String else { return }
        print(nameSpace) // Mirror
        // 字符串对应的class
        guard let cls2 = NSClassFromString(nameSpace +  "." + "ViewController") else { return }
        // 获取对应的控制器类型
        guard let vcType = cls2 as? UIViewController.Type else { return }
        // 获取对应的控制器实例
        let vcCalss = vcType.init()
        print(cls2,vcType,vcCalss)  // ViewController ViewController <Mirror.ViewController: 0x7ffdd3c77940>
        
        
        // MARK: - swift 指针
        // https://www.cnblogs.com/qianxiaox/p/13754848.html
        // https://www.jianshu.com/p/123d62cfb608
        /**
         typed pointer 指定数据类型指针
         raw pointer 未指定数据类型指针(原生指针)
         */
        
        // 分配内存
        // sizeof_sfntInstance 由系统决定实例对象占用多大内存j空间
        let a = UnsafeMutablePointer<Int>.allocate(capacity: sizeof_sfntInstance)
//        print(sizeof_sfntInstance)  // 4
        
        // 初始化
        // 对于 Int Float Double 这些基本数据类型可以不进行 initialize 操作，因为分配内存之后会有默认值 0
        // 对于引用类型，必须进行 initialize 操作，才能在内存中写入值，否者编译器报错
        a.initialize(to: 10)
        
        // 设置值
        // 每一个 Pointer 对象都有一个属性 pointee 可以通过这个属性直接获取指针指向内存中的值
        a.pointee = 10
//        print(a.pointee)  // 10
        
        // 释放内存
        // 有分配内存，最好在不需要的时候释放掉
        a.deallocate()
        
        /*
        let mirror = Mirror(reflecting: Person(age: 10, name: "Jack"))
        print(mirror.displayStyle!)   // struct
        print(mirror.subjectType)  // Person
        print(mirror.superclassMirror as Any)  // nil
        for case let (label?, value) in mirror.children {
            print(label,value)
        }
        /*
         age 10
         name Jack
         */
        */
 
        // 常见4种类型
        // UnsafePointer<Pointee> 类似 const Pointee *
        // UnsafeMutablePointer<Pointee> 类似 Pointee *
        // UnsafeRawPointer 类似 const void *   不支持泛型
        // UnsafeMutableRawPointer 类似 void *  不支持泛型
        
        /*
        var age = 10
        func test1(_ ptr: UnsafeMutablePointer<Int>) {
            // 通过访问 pointee属性，获取 ptr 指针的内存地址所存储的值
            ptr.pointee += 10
        }
        
        func test2(_ ptr: UnsafePointer<Int>) {
            print(ptr.pointee) // 20
        }
        
        test1(&age)
        test2(&age)
        print(age) // 20
         
         
         NSArray().enumerateObjects(<#T##block: (Any, Int, UnsafeMutablePointer<ObjCBool>) -> Void##(Any, Int, UnsafeMutablePointer<ObjCBool>) -> Void#>)
         UnsafeMutablePointer<ObjCBool> 就类似 OC 中的 * stop
        */
        
        // MARK: 获取指向某个变量的指针
        /*
        var age = 11
        // ptr1 类型为 UnsafeMutablePointer<Int> 实际上就是一个指向age变量的指针
        // func withUnsafePointer<T, Result>(to value: T, _ body: (UnsafePointer<T>) throws -> Result) rethrows -> Result
        // withUnsafePointer 的返回值实际上即闭包的返回值
        // ptr1 ptr2 都是泛型指针
        var ptr1 = withUnsafeMutablePointer(to: &age) { $0 }
        var ptr2 = withUnsafePointer(to: &age) { $0 }
        
        print(ptr1,ptr2)  // 0x00007ffee8783fb8 0x00007ffee8783fb8
        
        ptr1.pointee = 22
        print(ptr2.pointee) // 22
        print(age) // 22
        
        // ptr3 ptr4 返回的为非泛型指针
        var ptr3 = withUnsafeMutablePointer(to: &age) { UnsafeMutableRawPointer($0) }
        var ptr4 = withUnsafePointer(to: &age) { UnsafeRawPointer($0) }
        
        ptr3.storeBytes(of: 33, as: Int.self)
        print(ptr4.load(as: Int.self)) // 33
        print(age) // 33
        */
        
        // MARK: 获取指向堆空间实例的指针
        // 用来生成指向某一地址的指针
        //var ptr = UnsafeRawPointer(bitPattern: 0x100000000)
        /*
        class Person {
            var age: Int
            init(age:Int) {
                self.age = age
            }
        }
        var person = Person(age: 20)  //类似 *p = person
        // p = &person  p 是 person变量地址值
        var ptr = withUnsafePointer(to: &person) { UnsafeRawPointer($0)}
        // ptr.load(as: UInt.self) 类似 *p ,取出地址中存储的值，也即是Person 实例在堆上的地址值
        var heapPtr = UnsafeRawPointer(bitPattern: ptr.load(as: UInt.self))
        print(heapPtr!)
        
//        // 也可以验证 ptr1.pointee 等同于 person
//        var ptr1 = withUnsafePointer(to: &person) { $0 }
//        ptr1.pointee.age = 30
//        person.age = 40
//        print(person.age)
        */
        
        
        // MARK: 创建指针
        // 需要 import Foundation
        
        /*
        // 方式1
        // 创建
        //malloc 返回值为 UnsafeMutableRawPointer
        var ptr = malloc(16)
        
        // 存
        ptr?.storeBytes(of: 11, as: Int.self)  // 存储在前8个字节
        ptr?.storeBytes(of: 22, toByteOffset: 8, as: Int.self) // 存储在后8个字节
        
        // 取
        print(ptr?.load(as: Int.self)) // 11
        print(ptr?.load(fromByteOffset: 8, as: Int.self))  // 22
        
        // 销毁
        free(ptr)
        */
        
        /*
        // 方式2
        // 创建
        var ptr = UnsafeMutableRawPointer.allocate(byteCount: 16, alignment: 1)
        
        // 存
        ptr.storeBytes(of: 11, as: Int.self)
        ptr.advanced(by: 8).storeBytes(of: 22, as: Int.self)  // 偏移8字节
        
        // 取
        print(ptr.load(as: Int.self))  // 11
        print(ptr.advanced(by: 8).load(as: Int.self)) // 22
        
        // 销毁
        ptr.deallocate()
         */
        
        /*
        // 方式 3
        var ptr = UnsafeMutablePointer<Int>.allocate(capacity: 3)
         
        ptr.initialize(to: 11)
        ptr.successor().initialize(to: 22)  // 下一个8字节
        ptr.successor().successor().initialize(to: 33)
        
        print(ptr.pointee)  // 11
        print((ptr+1).pointee) // 22
        print((ptr+2).pointee) // 33
        
        print(ptr[0]) // 11
        print(ptr[1]) // 22
        print(ptr[2])  // 33
        
        ptr.deinitialize(count: 3)  // 初始化多少个，必须销毁多少个
        ptr.deallocate()
         */
        
        // MARK: 指针之间的转换
        /*
        var ptr = UnsafeMutableRawPointer.allocate(byteCount: 16, alignment: 1)
        ptr.assumingMemoryBound(to: Int.self).pointee = 11
        (ptr+8).assumingMemoryBound(to: Double.self).pointee = 22.0
        
        // 只改变类型不改变值
        print(unsafeBitCast(ptr, to: UnsafePointer<Int>.self).pointee)  // 11
        print(unsafeBitCast(ptr + 8, to: UnsafePointer<Double>.self).pointee) // 22.0
        ptr.deallocate()
        */
        
        // unsafeBitCast 忽略数据类型的强制转换，不会因为数据类型的变化而改变原来的内存
        // 类似于C++ 中的 reinterpret_cast
        /*
        class Animal {}
        var animal = Animal()
        var ptr = unsafeBitCast(animal, to: UnsafeRawPointer.self)
        print(ptr) // 0x00006000016105c0
         */
    }
}

