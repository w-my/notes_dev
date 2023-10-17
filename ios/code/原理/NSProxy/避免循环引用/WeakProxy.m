//
//  WeakProxy.m
//  NSProxy
//
//  Created by WTW on 2020/3/9.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "WeakProxy.h"

@implementation WeakProxy

- (instancetype)initWithTarget:(id)target {
    _target = target;
    return self;
}

+ (instancetype)proxyWithTarget:(id)target {
    return [[self alloc] initWithTarget:target];
}

- (NSMethodSignature *)methodSignatureForSelector:(SEL)sel {
    return [self.target methodSignatureForSelector:sel];
}

- (void)forwardInvocation:(NSInvocation *)invocation {
    SEL sel = invocation.selector;
    if ([self.target respondsToSelector:sel]) {
        [invocation invokeWithTarget:self.target];
    }
}

@end
