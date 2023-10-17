//
//  NSConditionLockDemo.m
//  多线程-03(线程同步问题 锁)
//
//  Created by WTW on 2019/8/5.
//  Copyright © 2019 wtw. All rights reserved.
// 可以实现线程依赖 顺序执行

#import "NSConditionLockDemo.h"

@interface NSConditionLockDemo ()
@property (strong,nonatomic) NSConditionLock *conditionLock;
@end

@implementation NSConditionLockDemo
- (instancetype)init {
    if (self = [super init]) {
        self.conditionLock  = [[NSConditionLock alloc] initWithCondition:1];
    }
    return self;
}

- (void)otherTest {
    
    [[[NSThread alloc] initWithTarget:self selector:@selector(__one) object:nil] start];
    sleep(1);
    [[[NSThread alloc] initWithTarget:self selector:@selector(__two) object:nil] start];
    sleep(1);
    [[[NSThread alloc] initWithTarget:self selector:@selector(__three) object:nil] start];

    
}

- (void)__one {
    
    [self.conditionLock lockWhenCondition:1];  //当condition 为条件的时候才执行

    NSLog(@"one");
    
    [self.conditionLock unlockWithCondition:2];
}

- (void)__two {
    
    [self.conditionLock lockWhenCondition:2];  //当condition 条件不成立的时候不执行
    
    NSLog(@"two");
    
    [self.conditionLock unlockWithCondition:3];
    
}

- (void)__three {
    
    [self.conditionLock lockWhenCondition:3];  //当condition 条件成立的时候才执行
    
    NSLog(@"three");
    
    [self.conditionLock unlock];
    
}
@end
