//
//  UIControl+Extension.m
//  Runtime 方法交换
//
//  Created by WTW on 2020/3/10.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "UIControl+Extension.h"
#import <objc/runtime.h>

// 默认间隔时间1秒
#define defaultInterval 1

@implementation UIControl (Extension)

+ (void)load {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        @autoreleasepool {
            Method method1 = class_getInstanceMethod(self, @selector(sendAction:to:forEvent:));
            Method method2 = class_getInstanceMethod(self, @selector(tw_sendAction:to:forEvent:));
            method_exchangeImplementations(method1, method2);
        }
    });
}

- (void)setTimeInterval:(NSTimeInterval)timeInterval {
    objc_setAssociatedObject(self, @selector(timeInterval), @(timeInterval), OBJC_ASSOCIATION_ASSIGN);
}

- (NSTimeInterval)timeInterval {
    return [objc_getAssociatedObject(self, @selector(timeInterval)) doubleValue];
}

- (void)setIsIgnore:(BOOL)isIgnore {
    objc_setAssociatedObject(self, @selector(isIgnore), @(isIgnore), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (BOOL)isIgnore {
    return [objc_getAssociatedObject(self, @selector(isIgnore)) boolValue];
}

- (void)tw_sendAction:(SEL)action to:(id)target forEvent:(UIEvent *)event {
    
    NSLog(@"可以在这里处理button 的点击等 %@ target: %@ action:%@",[self class],target,NSStringFromSelector(action));
    
    
    // 下面方法
    if ([NSStringFromClass(self.class) isEqualToString:@"UIButton"]) {
           self.timeInterval = self.timeInterval == 0 ? defaultInterval : self.timeInterval;
           if (self.isIgnore) {
               return;
           }else if(self.timeInterval > 0) {
               [self performSelector:@selector(resetState) withObject:nil afterDelay:self.timeInterval];
           }
       }
       self.isIgnore = YES;
       
       [self tw_sendAction:action to:target forEvent:event];
}

- (void)resetState {
    [self setIsIgnore:NO];
}

@end
