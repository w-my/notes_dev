//
//  ViewController.m
//  Runtime 方法交换
//
//  Created by WTW on 2020/3/10.
//  Copyright © 2020 wtw. All rights reserved.
//

// http://www.tanhao.me/code/160723.html/

/*
 基本上是线程安全的，因为是加在load 方法中，程序一开始就调用执行，这样一般不会出现线程问题 (initialize 则会有线程问题)
 可能会出现命名冲突的问题，只要加上前缀可以尽量避免
 Swizzling changes the method's arguments
 调试定位问题可能会比较麻烦
 */

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    NSLog(@"%s",__func__);
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    NSLog(@"%s",__func__);
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    // 可以在按钮点击的时候处理别的事情
    UIButton *button = [[UIButton alloc] initWithFrame:CGRectMake(100, 100, 100, 45)];
    button.backgroundColor = [UIColor redColor];
    [self.view addSubview:button];
    [button addTarget:self action:@selector(buttonclick) forControlEvents:UIControlEventTouchUpInside];
    
    
    // 保证数组插入 nil 不会崩溃
    NSMutableArray *Marr = [NSMutableArray array];
    [Marr addObject:@1];
    [Marr addObject:nil];
    NSLog(@"%@",Marr);
    
    
    // 保证插入 和 取的时候 传 nil 不会崩溃
    NSMutableDictionary *Mdic = [NSMutableDictionary dictionary];
    [Mdic setValue:@1 forKey:nil];
    [Mdic setValue:@2 forKey:@"2"];
//
    [Mdic objectForKey:nil];
    
    Mdic[@"name"] = nil;
    NSString *obj = nil;
    Mdic[@"value"] = obj;
    
  
    NSDictionary *dict = [NSDictionary dictionary];
    NSDictionary *dict2 = [NSDictionary dictionaryWithObjectsAndKeys:@"1",@"2", nil];

    // __NSDictionaryM == __NSDictionary0 == __NSDictionaryI
//    NSLog(@"%@ == %@ == %@",[Mdic class],[dict class],[dict2 class]);
    
//    NSLog(@"dict=%@",Mdic);
    
    
}

- (void)buttonclick {
    NSLog(@"%s",__func__);
}


@end
