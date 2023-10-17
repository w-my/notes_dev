//
//  ViewController.m
//  TableView 性能优化
//
//  Created by WTW on 2020/4/22.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()<UITableViewDelegate,UITableViewDataSource>
@property (nonatomic,strong) UITableView *tableView;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.view addSubview:self.tableView];
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 30;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"customCell" forIndexPath:indexPath];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"customCell"];
        NSLog(@"customCell == 创建cell");
    }
    cell.textLabel.text = [NSString stringWithFormat:@"我是 %zd 行",indexPath.row];
    NSLog(@"%s",__func__);
    return cell;
}

- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath {
    
}

- (BOOL)tableView:(UITableView *)tableView shouldSpringLoadRowAtIndexPath:(NSIndexPath *)indexPath withContext:(id<UISpringLoadedInteractionContext>)context {
    return YES;
}

#pragma mark - UITableViewDelegate

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    NSLog(@"%s == %ld",__func__,indexPath.row);

    return  64;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

- (UITableView *)tableView {
    if (!_tableView) {
        _tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        [_tableView registerClass:NSClassFromString(@"UITableViewCell") forCellReuseIdentifier:@"customCell"];
    }
    return _tableView;
}


@end
