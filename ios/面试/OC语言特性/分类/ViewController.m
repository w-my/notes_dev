//
//  ViewController.m
//  分类
//
//  Created by wtw on 2018/12/26.
//  Copyright © 2018 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    CFRunLoopGetCurrent();
    [NSRunLoop currentRunLoop];
    
    [self performSelector:@selector(test) withObject:nil];
}

@end
