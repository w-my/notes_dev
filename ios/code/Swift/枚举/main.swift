//
//  main.swift
//  枚举
//
//  Created by WTW on 2021/6/2.
//  Copyright © 2021 WTW. All rights reserved.
//

import Foundation

//MARK:- 枚举 (为一组相关值定义的一个通用类型)

// Swift 中的枚举语法格式
// 枚举名：首字母大写，尽量用一个英文单词
/*
enum 枚举名 {
    枚举的定义
}
 */

// 在其他语言中枚举的成员值是整型类型,在Swift 中，成员值默认不是整数类型
// 如下声明 WeakDays 枚举，表示一周的每个工作日，这些成员值并不是整数类型
// 成员值前面还要加上 case 关键字，也可以将多个成员值放在同一行，用逗号隔开
/*
enum WeekDays{
    case Monday
    case Tuesday
    case Wednesday
    case Thursday
    case Friday
}

enum WeekDays {
    case Monday,Tuesday,Wednesday,Thursday,Friday
}

var day = WeekDays.Friday  //成员值赋值给变量 day
day = .Monday

// switch 语句中的 case 必须全面包含枚举中的所有成员
// 如果不能为所有枚举都提供一个case ,可以提供一个 default 来包含那些不能被明确写出来的成员
func writeGreeting(day:WeekDays){
    switch day {
    case .Monday:
        print("周一")
    case .Tuesday:
        print("周二")
    case .Wednesday:
        print("周三")
    case .Thursday:
        print("周四")
    case .Friday:
        print("周五")
    }
}

writeGreeting(day: day)  // 周一
writeGreeting(day: WeekDays.Friday) // 周五
*/

//MARK: 遍历枚举情况
// 可以在枚举后添加 : CaseIterable 来允许枚举被遍历。
/*
enum WeekDays : CaseIterable {
    case Monday,Tuesday, Wednesday,Thursday, Friday
}

print(WeekDays.allCases.count) // 5

for day in WeekDays.allCases {
    print(day)
}
*/

//MARK: 原始值
// 定义枚举的时候可以提供原始值(raw value) 这些原始值类型可以是字符、字符串、整数和浮点数等
/*
 // 使用原始值格式如下：
 // 枚举名后跟数据类型可以声明原始值枚举的类型，然后在定义case 成员的时候需要提供原始值
 enum 枚举名: 数据类型 {
    case 成员名 = 默认值
 }
 */

/*
// Int 实际上就是原始值类型
enum WeekDays: Int {
    case Monday     = 0
    case Tuesday    = 1
    case Wednesday  = 2
    case Thursday   = 3
    case Friday     = 4
}

enum WeekDays : Int {
    case Monday = 0,Tuesday,Wednesday,Thursday,Friday
}

var day = WeekDays.Friday
func writeGreeting(day:WeekDays){
    switch day {
    case .Monday:
        print("周一")
    case .Tuesday:
        print("周二")
    case .Wednesday:
        print("周三")
    case .Thursday:
        print("周四")
    case .Friday:
        print("周五")
    }
}


let friday = WeekDays.Friday.rawValue  // 通过 rawValue 转换成原始值
let thursday = WeekDays(rawValue: 3)   // 将原始值转换成成员值
if (WeekDays.Friday.rawValue == 4) {
    print("今天是周五")
}
writeGreeting(day: day)
writeGreeting(day: WeekDays.Friday)
*/

//MARK: 关联值 (相关值)
// Swift 中除了可以定义成员值还可以定义一组相关值(associated value),类似C 语言中的联合类型
// 枚举 Figure(图形) 有两个相关值
enum Figure{
    case Rectangle(Int,Int)  // 矩形
    case Circle(Int)  // 圆
}

func printFigure(figure:Figure){
    switch figure {
    case .Rectangle(let width, let height):
        print("width:\(width) height:\(height)")
    case .Circle(let radius):
        print("半径:\(radius)")
    }
}

var figure = Figure.Rectangle(100, 50)
printFigure(figure: figure)

figure = Figure.Circle(20)
printFigure(figure: figure)


// MARK:枚举高级
// 能够提供计算属性
// 能够提供实例方法
// 能够定义初始化方法
// 能支持扩展
// 能够准守协议，用于提供一切标准的功能

// 枚举的嵌套
enum Area {
    case BeiJing
    case ShangHai
    
    enum JiangSu {
        case NanJing
        case SuZhou
        case Wuxi
    }
}

// 枚举中方法和属性
enum Device {
    
    case iPad,iPhone,AppleTV,AppleWatch
    
       /*
     计算属性
     增加一个存储属性在枚举中是不被允许的，能够创建计算属性
     计算属性的内容都是建立在枚举值下或者枚举关联值得到的
     */
    var productName: String {
        switch self {
        case .iPad:
            return "iPad"
        case .iPhone:
            return "iPhone"
        case .AppleTV:
            return "AppleTV"
        case .AppleWatch:
            return "AppleTV"
        }
    }
    
    // 方法
    func descption() ->String{
        switch self {
        case .iPad:
            return "iPad"
        case .iPhone:
            return "iPhone"
        case .AppleTV:
            return "AppleTV"
        case .AppleWatch:
            return "AppleTV"
        }
    }
    
    // 静态方法
    static func getTypeWithName(name:String) ->Device? {
        if name == "iPad" {
            return .iPad
        }
        return nil
    }
}

let device = Device.iPhone
print(device.productName,device.descption(),Device.getTypeWithName(name: "iPad")!)

// 可变方法
enum Rotate : Int {
    case Top
    case Right
    case Bottom
    case Left

    //enmu 中可以使用可变方法，这样就可以更改 self 的值  mutating
    mutating func next() {
        switch self {
            case .Top:
                self = .Right
            case .Bottom:
                self = .Bottom
            case .Left:
                self = .Left
            case .Right:
                self = .Top
            }
        }
}

// 枚举也可以使用 协议 和 扩展 和 泛型
// ......






