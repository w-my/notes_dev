//
//  ViewController.swift
//  内存管理
//
//  Created by WTW on 2020/1/20.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
       
        // 主要是对引用类型的管理，即对类创建的对象采用ARC管理  (内存分配在堆上)
        // 值类型(整型、浮点型、布尔、字符串、元组、集合、枚举、结构体等)是有处理器自动管理； (内存分配在栈上)
        
        
        //循环引用问题
        /*
        class Employee {
            var no: Int
            var name: String
            var job: String
            var dept: Department?
            
            init(no: Int, name: String, job: String) {
                self.no = no
                self.name = name
                self.job = job
                print("员工\(name)已构造完成")
            }
            deinit {
              print("员工\(name)已析构完成")
            }
        }
        
        class Department {
            var no: Int = 0
            var name: String?
            var manager: Employee?
            
            init(no: Int, name: String) {
                self.no = no
                self.name = name
                print("部门\(name)已构造完成")
            }
            deinit {
                print("部门\(name)已析构完成")
            }
        }
        
        var emp: Employee?
        var dept: Department?
        
        emp = Employee(no: 001, name: "Black", job: "工程师")
        dept = Department(no: 001, name: "White")
        
        emp!.dept = dept
        dept!.manager = emp   //造成循环引用
        
        emp = nil
        dept = nil
    }
         */

    
    // Swift 提供了两种办法解决循环引用：弱引用 (weak_reference)和无主引用(unowned_reference)
   
    //弱引用：允许循环引用中的一个对象不采用强引用的方式引用另外一个对象，这样就不会引起循环引用
        /*
        class Employee {
            var no: Int
            var name: String
            var job: String
            weak var dept: Department?  // 声明为弱引用
            
            init(no: Int, name: String, job: String) {
                self.no = no
                self.name = name
                self.job = job
                print("员工\(name)已构造完成")
            }
            deinit {
              print("员工\(name)已析构完成")
            }
        }
        
        class Department {
            var no: Int = 0
            var name: String?
            var manager: Employee?
            
            init(no: Int, name: String) {
                self.no = no
                self.name = name
                print("部门\(name)已构造完成")
            }
            deinit {
                print("部门\(name)已析构完成")
            }
        }
        
        var emp: Employee?
        var dept: Department?
        
        emp = Employee(no: 001, name: "Black", job: "工程师")
        dept = Department(no: 001, name: "White")
        
        emp!.dept = dept
        dept!.manager = emp
        
        emp = nil
        dept = nil
    }
    */
    
    // 无主引用 使用关键字 (unowned)
        /*
    class Employee {
            var no: Int
            var name: String
            var job: String
            var dept: Department?
            
            init(no: Int, name: String, job: String) {
                self.no = no
                self.name = name
                self.job = job
                print("员工\(name)已构造完成")
            }
            deinit {
              print("员工\(name)已析构完成")
            }
        }
        
        class Department {
            var no: Int = 0
            var name: String?
            unowned var manager: Employee  //  unowned 无主引用
            
            init(no: Int, name: String,manager:Employee) {
                self.no = no
                self.name = name
                self.manager = manager
                print("部门\(name)已构造完成")
            }
            deinit {
                print("部门\(name)已析构完成")
            }
        }
        
        var emp: Employee?
        var dept: Department?
        
        emp = Employee(no: 001, name: "Black", job: "工程师")
        dept = Department(no: 001, name: "White",manager: emp!)
        
        emp!.dept = dept
        
        emp = nil
        dept = nil
         */
        
        //MARK:闭包中的强引用循环
        // 闭包本质上是是函数类型，所以也是引用类型，因此可能在闭包的上下文捕获变量(或常量)之间出现强引用循环问题
        // 并不是所有的捕获变量或常量都会发生强引用循环问题，只有将一个闭包赋值给对象的某个属性，并且这个闭包体使用了该对象，才会产生闭包强循环引用
        /*
        class Employee {
            var no: Int = 0
            var firstName: String
            var lastName: String
            var job: String
            
            init(no: Int, firstName: String, lastName: String, job: String) {
                self.no = no
                self.firstName = firstName
                self.lastName = lastName
                self.job = job
                print("员工\(firstName)已构造完成")
            }
            deinit {
              print("员工\(firstName)已析构完成")
            }
            
            // 定义一个计算属性 属性值是通过一个闭包实现的，闭包的返回值类型是 ()->String
            // 闭包内捕获了self,self 能够在闭包内使用，那么属性必须声明为 lazy ，所有属性初始化完成后，self 表示的对象才能被创建
            lazy var fullName: ()->String = {
                return self.firstName + "." + self.lastName
            }
        }
        
        var emp:Employee? = Employee(no: 001, firstName: "Tony", lastName: "Zhao", job: "工程师")
        print(emp!.fullName())
        emp = nil
         */
        
        // 解决闭包循环引用
        // 到底是采用弱引用(weak)还是无主引用(unowned)，与两个对象之间的选择条件是：捕获的对象是否可以为nil
        // 如果闭包和捕获的对象总是互相引用并且总是同时销毁，则将闭包内的捕获声明为无主引用，当捕获的对象有时可为nil时，则将闭包内的捕获声明为 弱引用。
        // 如果捕获的对象绝对不会为nil,那么就应该采用无主引用
        // Swift 在闭包中定义了捕获列表来解决强引用循环问题
        /*
        lazy var 闭包 : <闭包参数列表> -> <返回值类型> = {
            [unowned 捕获对象]<闭包参数列表> -><返回值类型> in
            或
            [weak 捕获对象]<闭包参数列表> -><返回值类型> in
         
            // 闭包体
        }
        或
        lazy var 闭包 : () -> <返回值类型> = {
            [unowned 捕获对象] in
            或
            [weak 捕获对象] in
            
            //闭包体
        }
         */
        //上述语法格式可以定义两种闭包捕获列表，第一种是最为普通的
        /*
        lazy var fullName : (String,String)->String = {
            [weak self] (firstName:String, lastName: String)->String in
            // 闭包体
        }
         */
        // 第二种是无参情况下的捕获列表，可以省略参数列表，只保留 in ,Swift 编译器或通过上下文推断出参数列表和返回值类型
        /*
        lazy var fullName: () -> String = {
            [unowned self] in
            // 闭包体
        }
         */
        class Employee {
            var no: Int = 0
            var firstName: String
            var lastName: String
            var job: String
            
            init(no: Int, firstName: String, lastName: String, job: String) {
                self.no = no
                self.firstName = firstName
                self.lastName = lastName
                self.job = job
                print("员工\(firstName)已构造完成") 
            }
            deinit {
              print("员工\(firstName)已析构完成")
            }
            
            lazy var fullName: ()->String = {
                [weak self] ()->String in
                let fn = self!.firstName
                let ln = self!.lastName
                return fn + "." + ln
                
            }
        }
        
        var emp:Employee? = Employee(no: 001, firstName: "Tony", lastName: "Zhao", job: "工程师")
        print(emp!.fullName())
        emp = nil
        
        
    }
}

