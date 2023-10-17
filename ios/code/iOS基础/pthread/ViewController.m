//
//  ViewController.m
//  pthread
//
//  Created by WTW on 2020/2/5.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"
@import Darwin.POSIX.pthread.pthread;

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //1、创建线程对象
    pthread_t thread = NULL;
    
    // 创建线程
    pthread_create(&thread,NULL,task,NULL);
}

void *task(void *param){
    NSLog(@"---%@---",[NSThread currentThread]);
    
    return NULL;
}

// ---<NSThread: 0x600001ada540>{number = 6, name = (null)}---

@end
