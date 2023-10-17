//
//  NSTimer+EOCBlockSupport.m
//  52-NSTimer 保留目标对象的问题
//
//  Created by WTW on 2020/4/3.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "NSTimer+EOCBlockSupport.h"

@implementation NSTimer (EOCBlockSupport)

// 将任务作为 block 传递过去
// 在调用计时器函数时，而是将 block(所执行的任务) 作为 userinfo 传递进去，只要 timer 没有被回收，任务就一直存在（blcok 要 copy 到到堆上，避免被释放）
// 这样 timer 的 target 就是 NSTimer 类对象，是个单例，计时器是否保留NSTimer 都无所谓
// 此处依然有保留环，但是因为类对象无需回收，所以不用担心
+ (NSTimer *)eoc_scheduledTimerWithTimeInterval:(NSTimeInterval)interval
                                          blcok:(void (^)(void))blcok
                                        repeats:(BOOL)repeats {
    
    return  [NSTimer scheduledTimerWithTimeInterval:interval
                                             target:self
                                           selector:@selector(eoc_blockInvoke:)
                                           userInfo:[blcok copy]
                                            repeats:repeats];
}

+ (void)eoc_blockInvoke:(NSTimer *)timer {
    void(^block)(void) = timer.userInfo;
    if (block) {
        block();
    }
}

@end
