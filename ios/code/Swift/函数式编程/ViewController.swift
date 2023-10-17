//
//  ViewController.swift
//  函数式编程
//
//  Created by WTW on 2020/11/3.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        let num = 10

        // 要实现如下功能
        print(((num + 3) * 5 - 1) % 10 / 2)  // 2
        
        
        // 函数式编程
        let result = add(num)(20)
        print(result) // 30
       
        
//        let fn = add(3) >>> multiple(5) >>> sub(1) >>> mod(10) >>> divide(2)
//        print(fn(num))
     
    }
    
    // MARK: 求两个数的和
    
//     一般的写法
//    func add(_ v1: Int, _ v2 : Int) -> Int { v1 + v2 }
    
    // 函数式编程的写法
    // 求两个数的和 (把接收两个参数的函数改写为只接收一个参数的形式)
//    func add(_ v: Int) -> (Int) -> Int {
//        return {
//            $0 + v
//        }
//    }

    
    // 简写如下
    func add(_ v: Int) -> (Int) -> Int { { $0 + v } } // 加
    func sub(_ v: Int) -> (Int) -> Int { { $0 - v } } // 减
    func multiple(_ v: Int) -> (Int) -> Int { { $0 * v } } // 乘
    func divide(_ v: Int) -> (Int) -> Int { { $0 / v } }  // 除
    func mod(_ v: Int) -> (Int) -> Int { { $0 % v } } // 求余
    
    // MARK: 函数合成
//    let fn1 = add(3)
//    let fn2 = multiple(5)
//    let fn3 = sub(1)
//    let fn4 = mod(10)
//    let fn5 = divide(2)
//
//    print(fn5(fn4(fn3(fn2(fn1(num))))))  // 2
    
    
//    infix operator >>> : AdditionPrecedence
//    func >>> (_ f1: @escaping (Int) -> Int,
//              _ f2: @escaping (Int) -> Int)
//        -> (Int) -> Int { { f2(f1($0)) }}
//
//    let fn = add(3) >>> multiple(5) >>> sub(1) >>> mod(10) >>> divide(2)
//    print(fn(num))
    
}

