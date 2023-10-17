//
//  MVPPresenter.m
//  分层架构
//
//  Created by WTW on 2020/4/10.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "MVPPresenter.h"
#import "MVPView.h"
#import "Model.h"

@interface MVPPresenter ()

@property (nonatomic,strong) UIViewController *viewController;

@end

@implementation MVPPresenter

- (instancetype)initWithController:(UIViewController *)controller {
    if (self = [super init]) {
        
        self.viewController = controller;
        
        // 创建View
        MVPView *view = [[MVPView alloc] init];
        [self.viewController.view addSubview:view];
        
        // 加载数据
        Model *model = [[Model alloc] init];
        
        
        // 赋值数据
        
    }
    return  self;
}

@end
