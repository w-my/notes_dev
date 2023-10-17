//
//  NSTimer+RCTimer.h
//  NSTimer使用注意事项
//
//  Created by wtw on 2018/8/29.
//  Copyright © 2018年 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSTimer (RCTimer)

+ (instancetype)timerWithTimeInterval:(NSTimeInterval)ti
                                block:(void(^)(void))block
                              repeats:(BOOL)repeats;

@end
