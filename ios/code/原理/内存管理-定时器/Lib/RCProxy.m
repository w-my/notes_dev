//
//  RCProxy.m
//  NSTimer使用注意事项
//
//  Created by wtw on 2018/8/30.
//  Copyright © 2018年 wtw. All rights reserved.
//

#import "RCProxy.h"

@implementation RCProxy

-(instancetype)initWithTarget:(id)target {
    _target = target;
    return self;
}

// NSProxy 对象不需要调用 init 方法，因为 NSProxy 没有init 方法
+(instancetype)proxyWithTarget:(id)target {
    return [[RCProxy alloc] initWithTarget:target];
}

// 通过消息转发来实现间接调用
-(NSMethodSignature *)methodSignatureForSelector:(SEL)sel {
    return [_target methodSignatureForSelector:sel];
}

-(void)forwardInvocation:(NSInvocation *)invocation {
    [invocation invokeWithTarget:_target];
}

//-(BOOL)respondsToSelector:(SEL)aSelector {
//    return [_target respondsToSelector:aSelector];
//}
//-(BOOL)isEqual:(id)object {
//    return [_target isEqual:object];
//}
//-(NSUInteger)hash {
//    return [_target hash];
//}
//-(Class)superclass {
//    return [_target superclass];
//}
//-(Class)class {
//    return [_target class];
//}
//-(BOOL)isKindOfClass:(Class)aClass {
//    return [_target isKindOfClass:aClass];
//}
//-(BOOL)isMemberOfClass:(Class)aClass {
//    return [_target isMemberOfClass:aClass];
//}
//-(BOOL)conformsToProtocol:(Protocol *)aProtocol {
//    return [_target conformsToProtocol:aProtocol];
//}
//-(BOOL)isProxy {
//    return YES;
//}
//-(NSString *)description {
//    return [_target description];
//}
//-(NSString *)debugDescription {
//    return [_target debugDescription];
//}

@end
