//
//  main.swift
//  并发
//
//  Created by WTW on 2021/8/10.
//  Copyright © 2021 WTW. All rights reserved.
//

import Foundation

// swift 为写异步和并行提供了内置的结构化方式，异步代码可以挂起并稍后继续。
// swift 的并发模型是构建在线程之上的，不会直接与他们互动，在swift 中异步函数能让出线程，允许另一个异步函数在第一个函数阻塞时在这个线程执行。

// MARK: - 定义和调用异步函数
// 异步函数和异步方法是一种特殊的能在执行一部分时挂起函数或者方法，(之前同步函数是要么失败要么返回内容）在异步函数或方法内部可以标记哪里可以挂起。
// 要标记函数或者方法是异步的，需要在声明中形参后面使用 async 关键字，如果函数或者方法有返回值，就把 async 写在返回箭头前面。
/*
func listPhotos(inGallery name: String) async -> [String] {
    
    let result =  // ... some asynchronous networking code ...
    return result
}
*/

// 当调用异步方法时，执行会挂起直到那个方法返回，在调用钱使用 await 来标记可能会挂起的位置，类似 try 一样。在异步方法内部，执行的流程只会在你调用另一个异步方法时挂起(挂起不会隐含或者抢先,即所有可能的挂起位置都会用 await 标记)

/*
 let photoNames = await listPhotos(inGallery: "Summer Vacation")
 let sortedNames = photoNames.sorted()
 let name = sortedNames[1]
 let photo = await downloadPhoto(named: name)
 show(photo)
 */


// MARK: - 异步序列


// MARK: - 并行调用异步方法


