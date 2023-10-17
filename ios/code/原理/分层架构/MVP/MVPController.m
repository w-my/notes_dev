//
//  MVPController.m
//  分层架构
//
//  Created by WTW on 2020/4/10.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "MVPController.h"
#import "MVPPresenter.h"

@interface MVPController ()

// Controller  拥有 MVPPresenter ，MVPPresenter 处理所有的 View 和 Model 的交互
@property (nonatomic,strong) MVPPresenter *presenter;

@end

@implementation MVPController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.presenter = [[MVPPresenter alloc] initWithController:self];
    
    
    
}



@end
