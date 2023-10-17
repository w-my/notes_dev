//
//  RCPermenantThread.h
//  RunLoop 线程保活封装工具
//
//  Created by WTW on 2019/8/19.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RCPermenantThread : NSObject

/**
 开启一个线程
 */
- (void)run;

/**
 在当前子线程执行一个任务
 */
- (void)executeTask:(void(^)(void))task;

/**
 结束一个线程
 */
- (void)stop;

@end

NS_ASSUME_NONNULL_END
