//
//  ViewController.m
//  RunLoop
//
//  Created by wtw on 2019/1/2.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    
//    CFRunLoopObserverRef
    
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        NSLog(@"任务A");
        [self performSelector:@selector(test) withObject:nil afterDelay:1.0];
        NSLog(@"任务C");
    });
}

- (void)test{
    NSLog(@"任务B");
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
    
}

@end
