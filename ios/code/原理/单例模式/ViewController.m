//
//  ViewController.m
//  单例模式
//
//  Created by WTW on 2020/2/6.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "ViewController.h"
#import "SingletonTool.h"
#import "TestSingleton.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    SingletonTool *instance1 = [[SingletonTool alloc] init];
    
//    [instance1 release];
    
    SingletonTool *instance2 = [SingletonTool new];

//    [instance2 release];
    
    SingletonTool *instance3 = [SingletonTool shareTool];

    SingletonTool *instance4 = [instance1 copy];
    SingletonTool *instance5 = [instance1 mutableCopy];
    
    NSLog(@"%p  %p  %p  %p  %p",instance1,instance2,instance3,instance4,instance5);
    
    
    TestSingleton *test1 = [TestSingleton shareTest];
    TestSingleton *test2 = [[TestSingleton alloc] init];
    
    NSLog(@" %@ %p \n %@ %p",test1,test1,test2,test2);
}


@end
