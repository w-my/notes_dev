//
//  ViewController.m
//  多线程-01
//
//  Created by WTW on 2019/7/30.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

/*
 面试题
 performSelector:withObject:afterDelay: 方法是在 Runloop 中定义的
 afterDelay 的底层是用到了定时器，定时器只有加入到 RunLoop 并且Runloop 唤醒的时候才会触发
 
 打印结果是 1 3
 原因是 performSelector:withObject:afterDelay:的本质是往Runloop中添加定时器
 子线程 默认没有开启 RunLoop
 
 // 开启runLoop 后打印结果是 1 3 2
*/

- (void)interview1 {
    
    // 子线程中默认不会开始runloop
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        NSLog(@"1");
        
        //performSelector 的本质是往runloop 中添加定时器
        //但是必须启动 runloop 才会执行
        [self  performSelector:@selector(test) withObject:self afterDelay:.0];
        
        // 这句话是通过 Runtime 来调用的
//        [self performSelector:@selector(test) withObject:self];
        
        // 这个方法是在 NSRunLoop 中定义的(并不是通过Runtime 来调用的)，本质是往 RunLoop 中添加定时器
        // 所以在子线程中使用必须手动开启 RunLoop
        // [self performSelector:<#(nonnull SEL)#> withObject:<#(nullable id)#> afterDelay:<#(NSTimeInterval)#>]
        
        NSLog(@"3");
        
        // 手动开启 RunLoop 以后就是 1 3 2 (只写run 也是可以的，performSelector:withObject:afterDelay:已经添加了Timer)
//         [[NSRunLoop currentRunLoop] addPort:[[NSPort alloc] init] forMode:NSDefaultRunLoopMode];
//         [[NSRunLoop currentRunLoop] runMode:NSDefaultRunLoopMode beforeDate:[NSDate distantFuture]];
        
    });
}

- (void)test {
    NSLog(@"2");
}

/**
 面试题2
 */
- (void)interview2 {
    NSThread *thread = [[NSThread alloc] initWithBlock:^{
        NSLog(@"1");
        
          //必须启动 RunLoop 能保证线程不会死，等到 performSelector 唤醒时候才会执行
          //否者执行完就直接销毁了 thread
        [[NSRunLoop currentRunLoop] addPort:[[NSPort alloc] init] forMode:NSDefaultRunLoopMode];
        [[NSRunLoop currentRunLoop] runMode:NSDefaultRunLoopMode beforeDate:[NSDate distantFuture]];
        
    }];
    [thread start];
    //target thread exited while waiting for the perform'
    // 上面代码执行完线程就销毁了，只有开启了runLoop 才会不会销毁线程(阻塞)，下面的代码才会没问题
    [self performSelector:@selector(test) onThread:thread withObject:nil waitUntilDone: YES];
}

- (void)interview3 {
    dispatch_group_t group = dispatch_group_create();
    dispatch_queue_t queue = dispatch_queue_create("myqueue", DISPATCH_QUEUE_CONCURRENT);
    dispatch_group_async(group, queue, ^{
        NSLog(@"任务1");
    });
    dispatch_group_async(group, queue, ^{
        NSLog(@"任务2");
    });
    dispatch_group_notify(group, dispatch_get_main_queue(), ^{
        NSLog(@" 任务1、任务2执行完了,开始执行任务3");
    });
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
//    [self interview1];
    
    //测试死锁
//    [self interView4];
//    [self interView5];
//    [self interView6];
//    [self interView7];
    
    [self interview8];
}

#pragma mark - 死锁相关 (使用 sync函数 往 当前串行队列 中添加任务，会卡住当前的串行队列（产生死锁）)


// 以下程序会不会死锁 ?? 会产生死锁
/*
 2020-02-14 11:46:24.415080+0800 多线程-01(面试题)[44934:2947123] 任务1
 2020-02-14 11:46:24.415447+0800 多线程-01(面试题)[44934:2947123] 任务5
 2020-02-14 11:46:24.415471+0800 多线程-01(面试题)[44934:2947249] 任务2
 */
// 会产生死锁
- (void)interView4 {
    NSLog(@"任务1");
    dispatch_queue_t queue = dispatch_queue_create("muQueue", DISPATCH_QUEUE_SERIAL);
    dispatch_async(queue, ^{
        NSLog(@"任务2");
        
        dispatch_sync(queue, ^{
            NSLog(@"任务3");
        });
        
        NSLog(@"任务4");
    });
    NSLog(@"任务5");
    
}

// 不会产生死锁
/*
 2020-02-14 11:51:24.730657+0800 多线程-01(面试题)[45002:2950907] 任务1
 2020-02-14 11:51:24.731070+0800 多线程-01(面试题)[45002:2950907] 任务5
 2020-02-14 11:51:24.731091+0800 多线程-01(面试题)[45002:2950931] 任务2
 2020-02-14 11:51:24.731226+0800 多线程-01(面试题)[45002:2950931] 任务3
 2020-02-14 11:51:24.731331+0800 多线程-01(面试题)[45002:2950931] 任务4
 */
- (void)interView5 {
   NSLog(@"任务1");
   dispatch_queue_t queue = dispatch_queue_create("muQueue", DISPATCH_QUEUE_SERIAL);
   dispatch_queue_t queue2 = dispatch_queue_create("muQueue", DISPATCH_QUEUE_CONCURRENT);
   dispatch_async(queue, ^{
       NSLog(@"任务2");
       
       dispatch_sync(queue2, ^{
           NSLog(@"任务3");
       });
       
       NSLog(@"任务4");
   });
   NSLog(@"任务5");
}

/*
 2020-02-17 10:23:26.798244+0800 多线程-01(面试题)[52690:3651656] 任务1
 2020-02-17 10:23:26.798879+0800 多线程-01(面试题)[52690:3651656] 任务5
 2020-02-17 10:23:26.799051+0800 多线程-01(面试题)[52690:3651730] 任务2
 2020-02-17 10:23:26.799217+0800 多线程-01(面试题)[52690:3651730] 任务3
 2020-02-17 10:23:26.799353+0800 多线程-01(面试题)[52690:3651730] 任务4
 */
- (void)interView6 {
   NSLog(@"任务1");
   dispatch_queue_t queue = dispatch_queue_create("muQueue", DISPATCH_QUEUE_CONCURRENT);
   dispatch_async(queue, ^{
       NSLog(@"任务2");
       
       dispatch_sync(queue, ^{
           NSLog(@"任务3");
       });
       
       NSLog(@"任务4");
   });
   NSLog(@"任务5");
}

// 大于等于
/*
 因为是异步并发，所以可能一次循环任务还没完成(a++),就又开始了下次循环，由于任务没有完成即a没有执行++,所以开启的线程数可能大于或等于 5
 所以结果是 大于或者等于 5
 */
- (void)interView7 {
    __block int a = 0;
    while (a<5) {
        dispatch_async(dispatch_get_global_queue(0, 0), ^{
            NSLog(@"==========");
            a++;
        });
    }
    NSLog(@" == %d",a);  // 大于等于 5
}

// 会产生死锁
- (void)interview8 {
    // 死锁
    dispatch_sync(dispatch_get_main_queue(), ^{
        NSLog(@"======");
    });
}

@end
