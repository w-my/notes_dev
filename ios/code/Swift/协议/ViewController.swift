//
//  ViewController.swift
//  协议
//
//  Created by WTW on 2020/1/20.
//  Copyright © 2020 WTW. All rights reserved.
//
//  https://www.cnswift.org/protocols

// Java 中称为 接口，C++ 中叫纯虚类
// 几何图形类中所有的方法都是抽象的，在OC和Swift中称为协议
// 协议是高度抽象的，只规定绘图的抽象方法名、参数列表、返回值等信息，不给出具体实现，这个抽象方法由遵从该协议的遵从者实现

import UIKit

class ViewController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // MARK: 协议
        
        // 类 结构体 枚举 都可以声明一个或多个协议，并提供该协议所要求属性和方法的具体实现
        // 协议可以用来定义方法、属性、下标的声明，协议可以被枚举、结构体、类遵守(多个协议之间用逗号隔开)
        // 协议中定义方法时不能有默认参数值，默认情况下，协议中定义的内容必须都实现
        /*
        protocol Drawable {
            func draw()
            var x: Int { get set }
            var y: Int { get }
            subscript(index: Int) -> Int { get set }
        }
         */
       
        // MARK: - 协议语法
        /*
        // 协议定义
        protocol 协议名 {
            // 协议内容
        }
         
        // 遵从协议
        类型 类型名 ： 协议1，协议2{   // 类型 class\struct\enum
            //遵从协议内容
        }
 
        // 如果一个类继承父类的的同时也要遵从协议，应该把父类放在所有协议之前
        class 类名 ： 父类，协议1，协议2 {
            //遵从协议实现
        }
        */
        
        //MARK:- 协议属性
        // 协议可以要求遵从者实现某些指定属性，包括实例属性和静态属性
        // 定义的时候，每种属性可以有只读和读写之分，遵从者实现属性比较灵活，无论是存储属性还是计算属性，只要能满足协议属性的要求，就可以通过编译
        // 甚至协议只规定只读属性，而遵从者可以提供读写实现。协议只规定了遵从者必须要实现要做的事，没有规定不能做的事
        // 协议中定义属性时，必须用 var 关键字
        // 实现协议时的属性权限不小于协议中定义的属性权限
        // 协议定义 get set 用var 属性，或get set 计算属性去实现
        // 协议定义 get ,用任何属性都可以实现
        
        //MARK: 协议实例属性
        /*
        protocol Drawable {
            func draw()
            var x: Int { get set }
            var y: Int { get }
            subscript(index: Int)->Int { get set }
        }
        
        class Person: Drawable {
            var x: Int = 0
            let y: Int = 0
            func draw() {
                print("Person draw")
            }
            subscript(index: Int) -> Int {
                set {}
                get {index}
            }
        }
        
        class Person1: Drawable {
            var x: Int {
                get {0}
                set {}
            }
            var y: Int { 0 }
            func draw() {
                print("Person draw")
            }
            subscript(index: Int) -> Int {
                set {}
                get {index}
            }
        }
        */
        
        //MARK: 协议静态属性
        // 协议静态属性与在协议中定义静态方法类似，前面需要添加static 关键字
        // 如果遵从者是类，关键字就是class 和 static ;如果遵从者是结构体或枚举，关键字就是 static
        // 协议静态属性定义和声明都比较麻烦，与具体的类型有关，使用时需要注意
        // 为了保证通用(结构体、枚举、类)，协议中必须用 static 定义类型方法、协议属性、类型下标
        
        // 只有将协议中的实例方法标记为 mutating(只能用于结构体和枚举中（值类型）) ，才允许结构体、枚举的具体实现修改自身内存
        // 类在实现方法时不用加 mutating, 枚举 结构体 才需要加  mutating
       /*
        protocol Drawable {
            mutating func draw()  // 必须在协议中加 mutating 才允许在结构体 或者 枚举中去修改
        }
        
        // 类实现协议时不需要加 mutating
        class Size: Drawable {
            var width: Int = 0
            func draw() {
                width = 30
            }
        }
        
        // 结构体和枚举实现协议时需要加 mutating
        struct Point: Drawable {
            var x: Int = 0
            mutating func draw() {
                x = 10
            }
        }
        */
        
        //MARK:- 协议方法
        // 可以要求遵从者实现某些指定方法，包括实例方法和静态方法。这些方法在协议中定义
        // 协议方法和普通方法类似，但不支持变长参数和默认值参数，也不需要大括号和方法体
        
        //MARK: 协议实例方法
//        let rect:Figure = Rectangle() // 把协议作为类型使用 rect 即Figure类型，本质上还是Rectangle
//        rect.onDraw()
//
//        let circle:Circle = Circle()
//        circle.onDraw()
        
    
        //MARK: 协议静态方法
        // 如果遵从者是结构体或者枚举，关键字就是 static
        // 如果遵从者是类，关键字就是 class 或者 static，使用class 时遵从者的子类中可以重写该静态方法，使用static时遵从者的子类中不可以重写该静态方法（和子类继承父类的规则一样）
        
        //MARK: 协议可变方法
        // 在结构体和枚举中可以定义可变方法(因为结构体和枚举类型的属性不可以修改的，通过定义可变方法可以修改这些属性，而类是引用类型，方法本身就是可变的，能修改自己的属性)，而类中没有这种方法
        // 协议定义可变方法 是前面添加 mutating 关键字
        // 结构体和枚举类型遵从可变方法，方法前面需要关键字 mutating ，类不需要
//        var classInstance:Editable = ClassImp()
//        classInstance.edit()
//
//        var structInstance:Editable = structImp()
//        structInstance.edit()
//
//        var enumInstance:Editable = enumImp.Monday
//        enumInstance.edit()
        
        // MARK:- init
        /**
         * 协议中还可以定义初始化器( 要求遵循协议的类型实现指定的初始化器)
         * 非 final 类实现时必须加上 required (因为 final 的类不会有子类)
         * 如果从协议实现的初始化器，刚好是重写了父类的指定初始化器, 那么这个初始化必须同时加上 required override
         */
        
        /*
        // 协议中带有初始化器
        protocol Drawable {
            init(x: Int,y: Int)
        }
        // 非 final 类实现时必须加上 required
        class Point: Drawable {
            required init(x: Int, y: Int) { }
        }
        final class Size: Drawable {
            init(x: Int, y: Int) { }
        }
        */
        
        /*
        protocol Livable {
            init(age: Int)
        }
        class Person {
            init(age: Int) { }
        }
        // 从协议实现的初始化器，刚好是重写了父类的指定初始化器，需要同时加上 required override
        class Student: Person,Livable {
          required override init(age: Int) {
                super.init(age: age)
            }
        }
         */
        
        // MARK: init init? init!
        /**
         * 协议中定义的 init? init! 可以用 init init? init! 去实现
         * 协议中定义的 init 可以用 init init! 去实现
         */
        /*
        protocol Livable {
            init()
            init?(age: Int)
            init!(age: Int)
        }
        
        class Person: Livable {
            required init(){ }
            //required init()!{ }
            
            required init?(age: Int) { }
            //required init!(age: Int) { }
            //required init(age: Int) { }
            
            required init!(age: Int) { }
           // required init?(age: Int) { }
           // required init(age: Int) { }
        }
        */
        
        //MARK:- 面向协议编程
        // 面向对象的最重要一点就是 面向接口编程 ，在Swift 和 OC 中称为面向协议编程，面向协议编程能够使面向对象类型(类、结构体、枚举)的定义和实现分离，协议作为数据类型暴露给使用者，不用关心具体的实现细节，从而提供代码的可扩展性和可复用性
        
        // MARK:- 协议类型
        /* 在 Swift 中协议是作为数据类型使用的，这是 面向协议编程 具体实现的一个方面，协议可以出现在任意允许其他数据类型出现的地方
         1、协议类型可以作为函数、方法或构造函数中的参数类型或返回值类型
         2、协议类型可以作为常量、变量、属性的类型
         3、协议类型可以作为数组、字典、Set 等集合的元素类型
         */
        // 协议作为类型使用，与其他类型没有区别，不仅可以使用 as、as！、as？操作符进行类型转换
        // 还可以使用 is 操作符判断类型是否遵从了某个协议 ,除了不能实例化，协议可以像其他类型一样
        // 由于协议是类型,所以要开头大写

        // 定义了3个Student 实例，他们的类型是 Person 协议
//        let student1:Person = Student(firstName: "Tom1", lastName: "Guan1", school: "清华1")
//        let student2:Person = Student(firstName: "Tom2", lastName: "Guan2", school: "清华2")
//        let student3:Person = Student(firstName: "Tom3", lastName: "Guan3", school: "清华3")
//
//        let worker1:Person = Worker(firstName: "Tom1", lastName: "Zhao1", factory: "电厂1")
//        let worker2:Person = Worker(firstName: "Tom2", lastName: "Zhao2", factory: "电厂2")
//
//        let people : [Person] = [student1,student2,student3,worker1,worker2]
//
//        for item:Person in people {
//            if let student = item as? Student {  // as? 类型转换
//                print("student school:\(student.school)")
//                print("studnet fullName:\(student.fullName)")
//                print("studnet desc:\(student.description())")
//            }else if let worker = item as? Worker {
//                print("factory:\(worker.factory)")
//                print("worker fullName:\(worker.fullName)")
//                print("worker desc:\(worker.description())")
//            }
//        }
        
        /*
         protocol RandomNumberGenerator {
             func random() -> Double
         }
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
         */
        
        //MARK: 协议的继承
//        let gStudent = Grauate(firstName: "Tom", lastName: "Zhao", school: "清华", special: "计算机")
//        print(gStudent.description())
        
        //MARK: - 协议扩展
//        let emp = Employee()
//        emp.printFullName()
        
        //MARK: 协议的合成
        //多个协议可以临时合成一个整体，作为一个类型使用。首先要有一个类型在声明时遵从多个协议
        /*
        protocol Ship {  // 定义船的协议
            var dispacement:Double {get set} // 排水量
        }

        protocol Weapon { // 定义武器协议
            //大炮门数
            var gunNumber : Int {get set}
        }

        // 定义军舰
        class WarShip: Ship,Weapon {  // 同时遵从 Ship Weapon 协议
            var dispacement: Double = 10000000
            var gunNumber: Int = 20
        }

         // 这种类型的参数 需要同时遵守 Ship 和 Waspon 协议，这种类型就是协议合成，是一种临时的类型，当作用域结束时，这个类型就不存在了
        func showWarResource(resource:Ship&Weapon) {
               print("Ship:\(resource.dispacement) - Weapon:\(resource.gunNumber)")
        }
         
        let ship = WarShip()
        showWarResource(resource: ship)
        */
        
        
        //MARK: 扩展中遵从协议
        //扩展中也可以声明遵从某个协议
        /*
        extension 类型名:协议1，协议2{
            
        }
         */
        var account = Account()
        account.edit()
        print("\(account.owner) - \(account.amount)")
        
        
        // MARK:- 只能被class 继承的协议 (补充)
        // 以下三种协议 枚举和结构体是不能继承的
        // 被 @objc 修饰的协议，还可以暴露给 OC 去实现
        /*
        protocol Runnable1: AnyObject {}
        protocol Runnable2: class {}
        @objc protocol Runnable3 {}
        */
        
        // MARK: 可选协议
        // 可以通过 @objc 定义可选协议，这种协议只能被 class 遵守
        /*
         @objc protocol Runnable {
             func run1()
             @objc optional func run2()  // 可选协议
             func run3()
         }

         class Dog: Runnable {
             func run1() {}
             func run3() {}
         }
         */
        
        // MARK: dynamic
        // 被 @objc dynamic 修饰的内容会具有动态性，比如调用方法会走 runtime 的那一套流程
        /*
        class Dog: NSObject {
            @objc dynamic func test1(){}  // objc_msgSend
            func test2() {}  // 虚表的函数地址调用方式
        }
        
        var d = Dog()
        d.test1()
        d.test2()
        */
        
        // MARK: Swift 支持 KVC/KVO
        // 条件：属性所在的类、监听器最终继承自 NSObject ，用 @objc dynamic 修饰对应的属性
    
        /*
         class Observer: NSObject {
             
             override func observeValue(forKeyPath keyPath: String?,
                                        of object: Any?,
                                        change: [NSKeyValueChangeKey : Any]?,
                                        context: UnsafeMutableRawPointer?) {
                 print(change?[.newKey] as Any)
             }
             
         }

         class Person: NSObject {
             @objc dynamic var age: Int = 0   //  @objc dynamic  必须要用这个
             var name: String = ""
             var observer: Observer = Observer()
             
             override init() {
                 super.init()
                 self.addObserver(observer,
                                  forKeyPath: "age",
                                  options: .new ,
                                  context: nil)
                 self.addObserver(observer,
                                 forKeyPath: "name",
                                 options: .new ,
                                 context: nil)
             }
             
             deinit {
                 self.removeObserver(observer, forKeyPath: "age")
                 self.removeObserver(observer, forKeyPath: "name")
             }
         }
         
        var p = Person()
        p.age = 20
        p.setValue(25, forKey: "age")
//        p.name = "hello"  // 没有打印
//        p.setValue("world", forKey: "name")  // 报错
        //Optional(20)   Optional(25)
        */
        
        // MARK: block 方式的 KVO
        /*
        class Person : NSObject {
            @objc dynamic var age: Int = 0
            var observation: NSKeyValueObservation?
            override init() {
                super.init()
                observation = observe(\Person.age, options: .new
                    , changeHandler: { (person, change) in
                        print(change.newValue as Any)
                })
            }
        }
        
        var p = Person()
        p.age = 20  //  @objc dynamic
        */
     
        //MARK: - Swift 关联对象 (Associated Object)
        // 在 Swift 中，class 依然可以使用关联对象 (只有 class 可以)
        // 默认情况下，extension 不可以增加存储属性
        // 借助关联对象，可以实现类似 extension 为 class 增加存储属性的效果
        
        /*
        class Person {}

        // Self 代表当前类 self 代表实例对象
        // Void? 只占用一个字节 也可以使用 Bool
        extension Person {
            private static var AGE_KEY: Void?
            var age: Int {
                get {
                    (objc_getAssociatedObject(self,
                                             &Self.AGE_KEY) as? Int) ?? 0        }
                set {
                   objc_setAssociatedObject(self,
                                            &Self.AGE_KEY,
                                            newValue,
                                            .OBJC_ASSOCIATION_ASSIGN)
                }
            }
        }
         
        var p = Person()
        p.age = 10
        print(p.age) // 10
        */
     
        // MARK: is as? as! as
        /**
         * is 用来判断是否为某种类型，as 用来做强制类型转换
         */
        /*
        protocol Runnable {
            func run()
        }
        
        class Person {
            
        }
        
        class Student: Person,Runnable {
            func run() {
                print("student run")
            }
            func study() {
                print("studnet study")
            }
        }
        var stu: Any = 10
        print(stu is Int) // true
        stu = "Jack"
        print(stu is String) // true
        stu = Student()
        print(stu is Person)  // true
        print(stu is Student) // true
        print(stu is Runnable) // true
        */
        
        
    }
}


// 扩展中遵从协议
protocol Editable {
    mutating func edit()
}

struct Account {
    var amount : Double = 10.0
    var owner: String = ""
}

extension Account : Editable {
    mutating func edit() {
        self.amount *= 100
        self.owner = "Tony"
    }
}
 
// 协议扩展
/*
protocol Person {   // 定义协议
    var firstName:String {get set}
    var lastName:String {get set}
    var fullName:String {get}
}

extension Person { // 定义协议扩展
    func printFullName() {
        print("Print:\(fullName)")
    }
}

class Employee: Person {
    
    var no: Int = 0
    var job: String?
    var salary: Double = 0
    
    var firstName: String = "Tony"
    var lastName: String = "Guan"
    var fullName: String{
        get {
             return self.firstName + "." + self.lastName
        }
        set (newFullName){
            let name = newFullName.components(separatedBy: ".")
            self.firstName = name[0]
            self.lastName = name[1]
        }
    }
}
*/

// 协议继承
/*
protocol Person {   // 定义协议
    var firstName:String {get set}
    var lastName:String {get set}
    var fullName:String {get}
    func description() -> String
}

protocol Studnet : Person {  // 协议继承
    var school:String {get set}
}

class Grauate: Studnet,Person {  // 遵守 Person Student 协议，同时也要遵守 Person 协议
    
    var special: String
    
    var school: String
    var firstName: String
    var lastName: String
    
    var fullName: String {
        return self.firstName + "." + self.lastName
    }
    
    func description() -> String {
        return "firstName:\(firstName) lastName:\(lastName) school:\(school) special:\(special)"
    }
    
    init(firstName:String,lastName:String,school:String,special:String) {
        self.firstName = firstName
        self.lastName = lastName
        self.school = school
        self.special = special
    }
}
*/

// 协议类型
/*
protocol Person {   // 定义协议
    var firstName:String {get set}
    var lastName:String {get set}
    var fullName:String {get}
    
    func description() -> String
}

class Student: Person {
    var school:String
    var firstName: String
    var lastName: String
    
    var fullName: String {
        return self.firstName + "." + self.lastName
    }
    
    func description() -> String {
        return "firstName:\(firstName) lastName:\(lastName) school:\(school)"
    }
    
    init(firstName:String,lastName:String,school:String) {
        self.firstName = firstName
        self.lastName = lastName
        self.school = school
    }
}

class Worker: Person {
    var factory:String
    var firstName: String
    var lastName: String
    var fullName: String {
        return self.firstName + "." + self.lastName
    }
    
    func description() -> String {
        return "firstName:\(firstName) lastName:\(lastName) factory:\(factory)"
    }
    
    init(firstName:String,lastName:String,factory:String) {
        self.firstName = firstName
        self.lastName = lastName
        self.factory = factory
    }
}
*/

// 协议静态属性
/*
protocol Account {  // 定义协议
    static var interestRate:Double {get}
    static func interestBy(amount:Double)->Double
}

class ClassImp: Account {
    static var interestRate: Double {   // 可以是 static 也可以是 class
        return 0.0668
    }
    
    static func interestBy(amount: Double) -> Double {
        return ClassImp.interestRate * amount
    }
}

struct structImp : Account {
    static var interestRate: Double = 0.0668
    
    static func interestBy(amount: Double) -> Double {
        return structImp.interestRate * amount
    }
}

enum enumImp : Account {
    static var interestRate: Double = 0.0668
    
    static func interestBy(amount: Double) -> Double {
        return enumImp.interestRate * amount
    }
}
*/

// 协议实例属性
/*
protocol Person {   // 定义协议
    var firstName:String {get set}  // 读写
    var lastName :String {get set}
    var fullName :String {get}  // 只读
}

class Employee: Person {  // 遵从Person 协议，实现属性
    var no : Int = 0
    var job: String?
    
    var firstName: String = "Tony"
    var lastName: String = "Guan"
    var fullName: String {  // 计算属性，计算属性除了要通过定义Getter 访问实现Person 协议，还定义了没有规定的setter
        get {
            return self.firstName + "." + self.lastName
        }
        set (newFullName){
            let name = newFullName.components(separatedBy: ".")
            self.firstName = name[0]
            self.lastName = name[1]
        }
    }
}
*/

// 协议可变方法
/*
protocol Editable {
    mutating func edit()  // 定义协议可变方法  mutating
}

class ClassImp: Editable {
    var name : String = "classImp"
    func edit() {   // 不需要 mutating
        print("编译ClassImp...")
        self.name = "编译ClassImp..."
    }
}

struct structImp:Editable {
     var name  = "structImp"
    mutating func edit() {
       print("编译structImp...")
        self.name = "编译structImp..."  // 修改属性，必须是 mutating 方法
    }
}

enum enumImp:Editable {
    case Monday
    case Tuesday
    case Wednesday
    case Friday
    mutating func edit() {
        print("编译enumImp...")   // 修改属性，必须是 mutating 方法
        self = .Friday
    }
}
*/


// 定义协议（静态方法）
/*
protocol Account {
    static func interestBy(amount:Double)->Double  // 静态方法
}
class ClassImp : Account {
    // 可以是 static \ class
    static func interestBy(amount: Double) -> Double {
        return 0.0668 * amount
    }
}
struct StructImp: Account {
    // 只能是 static
    static func interestBy(amount: Double) -> Double {
        return 0.0668 * amount
    }
}
enum EnumImp : Account {
     // 只能是 static
    static func interestBy(amount: Double) -> Double {
        return 0.0668 * amount
    }
}
 */


// 定义协议 (实例方法)
/*
protocol Figure {
    func onDraw() // 定义抽象绘制几何图形
}

class Rectangle: Figure {
    func onDraw() {
        print("绘制矩形")
    }
}
class Circle: Figure {
    func onDraw() {
        print("绘制圆形")
    }
}
*/


// MARK: 协议扩展
// 协议中可以声明变量，方便在协议方法中使用
// 协议方法的具体实现，需要在 extension 中实现
// OC无法做到面向协议开发，而Swift可以，因为Swift可以做到协议方法的具体实现，而OC不行
protocol Eatable {
    // 可声明变量
}
// 协议扩展
extension Eatable {
    func eat() {
        // 实现具体功能
        print("吃")
    }
}

class Dog: Eatable { }

// 测试
/* 打印结果  吃
 let dog = Dog()
 dog.eat()
 */

// 协议扩展约束
// 比如说这个协议只能被 Controller 遵守
protocol BackGroundColor {
//    var age: Int {
//        get
//        set
//    }
}
extension BackGroundColor where Self: UIViewController {
    func backgroundcColor() {
        view.backgroundColor = .red
    }
}



extension ViewController {
    
    func testloadNib()  {
        // https://juejin.im/post/59ee05846fb9a0451329dd52  测试面象协议编程
        // 通过遵守协议 而不是通过基类实现继承的方式
        let firstView = FirstTypeView.loadFromNib()
        firstView.frame = CGRect(x: 100, y: 100, width: 100, height: 100)
        
        let secondView = SecondTypeView.loadFromNib()
        firstView.frame = CGRect(x: 200, y: 100, width: 100, height: 100)
        
//       view.addSubview(firstView)
//       view.addSubview(secondView)
    }
    
}
