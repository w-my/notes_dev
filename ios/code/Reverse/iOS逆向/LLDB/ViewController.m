//
//  ViewController.m
//  LLDB
//
//  Created by WTW on 2019/9/30.
//  Copyright © 2019 WTW. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (nonatomic,assign) int age;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    NSArray *array = @[@1,@2,@3];
    array[4];
    
}

// frame 栈帧 一个frame 就是一个函数
//
//int a = 10, b = 20;
//
//NSLog(@"hello world");

@end
