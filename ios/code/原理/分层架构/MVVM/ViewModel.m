//
//  ViewModel.m
//  分层架构
//
//  Created by WTW on 2020/4/10.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "ViewModel.h"
#import "View.h"
#import "Model.h"

@interface ViewModel ()

@property (nonatomic,strong) UIViewController *controller;

@property (nonatomic,copy) NSString *name;
@property (nonatomic,copy) NSString *icon;
@end

@implementation ViewModel

- (instancetype)initWithController:(UIViewController *)controller {
    if (self = [super init]) {
        
        self.controller = controller;
        
        // 创建View
        View *view = [[View alloc] initWithFrame:CGRectMake(0, 0, 200, 200)];
        view.viewModle = self;
        [controller.view addSubview:view];
        
        // 创建model 网络加载模型数据
        Model *model = [[Model alloc] init];
        model.name = @"";
        model.icon = @"";
        
        // 设置数据 (这个位置触发KVO)
        self.name = model.name;
        self.icon = model.icon;
    }
    return  self;
}

@end
