//
//  ViewController.m
//  多线程-GCD
//
//  Created by WTW on 2019/8/20.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

/*
 GCD 是 apple 为多核的并行计算提出的解决方案
 GCD 会自动利用更多的 CPU 内核 (比如双核 、四核)
 GCD 会自动管理线程的声明周期 (创建线程、线程调度、销毁线程)
 程序员只需要告诉GCD 想要执行的任务，不需要写任何的管理代码
 
 任务 和 队列：
    任务：执行什么操作
    队列：用来存放任务
 
 GCD 的使用步骤：
    1、定制任务
    2、将任务添加到队列中
 
 GCD 有 2个用来执行任务的常用函数
    // queue : 队列
    // block : 任务
    // 异步的方式执行任务
    dispatch_async(<#dispatch_queue_t  _Nonnull queue#>, <#^(void)block#>)
    // 同步的方式执行任务
    dispatch_sync(<#dispatch_queue_t  _Nonnull queue#>, <#^(void)block#>)
 
 同步和异步的区别：(区别：具不具备开启新线程的能力)
    同步：只能在当前线程中执行任务，不具备开启线程的能力
    异步：可以在新的线程中执行任务，具备开启新线程的能力
 
 队列的类型：(区别：任务的执行方式)
    并发队列：多个任务并发(同时)执行 (自动开启多个线程同时执行任务)，并发队列功能只有在 异步函数 下才有效
    串行队列：一个接一个执行(一个任务执行完毕后，再执行下一个任务)
    主队列: 一个特殊的串行队列
 */

@interface ViewController ()
@property (nonatomic,strong) NSArray *listArr;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
#pragma mark - 异步函数 + 并发队列
    // 会开启多条线程，同步执行
   
//    // 创建队列 并发队列
//    dispatch_queue_t concurrentQueue = dispatch_queue_create("concurrentQueue", DISPATCH_QUEUE_CONCURRENT);
    
      // 获取一个全局并发队列
//    //dispatch_queue_t queue = dispatch_get_global_queue(0, 0);
    
//    // 封装任务 添加任务到队列中
//    dispatch_async(concurrentQueue, ^{
//        NSLog(@" === 异步函数 + 并发队列 ==11==  %@",[NSThread currentThread]);
//    });
//    dispatch_async(concurrentQueue, ^{
//        NSLog(@" === 异步函数 + 并发队列 ==22==  %@",[NSThread currentThread]);
//    });
//    dispatch_async(concurrentQueue, ^{
//        NSLog(@" === 异步函数 + 并发队列 ==33==  %@",[NSThread currentThread]);
//    });
//
    /*
     === 异步函数 + 并发队列 ==33==  <NSThread: 0x600003471a00>{number = 3, name = (null)}
     === 异步函数 + 并发队列 ==22==  <NSThread: 0x600003449d80>{number = 7, name = (null)}
     === 异步函数 + 并发队列 ==11==  <NSThread: 0x60000347cf40>{number = 5, name = (null)}
     */
    
#pragma mark - 异步函数 + 串行队列
    // 会开线程，开一条线程，串行执行
    
//    dispatch_queue_t serialQueue = dispatch_queue_create("serialQueue", DISPATCH_QUEUE_SERIAL);
//    dispatch_async(serialQueue, ^{
//        NSLog(@" === 异步函数 + 串行队列 ==11==  %@",[NSThread currentThread]);
//    });
//    dispatch_async(serialQueue, ^{
//        NSLog(@" === 异步函数 + 串行队列 ==22==  %@",[NSThread currentThread]);
//    });
//    dispatch_async(serialQueue, ^{
//        NSLog(@" === 异步函数 + 串行队列 ==33==  %@",[NSThread currentThread]);
//    });
         
    /*
     === 异步函数 + 串行队列 ==11==  <NSThread: 0x600003963b80>{number = 5, name = (null)}
     === 异步函数 + 串行队列 ==22==  <NSThread: 0x600003963b80>{number = 5, name = (null)}
     === 异步函数 + 串行队列 ==33==  <NSThread: 0x600003963b80>{number = 5, name = (null)}
     */
    
#pragma mark - 同步函数 + 并发队列
    // 不会开线程，串行执行
    
//    dispatch_queue_t concurrentQueue = dispatch_queue_create("concurrentQueue", DISPATCH_QUEUE_CONCURRENT);
//    dispatch_sync(concurrentQueue, ^{
//        NSLog(@" === 同步函数 + 并发队列 ==11==  %@",[NSThread currentThread]);
//    });
//    dispatch_sync(concurrentQueue, ^{
//        NSLog(@" === 同步函数 + 并发队列 ==22==  %@",[NSThread currentThread]);
//    });
//    dispatch_sync(concurrentQueue, ^{
//        NSLog(@" === 同步函数 + 并发队列 ==33==  %@",[NSThread currentThread]);
//    });
    /*
     === 同步函数 + 并发队列 ==11==  <NSThread: 0x6000012b6d00>{number = 1, name = main}
     === 同步函数 + 并发队列 ==22==  <NSThread: 0x6000012b6d00>{number = 1, name = main}
     === 同步函数 + 并发队列 ==33==  <NSThread: 0x6000012b6d00>{number = 1, name = main}
     */
    
#pragma mark - 同步函数 + 串行队列
    // 不会开线程，串行执行
    
//    dispatch_queue_t serialQueue = dispatch_queue_create("serialQueue", DISPATCH_QUEUE_SERIAL);
//    dispatch_sync(serialQueue, ^{
//        NSLog(@" === 同步函数 + 串行队列 ==11==  %@",[NSThread currentThread]);
//    });
//    dispatch_sync(serialQueue, ^{
//        NSLog(@" === 同步函数 + 串行队列 ==22==  %@",[NSThread currentThread]);
//    });
//    dispatch_sync(serialQueue, ^{
//        NSLog(@" === 同步函数 + 串行队列 ==33==  %@",[NSThread currentThread]);
//    });
    
    /*
     === 同步函数 + 串行队列 ==11==  <NSThread: 0x6000015e4c00>{number = 1, name = main}
     === 同步函数 + 串行队列 ==22==  <NSThread: 0x6000015e4c00>{number = 1, name = main}
     === 同步函数 + 串行队列 ==33==  <NSThread: 0x6000015e4c00>{number = 1, name = main}
     */
    
#pragma mark - 主队列 + 同步/异步
    // 同步函数 + 主队列 ： 产生死锁 (自己创建的队列不会产生死锁)
    // 异步函数 + 主队列 ： 不会开线程，在主线程中执行
    
      //同步函数 + 主队列 ： 产生死锁
//    dispatch_queue_t queue = dispatch_get_main_queue();
//    dispatch_sync(queue, ^{
//        NSLog(@" ===  同步函数 + 主队列  ==11==  %@",[NSThread currentThread]);
//    });
//    dispatch_sync(queue, ^{
//        NSLog(@" ===  同步函数 + 主队列  ==22==  %@",[NSThread currentThread]);
//    });
//    dispatch_sync(queue, ^{
//        NSLog(@" ===  同步函数 + 主队列  ==33==  %@",[NSThread currentThread]);
//    });
    
       //异步函数 + 主队列
//        dispatch_queue_t queue = dispatch_get_main_queue();
//        dispatch_async(queue, ^{
//            NSLog(@" === 异步函数 + 主队列 列 ==11==  %@",[NSThread currentThread]);
//        });
//        dispatch_async(queue, ^{
//            NSLog(@" === 异步函数 + 主队列  ==22==  %@",[NSThread currentThread]);
//        });
//        dispatch_async(queue, ^{
//            NSLog(@" === 异步函数 + 主队列  ==33==  %@",[NSThread currentThread]);
//        });
    
#pragma mark - 并发队列 串行队列
        
    // 并发队列获取的两种方法：
    // 1、使用 dispatch_queue_create 函数创建队列：
    //<#const char * _Nullable label#> : 队列名称
    //<#dispatch_queue_attr_t  _Nullable attr#> 队列的类型
//    dispatch_queue_t concurrentQueue = dispatch_queue_create("concurrentQueue", DISPATCH_QUEUE_CONCURRENT);

    // 2、获取全局并发队列
    //<#long identifier#> 队列的优先级
    //<#unsigned long flags#> 参数暂时无用，给 0 即可
//    dispatch_queue_t  queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);

     // 串行队列获取的两种方法
     // 1、使用 dispatch_queue_create 函数创建队列：
//    dispatch_queue_t serialQueue = dispatch_queue_create("serialQueue", DISPATCH_QUEUE_SERIAL);
     
     // 2、使用主队列
//    dispatch_queue_t  queue = dispatch_get_main_queue()

    
#pragma mark - GCD 线程间通信
    
//    dispatch_async(dispatch_get_global_queue(0, 0), ^{
//        dispatch_async(dispatch_get_main_queue(), ^{
//           // 更新UI
//        });
//    });
    
#pragma mark - 常用函数
    
    // 延时执行
//    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//
//    });
    
    //一次性代码
//    static dispatch_once_t onceToken;
//    dispatch_once(&onceToken, ^{
//
//    });
    
#pragma mark - 栅栏函数 (必须是自己创建的并发队列)
    
    // 栅栏函数不能使用全局获取的并发队列，必须使用自己创建的并发队列
    
    // 示例1：
    
//    dispatch_queue_t queue = dispatch_get_global_queue(0, 0);  // 不行，必须是自己创建的全局并发队列
//    dispatch_queue_t queue = dispatch_queue_create("concurrentQueue", DISPATCH_QUEUE_CONCURRENT);
//
//    dispatch_async(queue, ^{
//        NSLog(@" ==11==  %@",[NSThread currentThread]);
//        for (int i = 0; i < 10; i ++) {
//           NSLog(@" ==%d==  %@",i,[NSThread currentThread]);
//        }
//    });
//    dispatch_async(queue, ^{
//        NSLog(@" ==22==  %@",[NSThread currentThread]);
//    });
//    dispatch_barrier_async(queue, ^{
//        NSLog(@" ==栅栏函数 ==  %@",[NSThread currentThread]);
//    });
//    dispatch_async(queue, ^{
//        NSLog(@" ==33==  %@",[NSThread currentThread]);
//    });
//
    /*
       ==11==  <NSThread: 0x600000acf640>{number = 7, name = (null)}
       ==22==  <NSThread: 0x600000ac83c0>{number = 6, name = (null)}
       ==栅栏函数 ==  <NSThread: 0x600000af0bc0>{number = 5, name = (null)}
       ==33==  <NSThread: 0x600000acf640>{number = 7, name = (null)}
     */
    
    
    // 示例 2:
//    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_TARGET_QUEUE_DEFAULT, 0);
//    dispatch_async(queue, ^{NSLog(@"0读取数据"); });
//    dispatch_async(queue, ^{NSLog(@"1读取数据"); });
//    dispatch_async(queue, ^{NSLog(@"2读取数据"); });
//    dispatch_async(queue, ^{NSLog(@"3读取数据"); });
//    dispatch_barrier_async(queue, ^{NSLog(@"写入数据");});
//    dispatch_async(queue, ^{NSLog(@"4读取数据"); });
//    dispatch_async(queue, ^{NSLog(@"5读取数据"); });
//    dispatch_async(queue, ^{NSLog(@"6读取数据"); });
//    dispatch_async(queue, ^{NSLog(@"7读取数据"); });
    
    /*
     2020-02-06 01:52:29.595585+0800 多线程-GCD[10170:678939] 2读取数据
     2020-02-06 01:52:29.595790+0800 多线程-GCD[10170:678946] 3读取数据
     2020-02-06 01:52:29.595609+0800 多线程-GCD[10170:678945] 0读取数据
     2020-02-06 01:52:29.595625+0800 多线程-GCD[10170:678940] 1读取数据
     2020-02-06 01:52:29.595819+0800 多线程-GCD[10170:678939] 写入数据
     2020-02-06 01:52:29.595921+0800 多线程-GCD[10170:678946] 4读取数据
     2020-02-06 01:52:29.595983+0800 多线程-GCD[10170:678940] 5读取数据
     2020-02-06 01:52:29.595993+0800 多线程-GCD[10170:678939] 6读取数据
     2020-02-06 01:52:29.596017+0800 多线程-GCD[10170:678945] 7读取数据
     */
    
#pragma mark - 快速迭代
    
    // 同步执行
//    for (int i = 0; i < 10; i ++) {
//         NSLog(@" ==%d==  %@",i,[NSThread currentThread]);
//    }
    /*
     ==0==  <NSThread: 0x6000001ce0c0>{number = 1, name = main}
     ==1==  <NSThread: 0x6000001ce0c0>{number = 1, name = main}
     ==2==  <NSThread: 0x6000001ce0c0>{number = 1, name = main}
     ==3==  <NSThread: 0x6000001ce0c0>{number = 1, name = main}
     ==4==  <NSThread: 0x6000001ce0c0>{number = 1, name = main}
     ==5==  <NSThread: 0x6000001ce0c0>{number = 1, name = main}
     ==6==  <NSThread: 0x6000001ce0c0>{number = 1, name = main}
     ==7==  <NSThread: 0x6000001ce0c0>{number = 1, name = main}
     ==8==  <NSThread: 0x6000001ce0c0>{number = 1, name = main}
     ==9==  <NSThread: 0x6000001ce0c0>{number = 1, name = main}
     */
    
    
    // 示例1：
    // dispatch_apply ：开子线程和主线程一起完成遍历任务，任务的执行是并发的, 比for循环执行的更快
    //  <#size_t iterations#> 要遍历的次数
    //  <#dispatch_queue_t  _Nullable queue#> 队列(只能传并发队列)
    // <#^(size_t)block#> 索引
//    dispatch_apply(10, dispatch_get_global_queue(0, 0), ^(size_t index) {
//        NSLog(@" ==dispatch_apply == %d==  %@",index,[NSThread currentThread]);
//    });
    
    /*
     ==dispatch_apply == 0==  <NSThread: 0x6000001ce0c0>{number = 1, name = main}
     ==dispatch_apply == 1==  <NSThread: 0x600000195300>{number = 4, name = (null)}
     ==dispatch_apply == 2==  <NSThread: 0x600000191240>{number = 6, name = (null)}
     ==dispatch_apply == 3==  <NSThread: 0x6000001ce0c0>{number = 1, name = main}
     ==dispatch_apply == 4==  <NSThread: 0x6000001ae
     ==dispatch_apply == 6==  <NSThread: 0x6000001ce0c0>{number = 1, name = main}
     ==dispatch_apply == 5==  <NSThread: 0x600000195300>{number = 4, name = (null)}
     ==dispatch_apply == 7==  <NSThread: 0x600000191240>{number = 6, name = (null)}
     ==dispatch_apply == 9==  <NSThread: 0x600000191240>{number = 6, name = (null)}
     ==dispatch_apply == 8==  <NSThread: 0x600000195300>{number = 4, name = (null)}
     */
    
    
    // 示例 2 :
//    NSArray *array = @[@1,@2,@3,@4,@5];
//    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_TARGET_QUEUE_DEFAULT, 0);
//    //在 Global Dispatch Queue 中异步执行
//    dispatch_async(queue, ^{
//        //Global Dispatch Queue 等待 dispatch_apply 函数中全部处理执行结束
//        dispatch_apply([array count], queue, ^(size_t index) {
//            //并行处理包含在array 对象的全部对象
//            NSLog(@"index %zu : %@",index,[array objectAtIndex:index]);
//        });
//        // dispatch_apply 函数中的处理全部执行结束
//        // 在 Main Dispatch Queue 中非同步执行
//        dispatch_async(dispatch_get_main_queue(), ^{
//            //在 Main Dispatch Queue 中执行处理用户界面更新
//            NSLog(@"done");
//        });
//    });
    
    /*
     2020-02-06 01:54:52.202205+0800 多线程-GCD[10188:680499] index 0 : 1
     2020-02-06 01:54:52.202239+0800 多线程-GCD[10188:680497] index 1 : 2
     2020-02-06 01:54:52.202322+0800 多线程-GCD[10188:680502] index 2 : 3
     2020-02-06 01:54:52.202479+0800 多线程-GCD[10188:680497] index 4 : 5
     2020-02-06 01:54:52.202384+0800 多线程-GCD[10188:680499] index 3 : 4
     2020-02-06 01:54:52.233919+0800 多线程-GCD[10188:680420] done
     */
    
#pragma mark - 队列组
    
    // 写法1：
//    dispatch_group_t group = dispatch_group_create();
//    dispatch_queue_t  queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
//
//    dispatch_group_async(group, queue, ^{
//        NSLog(@"1");
//    });
//    dispatch_group_async(group, queue, ^{
//        NSLog(@"2");
//    });
//    dispatch_group_async(group, queue, ^{
//        NSLog(@"3");
//    });
//    // 所有的任务都完成后走这个方法
//    dispatch_group_notify(group, queue, ^{
//        NSLog(@"执行完了");
//    });
    
    /*
     2020-02-06 02:00:14.263733+0800 多线程-GCD[10237:684075] 2
     2020-02-06 02:00:14.263739+0800 多线程-GCD[10237:684073] 3
     2020-02-06 02:00:14.263757+0800 多线程-GCD[10237:684076] 1
     2020-02-06 02:00:14.263970+0800 多线程-GCD[10237:684076] 执行完了
     */
    
    // 写法2：
    // dispatch_group_enter dispatch_group_leave 必须配对使用 (对于异步的网络请求一般使用这个)
    // 创建队列
//    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
//    // 创建队列组
//    dispatch_group_t group = dispatch_group_create();
//
//    // 在该方法后面的异步任务都被纳入到队列组的监听范围
//    dispatch_group_enter(group);
//    dispatch_async(queue, ^{
//        NSLog(@" == 1 ==  %@",[NSThread currentThread]);
//        dispatch_group_leave(group);
//    });
//    dispatch_group_enter(group);
//    dispatch_async(queue, ^{
//        NSLog(@" == 2 ==  %@",[NSThread currentThread]);
//        dispatch_group_leave(group);
//    });
//    dispatch_group_enter(group);
//    dispatch_async(queue, ^{
//        NSLog(@" == 3 ==  %@",[NSThread currentThread]);
//        dispatch_group_leave(group);
//    });
//    // 不是阻塞，内部是异步执行的
//    dispatch_group_notify(group, queue, ^{
//        NSLog(@"执行完了");
//    });
    
    /*
     == 3 ==  <NSThread: 0x600003ec4480>{number = 5, name = (null)}
     == 2 ==  <NSThread: 0x600003ecc540>{number = 4, name = (null)}
     == 1 ==  <NSThread: 0x600003ecf0c0>{number = 7, name = (null)}
     执行完了
     */
    
    
    // 写法3:
//    dispatch_queue_t  queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
//    dispatch_group_t group = dispatch_group_create();
//
//    dispatch_group_async(group, queue, ^{
//        NSLog(@"== 1 == %@",[NSThread currentThread]);
//    });
//    dispatch_group_async(group, queue, ^{
//        NSLog(@"== 2 == %@",[NSThread currentThread]);
//    });
//    dispatch_group_async(group, queue, ^{
//        NSLog(@"== 3 == %@",[NSThread currentThread]);
//    });
//    // DISPATCH_TIME_FOREVER 等待，死等，直到对队列组中所有的任务都执行完毕之后才执行
//    // 此方法是阻塞的，如果执行不完成下面的方法不会执行
//    dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
//    NSLog(@"执行完了");
    
    /*
     == 3 == <NSThread: 0x600003acc240>{number = 3, name = (null)}
     == 2 == <NSThread: 0x600003acc740>{number = 5, name = (null)}
     == 1 == <NSThread: 0x600003ac1200>{number = 4, name = (null)}
     执行完了
     */
    
    // 写法 3.1
//    dispatch_time_t time = dispatch_time(DISPATCH_TIME_NOW, 2ull*NSEC_PER_SEC);
//    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
//    dispatch_group_t group = dispatch_group_create();
//
//    dispatch_group_async(group, queue, ^{
//        NSLog(@"1");
//    });
//    dispatch_group_async(group, queue, ^{
//        [NSThread sleepForTimeInterval:3];
//        NSLog(@"2");
//    });
//    dispatch_group_async(group, queue, ^{
//        NSLog(@"3");
//    });
//    long result = dispatch_group_wait(group, time);
//    if (result == 0) {
//        //属于Dispatch Group 的全部处理执行结束
//        NSLog(@"执行完了");
//    }else {
//        //属于Dispatch Group 的某一个处理还在执行中
//        NSLog(@"没执行完呢");
//    }
    /*
     2020-02-06 02:01:50.840621+0800 多线程-GCD[10259:685462] 3
     2020-02-06 02:01:50.840622+0800 多线程-GCD[10259:685460] 1
     2020-02-06 02:01:52.841573+0800 多线程-GCD[10259:685372] 没执行完呢
     2020-02-06 02:01:53.847624+0800 多线程-GCD[10259:685458] 2
     */
  
#pragma mark -  dispatch_suspend dispatch_resume
    
    // 对已经执行的处理没有影响，挂起后，追加到 Dispatch Queue 中但是尚未执行的处理在此后就会停止执行
    // 而恢复则继续执行
    
    // 挂起指定的 Dispatch Queue
//    dispatch_suspend(queue)
    //恢复指定的 Dispatch Queue
//    dispatch_resume(queue)
    
#pragma mark - dispatch_set_target_queue
 
    // dispatch_set_target_queue 变更队列的执行优先级
    // 第一个参数指定要变更执行优先级的 Dsiapacth Queue
    // 第一个参数不能指定系统提供的 Main Dispath Queue 和 Global Dispatch Queue
    // 第二个参数指定与要使用的执行优先级相同优先级的 Global Dispatch Queue
//    dispatch_set_target_queue(<#dispatch_object_t  _Nonnull object#>, <#dispatch_queue_t  _Nullable queue#>)
   
    // dispatch_set_target_queue 还可以作为 Dispatch Queue 的执行阶层
    // 在多个 Serial Dispatch Queue 用 dispatch_set_target_queue 指定为某一个  Serial Dispatch Queue 那么原先本应该并行执行的多个
    // Serial Dispatch Queue 在目标 Serial Dispatch Queue 上只能同时执行一个处理
//    dispatch_queue_t targetQueue = dispatch_queue_create("test.target.queue", DISPATCH_QUEUE_SERIAL);
//
//    dispatch_queue_t queue1 = dispatch_queue_create("test.1", DISPATCH_QUEUE_SERIAL);
//    dispatch_queue_t queue2 = dispatch_queue_create("test.2", DISPATCH_QUEUE_SERIAL);
//    dispatch_queue_t queue3 = dispatch_queue_create("test.3", DISPATCH_QUEUE_SERIAL);
//
//    dispatch_set_target_queue(queue1, targetQueue);
//    dispatch_set_target_queue(queue2, targetQueue);
//    dispatch_set_target_queue(queue3, targetQueue);
//
//    dispatch_async(queue1, ^{
//        NSLog(@"1 in");
//        [NSThread sleepForTimeInterval:3.f];
//        NSLog(@"1 out");
//    });
//    dispatch_async(queue2, ^{
//        NSLog(@"2 in");
//        [NSThread sleepForTimeInterval:3.f];
//        NSLog(@"2 out");
//    });
//    dispatch_async(queue3, ^{
//        NSLog(@"3 in");
//        [NSThread sleepForTimeInterval:3.f];
//        NSLog(@"3 out");
//    });
    
    /*
     2020-02-06 02:18:32.002512+0800 多线程-GCD[10441:697979] 1 in
     2020-02-06 02:18:35.006028+0800 多线程-GCD[10441:697979] 1 out
     2020-02-06 02:18:35.006347+0800 多线程-GCD[10441:697979] 2 in
     2020-02-06 02:18:38.009656+0800 多线程-GCD[10441:697979] 2 out
     2020-02-06 02:18:38.009975+0800 多线程-GCD[10441:697979] 3 in
     2020-02-06 02:18:41.015102+0800 多线程-GCD[10441:697979] 3 out
     */
   
# pragma mark - dispatch_queue_set_specific 和 dispatch_get_specific
    
    /*
     dispatch_queue_set_specific 用于给一个队列设置相关的上下文数据
     dispatch_get_specific 用于获取队列相关的上下文数据,获取的是当前执行队列的相关数据，而不仅仅与 key 对应这一个条件
     */
    
//    static void *queueKey1 = "queueKey1";
//
//    dispatch_queue_t queue1 = dispatch_queue_create(queueKey1, DISPATCH_QUEUE_SERIAL);
//
//    NSLog(@"1. 当前线程是: %@, 当前队列是: %@ 。",[NSThread currentThread],dispatch_get_current_queue());
//
//    if (dispatch_get_specific(queueKey1)) {
//        // 当前队列是主队列，不是queue1队列，所以取不到queueKey1对应的值，故而不执行
//        NSLog(@"2. 当前线程是: %@, 当前队列是: %@ 。",[NSThread currentThread],dispatch_get_current_queue());
//        [NSThread sleepForTimeInterval:1];
//    }else{
//        NSLog(@"3. 当前线程是: %@, 当前队列是: %@ 。",[NSThread currentThread],dispatch_get_current_queue());
//        [NSThread sleepForTimeInterval:1];
//    }
//
//    dispatch_sync(queue1, ^{
//        NSLog(@"4. 当前线程是: %@, 当前队列是: %@ 。",[NSThread currentThread],dispatch_get_current_queue());
//        [NSThread sleepForTimeInterval:1];
//
//        if (dispatch_get_specific(queueKey1)) {
//             //当前队列是queue1队列，所以能取到queueKey1对应的值，故而执行
//            NSLog(@"5. 当前线程是: %@, 当前队列是: %@ 。",[NSThread currentThread],dispatch_get_current_queue());
//            [NSThread sleepForTimeInterval:1];
//        }else{
//            NSLog(@"6. 当前线程是: %@, 当前队列是: %@ 。",[NSThread currentThread],dispatch_get_current_queue());
//            [NSThread sleepForTimeInterval:1];
//        }
//    });
//
//    dispatch_async(queue1, ^{
//        NSLog(@"7. t当前线程是: %@, 当前队列是: %@ 。",[NSThread currentThread],dispatch_get_current_queue());
//        [NSThread sleepForTimeInterval:1];
//    });
//
//    [NSThread sleepForTimeInterval:5];
    
  
    
    
#pragma mark - Dispatch Semaphore
    
    // 内存错误导致程序意外退出
//    dispatch_queue_t queue = dispatch_get_global_queue(0, 0);
//    NSMutableArray *array = [[NSMutableArray alloc] init];
//    for (int i = 0; i < 100000; i ++) {
//        dispatch_async(queue, ^{
//            [array addObject:[NSNumber numberWithInt:i]];
//        });
//    }

    //Dispatch Semaphore 优化 解决
    /*
     Dispatch Semaphore 是持有计数的信号，计数为 0 时等待，计数为 1或大于1 时，减去 1 而不等待
     
     // 生成信号量 Dispatch Semaphore  以初始化为1为例
     dispatch_semaphore_t semaphore = dispatch_semaphore_create(1);
    
     // dispatch_semaphore_wait 等待计数值达到大于或等于1，当计数值大于或等于1时，对该计数进行减去并从 dispatch_semaphore_wait 函数返回
     dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
     
     // 通过 dispatch_semaphore_signal 将 Dispatch Semaphore 的计数值加 1
     dispatch_semaphore_signal(semaphore)
     */
    
    
    
//        dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
//        //生成 Dispatch Semaphore
//        //Dispatch Semaphore 的计数初始值设定为 1
//        //保证可访问 NSMutableArray 类对象的线程同时只能有1个
//        dispatch_semaphore_t semaphore = dispatch_semaphore_create(1);
//        NSMutableArray *array = [[NSMutableArray alloc] init];
//        for (int i = 0; i < 10000; ++i) {
//            dispatch_async(queue, ^{
//                //等待 Dispatch Semaphore一直等待，直到 Dispatch Semaphore 的技术值达到大于等于 1。
//                dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
//                //由于 Dispatch Semaphore 的技术值达到大于等于 1
//               //所以将 Dispatch Semaphore 的计数值减去 1
//               //dispatch_semaphore_wait 函数执行返回
//               //即执行到此时的 Dispatch Semaphore 的计数值恒为0
//               //由于可访问 NSMutableArray 类对象的线程 只有 1个 ，因此可以安全地进行更新
//                [array addObject:[NSNumber numberWithInteger:i]];
//                // 排他控制处理结束，所以通过 dispatch_semaphore_signal 函数将 Dispatch Semaphore 的计数值加1.
//                //如果有通过 dispatch_semaphore_wait 函数等待 Dispatch Semaphore 的计数值增加的线程，就由最先等待的线程执行。
//                dispatch_semaphore_signal(semaphore);
//            });
//        }
    
    
    
    
    
    
    //    static int initialized = NO;
    //    if (initialized == NO) {
    //        //初始化
    //        initialized = YES;
    //    }
    
    //    static dispatch_once_t pred;
    //    dispatch_once(&pred, ^{
    //        //初始化
    //    });
    
    //NSHashTable;
    //    NSMapTable
    //NSPointerArray
//    NSDictionary *dict = [NSDictionary dictionaryWithObject:@"2" forKey:@"3"];
//    NSLog(@"%@ == %ld",dict,[dict hash]);
    
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (NSArray *)listArr {
    if (!_listArr) {
        _listArr = [NSArray arrayWithObjects:@1,@3,@4,@5,@6, nil];
    }
    return _listArr;
}


@end
