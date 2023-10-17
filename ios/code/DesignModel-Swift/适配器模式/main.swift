//
//  main.swift
//  适配器模式
//
//  Created by WTW on 2021/6/7.
//  Copyright © 2021 WTW. All rights reserved.
//

import Foundation

/**
 * 适配器模式的三个角色：
 * Target目标角色
 * Adaptee 源角色
 * Adapter 适配器角色
 *
 * swift 实现适配器模式有两种方式 ：
 * Extension
 * 创建适配器类
 */

protocol Jumping {
    func jump()
}

class Dog: Jumping {
    func jump() {
        print("Dog Jump")
    }
}

class Cat: Jumping {
    func jump() {
        print("Cat Jump")
    }
}

// 假如需要 Flog 和已有的类有相同的操作
class Frog {
    func leap() {
        print("Flag leaps")
    }
}

let cat = Cat()
let dog = Dog()
let frog = Frog()
//var animals:[Jumping] = [cat,dog]

//func jumpAll(animals: [Jumping], frog: Frog? = nil) {
// for animal in animals {
//   animal.jump()
// }
// if let frog = frog {
//   frog.leap()
// }
//}

// Extension 方式
extension Frog: Jumping {
    func jump() {
        leap()
    }
}

jumpAll(animals: animals);

func jumpAll(animals: [Jumping]){
    for animal in animals {
        animal.jump()
    }
}

// 适配器类
class FrogAdpter: Jumping {
    private let frog = Frog()
    func jump() {
        frog.leap()
    }
}

let frogAdpter = FrogAdpter()
let animals:[Jumping] = [dog,cat,frogAdpter]
jumpAll(animals: animals)

print("Hello, World!")

