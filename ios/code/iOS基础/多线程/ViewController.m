//
//  ViewController.m
//  多线程
//
//  Created by WTW on 2020/2/5.
//  Copyright © 2020 WTW. All rights reserved.
//

/**
 *  线程 和 进程的比较：
 *  1、线程是CPU 调度的的最小单位
 *  2、进程是资源分配和调用的单位
 *  3、一个程序可以对应多个进程，一个进程可以有多个线程，但至少要有一个线程
 *  4、同一个进程内的线程共享进程的资源
 *
 *  多线程的原理：
 *  同一时间，CPU(未考虑多核CPU)只能处理1条线程，只有1条线程在工作
 *  多线程并发执行，其实是CPU足够快地在多条线程之间调度(切换)
 *  如果CPU调度线程的时间足够快，就造成了多线程并发执行的假象
 *
 *  多线程的优缺点：
 *  优点：
 *  能适当提高程序的执行效率
 *  能适当提高资源的利用率(CPU、内存利用率)
 *
 *  缺点:
 *  1、创建线程是有开销的，iOS 下主要成本包括：内核数据结构(大约1KB)、栈空间(子线程512KB、主线程1MB、也可以使用 setStackSize:设置，但必须是4K的倍数，而且最小是16K).创建线程大约需要90毫秒的创建时间
 *  2、如果开启大量的线程，会降低程序的性能
 *  3、线程越多，CPU 在调度程序上的开销就越大
 *  4、程序设计更加复杂：比如线程之间的通信、多线程的数据共享
 *
 *  iOS中多线程方案：
 *  pthread （了解）
 *  NSThread
 *  GCD  (重点)
 *  NSOperation （重点）
 *
 */

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.

    NSThread *mainThread = [NSThread mainThread];
    NSLog(@"获取主线程:%@",mainThread);
    
    NSThread *currentThread = [NSThread currentThread];
    NSLog(@"获取当前线程%@",currentThread);
}

@end
