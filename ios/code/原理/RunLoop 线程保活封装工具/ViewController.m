//
//  ViewController.m
//  RunLoop 线程保活封装工具
//
//  Created by WTW on 2019/8/19.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"
#import "RCPermenantThread.h"

@interface ViewController ()

@property (nonatomic,strong) RCPermenantThread *thread;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.thread = [[RCPermenantThread alloc] init];
   
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.thread executeTask:^{
        NSLog(@" == 执行任务1 ==");
        NSLog(@"%@",[NSThread currentThread]);

    }];
    
    [self.thread executeTask:^{
        sleep(3);
         NSLog(@" == 执行任务2 ==");
        NSLog(@"%@",[NSThread currentThread]);

    }];
    
    [self.thread executeTask:^{
        NSLog(@" == 执行任务3 ==");
        NSLog(@"%@",[NSThread currentThread]);
    }];
    
    [self.thread executeTask:^{
        sleep(5);
        NSLog(@" == 执行任务4 ==");
        NSLog(@"%@",[NSThread currentThread]);

    }];
}
     
 - (void)dealloc {
     [self.thread stop];
     NSLog(@"%s",__func__);
 }

@end
