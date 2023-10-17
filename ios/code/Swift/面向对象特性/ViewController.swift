//
//  ViewController.swift
//  面向对象特性
//
//  Created by WTW on 2020/1/20.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        // MARK:- 概念
        // 封装 继承 多态
        // 封装:尽可能隐蔽对象的内部细节，对外形成一个边界，只保留有限的对外接口使之与外部发生联系
        // 继承：一些特殊类能够具有一般类的全部属性和方法，称为特殊类对一般类的继承
        // 多态：父类中定义的属性或者方法被子类继承之后，可以使用同一属性或同一方法在父类及其子类中具有不同含义
        
        // MARK: Swift 面向对象
        // 在 C++ 和 Java 等语言中，面向对象的数据类型只有类，但是Swift中 类、结构体、枚举 都具有面向对象的特征(其他语言是没有的)
        // 类的实例化结果是实例，也称为对象，但是结构体和枚举实例一般不称为对象，因为不是彻底的面向对象类型，而只是包含了一些面向对象的特点
        // 比如结构体和枚举不能继承
        
        //MARK:- 结构体和类
        // Swift 把结构体作为实现面向对象的重要手段，Swift 中的结构体和C++ 和 OC 中的结构体差距比较大
        // C++ 和 OC 结构体只能定义一组相关的成员变量，而Swift 中的结构体不仅可以定义成员变量(属性)，还可以定义成员方法，可以看做一种轻量级的类
        // Swift 中绝大多数的公开类型都是结构体，枚举和类只占很小一部分
        
        // Swift 中的类和结构体非常类似，都具有定义和使用属性 方法  下标 和 构造函数等面向对象的特性，
        // 区别：结构体不具有继承性，也不具备运行时强制类型转换、使用析构函数和使用引用计数等能力 (结构体是值类型，类是引用类型)
        
        //MARK:结构体
        // 所有的结构体都有一个编译器自动生成的初始化器 (initialzer,初始化方法,构造器,构造方法)
        struct Date {
            var year: Int
            var month: Int
            var day: Int
        }
        // 结构体 可以传入所有的成员值，用以初始化所有成员 默认的初始化方法
        //let date = Date(year: <#T##Int#>, month: <#T##Int#>, day: <#T##Int#>)
       
        // 编译器也会根据情况，为结构体生成多个初始化器,保证所有成员都有初始值
        struct Point {
            var x: Int
            var y: Int
        }
        struct Point1 {
            var x: Int = 0
            var y: Int
            var z: Int
        }
        //Point(x: <#T##Int#>, y: <#T##Int#>)
        //Point1(x: <#T##Int#>, y: <#T##Int#>, z: <#T##Int#>)
        //Point1(y: <#T##Int#>, z: <#T##Int#>)
        
        
        // 以下情况一样能编译通过
        // 因为可选项有个默认值是 nil
        struct Point2 {
            
            var x: Int?
            var y: Int?
        }
        var p1 = Point2(x: 10, y: 10)
        var p2 = Point2(x: 10)
        var p3 = Point2(y: 10)
        var p4 = Point2()
        
        // 在定义结构体时，自定义了初始化器，系统就不会再帮他自动生成其他初始化器
        struct Point3 {
            var x: Int
            var y: Int
            
            init(x: Int,y: Int) {
                self.x = x
                self.y = y
            }
        }
        //var p31 = Point3(x: 10, y: 10)
        //var p32 = Point3(x: 10)  报错
        //var p33 = Point3(y: 10)  报错
        // var p34 = Point3()      报错
        
        
        // MARK: 类
        // 类和结构体类似，但是编译器并没有为类生成可以传入成员值的初始化器
        // 以下两种方式是等价的
        class CPoint {
            var x: Int = 10
            var y: Int = 20
        }
        class CPoint1 {
            var x: Int
            var y: Int
            init() {
                x = 10
                y = 20
            }
        }
        
        // MARK: 类 和 结构体 的定义
        /*
        class 类名 {
            定义类的成员
        }
         
        struct 结构体名 {
            定义结构体的成员
        }
         */
        
        class Employee {  // 员工类
            var no:Int = 0
            var name:String = ""
            var job:String?
            var salary:Double = 0
            
            var dept:Department? //部门属性
        }
        
        struct Department {  // 部门结构体
            var no:Int = 0  // 部门编号属性
            var name:String = ""  // 部门属性
        }
        
        // 实例化
        // 类一般声明为 let 常量，类是引用数据类型
        /*
        let emp = Employee()
        var dept = Department()
        */
        
        // 值类型 和 引用类型
        // 只有类是引用类型，其他都是值类型
        // 结构体也是值类型
        var dept = Department()
        dept.no = 10
        dept.name = "Sales"
        
        let emp = Employee()
        emp.no = 1000
        emp.name = "Martin"
        emp.job = "Salesman"
        emp.salary = 1250
        emp.dept = dept
        
        // 直接修改会报错 因为是值类型，需要使用 inout 修改为引用类型传递
        func updateDept (dept: inout Department){
            dept.name = "Research"
        }
        
        print("更新前 \(dept.name)")  // 更新前 Sales
        updateDept(dept: &dept)
        print("更新后 \(dept.name)")  // 更新后 Research
        
        func updateEmp(emp:Employee){
            emp.job = "Clerk"
        }
        
        print("更新前 \(emp.job!)")  // 更新前 Salesman
        updateEmp(emp: emp)
        print("更新后 \(emp.job!)")  // 更新后 Clerk
        
        
        // 引用类型比较 (只能用于引用类型，也就是类的实例)
        // 恒等于 ===  比较两个引用是否为同一个实例
        // 不恒等于 !==
        
        let emp1 = Employee()
        emp1.no = 1000
        emp1.name = "Martin"
        emp1.job = "Salesman"
        emp1.salary = 1250
        
        let emp2 = Employee()
        emp2.no = 2000
        emp2.name = "Martin"
        emp2.job = "Salesman"
        emp2.salary = 2250
        
        if emp1 === emp2 {
            print("同一个实例 emp1 === emp2")
        }
        
        if emp1 === emp1 {
            print("同一个实例 emp1 === emp1  ")  // 同一个实例 emp1 === emp1
        }
        
        var dept1 = Department()
        dept1.no = 10
        dept1.name = "Sales"
        
        var dept2 = Department()
        dept2.no = 10
        dept2.name = "Sales"
        
//        if dept1 == dept2 {  // Binary operator '==' cannot be applied to two 'Department' operands
//            print("dept1 == dept2 ")
//        }
        
        
        /*
         恒等运算符
         === 只能用于判断两个类的实例是不是同一个实例，即判断内存地址是否一致
         == 可以判断任何数据类型，包括值类型和引用类型，如果使用 == 都需要遵循 Equatable 协议，并实现 == 静态方法，以此来判断两个实例是否相同
         */
        
        // 运算法重载
        // 运算法重载就是定义一个重载运算符的函数，在需要执行被重载的运算符时调用该函数，以实现相应的运算，也就是说 运算符重载是通过定义函数实现的
        
        // MARK:-类型嵌套
        // Swift 中的枚举 类 结构体 可以进行嵌套(在某一个类型的{}内部定义类)，这种类型嵌套在Java 中称为内部类
        // 类嵌套的优点是：支持访问它外部的成员(包括方法、属性和其他的嵌套类型)，嵌套还可以有多个层次
        // 嵌套会使程序结构不清楚，可读性变差
         class Employee1 {  // 员工类
            var no:Int = 0
            var name:String = ""
            var job:String?
            var salary:Double = 0
           
            var dept:Department1 = Department1() //部门属性
            var day:WeekDays = WeekDays.Friday
                
            
           struct Department1 {
                var no:Int = 10
                var name:String = "SALES"
            }
            enum WeekDays{
                case Monday
                case Tuesday
                case Wednesday
                case Thursday
                case Friday
                struct Day {
                    static var message : String = "Today is ..."
                }
            }
        }
        
        var emp3 = Employee1()
        print(emp3.dept.name)
        print(emp3.day)
        
        // MARK: 什么情况下使用结构体
        /*
         结构体总是通过被复制的方式在代码中传递，因此它的值是不可修改的
         结构体实例总是通过值传递来定义你的自定义数据类型。
         
         按照通用的准则，当符合一条或多条一下条件时，考虑使用结构体：
         1、结构体的主要目的是用来封装少量相关简单数据值
         2、有理由预计一个结构体实例在赋值或传递时，封装的数据将会被拷贝而不是被引用
         3、任何在结构体中存储的值类型属性，也将会被拷贝，而不是被引用
         4、结构体不需要去继承另外一个已存在类型的属性或者行为
         */
        
        
        // MARK: 存储属性的初始化赋值
        /*
         类和结构体在实例创建时，必须为所有的存储属性设置合适的初始值
         存储属性在构造器中赋值时，他们的值是被直接设置的，不会触发任何属性观测器
         
         存储属性在构造器中赋值流程：
         1、创建初始值
         2、在属性定义中指定默认属性值
         3、初始化实例，并调用 init() 方法
         */
        
//        class Person {
//            var name:String = ""   // 初始值是 空串
//            var age : Int?  // 可选类型默认初始值是 nil
//            var height : Float?  // 默认初始值是 nil
//        }
        
        // MARK: 指定构造器(自定义的构造器) 和便利构造器、默认构造器init() 三种
        /*
         类构造器分为指定构造器和便利构造器
         1、一个指定构造器必须调用它的直系父类的一个指定构造器
         2、一个便利构造器必须调用这个类自身的另一个构造器
         3、一个便利构造器最终一定会调用一个指定构造器
         */
        // 便利构造器
        /*
         1、init 之前有关键之 convenience
         2、少量参数
         3、通过调用自身其他初始化方法 self.init 并给某些参数设置默认值
         */
        
        class MainClass {
            var prop : Int

            // 指定构造器
            init(prop:Int) {
                self.prop = prop
            }
        }
        class SubClass : MainClass {
            var prop2 : Int

            // 子类的指定构造器
            init(prop:Int,prop2:Int) {
                self.prop2 = prop2
                super.init(prop: prop)
            }

            // 便利构造器
            override convenience init(prop:Int) {
                self.init(prop:prop,prop2:0)
            }
        }
        
        // MARK:可失败的构造器
        /*
         如果一个类，结构体，枚举类型的对象，在构造自身的过程中可能失败，则为其定义一个可失败的构造器
         
         便利初始化失败可能的原因有：
         传入无效的参数值
         缺少某种所需的外部资源
         没有满足特定条件
         
         语法是在 init 关键字后面添加问号 init?
         */
        
//        class Person {
//            var name:String = ""
//            // 可失败的构造器
//            init?(name:String) {
//                if name.isEmpty {
//                    return nil
//                }
//                self.name = name
//            }
//        }
//        let p = Person(name: "")
//        print(p?.name)
        
        // MARK: 析构 deinit
        
        
        // MARK:延迟存储属性
        /*
         延迟存储属性是指当第一次被调用的时候才会计算其初始值的属性，且仅计算一次，在属性声明前使用 lazy 来表示一个延迟存储属性
         
         必须将延迟存储属性声明成变量 (必须  var 关键字)，因为属性的值是在实例构造完成之前可能无法得到，
         而常量属性在构造过程过程完成之前必须要有初始值，因此无法声明成延迟属性
         延迟存储属性一般用于：
         1、延迟对象的创建
         2、当属性的值依赖于其他未知类
         
         lazy var property : Type = Value
         */
        
//        class MyCalss {
//            lazy var other = OtherClass()
//
//            init() {
//                print("MyClass init...")
//            }
//        }
//
//        class OtherClass {
//            var name = "swift"
//
//            init() {
//                print("OtherClass init ......")
//            }
//        }
//
//        var my = MyCalss()
//        print(my.other)  // 第一次调用的时候才会初始化
        
        
        // MARK: 属性观察器
        // 只能用于普通的存储属性，而且是可变属性 (变量 var )
        /* 可以为属性添加如下的一个或全部观察者：
         1、willSet 在设置新值之前调用
         2、didSet 在新的值被设置之后立即调用
         3、willSet 和 didSet 观察者在属性初始化过程中不会被调用
         */
        
        
        // MARK:- 可选链
        
        // 使用 ？ ！
        // 1、可选类型中的 ？
        // 声明这个类型是可选类型，访问这种类型的变量或常量需要使用 ！ (显示拆包)
        let result1 : Double? = 200  // 声明可选类型
        print(result1!)  // 显示拆包取值
        
        // 2、可选类型中的 ！
        // 声明这个类型是可选类型，访问这种类型的变量或常量时可以不使用感叹号
        let result2 : Double! = 200  // 声明可选类型
        print(result1)  // 隐式拆包取值
        
        // 3、可选链中的？
        // 在可选链中使用 ！ 访问时，一旦链条某些环节没有值，程序会异常，于是把感叹号改为？
        // 这样某些环节没有值得时候返回nil，程序不会发生异常
        
        // MARK:- 访问限定
        
        //1、访问级别
        // Swift 提供了5种访问级别：open public internal fileprivate private
        // 可以修饰 枚举 结构体 类 也可以修饰 变量 常量 下标 元组 函数 属性 等
        // open         访问限制最小，任何open 实体，无论是在自己模块内部，还是其他模块都可以被访问(import 语句引入其他模块后)
        // public       在同一个模块下和open 一样，在不同模块时，public 声明的类不能被继承，属性 和 方法不能被重写(override)
        // internal     默认访问限定，只能在自己模块中被访问
        // fileprivate  只能在当前源文件中被访问
        // private      真正意义上的私有，只能在类型内部访问
        
        //TODO:-访问级别最佳实践
        
        
        //MARK:- 类和结构体的比较
       
        // 相同点：
        /**
         * 定义存储属性
         * 定义方法
         * 定义下标
         * 定义构造函数
         * 定义扩展
         * 实现协议
         */
        
        //不同点：
        /**
         * 只有类才有的：
         *   能够继承另一个类
         *   能够核对运行时对象的类型
         *   析构对象释放资源
         *   引用计数允许一个实例有多个引用
         * 本质区别：
         *   结构体(枚举)都是值类型，类是引用类型(指针类型)
         */
        
        // 选择的原则：
        // 结构体是值类型，每一个实例没有独一无二的标识
        // 他们没有本质上的区别，可以互换
        var studentList1 : [String] = ["张三","李四"]
        var studnetList2 : [String] = ["张三","李四"]
        // 类是引用类型，每个实例都是独一无二的标识
        class Employ2 {
            var no = 0
            var name = ""
            var job = ""
            var salary = 0.0
        }
        
        var emp4 = Employ2()
        emp4.no = 100
        emp4.name = "Tom"
        emp4.job = "SALES"
        emp4.salary = 100
        
        var emp5 = Employ2()
        emp5.no = 200
        emp5.name = "Jack"
        emp5.job = "SALES"
        emp5.salary = 200
        
        // emp4 和 emp5 即便内容完全一样也不能说明就是同一个员工，只是相似而已
    }
}

