//  MyOperation.m
//  自定义NSOperation
//
//
//  Created by WTW on 2020/4/3.
//  Copyright © 2020 wtw. All rights reserved.
//

/*
* 自定义并发的NSOperation需要以下步骤：
* 1.start方法：该方法必须实现，
* 2.main:该方法可选，如果你在start方法中定义了你的任务，则这个方法就可以不实现，但通常为了代码逻辑清晰，通常会在该方法中定义自己的任务
* 3.isExecuting  isFinished 主要作用是在线程状态改变时，产生适当的KVO通知
* 4.isConcurrent :必须覆盖并返回YES;
*/

#import "MyOperation.h"

@implementation MyOperation

// 由于父类是 readonly 的，所需重载时需要setter的话需要手动合成
@synthesize executing = _executing;
@synthesize finished = _finished;

- (instancetype)init {
    if (self = [super init]) {
        _executing = NO;
        _finished = NO;
    }
    return self;
}

/*
 并发操作必须重载此方法，并使用自定义的实现替换默认实现
 重载 start 方法负责以异步的方式启动一个操作，无论是像开启一个线程还是调用异步函数，都可以在start 方法中进行
 开始操作之前需要需要更新操作的执行状态，方便查看操作状态
 任何时候都不需要调用父类的 start 方法
 
 main 方法可选，如果在 start 方法中定义了任务，mian 方法就可以不实现
 通常为了代码清晰，会在该方法中定义自己的任务
 */
// 此方法必须实现
- (void)start {
    @autoreleasepool {
        if (self.isCancelled) {
            self.finished = YES;
            self.executing = NO;
            return;
        }
        
        self.executing = YES;
        
        // 需要做的任务 ......
        for (int i = 0; i < 10; i ++) {
            [NSThread sleepForTimeInterval:2];
            NSLog(@"Thread1 == %@",[NSThread currentThread]);
        }
        
        for (int i = 0; i < 10; i ++) {
            [NSThread sleepForTimeInterval:2];
            NSLog(@"Thread2 == %@",[NSThread currentThread]);
        }
    }
    
    // 任务执行完，手动设置状态
    self.finished = YES;
    self.executing = NO;
}

#pragma mark - getter & setter

- (void)setExecuting:(BOOL)executing {
    [self willChangeValueForKey:@"isExecuting"];
    _executing = executing;
    [self didChangeValueForKey:@"isExecuting"];
}

- (BOOL)isExecuting {
    return _executing;
}

- (void)setFinished:(BOOL)finished {
    [self willChangeValueForKey:@"isFinished"];
    _finished = finished;
    [self didChangeValueForKey:@"isFinished"];
}

- (BOOL)isFinished {
    return _finished;
}

#pragma mark - 标识是否并发
- (BOOL)isAsynchronous {
    return  YES;
}

//- (void)cancel {
//    if (self.isFinished) return;
//    [super cancel];
//
//    self.executing = NO;
//    self.finished = YES;
//}

@end
