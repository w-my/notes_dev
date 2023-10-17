//
//  ViewController.m
//  __kindof
//
//  Created by WTW on 2020/2/2.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"
#import "SubPerson.h"

/**
 * kindof 相当于
 * 表示当前类或者它的子类
 */

@interface ViewController ()


@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //不加 __kindof Incompatible pointer types initializing 'SubPerson *' with an expression of type 'Person * _Nonnull'
    SubPerson *person = [SubPerson person];
}


@end
