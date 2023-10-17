//
//  ViewController.m
//  原理
//
//  Created by wtw on 2019/3/23.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.

    // 断言，如果不成立，在debug 模式下就会 crash
//    NSParameterAssert(<#condition#>)
//    NSAssert(<#condition#>, <#desc, ...#>)
    
    // 1、header_search_path  // 找头文件
    // 2、library_search_path // 找文件路径
    // 3、other_ldflags       // 找库名称
    
    
    // pod 导入静态的 framwork
    use_frameworks! :linkage :static
}


@end
