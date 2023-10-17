//
//  ViewController.m
//  52-NSTimer 保留目标对象的问题
//
//  Created by WTW on 2020/4/3.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"
#import "TestViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.navigationController pushViewController:[TestViewController new] animated:YES];
}

@end
