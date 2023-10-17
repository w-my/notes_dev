//
//  PthreadMutexDemo.m
//  多线程-03(线程同步问题 锁)
//
//  Created by WTW on 2019/7/31.
//  Copyright © 2019 wtw. All rights reserved.
//

/*
 mutex叫做”互斥锁”，等待锁的线程会处于休眠状态
 需要导入头文件#import <pthread.h>
 
 Mutex type attributes :
 #define PTHREAD_MUTEX_NORMAL        0
 #define PTHREAD_MUTEX_ERRORCHECK    1
 #define PTHREAD_MUTEX_RECURSIVE        2
 #define PTHREAD_MUTEX_DEFAULT        PTHREAD_MUTEX_NORMAL
 */

#import "PthreadMutexDemo.h"
#import <pthread.h>

@interface PthreadMutexDemo ()
@property (assign, nonatomic) pthread_mutex_t moneyLock;
@property (assign, nonatomic) pthread_mutex_t ticketLock;
@end

@implementation PthreadMutexDemo

- (void)__initMutex:(pthread_mutex_t *)mutex {
    
    // 第一种方式
//    //初始化锁属性
//    pthread_mutexattr_t attr;
//    pthread_mutexattr_init(&attr);
//    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_NORMAL);
//    //初始化锁
//    pthread_mutex_init(mutex,&attr);
//    //销毁相关资源
//    pthread_mutexattr_destroy(&attr);
    
    // 第二种方式
    pthread_mutex_init(mutex,NULL);
}

- (instancetype)init {
    if (self = [super init]) {
        [self __initMutex:&_moneyLock];
        [self __initMutex:&_ticketLock];
    }
    return self;
}

- (void)__saleTicket {
    
    pthread_mutex_lock(&_ticketLock);
    
    [super __saleTicket];
    
    pthread_mutex_unlock(&_ticketLock);
}

- (void)__saveMoney {
    
    pthread_mutex_lock(&_moneyLock);
    
    [super __saveMoney];

    pthread_mutex_unlock(&_moneyLock);
}

- (void)__drawMoney {
    
    pthread_mutex_lock(&_moneyLock);
    
    [super __drawMoney];
 
    pthread_mutex_unlock(&_moneyLock);
}

- (void)dealloc {
    pthread_mutex_destroy(&_ticketLock);
    pthread_mutex_destroy(&_moneyLock);
}

@end
