//
//  ViewController.m
//  51-精简initialize 与 load 的实现代码
//
//  Created by WTW on 2020/4/3.
//  Copyright © 2020 WTW. All rights reserved.
//

/*
 有时候类必须先执行某些初始化操作，才能正常使用，这就引入了 initialize 和 load
 
 load 应用程序启动的时候调用 (runtime装载 类 与 分类的时候)，且仅调用一次
 */

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}


@end
