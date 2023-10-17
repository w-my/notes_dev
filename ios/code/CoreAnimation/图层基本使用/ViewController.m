//
//  ViewController.m
//  图层基本使用
//
//  Created by wtw on 2019/1/8.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    CALayer *blueLayer = [CALayer layer];
    blueLayer.frame = CGRectMake(50, 50, 100, 100);
    blueLayer.backgroundColor = [UIColor blueColor].CGColor;
    [self.view.layer addSublayer:blueLayer];
    
}


@end
