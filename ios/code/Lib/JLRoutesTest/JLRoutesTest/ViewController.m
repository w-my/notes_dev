//
//  ViewController.m
//  JLRoutesTest
//
//  Created by wtw on 2018/9/14.
//  Copyright © 2018年 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

//https://www.jianshu.com/p/76da56b3bd55
//https://www.jianshu.com/p/d24e9a7c8d4e
//https://www.jianshu.com/p/109425367a90
- (void)viewDidLoad {
    [super viewDidLoad];
    
//     NSScanner
    
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    NSString *customURL = @"JLRoutesTestOne://SecondController/我是UserID/我是password";
    //中文需要转义
     customURL = [customURL stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLQueryAllowedCharacterSet]];
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:customURL]];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
