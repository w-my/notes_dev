//
//  XMGRootViewController.m
//  01.WeChat(EaseMobSDK导入)
//
//  Created by 肖剑 on 15/12/1.
//  Copyright © 2015年 肖剑. All rights reserved.
//

#import "XMGRootController.h"
@interface XMGRootController ()

@end

@implementation XMGRootController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // 初始化添加内容的view
    XMGContentView *contentView = [[XMGContentView alloc]init];
    contentView.backgroundColor = [UIColor whiteColor];
    contentView.showsHorizontalScrollIndicator = NO;
    contentView.showsVerticalScrollIndicator = NO;
    contentView.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height);
    [self.view addSubview:contentView];
    self.contentView = contentView;
}

@end
