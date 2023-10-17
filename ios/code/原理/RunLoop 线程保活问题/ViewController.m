//
//  ViewController.m
//  RunLoop 线程保活问题
//
//  Created by WTW on 2019/8/16.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"
#import "RCThread.h"

@interface ViewController ()
@property (nonatomic,strong) RCThread *thread;

@property (nonatomic,assign,getter=isStoped) BOOL stoped;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // AFN 2.x 就是使用了常住线程(线程保活)
    
#pragma mark 正常情况下 执行完线程就回收了
//    NSThread * thread = [[RCThread alloc] initWithTarget:self selector:@selector(run) object:nil];
//    [thread start];

    
#pragma mark 为了观察线程的销毁过程，自定义一个类 RCThread
//    self.thread = [[RCThread alloc] initWithTarget:self selector:@selector(run) object:nil];
//    [self.thread start];
    
    
#pragma mark 线程保活 和 RunLoop 停止的方法
    // 为了测试 在线程内干别的事，需要被控制器持有保持强引用
    __weak typeof(self) weakself = self;
    self.stoped = NO;
    self.thread = [[RCThread alloc] initWithBlock:^{
        NSLog(@"begin === %@",[NSThread currentThread]);
        
        // 这样就能保证线程不会被销毁
        // 但是这样会有问题  控制器销毁的时候 线程并没有结束(线程无法销毁)
        // runloop 需要手动停掉
        [[NSRunLoop currentRunLoop] addPort:[[NSPort alloc] init] forMode:NSDefaultRunLoopMode];
       
        // 必须要验证 weakself 因为当 weakself == nil 的时候也会进来导致线程不销毁
        while (weakself && !weakself.isStoped) {
            [[NSRunLoop currentRunLoop] runMode:NSDefaultRunLoopMode beforeDate:[NSDate distantFuture]];
        }
        
        // run 方法 是无法手动停止的，它专门用于开启一个永不销毁的线程（NSRunLoop）
        /*
         it runs the receiver in the NSDefaultRunLoopMode by repeatedly(反复) invoking(调用) runMode:beforeDate:. In other words, this method effectively begins an infinite(无穷的) loop that processes data from the run loop’s input sources and timers.
         If you want the run loop to terminate(停止), you shouldn't use this method. Instead, use one of the other run methods and also check other arbitrary conditions of your own, in a loop. A simple example would be:
         BOOL shouldKeepRunning = YES; // global
         NSRunLoop *theRL = [NSRunLoop currentRunLoop];
         while (shouldKeepRunning && [theRL runMode:NSDefaultRunLoopMode beforeDate:[NSDate distantFuture]]);
         */
//        [[NSRunLoop currentRunLoop] run];
        
        NSLog(@"====== end ==== %@",[NSThread currentThread]);
    }];
    [self.thread start];
}

- (void)run {
    NSLog(@"run === %@",[NSThread currentThread]);
   
    //这样写 一样是 执行完就销毁
    // 因为默认情况下开启的线程是没有 Source\Timer\Observer 的
//    [[NSRunLoop currentRunLoop] run];
    
    //这样就能保证线程不会被销毁
    // 添加 source1 (Port)
    [[NSRunLoop currentRunLoop] addPort:[[NSPort alloc] init] forMode:NSDefaultRunLoopMode];
    [[NSRunLoop currentRunLoop] run];

    // 一直走不到这一行，证明线程在睡眠而没有销毁
    NSLog(@"====== end ==== ");
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    //在已有的线程上执行 test 方法
    //waitUntilDone : 是否等线程的方法执行完再往下执行 NO 不等待  YES 等待执行完再往下执行
    [self performSelector:@selector(test) onThread:self.thread withObject:nil waitUntilDone:NO];
    NSLog(@"test ==  waitUntilDone == ");
}

//测试子线程需要执行的任务
- (void)test {
    NSLog(@"%s == thread:%@",__func__,[NSThread currentThread]);
}

//用于停止子线程的RunLoop
- (void)stop {
    
    self.stoped = YES;
    CFRunLoopStop(CFRunLoopGetCurrent());
    NSLog(@"%s == thread:%@",__func__,[NSThread currentThread]);
}

- (void)dealloc {
    
    //必须在 子线程 手动停止 RunLoop (所以要使用 performSelector 在子线程中停止对应的runloop)
    //waitUntilDone NO 和 YES 的区别 YES 代表子线程执行完以后才会往下执行 是等待执行完才往下执行
    // 不然的话 self 会提前销毁了 所以要用 YES
    [self performSelector:@selector(stop) onThread:self.thread withObject:nil waitUntilDone:YES];
    
    //需要手动置为nil，销毁线程
    self.thread = nil;
    
    NSLog(@"%s",__func__);
}

@end
