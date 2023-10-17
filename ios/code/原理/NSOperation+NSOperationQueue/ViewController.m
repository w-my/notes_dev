//
//  ViewController.m
//  NSOperation+NSOperationQueue
//
//  Created by WTW on 2019/10/21.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

/*
 NSOperation 的作用：
    NSOperation 和 NSOperationQueue 搭配实现多线程编程
 
 NSOperation 和 NSOperationQueue 实现多线程的步骤：
     1、先将需要执行的操作封装到 NSOperation 对象中
     2、将 NSOperation 对象添加到 NSOperationQueue 中
     3、系统会自动将 NSOperationQueue 中的 NSOperation 取出来
     4、将取出来的 NSOperation 封装的操作放到一条新线程中执行
 
 NSOperation 的子类 ：
    NSInvocationOperation
    NSBlockOperation
    自定义 NSOperation
 
 
 
 */

#pragma mark - 自定义非并发的 NSOperation

@interface TestOperation : NSOperation

@end

@implementation TestOperation

// main 方法是在 start 方法内部执行的
//- (void)start {
//
//}

// 自定义 NSOperation   1、有利于代码隐蔽  2、有利于代码复用
// 需要重写 mian 方法，执行自定义的任务
// 不建议在只实现 main 函数的情况下将其加入到 NSOperationQueue ，只实现 main 一般只适合自定义非并发
- (void)main {
    
    if (!self.isCancelled) {
        for (int i = 0; i < 10; i ++) {
            [NSThread sleepForTimeInterval:2];
            NSLog(@"currentThread =11= %@",[NSThread currentThread]);
        }
    }
    
    if (!self.isCancelled) {
        for (int i = 0; i < 10; i ++) {
            [NSThread sleepForTimeInterval:2];
            NSLog(@"currentThread =22= %@",[NSThread currentThread]);
        }
    }

}

@end

@interface ViewController ()
@property (nonatomic,strong) NSOperationQueue *queue;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
   
    // NSInvocationOperation 创建操作
//    [self NSInvocationOperationTest];
    
    /*
     currentThread == <NSThread: 0x600001d47b80>{number = 1, name = main} param 方法参数
     currentThread == <NSThread: 0x600001d47b80>{number = 1, name = main} param 方法参数
     */

    // NSBlockOperation 创建操作
//    [self NSBlockOperationTest];
    /*
     如果一个操作中的任务数量大于1，会开子线程并发执行任务
     currentThread =3333= <NSThread: 0x600003567cc0>{number = 7, name = (null)}
     currentThread == <NSThread: 0x600003502d40>{number = 1, name = main}
     currentThread =1111= <NSThread: 0x600003557180>{number = 5, name = (null)}
     currentThread =2222= <NSThread: 0x60000355c040>{number = 4, name = (null)}
     currentThread =3333= <NSThread: 0x600003567cc0>{number = 7, name = (null)}
     currentThread =2222= <NSThread: 0x60000355c040>{number = 4, name = (null)}
     currentThread == <NSThread: 0x600003502d40>{number = 1, name = main}
     currentThread =1111= <NSThread: 0x600003557180>{number = 5, name = (null)}
     */
    
    // 使用 addOperation: 将操作加入到操作队列中
//    [self addOperationToQueue];
    /*
      3---<NSThread: 0x6000034d5f80>{number = 9, name = (null)}
      currentThread =2= <NSThread: 0x60000342ad00>{number = 5, name = (null)}
      4---<NSThread: 0x600003433cc0>{number = 6, name = (null)}
      3---<NSThread: 0x6000034d5f80>{number = 9, name = (null)}
      currentThread =2= <NSThread: 0x60000342ad00>{number = 5, name = (null)}
      4---<NSThread: 0x600003433cc0>{number = 6, name = (null)}
     */
    
     // 使用 addOperationWithBlock: 将操作加入到操作队列中
//    [self addOperationWithBlockToQueue];
    
    
    // 测试最大并发数
//    [self setMaxConcurrentOperationCount];
    
    
    // 将操作添加到队列中并测试 暂停  继续  取消
//    [self addOperationToQueue];
    
//    // 在主线程调用
//    [self useCustomOperation];
//    // 在子线程调用
//    [NSThread detachNewThreadSelector:@selector(useCustomOperation) toTarget:self withObject:nil];
    
    // 测试自定义操作的取消 暂停 继续
//    [self useCustomOperation2];
    
    // 测试操作依赖和操作监听
//    [self addDependency];
    
    // 线程间通信
    [self communication];
}

#pragma mark - 线程间通信
/**
 * 线程间通信
 */
- (void)communication {

    // 1.创建队列
    NSOperationQueue *queue = [[NSOperationQueue alloc]init];

    // 2.添加操作
    [queue addOperationWithBlock:^{
        // 异步进行耗时操作
        for (int i = 0; i < 2; i++) {
            [NSThread sleepForTimeInterval:2]; // 模拟耗时操作
            NSLog(@"1---%@", [NSThread currentThread]); // 打印当前线程
        }

        // 回到主线程
        [[NSOperationQueue mainQueue] addOperationWithBlock:^{
            // 进行一些 UI 刷新等操作
            for (int i = 0; i < 2; i++) {
                [NSThread sleepForTimeInterval:2]; // 模拟耗时操作
                NSLog(@"2---%@", [NSThread currentThread]); // 打印当前线程
            }
        }];
    }];
}

#pragma mark - NSOperation 优先级


#pragma mark - addDependency 操作依赖 和 操作监听
// 有 A、B 两个操作，其中 A 执行完操作，B 才能执行操作。
/**
 * 操作依赖
 * 使用方法：addDependency:
 */
- (void)addDependency {

    // 1.创建队列
    NSOperationQueue *queue = [[NSOperationQueue alloc] init];

    // 2.创建操作
    NSBlockOperation *op1 = [NSBlockOperation blockOperationWithBlock:^{
        for (int i = 0; i < 2; i++) {
            [NSThread sleepForTimeInterval:2]; // 模拟耗时操作
            NSLog(@"1---%@", [NSThread currentThread]); // 打印当前线程
        }
    }];
    NSBlockOperation *op2 = [NSBlockOperation blockOperationWithBlock:^{
        for (int i = 0; i < 2; i++) {
            [NSThread sleepForTimeInterval:2]; // 模拟耗时操作
            NSLog(@"2---%@", [NSThread currentThread]); // 打印当前线程
        }
    }];
    NSBlockOperation *op3 = [NSBlockOperation blockOperationWithBlock:^{
           for (int i = 0; i < 2; i++) {
               [NSThread sleepForTimeInterval:2]; // 模拟耗时操作
               NSLog(@"3---%@", [NSThread currentThread]); // 打印当前线程
           }
       }];

    // 3.添加依赖
    // 不能循环依赖
    // 可以跨队列依赖
    [op2 addDependency:op1]; // 让op2 依赖于 op1，则先执行op1，在执行op2
    [op1 addDependency:op3];

    // 优先级不能取代依赖关系 (还是按照依赖执行)，依赖必须是在同一个队列内，不能跨队列依赖
//    op2.queuePriority = NSOperationQueuePriorityVeryHigh;
//    op1.queuePriority = NSOperationQueuePriorityNormal;
    
    // 操作监听
    op3.completionBlock = ^{
        NSLog(@" 操作 op3 执行完了 %@",[NSThread currentThread]);
    };
    
    // 4.添加操作到队列中
    [queue addOperation:op1];
    [queue addOperation:op2];
    [queue addOperation:op3];
}

#pragma mark - MaxConcurrentOperationCount 最大并发操作数
// 同一时间，有多少个任务可以执行
- (void)setMaxConcurrentOperationCount {

    // 1.创建队列
    NSOperationQueue *queue = [[NSOperationQueue alloc] init];

    // 2.设置最大并发操作数 (可以控制是串行 还是 并发 队列)  具体的线程开销是有系统决定的
    // >1 并发队列  =1 串行队列  =0 不执行任务  =-1 特殊意义，最大值，不受限制
//    queue.maxConcurrentOperationCount = 1; // 串行队列
    queue.maxConcurrentOperationCount = 2; // 并发队列
//    queue.maxConcurrentOperationCount = 8; // 并发队列

    // 3.添加操作
    [queue addOperationWithBlock:^{
        for (int i = 0; i < 2; i++) {
            [NSThread sleepForTimeInterval:2]; // 模拟耗时操作
            NSLog(@"1---%@", [NSThread currentThread]); // 打印当前线程
        }
    }];
    [queue addOperationWithBlock:^{
        for (int i = 0; i < 2; i++) {
            [NSThread sleepForTimeInterval:2]; // 模拟耗时操作
            NSLog(@"2---%@", [NSThread currentThread]); // 打印当前线程
        }
    }];
    [queue addOperationWithBlock:^{
        for (int i = 0; i < 2; i++) {
            [NSThread sleepForTimeInterval:2]; // 模拟耗时操作
            NSLog(@"3---%@", [NSThread currentThread]); // 打印当前线程
        }
    }];
    [queue addOperationWithBlock:^{
        for (int i = 0; i < 2; i++) {
            [NSThread sleepForTimeInterval:2]; // 模拟耗时操作
            NSLog(@"4---%@", [NSThread currentThread]); // 打印当前线程
        }
    }];
}


#pragma mark - 将操作放到队列中 (并测试 暂停 继续  取消 )
/*
 NSOperationQueue
 主队列：   [NSOperationQueue mainQueue] 和 GCD 的主队列一样 串行队列
 非主队列： [[NSOperationQueue alloc] init]  比较特殊(同时具备并发和串行的功能)
    默认情况下，非主队列是并发队列
 
 队列中的任务的状态：已经执行完毕状态 | 正在执行状态 | 排队等待状态
*/

///  使用 addOperation: 将操作加入到操作队列中
- (void)addOperationToQueue {
    // 1.创建队列
    self.queue = [[NSOperationQueue alloc] init];
    
    // 测试串行队列
    [self.queue setMaxConcurrentOperationCount:1];
    
    // 2.创建操作
    // 使用 NSInvocationOperation 创建操作1
    NSInvocationOperation *op1 = [[NSInvocationOperation alloc] initWithTarget:self selector:@selector(task:) object:nil];

    // 使用 NSInvocationOperation 创建操作2
    NSInvocationOperation *op2 = [[NSInvocationOperation alloc] initWithTarget:self selector:@selector(task2) object:nil];

    // 使用 NSBlockOperation 创建操作3
    NSBlockOperation *op3 = [NSBlockOperation blockOperationWithBlock:^{
        for (int i = 0; i < 10; i++) {
            [NSThread sleepForTimeInterval:2]; // 模拟耗时操作
            NSLog(@"3---%@", [NSThread currentThread]); // 打印当前线程
        }
    }];
    [op3 addExecutionBlock:^{
        for (int i = 0; i < 10; i++) {
            [NSThread sleepForTimeInterval:2]; // 模拟耗时操作
            NSLog(@"4---%@", [NSThread currentThread]); // 打印当前线程
        }
    }];

    // 3.使用 addOperation: 添加所有操作到队列中
    // 内部已经调用了 strat 方法
    [self.queue addOperation:op1]; // [op1 start]
    [self.queue addOperation:op2]; // [op2 start]
    [self.queue addOperation:op3]; // [op3 start]
}

// 暂停 是可以恢复的
// 不能暂停当前正在执行的任务 暂停的是之后的任务
-(IBAction)suspendClick:(id)sender {
    [self.queue setSuspended:YES];
}
// 继续  继续执行
-(IBAction)goOnClick:(id)sender {
    [self.queue setSuspended:NO];
}
// 取消 不可以恢复
// 不可以取消当前正在执行的任务 取消的是之后的任务
-(IBAction)cancleClick:(id)sender {
    // cancelAllOperations 方法的底层是调用了队列中的所有任务的 cancle 方法
    [self.queue cancelAllOperations];
}

/**
 * 使用 addOperationWithBlock: 将操作加入到操作队列中
 */

- (void)addOperationWithBlockToQueue {
    // 1.创建队列
    NSOperationQueue *queue = [[NSOperationQueue alloc] init];

    // 2.使用 addOperationWithBlock: 添加操作到队列中
    [queue addOperationWithBlock:^{
        for (int i = 0; i < 2; i++) {
            [NSThread sleepForTimeInterval:2]; // 模拟耗时操作
            NSLog(@"1---%@", [NSThread currentThread]); // 打印当前线程
        }
    }];
    [queue addOperationWithBlock:^{
        for (int i = 0; i < 2; i++) {
            [NSThread sleepForTimeInterval:2]; // 模拟耗时操作
            NSLog(@"2---%@", [NSThread currentThread]); // 打印当前线程
        }
    }];
    [queue addOperationWithBlock:^{
        for (int i = 0; i < 2; i++) {
            [NSThread sleepForTimeInterval:2]; // 模拟耗时操作
            NSLog(@"3---%@", [NSThread currentThread]); // 打印当前线程
        }
    }];
}

#pragma mark - 自定义 NSOperation

- (void)useCustomOperation {
    TestOperation *operation = [[TestOperation alloc] init];
    [operation start];
}

// 测试自定义操作的取消 暂停 继续
- (void)useCustomOperation2 {
    
    self.queue = [[NSOperationQueue alloc] init];
    
    [self.queue setMaxConcurrentOperationCount:1];
    
    TestOperation *operation = [[TestOperation alloc] init];
    
    [self.queue addOperation:operation];
}

#pragma mark - NSBlockOperation 创建操作
// 如果一个操作中的任务数量大于1，会开子线程并发执行任务

- (void)NSBlockOperationTest{
    // 1、创建 NSBlockOperation 对象
    NSBlockOperation *operation = [NSBlockOperation blockOperationWithBlock:^{
        for (int i = 0 ; i < 2; i ++) {
            [NSThread sleepForTimeInterval:2.0]; // 模拟耗时
            NSLog(@"currentThread == %@",[NSThread currentThread]);
        }
    }];
    
    [operation addExecutionBlock:^{
        for (int i = 0 ; i < 2; i ++) {
                   [NSThread sleepForTimeInterval:2.0]; // 模拟耗时
                   NSLog(@"currentThread =1111= %@",[NSThread currentThread]);
               }
    }];
    [operation addExecutionBlock:^{
        for (int i = 0 ; i < 2; i ++) {
                   [NSThread sleepForTimeInterval:2.0]; // 模拟耗时
                   NSLog(@"currentThread =2222= %@",[NSThread currentThread]);
               }
    }];
    [operation addExecutionBlock:^{
           for (int i = 0 ; i < 2; i ++) {
                      [NSThread sleepForTimeInterval:2.0]; // 模拟耗时
                      NSLog(@"currentThread =3333= %@",[NSThread currentThread]);
                  }
       }];
    //2、调用 start 方法开始执行操作
    [operation start];
}

#pragma mark - NSInvocationOperation 创建操作

- (void)NSInvocationOperationTest{
    // 1.创建 NSInvocationOperation 对象
    NSInvocationOperation *operation = [[NSInvocationOperation alloc] initWithTarget:self selector:@selector(task:) object:@"param 方法参数"];
    //2.调用 start 方法开始执行操作
    [operation start];
}

- (void)task:(NSString *)param {
    for (int i = 0 ; i < 2; i ++) {
        [NSThread sleepForTimeInterval:2.0]; // 模拟耗时
        NSLog(@"currentThread ==1 ==  %@ %@",[NSThread currentThread],param);
    }
}
- (void)task2 {
    for (int i = 0 ; i < 10; i ++) {
        [NSThread sleepForTimeInterval:2.0]; // 模拟耗时
        NSLog(@"currentThread =2= %@",[NSThread currentThread]);
    }
}

@end


