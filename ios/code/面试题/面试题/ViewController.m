//
//  ViewController.m
//  面试题
//
//  Created by WTW on 2020/3/11.
//  Copyright © 2020 WTW. All rights reserved.
//

// 1、为什么在主线程刷新UI? 为什么刷新UI 需要在主线程？在子线程能刷新 UI 吗？会有什么问题？
// 2、通知里面接收的方法所在的线程一定是主线程吗？比如子线程发送通知，接收通知的时候是在主线程还是子线程？ (发送通知的线程，所以在处理通知的时候一定要注意是在主线程还是子线程，如果是子线程需要切换到主线程才能更新UI)
// 3、js 的跨越问题是怎么产生的？怎么解决 js 跨越的问题？
// 4、3个线层 并发10个下载任务，怎么处理？
// 5、开发中域名解析出错了怎么办？
// 6、GCD 和 NSOperation 的区别在哪里？什么时候用 GCD ? 什么时候用 NSOperation ？
// 7、strong weak 和 assign 的区别？ 为什么 assign 修饰的对像类型不会自动置为nil,会照成野指针？weak为什么不会？
// 8、git 中rebase 和 merge 的区别是什么？
// 9、如果让你设计一个消息的通知中心，你会怎么设计？
// 10、苹果支付和支付宝支付的完整流程是什么样的？
// 11、二分查找算的是怎么实现的？
// 12、事件的传递机制和响应机制？
// 13、https 和 http 的区别？ https 的实现机制？
// 14、什么是三次握手，四次挥手？为什么要这样设计？
// 15、列表滑动的优化方案？


#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
       
        NSLog(@"%@",[NSThread currentThread]);
        
        [NSNotificationCenter.defaultCenter postNotificationName:@"notiTest" object:nil];
        
    });
    
    [NSNotificationCenter.defaultCenter addObserver:self selector:@selector(noti) name:@"notiTest" object:nil];
}

- (void)noti {
    NSLog(@" == %@ == ",[NSThread currentThread]);
}

#pragma mark - 为什么在主线程刷新UI? 为什么刷新UI 需要在主线程？在子线程能刷新UI 吗？会有什么问题？
/**
 * UIKit 不是线程安全的，假如两个子线程中设置了同一张背景图片，很有可能会由于背景图片释放两次，导致程序崩溃
 * 或者一个线层在遍历寻找某个 subview 而另一个线程中删除了这个 subview 这样就导致错乱
 *
 * 事实上在子线程中如果要对其他UI进行更新，必须要等到该子线层运行结束
 * 在子线程中是不能进行UI 更新的，我们看到的UI更新其实是子线程代码执行完毕了，又自动进入到了主线程，执行了子线程中的UI更新的函数栈，
 * 这中间的时间非常的短，就让大家误以为分线程可以更新UI。如果子线程一直在运行，则子线程中的UI更新的函数栈 主线程无法获知，即无法更新。
 * 只有极少数的UI能直接进行UI更新，因为开辟线程时会获取当前环境，如点击某个按钮，这个按钮响应的方法是开辟一个子线程，在子线程中对该按钮进行UI 更新是能及时的，如上面的换背景图，但这没有任何意义。
 *
 *
 */


@end
