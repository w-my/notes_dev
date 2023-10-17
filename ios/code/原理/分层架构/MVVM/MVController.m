//
//  MVController.m
//  分层架构
//
//  Created by WTW on 2020/4/10.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "MVController.h"
#import "ViewModel.h"

@interface MVController ()

@property (nonatomic,strong) ViewModel *viewModel;


@end

@implementation MVController

- (void)viewDidLoad {
    [super viewDidLoad];
   
    self.viewModel = [[ViewModel alloc] initWithController:self];
    
}


@end
