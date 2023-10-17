//
//  Observer.m
//  NSNotificationCenter
//
//  Created by WTW on 2020/3/14.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "Observer.h"

static NSString *TestNotification = @"TestNotification";

@implementation Observer

- (instancetype)init
{
    self = [super init];
    
    if (self)
    {
        NSLog(@"Init Observer");
        
        // 添加观察者
        // block 内部一定要用 weakself ,避免循环引用
        __weak typeof(self) weakself = self;
        _observer =  [[NSNotificationCenter defaultCenter] addObserverForName:TestNotification object:nil queue:[NSOperationQueue mainQueue] usingBlock:^(NSNotification *note) {
            
            NSLog(@"handle notification");
            
            // 使用self
            weakself.i = 10;
        }];
    }
    
    return self;
}

- (void)dealloc {
    NSLog(@"%s",__func__);
}

@end
