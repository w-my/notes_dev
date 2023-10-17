//
//  ViewController.m
//  MainProject
//
//  Created by WTW on 2020/3/6.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"
#import <NetWorkTools.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
        
    [NetWorkTools requestDataWithParam:nil
                        successHandler:^(NSDictionary * _Nonnull info) {
        NSLog(@"%@",info);
    }
                          errorHandler:^(NSError * _Nonnull error) {
        NSLog(@"%@",error);
    }];
    
}


@end
