//
//  ViewController.m
//  44-以下代码运行结果如何？
//
//  Created by WTW on 2020/3/14.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSLog(@"1");
    dispatch_sync(dispatch_get_main_queue(), ^{
        NSLog(@"2");
    });
    NSLog(@"3");
}


@end
