//
//  ViewController.swift
//  方法
//
//  Created by WTW on 2020/1/20.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        // 类是有属性和方法组成的，方法用于完成操作，完成计算数据等任务
        // Swift 中方法是在 枚举 结构体 和 类中定义的函数，具有面向对象的特性，与属性类似，分为实例方法和静态方法
        // 方法和函数的区别：方法是在 类 枚举 和 结构体内部定义的，方法的调用前面需要有主体，而函数不需要
        
        //MARK:实例方法
        /*
        class Account {
            var amount : Double = 10_000.00  // 账户金额
            var owner : String = "Tony"
            
            // 计算利息
            func interestWithRate(rate:Double) -> Double {
                return rate * amount
            }
        }
        
        let myAccount = Account()
        // 调用实例方法
        print(myAccount.interestWithRate(rate: 0.088))
        */
        
        // MARK:-可变方法
        // 结构体和枚举中的方法默认是不能修改值类型变量属性的
        // mutating
        /*
        class Employee {
            var no : Int = 0
            var name : String = ""
            var job : String?
            var salary : Double = 0
            var dept : Department?
        }
        
        struct Department {
            var no : Int = 0
            var name : String = ""
            
            var employees : [Employee] = [Employee]()
            
            // Cannot use mutating member on immutable value: 'self' is immutable
            // 报错提示 employees 不能修改，因为 employees 是 [Employee] 数组类型，是值类型
            // 需要修改他，就要将方法修改成 mutating 可变的
            // 可变方法能够修改值类型的变量属性，但是不能修改值类型的常量属性
            mutating func insert(object:AnyObject,index:Int) -> () {
                let emp = object as! Employee
                employees.insert(emp, at: index)
            }
        }
        
        var dept = Department()
        
        let emp1 = Employee()
        dept.insert(object: emp1, index: 0)
        
        let emp2 = Employee()
        dept.insert(object: emp2, index: 0)
        
        let emp3 = Employee()
        dept.insert(object: emp3, index: 0)
        
        print(dept.employees.count)
         */
        
        //MARK:静态方法
        // 也称类型方法
        // 结构体 和 枚举 的静态方法使用的关键字是 static 类的静态方法使用的是 class 或 static
        // 类中 如果使用 static 定义，则该方法不能在子类中被重写(override),如果是 class 定义，则该方法可以被子类重写
        
        // 1、结构体静态方法
        
        /*
        struct Account {
           
            var owner : String = "Tony" // 实例属性
            static var interestRate : Double = 0.668    // 静态属性
            
            // 计算利息
           static func interestBy(amount:Double) -> Double {  // 静态方法
                print(self)
                return interestRate * amount
            }
            
            // 实例方法能访问实例属性和方法，也能访问静态属性和方法
            // self 指代当前类型实例
            func messageWith(amount:Double) -> String {     // 实例方法
                let interest = Account.interestBy(amount: amount)
                return "\(self.owner) 的利息是 \(interest)"
            }
        }
        
        // 调用静态方法
        print(Account.interestBy(amount: 10_000.00))
        
        // 调用实例方法
        let myAccount = Account()
        print(myAccount.messageWith(amount: 10_000.00))
        */
        
        // 2、枚举静态方法
        /*
        enum Account {
            case 中国银行
            case 中国工商银行
            case 中国建设银行
            case 中国农业银行
        
        static var interestRate : Double = 0.0688 //利率
        
        static func interestBy(amount:Double) ->Double  {
            return interestRate * amount
            }
        }
        
        // 调用静态方法
        print(Account.interestBy(amount: 10_000.00))
        */
        
        
        // 3、类静态方法
        class Account {
            var owner:String = "Tony"
            // class 如果换成 static ，不能重写该方法
            class func interetBy(amount:Double)->Double {
                return amount * 0.0668
            }
        }
        class AccountB: Account {
            override class func interetBy(amount: Double) -> Double {
                return 0.0889 * amount
            }
        }
        
        // 调用静态方法
        print(Account.interetBy(amount: 10_000.00))
    }


}

