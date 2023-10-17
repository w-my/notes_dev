//
//  ViewController.m
//  NSNotificationCenter
//
//  Created by WTW on 2020/3/14.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "ViewController.h"
#import "Observer.h"
#import "Test.h"

/*
  NSNotificationCenter 和 NSNotification 是使用观察者模式来实现的用于跨层传递消息

  通知的原理：
  实际上是 NSNotificationCenter 维护的一个 hashmap表(字典)，key 是 notificationName ，value 是 Observer 数组列表(一个通知可能有多个监听者)
 */

// http://southpeak.github.io/2015/03/20/cocoa-foundation-nsnotificationcenter/
// https://www.jianshu.com/p/356f7af4f2ee
// https://juejin.im/post/5e5fc16df265da575155723b


/*
 通知和代理的区别：
 1、代理是代理模式，传递方式是一对一
 2、通知是基于观察者模式实现的跨层传递信息的机制，传递方式是一对多
 3、通知是松耦合的，通知方不需要知道被通知放的任何情况，而代理不行
 4、通知的效率要比 deleagte 低
 */

/*
 注意点：
 1、每次 addObserver 都会在通知中心重新注册一下，即使是同一个对象，监听同一个消息，而不是去覆盖原来的监听。这样，当通知中心转发某一消息时，如果同一对象多次注册了这个通知的观察者，则会收到多个通知
 2、observer 观察者（不能为nil，通知中心会弱引用，ARC是iOS9之前是unsafe_unretained，iOS9及以后是weak，MRC是assign，所以这也是MRC不移除会crash，ARC不移除不会crash的原因）
 */

@interface ViewController ()
@property (nonatomic,strong) Observer *observer;
@property (nonatomic,strong) Test *test;
@end

static NSString *TestNotification = @"TestNotification";

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
#pragma mark - 面试题
    
    // 1、通知的实现原理
    /*
     实际上是 NSNotificationCenter 维护的一个 hashmap表(字典)，key 是 notificationName ，value 是 Observer 数组列表(一个通知可能有多个监听者)
     */
    
    // 2、这种方式能接收到通知吗？ 不能(通知必须先注册才能监听)
//    [[NSNotificationCenter defaultCenter] postNotificationName:@"NOTI_TEST" object:nil];
//    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(noti:) name:@"NOTI_TEST" object:nil];
       
    
    //3、NSNotificationCenter接受消息和发送消息是在一个线程里吗？如何异步发送消息
    /*
     是在同一个线程
     可以在指定监听的队列
     */
    
    //4、NSNotificationQueue是异步还是同步发送？在哪个线程响应
    /* 一般使用的通知都是同步的
     同步还是异步是相对于发送通知所在的线程
     */
    
    //5、NSNotificationQueue和runloop的关系
    
    // 6、如何保证通知接收的线程在主线程
    
    // 7、页面销毁时不移除通知会崩溃吗
    
    // 8、多次添加同一个通知会是什么结果？多次移除通知呢
    
    
#pragma mark - 多次监听，会在通知中心多次注册
    
    // 多次监听，即使是同一个对象，同一消息，不是去覆盖监听，都会去通知中心重新注册
//    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(noti:) name:TestNotification object:nil];
//    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(noti:) name:TestNotification object:nil];

#pragma mark - block 方式监听
    
    // iOS 4 以后提供的block 方式的监听,上面的方式的观察者是self，而block 方式会创建一个匿名的对象作为观察者,这个匿名对象会在指定的队列中执行block
    // 返回一个表示观察者的对象，不用的时候需要释放该对象
    // 如果queue为nil，则消息是默认在post线程中同步处理，即通知的post与转发是在同一线程中
    // block块会被通知中心拷贝一份(执行copy操作)，以在堆中维护一个block对象，直到观察者被从通知中心中移除。所以，应该特别注意在block中使用外部对象，避免出现对象的循环引用
    // block 内部一定要用weakself，不能使用self ，且要移除对应的监听 [[NSNotificationCenter defaultCenter] removeObserver:observer];
//    __weak typeof(self) weakSelf = self;
//    id<NSObject> observer = [[NSNotificationCenter defaultCenter] addObserverForName:TestNotification object:nil queue:nil usingBlock:^(NSNotification * _Nonnull note) {
//        NSLog(@"usingBlock: %@ == %@,内部使用self 必须是 weakSelf",note,[NSThread currentThread]);
//    }];
    
#pragma mark - name 传nil 打印出系统的所有的通知
    // name 传 nil 可以打印出程序启动系统的所有通知消息
//    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(noti:) name:nil object:nil];
    
#pragma mark - 在指定队列中接收通知
    
//    [[NSNotificationCenter defaultCenter] addObserverForName:TestNotification object:nil queue:[NSOperationQueue mainQueue] usingBlock:^(NSNotification * _Nonnull note) {
//        NSLog(@"receive thread == %@",[NSThread currentThread]);
//    }];
    
    // 默认发送和接收是在同一个线程的,可以在指定队列中接收通知
//    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(noti:) name:TestNotification object:nil];
//    dispatch_async(dispatch_get_global_queue(0, 0), ^{
//        NSLog(@"post thread == %@",[NSThread currentThread]);
//        [[NSNotificationCenter defaultCenter] postNotificationName:TestNotification object:nil];
//    });
//    /*
//      post thread == <NSThread: 0x6000039f9800>{number = 6, name = (null)}
//      receive thread == <NSThread: 0x6000039b5140>{number = 1, name = main}
//     */
    
#pragma mark - 使用block 引起的循环引用问题 (一定要移除监听)
    
//    Observer *observer = [[Observer alloc] init];
//    self.observer = observer;
//    [[NSNotificationCenter defaultCenter] postNotificationName:TestNotification object:nil];
    /*
     Init Observer
     handle notification
     handle notification
     */
    
#pragma  mark - NotificationQueues和异步通知
    /*
     NotificationQueue 通知队列，用于异步发送消息，这个异步并不是开启线程(并没有开启线程，而是在合适的时机发送，受 runloop 影响)
     而是把通知存到了双向链表实现的队列里面，等待某个时机触发时调用 NSNotificationCenter 的发送接口进行发送通知
     最终还是调用 NSNotificationCenter 进行消息的分发
     (NotificationQueue 是依赖runloop的，如果线程的 runLoop 未开启则无效)
     
     NSNotificationQueue 主要做两件事：
     1、添加通知到队列
     2、删除通知
     */
    
    // 把通知添加到队列中
//    [[NSNotificationQueue defaultQueue] enqueueNotification:<#(nonnull NSNotification *)#> postingStyle:<#(NSPostingStyle)#>]
//      [[NSNotificationQueue defaultQueue] enqueueNotification:<#(nonnull NSNotification *)#> postingStyle:<#(NSPostingStyle)#> coalesceMask:<#(NSNotificationCoalescing)#> forModes:<#(nullable NSArray<NSRunLoopMode> *)#>]
    // 删除通知
//    [[NSNotificationQueue defaultQueue] dequeueNotificationsMatching:<#(nonnull NSNotification *)#> coalesceMask:<#(NSUInteger)#>]
    
    // 队列的合并策略和发送时机
    // 把通知添加到队列等待发送，同时提供了一些附加条件选择发送时机
    /*
    // 表示通知的发送时机
    typedef NS_ENUM(NSUInteger, NSPostingStyle) {
        NSPostWhenIdle = 1, // runloop空闲时发送通知
        NSPostASAP = 2, // 尽快发送，这种情况稍微复杂，这种时机是穿插在每次事件完成期间来做的
        NSPostNow = 3 // 立刻发送或者合并通知完成之后发送
    };
    // 通知合并的策略，有些时候同名通知只想存在一个，这时候就可以用到它了
    typedef NS_OPTIONS(NSUInteger, NSNotificationCoalescing) {
        NSNotificationNoCoalescing = 0, // 默认不合并
        NSNotificationCoalescingOnName = 1, // 只要name相同，就认为是相同通知
        NSNotificationCoalescingOnSender = 2  // object相同
    };
    */
    
    // 同步还是异步是相对于发送通知所在的线程
//    Test *test = [[Test alloc] init];
//    [test test]; // 添加监听
//    [[NSNotificationCenter defaultCenter] postNotificationName:TestNotification object:nil];
//    NSLog(@"测试同步还是异步");
    // 执行结果 同步
    // selector 1 执行完才执行的 log 所以是同步的
    /*
      selector 1
      测试同步还是异步
     */
    
    //异步通知原理
    // 创建一个 NSNotificationQueue 队列，定义的 NSNotification 放入其中，并指定三种状态之一：
    //    typedef NS_ENUM(NSUInteger, NSPostingStyle) {
    //        NSPostWhenIdle = 1,      // 当runloop处于空闲状态时post
    //        NSPostASAP = 2,    // 当当前runloop完成之后立即post
    //        NSPostNow = 3    // 立刻发送或者合并通知完成之后发送
    //    };
    
    // 异步通知
//    Test *test = [[Test alloc] init];
//    [test test];
//    self.test = test;
//    NSNotification *noti = [NSNotification notificationWithName:TestNotification object:nil];
//    [[NSNotificationQueue defaultQueue] enqueueNotification:noti postingStyle:NSPostASAP];
//    //[[NSNotificationQueue defaultQueue] enqueueNotification:noti postingStyle:NSPostWhenIdle];
//    //[[NSNotificationQueue defaultQueue] enqueueNotification:noti postingStyle:NSPostNow];
//    NSLog(@"测试同步还是异步");
    /* 异步
     测试同步还是异步
     selector 1
     */
    
#pragma mark - Notification Queues的合成作用
//    NSNotificationQueue除了有异步通知的能力外，还能对当前队列的通知根据 NSNotificationCoalescing 类型进行合成(即几个合成一个)
/*
 typedef NS_OPTIONS(NSUInteger, NSNotificationCoalescing) {
     NSNotificationNoCoalescing = 0,  // 不合成
     NSNotificationCoalescingOnName = 1,  // 根据NSNotification的name字段进行合成
     NSNotificationCoalescingOnSender = 2  // 根据NSNotification的object字段进行合成
 };
 */
//    Test *a = [Test new];
//    [a test];
//    self.test = a;
//    NSNotification *noti = [NSNotification notificationWithName:TestNotification object:nil];
//    [[NSNotificationQueue defaultQueue] enqueueNotification:noti postingStyle:NSPostASAP coalesceMask:NSNotificationNoCoalescing forModes:nil];
//    [[NSNotificationQueue defaultQueue] enqueueNotification:noti postingStyle:NSPostWhenIdle coalesceMask:NSNotificationNoCoalescing forModes:nil];
//    [[NSNotificationQueue defaultQueue] enqueueNotification:noti postingStyle:NSPostNow coalesceMask:NSNotificationNoCoalescing forModes:nil];
//    NSLog(@"测试同步还是异步");
    
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
//    [[NSNotificationCenter defaultCenter] postNotificationName:TestNotification object:nil];

    
}

- (void)noti:(NSNotification *)noti {
    NSLog(@"%s == %@ == %@ == %@",__func__,noti.name,[NSThread currentThread],noti);
}

- (void)dealloc {
    
    // 添加和移除要配对出现
    /*
     这两个方法的使用时机。–removeObserver:适合于在类的dealloc方法中调用，可以确保将对象从通知中心中清除；
     而在viewWillDisappear:这样的方法中，则适合于使用-removeObserver:name:object:方法，以避免不知情的情况下移除了不应该移除的通知观察者。
  例如，假设我们的ViewController继承自一个类库的某个ViewController类(假设为SKViewController吧)，可能SKViewController自身也监听了某些通知以执行特定的操作，但我们使用时并不知道。
     如果直接在viewWillDisappear:中调用–removeObserver:，则也会把父类监听的通知也给移除
     */
    
//    [[NSNotificationCenter defaultCenter] removeObserver:self];
    
//    [[NSNotificationCenter defaultCenter] removeObserver:<#(nonnull id)#> name:<#(nullable NSNotificationName)#> object:<#(nullable id)#>]
    
    // block 方式移除监听
    [[NSNotificationCenter defaultCenter] removeObserver:self.observer];
    
    NSLog(@"===== dealloc ==== ");
}


@end
