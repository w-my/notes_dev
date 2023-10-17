//
//  XMGRootController.m
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/27.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import "XMGRootController.h"
@interface XMGRootController ()

@end

@implementation XMGRootController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    XMGContentView *contentView = [[XMGContentView alloc]init];
    contentView.frame = CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height - 64);
    [self.view addSubview:contentView];
    self.contentView = contentView;
    
    AppDelegate *app = [UIApplication sharedApplication].delegate;
    self.myAppDelegate = app;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
