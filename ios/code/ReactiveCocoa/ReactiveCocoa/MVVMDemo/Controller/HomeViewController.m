//
//  HomeViewController.m
//  ReactiveCocoa
//
//  Created by wtw on 2018/12/6.
//  Copyright © 2018 wtw. All rights reserved.
//

#import "HomeViewController.h"
#import "HomeViewModel.h"

@interface HomeViewController ()

@property (nonatomic,strong) HomeViewModel *homeViewModel;

@end

@implementation HomeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //请求数据
    @weakify(self)
    [[self.homeViewModel.loadHomeDataCommand execute:nil] subscribeNext:^(NSArray * arr) {
        @strongify(self)
        //刷新表格
        [self.tableView reloadData];
    } error:^(NSError * _Nullable error) {
        NSLog(@"%@",error);
    }];
    
    //绑定视图模型 对控件的设置
    [self.homeViewModel bindViewModel:self.tableView];
}

#pragma mark - lazy load
- (HomeViewModel *)homeViewModel {
    if (!_homeViewModel) {
        _homeViewModel = [[HomeViewModel alloc] init];
    }
    return _homeViewModel;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



@end
