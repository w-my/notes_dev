//
//  ViewController.m
//  内存管理-定时器
//
//  Created by WTW on 2019/8/8.
//  Copyright © 2019 wtw. All rights reserved.
//

// CADisplayLink、NSTimer会对target产生强引用，如果target又对它们产生强引用，那么就会引发循环引用
// NSTimer依赖于RunLoop，如果RunLoop的任务过于繁重，可能会导致NSTimer不准时
// 而GCD的定时器会更加准时

/*
 循环引用的问题：
    关于 NStimer 的循环引用解决方案：
        1、 使用 block iOS 10 以后的 API
            + (NSTimer *)scheduledTimerWithTimeInterval:(NSTimeInterval)interval repeats:(BOOL)repeats block:(void (^)(NSTimer *timer))block
        2、 通过代理对象 (NSProxy) (消息转发)   NSTimer强引用 代理对象 代理对象弱引用 self
 NSTimer 不准时的问题：
    使用 GCD 定时器更加准确
*/

#import "ViewController.h"
#import "RCTimer.h"
#import "RCProxy.h"
#import "NSTimer+RCTimer.h"

@interface ViewController ()

@property (nonatomic,strong) CADisplayLink *link;
@property (nonatomic,strong) NSTimer *timer;
//@property (nonatomic,strong) dispatch_source_t dis_timer;

@property (nonatomic,strong) NSString *task;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
#pragma mark - NSTimer & CADisplayLink 都会引起循环引用
    
    //保证调用频率和屏幕的帧刷新频率一致 60FPS
    // CADisplayLink
    //self 强引用 link   link 强引用 self 会有循环引用问题
//    self.link = [CADisplayLink displayLinkWithTarget:self selector:@selector(linkTest)];
//    [self.link addToRunLoop:[NSRunLoop mainRunLoop] forMode:NSDefaultRunLoopMode];
    
    // NSTimer
//    self.timer = [NSTimer scheduledTimerWithTimeInterval:1 target:self selector:@selector(timerTest) userInfo:nil repeats:YES];
    
#pragma mark - NSTimer 解决方案一  (iOS 10 以后可以用)

//    __weak typeof(self) weakSelf = self;
//    self.timer = [NSTimer scheduledTimerWithTimeInterval:1 repeats:YES block:^(NSTimer * _Nonnull timer) {
//        [weakSelf timerTest];
//    }];
  
#pragma mark - 解决方案二 NSProxy
    
    //NSTimer
//    self.timer = [NSTimer scheduledTimerWithTimeInterval:1.0 target:[RCProxy proxyWithTarget:self] selector:@selector(timerTest) userInfo:nil repeats:YES];
    
    // CADisplayLink
//    self.link = [CADisplayLink displayLinkWithTarget:[RCProxy proxyWithTarget:self] selector:@selector(linkTest)];
//    [self.link addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSRunLoopCommonModes];
    
    
#pragma mark - 解决方案三 给 NSTimer 添加分类
    
//    self.timer = [NSTimer timerWithTimeInterval:1.0 block:^{
//        NSLog(@" == NSTimer == ");
//    } repeats:YES];
//    [[NSRunLoop currentRunLoop] addTimer:self.timer forMode:NSRunLoopCommonModes];
    
#pragma mark - GCD 定时器 (GCD定时器与系统内核有关，更加准确 不受 Runloop 影响)
    // NSTimer 和 CADisplayLink 都是依赖 RunLoop的，如果定时器的任务比较复杂就可能会导致定时器不准时
    // RunLoop 的一个循环的时间不是固定的，所以可能会导致不准时
    
//    //队列
//    dispatch_queue_t queue = dispatch_get_main_queue();
//    //创建定时器
//    self.dis_timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, queue);
//    //设置时间
//    uint64_t start = 2; // 2 秒后开始执行
//    uint64_t interval = 1; // 每隔一秒执行
//    dispatch_source_set_timer(self.dis_timer,
//                              dispatch_time(DISPATCH_TIME_NOW, start * NSEC_PER_SEC),
//                              interval * NSEC_PER_SEC, 0);  //误差为0
////    //设置回调 block 回调
////    dispatch_source_set_event_handler(self.dis_timer, ^{
////        NSLog(@"1111");
////    });
//    
//    //函数形式回调
//    dispatch_source_set_event_handler_f(self.dis_timer, timerFire);
//    //启动定时器
//    dispatch_resume(self.dis_timer);
    
#pragma mark - 封装 GCD 方式定时器
    
    __weak typeof(self) weakSelf = self;
    self.task = [RCTimer execTask:^{
        [weakSelf timerTest];
    }
                          start:0
                       interval:1
                        repeats:YES
                          async:YES];
    
//     self.task = [RCTimer execTask:self selector:@selector(timerTest) start:0 interval:2 repeats:YES async:YES];
 
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [RCTimer cancelTask:self.task];
}

//void timerFire(void *param) {
//    NSLog(@"2222");
//}

// 一般情况下一秒钟调用 60 次
- (void)linkTest {
    NSLog(@"%s",__func__);
}

- (void)timerTest {
    NSLog(@"%s",__func__);
    NSLog(@"%@",self.task);
}

- (void)dealloc {
    [self.link invalidate];
    [self.timer invalidate];
    [RCTimer cancelTask:self.task];
}

@end
