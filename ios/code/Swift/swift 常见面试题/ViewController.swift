//
//  ViewController.swift
//  swift 常见面试题
//
//  Created by WTW on 2020/3/30.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
     
      //MARK:map flatmap

        // map 接收一个闭包作为参数，它会遍历整个 numbers 数组，对数组中的每一个元素执行闭包中定义的操作
        // 相当于对数组中的所有元素做了一个映射
        let numbers = [1,2,3,4]
        let result1 = numbers.map { $0 + 2 }
        print(result1)
        
        /*
         flatMap(transform: (Element) throws -> T?) -> [T]
         */
        
        // flatmap 对于二维数组会进行降维操作
        let result2 = numbers.flatMap { $0 + 2 }
        print(result2)  // 这样和map 的结果是一样的
        
        // [[3, 4, 5], [6, 7, 8]]
        let numbersCompound = [[1,2,3],[4,5,6]]
        let res = numbersCompound.map {
            $0.map {
                $0 + 2
            }
        }
        
        // [3, 4, 5, 6, 7, 8]
        let flatRes = numbersCompound.flatMap {
            $0.map{
                $0 + 2
            }
        }
        
        print(res)
        print(flatRes)
        
        
        // MARK: typealias  定义类型别名
        // https://blog.csdn.net/jichunw/article/details/80088865
        // typealias aliasType = Type
        
        // 重新定义闭包类型
//        // 声明
//        typealias sendValueClosure = (sendString:String)->Void
//        //持有
//        var callBackString : sendValueClosure
//        // 调用
//        self.callBackString!(sendString:self.nameString)
              
    }
}

