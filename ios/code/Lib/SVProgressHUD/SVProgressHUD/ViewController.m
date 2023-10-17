//
//  ViewController.m
//  SVProgressHUD
//
//  Created by wtw on 2019/1/30.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"
#import <SVProgressHUD.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
//    [SVProgressHUD setDefaultStyle:SVProgressHUDStyleDark];
//    [SVProgressHUD setDefaultMaskType:SVProgressHUDMaskTypeGradient];
//    [SVProgressHUD showWithStatus:@"123"];
//    [SVProgressHUD show];
    [SVProgressHUD showProgress:0.8];
}

@end
