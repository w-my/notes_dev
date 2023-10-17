//
//  ViewController.m
//  多线程-03(线程同步问题 锁)
//
//  Created by WTW on 2019/7/31.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"
#import "OSSpinLockDemo.h"
#import "OSUnfairLockDemo.h"
#import "PthreadMutexDemo.h"
#import "PthreadMutexDemo2.h"
#import "PthreadMutexDemo3.h"
#import "NSLockDemo.h"
#import "NSConditionDemo.h"
#import "NSConditionLockDemo.h"
#import "SerialQueueDemo.h"
#import "SemaphoreDemo.h"
#import "SynchronizedDemo.h"

/*
 性能从高到低：
 os_unfair_lock  (不公平的 iOS10开始推荐使用，10以前版本不支持)
 OSSpinLock   (spin 旋转 不推荐使用)
 dispatch_semaphore              (推荐使用)
 pthread_mutex  (mutex 互斥)      (推荐使用)
 dispatch_queue(DISPATCH_QUEUE_SERIAL)
 NSLock
 NSCondition  (Condition 条件)
 pthread_mutex(recursive)
 NSRecursiveLock
 NSConditionLock
 @synchronized
 
 // NSOperationQueue 也可以控制最大并发为1 实现线程同步
 NSOperationQueue *queue = [[NSOperationQueue alloc] init];
 queue.maxConcurrentOperationCount = 1;
 */

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // OSSpinkLock (自旋锁) 已经不安全，不推荐使用
//    BaseDemo *demo = [[OSSpinLockDemo alloc] init];
//    [demo moneyTest];

    // OS_unfair_Lock (互斥锁)
//    BaseDemo *demo = [[OSUnfairLockDemo alloc] init];
//    [demo moneyTest];
    
     // Pthread_Mutex (互斥锁)
//    BaseDemo *demo = [[PthreadMutexDemo alloc] init];
//    [demo moneyTest];
    
    // Pthread_Mutex 条件锁 (线程依赖)
//    BaseDemo *demo = [[PthreadMutexDemo2 alloc] init];
//    [demo otherTest];
    
    // Pthread_Mutex 递归锁
//    BaseDemo *demo = [[PthreadMutexDemo3 alloc] init];
//    [demo otherTest];
    
    // NSLock (对 Pthread_Mutex 普通锁的封装)
    // NSRecursiveLock (和 NSLock API 相同，对 Pthread_Mutex 递归锁的封装)
//    BaseDemo *demo = [[NSLockDemo alloc] init];
//    [demo moneyTest];
    
    // NSCondition (对 Pthread_Mutex 和 cond条件的封装)
//    BaseDemo *demo = [[NSConditionDemo alloc] init];
//    [demo otherTest];
    
    // NSConditionLock (对 NSCondition 的进一步封装)
//    BaseDemo *demo = [[NSConditionLockDemo alloc] init];
//    [demo otherTest];
   
    // SerialQueue (sync 串行队列实现)
//    BaseDemo *demo = [[SerialQueueDemo alloc] init];
//    [demo ticketTest];

    // Semaphore
//    BaseDemo *demo = [[SemaphoreDemo alloc] init];
//    [demo otherTest];
//    [demo ticketTest];
    
    // synchronized (对mutex递归锁的封装)
    BaseDemo *demo = [[SynchronizedDemo alloc] init];
    [demo ticketTest];
    [demo moneyTest];
    
}


@end
