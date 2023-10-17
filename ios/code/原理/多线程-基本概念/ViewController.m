//
//  ViewController.m
//  多线程-基本概念
//
//  Created by WTW on 2020/2/5.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
//    NSThread *mainThread = [NSThread mainThread];
//    NSLog(@"获取主线程:%@",mainThread);
//
//    NSThread *currentThread = [NSThread currentThread];
//    NSLog(@"获取当前线程%@",currentThread);
    
#pragma mark - pthread_t 使用
    
    //1、创建线程对象
//    pthread_t thread = NULL;
   
    // 创建线程
//    pthread_create(&thread,NULL,task,NULL);
   
#pragma mark - NSThread 使用
    // 方式1
    // 创建线程
//    NSThread *thread1 = [[NSThread alloc] initWithTarget:self selector:@selector(longOperation:) object:@"alloc"];
    // 启动线程
//    [thread1 start];
//    thread1.name = @"thread1"; // 线程名称
//    thread1.threadPriority = 0.7; // 0.0 ~1.0;
    
    // 方式2
//    [NSThread detachNewThreadWithBlock:^{
//        NSLog(@"%@",[NSThread currentThread]);
//    }];
    
//    [NSThread detachNewThreadSelector:@selector(longOperation:) toTarget:self withObject:@"detach"];
    
    // 方式3
//    [self performSelectorInBackground:@selector(longOperation:) withObject: @"perform"];
    
#pragma mark - 线程间通信
    // 1个线程传递数据给另外一个线程
    // 在一个线程中执行完特定的任务后，转到另外一个线程继续执行任务
//    [self performSelectorOnMainThread:<#(nonnull SEL)#> withObject:<#(nullable id)#> waitUntilDone:<#(BOOL)#>]
//    [self performSelector:<#(nonnull SEL)#> onThread:<#(nonnull NSThread *)#> withObject:<#(nullable id)#> waitUntilDone:<#(BOOL)#>]
    
#pragma mark - GCD 使用
    // 详见 多线程-GCD
    
#pragma mark - NSOperation 使用
    // 详见 NSOperation

    
}


void *task(void *param){
    NSLog(@"---%@---",[NSThread currentThread]);
    return NULL;
}

- (void)longOperation:(NSString *)param {
    NSLog(@"%@,%@",[NSThread currentThread],param);
}

@end
