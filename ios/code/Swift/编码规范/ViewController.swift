//
//  ViewController.swift
//  Swift
//
//  Created by WTW on 2019/11/19.
//  Copyright © 2019 WTW. All rights reserved.
//

/*
    https://swift.org/documentation/api-design-guidelines/
 */

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
       
        //MARK: 地标注释  (类似OC 中 #pragma mark )
        //MARK:- 用于方法或函数的注释  (类似OC 中 #pragma mark- )
        //TODO: 表示这里的代码有没有完成或者还要处理
        //FIXME: 表示待修复的代码
        #warning("我是warning")
        
        // 如果不知道函数暂时的实现，可以先写一个 0 占位
        // 也可以写一个 fatalError() 占位
        func test() ->Int {
//            0
            #warning("test还没实现")
            fatalError()
        }
        

        // MARK:- 声明
        // 变量和常量声明
        // 推荐
//        let level = 0
//        var size = 10
        //不推荐
//        let level = 0,size = 10
        
        // 尽量采用类型推断，这样代码更简洁
        // 推荐
//        let level = 0
//        var size = 10
        // 不推荐
//        let level: Int = 0
//        var size: Int = 10
        
        // 不是默认数据类型，需要明确声明变量或常量的数据类型
//        let level: Int8 = 0
//        let size: Int64 = 10
        
        // 不推荐 (注意空格的位置)
//        let level:Int8 = 0
//        let size : Int64 = 10
        // 推荐
//        let level: Int8 = 0
//        let size: Int64 = 10
        
        // 尽量使用Swift 原生的数据类型
        // 推荐使用
//        let width = 120.0
//        let widthString = "Hello"
//        var deviceModels: [String]
//        var employess: [Int: String]
        //不推荐使用
//        let width: NSNumber = 120.0
//        let widthString: NSString = "Hello"
//        var deviceModels: NSArray
//        var employess: NSDictionary
        
        // 属性声明
        // 如果是存储属性，声明规范与变量或常量声明的规范一样
        // 如果是计算属性，声明规范类似于代码块，特别是在使用只读计算属性的时，应尽量省略get语句
        // 推荐
//        var fullName: String {
//            return ....
//        }
        // 不推荐
//        var fullName: String {
//            get{
//                return ...
//            }
//        }
        
        //MARK: 代码排版
        // 空行
        /*
         类型声明之前
         import语句前后
         两个方法或者函数之间
         块注释或单行注释之前
         一个源文件的两个片段之间
         */
        
        // 空格
        /*
         赋值符号左右各空一个
         小左括号之后，小右括号之前不应该有括号
         大括号之前有一个空格
         方法或者函数名与第一个参数之间没有空格，后面的参数应该有一个空格，参数冒号与数据类型之间也需要一个括号
         */
        
        // 断行
        // 一行代码长度不应超过80个字符
        
        
        //MARK: - mutating
        // 一般在修改值类型的属性的时候需要加上mutating
        // 在使用协议的时候一般会加上 mutating ，方便 结构体和枚举等实现协议 （协议实现中可能会修改 结构体和枚举的成员变量）
    }
    


}

