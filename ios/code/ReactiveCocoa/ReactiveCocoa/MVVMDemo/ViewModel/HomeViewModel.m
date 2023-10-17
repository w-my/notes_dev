//
//  HomeViewModel.m
//  ReactiveCocoa
//
//  Created by wtw on 2018/12/6.
//  Copyright © 2018 wtw. All rights reserved.
//

#import "HomeViewModel.h"
#import <AFNetworking.h>
#import "HomeModel.h"
#import <MJExtension/MJExtension.h>
#import "HomeTableViewCell.h"
#import "HomeCellViewModel.h"

@interface HomeViewModel ()<UITableViewDelegate,UITableViewDataSource>

@property (nonatomic,strong) NSArray *listCellViewModels;

@end

@implementation HomeViewModel {
    
}

- (RACCommand *)loadHomeDataCommand {
    if (!_loadHomeDataCommand) {
        _loadHomeDataCommand = [[RACCommand alloc] initWithSignalBlock:^RACSignal * _Nonnull(id  _Nullable input) {
            return [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
              
                //发送网络请求
                [[AFHTTPSessionManager manager] GET:@"https://c.m.163.com/recommend/getSubDocPic?from=toutiao"
                                         parameters:nil
                                           progress:nil
                                            success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
                                                
                                                // 请求成功 处理数据 数据转模型
                                                NSDictionary *dict = responseObject;
                                                
                                                NSArray *dataArr;
                                                dataArr = [HomeModel mj_objectArrayWithKeyValuesArray:dict[@"tid"]];
                                                
                                                //创建cell 视图模型
                                                //模型转视图模型
                                               _listCellViewModels = [[dataArr.rac_sequence map:^id _Nullable(id  _Nullable value) {
                                                    HomeCellViewModel *cellVM = [[HomeCellViewModel alloc] init];
                                                   cellVM.item = value;
                                                    return cellVM;
                                                }] array] ;
                                                
                                                //发送数据
                                                [subscriber sendNext:dataArr];
                                                [subscriber sendCompleted];
                                            } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
                                                [subscriber sendError:error];
                                            }];
                return nil;
            }];
        }];
    }
    return _loadHomeDataCommand;
}

#pragma mark - TableView Data Source

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.listCellViewModels.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    HomeTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell" forIndexPath:indexPath];
    
    //视图模型
    HomeCellViewModel *cellVM = self.listCellViewModels[indexPath.row];
    
    //绑定视图模型
    [cellVM bindViewModel:cell];
    
    return cell;
}

#pragma mark - TableView Delegate
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 100;
}

#pragma mark - 视图模型的绑定
- (void)bindViewModel:(UIView *)bindView {
    UITableView *tableView = (UITableView *)bindView;
    [tableView registerNib:[UINib nibWithNibName:@"HomeTableViewCell" bundle:nil] forCellReuseIdentifier:@"cell"];
    
    tableView.delegate = self;
    tableView.dataSource = self;
}

@end
