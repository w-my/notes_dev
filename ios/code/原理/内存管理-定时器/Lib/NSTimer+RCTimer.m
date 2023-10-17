//
//  NSTimer+RCTimer.m
//  NSTimer使用注意事项
//
//  Created by wtw on 2018/8/29.
//  Copyright © 2018年 wtw. All rights reserved.
//

#import "NSTimer+RCTimer.h"

@implementation NSTimer (RCTimer)

//block 在ARC的情况下，一般情况下是自动copy的，不管是设置为propetry strong/copy 都是一样的
//但是作为自己函数的参数：block 是不会copy的 ，系统的会自动copy的
// __NSStackBlock__
+ (instancetype)timerWithTimeInterval:(NSTimeInterval)ti
                                block:(void (^)(void))block
                              repeats:(BOOL)repeats {
    
    return [NSTimer timerWithTimeInterval:ti
                                   target:self
                                 selector:@selector(timerAction:)
                                 userInfo:block
                                  repeats:repeats];
}

+ (void)timerAction:(NSTimer *)timer {
    void(^block)(void) = [timer userInfo];
    if (block) {
        block();
    }
}

@end
