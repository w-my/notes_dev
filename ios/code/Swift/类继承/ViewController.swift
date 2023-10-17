//
//  ViewController.swift
//  类继承
//
//  Created by WTW on 2020/1/20.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Swift 中的继承只能在类上，不能在枚举和结构体上
        // Swift 中的类可以没有父类，这种没有父类的就是基类，OC 中所有的类的基类是NSObject ,Swift 中没有这样一个类
        // override init() 是子类重写父类的构造函数
        // 一般情况下，一个类继承一个父类(单继承)，但有的情况下一个子类可以有多个不同的父类，称为多继承
        // 在 Swift 中只能有单继承，而多继承可以通过遵从多个协议来实现
        
        // MARK: 构造函数继承
        // 构造函数代理分为 横向代理 和 向上代理
        // 横向代理只发生在同一类内部，这种构造函数叫做 便利构造函数
        // 向上代理发生在继承的情况下，在子类构造过程中，要先调用父类构造函数初始化父类的存储属性，这种构造函数称为 指定构造函数
        
        //1、 构造函数调用规则 如下三点：
        // 指定构造函数必须调用其直接父类的指定构造函数
        // 便利构造函数必须调用同一类中定义的其他构造函数
        // 便利构造函数必须最终调用一个指定构造函数结束
        
        /*
        class Person {
            var name:String
            var age:Int
            
            func description() -> String {
                return "\(name) 年龄是 :\(age)"
            }
            
            convenience init() {  // 便利构造函数
                self.init(name:"Tony")
                self.age = 18
            }
            
            // 便利构造函数必须最终调用一个指定构造函数结束
            convenience init(name :String) {  // 便利构造函数
                self.init(name:name,age:18)
            }
            
            init(name:String,age:Int) {  // 指定构造函数
                self.name = name
                self.age = age
            }
        }
        
        class Student : Person {
            var school : String
            
            // 指定构造函数必须调用其直接父类的指定构造函数
            init(name:String,age:Int,school:String){  // 指定构造函数
                self.school = school
                super.init(name:name,age:age)
            }
            
            // 便利构造函数必须调用同一类中定义的其他构造函数
            // 便利构造函数必须最终调用一个指定构造函数结束
            override convenience init(name: String, age: Int) {  // 便利构造函数
                self.init(name:name,age:age,school:"清华大学")
            }
        }
        
        let student = Student()
        print(student.description())
        */
        
        //2、构造函数安全检查
        // Swift 中类的构造过程分为2个阶段：
        // 第一阶段：分配内存，初始化子类存储属性，沿构造函数链向上初始化父类存储属性，到达构造函数链顶部，初始化全部的父类存储属性
        // 第二阶段：从顶部构造函数往下，可以对每个类进行进一步修改存储属性、调用实例方法等处理
        
        //3、构造函数继承
        // 子类构造函数有两种来源：
        // 1、自己编写
        // 2、父类继承，能从父类继承下来的构造函数是有条件的
        // 条件1 : 如果子类没有定义任何指定构造函数，将自动继承父类的所有指定构造函数
        // 条件2 : 如果子类提供了所有父类指定的构造函数的实现，无论是通过条件1继承来的，还是自己编写实现的，都将自动继承父类的所有便利构造函数
        /*
        class Person {
            var name:String
            var age:Int
            
            func description() -> String {
                return "\(name) 年龄是 :\(age)"
            }
            
            convenience init() {  // 便利构造函数
                self.init(name:"Tony")
                self.age = 18
            }
            
            // 便利构造函数必须最终调用一个指定构造函数结束
            convenience init(name :String) {  // 便利构造函数
                self.init(name:name,age:18)
            }
            
            init(name:String,age:Int) {  // 指定构造函数
                self.name = name
                self.age = age
            }
        }
        
        class Student : Person {
            var school : String
            
            // 指定构造函数必须调用其直接父类的指定构造函数
            init(name:String,age:Int,school:String){  // 指定构造函数
                self.school = school
                super.init(name:name,age:age)
            }
            
            // 便利构造函数必须调用同一类中定义的其他构造函数
            // 便利构造函数必须最终调用一个指定构造函数结束
            override convenience init(name: String, age: Int) {  // 便利构造函数
                self.init(name:name,age:age,school:"清华大学")
            }
        }
        
        // 没有定义任何构造函数，将自动继承Student 的所有指定构造函数
        // 提供了所有父类指定的构造函数的实现，无论是通过条件1继承来的，还是自己编写实现的，都将自动继承父类的所有便利构造函数
        class Graduate : Student {
            var special:String = ""
        }
        
        let student = Student()
        print(student.description())
        */
        
        // MARK: 重写
        // 一个类继承了另一个类的属性、方法、下标等特征后，子类可以重写(override)这些特征
        
        // 1、重写实例属性
        // 实例属性的重写可以重写 setter 和 getter 访问器，也可以重写属性观察者
        // 可以通过getter 和 setter 访问器重写父类的存储属性和计算属性
        
        /*
        class Person {
            var name:String
            var age:Int
            
            func description() -> String {
                return "\(name) 年龄是 :\(age)"
            }
            
            init(name:String,age:Int) {  // 指定构造函数
                self.name = name
                self.age = age
            }
        }
        
        class Student : Person {
            var school : String
            
            //1、 重写 getter 和 setter 的方式
//            override var age: Int {
//                get {
//                    return super.age
//                }
//                set {
//                    super.age = newValue < 8 ? 8 : newValue
//                }
//            }
            
            // 2、重写访问器观察者的方式
            // 一个属性重写了观察者就不能同时重写 getter 和 setter
            // 常量属性 和 只读计算属性不能重写属性观察者
            override var age: Int {
                willSet {
                    print("newValue: \(newValue)")
                }
                didSet {
                    print("oldValue : \(oldValue)")
                }
            }
            
            
            convenience override init(name: String, age: Int) {  // 便利构造函数
                self.init(name:name,age:age,school:"清华大学")
            }
            
            init(name:String,age:Int,school:String){  // 指定构造函数
                self.school = school
                super.init(name:name,age:age)
            }
        }
                    
        let student1  = Student(name: "Tony1", age: 8)
        print(student1.age)
        student1.age = 10
        print(student1.age)
        */
        
        // 2、重写静态属性
        // 类中静态属性使用 class 和 static 关键字
        // class 子类中可以重写
        // static 子类中不能重写
        /*
        class Account {
            var amount:Double = 0.0
            var owner: String = ""
            
            var interestRate:Double = 0.0668
            
            // static 则子类中不能重写该属性
            class var staticProp:Double {
                return 0.0668 * 10_000
            }
            
            var instanceProp : Double {
                return self.interestRate * self.amount
            }
        }
        class TermAccount : Account {
            override var instanceProp: Double {
                return 0.07 * 10_000
            }
        }
        // 访问静态属性
        print(Account.staticProp)
        print(TermAccount.staticProp)
        */
        
        // 3、重写实例方法
        /*
        class Person {
           var name:String
           var age:Int
           
           func description() -> String {
               return "\(name) 年龄是 :\(age)"
            }
            
            init(name:String,age:Int) {
                self.name = name
                self.age = age
            }
            
            class func printClass() -> () {
                print("Person printClass")
            }
        }
        
        class Student : Person {
            var school:String
            
            init(name:String,age:Int,school:String) {
                self.school = school
                super.init(name: name, age: age)
            }
            
            convenience init(){
                self.init(name:"Tony",age:20,school:"清华大学")
            }
            
            // 重写实例方法
            override func description() -> String {
                print("父类打印 \(super.description())")
                return "\(name) 年龄 \(age), 学校：\(school)"
            }
            
            override class func printClass() {
                print("studnet printClass")
            }
        }
        
        let studnet = Student()
        print(studnet.description())
        
        Student.printClass()
        Person.printClass()
        */
        
        // 4、重写静态方法
        // 与类的静态属性类似，静态方法使用 class 和 static 关键字，但是使用哪一个要看子类是否需要重写该方法
        
        // 5、下标重写
        // 子类属性重写是重写属性的 getter 和 setter ，对下标的重写也是重写 下标的 getter 和 setter 访问器
        
        // 6、使用 final 关键字
        // 可以在类的定义中使用final 关键字声明类、属性、方法和下标
        // final 声明的类不能被继承，final 声明的属性、方法 和 下标不能被重写
        /*
        final class Person {
            var name : String
            
            final var age : Int
            
            final func description()->String{
                return "\(name) 年龄是：\(age)"
            }
            
            init(name:String,age:Int) {
                self.name = name
                self.age = age
            }
        }
        
//        class Studnet: Person {  // 编译错误 final类不能继承
//            var school : String
//
//            init(name:String,age:Int,school:String){
//                self.school = school
//                super.init(name: name, age: age)
//            }
            // 编译错误 属性不能被重写
//          final var age : Int {
//                set{
//                    super.age = newValue < 8 ? 8 : newValue
//                }
//                get {
//                    return super.age
//                }
//            }
        
//            convenience init(){
//                self.init(name:"Tony",age:20,school:"清华大学")
//            }
//
            // 编译错误 final 方法不能被重写
//            override func description()->String {
//                print("父类打印 \(super.description())")
//                return "\(name) 年龄 \(age), 学校：\(school)"
//            }
//        }
        */
        
        //MARK: required
        /*
         用 required 修饰的指定构造函数(便利构造函数不行)，表明其所有子类必须实现该指定构造函数(通过继承或者重写实现)
         如果子类重写了 required 构造函数，也必须加上 required ，不用加 override
         */
        /*
        class Person1 {
            required init(){}
            init(age: Int) {}
        }
        class Student1: Person1 {
            init(no: Int) {
                super.init(age: 0)
            }
            override init(age: Int) {
                super.init(age: age)
            }
            required init() {
                super.init()
            }
        }
        let s = Student1()
        */
        

        // MARK: 属性观察器
        /*
         父类的属性在它自己的初始化器中赋值不会触发属性观察器，但在子类的初始化器中赋值会触发属性观察器
         */
        /*
        class Person1 {
            var age: Int {
                willSet {
                    print("willSet",newValue)
                }
                didSet {
                    print("didSet",oldValue,age)
                }
            }
            init() {
                // 并不会触发属性观察器
                self.age = 0
            }
        }
        
        class Student1: Person1 {
            override init() {
                super.init()
                // 子类初始器中赋值会触发属性观察器
                self.age = 1
            }
        }
        
        //willSet 1  didSet 0 1
        var stu = Student1()
        */
        
        //MARK: 可失败的初始化器
        /*
         类 结构体 和 枚举都可以使用 init？ 定义可失败的初始化器
         不允许同时定义参数标签、参数个数、参数类型相同的可失败初始化器和非可失败初始化器
         可以用 init! 定义隐式解包的可失败初始化器
         可失败初始化器可以调用非可失败初始化器，非可失败初始化器调用可失败初始化器需要进行解包
         如果初始化器调用一个可失败初始化器导致初始化失败，那么整个初始化过程都失败，并且之后的代码都停止执行
         */
        /*
        class Person1 {
            var name: String?
            init?(name: String) {  // init? 可失败的初始化器
                if name.isEmpty {
                    return nil
                }
                self.name = name
            }
        }
        
        var person1 = Person1(name: "")
        print(person1)  // nil
        var person2 = Person1(name: "hello")
        print(person2)  // Person1
        */
        
        // MARK: 类型检查与转换
        // is as 操作符
        // Any AnyObject 类型
        
        class Person {
            var name:String
            var age:Int
            
            func description() -> String {
                return "\(name) 年龄是 :\(age)"
            }
            
            init(name:String,age:Int) {  // 指定构造函数
                self.name = name
                self.age = age
            }
            convenience init() {  // 便利构造函数
                self.init(name:"Tony")
                self.age = 18
            }
            
            // 便利构造函数必须最终调用一个指定构造函数结束
            convenience init(name :String) {  // 便利构造函数
                self.init(name:name,age:18)
            }
        }
        
        class Student : Person {
            var school : String
            
            init(name:String,age:Int,school:String){  // 指定构造函数
                self.school = school
                super.init(name:name,age:age)
            }
        }
           
        class Worker : Person {
            var factory : String
            
            init(name: String, age: Int,factory:String) {
                self.factory = factory
                super.init(name: name, age: age)
            }
        }
        
        // 1、使用 is 进行类型检查
        // is 操作符可以判断一个实例是否是某个类的类型，如果是返回 true 不是返回false
//        let stu1 = Student(name: "小明", age: 20, school: "清华")
//        print(stu1 is Student)  // true
//        print(stu1 is Person)  // true
//        print(stu1 is Worker) // false
        
        // 2、使用 as  as!  as？ 进行类型转换
        // 并不是所有的类型都能相互转换
        // 对象转换一定是发生在继承的前提下的
        // 类型转换有两个方向：
        // 1、将父类转换为子类类型，向下转型
        // 2、将子类转换为父类类型，向上转型
        // 通常情况下都是向下转型，向上转型很少见
        let p1 : Person = Student(name: "小明", age: 20, school: "清华")
        let p2 : Person = Worker(name: "小花", age: 20, factory: "清华")
        let p3 : Person = Person(name: "小明", age: 20)
        let p4 : Student = Student(name: "Ben", age: 40, school: "清华")
        let p5 : Worker = Worker(name: "Tony", age: 28, factory: "华为")
        
        // as 操作符 仅应用于向上转型，很少见
        let p41 : Person = p4 as Person

        
        // as! 操作符
        // 在类型转换过程中对可选值进行拆包，转换的结果是非可选类型
        // 主要有两种情况：
        // 将非可选的类型转换成非可选类型
        // 将可选类型转换成非可选类型
        
        //示例
        // 向下转型 as!
        // 非可选的类型转换成非可选类型
        let p11 = p1 as! Student
//        let p111 = p2 as! Student  // 编译异常
        
        // 可选类型转换成非可选类型
        let p6 : Person? = Student(name: "Tony", age: 20, school: "清华")
        let p12 = p6 as! Student
        print(p12)
        
        // as? 操作符
        // 在转换的过程中不进行拆包，转换的结果是可选类型
        // 主要作用有两种：
        // 非可选 -> 可选
        // 可选 -> 可选
        
        // 非可选 -> 可选
        let p21 = p1 as? Student
        // 如果不能转换成目标类型，会为nil 而不会像上面的编译错误
        let p211 = p2 as? Student  // nil
        
        // 可选 -> 可选
        let p22 = p6 as? Student
        
        
        // 在使用 as? 操作符进行类型转换时，最好采用可选绑定方式
        // 也就是将转换语句放到if 或者 while 语句中，如下示例：
        let student1 = Student(name: "Tom", age: 18, school: "清华")
        let student2 = Student(name: "Ben", age: 19, school: "北大")
        let student3 = Student(name: "Tony", age: 30, school: "人大")
        
        let worker1 = Worker(name: "Tom", age: 20, factory: "电厂")
        let worker2 = Worker(name: "Tony", age: 25, factory: "钢厂")
        
        let people = [student1,student2,student3,worker1,worker2]
        for item in people {
            // 如果转换成功 item 赋值给 Student 变量，否则将 nil 赋值给 Student 变量
            if let student = item as? Student {
                print("Studnet school:\(student.school)")
            }else if let worker = item as? Worker {
                print("Worker factory :\(worker.factory)")
            }
        }
        
        
        // Any  AnyObject
        // AnyObject 可以表示任何类的类型
        // Any 可以表示任何类型，包括类 和 其他数据类型 ，包括 基本数据类型 和 AnyObject类型
        
        // AnyObject 可以和 OC 的id 互换,但是两者本质不同
        // id 是泛型，代表任何对象的指针类型，编译的时候不检查 id 类型,是动态的
        // AnyObject 是一个实实在在表示类的类型，编译时编译器会检查 AnyObject 类型
        
        // 原则上若能够使用具体的数据类型就不要使用 AnyObject 类型，更要少考虑使用 Any 类型
        // 从集合中取实例时，尽量将 AnyObject 类型转换成特定类型
    }


}

