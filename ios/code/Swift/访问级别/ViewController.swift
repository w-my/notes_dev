//
//  ViewController.swift
//  访问级别
//
//  Created by WTW on 2020/4/19.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    fileprivate var name : String?
    private var age : String?
    
    override func viewDidLoad() {
        super.viewDidLoad()
       
        self.name = "hello"
        self.age = "20"
        
        /*
         swift 中的访问级别分为 open public internal fileprivate private 五种，
         可以修饰类、结构体、枚举等面向对象对象的类型
         还可以修饰 变量、常量、下标、元组、函数、属性等
         
         open 访问限制最小的，任何 open 实体，无论在自己模块内部还是其他模块(import 语法引入其他模块后)都可以方法
         public 类似 open ，在同一个模块中 open 和 public 完全一样。在不同模块时，public 声明的类不能被继承，public 所声明的属性和方法不能被重写(override)
         internal 默认访问限制，internal 实体只能在自己的模块中被访问
         fileprivate 只能在当前源文件中被访问
         private 真正意义上的私有，只能在类内部被访问
         
         
         最佳实践：
// MARK: 1、统一性原则
         如果一个类型(类、结构体、枚举)定义为 internal 或 private ，那么类型声明的常量或者变量不能使用 public 访问级别，因为 public 的变量或常量可以被任何人访问，而internal 或 private 类型不可以
         
         函数的访问级别不能高于他的参数和返回类型(类、结构体、枚举)的访问级别。假如函数声明为 public 级别，而参数或返回类型声明为 internal 或 private ，就会出现函数可以被任何人访问，而它的参数和返回类型不能访问的矛盾情况。
         */
        
        /*
        private class Employee {
            var no: Int = 0
            var name: String = ""
            var job: String?
            var salary: Double = 0
            var dept: Department?
        }

        internal struct Department {
            var no: Int
            var name: String = ""
        }
        
        public let emp = Employee()  // 编译错误  Employee private
        public var dept = Department() // 编译错误 Department internal
        */
        
        /*
        class Employee {
            var no: Int = 0
            var name: String = ""
            var job: String?
            var salary: Double = 0
            var dept: Department?
        }

        struct Department {
            var no: Int
            var name: String = ""
        }
        // Attribute 'public' can only be used in a non-local scope
         // 编译错误 访问级别不一致
        public func getEmpDepat(emp: Employee)->Department? {
            return emp.dept
        }
         */
        
        // MARK:设计原则
        /*
         如果编写的应用程序包中的所有swift 文件和其定义的实体都是供本应用使用的，而不是提供给其他模块使用，那么就不用设置访问级别，即使用默认的访问级别
         如果设计的是框架，框架编译的文件不能独立运行，这种情况需要详细设计其中的 swift 文件和实体的访问级别，让别人使用的可以设定为 public ，不想让别人看到的可以设定为 internal 或 private
         */
        
        //MARK: 元组类型的访问级别
        // 元组类型的访问级别遵循元组中字段最低级的访问级别
        /*
        private class Employee {
            var no: Int = 0
            var name: String = ""
            var job: String?
            var salary: Double = 0
            var dept: Department?
        }

        struct Department {
            var no: Int
            var name: String = ""
        }
        
        private let emp = Employee()
        var dept = Department()
        
        private var student1 = (dept,emp)
        */
        
        //MARK: 枚举类型的访问级别：
        // 枚举中成员的访问级别继承自该枚举，因此不能为枚举中的成员指定访问级别
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
//         callPrint()
    }
}

//extension ViewController {
//    // 同一个文件中访问没问题，不同文件中访问不行
//    func callPrint()  {
//        print(self.name!)
//        print(self.age!)
//    }
//}

public class ClassA {
    /*
     fileprivate 改为 private 就会编译错误
     Property does not override any property from its superclass
     */
    fileprivate var name : String {
        return ""
    }
    
    public func callPrint()  {
        print(self.name)
    }
}

class ClassB: ClassA {
    override var name: String {
        return "Tony"
    }
}
