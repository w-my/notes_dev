//
//  ViewController.m
//  instancetype 和 id
//
//  Created by WTW on 2020/3/10.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    /*
     相同点：
        都可以作为方法的返回类型
     不同点：
        id 在编译的时候不能判断出对象的真实类型
        instancetype 在编译的时候可以判断出对象的真实类型
        instancetype 可以返回和方法所在类相同类型的对象，id 只能返回未知类型的对象
        instancetype 只能作为返回值，id 还可以作为参数
     
    NSObject id instancetype
     
     可以用 NSObject 表示 id,但是不能用 id 来表示 NSObject
     id 可以是任何对象,包括不是 NSObject 的对象(ARC中不行)
     定义id 的时候不需要加 * ，而定义 NSObject 的时候需要
     */
    
    
//    id a = 10;
    id obj = [[NSObject alloc] init];
    
}


@end
