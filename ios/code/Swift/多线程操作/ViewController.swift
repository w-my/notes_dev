//
//  ViewController.swift
//  多线程操作
//
//  Created by WTW on 2020/5/24.
//  Copyright © 2020 WTW. All rights reserved.
//  https://www.cnblogs.com/wjw-blog/p/13038553.html

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        //MARK: 常见多线程方案
        /*
         Thread (最轻量级的，需要自己管理线程的生命周期和线程同步。线程同步对数据的枷锁会有一定的系统开销)
         Cocoa Operation
         GCD(Grand Central Dispatch)
         */
        
        // MARK: Thread
        
        // 使用方式1
        /*
        for i in 0..<10 {
            Thread.detachNewThread {
                print(i)
            }
        }
         */
        /* 无序的
         0 5 4 6 7 8 9 1 2 3
         */
        
        // 使用方式2
        // Thread(target: <#T##Any#>, selector: <#T##Selector#>, object: <#T##Any?#>)
//        let thread = Thread(target: self, selector: #selector(threadWorker), object: nil)
//        // 需要手动start
//        thread.start()
    
        // 使用方式3
        // Thread.detachNewThreadSelector(<#T##selector: Selector##Selector#>, toTarget: <#T##Any#>, with: <#T##Any?#>)
//        Thread.detachNewThreadSelector(#selector(threadWorker), toTarget: self, with: nil)
       

        
        // MARK: 同步
        /*
        let queue = DispatchQueue(label: "com.tw.test")
        queue.sync {
            
            print("== start ==")
            
            for i in 0..<5 {
                print(i)
            }
            print("== end ==")
        }
        
        for i in 5...10 {
            print(i)
        }
        */
        /*
         == start ==
         0
         1
         2
         3
         4
         == end ==
         5
         6
         7
         8
         9
         10
         */
        
        // MARK: 异步
        /*
        let queue = DispatchQueue(label: "com.ffib.blog")

        queue.async {
            for i in 0..<5 {
                print(i)
            }
        }

        for i in 10..<15 {
            print(i)
        }
         */
        /*
         10
         11
         12
         13
         0
         1
         2
         3
         4
         14
         */
        
        // MARK:QoS 优先级
        /*
         // 用户无法感知，比较耗时的一些操作
         public static let background: DispatchQoS

         // 实用级别，不需要很快完成的任务
         public static let utility: DispatchQoS

         // 系统默认的优先级
         public static let `default`: DispatchQoS
         
         // 用户发起，需要在很快时间内完成的，例如用户的点击事件、以及用户的手势
         public static let userInitiated: DispatchQoS
         
         //用户交互级别 ，需要在极快的时间内完成，比如UI的显示
         public static let userInteractive: DispatchQoS

         public static let unspecified: DispatchQoS
         */
        
        // 相同优先级
        // 优先级相同，两个队列交替执行
        /*
        let queue1 = DispatchQueue(label: "com.tw.test1", qos: .utility)
        let queue2 = DispatchQueue(label: "com.tw.test2", qos: .utility)
        
        queue1.async {
            for i in 5..<10 {
                print(i)
            }
        }
        
        queue2.async {
            for i in 0..<5 {
                print(i)
            }
        }
        */
        /* 执行结果
         5
         6
         7
         8
         9
         0
         1
         2
         3
         4
         */
        
        // 不同优先级
        // 交替输出，CPU 会把更多的资源优先分配给优先级高的队列，等到CPU 空闲后z才分配资源给优先级低的队列
        /*
        let queue1 = DispatchQueue(label: "com.ffib.blog.queue1", qos: .default)
        let queue2 = DispatchQueue(label: "com.ffib.blog.queue2", qos: .utility)

        queue1.async {
            for i in 0..<5 {
                print(i)
            }
        }

        queue2.async {
            for i in 5..<10 {
                print(i)
            }
        }
        */
        
        // 主队列默认使用最高优先级，即 userInteractive ，最好慎用这一优先级，否则极有可能会影响用户体验
        // 一些不需要用户感知的操作，比如缓存等，使用 utility 即可
        
        // MARK: 串行队列
        // 不指定队列类型时，默认是串行队列
        /*
        let queue = DispatchQueue(label: "com.ffib.blog.initiallyInactive.queue", qos: .utility)

        queue.async {
            for i in 0..<5 {
                print(i)
            }
        }

        queue.async {
            for i in 5..<10 {
                print(i)
            }
        }

        queue.async {
            for i in 10..<15 {
                print(i)
            }
        }
        */
        /*
         0
         1
         2
         3
         4
         5
         6
         7
         8
         9
         10
         11
         12
         13
         14
         */
        
        //MARK: 并行队列
        // 所有任务时并行执行的
        /*
        let queue = DispatchQueue(label: "com.ffib.blog.concurrent.queue", qos: .utility, attributes: .concurrent)
        queue.async {
            for i in 0..<5 {
                print(i)
            }
        }

        queue.async {
            for i in 5..<10 {
                print(i)
            }
        }

        queue.async {
            for i in 10..<15 {
                print(i)
            }
        }
        */
        /*
         5
         6
         7
         8
         9
         10
         11
         12
         13
         14
         0
         1
         2
         3
         4
         */
        
        // attributes 还有另外一个枚举值 initiallyInactive 表示任务不会自动执行，需要手动触发，如果不设置，默认是添加完任务后，自动执行
        // 可以自由决定执行的时机
        /*
        let queue = DispatchQueue(label: "com.ffib.blog.concurrent.queue", qos: .utility,
        attributes: .initiallyInactive)
        queue.async {
            for i in 0..<5 {
                print(i)
            }
        }
        queue.async {
            for i in 5..<10 {
                print(i)
            }
        }
        queue.async {
            for i in 10..<15 {
                print(i)
            }
        }
        // 需要调用 activate 激活队列
        queue.activate()
        */
        /*
         0
         1
         2
         3
         4
         5
         6
         7
         8
         9
         10
         11
         12
         13
         14
         */
        
        // 并行队列 且 手动触发的情况
        /*
        let queue = DispatchQueue(label: "com.ffib.blog.concurrent.queue", qos: .utility,
                                  attributes: [.concurrent,.initiallyInactive])
        queue.async {
            for i in 0..<5 {
                print(i)
            }
        }
        queue.async {
            for i in 5..<10 {
                print(i)
            }
        }
        queue.async {
            for i in 10..<15 {
                print(i)
            }
        }
        // 手动触发
        queue.activate()
        */
        /*
         0
         1
         2
         3
         4
         10
         11
         12
         13
         14
         5
         6
         7
         8
         9
         */
        
        // MARK: - 延时执行
        // 通过对已创建的队列，调用延时任务的函数即可，时间是通过 DispatchTimeInterval 设置
        /*
            case seconds(Int)  // 秒

            case milliseconds(Int) // 毫秒

            case microseconds(Int) // 微秒

            case nanoseconds(Int)  // 纳秒

            case never
         */
        
        //  deadline : 系统睡眠后，会被挂起
        //  wallDeadline : 当系统睡眠后，会继续
        /*
        let queue = DispatchQueue(label: "com.tw.test")
        
        let time = DispatchTimeInterval.seconds(5)
        
        queue.asyncAfter(deadline: .now() + time) {
            print("wall dead line done")
        }
        
        queue.asyncAfter(wallDeadline: .now() + time) {
            print("dead line done")
        }
        */
        
        //MARK: timer
        /*
        let queue = DispatchQueue(label: "com.tw.test")
        var seconds = 10
        let timer = DispatchSource.makeTimerSource(flags: [], queue: queue)
        timer.schedule(deadline: .now(), repeating: 1.0)
        timer.setEventHandler {
           seconds -= 1
           if seconds < 0 {
               timer.cancel()
           } else {
               print(seconds)
           }
        }
        timer.resume()
        */
        //打印结果 9 8 7 6 5 4 3 2 1 0
        
        
        // MARK: - DispatchGroup
        // 如果想等到所有的队列任务执行完毕在进行某些操作时 ，使用 DispatchGroup
        /*
        let group = DispatchGroup()
        
        let queue1 = DispatchQueue(label: "com.ffib.blog.queue1", qos: .utility)
        let queue2 = DispatchQueue(label: "com.ffib.blog.queue2", qos: .utility)
        
        queue1.async(group: group) {
            for i in 0..<10 {
                print(i)
            }
        }
        
        queue2.async(group: group) {
            for i in 10..<20 {
                print(i)
            }
        }
        
        group.notify(queue: DispatchQueue.main) {
            print("done")
        }
        */
        /*
         10
         11
         12
         13
         14
         15
         16
         17
         18
         19
         0
         1
         2
         3
         4
         5
         6
         7
         8
         9
         done
         */
        
        // 如果想等待某一队列执行完毕再执行其他队列可以使用 wait
        /*
        let group = DispatchGroup()
        let queue1 = DispatchQueue(label: "com.ffib.blog.queue1", qos: .utility)
        let queue2 = DispatchQueue(label: "com.ffib.blog.queue2", qos: .utility)
        queue1.async(group: group) {
            for i in 0..<10 {
                print(i)
            }
        }
        queue2.async(group: group) {
            for i in 10..<20 {
                print(i)
            }
        }
        group.wait()
        //group内所有线程的任务执行完毕
        group.notify(queue: DispatchQueue.main) {
            print("done")
        }
        
        // 为了防止队列执行任务时出现阻塞，导致线程锁死，可以设置超时时间
//        group.wait(timeout: <#T##DispatchTime#>)
//        group.wait(wallTimeout: <#T##DispatchWallTime#>)
        */
        
        
        // MARK: group.enter group.leave
        /*
        let queue = DispatchQueue(label: "com.tw.test")
        
        let group = DispatchGroup()
        
        group.enter()
        queue.async {
            sleep(1)
            print("模拟接口请求1")
            group.leave()
        }
        
        group.enter()
        queue.async {
            sleep(1)
            print("模拟接口请求2")
            group.leave()
        }
        
        print("group enter() 调用完成")
        group.wait()//阻塞
        print("接口1，接口2调用完成")
         */
        /*
         group enter() 调用完成
         模拟接口请求1
         模拟接口请求2
         接口1，接口2调用完成
         */
        
        
        /*
        let queue = DispatchQueue(label: "com.tw.test")
        let groupn = DispatchGroup()
        groupn.enter()
        print("groupn enter() 调用完成")

        queue.async {
            sleep(1)
            print("模拟接口A请求完成")
            groupn.leave()
        }
        
        groupn.enter()
        queue.async {
            sleep(1)
            print("模拟接口B请求完成")
            groupn.leave()
        }
        
        print("groupn enter() 调用完成")
        groupn.notify(queue: queue) {
            print("接口A，接口B调用完成")
        }
        print("验证不阻塞")
        */
        /*
         groupn enter() 调用完成
         groupn enter() 调用完成
         验证不阻塞
         模拟接口A请求完成
         模拟接口B请求完成
         接口A，接口B调用完成
         */
        
        
        //MARK:- DispatchWorkItem
        /*
        // 通过设置此 api 设置队列执行的任务
        let workItem = DispatchWorkItem {
            for i in 0..<10 {
                print(i)
            }
        }
        
        // 调用分为两种情况，第一种是通过调用 perform() ,自动响应闭包
        DispatchQueue.global().async {
            workItem.perform()
        }
        
        // 第二种是作为参数传递给 async 方法
        DispatchQueue.global().async(execute: workItem)
        */
        
        // DispatchWorkItem 的内部属性和方法
        // DispatchWorkItem.init(qos: <#T##DispatchQoS#>, flags: <#T##DispatchWorkItemFlags#>, block: <#T##() -> Void#>)
        // DispatchWorkItem 可以设置优先级，另外还有个参数 DispatchWorkItemFlags
        // DispatchWorkItemFlags 主要分两部分：
        /*
         覆盖
             noQoS 没有优先级
             inheritQoS 继承Queue的优先级
             enforceQoS 覆盖Queue的优先级
         执行情况
             barrier
             detached
             assignCurrentContext
         */
        /*
        DispatchWorkItemFlags
         
        public static let barrier: DispatchWorkItemFlags

        public static let detached: DispatchWorkItemFlags
       
        public static let assignCurrentContext: DispatchWorkItemFlags
        
        public static let noQoS: DispatchWorkItemFlags   // 没有优先级
       
        public static let inheritQoS: DispatchWorkItemFlags  // 继承 Queue的优先级
       
        public static let enforceQoS: DispatchWorkItemFlags  // 覆盖 Queue的优先级
         */
        
        // 下面例子可以看出即使设置了 DispatchWorkItem 仅仅只设置了优先级并不会对任务执行顺序有任何的影响
        /*
        let queue1 = DispatchQueue(label: "com.ffib.blog.workItem1", qos: .utility)
        let queue2 = DispatchQueue(label: "com.ffib.blog.workItem2", qos: .userInitiated)
        let workItem1 = DispatchWorkItem(qos: .userInitiated) {
            for i in 0..<5 {
                print(i)
            }
        }
        let workItem2 = DispatchWorkItem(qos: .utility) {
            for i in 5..<10 {
                print(i)
            }
        }
        queue1.async(execute: workItem1)
        queue2.async(execute: workItem2)
        */
        /*
        执行结果
         5
         6
         7
         8
         9
         0
         1
         2
         3
         4
         */
        
        // 设置enforceQoS，使优先级强制覆盖queue的优先级，所以两个队列呈交替执行状态，变为同一优先级。
        /*
        let queue1 = DispatchQueue(label: "com.ffib.blog.workItem1", qos: .utility)
        let queue2 = DispatchQueue(label: "com.ffib.blog.workItem2", qos: .userInitiated)

        let workItem1 = DispatchWorkItem(qos: .userInitiated, flags: .enforceQoS) {
            for i in 0..<5 {
                print(i)
            }
        }

        let workItem2 = DispatchWorkItem {
            for i in 5..<10 {
                print(i)
            }
        }

        queue1.async(execute: workItem1)
        queue2.async(execute: workItem2)
        */
        /*
         执行结果：
         0
         5
         1
         2
         3
         4
         6
         7
         8
         9
         */
        
        // DispatchWorkItem也有wait和notify方法，和DispatchGroup用法相同。

        //MARK: barrier
        /*
    可以理解为隔离，还是以文件读写为例，在读取文件时，可以异步访问，但是如果突然出现了异步写入操作，我们想要达到的效果是在进行写入操作的时候，使读取操作暂停，直到写入操作结束，再继续进行读取操作，以保证读取操作获取的是文件的最新内容。
        以上文中的test.txt文件为例，预期结果是：在写入操作之前，读取到的内容是test4；在写入操作之后，读取到的内容是done（即写入的内容）。
        barrier主要用于读写隔离，以保证写入的时候，不被读取。
        */
        /*
         let queue = DispatchQueue(label: "com.ffib.blog.queue", qos: .utility, attributes: .concurrent)

         let path = NSHomeDirectory() + "/test.txt"
         print(path)

         let readWorkItem = DispatchWorkItem {
             do {
                 let str = try String(contentsOfFile: path, encoding: .utf8)
                 print(str)
             }catch {
                 print(error)
             }
             sleep(1)
         }

         let writeWorkItem = DispatchWorkItem(flags: []) {
             do {
                 try "done".write(toFile: path, atomically: true, encoding: String.Encoding.utf8)
                 print("write")
             }catch {
                 print(error)
             }
             sleep(1)
         }
         for _ in 0..<3 {
             queue.async(execute: readWorkItem)
         }
         queue.async(execute: writeWorkItem)
         for _ in 0..<3 {
             queue.async(execute: readWorkItem)
         }
            
         输出结果：
         test4
         test4
         test4
         test4
         test4
         test4
         write
        */

        /*
        let queue = DispatchQueue(label: "com.ffib.blog.queue", qos: .utility, attributes: .concurrent)

        let path = NSHomeDirectory() + "/test.txt"
        print(path)

        let readWorkItem = DispatchWorkItem {
            do {
                let str = try String(contentsOfFile: path, encoding: .utf8)
                print(str)
            }catch {
                print(error)
            }
        }

        let writeWorkItem = DispatchWorkItem(flags: .barrier) {
            do {
                try "done".write(toFile: path, atomically: true, encoding: String.Encoding.utf8)
                print("write")
            }catch {
                print(error)
            }
        }

        for _ in 0..<3 {
            queue.async(execute: readWorkItem)
        }
        queue.async(execute: writeWorkItem)
        for _ in 0..<3 {
            queue.async(execute: readWorkItem)
        }

        output:
        test4
        test4
        test4
        write
        done
        done
        done
        */
        
        
        //MARK:DispatchSemaphore
        // 如果想同步执行一个异步任务，可以使用信号量
        // wait()会使信号量减一，如果信号量大于1则会返回.success，否则返回timeout（超时），也可以设置超时时间
        // func wait(wallTimeout: DispatchWallTime) -> DispatchTimeoutResult
        // func wait(timeout: DispatchTime) -> DispatchTimeoutResult
        // signal()会使信号量加一，返回当前信号量。


        /*
        //初始化信号量为1
        let semaphore = DispatchSemaphore(value: 1)

        let queue = DispatchQueue(label: "com.ffib.blog.queue", qos: .utility, attributes: .concurrent)
        let fileManager = FileManager.default
        let path = NSHomeDirectory() + "/test.txt"
        print(path)
        fileManager.createFile(atPath: path, contents: nil, attributes: nil)

        //循环写入，预期结果为test4,实际不是
        for i in 0..<5 {
            queue.async {
                do {
                    try "test\(i)".write(toFile: path, atomically: true, encoding: String.Encoding.utf8)
                }catch {
                    print(error)
                }
                semaphore.signal()
            }
        }
        */
        
        /*
        let semaphore = DispatchSemaphore(value: 1)
        let queue = DispatchQueue(label: "com.ffib.blog.queue", qos: .utility, attributes: .concurrent)
        let fileManager = FileManager.default
        let path = NSHomeDirectory() + "/test.txt"
        print(path)
        fileManager.createFile(atPath: path, contents: nil, attributes: nil)
        for i in 0..<5 {
            //.distantFuture代表永远
            if semaphore.wait(wallTimeout: .distantFuture) == .success {
                queue.async {
                    do {
                        print(i)
                        try "test\(i)".write(toFile: path, atomically: true, encoding: String.Encoding.utf8)
                    }catch {
                        print(error)
                    }
                    semaphore.signal()
                }
            }
        }
        */
    // DispatchSemaphore还有另外一个用法，可以限制队列的最大并发量，通过前面所说的wait()信号量减一，signal()信号量加一，来完成此操作，
    // 正如上文所述例子，其实达到的效果就是最大并发量为一
        

        // 异步操作 主线程回调
        DispatchQueue.global().async {

            print(Thread.current)

            DispatchQueue.main.async {
                print(Thread.current)
            }
        }
    }
    
    @objc func threadWorker() {
        print("threadWorker"+"当前线程\(Thread.current)")
    }
}

