//
//  TestViewController.m
//  WKWebViewDemo
//
//  Created by WTW on 2020/3/25.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "TestViewController.h"
#import "ViewController.h"

@interface TestViewController ()

@end

@implementation TestViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.navigationController pushViewController:[ViewController new] animated:YES];
}

@end
