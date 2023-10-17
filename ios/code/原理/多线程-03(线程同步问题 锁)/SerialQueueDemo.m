//
//  SerialQueueDemo.m
//  多线程-03(线程同步问题 锁)
//
//  Created by WTW on 2019/8/5.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "SerialQueueDemo.h"

@interface SerialQueueDemo ()

@property (nonatomic,strong) dispatch_queue_t ticketQueue;

@end

@implementation SerialQueueDemo

- (instancetype)init {
    if (self = [super init]) {
        self.ticketQueue = dispatch_queue_create("ticketQueue", DISPATCH_QUEUE_SERIAL);
    }
    return self;
}


-(void)__saleTicket {
    dispatch_sync(self.ticketQueue, ^{
        [super __saleTicket];
    });
}

@end
