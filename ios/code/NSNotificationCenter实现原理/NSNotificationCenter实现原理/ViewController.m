//
//  ViewController.m
//  NSNotificationCenter实现原理
//
//  Created by wtw on 2018/8/21.
//  Copyright © 2018年 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    // 通知默认是同步的
//    [self sendNotification];
    
    //异步发送通知
    [self notificationQueue];
}

- (void)viewDidLoad {
    [super viewDidLoad];

    //po [NSNotificationCenter defaultCenter] 可以查看系统通知 是一个列表
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotifaction:) name:@"TESTNSNOTIFICATION" object:nil];
}

//异步发送
//send before 1 : <NSThread: 0x604000262e00>{number = 1, name = main}
//send over 3
//notification 2 : <NSThread: 0x604000262e00>{number = 1, name = main}
- (void)notificationQueue {
    NSNotification *noti = [NSNotification notificationWithName:@"TESTNSNOTIFICATION" object:nil userInfo:nil];
    NSNotificationQueue *queue = [NSNotificationQueue defaultQueue];
    
    NSLog(@"send before 1 : %@",[NSThread currentThread]);
    
    //NSPostNow : 同步发送
    //每一个线程都有一个通知队列
    [queue enqueueNotification:noti postingStyle:NSPostWhenIdle coalesceMask:NSNotificationNoCoalescing forModes:nil];

    NSLog(@"send over 3");
    
}

//同步发送
//send before 1 : <NSThread: 0x604000074c40>{number = 1, name = main}
//notification 2 : <NSThread: 0x604000074c40>{number = 1, name = main}
//send over 3
- (void)sendNotification {
    NSLog(@"send before 1 : %@",[NSThread currentThread]);
   
    [[NSNotificationCenter defaultCenter] postNotificationName:@"TESTNSNOTIFICATION" object:nil userInfo:nil];
    
    NSLog(@"send over 3");
}

- (void)handleNotifaction:(NSNotification *)noti {
    
    NSLog(@" notification 2 : %@",[NSThread currentThread]);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
