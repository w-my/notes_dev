//
//  SingletonTool.m
//  单例模式
//
//  Created by WTW on 2020/2/6.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "SingletonTool.h"

@implementation SingletonTool

static SingletonTool *_instance;

// alloc 调的也是 allocWithZone 重新 allocWithZone
+ (instancetype)allocWithZone:(struct _NSZone *)zone {
    
    // 加互斥锁也可以解决多线程访问的问题
//    @synchronized (self) {
//        if (!_instance) {
//            _instance = [super allocWithZone:zone];
//        }
//    }
    
    // 一般是用 dispatch_once
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [super allocWithZone:zone];
    });
    return _instance;
}

+ (instancetype)shareTool {
    return [[self alloc] init];
}

- (id)copyWithZone:(struct _NSZone *)zone{
    return _instance;
}

- (id)mutableCopyWithZone:(struct _NSZone *)zone{
    return _instance;
}

#if __has_feature(objc_arc)
    // ARC
#else
   // MRC
- (oneway void)release {
    
}

- (instancetype)retain {
    return _instance;
}

- (NSUInteger)retainCount {
    return  MAXFLOAT;
}
#endif



@end
