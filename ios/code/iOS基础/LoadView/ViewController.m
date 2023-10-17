//
//  ViewController.m
//  LoadView
//
//  Created by WTW on 2020/2/10.
//  Copyright © 2020 WTW. All rights reserved.
//

/*
 loadView 的作用：用来创建控制器的View
 调用时机： 当控制器的View 第一次使用的时候调用
 loadView 的底层原理：
 1、先判断当前控制器是不是从 sb 中加载的，如果是那么就会从 sb 中加载控制器的 View ，设置当前控制器的View
 2、当前控制是不是从 xib 中加载的，如果是把 xib 当中指定的View 设置为当前控制器的View
 3、如果也不是 xib 加载的，就会创建空白的 view (控制器的颜色是透明的)

 一旦自己重写了 loadView 就说明自己要自定义 View
 */

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
//    UIView *v = [[UIView alloc] initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height)];
//    [self.view addSubview:v];
    
//    NSLog(@"%@ == %zd",self.view,self.view.tag);
    
    NSLog(@"%s",__func__);
}

// 一旦自己重写了 loadView 就说明自己要自定义 View
- (void)loadView {
    
    UIView *v = [[UIView alloc] initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height)];
    v.tag = 10;
    v.backgroundColor = [UIColor redColor];
    self.view = v;
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    NSLog(@"%s",__func__);
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    NSLog(@"%s",__func__);
}

- (void)viewWillLayoutSubviews {
    [super viewWillLayoutSubviews];
    NSLog(@"%s",__func__);
}

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    NSLog(@"%s",__func__);
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    NSLog(@"%s",__func__);
}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    NSLog(@"%s",__func__);
}

/*
 2020-02-10 23:37:17.754911+0800 LoadView[33151:1995365] -[ViewController viewDidLoad]
 2020-02-10 23:37:17.768026+0800 LoadView[33151:1995365] -[ViewController viewWillAppear:]
 2020-02-10 23:37:17.772837+0800 LoadView[33151:1995365] -[ViewController viewWillLayoutSubviews]
 2020-02-10 23:37:17.773013+0800 LoadView[33151:1995365] -[ViewController viewDidLayoutSubviews]
 2020-02-10 23:37:17.803754+0800 LoadView[33151:1995365] -[ViewController viewDidAppear:]
 */

@end
