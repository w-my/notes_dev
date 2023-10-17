//
//  SemaphoreDemo.m
//  多线程-03(线程同步问题 锁)
//
//  Created by WTW on 2019/8/5.
//  Copyright © 2019 wtw. All rights reserved.
//

/*
 semaphore叫做”信号量”
 信号量的初始值，可以用来控制线程并发访问的最大数量
 信号量的初始值为1，代表同时只允许1条线程访问资源，保证线程同步
 */

#import "SemaphoreDemo.h"

@interface SemaphoreDemo ()
@property (nonatomic,strong) dispatch_semaphore_t semaphore;
@property (nonatomic,strong) dispatch_semaphore_t ticketSemaphore;
@end

@implementation SemaphoreDemo

- (instancetype)init {
    if (self = [super init]) {
        self.semaphore = dispatch_semaphore_create(5);  // 控制并发量为5
        self.ticketSemaphore = dispatch_semaphore_create(1);  // 并发线程为1 实现同步
    }
    return self;
}

- (void)otherTest {
    for (int i = 0; i < 20; i ++) {
        [[[NSThread alloc] initWithTarget:self selector:@selector(test) object:nil] start];
    }
}

- (void)test {
    //如果信号量的值 >0 就让信号量的值减1 然后继续往下执行代码
    //如果信号量的值<= 0 就会休眠等待，直到信号量的值变成 > 0 就会让信号量的值减1 ，然后继续往下执行代码
    dispatch_semaphore_wait(self.semaphore, DISPATCH_TIME_FOREVER);
    sleep(2);
    NSLog(@"test - %@",[NSThread currentThread]);
    dispatch_semaphore_signal(self.semaphore);
}

//测试卖票 实现线程同步
- (void)__saleTicket {
    
    dispatch_semaphore_wait(self.ticketSemaphore, DISPATCH_TIME_FOREVER);
    
    [super __saleTicket];
    
    dispatch_semaphore_signal(self.ticketSemaphore);
}


/**
 * 如果有多个方法，每个方法需要一个锁的解决方法
 * 1、可以声明多个 Semaphore 属性
 * 2、可以使用单例
 *
- (void)test1 {
    static dispatch_semaphore_t semaphore;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        semaphore = dispatch_semaphore_create(1);
    });
    
    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    
    ......
    
    dispatch_semaphore_signal(semaphore);
}

- (void)test2 {
    static dispatch_semaphore_t semaphore;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        semaphore = dispatch_semaphore_create(1);
    });
    
    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    
    ......
    
    dispatch_semaphore_signal(semaphore);
}

- (void)test3 {
    static dispatch_semaphore_t semaphore;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        semaphore = dispatch_semaphore_create(1);
    });
    
    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    
    ......
    
    dispatch_semaphore_signal(semaphore);
}
*/

@end
