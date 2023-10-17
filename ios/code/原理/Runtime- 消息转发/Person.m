//
//  Person.m
//  Runtime- 消息转发
//
//  Created by WTW on 2019/8/21.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "Person.h"
#import "PersonC.h"
#import <objc/runtime.h>

// 消息转发 : 将消息转发
// 无法跟源码，只能打断点跟，国外有开源的代码参考 __forwarding__ 

@implementation Person

- (id)forwardingTargetForSelector:(SEL)aSelector {
    if(aSelector == @selector(test:)){
//        return [[PersonC alloc] init];  // 转发给 PersonC
        return nil;    // 如果返回 nil 会走 methodSignatureForSelector 
    }
    return [super forwardingTargetForSelector:aSelector];
}

// 方法签名 ： 返回值类型 参数类型
- (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector {
    if (aSelector == @selector(test:)) {
        return [NSMethodSignature signatureWithObjCTypes:"v@:i"];
        
        // 也可以这样返回
        // 前提是 PersonC 必须有 test: 这个方法
//       return [[[PersonC alloc] init] methodSignatureForSelector:@selector(test:)];
    }
    return [super methodSignatureForSelector:aSelector];
}

//NSInvocation 封装了一个方法调用  包括：方法调用者 方法名 方法参数
// anInvocation.target   方法调用者
// anInvocation.selector  方法名
// [anInvocation getArgument:NULL atIndex:0]

// 只要走到这个方法 怎么处理都可以的 都是执行方法后的结果
- (void)forwardInvocation:(NSInvocation *)anInvocation {

//    anInvocation.target = [[PersonC alloc] init];
//    [anInvocation invoke];
    
    [anInvocation invokeWithTarget:[[PersonC alloc] init]];
    
//    // 也可以在此获取参数值
//    int age;
//    [anInvocation getArgument:&age atIndex:2];
//    NSLog(@"%d",age);  // 10
    
    // 也可以获取方法的返回值
//    int retvalue;
//    [anInvocation getReturnValue:&retvalue];
//    NSLog(@"%d",retvalue);
    
//    NSLog(@"哈哈哈哈");
}

@end
