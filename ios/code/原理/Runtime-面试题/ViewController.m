//
//  ViewController.m
//  Runtime-面试题
//
//  Created by WTW on 2019/9/19.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"
#import "Person.h"

@interface ViewController ()

@end

@implementation ViewController

/*
 1、 print 为什么能够调用成功 ？
 2、 为什么 self.name 变成了 ViewController等其他内容 ？
 */

/*
 
[super viewDidLoad]; 转换为以下代码：
 
 // objc_super 相当于是一个局部变量
 struct objc_super = {
 {
     self,
     [UIViewController class]
 }
 
 objc_msgSendSuper)(objc_super,sel_registerName("viewDidLoad"));
 
 objc_super 其实就是一个隐藏的局部变量，相当于在 cls 前面是有一个局部变量(这个局部变量是一个结构体)，这样结构就如上图所示。
 这样根据前面介绍的原理 忽略掉前8个字节(cls)找到的就是 self 而 self 就是ViewOntroller，所以打印出来就是 ViewController.
 */


- (void)viewDidLoad {
    
    [super viewDidLoad];
    
//    NSString *test = @"123"; // my name's 123
//    NSObject *obj2 = [[NSObject alloc] init];  // my name's <NSObject: 0x6000019b8440>
    
    // print 为什么能调用成功 ？ 调用成功的原因在于 [super viewDidLoad];
    id cls = [Person class];
    void *obj = &cls;
    [(__bridge id)obj print]; // my name's <ViewController: 0x7fb9ebe04470>
    
//    NSLog(@"%p %p %p",&test,&cls,&obj); // 0x7ffee18878f8 0x7ffee18878f0 0x7ffee18878e8
    
    Person *person = [[Person alloc] init];
    [person print]; // my name's (null)
    
    // 局部变量分配在栈空间
    // 栈空间内存的分配是从高地址到低地址
//    long long a = 4;    // 0x7ffeea6e98e0
//    long long b = 5;    // 0x7ffeea6e98d8
//    long long c = 6;    // 0x7ffeea6e98d0
//    NSLog(@"%p %p %p",&a,&b,&c);  // 0x7ffeea6e98e0 0x7ffeea6e98d8 0x7ffeea6e98d0
}

@end
