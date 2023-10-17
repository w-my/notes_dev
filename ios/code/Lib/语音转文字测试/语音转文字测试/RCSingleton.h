//
//  Singleton.h
//  单例宏定义
//  Created by wtw on 2018/11/8.
//  Copyright © 2018 wtw. All rights reserved.

#ifndef RCSingleton_h
#define RCSingleton_h

#define singleton_H(className) +(className *)shared##className;

#define singleton_M(className) \
static className* _instance = nil; \
+ (instancetype)shared##className { \
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken, ^{ \
        _instance = [[className alloc] init]; \
    }); \
        return _instance; \
} \
+ (id)allocWithZone:(struct _NSZone *)zone {\
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken, ^{\
        _instance = [super allocWithZone:zone];\
    });\
    return _instance;\
}\
\
- (id)copyWithZone:(nullable NSZone *)zone {\
    return _instance;\
}\
\
- (id)mutableCopyWithZone:(nullable NSZone *)zone {\
    return _instance;\
}

#endif /* RCSingleton_h */
