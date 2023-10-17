//
//  ViewController.m
//  RunLoop卡顿监测
//
//  Created by WTW on 2022/2/24.
//  Copyright © 2022 wtw. All rights reserved.
//

#import "ViewController.h"

/*
  监控卡顿线程思路：
 1、首先创建一个观察者 runLoopObserver 用于观察主线程的 runloop 状态，同时还要创建一个信号量 dispatchSemaphore 用户保证同步操作；
 2、其次将观察者 runLoopObserver 添加到主线程的runloop 中观察；
 3、然后开启一个子线程，并在子线程中开启一个持续的 loop 来监控主线程的 loop 状态；
 4、如果发现主线程的 loop 状态卡在 BeforeSources 或者 AfterWaiting 超过 88 毫秒，即表示主线程当前卡顿；
 5、保存主线程当前的调用堆栈即达到监控的目的；
 */


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}


@end
