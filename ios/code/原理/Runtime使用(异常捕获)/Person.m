//
//  Person.m
//  Runtime使用(异常捕获)
//
//  Created by WTW on 2020/3/8.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "Person.h"

@implementation Person

- (void)test1 {
    NSLog(@"%s",__func__);
}

- (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector {
    if ([self respondsToSelector:aSelector]) {
        return [super methodSignatureForSelector:aSelector];
    }
    return [NSMethodSignature signatureWithObjCTypes:"v@:"];
}

// 比如方法没有实现，可以保证程序不会崩溃报错(unrecognized selector sent to instance)
// 可以在这里处理错误信息，比如上传服务器日志等
// 如果想全局都要收集这种错误，保证程序不会崩溃,可以给 NSObject 写一个分类来实现消息转发(也可以使用 NSProxy 这个类是专门做消息转发的)
- (void)forwardInvocation:(NSInvocation *)anInvocation {
    NSLog(@"找不到%@方法实现",NSStringFromSelector(anInvocation.selector));
}
@end
