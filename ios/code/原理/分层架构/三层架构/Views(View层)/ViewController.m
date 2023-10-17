
//
//  ViewController.m
//  分层架构
//
//  Created by WTW on 2020/2/23.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "ViewController.h"
#import "NewsService.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //界面层只要向业务层要数据即可，不用管内部实现
    [NewsService loadNewsWithParam:@""
                           success:^(NSArray * _Nonnull dataArr) {
        
    } faile:^(NSError *error))

    }];
}


@end
