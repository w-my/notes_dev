//
//  ViewController.swift
//  属性和下标
//
//  Created by WTW on 2020/1/20.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Swift 中属性分为 存储属性 和 计算属性
        // 存储属性就是 OC 中的数据成员
        // 计算属性不存储数据，但是可以通过计算其他属性返回数据
        
        // 集合类型中的元素还可以通过下标访问，下标在 Java 中称为索引属性，Swift 的下标也具有属性特性
        
        // MARK:-存储属性
        // 实例通过 . 来调用属性
        /*
        class Employee {  // 员工类
         var no:Int = 0
         var name:String = ""
         var job:String?
         var salary:Double = 0
        
         var dept:Department? //部门属性
        }
        
        // 结构体内部只有在构造函数中修改字段的值，在结构体内部方法和属性内不能直接修改结构体内部字段的值
        struct Department {
             var no:Int = 10
             var name:String = ""

         }
        
        let emp = Employee()
        emp.no = 100
        
        var dept = Department()
        // 会编译错误 因为 dept 是值类型，值类型不能修改，即便属性name 是变量也不能修改
        dept.name = "JACK"  // Cannot assign to property: 'dept' is a 'let' constant
        
        let emp1 = Employee()
        // emp1 即使是常量也可以修改 ，因为是引用类型
        emp1.name = "Tony"
        */
        
        // 延迟存储属性
        /*
        class Employee {  // 员工类
         var no:Int = 0
         var name:String = ""
         var job:String?
         var salary:Double = 0
        
         var dept:Department = Department() //部门属性
        }
        
        struct Department {
             var no:Int = 10
             var name:String = ""
         }
        
        // 创建实例的时候，dept 也会进行实例化，即使不用也会实例化
        let emp = Employee()
        */
        
        
        // 优化如下：lazy 延迟
        /*
        class Employee {  // 员工类
             var no:Int = 0
             var name:String = ""
             var job:String?
             var salary:Double = 0
        
            //使用 lazy 关键字，这样dept 属性就延迟加载，只有第一个访问的时候才会被加载，如果不访问就不创建，可以减少内存的开销
            lazy var dept:Department = Department() //部门属性
        }
        
        struct Department {
             var no:Int = 10
             var name:String = ""
         }
        
        // 创建实例的时候，dept 也会进行实例化，即使不用也会实例化,如果使用 lazy 只有在使用的时候才会实例化
        let emp = Employee()
        */
        
        
        // MARK:- 计算属性
        // 计算属性不存储数据，从其他属性中计算得到数据
        // 计算属性提供了一个 getter 来获取值，以及一个 setter (newValue) 来间接设置其他属性或者变量的值
        // 语法格式如下：
        /*
         // 面向对象类型可以是 枚举 结构体 类
        面向对象类型 类型名 {
            存储属性
            ......
            var 计算属性名：属性数据类型{   // 变量必须使用 var 声明
                get{   // getter 访问器
                    return 计算后属性值
                }
                set(新属性值){  // setter 访问器
                    ......
                }
            }
        }
        */
        
        // 示例
        /*
        class Employee {  // 员工类
            var no:Int = 0
            var firstName:String = "Tony"
            var lastName:String = "Guan"
            var job:String?
            var salary:Double = 0
           
            lazy var dept:Department = Department() //部门属性
            
            var fullName : String {
                get{
                    return firstName + "." + lastName
                }
                set(newFullName) {
                    let name = newFullName.components(separatedBy: ".")
                    firstName = name[0]
                    lastName = name[1]
                }
//                // setter 方法也可以这样写
//                set {
//                   let name = newValue.components(separatedBy: ".")
//                   firstName = name[0]
//                   lastName = name[1]
//               }
            }
       }
       
       struct Department {
            var no:Int = 0
            var name:String = ""
        }
      
        let emp = Employee()
        print(emp.fullName)
        
        emp.fullName = "Tom.Guan"
        print(emp.fullName)
        */
        
        // 只读计算属性
        // 计算属性只有 getter 没有 setter
        // 只读计算属性可以不用写 getter ，也可以省略get{}
        // 示例：
        /*
        class Employee {  // 员工类
             var no:Int = 0
             var firstName:String = "Tony"
             var lastName:String = "Guan"
             var job:String?
             var salary:Double = 0
            
             lazy var dept:Department = Department() //部门属性
             
             var fullName : String {
                  return firstName + "." + lastName
             }
        }
        
        struct Department {
             var no:Int = 0
             var name:String = ""
         }
        */
        
        
        // 结构体 和 枚举中计算属性
        /*
        struct Department{
            let no:Int = 0
            var name:String = "SALE"
            
            var fullName:String {
                return "swift" + name + ".D"
            }
        }
        
        var dept = Department()
        print(dept.fullName)
        
        enum WeekDays: String {
            case Monday     = "Mon"
            case Tuesday    = "Tue"
            case Wednesday  = "Wed"
            case Thursday   = "Thu"
            case Friday     = "Fri"
            
            var message:String {
                return "Today is " + self.rawValue
            }
        }
        
        var day = WeekDays.Friday
        print(day.message)
        */
        
        //MARK:-属性观察者
        // 监听属性的变化， Swift 提供了属性观察者，属性观察者能够监听存储属性的变化，即便变化前后的值相同，他们也能监听到
        // 属性观察者不能监听延迟存储属性和常量存储属性的变化
        // 只能在类和结构体中使用，不能再枚举中使用，枚举不支持存储属性
        // Swift 中的属性观察者主要有以下两个：
        // willSet
        // didSet
        
        //常用于后台处理，以及需要更新界面的业务需求
        
        // 属性观察者的语法格式如下：
        /*
        面向对象类型 类型名 {
            ......
            var 存储属性：属性数据类型 = 初始化值 {  // 定义存储属性
                willSet(新值){  // (新值)可以省略，系统默认分配一个默认参数 newValue
                    ......
                }
                didSet(旧值){  // (旧值)可以省略，系统默认分配一个默认参数 oldValue
                    ....
                }
            }
        }
         */
        
        //示例：
        /*
        class Employee {
            var no:Int = 0
            var name: String = "Tony"{
                willSet {
                    print("员工name新值：\(newValue)")
                }
                didSet {
                    print("员工name旧值：\(oldValue)")
                }
            }
            var job:String?
            var salary:Double = 0
            var dept:Department?
            
        }
        struct Department {
            var no:Int = 10{
                willSet{
                    print("部门编号新值：\(newValue)")
                }
                didSet{
                    print("部门编号旧值：\(oldValue)")
                }
            }
            var name:String = "JACK"
        }
        
        let emp = Employee()
        emp.no = 100
        emp.name = "Smith"
        
        var dept = Department()
        dept.no = 20
        
        
         //员工name新值：Smith
         //员工name旧值：Tony
         //部门编号新值：20
         //部门编号旧值：10
         */
        
        
        // MARK:- 静态属性
        // 语法格式如下：
        /*
        struct(class/enum) 结构体(类/枚举)名 {
            static var(或let) 存储属性 = xxx
            ......
            static var 计算属性名:属性数据类型 {
                get {
                    return 计算后属性值
                }
                set (新属性值) {
                    ......
                }
            }
        }
         */
        
        // 结构体不能定义实例存储属性，但是可以定义静态存储属性，也可定义静态计算属性
        // 类静态计算属性如果使用了static 定义，则该属性不能在子类中被重写(override),如果使用class 定义，则该属性可以被子类重写
        /*
        类型     实例存储属性   静态存储属性  实例计算属性  静态计算属性
        类       支持         支持           支持      支持
        结构体    支持         支持           支持      支持
        枚举     不支持        支持           支持      支持
         */
        
        // 1、结构体静态属性
        
        // 2、枚举静态属性
        
        // 3、类静态属性
        class Account {
            //余额
            var amount:Double = 0.0
            //账户名
            var owner:String = ""
            // 利率
            static var interestRate:Double = 0.0668  //静态存储属性
            
            // class 换成 static 不能重写该属性
           class var staticPro:Double {  // 静态计算属性 关键字 class ，如果换成 static 则不能重写 staticPro 属性
                return interestRate * 1_000_000
            }
             
            var instanceProp : Double {  // 实例计算属性
                return Account.interestRate * self.amount   // 访问静态属性/实例属性
            }
        }
        
        class AccountB : Account {
            override class var staticPro: Double {  // 重写 staticPro 属性
                return interestRate * 1_000_000
            }
        }
        
        // 访问静态属性
        print(Account.staticPro)
        
        let myAccount = Account()
        // 访问实例属性
        myAccount.amount = 1_000_000
        // 访问静态属性
        print(myAccount.instanceProp)
        
        // MARK:- 下标
        // Swift 中可以定义一些集合类型，可能会有一些集合类型的存储属性，这些属性中的元素可以通过下标访问
        // 下标可以认为是访问对象、集合或序列的快捷方式，不需要再调用实例的特定的赋值和访问方法
        // 允许通过子啊实例后面的方括号中传入一个或者多个的索引值来对实例进行访问和赋值，同样可以根据自身需要提供多个下标脚本实现，方法的参数和返回值完全可以自定义
        // 下标采用 subscript 关键字声明
        // 下标访问的语法格式如下：
        /*
        面向对象类型 类型名 {
            其他属性
            ...
            subscript(参数:参数数据类型)-> 返回值数据类型 {
                get{
                    return 返回值
                }
                set {
                    ......
                }
            }
        }
         */
        
        //示例
        // swift 中没有二维数组，只有一维数组，k自定义一个二维数组，然后通过两个下标参数访问它的元素，形式上类似于C语言中的二维数组
        struct DoubleDimensionalArray {
            
            let rows:Int,columns:Int   //声明存储属性 rows columns 分别存储最大行数和最大列数
            var grid:[Int]
            
            init(rows:Int,columns:Int) {  // 构造函数
                self.rows = rows
                self.columns = columns
                //grid 是一维数组，二维数组中的数据实际上保存在 grid 属性中
                // repeating 表示数组中所有元素全部赋值为0
                grid = Array(repeating: 0, count: rows*columns)  // 初始化存储属性
            }
            
            subscript(row:Int,col:Int)->Int {  // 定义下标
                get {
                    return grid[(row * columns) + col] // (row * columns) + col 下标表达式
                }
                set {
                    grid[(row * columns) + col] = newValue
                }
            }
        }
        
        let COL_NUM = 10
        let ROW_NUM = 10
        
        //创建10*10的二维数组
        var ary2 = DoubleDimensionalArray(rows: ROW_NUM, columns: COL_NUM)
        
        for i in 0..<ROW_NUM {
            for j in 0..<COL_NUM {
                ary2[i,j] = i*j
            }
        }
        
        // 打印出二维数组
        for i in 0..<ROW_NUM {
            for j in 0..<COL_NUM {
                print("\t \(ary2[i,j])",terminator:"")
            }
            print("\n")
        }
        
        
        // 下标demo
        class MyClass {
            var array:Array<String> = []
            
            subscript(index: Int) -> String? {
                set {
                    if index <= array.count && newValue != nil {
                        array.insert(newValue!, at: index)
                    }else {
                        print(index,array.count)
                    }
                }
                get {
                    if index >= array.count {
                        return nil
                    }
                    return array[index]
                }
            }
        }
        
        let my = MyClass()
        my[0] = "apple"
        my[1] = "orange"
        my[2] = "banana"
        my[4] = nil
        print(my.array)
        
    }
}

