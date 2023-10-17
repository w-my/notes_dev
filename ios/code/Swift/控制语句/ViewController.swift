//
//  ViewController.swift
//  控制语句
//
//  Created by WTW on 2020/1/19.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        // MARK:- 顺序  分支  循环
        // 分支 ： if 、switch 、 guard
        // 循环语句 : while 、repeat-while 、for
        // 跳转语句 : break 、continue 、 fallthrough 、return 、 throw
        
        // MARK: if 结构
        // if结构 、 if-else 结构 、 else-if 结构 (条件必须是Bool 类型)
        /*
         if 条件表达式 {
          语句组
         }
         
         if 条件表达式 {
          语句组1
         }else {
          语句组2
         }
         
         if 条件表达式1 {
          语句组1
         }else if 条件表达式2 {
          语句组2
         }else if 条件表达式3{
          ...
         }
         
         */
        
        // MARK: Switch 结构
        // swift 中的 switch 语句可以是 整数、浮点数、字符、字符串、元组等类型，而且数值可以是离散的，也可以是连续的范围
        // swift 中的 switch 语句case分支不需要显式地添加break 语句，分支执行完就会跳出 switch 语句
       
        /*
         // case 后面可以跟一个或者多个值 ，逗号隔开 ，每个switch 必须有一个 default 语句
        switch 条件表达式 {
        case 值1:
            语句组1
        case 值2,值3:
            语句组2
        default:
            语句组n+1
        }
        */
        
        // 比较的可以是整数、浮点数、字符、字符串、元组等
        let value  = 1.00
        var desc : String
        switch value {
        case 0.0:
            desc = "最小值"
        case 0.5:
            desc = "中值"
        case 1.0:
            desc = "最大值"
        default:
            desc = "其他值"
        }
        
        // 区间匹配
        let count = 62
        switch count {
        case 0:
            print("0")
        case 1..<5:
            print("1..5")
        case 5..<12:
            print("5..12")
        case 12..<100:
            print("12..<100")
        default:
            print("default")
        }
        
        // 元组匹配
        let point = (1,1)
        switch point {
        case (0,0):
            print("the origin")
        case (_,0):
            print("on the x-axis")
        case (0,_):
            print("on the y-axis")
        case (-2...2,-2...2):
            print("inside the box")
        default:
            print("outside of the box")
        }
        
        // MARK: guard
        // 与 if 语句类似，判断一个条件为真的情况下执行某语句，否者终止或跳过执行某语句，主要是为了替换 if-else 语句的嵌套，提高程序的可读性
        /*
         // 当表达式为真时，跳过 else 语句中内容，执行语句组内容，条件表达式为false 时执行 else 语句中的内容。
         // 跳转语句一般是 return 、break、 continue 和 throw
         guard 条件表达式 else {
            跳转语句
         }
         语句组
         */
        
        // let blogName = lobg.name 称为值绑定 做了两件事
        // 一是把 blog.name 赋值给 blogName
        // 二是判断blogName 是否为 空值(nil)
        struct Blog {
            let name: String?
            let URL: String?
            let Author: String?
        }
        func ifStyleBlog(blog:Blog){
            if let blogName = blog.name {
                print("博客名 : \(blogName)")
            }else {
                print("博客没有名字")
            }
        }
        func guardStyleBlog(blog:Blog){
            guard let blogName = blog.name else {
                print("博客没有名字")
                return
            }
            print("博客名：\(blogName)")
        }
        
        
        // MARK: - 循环语句
        // while、repeat-while、 for
        // while 在执行循环体之前测试循环条件
        // repeat-while 执行循环体之后测试循环条件
        // for 和 in 结合使用，专门为集合遍历而设计的
        
        /*
         while 循环条件 {
            语句组
         }
         
         repeat {
            语句组
        }while 循环条件
         
         // swift 3 之前还可以使用C语言风格的for语句，swift3 之后只能和 in 结合使用
         for <#item#> in <#items#> {
             <#code#>
         }
         */
        for i in 1..<10 {
            print("\(i) x \(i) = \(i * i)")
        }
        
        let range = 1...3
        for i in range {
            print(i)
        }
        
        let a = 1
        let b = 2
        for i in a...b {
            print(i)
        }
        
        // 如果在内部操作i需要定义为 var
        for var i in 1...3 {
            i += 5
            print(i)
        }
        
        for _ in 1...3 {
            print("省略的形式")
        }
        
        // MARK: - 跳转语句
        // break 强行退出循环结构，不执行循环结构中剩余的语句
        // break 语句有两种方式，可以带标签，可以不带标签
        /*
         break label // 带标签
         break  // 不带标签
         */
        // 默认情况下，break 只会跳出最近的内循环。如果跳出外循环，可以为外循环添加一个标签，然后在break后指定这个标签即可
       
        
        // continue 语句
        // 用来结束本次循环，跳出循环体尚未执行的语句，接着进行终止条件的判断，以决定是否继续循环
        // 也有两种方式，可以带标签，可以不带标签
        
        
        // fallthrough 语句
        // 是贯通语句，只能在switch 语句中使用，swift 中的switch 语句case 分支默认是不能贯通的，即执行完一个case分支，跳出switch 语句
        // 如果需要多个case分支贯通，可以使用 fallthrough 
        var j = 1
        var x = 4
        
        switch x {
        case 1:
            j += 1
        case 2:
            j += 1
        case 3:
            j += 1
        case 4:
            j += 1
            fallthrough
        case 5:
            j += 1
            fallthrough
        default:
            j += 1
        }
        print("j = \(j)")  // 4
        
        
        // MARK: - 范围和区间运算符
        // ... 闭区间      ag:  a...b   a<= 取值 <= b           区间类型:ClosedRange<Int>
        // ..< 半开区间    ag:  a..<b    a<= 取值 < b           区间类型:Range<Int>
        // 单侧区间  a... 右边不限制    ...a 左边不限制            区间类型:PartialRangeFrom<Int>
   
        // 带间隔的区间值
        let hours = 11
        let hourInterval = 2
        // 从 4 开始 累加2 不超过11
        for tickMark in stride(from: 4, to: hours, by: hourInterval) {
            print("带间隔的区间值" + "\(tickMark)")
        }
        
        // MARK:- 值绑定
        // 将表达式的值临时赋给一个常量或变量，这些常量或变量能够在该控制语句中使用，称为 值绑定

        // if 中的值绑定
        // 先将表达式赋值给一个变量或者常量，然后判断这个值是否为nil,如果不等于nil 则绑定成功进入 true 分支，否者进入 false 分支
       
        // guard 中的值绑定
        // 类似 if 语句
        
        // switch 中的值绑定 (也可见下方的demo)
        
        let point = (2,0)
        switch point {
        case (let x,0):
            print("on the x-axis with an x value of \(x)")
        case (0,let y):
            print("on the y-axis with a y value of \(y)")
        case let (x,y):
            print("somewhere else at \(x),\(y)")
        }
        // print("on the x-axis with an x value of 2")
        
        
        // if 和 guard 中的值绑定demo 见上方 guard
        
        // MARK: - where 语句
        // 条件过滤，类似 SQL 中的 where 语句 ，能够使用 where 语句的控制语句在 switch 和 for 等语句中使用，此外还可以应用于泛型
        
        // switch 语句在值绑定的情况下可以在 case 中使用where 语句进行条件过滤
        var student = (id:"1002",name:"李四",age:32,ChineseScore:98,EnglishScore:91)
        var desc1 : String
        switch student {
        case (_,_,let age,90...100,90...100) where age > 30:
            desc1 = "优"
        case (_,_,_,80..<90,80..<90):
            desc1 = "良"
        case (_,_,_,60..<80,90...100),(_,_,_,90...100,60..<80):
            desc1 = "偏科"
        case (_,_,_,0..<80,90...100),(_,_,_,90...100,0..<80):
            desc1 = "严重偏科"
        default:
            desc1 = "无"
        }
        print("说明 : \(desc1)")
     
        // for 中使用 where 语句
        let numbers = [1,2,3,4,5,6,7,8,9,10]
        for item in numbers where item > 5 {
            print("Count is : \(item)")
        }
        
        //MARK:标签语句
        outer: for i in 1...4 {
            for k in 1...4 {
                if k == 3 {
                    continue outer
                }
                if i == 3 {
                    break outer
                }
                print("i == \(i),k== \(k)")
            }
        }
    }
  
}

