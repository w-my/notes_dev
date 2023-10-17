//
//  ViewController.m
//  NSThread
//
//  Created by WTW on 2020/2/5.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    // 方式1
    // 创建线程
    NSThread *thread1 = [[NSThread alloc] initWithTarget:self selector:@selector(longOperation:) object:@"alloc"];
    // 启动线程
    [thread1 start];
    thread1.name = @"thread1"; // 线程名称
    thread1.threadPriority = 0.7; // 0.0 ~1.0;
    
    // 方式2
//    [NSThread detachNewThreadWithBlock:^{
//        NSLog(@"%@",[NSThread currentThread]);
//    }];
    
    [NSThread detachNewThreadSelector:@selector(longOperation:) toTarget:self withObject:@"detach"];
    
    // 方式3
    [self performSelectorInBackground:@selector(longOperation:) withObject: @"perform"];
}

- (void)longOperation:(NSString *)param {
    NSLog(@"%@,%@",[NSThread currentThread],param);
}

@end
