//
//  NSLockDemo.m
//  多线程-03(线程同步问题 锁)
//
//  Created by WTW on 2019/8/4.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "NSLockDemo.h"

@interface NSLockDemo ()
@property (strong, nonatomic) NSLock *moneyLock;
@property (strong, nonatomic) NSLock *ticketLock;
@end

@implementation NSLockDemo

- (instancetype)init
{
    if (self = [super init]) {
        self.moneyLock = [[NSLock alloc] init];
        self.ticketLock = [[NSLock alloc] init];
    }
    return self;
}

- (void)__drawMoney
{
    [self.moneyLock lock];
    
    [super __drawMoney];
    
    [self.moneyLock unlock];
}

- (void)__saveMoney
{
     [self.moneyLock lock];
    
     [super __saveMoney];
    
     [self.moneyLock unlock];
}

- (void)__saleTicket
{
    [self.ticketLock lock];
    
    [super __saleTicket];
    
    [self.ticketLock unlock];
}

@end
