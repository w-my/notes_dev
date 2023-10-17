//
//  ViewController.m
//  RunLoop 基本概念
//
//  Created by WTW on 2019/8/15.
//  Copyright © 2019 wtw. All rights reserved.
//

/*
 应用范畴：
 定时器（Timer）、PerformSelector
 GCD Async Main Queue
 事件响应、手势识别、界面刷新
 网络请求
 AutoreleasePool
 */

/**
 * 一个RunLoop包含若干个Mode，每个Mode包含若干个Source/Timer/Observer/Port。
 * 当启动一个RunLoop时会先指定一个Mode，检查指定Mode是否存在以及Mode中是否含有Source和Timer，
 * 如果Mode不存在或者Mode中无Source和Timer，认为该Mode是一个空的Mode，RunLoop就直接退出
 */

#import "ViewController.h"

@interface ViewController ()

@property (nonatomic,strong) NSTimer *timer;

@end

@implementation ViewController

void observeRunLoopActicities(CFRunLoopObserverRef observer, CFRunLoopActivity activity, void *info) {
    switch (activity) {
        case kCFRunLoopEntry:
            NSLog(@"kCFRunLoopEntry == 即将进入RunLoop");
            break;
       case kCFRunLoopBeforeTimers:
            NSLog(@"kCFRunLoopBeforeTimers == 即将处理timer");
            break;
       case kCFRunLoopBeforeSources:
            NSLog(@"kCFRunLoopBeforeSources == 即将处理source");
            break;
        case kCFRunLoopBeforeWaiting:
            NSLog(@"kCFRunLoopBeforeWaiting == 即将进入休眠");
            break;
        case kCFRunLoopAfterWaiting:
            NSLog(@"kCFRunLoopAfterWaiting == 即将从休眠中唤醒");
            break;
        case kCFRunLoopExit:
            NSLog(@"kCFRunLoopExit == 退出RunLoop");
            break;
        default:
            break;
    }
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.

#pragma mark - 获取Runloop对象
/**
 *  获取主线程的RunLoop
 *  [NSRunLoop mainRunLoop];  // Foundation
 *  CFRunLoopGetMain();  // CoreFounation
 *
 *  获取当前线程的RunLoop
 *  [NSRunLoop currentRunLoop];
 *  CFRunLoopGetCurrent();
 *
 *  转换 [NSRunLoop mainRunLoop].getCFRunLoop
 */
    
//    NSLog(@"😁😁currentRunLoop:%@ \n 😁😁mainRunLoop: %@",[NSRunLoop currentRunLoop],[NSRunLoop mainRunLoop]);
//    NSLog(@"😁😁CFRunLoopGetCurrent:%@ \n 😁😁CFRunLoopGetMain：%@",CFRunLoopGetCurrent() ,CFRunLoopGetMain());

/**
 * 主线程默认注册了5个mode
 * kCFRunLoopDefaultMode  默认 Mode，通常主线程是在这个 Mode 下运行的
 * UITrackingRunLoopMode  界面跟踪 Mode，用于 ScrollView 追踪触摸滑动，保证界面滑动时不受其他 Mode 影响
 * UIInitializationRunLoopMode  启动 App 时进入的第一个 Mode，启动完成后就不再使用
 * GSEventReceiveRunLoopMode 接受系统事件的内部 Mode，通常用不到
 * kCFRunLoopCommonModes  Default模式和UI模式之间切换使用
 */
    
#pragma mark RunLoop 与线程的关系
    /**
     * RunLoop 和线程的关系
     * 每个线程都有唯一的一个与之对应的RunLoop 对象(一一对应)
     * RunLoop保存在一个全局的Dictionary里，线程作为key，RunLoop作为value
     * 主线程的Runloop 已经自动创建，但是子线程的RunLoop 需要手动创建(第一次获取时创建  [NSRunLoop currentRunLoop])
     * RunLoop 在第一次获取时创建，在线程结束时销毁,子线程默认没有开启 RunLoop 
     */
    // 创建一个子线程
//    [[[NSThread alloc] initWithTarget:self selector:@selector(run) object:nil] start];
  
#pragma mark - RunLoop 相关类
    //CFRunLoopRef   RunLoop 对象
    //CFRunLoopModeRef   RunLoop 运行模式
    //CFRunLoopSourceRef  RunLoop 输入源/事件源
    //CFRunLoopTimerRef   RunLoop 定时源
    //CFRunLoopObserverRef  观察者，监听 RunLoop 状态的改变
    
#pragma mark - CFRunLoopTimerRef
    
    // 需要手动加入到RunLoop 才会执行 且RunLoop Mode 为 NSRunLoopCommonModes
//    self.timer = [NSTimer timerWithTimeInterval:1 target:self selector:@selector(testTimer) userInfo:nil repeats:YES];
//    [[NSRunLoop currentRunLoop] addTimer:self.timer forMode:NSRunLoopCommonModes];
    
    
    // 不需要手动添加到RunLoop 中，方法内部会自动以 Defalut 模式添加到RunLoop 中
//    self.timer = [NSTimer scheduledTimerWithTimeInterval:1.0 target:self selector:@selector(testTimer) userInfo:nil repeats:YES];
    
    
    // 子线程开启定时器 需要手动创建 RunLoop (调用 [NSRunLoop currentRunLoop]，并开启)
//    [NSThread detachNewThreadWithBlock:^{
//        NSRunLoop *runLoop = [NSRunLoop currentRunLoop];
//        [NSTimer scheduledTimerWithTimeInterval:1.0 target:self selector:@selector(testTimer) userInfo:nil repeats:YES];
//        [runLoop run];
//    }];
    
#pragma mark - CFRunLoopObserverRef
    
    /*
    typedef CF_OPTIONS(CFOptionFlags, CFRunLoopActivity) {
        kCFRunLoopEntry = (1UL << 0),           //即将进入RunLoop
        kCFRunLoopBeforeTimers = (1UL << 1),    //即将处理timer 之前
        kCFRunLoopBeforeSources = (1UL << 2),   //即将处理source 之前
        kCFRunLoopBeforeWaiting = (1UL << 5),   //即将进入休眠
        kCFRunLoopAfterWaiting = (1UL << 6),    //刚从休眠中唤醒
        kCFRunLoopExit = (1UL << 7),            //退出RunLoop
        kCFRunLoopAllActivities = 0x0FFFFFFFU   //所有的活动
    };
     */
    
    // 手动添加 Observer  监听 RunLoop 的所有状态 (方式1)
    //kCFRunLoopCommonModes 默认包括 kCFRunLoopDefaultMode 、 UITrackingRunLoopMode
    //kCFRunLoopAllActivities 监听所有的状态
    CFRunLoopObserverRef observer = CFRunLoopObserverCreate(kCFAllocatorDefault, kCFRunLoopAllActivities, YES, 0, observeRunLoopActicities, NULL);

    //添加Observer 到 RunLoop 中
    // 第一个参数 : 要监听哪个 RunLoop
    // 第二个参数 : 观察者
    // 第三个参数 : 运行模式
    CFRunLoopAddObserver(CFRunLoopGetMain(), observer, kCFRunLoopCommonModes);
      //释放 observer
    CFRelease(observer);
    
    
    // 手动添加 Observer  监听 RunLoop 的所有状态 (方式 2)
    // 第一个参数：怎么分配内存空间
    // 第二个参数：要监听的状态 kCFRunLoopAllActivities 所有的状态
    // 第三个参数：是否持续监听
    // 第四个参数：优先级，传0
    // 第五个参数：当状态改变时候的回调
//    CFRunLoopObserverRef observer = CFRunLoopObserverCreateWithHandler(kCFAllocatorDefault, kCFRunLoopAllActivities, YES, 0, ^(CFRunLoopObserverRef observer, CFRunLoopActivity activity) {
//        switch (activity) {
//            case kCFRunLoopEntry:{
//                // 模式的切换
//                CFRunLoopMode mode = CFRunLoopCopyCurrentMode(CFRunLoopGetCurrent());
//                NSLog(@"kCFAllocatorDefault == %@",mode);
//                CFRelease(mode);
//            }
//                break;
//            case kCFRunLoopExit:{
//                // 模式的切换
//                CFRunLoopMode mode = CFRunLoopCopyCurrentMode(CFRunLoopGetCurrent());
//                NSLog(@"kCFRunLoopExit == %@",mode);
//                CFRelease(mode);
//            }
//                break;
//            default:
//                break;
//        }
//    });
    // 第一个参数 : 要监听哪个 RunLoop
    // 第二个参数 : 观察者
    // 第三个参数 : 运行模式
//    CFRunLoopAddObserver(CFRunLoopGetMain(), observer, kCFRunLoopCommonModes);
    //释放 observer
//    CFRelease(observer);

//    kCFRunLoopExit == kCFRunLoopDefaultMode
//    kCFAllocatorDefault == UITrackingRunLoopMode
//    kCFRunLoopExit == UITrackingRunLoopMode
//    kCFAllocatorDefault == kCFRunLoopDefaultMode

#pragma mark  - 运行逻辑
    
    /*
     
     */
    
// RunLoop 中的处理 Blocks 就是这样添加的block
//    CFRunLoopPerformBlock(<#CFRunLoopRef rl#>, <#CFTypeRef mode#>, ^{
//
//    });
    
#pragma mark - GCD 一般不依赖 RunLoop , 但是只有如下情况是需要 RunLoop 的
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        dispatch_async(dispatch_get_main_queue(), ^{
            NSLog(@"这种情况下是需要依赖RunLoop的");  // __CFRUNLOOP_IS_SERVICING_THE_MAIN_DISPATCH_QUEUE__
        });
    });
}

//lldb bt 查看调用栈
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    NSLog(@"=== %s === ",__func__);
    
//    [NSTimer scheduledTimerWithTimeInterval:3 repeats:NO block:^(NSTimer * _Nonnull timer) {
//        NSLog(@" ==== timer ==== ");
//    }];
}

- (void)run {
    
    // 在子线程中创建RunLoop 使用 [NSRunLoop currentRunLoop]
    // [NSRunLoop currentRunLoop] 是懒加载的，如果当前线程的 runloop 不存在就会创建一个 runloop 存在就不会再创建
    NSLog(@"%@",[NSRunLoop currentRunLoop]);
    //<NSThread: 0x600002277d00>{number = 7, name = (null)}
    NSLog(@"%@",[NSThread currentThread]);
}

- (void)testTimer {
    NSLog(@" == %@ == ",[NSThread currentThread]);
}

@end
