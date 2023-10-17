//
//  ViewController.m
//  自定义NSOperation
//
//  Created by WTW on 2020/4/2.
//  Copyright © 2020 wtw. All rights reserved.
//

/*
 自定义 NSOperation 需要重写 main 或者 start 方法
 
 区别：
    如果是对于并发的 Operation 需要重写 start 方法
    如果是对于非并发的 Operation 需要重写的是 main 方法
 
 */

#import "ViewController.h"
#import "MyOperation.h"

@interface ViewController ()
@property (nonatomic,strong) NSOperationQueue *queue;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.queue = [[NSOperationQueue alloc] init];
    [self.queue setMaxConcurrentOperationCount:2];
    
    MyOperation *operation1 = [[MyOperation alloc] init];
    MyOperation *operation2 = [[MyOperation alloc] init];
    
    [self.queue addOperations:@[operation1,operation2] waitUntilFinished:YES];
    
    NSLog(@" ===== ");
}


@end
