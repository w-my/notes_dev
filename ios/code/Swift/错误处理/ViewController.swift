//
//  ViewController.swift
//  错误处理
//
//  Created by WTW on 2020/1/20.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        // MARK: - 自定义错误
        // 可以通过Error协议自定义运行时的错误信息
        // 函数内部通过 throw 抛出自定义Error,可能会抛出Error的函数必须加上 throws 声明
        // 需要使用 try 调用可能会抛出的函数
        enum SomeError: Error {
            case illegalArg(String)
            case outOfBounds(Int,Int)
            case outOfMemory
        }
        
        // 当除数为0 时抛出错误
        func divide(_ num1: Int,_ num2: Int) throws -> Int {
            
            if num2 == 0 {
                
                throw SomeError.illegalArg("参数异常")
            }
            
            return num1 / num2
        }

//        let reslut = try? divide(10, 0)
//        print(reslut)
        
        
        //MARK: - 处理Error的方式
        // do {try } catch { } 手动捕捉异常
        // 不捕捉Error ，在当前函数增加 throws 声明，Error 将会自动抛给上层函数，如果顶层是main函数没有处理捕获Error，则程序终止
        // try?  // 推荐使用
        // try!  // 不推荐使用
        
        // MARK: do-try-catch 处理模式
        /* 语法格式:
        do {
            try 语句
            成功处理语句
        } catch 匹配错误 {   // catch 代码块可能有多个，错误由哪个catch 代码块处理视后面的错误匹配与否而定，错误类型的多少，就决定了 cacth 可能有多少
            错误处理
        }
        */
        /*
        do {
            try print(divide(20, 0))
        } catch  let SomeError.illegalArg(msg) {
            print("参数异常:",msg)
        }catch let SomeError.outOfBounds(size, index) {
            print("下标越界:",size,index)
        }catch let SomeError.outOfMemory {
            print("内存越界:")
        }catch {
            print("其他错误")
        }
        */
        
        // MARK:  错误类型
//        swift中错误类型必须遵从 Error 协议，其次是考虑错误类型的匹配，应该设计为枚举类型，因为枚举非常适合将一组相关联值关联起来
        // 例如修改数据库的情况
//        enum DAOError : Error {
//            case noData
//            case primaryKeyNull
//        }
        
//        do {
//            try //访问数据库表函数或者方法
//        } catch DAOError.noData {
//            print("noData")
//        }catch DAOError.primaryKeyNull {
//            print("primaryKeyNull")
//        }
        
        
        // MARK: 声明抛出错误
        // 能放到 try 后面的函数或方法都是有要求的，他们可能抛出错误，但是需要在函数或方法后面加上 throws 关键字，表示这个方法或函数可以抛出错误
        // 声明抛出错误的方法
       
        /*
        func remove(_ modle: Note) throws {  // 没有返回值的就直接写在参数后面
            // ......
        }
        
        
        func findAll() throws ->[Note] {  // 有返回值的就写在返回值和参数之间
            //......
        }
         */
        
        // MARK: 在函数或者方法中抛出错误
        // 产生并抛出错误有两种方式
        // 1、在函数或方法中通过 throw 语句人为地抛出错误
        // 2、在函数或方法中通过通过其他可以抛出错误的函数或者方法完成，但是没有捕获处理，会导致错误被传播出来
       
        // 删除 Note 方法
        /*
        func remove(_ model: Note) throws {
            
            guard let date = model.date else {
                // 抛出主键为空的错误
                throw DAOError.primaryKeyNull
            }
                
            // 比较日期主键是否相等
            for (index,note) in listData.enumerated() where note.date == date {
                listData.remove(at:index)
            }
        }
        
        // 查询所有数据的方法
        func findAll() throws ->[Note] {
            guard listData.count > 0 else {
                //抛出没有输数据的错误
                throw DAOError.noData
            }
            return listData
        }
        
        func printNotes() throws {
            let datas = try findAll()
            for note in datas {
                print("......")
            }
        }
        */
        
        // 如果声明了抛出错误，但是没有使用 catch 捕获处理，这样就导致错误传播给该函数或者方法的调用者，如果调用者也不捕获处理，那么最后程序就会出现运行时错误
        // 声明了抛出错误的函数或方法被调用时，前面都需要加上 try 关键字，如果需要捕获，需要使用 do catch 将 try 包裹起来
//        try printNotes()
        
        // MARK:try? try! 使用区别
        
        print(try? divide(10, 2))  // Optional(5)
        print(try? divide(10 , 0))  // nil
        print(try! divide(10, 2))  // 5
        
        // 推荐使用  try?
        // try? 会将错误转换为可选值，当调用try？ + 函数或者方法时，如果函数或方法抛出错误，程序不会崩溃，而是返回一个nil，如果没有抛出错误，则返回可选值
//        guard let datas = try? findAll() else{ return }
//        print(datas)  // datas 是可选值，try？语句就没有必要使用 do-catch 语句进行包裹
                
        // try! 可以打破错误传播链条，错误抛出后被传播给他的调用者，就形成了一个传播链条，如果不想让错误传播下去，可以使用 try!语句
        // try！一旦出现异常会非常危险 会直接崩溃
        
        // MARK:- rethrows
        // 函数本身不会抛出错误，但调用闭包参数抛出错误，它会将错误向上抛出
        func exec(_ fn:(Int,Int) throws ->Int,_ num1: Int,_ num2: Int) rethrows {
            try fn(num1,num2)
        }
        print(try? exec(divide, 10, 0)) // nil
//        print(try! exec(divide, 10, 0)) // 会闪退
        
        // MARK: - defer 释放资源
        // 无论成功try 语句,还是有错误并执行了 catch 代码块，都应该保证释放这些资源  类似java的finally (无论成功与否都会走到finally)
        // 保证程序运行在超出 defer 语句作用域之前，一定执行 defer 语句
        // 将延迟至当前作用域结束之前执行(不关心是否是正常结束)
        /*
        defer {
            
        }
        */
        
        //MARK: 测试
        
        let pattern = "正则表达式"
        
        // 方式1 try catch
        do {
            let regex = try NSRegularExpression(pattern: pattern, options: .caseInsensitive)
        }catch {
            print(error)
        }
        
        // 方式2 try? (推荐这样写)
        guard let regex1 = try? NSRegularExpression(pattern: pattern, options: .caseInsensitive) else {
            return
        }
        
        // 方式3 try! (不推荐这样写，如果有异常会直接崩溃)
        let regex2 = try! NSRegularExpression(pattern: pattern, options: .caseInsensitive)
     
        
        // MARK: 断言(assert)和先决条件(precondition)
        
        // assert(_ condition: @autoclosure () -> Bool, _ message: @autoclosure () -> String = String(), file: StaticString = #file, line: UInt = #line)
        // 断言只会在debug 模式下生效，生产构建时断言不会生效，也就是说开发过程中可以随便适用断言而无需担心影响生产性能
        // 断言和先决条件的不同之处在于他们什么时候做检查：断言只在 debug 构建的时候检查，但先决条件则在 debug 和生产构建中生效。在生产构建中，断言中的条件不会被计算。这就是说你可以在开发的过程当中随便使用断言而无需担心影响生产性能
        let age = -3
//        assert(age >= 0,"A person's age cannot be less than zero")
        // 错误处理/ViewController.swift:199: Assertion failed: A person's age cannot be less than zero
        
        // 如果代码已经检查了条件，你可以使用 assertionFailure(_:file:line:) 函数来标明断言失败
//        if age > 0 {
//
//        }else {
//            assertionFailure("A person's age cannot be less than zero")
//        }
        
        // 强制先决条件 precondition
        // precondition(_ condition: @autoclosure () -> Bool, _ message: @autoclosure () -> String = String(), file: StaticString = #file, line: UInt = #line)
        // 代码中任何条件可能潜在为假但必须肯定为真才能继续执行的地方使用先决条件,比如说，使用先决条件来检测下标没有越界，或者检测函数是否收到了一个合法的值
//        precondition(age > 0, "年龄必须大于0")
        
        // 如果你在不检查模式编译（ -Ounchecked ），先决条件不会检查。编译器假定先决条件永远为真，并且它根据你的代码进行优化。总之， fatalError(_:file:line:) 函数一定会终止执行，无论你优化设定如何。
        // 可以在开发过程中使用 fatalError(_:file:line:) 函数标记那些还没实现的功能，使用 fatalError("Unimplemented") 来作为代替。
        // 由于致命错误永远不会被优化，不同于断言和先决条件，你可以确定执行遇到这些临时占位永远会停止。
//        fatalError(<#T##message: String##String#>)   可以开发阶段用在某些不希望被调用的方法后，或者 未实现的代码标识
//        class Student: Person {
//            required init() { fatalError("don not call Student.init") }
//            init(score: Int) { }
//        }
    }
    


}

