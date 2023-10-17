//
//  main.swift
//  对象模板模式
//
//  Created by WTW on 2020/11/21.
//  Copyright © 2020 WTW. All rights reserved.
//

import Foundation

var products = [
    ("Kayak","A boat for one person",275.0,10),
    ("Lifejacket","Protetive and fashionable",48.95,14),
    ("Soccer Ball","FIFA-approved size and weight",19.5,32)
]

func calculateTax(product:(String,String,Double,Int)) -> Double {
    return product.2 * 0.2
}

func calculateStockValue(tuples:[(String,String,Double,Int)]) -> Double {
    return tuples.reduce(0) { (total, product) -> Double in
        
        return total + (product.2 * Double(product.3))
    }
}

print(calculateTax(product: products[0]))
print(calculateStockValue(tuples: products))

/// 上面代码的问题 两个函数和元组数组紧耦合 ，一旦元组数组发生变化函数参数就要修改，函数参数修改元组数组就要跟着改变

