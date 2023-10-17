//
//  SequenceTestViewController.swift
//  RXSwift 语法基础
//
//  Created by WTW on 2020/11/11.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

/**
 *
 * https://www.dazhuanlan.com/2019/10/16/5da640c19e2bc/
 * Sequence 协议
 *
 * 主要有两个参数， 一个是 Element，也即是 sequence 里的元素，
 * 别一个则是 Iterator（迭代器），Iterator 是实现 IteratorProtocol 协议并且迭代器的元素和 sequence 的元素是相同类型（Iterator.Element == Element）
 *
 * IteratorProtocol  协议
 * IteratorProtocol 的核心是 next() 方法，这个方法在每次被调用时返回序列中的下一个值。当序列下一个值为空时，next() 应该返回 nil
 *
 */

// 自定义一个 sequence 其实只需要实现 makeIterator 方法就可以了

struct CustomIterator: IteratorProtocol {
    
    var num = 0
    
    mutating func next() -> Int? {
        
        num += 1
        
        if num == 10 {
            
            return nil
        }
        return num
    }
}

struct CustomSequence: Sequence {
    
     func makeIterator() -> CustomIterator {
        
        return CustomIterator()
    }
}

class SequenceTestController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        self.view.backgroundColor = .white
        
        // 测试自定义 sequence
        let sequence = CustomSequence()
        
        for item in sequence {
            
            print(item)  // 1 2 3 4 5 6 7 8 9
            
        }
        
        //MARK: - 实际上 for in 是转换成为下面的代码
        
        let animals = ["Antelope", "Butterfly", "Camel", "Dolphin"]
        for animal in animals {
            print(animal)
        }

        var animalIterator = animals.makeIterator()
        while let animal = animalIterator.next() {
            print(animal)
        }
        
    }
    
}

