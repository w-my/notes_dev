//
//  ViewController.m
//  NSInvocation
//
//  Created by WTW on 2020/3/7.
//  Copyright © 2020 wtw. All rights reserved.
//

/*
 NSMethodSignature
    * 方法签名 ，对方法的参数、返回类型进行封装，协同 NSInvocation 实现消息转发
 NSInvocation
    * 是一个消息调用类，包含所有OC消息的成分：target、selector、参数、返回值
    * 可以将消息转换成一个对象，消息的每一个参数都能够直接设定，而且当一个 NSInvocation 对象调度时返回值是可以自己设定的
    * 能够重复调度不同的目标(target),而且它的 selector 也能够设置为另外一个方法签名
    * 遵守 NSCoding 写协议，但是仅支持 NSPortCoder 编码，不支持归档型操作
 */

#import "ViewController.h"
#import <objc/runtime.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
   
#pragma mark -  NSInvocation 基本使用
    
    // 1、根据方法创建签名对象 (MethodSignature 对象)
    // 2、根据签名创建调用对象 (NSInvocation 对象)
    // 3、设置调用对象 (NSInvocation 对象)的相关信息
    // 4、调用方法
    // 5、获取方法返回值
 
    
    // 无参无返回值
//    [self testInvocation1];
    
    // 有参数无返回值
//    [self testInvocation2];
    
    // 有参数有返回值
//    [self testInvocation3];
    
    // 其他属性
    [self testInvocation4];
}
    
#pragma mark 无参无返回值
- (void)testInvocation1 {
    // 1、根据方法创建签名对象 signature
        NSMethodSignature *signature = [[self class] instanceMethodSignatureForSelector:@selector(method)];
    //    NSMethodSignature *signature = [self methodSignatureForSelector:@selector(method)];
        
        // 2、根据签名创建 invocation 对象
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:signature];
        
        // 3、设置调用对象的相关信息
        // 要执行谁(target)的哪个方法(selector)
        invocation.target = self;
        invocation.selector = @selector(method);
        
        // 4、调用方法
        [invocation invoke];
}

- (void)method {
    NSLog(@"无参无返回值");
}

#pragma mark 有参无返回值
- (void)testInvocation2 {
    
    // 1、根据方法创建签名对象 signature
    NSMethodSignature *signature = [[self class] instanceMethodSignatureForSelector:@selector(methodWithArg1:arg2:)];
    
    // 2、根据签名创建 invocation 对象
    NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:signature];
    
    // 3、设置调用对象的相关信息
    // 要执行谁(target)的哪个方法(selector)
    invocation.target = self;
    invocation.selector = @selector(methodWithArg1:arg2:);
    NSString *name = @"Jack";
    int age = 18;
    
    // 因为前两个被 target 和 selector 占用，所有从第三个开始
    [invocation setArgument:&name atIndex:2];
    [invocation setArgument:&age atIndex:3];
    
    // 4、调用方法
    [invocation invoke];
    
}

- (void)methodWithArg1:(NSString *)arg1 arg2:(int)arg2 {
    NSLog(@"arg1:%@ arg2:%d",arg1,arg2);
}

#pragma mark 有参有返回值

- (void)testInvocation3 {
    
    // 1、根据方法创建签名对象 signature
    NSMethodSignature *signature = [[self class] instanceMethodSignatureForSelector:@selector(methodWithArg1:arg2:arg3:)];
    
    // 2、根据签名创建 invocation 对象
    NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:signature];
    
    // 3、设置调用对象的相关信息
    // 要执行谁(target)的哪个方法(selector)
    invocation.target = self;
    invocation.selector = @selector(methodWithArg1:arg2:arg3:);
    int value1 = 111;
    int value2 = 222;
    int value3 = 333;
    
    // 因为前两个被 target 和 selector 占用，所有从第三个开始
    [invocation setArgument:&value1 atIndex:2];
    [invocation setArgument:&value2 atIndex:3];
    [invocation setArgument:&value3 atIndex:4];
    
    // 4、调用方法
    [invocation invoke];
    
    // 5、获取方法返回值
    NSNumber *num = nil;
    [invocation getReturnValue:&num];
    NSLog(@"最大数为:%@",num);
}

- (NSNumber *)methodWithArg1:(int)arg1 arg2:(int)arg2 arg3:(int)arg3 {
    int max1 = MAX(arg1, arg2);
    int max2 = MAX(arg2,arg3);
    return @(MAX(max1, max2));
}

#pragma mark 其他属性和方法
- (void)testInvocation4 {
    // 1、根据方法创建签名对象 signature
    NSMethodSignature *signature = [[self class] instanceMethodSignatureForSelector:@selector(methodWithArg1:arg2:arg3:)];
    
    // 2、根据签名创建 invocation 对象
    NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:signature];
    
    // 3、设置调用对象的相关信息
    // 要执行谁(target)的哪个方法(selector)
    invocation.target = self;
    invocation.selector = @selector(methodWithArg1:arg2:arg3:);
    int value1 = 111;
    int value2 = 222;
    int value3 = 333;
    
    // 因为前两个被 target 和 selector 占用，所有从第三个开始
    [invocation setArgument:&value1 atIndex:2];
    [invocation setArgument:&value2 atIndex:3];
    [invocation setArgument:&value3 atIndex:4];
    
    // 4、调用方法
    [invocation invoke];
    
    // 5、获取方法返回值
    NSNumber *num = nil;
    [invocation getReturnValue:&num];
    NSLog(@"最大数为:%@",num);
    
    
    // 测试其他属性和方法
    
    // NSInvocation 的属性
    // argumentsRetained属性是判断参数是否还存在
    // 调用retainArguments之前，值为NO，调用之后值为YES
    NSLog(@"%@参数保留", (invocation.argumentsRetained ? @"有" : @"没有"));
    [invocation retainArguments];
    NSLog(@"%@参数保留", (invocation.argumentsRetained ? @"有" : @"没有"));

    // 获取参数值
    if (invocation.argumentsRetained) {
        int arg;
        [invocation getArgument:&arg atIndex:4];
        NSLog(@"Argument ---- %d",arg);
    }

    // 设置方法返回值
    NSNumber *value = @987;
    [invocation setReturnValue:&value];
    [invocation getReturnValue:&value];
    NSLog(@"ReturnValue ---- %@",value);


    // 关于NSMethodSignature对象其他属性
    NSLog(@"-------------关于NSMethodSignature对象---------------");
    [self methodSignature:invocation];
        
}

- (void)methodSignature:(NSInvocation *)invocation {

    // 获取方法签名对象
    NSMethodSignature *signature = invocation.methodSignature;

    // 获取方法所占字节数
    NSUInteger frameLength = signature.frameLength;
    NSLog(@"frameLength ---- %ld",frameLength);

    // 获取方法返回值所占字节数
    // 这里只对数值型的类型有效，OC类型打印都是8字节
    NSUInteger returnLength = signature.methodReturnLength;
    NSLog(@"returnLength ---- %ld",returnLength);

    // 判断方法是否是单向
    NSString *oneWay =  [signature isOneway] ? @"是" : @"不是";
    NSLog(@"方法%@单向", oneWay);

    // 获取参数个数
    NSInteger count = signature.numberOfArguments;

    // 打印所有参数类型，
    // 这里打印的结果是  @ : i i i  它们是Objective-C类型编码
    // @ 表示 NSObject* 或 id 类型
    // : 表示 SEL 类型
    // i 表示 int 类型
    for (int i = 0; i < (int)count; i++) {
        const char *argTybe = [signature getArgumentTypeAtIndex:i];
        NSLog(@"参数类型 %s",argTybe);
    }

    // 获取返回值的类型
    const char *returnType = [signature methodReturnType];
    NSLog(@"返回值的类型 %s",returnType);

}

@end
