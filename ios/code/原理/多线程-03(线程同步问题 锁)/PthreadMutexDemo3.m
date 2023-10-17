//
//  PthreadMutexDemo3.m
//  多线程-03(线程同步问题 锁)
//
//  Created by WTW on 2019/8/5.
//  Copyright © 2019 wtw. All rights reserved.

// 汇编单步跟 使用指令 si

// 递归锁

#import "PthreadMutexDemo3.h"
#import <pthread.h>

@interface PthreadMutexDemo3 ()

@property (nonatomic,assign) pthread_mutex_t mutex;

@end

@implementation PthreadMutexDemo3

- (void)__initMutex:(pthread_mutex_t *)mutex {
    
    //递归锁：允许同一个线程对一把锁进行重复加锁
    
    //初始化锁属性
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);  //递归锁 PTHREAD_MUTEX_RECURSIVE 
    //初始化锁
    pthread_mutex_init(mutex,&attr);
    //销毁相关资源
    pthread_mutexattr_destroy(&attr);
}

- (instancetype)init {
    if (self = [super init]) {
        [self __initMutex:&_mutex];
    }
    return self;
}

- (void) otherTest {
    pthread_mutex_lock(&_mutex);
    NSLog(@"%s",__func__);
    
    static int count = 0;
    if (count < 10) {
        count ++;
        [self otherTest];
    }
    pthread_mutex_unlock(&_mutex);
}

- (void) otherTest2 {
    pthread_mutex_lock(&_mutex);
    NSLog(@"%s",__func__);
    pthread_mutex_unlock(&_mutex);
}

- (void)dealloc {
    pthread_mutex_destroy(&_mutex);
}

@end
