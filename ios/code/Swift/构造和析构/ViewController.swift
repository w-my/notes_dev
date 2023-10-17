//
//  ViewController.swift
//  构造和析构
//
//  Created by WTW on 2020/1/20.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        // 结构体 和 类 在创建实例的过程中需要进行一些初始化工作，这个过程就叫 构造过程
        // 相反，这些实例最后被释放的时候需要进行一些清除资源的工作，这个过程叫做 析构过程
        
        // MARK:- 构造函数
        // init 方法 ，称为构造函数 ，没有返回值 (区别于OC的init是有返回值的)
        // 可以重载，在多个构造函数重载的情况下，运行环境根据参数标签或参数列表调用合适的构造函数
        
        // 1、默认构造函数
        /*
        class/struct Rectangle {
            var width:Double = 0.0
            var height:Double = 0.0
        }
        
        // 省略了默认构造函数
//        init(){
//
//        }
        
        var rect = Rectangle()
        rect.width = 320
        rect.height = 480
        
        print(rect.width,rect.height)
        */
        
        
        // 2、构造函数与存储属性初始化
        // 构造函数的主要作用就是初始化实例(初始化存储属性和其他的初始化)
        // 如果存储属性在构造函数中没有初始化，在定义的时候也没有初始化，就会编译报错
        // 计算属性不保存数据，所以不需要初始化
        // 构造函数也不能初始化静态属性，因为静态属性与实例个体无关
        // 构造函数还可以初始化常量存储属性
        /*
        class Rectangle{
            var width:Double
            var height:Double
            
            init() {
                width = 0.0
                height= 0.0
            }
        }
         */
        
        
        // 3、使用参数标签
        // 构造函数可以使用参数标签，构造函数的参数标签要比一般方法和函数更有意义
        // 由于构造函数命名都是init 如果一个类型中有多个构造函数，可通过不同的参数标签来区分调用的构造函数
        /*
        class RectangleA {
            var width:Double
            var height:Double
            
            init(W width:Double,H height:Double) {
                self.width = width
                self.height = height
            }
        }
        
        let recta = RectangleA(W: 320, H: 480)
        
        //构造函数中参数可以直接当标签使用
        class RectangleB {
            var width:Double
            var height:Double
            
            init( width:Double, height:Double) {
                self.width = width
                self.height = height
            }
        }
        
        let rectb = RectangleB(width: 320, height: 480)
        
        // 以下写法仅仅适用于结构体类型
        // 使用默认的构造函数，调用的时候可以指定参数标签，结构体类型可以按照从上到下的顺序把属性名作为参数标签，依次提供参数
        // 类中不能这样写
        struct Rectangle {
            var width:Double = 0.0
            var height:Double = 0.0
        }
        
        let rect = Rectangle(width: 320, height: 480)
        */
                
        // MARK:-构造函数重载
        // 构造函数可以有多个，参数列表不同，这些构造函数构成重载
        /*
        class Rectangle {
            var width:Double
            var height:Double
            
            init(width:Double,height:Double) {
                self.width = width
                self.height = height
            }
            
            init(W width:Double,H height:Double) {
                self.width = width
                self.height = height
            }
            
            init() {
                self.width = 320
                self.height = 480
            }
        }
         */
        
        // MARK: 值类型初始化器委托
        // 体构造函数代理：为了减少构造函数间的代码重复，在定义构造函数时可以通过调用其他构造函数来完成实例的部分构造过程
        // 构造函数代理在类 和 结构体中使用的方法不一样
        /*
        struct Rectangle {
            var width:Double
            var height:Double
            
            init(width:Double,height:Double) {
                self.width = width
                self.height = height
            }
            
            init(W width:Double,H height:Double) {
                self.width = width
                self.height = height
            }
            
            init(length:Double) {
                self.init(W:length,H:length)
            }
            
            init() {
                self.init(width:640,height:940)
            }
        }
        */
        
        // 类构造函数横向代理
        // 由于类有继承关系,类构造函数代理比较复杂，分为 横向代理 和 向上代理
        // 横向代理：类似结构体类型构造函数代理，发生在同一类内部，这种构造函数称为 便利构造函数
        // 向上代理：是发生在继承情况下，在子类构造的过程中要先调用父类构造函数，初始化父类的存储属性，称为指定构造函数(示例见类继承)
        
        // 便利构造函数示例
        /*
        class Rectangle {
            var width:Double
            var height:Double
            
            init(width:Double,height:Double) {
                self.width = width
                self.height = height
            }
            
            init(W width:Double,H height:Double) {
                self.width = width
                self.height = height
            }
            
            // convenience 关键字，表示便利构造函数
            convenience init(length:Double) {
                self.init(W:length,H:length)
            }
            
            convenience init() {
                self.init(width:640,height:940)
            }
        }
         */
        
        // MARK: 析构函数
        // 析构过程会调用一种特殊的方法 deinit ，没有返回值，没有参数
        // 析构函数只适用于类，不适用于 结构体 和 枚举
        class Rectangle {
            var width:Double
            var height:Double
        
            init(width:Double,height:Double) {
                self.width = width
                self.height = height
            }
            
            init(W width:Double,H height:Double) {
                self.width = width
                self.height = height
            }
            
            deinit {
                print("调用析构函数")
                self.width = 0.0
                self.height = 0.0
            }
        }
        
        var rect : Rectangle? = Rectangle(W: 320, H: 480)
        print(rect!.width,rect!.height)
        rect = nil
        
        // 只有可选类型才能被赋值为 nil
        // 析构函数的调用是使实例被赋值为nil 表示实例需要释放内存
        // 在释放之前先调用析构函数，然后再释放
    }


}

