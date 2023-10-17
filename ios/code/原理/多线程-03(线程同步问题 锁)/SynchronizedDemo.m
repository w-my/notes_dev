//
//  SynchronizedDemo.m
//  多线程-03(线程同步问题 锁)
//
//  Created by WTW on 2020/2/17.
//  Copyright © 2020 wtw. All rights reserved.
//

// @synchronized 苹果官方不推荐使用
// @synchronized是对mutex递归锁的封装


#import "SynchronizedDemo.h"

@implementation SynchronizedDemo

- (void)__drawMoney {
    @synchronized(self){
        [super __drawMoney];
    }
}

-(void)__saveMoney {
    @synchronized(self){
        [super __saveMoney];
    }
}

- (void)__saleTicket {
    
    static NSObject *lock;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        lock = [[NSObject alloc] init];
    });
    @synchronized(lock) {
        [super __saleTicket];
    }
}

@end
