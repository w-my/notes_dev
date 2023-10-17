//
//  Person.m
//  Runtime-消息转发(类对象)
//
//  Created by WTW on 2019/8/21.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "Person.h"
#import "PersonC.h"

@implementation Person

// 类方法 xcode 会没有提示(先写成对象方法，在改一下即可)
+ (id)forwardingTargetForSelector:(SEL)aSelector {
    if (aSelector == @selector(test)) {
//        return [PersonC class];
        return nil;
    }
    return [super forwardingTargetForSelector:aSelector];
}

+ (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector {
 
    if (aSelector == @selector(test)) {
        return [NSMethodSignature signatureWithObjCTypes:"v@:"];
    }
    return [super methodSignatureForSelector:aSelector];
}

+ (void)forwardInvocation:(NSInvocation *)anInvocation {
    [anInvocation invokeWithTarget:[PersonC class]];
    NSLog(@"123");
}

@end
