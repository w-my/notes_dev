//
//  Person.m
//  LLVM 中间代码
//
//  Created by WTW on 2020/3/10.
//  Copyright © 2020 wtw. All rights reserved.
//

/*
 Objective-C在变为机器代码之前，会被LLVM编译器转换为中间代码（Intermediate Representation）

可以使用以下命令行指令生成中间代码
clang -emit-llvm -S Person.m

语法简介
@ - 全局变量
% - 局部变量
alloca - 在当前执行的函数的堆栈帧中分配内存，当该函数返回到其调用者时，将自动释放内存
i32 - 32位4字节的整数
align - 对齐
load - 读出，store 写入
icmp - 两个整数值比较，返回布尔值
br - 选择分支，根据条件来转向label，不根据条件跳转的话类似 goto
label - 代码标签
call - 调用函数

具体可以参考官方文档：https://llvm.org/docs/LangRef.html
 */

#import "Person.h"

@implementation Person

- (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector {
    return [NSMethodSignature signatureWithObjCTypes:"v@:"];
}

- (void)forwardInvocation:(NSInvocation *)anInvocation {
    
    // 通过 中间代码(.ll)可以验证 super 的底层的确调用的是 objc_msgSendSuper2
    [super forwardInvocation:anInvocation];
        
    int a = 10;
    int b = 20;
    int c = a + b;
    
    NSLog(@"===");
}


@end
