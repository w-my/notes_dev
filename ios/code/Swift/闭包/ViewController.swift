//
//  ViewController.swift
//  闭包
//
//  Created by WTW on 2020/1/20.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
       
        
        let dict = ["1": "value1","2":"value2","3":"value3","4":"value4"]
        
        dict.map { (key: String, value: String)) -> T in
            
        }
        
        
        // MARK:- 概念
        // 一门语言支持闭包的两个前提：
        // 支持函数类型，能够将函数作为参数或者返回值传递
        // 支持函数嵌套
        // 闭包是特殊的函数，当函数作为参数或者返回值，或者匿名函数时，称为闭包
        // 函数和闭包都是引用类型，无论将函数或闭包赋值给一个常量还是变量，实际上都是将常量或变量的值设置为对应的函数或闭包的引用，指向同一个闭包
        
        //swift 中可以通过func 定义一个函数，也可以通过闭包表达式定义一个函数
        func sum(_ v1: Int,_ v2: Int)->Int {
           return v1 + v2
        }

       let fn = {
            (v1:Int,v2:Int) -> Int in
            return v1+v2
        }

        print(fn(10,20))
        print(sum(10, 20))
        
        
        // 返回值是函数
         func calculate(opr:String)->(Int,Int)->Int {
             // 定义 + 函数
             func add(a:Int,b:Int)->Int {
                 return a+b
             }
             // 定义 - 函数
             func sub(a:Int,b:Int)->Int {
                 return a-b
             }

             var result:(Int,Int)->Int

             switch opr {
             case "+":
                 result = add
             case "-":
                 result = sub
             default:
                 result = add
             }
             return result
         }

         let f1:(Int,Int)->Int = calculate(opr: "+")
         print("10 + 5 = \(f1(10,5))")

         let f2:(Int,Int)->Int = calculate(opr: "-")
         print("10 - 5 = \(f2(10,5))")

        
        // 以上代码使用闭包替换如下
        func calculate1(opr:String) ->(Int,Int)->Int {
            var result :(Int,Int)->Int
            
            switch opr {
            case "+":
                result = {
                    (a:Int,b:Int)->Int in
                    return a + b
                }
            case "-":
                result = {
                    (a:Int,b:Int)->Int in
                    return a - b
                }
            default:
                result = {
                    (a:Int,b:Int)->Int in
                    return a + b
                }
            }
            
            return result
        }
        let f11:(Int,Int)->Int = calculate1(opr: "+")
        print("10 + 5 = \(f11(10,5))")
        
        let f22:(Int,Int)->Int = calculate1(opr: "-")
        print("10 - 5 = \(f22(10,5))")
        
        
        // MARK:闭包定义：
        // 闭包是 自包含的匿名函数代码块，可以作为表达式、函数参数、和函数返回值，闭包表达式的运算结果是一种函数类型
        
        
        // MARK:- 闭包表达式
        /*
        // 标准语法格式
        {
            (参数列表) -> 返回值类型 in
            函数体代码
        }
        */
        
        //MARK: 闭包常见简化写法
        
        // 1、类型推断简化
        // swift 可以根据上下文环境推断出参数类型和返回值类型

        /*
        // 标准形式的闭包
        {(a:Int,b:Int) -> Int in
            return a + b
        }

        // 简化后
        {(a,b) in return a + b}
        { a,b in return a + b }  // 参数列表的括号也可以省略
       
         func calculate(opr:String) ->(Int,Int)->Int {
             var result :(Int,Int)->Int
             
             switch opr {
             case "+":
                 result = {a,b in return a + b}
             case "-":
                 result = {a,b in return a - b}
             default:
                 result = {(a,b) in return a + b}
             }
             return result
         }
         let f1:(Int,Int)->Int = calculate(opr: "+")
         print("10 + 5 = \(f1(10,5))")
         
         let f2:(Int,Int)->Int = calculate(opr: "-")
         print("10 - 5 = \(f2(10,5))")
         */
                
        // 2、隐藏 return 关键字
        // 如果闭包内部语句组只有一条语句，比如 return a+b,前面的 return 也是可以省略的
        
        /*
        // 省略形式如下：
        {a,b in a+b}
        
        // 简化后
        func calculate(opr:String) ->(Int,Int)->Int {
            var result :(Int,Int)->Int
            
            switch opr {
            case "+":
                result = {a,b in  a + b}
            case "-":
                result = {a,b in  a - b}
            default:
                result = {(a,b) in  a + b}
            }
            return result
        }
        let f1:(Int,Int)->Int = calculate(opr: "+")
        print("10 + 5 = \(f1(10,5))")
        
        let f2:(Int,Int)->Int = calculate(opr: "-")
        print("10 - 5 = \(f2(10,5))")
        */
        
        // 3、省略参数名
        // 还可以再进行简化，swift 中提供了参数名省略功能，可以用 $0 $1 $2... 来指定闭包中的参数：$0 代表第一个参数，$1 指代第二个参数，依次类推
       // 参数列表省略了，in 关键字也需要省略
       
        /*
        {$0 + $1}
         
         func calculate(opr:String) ->(Int,Int)->Int {
             var result :(Int,Int)->Int
             
             switch opr {
             case "+":
                 result = {$0 + $1}
             case "-":
                 result = {$0 - $1}
             default:
                 result = {$0 + $1}
             }
             return result
         }
         let f1:(Int,Int)->Int = calculate(opr: "+")
         print("10 + 5 = \(f1(10,5))")
         
         let f2:(Int,Int)->Int = calculate(opr: "-")
         print("10 - 5 = \(f2(10,5))")
        */
        
        // 4、使用闭包返回值
        // 闭包表达式本质上是函数类型，是有返回值的，可以直接在表达式中使用闭包的返回值。从新修改add 和 sub 闭包
        let c1: Int = {(a:Int,b:Int) -> Int in
            return a + b
        }(10,5)
        print("10+5=\(c1)")
        
        
        // MARK:-使用尾随闭包
        // 闭包表达式可以作为函数的参数传递
        // 尾随闭包是一个书写在函数括号之后的闭包表达式，函数支持将其作为最后一个参数调用
        /*
        func calculate(opr:String,funN:(Int,Int)->Int){ // funN 是函数类型 funN 可以接受闭包表达式
            switch opr {
            case "+":
                print("10 + 5 = \(funN(10,5))")
            case "-":
                print("10 - 5 = \(funN(10,5))")
            default:
                print("10 - 5 = \(funN(10,5))")
            }
        }
        
        calculate(opr: "+", funN: {(a:Int,b:Int)->Int in return a+b})  //  {(a:Int,b:Int)->Int in return a+b} 是传递的参数，参数很长
        calculate(opr: "+"){(a:Int,b:Int)->Int in return a+b}  // 将闭包表达式转移到()之外，这种形式叫做尾随闭包
        calculate(opr: "+"){$0 + $1}
        
        calculate(opr:"-"){
            (a:Int,b:Int)->Int in
            return a - b
        }
        calculate(opr: "-"){
            $0 - $1
        }
        */
        
        
        // MARK:-捕获上下文中的变量和常量
        // 嵌套函数或闭包可以访问它所在上下文的变量和常量，这个过程称为捕获值
        // 即便是定义这些常量和变量的原始作用域已经不存在，嵌套函数或闭包仍然可以在函数体内或闭包体内引用和修改这些值
        
//        func makeArray()-> (String)->[String]{
//            // 局部变量
//            var arr:[String] = [String]()
//
//            func addElement(element:String) ->[String]{
//                arr.append(element)
//                return arr
//            }
//            return addElement
//        }
//
//        let f1 = makeArray()
//        print(f1("张三"))  // f1 每次调用的时候，变量 arr 值都能够被保持
//        print(f1("李四"))
//        print(f1("王五"))
//
//        let f2 = makeArray()
//        print(f2("张三1"))  // f2 每次调用的时候，变量 arr 值都能够被保持
//        print(f2("李四1"))
//        print(f2("王五1"))
        
        // f1 f2 是嵌套函数 addeElement 的不同实例，他们的运行结果也是独立的
        
        /* 打印结果
         ["张三"]
         ["张三", "李四"]
         ["张三", "李四", "王五"]
         ["张三1"]
         ["张三1", "李四1"]
         ["张三1", "李四1", "王五1"]
         */
        
        // 改为闭包实现如下：
        func makeArray()-> (String)-> [String]{
            var arr:[String] = [String]()

            // 闭包表达式结果直接作为函数值返回了
            return {(element: String) -> [String] in
                arr.append(element)  // 捕获变量
                return arr
            }
        }
        
//        let fn = makeArray()
//        print(fn("张三"))
//        print(fn("李四"))
//        print(fn("王五"))
        
        /*
        ["张三"]
        ["张三", "李四"]
        ["张三", "李四", "王五"]
         */
        
        let names = ["AT","AE","D","S","BE"]
        func compare(a:String,b:String)->Bool {
            return a < b
        }
        print(names.sorted(by:compare))  // 方法
        print(names.sorted(by: {$0 < $1}))  // 闭包
        print(names.sorted(){$0<$1})  // 尾随闭包
        print(names.sorted{$0<$1})  // 尾随闭包，无参时可省略()
        
        
        // MARK:自动闭包
        // 自动闭包是自动创建的闭包，用于包装传递给函数作为参数的表达式
        // 这种闭包不接受任何参数，当它被调用的时候，会返回被包装在其中的表达式的值
        // 这种语法让你能够省略闭包的花括号，用一个普通的表达式来替代显式闭包
        
//         一般闭包：花括号 {} 包裹的语句块
//        func make(_ closure:()->String){
//            print("do \(closure())")
//        }
//
//        var array = ["a","b","c","d"]
//        make{array.remove(at: 0)}
//        make({array.remove(at: 0)})
//        make {
//            let a = 10
//            return "\(a*10)"
//        }
        /*
         do a
         do b
         do 100
         */
        
        // 自动闭包：与上面相比，明显可以看到：他的闭包表达式中只有一条语句，且没有被花括号{}包裹住
//        func make_autoclosure(_ closure: @autoclosure () -> String){
//            print("do_autoclosure \(closure())")
//        }
//
//        var array = ["a","b","c","d"]
//        make_autoclosure(array.remove(at: 0))
//
//        func myassert(_ closure: @autoclosure () ->Bool, _ trueMessage:String?){
//            if closure() {
//                if trueMessage != nil {
//                    print(trueMessage!)
//                }
//            }
//        }
//        myassert(1<2, "条件为真")
        
        //MARK:逃逸闭包和非逃逸闭包
        // 一个接受闭包作为参数的函数，该闭包可能在函数返回后才被调用，也就是说这个闭包逃离了函数的作用域，这种闭包称为逃逸闭包。
        // 当声明一个接受闭包作为形式参数的函数时，可以在形式参数前写 @escaping 来明确闭包是允许逃逸，并且在闭包中显示地引用self
        
        // 逃逸闭包的生命周期：
        /*
         1、闭包作为参数传递给函数
         2、退出函数
         3、闭包被调用，闭包生命周期结束
         逃逸闭包的生命周期长于函数，函数退出的时候，逃逸闭包的引用仍能被其他对象持有，不会在函数结束时释放
         */
        // 逃逸闭包的使用场景
        /*
         1、异步调用：
         如果需要调度队列中异步调用闭包，这个队列持有闭包的引用，至于什么时候调用闭包，或者闭包什么时候运行结束都是不可预知的
         比如 loadData 方法进行网络请求，当网络响应后调用闭包，可视 loadData 这个方法早已经执行完毕，这样闭包就脱离了 loadData 方法的作用域，并还持有相关对象的引用
         */
        
//        typealias ResponseBlock = (_ data:Dictionary<String,Any>? , _ error :Error?) ->Void
//
//        func getRequest(url:String,body:Dictionary<String,Any>?, _ handle: @escaping ResponseBlock){
//            handle(Dictionary(),nil)
//        }
//
//        class Test {
//            var url = "http://www.baidu.com/"
//
//            func testEscaping() {
//                getRequest(url:url,body: nil) { (data,error) in
//                    print(self.url)
//                }
//            }
//        }
//
//        let tt = Test()
//        tt.testEscaping()
        
        // 非逃逸闭包
        // 一个接受一个闭包作为参数的函数，闭包会子啊函数结束前被调用，即相关引用已经被释放
        // swift4 好像把 @noescape 移除了，不过默认闭包都是隐式的非逃逸闭包
        
        
        
        /*
         为了管理内存，闭包会强引用它捕获的所有对象，比如在闭包中访问了当前控制器的属性、函数、编译器会要求在闭包中显示 self 的引用
         这样闭包就会持有当前对象，容易造成循环引用。
         
         非逃逸闭包不会产生循环引用，它会在函数作用域内释放，编译器可以保证在函数结束时闭包会释放它捕获的所有对象；
         使用非逃逸闭包的另外一个好处是编译器可以应用更多强有力的性能优化，例如：当明确了一个闭包的声明周期的话，就可以省略一些保留和释放的调用
         此外非逃逸闭包它的上下文的内存可以保存在栈上而不是堆上
         
         如果没有特殊需要，开发中使用非逃逸闭包是有利于内存优化的，所以苹果把闭包分为两种，特殊情况下再使用逃逸闭包
         */
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        TestByVal().testOne { (str1, str2, str3) in
            print(str1,str2,str3)
        }
    }
}



