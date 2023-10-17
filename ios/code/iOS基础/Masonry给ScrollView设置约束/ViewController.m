//
//  ViewController.m
//  Masonry给ScrollView设置约束
//
//  Created by WTW on 2020/3/17.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"
#import "Masonry/Masonry.h"
#import "TestMasonryController.h"

@interface ViewController ()

@property (nonatomic,strong) UIScrollView *scrollView;
@property (nonatomic,strong) UIView *containerView;
@property (nonatomic,strong) UIImageView *imageView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
//    self.scrollView = [[UIScrollView alloc] init];
//    self.scrollView.backgroundColor = [UIColor greenColor];
//    [self.view addSubview:self.scrollView];
//    
//    [self.scrollView mas_makeConstraints:^(MASConstraintMaker *make) {
////        make.edges.equalTo(self.view);
//        make.top.equalTo(self.view.mas_safeAreaLayoutGuideTop).offset(0);
//        make.bottom.right.left.equalTo(self.view);
//    }];
//    
//    self.containerView = [[UIView alloc] init];
//    self.containerView.backgroundColor = [UIColor redColor];
//    [self.scrollView addSubview:self.containerView];
//    
//    [self.containerView mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.edges.equalTo(self.scrollView);
//        make.width.equalTo(self.scrollView);
//    }];
//    
//    
//    self.imageView = [[UIImageView alloc] init];
//    UIImage *image  = [UIImage imageNamed:@"1125-2436"];
//    self.imageView.image = image;
//    NSLog(@"%@",image);
//    [self.containerView addSubview:self.imageView];
//    
//    [self.imageView mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.top.left.right.equalTo(self.containerView);
//        make.bottom.equalTo(self.containerView.mas_bottom);
//    }];
}


- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    TestMasonryController *testVc = [TestMasonryController new];
    [self.navigationController pushViewController:testVc animated:YES];
}

@end
