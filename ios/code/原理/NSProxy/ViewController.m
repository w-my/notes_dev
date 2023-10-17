//
//  ViewController.m
//  NSProxy
//
//  Created by WTW on 2020/3/9.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "ViewController.h"
#import "ClassA.h"
#import "ClassB.h"
#import "ClassProxy.h"
#import "WeakProxy.h"
#import "AOPProxy.h"

/*  真正的代理
 an abstract superclass defining an API for objects that act as stand-ins for other objects or for objects that don’t exist yet
 一个抽象的超类，它定义了一个对象的API，用来代替其他对象或不存在的对象；
 一般发送给 proxy 的消息被转发给真实的对象或者将proxy转换成一个真实的对象。
 其子类可以实现透明的转发消息，或用于创建开销比价大的对象的延迟实例化；
 NSProxy 实现了根类所需的基本方法，遵守 NSObject 协议，但是不提供初始化方法；
 因此一个具体的子类必须提供一个初始化的创建方法，并覆盖 forwardInvocation: 和 methodSignatureForSelector: 方法来处理它自己没有实现的消息。子类的 forwardInvocation：实现应该执行处理调用所需的所有操作；
 
 一般用法：
 1、多继承
 2、避免循环引用
    处理 NSTimer 循环引用的问题
 3、AOP 面向切片编程
    面向切片编程两种方式：
    一种是基于Runtime 的 method-Swizzling
    另外一种是基于 NSProxy
 */


@interface ViewController ()
@property (nonatomic,strong) NSTimer *timer;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
   
#pragma mark - OC 不支持多继承，可以通过 protocol 和 NSProxy 来实现
    
   ClassA *A = [[ClassA alloc]init];
   ClassB *B = [[ClassB alloc]init];
   ClassProxy *proxy = [ClassProxy alloc];
   [proxy handleTargets:@[A,B]];
   [proxy performSelector:@selector(infoA)];
   [proxy performSelector:@selector(infoB)];

#pragma mark - 避免循环引用
//    self.timer = [NSTimer timerWithTimeInterval:1
//                                             target:[WeakProxy proxyWithTarget:self]
//                                           selector:@selector(invoked:)
//                                           userInfo:nil
//                                            repeats:YES];
//    [[NSRunLoop mainRunLoop] addTimer:self.timer forMode:NSRunLoopCommonModes];

#pragma mark - AOP 面向切片编程
    
    NSMutableArray *targtArray = [AOPProxy proxyWithTarget:[NSMutableArray arrayWithCapacity:1]];
    [(AOPProxy *)targtArray inspectSelector:@selector(addObject:) preSelTask:^(id target, SEL selector) {
        [target addObject:@"-------"];
        NSLog(@"%@我加进来之前",target);
    } endSelTask:^(id target, SEL selector) {
        [target addObject:@"-------"];
        NSLog(@"%@我加进来之后",target);
    }];
    [targtArray addObject:@"我是一个元素"];
    
}

- (void)invoked:(NSTimer *)timer{
    NSLog(@"=====");
}


@end
