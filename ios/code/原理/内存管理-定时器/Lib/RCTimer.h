//
//  RCTimer.h
//  内存管理-定时器
//
//  Created by WTW on 2019/8/15.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RCTimer : NSObject

/*
 __weak typeof(self) weakSelf = self;
 self.task = [RCTimer execTask:^{
    [weakSelf timerTest];
    }
     start:0
     interval:1
     repeats:YES
     async:YES];
 */

/// GCD 定时器执行任务 返回任务的唯一标识
/// @param task block 形式追加任务
/// @param start 什么时候开始执行
/// @param interval 间隔多久执行一次
/// @param repeats 是否重复执行
/// @param async 是否异步执行
+ (NSString *)execTask:(void(^)(void))task
           start:(NSTimeInterval)start
        interval:(NSTimeInterval)interval
         repeats:(BOOL)repeats
           async:(BOOL)async;

/// GCD 定时器执行任务 返回任务的唯一标识
/// @param target 目标
/// @param selector 执行的方法
/// @param start 什么时候开始执行
/// @param interval 间隔多久执行一次
/// @param repeats 是否重复执行
/// @param async 是否异步执行
+ (NSString *)execTask:target
              selector:(SEL)selector
                 start:(NSTimeInterval)start
              interval:(NSTimeInterval)interval
               repeats:(BOOL)repeats
                 async:(BOOL)async;

/// 取消任务
/// @param task 任务的唯一标识
+ (void)cancelTask:(NSString *)task;

@end

NS_ASSUME_NONNULL_END
