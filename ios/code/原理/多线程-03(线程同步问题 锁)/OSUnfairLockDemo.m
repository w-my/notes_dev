//
//  OSUnfairLockDemo.m
//  多线程-03(线程同步问题 锁)
//
//  Created by WTW on 2019/7/31.
//  Copyright © 2019 wtw. All rights reserved.
//

/*
 os_unfair_lock用于取代不安全的 OSSpinLock ，从iOS10开始才支持
 从底层调用看，等待os_unfair_lock锁的线程会处于 休眠状态，并非忙等
 需要导入头文件 #import <os/lock.h>
 */

#import "OSUnfairLockDemo.h"
#import <os/lock.h>

@interface OSUnfairLockDemo ()
@property (assign, nonatomic) os_unfair_lock moneyLock;
@property (assign, nonatomic) os_unfair_lock ticketLock;
@end

@implementation OSUnfairLockDemo

- (instancetype)init {
    if (self = [super init]) {
        self.moneyLock = OS_UNFAIR_LOCK_INIT;
        self.ticketLock = OS_UNFAIR_LOCK_INIT;
    }
    return self;
}


//如果 只加锁 未解锁就会造成死锁
- (void)__saleTicket {
    os_unfair_lock_lock(&_ticketLock);
    [super __saleTicket];
    os_unfair_lock_unlock(&_ticketLock);
}

- (void)__saveMoney {
    os_unfair_lock_lock(&_moneyLock);
    [super __saveMoney];
    os_unfair_lock_unlock(&_moneyLock);
}

- (void)__drawMoney {
    os_unfair_lock_lock(&_moneyLock);
    [super __drawMoney];
    os_unfair_lock_unlock(&_moneyLock);
}

@end
