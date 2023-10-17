//
//  EOCClass.m
//  52-NSTimer 保留目标对象的问题
//
//  Created by WTW on 2020/4/3.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "EOCClass.h"
#import "NSTimer+EOCBlockSupport.h"

@implementation EOCClass
{
    NSTimer *_pollTimer;
}

- (void)startPolling {
    
    // 会存在循环引用
    // NSTimer 强引用 self  self 又强引用 Timer
//    _pollTimer = [NSTimer scheduledTimerWithTimeInterval:2.0
//                                              target:self
//                                                selector:@selector(do_someThing)
//                                                userInfo:nil
//                                                 repeats:YES];
    
    // 让 NSTimer 不强引用 self ,而是将任务封装在 block 块中
    // 必须是使用 weakself 否者还是会有循环引用
    __weak typeof(self) weakSelf = self;
    _pollTimer = [NSTimer eoc_scheduledTimerWithTimeInterval:2.0
                                                       blcok:^{
        [weakSelf do_someThing];
    } repeats:YES];
}

- (void)stopPolling {
    [_pollTimer invalidate];
    _pollTimer = nil;
}

- (void)do_someThing {
    NSLog(@"%s",__func__);
}

- (void)dealloc {
    [_pollTimer invalidate];
    _pollTimer = nil;
    NSLog(@"%s",__func__);
}

@end
