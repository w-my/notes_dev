//
//  ViewController.swift
//  Swift-tips
//
//  Created by WTW on 2021/1/6.
//  Copyright © 2021 WTW. All rights reserved.
//

import UIKit




class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
       
        testSequence()
    }

}

// MARK: - 将Protocol 的方法声明为 mutating

// 因为 protocol 不仅可以被 class 实现还可以被 struct 和 enum 实现，所以在写接口的时候最好考虑是否带上 mutating
// 如果没有写那么在 struct 和 enum 中就无法在方法中改变自己的变量了
/*
protocol Vehicle {

    var numberOfWheels: Int { get }
    var color: UIColor { get set }
    
    mutating func changeColor()
}

struct MyCar : Vehicle {

    var numberOfWheels = 4

    var color = UIColor.blue

    mutating func changeColor() {
        color = UIColor.red
    }
}

class MyCar: Vehicle {
    var numberOfWheels = 4
    
    var color = UIColor.blue
    
    func changeColor() {
        color = UIColor.red
    }
}
*/

// MARK: - Sequence

extension ViewController {
    
    func testSequence() {
   
    }
    
}


// MARK: - 实例方法的动态调用

/*
class MyClass {
    
    func method(number: Int) -> Int {
        
        return number + 1
    }
}

 // 普通使用方式
let object = MyClass()
let result = object.method(number: 1)

// 动态调用
// Swift 中可以直接使用 Type.instanceMethod 语法生成一个可以柯里化的方法
// f 的类型可以看出是 f: (MyClass) -> (Int) -> Int
// 其实 Type.instanceMethod 语法做的事情类似这样的字面量转换
// let f = { (obj: MyClass) in obj.method }
let f = MyClass.method
let object = MyClass()
let result = f(object)(1)

print(result)
 */


