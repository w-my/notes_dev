//
//  OSSpinLockDemo.m
//  多线程-03(线程同步问题 锁)
//
//  Created by WTW on 2019/7/31.
//  Copyright © 2019 wtw. All rights reserved.
//

/*
 OSSpinLock叫做”自旋锁”，等待锁的线程会处于忙等（busy-wait）状态，一直占用着CPU资源
 目前已经不再安全，可能会出现优先级反转问题
 如果等待锁的线程优先级较高，它会一直占用着CPU资源，优先级低的线程就无法释放锁
 需要导入头文件#import <libkern/OSAtomic.h>
 */

#import "OSSpinLockDemo.h"
#import <libkern/OSAtomic.h>

@interface OSSpinLockDemo()
@property (assign, nonatomic) OSSpinLock moneyLock;
@property (assign, nonatomic) OSSpinLock ticketLock;
@end

@implementation OSSpinLockDemo

- (instancetype)init
{
    if (self = [super init]) {
        self.moneyLock = OS_SPINLOCK_INIT;
        self.ticketLock = OS_SPINLOCK_INIT;
    }
    return self;
}

- (void)__drawMoney
{
   OSSpinLockLock(&_moneyLock);
    
    [super __drawMoney];
    
    OSSpinLockUnlock(&_moneyLock);
}

- (void)__saveMoney
{
    OSSpinLockLock(&_moneyLock);
    
    [super __saveMoney];
    
    OSSpinLockUnlock(&_moneyLock);
}

- (void)__saleTicket
{
    OSSpinLockLock(&_ticketLock);
    
    [super __saleTicket];
    
    OSSpinLockUnlock(&_ticketLock);
}

@end
