//
//  ViewController.swift
//  Swift
//
//  Created by WTW on 2019/11/19.
//  Copyright © 2019 WTW. All rights reserved.

// Swift 代码质量: https://zhuanlan.zhihu.com/p/396294862

import UIKit

class ViewController: UIViewController {

        override func viewDidLoad() {
            super.viewDidLoad()
         
        // 查看 swift 版本 : xcrun swift -version
        // swift 语法翻译 https://www.cnswift.org/
        /**
         * swift 最基本的语法变化
         * 1、导入框架使用 import
         * 2、定义标识符 必须声明是变量还是常量
         * 3、语句结束不需要加 ；
         * 4、swift中的打印语句是 print
         */

        //1、导入框架使用 import
        //import UIKit

        //2、定义标识符 必须声明是变量还是常量
        // 格式:   标识符:类型
        // let  定义常量
        // var  定义变量
        //let age : Int = 20
        //var a : Double = 3.14

        // 3、一行语句结束，不需要写 ； 但是如果一行中有多条语句，则还是通过 ; 将其分隔 (不建议一行写多条语句)

        // 4、打印不使用 NSLog  而是使用 print
        //print("hello world");


        /// 常量和变量

        /**
         * 在开发中优先使用常量，只有在需要修改时，再let 改为 var (数据更加安全)
         * 常量的意思：指向的对象不可修改(指针不可以修改)
         */
        // 变量
        //var age : Int = 20;
        //age = 30;

        //常量
        //let A : Double = 3.14;
        //A = 30;

        // swift 中创建对象， 类()
        let view : UIView = UIView(frame: CGRect(x: 0, y: 0, width: 100, height: 100));
        view.backgroundColor = UIColor.red;

        let btn : UIButton = UIButton(type: UIButton.ButtonType.contactAdd);
        btn.center = CGPoint(x: 50, y: 50);
        view.addSubview(btn);
            
            
        // 随机数 生成 1-100的随机数
    //        arc4random()
    //        arc4random_uniform(<#T##__upper_bound: UInt32##UInt32#>)

        print(Int(arc4random()%100) + 1)
        print(Int(arc4random_uniform(100)) + 1)
                
        /// swift 中的数据类型

        /**
         * swift 中的数据类型也有： 整型、浮点型、对象类型、结构体类型等等
         * 整型：
         *  有符号：
         *      Int8 ：有符号8位整型
         *      Int16 ：有符号16位整型
         *      Int32 :  有符号32位整型
         *      Int64 :  有符号64位整型
         *      Int : 和平台无关 (默认,相当于NSInteger)
         *  无符号：
         *      UInt8 ：无符号8位整型
         *      UInt16 ：无符号16位整型
         *      UInt32 :  无符号32位整型
         *      UInt64 :  无符号64位整型
         *      UInt : 和平台无关 (常用，相当于NSUInteger) (默认)
         * 浮点型：
         *      Float : 32位浮点型
         *      Double : 64位浮点型 (默认)
         *  Bool
         *  Character
         *  String
         */

        //var a : Int = 10
        //var c : Float = 10.0
        //var d : Double = 20.0
        var e : Bool = true
        var f : Character = "f"
        var g : String = "string"
        print(type(of: e))
        print(type(of: f))
        print(type(of: g))
        print(e,f,g)

        /**
         * swift 中的类型推导
         * swift 是强类型的语言
         * swift 中任何一个标识符都有明确的类型
         * 注意：
         *  如果定义一个标识符时有直接进行赋值，那么标识符后面的类型可以省略 ( :类型 可以省略)
         *  因为 swift 有类型推导，会自动根据后面的赋值来决定前面的标识符的数据类型
         *  可以通过 option + 鼠标左键 来查看变量的数据类型
         */
        // 类型推导
        //var a = 20;
        //var b = 1.5;

        // 基本运算
        // swift 中的基本运算，要求必须保证类型一致，因为swift中没有隐式类型转换
        //let c = a + b;  这样会报错
        // 将 Double 类型转成 Int 类型的方法： Int(Double 类型标识符)
        // 将 Int 类型转成 Double 类型的方法： Double(Int 类型标识符)
        //let c = a + Int(b);  //21
        //let d = Double(a) + b;  //21.5


        /// 逻辑分支  if、switch、三目运算符等

        /**
         * if 分支语句
         * 判断句可以不加 ()
         * 在swift 的判断句中必须有明确的真假
         *     不再有非0即真
         *     必须有明确的Bool值
         *     Bool有两个取值：false/true
         */

        //let a = 10;
        // 不再有非0就是真
        //if a {
        //    print("a");
        //}

        //if a > 0 {
        //    print("a > 0");
        //}else {
        //    print("a < 0");
        //}

        // 三目运算符号
        let age = 20;
        let result = age == 0 ? "age = 0" : "age = 20";

        
        // MARK: guard 的使用
        /**
         * guard 的使用
         * 与if语句非常类似，设计的目的是提高程序的可读性
         * guard 语句必须带有else 语句，语法如下:
         *      当条件表达式为true时候跳过 else 语句中的内容，执行语句组内容
         *      条件表达式为false时执行else语句中的内容，跳转语句一般是 return 、break 、continue 和 throw
         */

        //guard 条件表达式 else {
        //    //条件语句
        //    break
        //}
        //语句组


        func onLine(age : Int) -> Bool {
            guard age >= 18 else {
                // 为假执行else
                return false
            }
            // 如果为真 继续执行
            print("可以上网");
            return true;
        }
        print(onLine(age: 20)) // true
        print(onLine(age: 17)) // false

        //MARK: switch 基本使用
        /**
         * 使用fallthrougn 可以实现穿透
         * case 中可以判断多个条件 ，通过,(逗号分隔)
         * switch 可以判断浮点型
         * 可以判断字符串
         * 可以判断区间  闭区间：0~10  0...10(包括10)  开区间：0~9   0..<10 (不包括10)
         */

        let sex = 0;
        switch sex {
        case 0:
            print("女")
            //fallthrougn
        case 1:
            print("男")
        default:
            print("其他")
        }

        // 判断多个条件，逗号隔开
        switch sex {
        case 0, 1:
            print("正常人")
        default:
            print("其他")
        }

        // fallthrough 可以实现穿透
        switch sex {
        case 0:
            fallthrough
        case 1:
            print("正常人")
        default:
            print("其他")
        }

        // 浮点型switch 判断
        let sf = 3.14
        switch sf {
        case 3.14:
            print("π")
        default:
            print("not π")
        }

        // 支持区间判断
        let score = 88
        switch score {
        case 0..<60:
            print("不及格")
        case 60..<80:
            print("几个")
        case 80..<90:
            print("良好")
        case 90..<100:
            print("优秀")
        default:
            print("满分")
        }

        /// 循环
        // 常见循环 for 、while、do while

        // for 循环
        // 常规写法 (swift3 已经废弃)
        //for var i = 0 ;i < 10 ;i++ {
        //    print(i);
        //}

        // 区间 for 循环
        for i in 0..<10 {
            print(i);
        }

        for i in 0...10 {
            print(i);
        }

        let str = "hello world";
        for s in str {
            print(s);
        }

        // 特殊写法 （如果 for 循环不需要用到下标）
        for _ in 0..<10 {
            print("hello world");
        }

        // while 和 do while
        /**
         * while 的判断句必须有正确的真假，没有非0 即真
         * while 后面的() 可以省略
         */
        var wa = 0;
        while wa < 10 {
            wa+=1;
            print(wa);
        }

        // do while 循环
        /**
         * 使用repeat关键字来代替了do
         * while 后面的判断条件不存在小括号
         * 判断条件没有非零即真
         */
        var wb = 0
        repeat {
            print(wb)
            wb+=1
        }while wb < 10


        /// 字符串

        /**
         * 在OC中字符串类型是NSString,在Swift中字符串类型是String    OC中字符串@"",Swift中字符串""
         * 使用 String 的原因：
         * String 是一个结构体，性能更高
         * String 支持直接遍历
         * NSString 是一个 OC 对象，性能略差
         * Swift 提供了 String 和 NSString 之间的无缝转换
         */

        // 字符串遍历
        var str1 = "hello world"
        for c in str1 {
            print(c)
        }

        // 字符串拼接
        let str2 = "hello"
        let str3 = "world"
        let str4 = str2 + str3

        // 字符串和其他类型的拼接
        let name = "why"
        let age1 = 20
        let info = "my name is \(name),age is \(age1)"

        // 字符串的格式化 比如时间
        let min = 3
        let second = 4
        let time = String(format: "%02d:%02d",arguments:[min,second])

        // 字符串的截取 hello world
        // 简单的方式就是将 String 转换成 NSString 来使用 使用 as NSString 即可
        var subStr = (str1 as NSString).substring(from: 4)  // o world
        var subStr1 = (str1 as NSString).substring(to: 6)  // hello
        var subStr2 = (str1 as NSString).substring(with: NSRange(location: 5, length: 3)) // wo

        // subStrArr 里的对象是 Substring 类型
        let subStrArr = str1.split(separator: " ")
        // stringArr 里面的对象是 string 类型
        let stringArr = str1.split(separator: " ").map { String($0) }


        /// 数组

        /**
         * 数组（Array）是一串有序的由相同类型元素构成的集合
         * 数组中的集合元素是有序的，可以重复出现
         * swift数组类型是Array，是一个泛型集合
         */

        /**
         * 数组的初始化
         * 数组分成:可变数组和不可变数组
         * 使用let修饰的数组是不可变数组
         * 使用var修饰的数组是可变数组
         * 声明的数组需要进行初始化才能使用，数组类型往往是在声明的同时进行初始化的
         */

        // 定义一个可变数组，必须初始化才能使用
        var array1 : [String] = [String]()
        // 定义一个不可变数组
        let array2 : Array<String> = ["why","123"]
        let array3 : [String] = ["18", "why"]
        let array4 : [Any] = [18, "why", 1.88]
        let array5 = [18, "why", 1.88] as [Any]

        /**
         * 数组的基本操作
         * 添加元素
         * 删除元素
         * 修改元素
         * 取值
         */

        array1.append("hello")  // 添加
        array1[0] = "hello 123" // 修改
        print(array1[0])        // 取值
        array1.remove(at: 0)    // 删除 removeFirst

        // 数组的遍历
        for i in 0..<array1.count {
            print(array1[i])
        }
        // forin 方式
        for item in array2 {
            print(item)
        }
        //设置遍历的区间
        for item in array4[0..<2] {
            print(item)
        }

        // 数组的合并
        // 只有同类型的数组才能合并
        var arr1 = ["why","not","hello"]
        var arr2 = ["world","123"]
        var arr3 = arr1 + arr2;

        // 不建议一个数组中存放多种类型的数据
        //var arr4 = [2, 3, "why"]
        //var arr5 = ["yz", 23]
        //arr4 + arr5


        /// 字典

        /**
         * 字典允许按照某个键来访问元素
         * 字典是由两部分集合构成的，一个是键（key）集合，一个是值（value）集合
         * 键集合是不能有重复元素的，而值集合是可以重复的，键和值是成对出现的
         * Swift字典类型是Dictionary，也是一个泛型集合
         */

        /**
         * 字典的初始化
         * 使用let修饰的数组是不可变字典
         * 使用var修饰的数组是可变字典
         * 声明的字典需要进行初始化才能使用，字典类型往往是在声明的同时进行初始化的
         */
        // 定义一个可变字典
        var dict1 : [String : Any] = [String : Any]();
        // 定义一个不可变字典
        let dict2 = ["name":"why","age":18] as [String : Any]

        var dict3 : Dictionary<Int,String>
        var dict4 : [Int : String]
        var dict5 = ["name" : "why", "age" : 18] as [String : Any]

        var dict6 : Dictionary<String, Any> = ["name" : "why", "age" : 18]

        /**
         * 字典的基本操作
         * 添加数据
         * 删除数据
         * 修改数据
         * 查询数据
         * 字典的遍历
         * 字典的合并
         * 字典的过滤
         */

        
        // 添加数据
        dict1["height"] = 180
        dict1["weight"] = 120

        // 删除字段
        dict1.removeValue(forKey: "height")
        print(dict1)

        //修改数据
        dict1["weight"] = 150

        //查询字典
        print(dict1["weight"]!)

        // 字典的遍历
        dict1["name"] = "xiaohua"
        dict1["sex"] = "男"

        // 遍历字典中所有的值
        for vale in dict1.values {
            print(vale);
        }
        // 遍历字典中所有的键
        for key in dict1.keys {
            print(key);
        }
        //遍历所有的键值对
        for (key,value) in dict1 {
            print(key);
            print(value);
        }

        //字典的合并
        var dict7 = ["name" : "yz", "age" : 20] as [String : Any]
        var dict8 = ["height" : 1.87, "phoneNum" : "+86 110"] as [String : Any]

        for (key, value) in dict7 {
            dict8[key] = value
        }
        print(dict7);
        print(dict8);

        // 字典过滤
        var dict9 : Dictionary<String,String> = ["a":"123","b":"234","c":"345"]
        var new_dict = dict9.filter { (key, value) -> Bool in
            if (key == "b") {
                return true
            }else {
                return false
            }
        }
        print(new_dict)  // 过滤后的结果 ["b": "234"]

        /// 元组
        /**
         * 一旦声明，可以改值，但不能添加/删除元素
         * 不能更改已经声明的元素名称
         * 已声明的名称可以省略，但未声明名称的元组，不可添加名称：
         */
        // 元组的定义
        ("1001", "张三", 30, 90)
        (id:"1001", name:"张三", english_score:30, chinese_score:90)

        // 元组的简单使用 用元组来描述一个HTTP的错误信息
        // 元祖:HTTP错误
        // let array = [404, "Not Found"]
        // 写法一:
        let error1 = (404, "Not Found")
        print(error1.0)
        print(error1.1)

        // 写法二:
        let error2 = (errorCode : 404, errorInfo : "Not Found")
        print(error2.errorCode)
        print(error2.errorInfo)

        // 写法三:
        let (errorCode, errorIno) = (404, "Not Found")
        print(errorCode)
        print(errorIno)


        /// 可选类型

        /**
         *  在OC开发中,如果一个变量暂停不使用,可以赋值为0(基本属性类型)或者赋值为空(对象类型)
         *  在swift开发中,nil也是一个特殊的类型.因为和真实的类型不匹配是不能赋值的(swift是强语言)
         *  但是开发中赋值nil,在所难免.因此推出了可选类型
         *  可选类型的取值：空值  有值
         */

        // 定义可选类型 定义一个可选类型有两种写法 1、最基本的写法  2、语法糖(常用)
        // 写法一
        let string1 : Optional<String> = nil
        // 写法二
        let string2 : String? = nil

        // 可选类型的使用
        // 定义可选类型
        var string : Optional<String> = nil
        string = "Hello world"  // // 给可选类型赋值
        print(string)  // Optional("Hello world")\n

        // 去除可选类型的真实值(解包)
        print(string!)  // Hello world

        //如果可选类型为 nil 强制取出其中的值(解包)，会出错
        //string = nil
        //print(string!) // 报错
        // 正确的写法
        if string != nil {
            print(string!)
        }
        // 简单写法：为了if 语句中可以方便使用string
        if let str = string {
            print(str);
        }

        // 真实应用场景 让代码更加严谨
        // 通过该方法创建的URL,可能有值,也可能没有值
        // 错误写法:如果返回值是nil时,就不能接收了
        //let url : NSURL = NSURL(string: "www.520it.com")

        // 正确写法:使用可选类型来接收
        let url : NSURL? = NSURL(string: "www.520it.com")

        // 通过url来创建request对象
        if let tempUrl = url {
            let request = NSURLRequest(url: tempUrl as URL);
        }

        /// 函数

        /**
         * 函数相当于OC中的方法
         * func 函数名(参数列表) -> 返回值类型 {
         *    代码块
         *    return 返回值
         *}
         *
         * func是关键字,多个参数列表之间可以用逗号（,）分隔，也可以没有参数
         * 使用箭头“->”指向返回值类型
         * 如果函数没有返回值，返回值为Void.并且“-> 返回值类型”部分可以省略
         */
        // 1.没有参数,没用返回值
        func about() -> Void {
            print("iphone6s plus")
        }
        // 调用函数
        about()

        // 简单写法
        // 如果没用返回值,Void可以写成()
        func about1() -> () {
            print("iphone6s plus")
        }
        // 如果没有返回值,后面的内容可以都不写
        func about2() {
            print("iphone6s plus")
        }
        about2()

        // 2.有参数,没用返回值
        func callPhone(phoneNum : String) {
            print("打电话给\(phoneNum)")
        }
        callPhone(phoneNum: "+86 110")

        // 参数是元组类型，没有返回值
        func func_name(param:(name1:String,name2:Int)) ->Void {
            print(param.name1 + " - " + String(param.name2))
        }
        func_name(param: ("hello", 123))

        // 3.没用参数,有返回值
        func readMessage() -> String {
            return "吃饭了吗?"
        }
        print(readMessage())

        // 4.有参数,有返回值
    //    func sum(num1 : Int, num2 : Int) -> Int {
    //        return num1 + num2
    //    }
    //
    //    var result1 = sum(num1: 20, num2: 30)
    //    print(result1)

        // 5、参数是数组，返回值也是数组
        func func_name1(param:[Int]) ->[Int]{
            var array:Array<Int> = []
            for index in 0..<param.count {
                array.append(param[index]*2)
            }
            return array;
        }
        print(func_name1(param: [1,2,3,4,5]))

        /**
         * 函数使用注意：
         * 注意一: 外部参数和内部参数
         *      在函数内部可以看到的参数,就是内部参数
         *      在函数外面可以看到的参数,就是外部参数
         *      默认情况下,从第二个参数开始,参数名称既是内部参数也是外部参数
         *      如果第一个参数也想要有外部参数,可以设置标签:在变量名前加标签即可
         *      如果不想要外部参数,可以在参数名称前加 _
         */

        // num1 和 a、b 是外部参数的名称
    //    func ride(num1 : Int,a num2 : Int,b num3 : Int) -> Int {
    //        return num1 + num2 + num3;
    //    }
    //    var ret1 = ride(num1: 10, a: 20, b: 30);
    //    // 方法的重载 ：方法名称相同，但是参数不同，可以称之为方法的重载
    //    func ride(num1 : Int,_ num2 : Int) ->Int {
    //        return num1 + num2;
    //    }
    //    var ret2 = ride(num1: 30, 20)

        /**
         * 注意二：默认参数
         * 某些情况，如果没有传入具体的参数，可以使用默认参数
         */
        // 默认参数
        func makeCoffee(type : String = "卡布奇诺") -> String {
            return "制作一杯\(type)咖啡";
        }
        let coffee1 = makeCoffee();
        let coffee2 = makeCoffee(type: "拿铁")

        /**
         * 注意三:  可变参数
         * swift中函数的参数个数可以变化，它可以接受不确定数量的输入类型参数
         * 它们必须具有相同的类型
         * 我们可以通过在参数类型名后面加入（...）的方式来指示这是可变参数
         */
        func sum(numbers:Double...) -> Double {
            var total: Double = 0
            for number in numbers {
                total += number;
            }
            return total;
        }
        sum(numbers: 10,20.0,30.0);
        sum(numbers: 10,20)

        /**
         * 注意四：引用类型 (指针的传递)
         * 默认情况下，函数的参数是值传递，如果想要改变外面的变量，则需要传递变量的地址
         * 必须是变量，因为需要在内部改变其值
         * swift 提供的 inout 关键字可以实现
         */

        func swap1( a : inout Int, b : inout Int) {
            let temp = a;
            a = b;
            b = temp;
            print("a:\(a),b:\(b)");
        }
        var a = 10
        var b = 20
        swap1(a: &a, b: &b)
        print("a:\(a),b:\(b)");

        // 函数作为参数传递给另外一个函数
        func sum1(a: Int, b: Int) -> Int {
            return a + b
        }
        var addition: (Int, Int) -> Int = sum1
        print("输出结果：\(addition(40, 89))")

        func another(addition: (Int, Int) -> Int, a: Int, b: Int) {
            print("输出结果：\(addition(a, b))")
        }
        another(addition: sum1, a: 10, b: 20)

        //函数的嵌套使用
        let value = 55;
        func test(){
            func demo() {
                print("hello demo value:\(value)");
            }
            print("test");
            demo();
        }
        test();


        /// 类的定义

        /**
         * 面向对象的基础是类，类产生了对象
         *class 类名 ： SuperClass {
         *   // 定义属性和方法
         *}
         * 定义的类，可以没有父类，那么该类就是 rootClass
         * 通常情况下定义类时，继承自 NSObject
         */

        /**
         * 定义类的属性
         * 存储属性：存储实例的常量和变量
         * 计算属性：通过某种方式计算出来的属性
         * 类属性：与整个类自身相关的属性
         */

        /**
         * 存储属性 ：
         * 作为类实例的一部分，用于存储常量和变量
         * 可以给存储属性提供一个默认值，也可以在初始化方法中对其进行初始化
         * age和name都是存储属性,用来记录该学生的年龄和姓名
         * chineseScore和mathScore也是存储属性,用来记录该学生的语文分数和数学分数
         */

        class Student : NSObject {
            //定义属性
            //存储属性
            var age : Int = 0
            var name : String?

            var chineseScore : Double = 0.0
            var mathScore : Double = 0.0
        }
        // 创建学生对象
        let stu = Student()

        // 给存储属性赋值
        stu.age = 10
        stu.name = "why"

        stu.chineseScore = 89.0
        stu.mathScore = 98.0


        /**
         * 计算属性：
         * 计算属性并不存储实际的值，而是提供一个getter和一个可选的setter来间接获取和设置其它属性
         * 计算属性一般只提供getter方法
         * 如果只提供getter，而不提供setter，则该计算属性为只读属性,并且可以省略get{}
         * averageScore是计算属性,通过chineseScore和mathScore计算而来的属性
         * 在setter方法中有一个newValue变量,是系统指定分配的
         *
         */
        class Student1 : NSObject {
            // 定义属性
            // 存储属性
            var age : Int = 0
            var name : String?

            var chineseScore : Double = 0.0
            var mathScore : Double = 0.0

            // 计算属性
            var averageScore : Double {
                get {
                    return (chineseScore + mathScore) / 2
                }

                // 没有意义.newValue是系统分配的变量名,内部存储着新值
                set {
                    self.averageScore = newValue
                }
            }
        }
        let stu1 = Student1()

        // 获取计算属性的值
        print(stu1.averageScore)

        /**
         * 类属性
         * 类属性是与类相关联的，而不是与类的实例相关联
         * 所有的类和实例都共有一份类属性.因此在某一处修改之后,该类属性就会被修改
         * 类属性的设置和修改,需要通过类来完成
         *      类属性使用static来修饰
         *      courseCount是类属性,用来记录学生有多少门课程
         */
        class Student2 : NSObject {
            // 定义属性
            // 存储属性
            var age : Int = 0
            var name : String?

            var chineseScore : Double = 0.0
            var mathScore : Double = 0.0

            // 计算属性
            var averageScore : Double {
                get {
                    return (chineseScore + mathScore) / 2
                }

                // 没有意义.newValue是系统分配的变量名,内部存储着新值
                set {
                    self.averageScore = newValue
                }
            }

            // 类属性
            static var corseCount : Int = 0
        }
        // 设置类属性的值
        Student2.corseCount = 3
        // 取出类属性的值
        print(Student2.corseCount)

        /**
         * 监听属性的变化
         * 在OC中我们可以重写set方法来监听属性的改变
         * Swift中可以通过属性观察者来监听和响应属性值的变化
         * 通常是监听存储属性和类属性的改变.(对于计算属性，我们不需要定义属性观察者，因为我们可以在计算属性的setter中直接观察并响应这种值的变化)
         * 我们通过设置以下观察方法来定义观察者：
         *      willSet：在属性值被存储之前设置。此时新属性值作为一个常量参数被传入。该参数名默认为newValue，我们可以自己定义该参数名
         *      didSet：在新属性值被存储后立即调用。与willSet相同，此时传入的是属性的旧值，默认参数名为oldValue
         *      willSet与didSet只有在属性第一次被设置时才会调用，在初始化时，不会去调用这些监听方法
         */

        // 监听的方式如下：
        // 监听 age 和 name 的变化
        class Person : NSObject {
            var name : String  = "123" {
                //可以给newValue自定义名称
                willSet (new) {   // 属性即将改变,还未改变时会调用的方法
                    //在该方法中有一个默认的系统属性newValue,用于存储新值
                    print(name);  // 123
                    print(new);   // why
                }
                //可以给oldValue自定义名称
                didSet (old) {    // 属性值已经改变了,会调用的方法
                    // 在该方法中有一个默认的系统属性oldValue,用于存储旧值
                    print(name);  // why
                    print(old);   // 123
                }
            }
            var age : Int = 0;
            var height : Double = 0.0;
        }
        let p : Person = Person();
        // 在赋值时,监听该属性的改变
        // 在OC中是通过重写set方法
        // 在swift中,可以给属性添加监听器
        p.name = "why";


        /// 类的构造函数
        /**
         * 构造函数类似于OC中的初始化方法:init方法
         * 默认情况下载创建一个类时,必然会调用一个构造函数
         * 即便是没有编写任何构造函数，编译器也会提供一个默认的构造函数。
         * 如果是继承自NSObject,可以对父类的构造函数进行重写
         */

        /**
         * 构造函数的基本使用：
         * 类的属性必须有值
         * 如果不是在定义时初始化，可以在构造函数中赋值
         */
        class Person1: NSObject {
            var name : String
            var age : Int

            // 重写了NSObject(父类)的构造方法
            override init() {
                name = ""
                age = 0
            }
        }
        // 创建一个Person对象
        let person = Person1()

        /**
         * 初始化时给属性赋值
         * 很多时候，创建一个对象时就会给属性s赋值
         * 可以自定义构造函数
         * 如果自定了构造函数，会覆盖 init() 方法，即不再有默认的构造函数
         */
        class Person2 : NSObject {
            var name : String
            var age : Int
            
            //自定义构造函数，会覆盖 init() 函数
            init(name : String,age : Int) {
                self.name = name;
                self.age = age;
            }
        }
        // 创建一个 Person 对象
        let person2 = Person2(name: "why", age: 18);

        /**
         * 字典转模型(初始化时传入字典)
         * 真实创建对象时，更多的是将字典转成模型
         *      去字典中取出的是 NSObject 任意类型
         *      可以通过 as! 转成需要的类型，再赋值(不可以直接赋值)
         */
        class Person3: NSObject {
            var name : String
            var age : Int

            // 自定义构造函数,会覆盖init()函数
            init(dict : [String : NSObject]) {
                name = dict["name"] as! String
                age = dict["age"] as! Int
            }
        }
        // 创建一个Person对象
        let dict = ["name" : "why", "age" : 18] as [String : Any]
        let person3 = Person3(dict: dict as! [String : NSObject])


        /**
         * 字典转模型(利用KVC)
         * 利用 KVC 字典转模型会更加方便
         * 因此属性需要有默认值
         *      基本数据类型默认值设置为0
         *      对象或者结构体类型定义为可选类型即可(可选类型没有赋值前为nil)
         */
        class Person4: NSObject {
            // 结构体或者类的类型,必须是可选类型.因为不能保证一定会赋值
            var name : String?

            // 基本数据类型不能是可选类型,否则KVC无法转化
            var age : Int = 0

            // 自定义构造函数,会覆盖init()函数
            init(dict : [String : NSObject]) {
                // 必须先初始化对象
                super.init()

                // 调用对象的KVC方法字典转模型
                setValuesForKeys(dict)
            }
        }
        // 创建一个Person对象
        //let d = ["name" : "why", "age" : "18"] as [String : Any]
        //let person4 = Person4(dict: d)


        /// 闭包

        /**
         * OC中的block是匿名的函数
         * Swift中的闭包是一个特殊的函数
         * block和闭包都经常用于回调
         */

        //block的写法:
        //类型:
        //返回值(^block的名称)(block的参数)
        //
        //值:
        //^(参数列表) {
        //    // 执行的代码
        //};

        /**
         * 闭包的写法：
         * 类型：(形参列表)->(返回值)
         * 值：
         *{
         *(形参) ->返回值类型  in
         *执行代码
         *}
         *
         * 闭包的简写：
         * 如果闭包没有参数，没有返回值 ,in 和 in 之前的内容可以省略
         *
         *尾随闭包的写法：
         *  如果闭包是函数的最后一个参数，则可以将闭包写在 () 后面
         *  如果函数只有一个参数，并且这个参数是闭包，那么 () 可以不写
         */

        // 定义网络请求的类
        // 进行网络请求，请求到数据后利用闭包进行回调

        class HttpTool : NSObject {
            func loadRequest(callBack : @escaping ()->()){
                DispatchQueue.global().async {
                    print("加载数据",Thread.current)
                }
                DispatchQueue.main.async{
                    callBack();
                }
            }
        }

        var httpTool = HttpTool()
        httpTool.loadRequest {
            print("result")
        }

        /// 懒加载

        /**
         * 和 OC 不一样的是 Swift 提供了专门的关键字来实现懒加载
         * lazy 关键字可以用于定义某一个属性懒加载
         * 懒加载的格式：
         * lazy var  变量 ： 类型 = {创建变量的代码}()
         */
        // 懒加载的使用 1
        class viewController : UIViewController {
            lazy var button : UIButton = {
                let button = UIButton.init(type:.custom)
                button.titleLabel!.font = UIFont.systemFont(ofSize: 16)
                return button;
            }()
        }

        // 懒加载的使用 2
        class lazyTest : NSObject {
            // 懒加载的本质是,在第一次使用的时候执行闭包,将闭包的返回值赋值给属性
            // lazy的作用是只会赋值一次
            lazy var array : [String] = {
                () -> [String] in
                return ["why", "lmj", "lnj"]
            }()
        }
        var lazytest = lazyTest()
        print(lazytest.array)



        /// 协议 protocol
            /*
        class TestProtocol {
            
        }

        protocol Protocol1 {
            var value1 : String{get}

            func play1() -> String
        }

        protocol Protocol2 {
            var value2 : String {get set}
            
            func play2() -> String
        }

        class Data : TestProtocol,Protocol1,Protocol2 {
            var value1: String{
                return "value1"
            }
            
            var value2: String
            
            func play1() -> String {
                return self.value1
            }
            
            func play2() -> String {
                return self.value2
            }
            
            init(value2:String) {
                self.value2 = value2
            }
        }
        var data = Data(value2: "hello")
        print(data.play1())
        print(data.play2())
        print(data.value1)
        print(data.value2)
             */

            /// 自动内存释放   反初始化 deinit

            class TestA{
                
                var name:String
                
                weak var ref:TestB? = nil   // weak 弱引用就可以避免循环引用
                
                init(name:String) {
                    self.name = name
                }
                
                deinit {
                    print("TestA实例被释放了" + self.name)
                }
            }

            class TestB {
                
                var name:String
                
                weak var ref:TestA? = nil
                
                init(name :String) {
                    self.name = name
                }
                
                deinit {
                    print("TestB实例被释放了" + self.name)
                }
            }

            var testA:TestA? = TestA(name: "我是TestA")
            //print(testA!.name)  // 我是TestA
            //testA = nil         // TestA实例被释放了我是TestA
            //print(testA?.name)  // nil

            var testB = TestB(name: "我是TestB")
            //print(testB.name)   // 我是TestB


            /// 循环强引用  弱引用 weak

            testA!.ref = testB   // A 引用 B
            testB.ref = testA    // B 引用 A

            //testB.ref = nil  // 这样就可以释放

            testA = nil
            //testB = nil


            
        }
        


    }

