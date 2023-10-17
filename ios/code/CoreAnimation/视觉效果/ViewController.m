//
//  ViewController.m
//  视觉效果
//
//  Created by wtw on 2019/1/9.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.

    [self test3];
}

//组透明
/*
 UIView   alpha
 CALayer  opacity
 */
- (void)test3 {
 
    self.view.backgroundColor = [UIColor lightGrayColor];
    
    UIButton *button1 = [[UIButton alloc] initWithFrame:CGRectMake(100, 100, 200, 60)];
    button1.backgroundColor = [UIColor whiteColor];
    [button1 setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    button1.titleLabel.font = [UIFont systemFontOfSize:26];
    [button1 setTitle:@"Hello world1" forState:UIControlStateNormal];
    [self.view addSubview:button1];
    
    UIButton *button2 = [[UIButton alloc] initWithFrame:CGRectMake(100, 300, 200, 60)];
    button2.backgroundColor = [UIColor whiteColor];
    button2.alpha = 0.5;
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(50, 10, 100, 40)];
    label.backgroundColor = [UIColor whiteColor];
    label.text = @"Hello world2";
    label.textColor = [UIColor blackColor];
    [button2 addSubview:label];
    [self.view addSubview:button2];
    
}


@end
