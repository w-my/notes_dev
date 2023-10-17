//
//  ViewController.m
//  GPUImage使用
//
//  Created by WTW on 2020/3/18.
//  Copyright © 2020 WTW. All rights reserved.
//

/*
 1、用来修改图片(类似美图秀秀)
 2、利用GPUImage的美颜相机(美颜相机)
 3、录制视频(实时画面)
 */

#import "ViewController.h"

@interface ViewController ()<UITableViewDelegate,UITableViewDataSource>

@property (nonatomic,strong) UITableView *tablview;
@property (nonatomic,strong) NSArray *dataSource;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    [self.view addSubview:self.tablview];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.dataSource.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"cell"];
    }
    
    NSDictionary *dic = self.dataSource[indexPath.row];
    cell.textLabel.text = [dic objectForKey:@"title"];
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    NSDictionary *dict = self.dataSource[indexPath.row];
    Class cls = NSClassFromString([dict objectForKey:@"vc"]);
    [self.navigationController pushViewController:[[cls alloc] init] animated:YES];
}

- (UITableView *)tablview {
    if (!_tablview) {
        _tablview = [[UITableView alloc] initWithFrame:self.view.bounds];
        _tablview.delegate = self;
        _tablview.dataSource = self;
    }
    return _tablview;
}

- (NSArray *)dataSource {
    if (!_dataSource) {
        _dataSource = [NSArray arrayWithObjects:@{
            @"title":@"用来修改图片(类似美图秀秀)",@"vc":@"TestGPUImagePictureController"},@{@"title":@"利用GPUImage的美颜相机(美颜相机)",@"vc":@"TestGPUImageStillCameraController"},
                       @{@"title":@"录制视频(实时画面)",@"vc":@"GPUImageVideoCameraController"},@{@"title":@"测试美颜相机",@"vc":@"BeautyCameraController"}, nil];
    }
    return _dataSource;
}

@end
