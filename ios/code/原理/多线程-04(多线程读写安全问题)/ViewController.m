//
//  ViewController.m
//  多线程-04(多线程读写安全问题)
//
//  Created by WTW on 2019/8/6.
//  Copyright © 2019 wtw. All rights reserved.
//
/*
 同一时间，只能有1个线程进行写的操作
 同一时间，允许有多个线程进行读的操作
 同一时间，不允许既有写的操作，又有读的操作

 就是典型的“多读单写”，经常用于文件等数据的读写操作，iOS中的实现方案有
 pthread_rwlock：读写锁
 dispatch_barrier_async：异步栅栏调用
 */

#import "ViewController.h"
#import <pthread.h>

@interface ViewController ()
//等待锁的进行随眠
@property (nonatomic,assign) pthread_rwlock_t lock;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    //初始化锁
    pthread_rwlock_t lock;
    pthread_rwlock_init(&_lock, NULL);
    //读加锁
    pthread_rwlock_rdlock(&lock);
    //读尝试加锁
    pthread_rwlock_tryrdlock(&lock);
    //写加锁
    pthread_rwlock_wrlock(&lock);
    //写尝试加锁
    pthread_rwlock_trywrlock(&lock);
    //解锁
    pthread_rwlock_unlock(&lock);
    //销毁
//    pthread_rwlock_destroy(&lock);
    
    for (int i = 0; i < 10 ; i ++) {
        dispatch_async(dispatch_get_global_queue(0, 0), ^{
            [self read];
        });
        dispatch_async(dispatch_get_global_queue(0, 0), ^{
            [self write];
        });
    }
}

// 读可以并发 (多读单写)
- (void)read {
    
    pthread_rwlock_rdlock(&_lock);
    
    sleep(1);
    
    NSLog(@"%s",__func__);
    
    pthread_rwlock_unlock(&_lock);
    
}

// 写只能写一个
- (void)write {
    
    pthread_rwlock_wrlock(&_lock);
    
    sleep(1);
    
    NSLog(@"%s",__func__);
    
    pthread_rwlock_unlock(&_lock);
    
}

- (void)dealloc {
    pthread_rwlock_destroy(&_lock);
}

@end
