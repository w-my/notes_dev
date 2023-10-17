//
//  ViewController.m
//  内存管理-autorelease释放时机
//
//  Created by WTW on 2019/9/4.
//  Copyright © 2019 wtw. All rights reserved.
//


#import "ViewController.h"
#import "Person.h"

/*
 参考文章：
 http://blog.leichunfeng.com/blog/2015/05/31/objective-c-autorelease-pool-implementation-principle/#jtss-tsina
 http://blog.sunnyxx.com/2014/10/15/behind-autorelease/
 */

// autorelease  与 RunLoop 关系:
/*
 在iOS 程序启动后会注册两个 Observer (_wrapRunLoopWithAutoreleasePoolHandler)管理和维护 AutoreleasePool ：
 
     第一个Observer会监听RunLoop的进入，它会回调objc_autoreleasePoolPush()向当前的AutoreleasePoolPage增加一个哨兵对象标志创建自动释放池。
     这个Observer的order是-2147483647优先级最高，确保发生在所有回调操作之前。

     第二个Observer会监听 RunLoop的进入休眠 和 即将退出RunLoop 两种状态，在即将进入休眠时会调用objc_autoreleasePoolPop() 和 objc_autoreleasePoolPush() 根据情况从最新加入的对象一直往前清理直到遇到哨兵对象。而在即将退出RunLoop时会调用objc_autoreleasePoolPop() 释放自动自动释放池内对象。
     这个Observer的order是2147483647，优先级最低，确保发生在所有回调操作之后。
     
 其实在应用程序启动后系统还注册了其他 Observer (例如即将进入休眠时执行注册回调 _UIGestureRecognizerUpdateObserver 用于手势处理,回调为 _ZN2CA11Transaction17observer_callbackEP19__CFRunLoopObservermPv 的Observer 用于界面实时绘制更新) 和 多个 Source1
 在主线程执行的代码，通常是写在比如事件回调、timer 回调内的，这些回调会被 RunLoop 创建好的 AutoreleasePool 包裹着，所以不会出现内存泄露，开发者也不必显示创建Pool

 自动释放池的创建和释放、销毁时机如下：
     kCFRunLoopEntry; // 进入runloop之前，创建一个自动释放池  push
     kCFRunLoopBeforeWaiting; // 休眠之前，销毁自动释放池，创建一个新的自动释放池 pop push
     kCFRunLoopExit; // 退出runloop之前，销毁自动释放池 pop
 
 什么情况下需要创建自动释放池？？？(子线程，因为子线程没有默认开启RunLoop)
    其实自动释放池存在的意义是为了延迟释放一些对象，延迟向对象发送release消息。在实际的开发中，有以下情况是需要手动创建自动释放池的。
    1、如果你编写的程序不是基于 UI 框架的，比如说命令行工具；
    2、如果你编写的循环中创建了大量的临时对象；
    3、如果你创建了一个子线程。
 
 默认主线的运行循环（runloop）是开启的，子线程的运行循环默认是不开启的，也就意味着子线程中不会创建autoreleasepool，所以需要我们自己在子线程中创建一个自动释放池。（子线程里面使用的类方法都是autorelease,就会没有池子可释放，也就意味着后面没有办法进行释放，造成内存泄漏。）
 在主线程中如果产生事件那么runloop才回去创建autoreleasepool，通过这个道理我们就知道为什么子线程中不会创建自动释放池了，因为子线程的runloop默认是关闭的，所以他不会自动创建autoreleasepool，需要我们手动添加
 NSThread和NSOperationQueue开辟子线程需要手动创建autoreleasepool，GCD开辟子线程不需要手动创建autoreleasepool，因为GCD的每个队列都会自行创建autoreleasepool
 */

/*
 iOS在主线程的Runloop中注册了2个Observer
 第1个Observer监听了kCFRunLoopEntry事件，会调用objc_autoreleasePoolPush()
 第2个Observer
    监听了kCFRunLoopBeforeWaiting事件，会调用objc_autoreleasePoolPop()、objc_autoreleasePoolPush()
    监听了kCFRunLoopBeforeExit事件，会调用objc_autoreleasePoolPop()

 */

@interface ViewController ()

@end

@implementation ViewController

// person 什么时候销毁？
// 在其所处的那次 Runloop 循环休眠之前调用了 release
/* 打印顺序
 =====1=====
 =====2====
 [Person dealloc]
 */

- (void)viewDidLoad {
    [super viewDidLoad];
    
//    NSLog(@"=====1=====");
//
//    // 这个 person 什么时候调用 release 是由 Runloop 来控制的
//    // person 可能是所处的那次 Runloop 循环休眠之前调用了 release
//    Person *person = [[[Person alloc] init] autorelease];
//
//    NSLog(@"%s",__func__);
//
//    NSLog(@"=====2=====");
//
//    // 打印 [NSRunLoop currentRunLoop] 查看 Observer
//    NSLog(@"%@",[NSRunLoop currentRunLoop]);
    
    
    // __CFRUNLOOP_IS_CALLING_OUT_TO_A_SOURCE0_PERFORM_FUNCTION__
   
    
//    [self test1];
//    [self test2];
    [self test3];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    NSLog(@"%s %@",__func__,string_weak);
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    NSLog(@"%s %@",__func__,string_weak);
    
    // __CFRUNLOOP_IS_CALLING_OUT_TO_A_BLOCK__
    
}

/*
 iOS在主线程的Runloop中注册了2个Observer
    第1个Observer监听了kCFRunLoopEntry事件，会调用objc_autoreleasePoolPush()
    第2个Observer
    监听了kCFRunLoopBeforeWaiting事件，会调用objc_autoreleasePoolPop()、objc_autoreleasePoolPush()
    监听了kCFRunLoopBeforeExit事件，会调用objc_autoreleasePoolPop()
 
 _wrapRunLoopWithAutoreleasePoolHandler
    activities = 0x1 -> 十进制 1        kCFRunLoopEntry   push操作
 
 _wrapRunLoopWithAutoreleasePoolHandler
    activities = 0xa0 -> 十进制160     kCFRunLoopBeforeWaiting | kCFRunLoopExit
 
 kCFRunLoopBeforeWaiting        先pop 然后push
 kCFRunLoopExit                 直接 pop
 
 */

/*
 // Run Loop Observer Activities
typedef CF_OPTIONS(CFOptionFlags, CFRunLoopActivity) {
    kCFRunLoopEntry = (1UL << 0),  1
    kCFRunLoopBeforeTimers = (1UL << 1),  2
    kCFRunLoopBeforeSources = (1UL << 2),  4
    kCFRunLoopBeforeWaiting = (1UL << 5),  32
    kCFRunLoopAfterWaiting = (1UL << 6),   64
    kCFRunLoopExit = (1UL << 7),          128
    kCFRunLoopAllActivities = 0x0FFFFFFFU
};
 */

/* 打印 [NSRunLoop currentRunLoop] 查看 Observer
 observers = (
     "<CFRunLoopObserver 0x6000028ac780 [0x10d8e8ae8]>{valid = Yes, activities = 0x1, repeats = Yes, order = -2147483647, callout = _wrapRunLoopWithAutoreleasePoolHandler (0x1103e387d), context = <CFArray 0x6000017fc5a0 [0x10d8e8ae8]>{type = mutable-small, count = 1, values = (\n\t0 : <0x7fbab0009058>\n)}}",
 
     "<CFRunLoopObserver 0x6000028a0140 [0x10d8e8ae8]>{valid = Yes, activities = 0x20, repeats = Yes, order = 0, callout = _UIGestureRecognizerUpdateObserver (0x10ffc7d19), context = <CFRunLoopObserver context 0x6000032a0000>}",
 
     "<CFRunLoopObserver 0x6000028ac640 [0x10d8e8ae8]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 1999000, callout = _beforeCACommitHandler (0x110411245), context = <CFRunLoopObserver context 0x7fbaafe04130>}",
 
     "<CFRunLoopObserver 0x6000028a4fa0 [0x10d8e8ae8]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 2000000, callout = _ZN2CA11Transaction17observer_callbackEP19__CFRunLoopObservermPv (0x111de0e92), context = <CFRunLoopObserver context 0x0>}",
 
     "<CFRunLoopObserver 0x6000028ac6e0 [0x10d8e8ae8]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 2001000, callout = _afterCACommitHandler (0x1104112af), context = <CFRunLoopObserver context 0x7fbaafe04130>}",
 
     "<CFRunLoopObserver 0x6000028ac820 [0x10d8e8ae8]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 2147483647, callout = _wrapRunLoopWithAutoreleasePoolHandler (0x1103e387d), context = <CFArray 0x6000017fc5a0 [0x10d8e8ae8]>{type = mutable-small, count = 1, values = (\n\t0 : <0x7fbab0009058>\n)}}"
 ),
  */

/*
 _UIGestureRecognizerUpdateObserver                                0x20  -> 32      kCFRunLoopBeforeWaiting
 _beforeCACommitHandler                                            0xa0  -> 160     kCFRunLoopBeforeWaiting |   kCFRunLoopExit
 _ZN2CA11Transaction17observer_callbackEP19__CFRunLoopObservermPv  0xa0  -> 160     kCFRunLoopBeforeWaiting |   kCFRunLoopExit
 _afterCACommitHandler                                             0xa0  -> 160     kCFRunLoopBeforeWaiting |   kCFRunLoopExit
 */


// 使用 __weak 为了不影响对象生命周期的测试
__weak NSString *string_weak = nil;

/*
 string: 测试autorelease 什么时候释放
 -[ViewController viewWillAppear:] 测试autorelease 什么时候释放
 -[ViewController viewDidAppear:] (null)
  
 结论：在 viewWillAppear 和 viewDidAppear 之间某个时间， autorelease 被释放了
 
 验证：通过设置断点 watchpoint set v string_weak，观察打印和函数调用栈即可验证
 */
- (void)test1 {
    
    NSString *string = [NSString stringWithFormat:@"测试autorelease 什么时候释放"];
    string_weak = string;
    
    NSLog(@"string: %@",string_weak);
}

/*
 string: (null)
 -[ViewController viewWillAppear:] (null)
 -[ViewController viewDidAppear:] (null)

 */
- (void)test2 {
    @autoreleasepool {
        NSString *string = [NSString stringWithFormat:@"测试autorelease 什么时候释放"];
        string_weak = string;
    }
    NSLog(@"string: %@",string_weak);
}

/*
 string: (null)
 -[ViewController viewWillAppear:] (null)
 -[ViewController viewDidAppear:] (null)
 */
- (void)test3 {
    NSString *string = nil;
    @autoreleasepool {
        string = [NSString stringWithFormat:@"测试autorelease 什么时候释放"];
        string_weak = string;
    }
     NSLog(@"string: %@",string_weak);
}

@end

