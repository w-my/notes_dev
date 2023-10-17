//
//  TestViewController.m
//  52-NSTimer 保留目标对象的问题
//
//  Created by WTW on 2020/4/3.
//  Copyright © 2020 WTW. All rights reserved.
//

/*
 计时器与runloop 相关联，运行循环到时候才会触发任务，只有将计时器放到运行循环中才能正常触发任务
 这样如果runloop 的某一个循环时间比较长，很难保证时间的准确性，即 NSTimer 并不真正准时
 */

/*
 反复执行任务的计时器，很容易引入循环引用，如果这种计时器的目标对象又保留了计时器本身，那就回导致保留环。这种保留关系可能是直接发生的，也可能是通过对象图里面的其他对象间接发生的
 解决办法：
 1、可以通过创建timer的分类使用 block 打破引用
 2、可以使用 NSProxy 代理，打断引用
 3、可以使用 iOS 10 以后的 API (block 形式)
 4、自定义计时器 (基于GCD GCD 是基于 dispatch port 方式，不受 runloop 影响)
 */

#import "TestViewController.h"
#import "EOCClass.h"

@interface TestViewController ()
{
    EOCClass *_eocCls;
    NSTimer *_onceTimer;
}
@end

@implementation TestViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor greenColor];
    
    // 一次性的计数器在触发完成任务后也会失效
    _onceTimer = [NSTimer scheduledTimerWithTimeInterval:1.0 target:self selector:@selector(doOnceSomething) userInfo:nil repeats:NO];
    
    _eocCls = [[EOCClass alloc] init];
    [_eocCls startPolling];
        
}

- (void)doOnceSomething {
    NSLog(@"一次任务");
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [_eocCls stopPolling];
}

- (void)dealloc {
    NSLog(@"%s",__func__);
}

@end
