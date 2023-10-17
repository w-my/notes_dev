//
//  ViewController.m
//  多线程-05(dispatch_barrier_async 读写安全方案2)
//
//  Created by WTW on 2020/2/17.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property (nonatomic,strong) dispatch_queue_t queue;

@end

@implementation ViewController

/*
 栅栏函数不能使用全局并发队列(系统提供的)
 
     并发队列必须是自己通过dispatch_queue_cretate创建的 (DISPATCH_QUEUE_CONCURRENT)
     如果传入的是一个串行或是一个全局的并发队列，那这个函数便等同于dispatch_async函数的效果 （栅栏函数没效果）
 
 dispatch_barrier_xxx ：栅栏函数可以实现多读单写的需求，多线程同时读，但只有一个线程写的操作，并且写操作完成后才能继续读
 dispatch_barrier_async ：异步栅栏时，栅栏函数在子线程中执行；
 dispatch_barrier_sync ： 同步栅栏时，栅栏函数在主线程中执行；
 */

- (void)viewDidLoad {
    [super viewDidLoad];
    
//    _queue = dispatch_get_global_queue(0, 0);
//    _queue = dispatch_queue_create("myQueue", DISPATCH_QUEUE_SERIAL);
    
    // 并发队列必须是自己通过dispatch_queue_cretate创建的
    _queue = dispatch_queue_create("myQueue", DISPATCH_QUEUE_CONCURRENT);
    
    /// 测试读写安全
//    [self testReadWrite];
    
    /// 测试 dispatch_barrier_async
//    [self testbarrier_async];
    
    /// 测试 dispatch_barrier_sync
//    [self testbarrier_sync];
    
    // 测试栅栏函数 使用非自定义的并发队列
    [self testQueue];
}

/// 测试读写安全
- (void)testReadWrite {
    
    for (int i = 0; i < 10; i++) {
        [self read];
        [self read];
        [self write];
    }
}

- (void)read {
    dispatch_async(_queue, ^{
        sleep(1);
        NSLog(@"read");
    });
}

- (void)write {
    dispatch_barrier_async(_queue, ^{
        sleep(1);
        NSLog(@"write");
    });
}

/*
 2022-02-22 15:44:38.499620+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[88583:2833411] ====aaa======
 2022-02-22 15:44:38.499777+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[88583:2833411] ====bbb====
 2022-02-22 15:44:38.499898+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[88583:2833463] =====1111==== <NSThread: 0x600000c05700>{number = 6, name = (null)}
 2022-02-22 15:44:38.499912+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[88583:2833411] ====ccc====
 2022-02-22 15:44:38.500007+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[88583:2833465] =====2222==== <NSThread: 0x600000c003c0>{number = 3, name = (null)}
 2022-02-22 15:44:38.500063+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[88583:2833411] ====ddd====
 2022-02-22 15:44:38.500100+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[88583:2833463] =====3333==== <NSThread: 0x600000c05700>{number = 6, name = (null)}
 2022-02-22 15:44:38.500167+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[88583:2833411] ====eeee====
 2022-02-22 15:44:38.500257+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[88583:2833463] =====dispatch_barrier_sync==== <NSThread: 0x600000c05700>{number = 6, name = (null)}
 2022-02-22 15:44:38.500512+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[88583:2833411] ====ffff====
 2022-02-22 15:44:38.501093+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[88583:2833462] =====5555==== <NSThread: 0x600000c0d5c0>{number = 5, name = (null)}
 2022-02-22 15:44:38.501090+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[88583:2833463] =====4444==== <NSThread: 0x600000c05700>{number = 6, name = (null)}
 */

// dispatch_barrier_async 是在子线程中执行，不会阻塞线程
- (void)testbarrier_async {
    
    NSLog(@"====aaa======");
    dispatch_async(_queue, ^{
        sleep(0.5);
        NSLog(@"=====1111==== %@",[NSThread currentThread]);
    });
    NSLog(@"====bbb====");
    dispatch_async(_queue, ^{
        sleep(0.5);
        NSLog(@"=====2222==== %@",[NSThread currentThread]);
    });
    NSLog(@"====ccc====");
    dispatch_async(_queue, ^{
        sleep(0.5);
        NSLog(@"=====3333==== %@",[NSThread currentThread]);
    });
    NSLog(@"====ddd====");
    dispatch_barrier_async(_queue, ^{
        NSLog(@"=====dispatch_barrier_sync==== %@",[NSThread currentThread]);
    });
    NSLog(@"====eeee====");
    dispatch_async(_queue, ^{
        sleep(0.5);
        NSLog(@"=====4444==== %@",[NSThread currentThread]);
    });
    NSLog(@"====ffff====");
    dispatch_async(_queue, ^{
        sleep(0.5);
        NSLog(@"=====5555==== %@",[NSThread currentThread]);
    });
}

/*
 2022-02-22 16:40:17.632750+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[89674:2870079] ====aaa======
 2022-02-22 16:40:17.632939+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[89674:2870079] ====bbb====
 2022-02-22 16:40:17.633030+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[89674:2870166] =====1111==== <NSThread: 0x6000038bd040>{number = 6, name = (null)}
 2022-02-22 16:40:17.633077+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[89674:2870079] ====ccc====
 2022-02-22 16:40:17.633175+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[89674:2870169] =====2222==== <NSThread: 0x6000038c6400>{number = 7, name = (null)}
 2022-02-22 16:40:17.633227+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[89674:2870079] ====ddd====
 2022-02-22 16:40:17.633273+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[89674:2870166] =====3333==== <NSThread: 0x6000038bd040>{number = 6, name = (null)}
 2022-02-22 16:40:17.633427+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[89674:2870079] =====dispatch_barrier_sync==== <_NSMainThread: 0x6000038fc5c0>{number = 1, name = main}
 2022-02-22 16:40:17.633715+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[89674:2870079] ====eeee====
 2022-02-22 16:40:17.634092+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[89674:2870079] ====ffff====
 2022-02-22 16:40:17.634172+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[89674:2870166] =====4444==== <NSThread: 0x6000038bd040>{number = 6, name = (null)}
 2022-02-22 16:40:17.634607+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[89674:2870169] =====5555==== <NSThread: 0x6000038c6400>{number = 7, name = (null)}
 */

// dispatch_barrier_sync 是在主线程中执行(会阻塞当前线程主线程，会卡住后面的任务，包括打印)
- (void)testbarrier_sync {
    
    NSLog(@"====aaa======");
    dispatch_async(_queue, ^{
        sleep(0.5);
        NSLog(@"=====1111==== %@",[NSThread currentThread]);
    });
    NSLog(@"====bbb====");
    dispatch_async(_queue, ^{
        sleep(0.5);
        NSLog(@"=====2222==== %@",[NSThread currentThread]);
    });
    NSLog(@"====ccc====");
    dispatch_async(_queue, ^{
        sleep(0.5);
        NSLog(@"=====3333==== %@",[NSThread currentThread]);
    });
    NSLog(@"====ddd====");
    dispatch_barrier_sync(_queue, ^{
        NSLog(@"=====dispatch_barrier_sync==== %@",[NSThread currentThread]);
    });
    NSLog(@"====eeee====");
    dispatch_async(_queue, ^{
        sleep(0.5);
        NSLog(@"=====4444==== %@",[NSThread currentThread]);
    });
    NSLog(@"====ffff====");
    dispatch_async(_queue, ^{
        sleep(0.5);
        NSLog(@"=====5555==== %@",[NSThread currentThread]);
    });
}


// 测试非自己创建的并发队列 或者 自己创建的串行队列
- (void)testQueue {
 
    /*
     2022-02-22 19:45:24.692242+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[93235:2980349] =====1111======
     2022-02-22 19:45:24.692542+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[93235:2980349] =====2222======
     2022-02-22 19:45:24.692710+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[93235:2980251] =====dispatch_barrier_sync======
     2022-02-22 19:45:24.692919+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[93235:2980349] =====3333======
     2022-02-22 19:45:24.693114+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[93235:2980349] =====44444======
     */
//    dispatch_queue_t queue = dispatch_queue_create("myQueue", DISPATCH_QUEUE_SERIAL);  // 串行
    
    /*
     2022-02-22 19:47:07.764826+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[93325:2983331] =====2222====== <NSThread: 0x60000351c7c0>{number = 7, name = (null)}
     2022-02-22 19:47:07.764931+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[93325:2983320] =====dispatch_barrier_sync====== <NSThread: 0x60000354f580>{number = 8, name = (null)}
     2022-02-22 19:47:07.764967+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[93325:2983332] =====3333====== <NSThread: 0x600003511c40>{number = 5, name = (null)}
     2022-02-22 19:47:07.765228+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[93325:2983331] =====44444====== <NSThread: 0x60000351c7c0>{number = 7, name = (null)}
     2022-02-22 19:47:08.766112+0800 多线程-05(dispatch_barrier_async 读写安全方案2)[93325:2983328] =====1111====== <NSThread: 0x600003569940>{number = 6, name = (null)}
     */
    dispatch_queue_t queue = dispatch_get_global_queue(0, 0);
        
    dispatch_async(queue, ^{
        NSLog(@"=====1111====== %@",[NSThread currentThread]);
    });
    
    dispatch_async(queue, ^{
        NSLog(@"=====2222====== %@",[NSThread currentThread]);
    });
    
    dispatch_barrier_async(queue, ^{
        NSLog(@"=====dispatch_barrier_sync====== %@",[NSThread currentThread]);
    });
    
    dispatch_async(queue, ^{
        NSLog(@"=====3333====== %@",[NSThread currentThread]);
    });
    
    dispatch_async(queue, ^{
        NSLog(@"=====44444====== %@",[NSThread currentThread]);
    });
}

@end
