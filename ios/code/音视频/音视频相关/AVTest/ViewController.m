//
//  ViewController.m
//  音视频相关
//
//  Created by WTW on 2020/3/17.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    
    __block int a = 10;
    void(^block)(void) = ^{
        NSLog(@"== %d",a);
    };
    a = 20;
    block();
    
}


@end
