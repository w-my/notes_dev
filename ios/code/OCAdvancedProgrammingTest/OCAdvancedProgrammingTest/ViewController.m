//
//  ViewController.m
//  OCAdvancedProgrammingTest
//
//  Created by wtw on 2018/3/14.
//  Copyright © 2018年 rocedar. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    
    int (*p)(int,int);
    p = get_max;
    
    NSLog(@"%d",p(10,20));
    /*
    Dispatch Semaphore
     
     dispatch_once 函数是保证在应用程序执行中只执行一次指定处理的API。
    */
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        
    });
}

int get_max(int i,int j){
    return i > j ? i : j;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
