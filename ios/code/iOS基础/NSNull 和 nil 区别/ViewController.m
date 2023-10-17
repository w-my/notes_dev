//
//  ViewController.m
//  NSNull 和 nil 区别
//
//  Created by WTW on 2020/3/10.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    /*
     nil  指向一个对象的空指针,表示对象为空
     Nil  指向一个类的空指针，代表空类
     NSNull 表示空，什么也不存储，但他是一个对象，只是一个占位对象
     NULL 指向其他类型(基本类型，C类型)的空指针，用于非对象指针赋控制

     
     区别：
     NULL是宏，是对于C语言指针而使用的，表示空指针
     nil是宏，是对于Objective-C中的对象而使用的，表示对象为空
     Nil是宏，是对于Objective-C中的类而使用的，表示类指向空
     NSNull是类类型，是用于表示空的占位对象，与JS或者服务端的null类似的含意
     */
    
    NSURL *url = nil;

    Class class = Nil;

    int *pointerInt = NULL;

    NSArray *array = [NSArray arrayWithObjects:[[NSObject alloc] init], [NSNull null], [[NSObject alloc] init], [[NSObject alloc] init], nil];
    
}


@end
