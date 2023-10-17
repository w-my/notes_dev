//
//  ViewController.swift
//  函数
//
//  Created by WTW on 2020/1/20.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Swift 中的函数很灵活，可以独立存在，即全局函数，也可以存在于别的函数中，即函数嵌套，也可以存在于类中、结构体、枚举中，即方法
        
        // 1、函数可以被赋值给变量，也能够作为函数的输入或者输出 (输入参数和函数的返回值)
        // 2、函数可以捕获存在于他们作用范围之外的变量
        // 3、函数可以有两种方法创建，一种是使用 func 关键字，另一种是 {} ,最后一种方式叫做闭包
        
        //MARK: - 定义函数
        /*
        func 函数名(参数列表) ->返回值类型 {
             语句组/函数体
            return 返回值
        }
        */
        
        // MARK:- 函数的参数
        // 1、使用参数标签(外部参数名)
        /*
        // W H 就是参数标签 ，在定义函数的时候没有声明参数标签，原则上也是可以的
        func rectangleArea(W width : Double,H height : Double) ->Double{
            let area = width * height
            return area
        }
        print("使用参数标签计算长方形面积：\(rectangleArea(W: 20, H: 10))")
        
        // 如果没有声明参数标签，当调用函数的时候参数名作为参数标签使用
        func rectangleArea(width : Double,height : Double) ->Double{
           let area = width * height
           return area
        }
        print("未声明参数标签计算长方形面积：\(rectangleArea(width: 20, height: 10))")
        */
        
        // 2、省略参数标签
        // swift3 以后，调用函数时，要求指定所有参数的标签，除非函数定义时使用下划线（_）关键字声明标签
        // 一旦使用下划线 _ 关键字，在调用时，不需要指定参数标签，事实上也不能指定标签
        /*
        func rectangleArea(_ width : Double,H height : Double) ->Double{
           let area = width * height
           return area
        }
        print("省略参数标签计算长方形面积：\(rectangleArea(20, H: 10))")
        
        func rectangleArea(_ width : Double,height : Double) ->Double{
           let area = width * height
           return area
        }
        print("省略参数标签计算长方形面积：\(rectangleArea(20, height: 10))")
        */
        
        // 3、参数默认值
        // 可以为参数设置一个默认值，当调用函数的时候可以忽略该参数
//        func makeCoffee(type:String = "卡布奇诺") ->String{
//            return "制作一杯\(type)咖啡"
//        }
//        print(makeCoffee(type:"拿铁")) // 制作一杯拿铁咖啡
//        print(makeCoffee()) //制作一杯卡布奇诺咖啡
        
        // 4、可变参数
        // 参数的个数可以变化，可以接受不确定数量的输入类型参数(参数具有相同的类型)，有点像传递一个数组
        // 通过在参数类型名后面加入 ... 的方式来表示这是可变参数
//        func sum(numbers:Double...)->Double {
//            var total:Double = 0
//            for number in numbers {
//                total += number
//            }
//            return total
//        }
//        print(sum(numbers: 10,20,30,40))  // 100.0
        
        // 5、值类型参数的引用传递
        // 参数传递的方式有两种：值类型 和 引用类型
        // 值传递：给函数传递的是参数的一个副本，这样在函数调用的过程中不会影响原始数据
        // 引用传递：把数据本身引用(地址)传递过去，在函数的调用过程中会影响原始数据 (修改外部变量的值)
        // 只有类是引用传递，其他的数据类型(整型、浮点型、布尔型、字符、字符串、元组、集合、枚举、结构体)都是值类型
        // 但是有的时候需要将一个值类型的参数以引用方式传递，就需要用到 inout 关键字
        
        func increment(value : inout Double,amount : Double = 1.0) {
            value += amount
        }
        
        var value : Double = 10.0
        increment(value: &value)  // amount 是默认值 &value 取出的是地址，是传递引用方式
        print(value)  // 11
        increment(value: &value, amount: 100.0)
        print(value) // 111
        
        
        // MARK:- 函数的返回值
        // 返回值比较灵活，主要有三种：无返回值，单一返回值，多返回值
        
        // 1、无返回值函数
        // 函数只为处理某个过程或者返回的数据要通过 inout 类型参数传递出来，这时可以设置为无返回值 (实际上是一个Void类型 )
        
        /*
        func 函数名(参数列表) {
            语句组
        }
        func 函数名(参数列表) ->(){  // 表示返回空的元组
           语句组
        }
        func 函数名(参数列表) ->Void{  // 返回 Void 类型
            语句组
        }
        */
        
        // 2、多返回值函数
        // 通过两种方式实现：
        // 一种是在函数定义的时候将函数的多个参数声明为引用类型传递，当函数调用结束的时候，这些参数的值就变化了
        // 另外一种是返回元组类型
        func position(dt:Double,speed:(x:Int,y:Int)) -> (x:Int,y:Int) {  // 指定时间和速度时的位移
            let posx : Int = speed.x * Int(dt)
            let posy : Int = speed.y * Int(dt)
            
            return (posx,posy)
        }
        let move = position(dt: 60.0, speed: (x: 10, y: 5))
        print("\(move.x) \(move.y)")  // 600 300
        
        
        // MARK:- 函数类型
        // 每个函数都有一个类型，使用函数的类型与使用其他数据类型一样，可以声明变量和常量，也可以作为其他函数的参数或者返回值使用
        
        // 定义长方形面积的函数  函数类型是 (Double,Double)->Double
        func rectangleArea(width:Double,height:Double) -> Double {
            let area = width * height
            return area
        }
        
        // 定义三角形面积的函数   函数类型是 (Double,Double)->Double
        func triangleArea(bottom:Double,height:Double) -> Double {
            let area = 0.5 * bottom * height
            return area
        }
        
        func sayHello(){   // 函数类型是 ()->()
            print("hello world")
        }
        
        // 1、作为函数的返回类型使用
        
        // 返回值类型是 (Double,Double) -> Double ，返回值是一个函数类型
        func getArea(type:String) -> (Double,Double) -> Double {
            var returnFounction:(Double,Double) -> Double  // 声明函数类型变量
            switch type {
            case "rect": // 长方形
                returnFounction = rectangleArea  // 函数名赋值给声明的函数类型变量
            case "tria": // 三角形
                returnFounction = triangleArea
            default:
                returnFounction = rectangleArea
            }
            return returnFounction
        }
        
        // 计算三角形面积
        var area:(Double,Double)->Double = getArea(type: "tria")
        print("三角形面积 ： \(area(10,15))")  // 75.0
        
        // 计算长方形面积
        area = getArea(type: "rect")
        print("长方形面积 ：\(area(10,20))")  // 200
        
        // 2、作为参数类型使用
        // 第一个参数类型是函数类型
        func getAreaByFunc(funcName:(Double,Double)->Double,a:Double,b:Double) ->Double {
            let area = funcName(a,b)
            return area
        }
        
        // 计算三角形面积
        var result : Double = getAreaByFunc(funcName: triangleArea, a: 20, b: 10)
        print("三角形面积 ： \(result)")  // 100

        // 计算长方形面积
        result = getAreaByFunc(funcName: rectangleArea, a: 10, b: 20)
        print("长方形面积 ： \(result)")
        
        //MARK: - 函数捕获存在于他们作用范围之前的变量
        func counterFunc()->(Int)->String {
            var counter = 0
            func innerFunc(i: Int) -> String {
                counter += i  // 捕获了 counter
                return "running total:\(counter)"
            }
            return innerFunc
        }
        
        // 一般来说， counter 是 counterFunc  的局部变量，在return 执行之后应该离开作用于被结束，但是因为 innerFunc 捕获了它，它将继续存在
        // f 和 g 互不影响
        let f = counterFunc()
        print(f(3))  // 3
        print(f(4))  // 7
        
        let g = counterFunc()
        print(g(2))  // 2
        
        // MARK: - 隐式返回的函数
        // 如果整个函数体是一个单一表达式，那么函数隐式返回这个表达式(相当于省略了return)
        func greeting(for person: String) -> String {
            "Hello, " + person + "!"
        }
        print(greeting(for: "Dave"))
        // Prints "Hello, Dave!"
         
        func anotherGreeting(for person: String) -> String {
            return "Hello, " + person + "!"
        }
        print(anotherGreeting(for: "Dave"))
        // Prints "Hello, Dave!"
        
        
        // MARK:- 嵌套函数
        // 前面定义的函数都叫全局函数，并将定义在全局作用域中
        // 把函数定义在另外一个函数体中，叫做嵌套函数
                
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
        
        //默认情况下，嵌套函数的作用域在外函数体内，但是可以定义外函数的返回值类型为嵌套函数类型，从而将嵌套函数传递给外函数，被其他调用者使用
        
        //MARK:- 其他用法
        
        //MARK: 修改外部变量的值
        // 参数默认是常量，不能在函数内部修改参数的值，更不能修改传递过来的外部变量的值(值类型)
        // 可以使用 inout 关键字，表示内部可以修改外部的变量
        func swap(a: inout Int,b: inout Int){
            let t = a;
            a = b;
            b = t;
        }
        
        var a = 10 ,b = 20
        swap(a: &a, b: &b)
        print(a,b)  // 20 10
        
        //MARK: 函数结束前执行 defer
        // defer 修饰函数内任一段代码块，代码块将在函数即将结束前调用
        // 如果定义了多个 defer 代码块，程序会从下往上执行 defer 代码块
        // 异步代码的执行，不会影响 defer 的执行时间
        func testdefer() {
            print("函数开始了")
            defer {
                print("执行defer1")
            }
            print("函数执行中")
            defer {
                print("执行defer2")
            }
            print("函数即将结束")
        }
        testdefer()
        /*
         函数开始了
         函数执行中
         函数即将结束
         执行defer2
         执行defer1
         */
        
        
        //MARK:- 处理错误异常
        // try 手动 do-catch 捕获异常
        // try？ 如果该方法出现了异常，该方法返回nil,正常则返回对应的对象
        // try！ 直接强制执行，如果该方法出现了异常，那么程序崩溃
        
        // 在可能出现异常的函数后添加 throws 在调用的时候使用 do-catch 保证调用者对相应的错误进行处理
        
        enum myError : Error {
            case ErrorOne
        }

        func willThrow(_ type: Int) throws ->String {
            if type == 1 {
                throw myError.ErrorOne
            }
            return "OK"
        }
        
        do {
            let str = try willThrow(1)
            print(str)
        } catch let error as myError {
            print("throes",error)
        }catch {
            
        }
        
        // rethrows 针对的不是函数或者方法本身，而是携带的闭包类型的参数，当他的闭包类型的参数 throws 的时候，需要使用 rethrows 将这个异常向上传递
    
        func willRethrow(_ throwCall: (Int) throws -> String) rethrows {
            do {
                let result = try throwCall(1)
                print(result)
            }catch let error as myError {
                throw error  // 再次 throw 往上传递
            }catch {
                
            }
        }
        
        do {
            try willRethrow(willThrow)
        } catch let error as myError {
            print("rethrows" ,error)
        }catch {
            
        }
        
        /*
         throes ErrorOne
         rethrows ErrorOne
         */
        
        //MARK: 函数的文档注释
        
        /// 函数求和【概述】
        ///
        /// 求两个整数相加【更加详细的描述】
        ///
        /// - Parameters:
        ///   - v1: 第一个参数
        ///   - v2: 第二个参数
        /// - Returns: 返回值
        ///
        /// - Note:批注
//        func sum(v1: Int, v2: Int) -> Int {
//            return v1 + v2
//        }
    }
}

