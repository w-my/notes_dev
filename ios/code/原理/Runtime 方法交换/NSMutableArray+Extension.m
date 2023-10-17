//
//  NSMutableArray+Extension.m
//  Runtime 方法交换
//
//  Created by WTW on 2020/3/10.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "NSMutableArray+Extension.h"
#import <objc/runtime.h>

@implementation NSMutableArray (Extension)

// NSString NSArray NSDictonary 都是类簇，真实类型都是其他类型
/*
 NSArray             __NSArrayI
 NSMutableArray      __NSArrayM
 NSDictionry         __NSDictionaryI
 NSMutableDictionary __NSDictionaryM
 */

+ (void)load {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        Class cls = NSClassFromString(@"__NSArrayM");
        Method method1 = class_getInstanceMethod(cls, @selector(insertObject:atIndex:));
        Method method2 = class_getInstanceMethod(cls, @selector(tw_insertObject:atIndex:));
        method_exchangeImplementations(method1, method2);
    });
}

- (void)tw_insertObject:(id)anObject atIndex:(NSUInteger)index {
    if (anObject == nil) {
        NSLog(@"添加元素失败，不能添加nil");
        return;
    }
    [self tw_insertObject:anObject atIndex:index];
}

@end
