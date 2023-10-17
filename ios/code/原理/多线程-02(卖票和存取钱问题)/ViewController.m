//
//  ViewController.m
//  多线程-02(卖票和存取钱问题)
//
//  Created by WTW on 2019/7/31.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property (assign, nonatomic) int money;
@property (assign, nonatomic) int ticketsCount;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
   
    //测试存取钱
    [self moneyTest];
    
    // 测试卖票
    [self ticketTest];
}

/**
 存钱、取钱演示
 */
- (void)moneyTest
{
    self.money = 100;
    
    dispatch_queue_t queue = dispatch_get_global_queue(0, 0);
    
    dispatch_async(queue, ^{
        for (int i = 0; i < 10; i++) {
            [self saveMoney];
        }
    });
    
    dispatch_async(queue, ^{
        for (int i = 0; i < 10; i++) {
            [self drawMoney];
        }
    });
}

/**
 存钱
 */
- (void)saveMoney
{
    int oldMoney = self.money;
    sleep(.2);
    oldMoney += 50;
    self.money = oldMoney;
    
    NSLog(@"存50，还剩%d元 - %@", oldMoney, [NSThread currentThread]);
    
}

/**
 取钱
 */
- (void)drawMoney
{
    int oldMoney = self.money;
    sleep(.2);
    oldMoney -= 20;
    self.money = oldMoney;
    
    NSLog(@"取20，还剩%d元 - %@", oldMoney, [NSThread currentThread]);
}

/*
 thread1：优先级比较高
 
 thread2：优先级比较低
 
 thread3
 
 线程的调度，10ms
 
 时间片轮转调度算法（进程、线程）
 线程优先级
 */

/**
 卖1张票
 */
- (void)saleTicket
{
    int oldTicketsCount = self.ticketsCount;
    sleep(.2);
    oldTicketsCount--;
    self.ticketsCount = oldTicketsCount;
    NSLog(@"还剩%d张票 - %@", oldTicketsCount, [NSThread currentThread]);
}

/**
 卖票演示
 */
- (void)ticketTest
{
    self.ticketsCount = 15;
    
    dispatch_queue_t queue = dispatch_get_global_queue(0, 0);
    
    dispatch_async(queue, ^{
        for (int i = 0; i < 5; i++) {
            [self saleTicket];
        }
    });
    
    dispatch_async(queue, ^{
        for (int i = 0; i < 5; i++) {
            [self saleTicket];
        }
    });
    
    dispatch_async(queue, ^{
        for (int i = 0; i < 5; i++) {
            [self saleTicket];
        }
    });
}

@end
