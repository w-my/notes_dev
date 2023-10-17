//
//  NSMutableDictionary+Extension.m
//  Runtime 方法交换
//
//  Created by WTW on 2020/3/10.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "NSMutableDictionary+Extension.h"
#import <objc/runtime.h>


@implementation NSMutableDictionary (Extension)

+ (void)load {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
          @autoreleasepool {
            Class cls = NSClassFromString(@"__NSDictionaryM");
            Method method1 = class_getInstanceMethod(cls, @selector(setValue:forKey:));
            Method method2 = class_getInstanceMethod(cls, @selector(tw_setValue:forKey:));
            method_exchangeImplementations(method1, method2);
            
            Class cls2 = NSClassFromString(@"__NSDictionaryI");
            Method method3 = class_getInstanceMethod(cls2, @selector(objectForKey:));
            Method method4 = class_getInstanceMethod(cls2, @selector(tw_objectForKey:));
            method_exchangeImplementations(method3, method4);
                
            
          }
    });
}

- (void)tw_setValue:(id)value forKey:(NSString *)key {
    if (!key) {
        NSLog(@"添加失败 key 不能为nil");
        return; // key 为 nil 直接返回
    }
    [self tw_setValue:value forKey:key];
}

- (id)tw_objectForKey:(id)key {
    if (!key) return nil;
   return [self tw_objectForKey:key];
}

@end
