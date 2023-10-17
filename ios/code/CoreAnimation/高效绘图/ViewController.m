//
//  ViewController.m
//  高效绘图
//
//  Created by wtw on 2019/3/1.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"
#import "DrawingView.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    DrawingView *view = [[DrawingView alloc] initWithFrame:CGRectMake(0, 0, 300, 300)];
    view.backgroundColor = [UIColor lightTextColor];
    [self.view addSubview:view];
}


@end
