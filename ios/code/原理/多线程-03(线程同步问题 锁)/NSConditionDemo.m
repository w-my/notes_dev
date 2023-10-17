//
//  NSConditionDemo.m
//  多线程-03(线程同步问题 锁)
//
//  Created by WTW on 2019/8/4.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "NSConditionDemo.h"

@interface NSConditionDemo ()
@property (strong,nonatomic) NSCondition *condt;
@property (nonatomic,strong) NSMutableArray *data;
@end

@implementation NSConditionDemo

- (instancetype)init {
    if (self = [super init]) {
        self.condt  = [[NSCondition alloc] init];
        self.data = [NSMutableArray array];
    }
    return self;
}

- (void)otherTest {
    
    [[[NSThread alloc] initWithTarget:self selector:@selector(__remove) object:nil] start];
    sleep(1);
    [[[NSThread alloc] initWithTarget:self selector:@selector(__add) object:nil] start];
    
}

//删除数组中的元素
- (void)__remove {
    
    [self.condt lock];
    
    if (self.data.count == 0) {
        //等待 等待的同时会把锁放开
        [self.condt wait];
    }
    
    [self.data removeLastObject];
    NSLog(@"删除元素");
    
    [self.condt unlock];
}

//往数组中添加元素
- (void)__add {
    
    [self.condt lock];
    
    [self.data addObject:@"Test"];
    NSLog(@"添加元素");
    
    //唤醒等待线程
    [self.condt signal];
    //广播 唤醒所有等待条件的线程
//    [self.condt broadcast]
    
    [self.condt unlock];
    
}

@end
