//
//  TestMasonryController.m
//  Masonry给ScrollView设置约束
//
//  Created by WTW on 2020/3/17.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "TestMasonryController.h"
#import "Masonry.h"

#define K_HEIGHT [UIScreen mainScreen].bounds.size.height
#define K_WIDTH  [UIScreen mainScreen].bounds.size.width

@interface TestMasonryController ()

@end

@implementation TestMasonryController

- (void)viewDidLoad {
    [super viewDidLoad];
   
    self.view.backgroundColor = [UIColor whiteColor];
    
#pragma mark - 基础概念
    /*
     // 基础 API
     
     mas_makeConstraints()    添加约束
     mas_remakeConstraints()  移除之前的约束，重新添加新的约束
     mas_updateConstraints()  更新约束，写哪条更新哪条，其他约束不变

     equalTo()       参数是对象类型，一般是视图对象或者mas_width这样的坐标系对象
     mas_equalTo()   和上面功能相同，参数可以传递基础数据类型对象，可以理解为比上面的API更强大

     width()         用来表示宽度，例如代表view的宽度
     mas_width()     用来获取宽度的值。和上面的区别在于，一个代表某个坐标系对象，一个用来获取坐标系对象的值
    
     
     // 更新约束和布局 
     - (void)updateConstraintsIfNeeded  调用此方法，如果有标记为需要重新布局的约束，则立即进行重新布局，内部会调用updateConstraints方法
     - (void)updateConstraints          重写此方法，内部实现自定义布局过程
     - (BOOL)needsUpdateConstraints     当前是否需要重新布局，内部会判断当前有没有被标记的约束
     - (void)setNeedsUpdateConstraints  标记需要进行重新布局
     
     */

#pragma mark - 基本使用
    
    UIView *redView = [[UIView alloc] init];
    redView.backgroundColor = [UIColor redColor];
    [self.view addSubview:redView];
    
    [redView mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.edges.equalTo(self.view).insets(UIEdgeInsetsMake(100, 40, -40, -40));
        // 等价于下面代码
        make.top.equalTo(self.view).offset(100);
//        make.bottom.equalTo(self.view).offset(-40);
        make.left.equalTo(self.view).offset(40);
        make.right.equalTo(self.view).offset(-40);
        make.height.mas_equalTo(40);
    }];
    
    //更新约束
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        NSLog(@"%@",[NSThread currentThread]);
        [UIView animateWithDuration:0.5 animations:^{
            [redView mas_updateConstraints:^(MASConstraintMaker *make) {
                make.left.equalTo(self.view).offset(20);
            }];
        }];
    });
    
    
    // 大于或者小于等于某个约束值
    UILabel *label = [[UILabel alloc] init];
    label.backgroundColor = [UIColor greenColor];
    label.text = @" Masonry给ScrollView设置约束[44720:3492025] <NSThread: 0x600002aa0200>{number = 1, name = main";
    label.numberOfLines = 0;
    [self.view addSubview:label];
    [label mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(redView.mas_bottom).offset(40);
        make.centerX.equalTo(self.view);
        make.width.lessThanOrEqualTo(@200);
        make.height.greaterThanOrEqualTo(@10);
    }];
    
    // 设置约束优先级
//    [redView mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.center.equalTo(self.view);
//        make.width.equalTo(self.view).priorityLow();
//        make.width.mas_equalTo(20).priorityHigh();
//        make.height.equalTo(self.view).priority(200);
//        make.height.mas_equalTo(100).priority(1000);
//    }];
    
    UIView *blueView = [[UIView alloc] init];
    blueView.backgroundColor = [UIColor blueColor];
    [self.view addSubview:blueView];
    
    // 设置约束比例
    [blueView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(label.mas_bottom).offset(20);
        make.centerX.equalTo(self.view);
        make.height.mas_equalTo(40);
        make.width.equalTo(self.view).multipliedBy(0.5);
    }];
    
#pragma mark - 等高 等宽
    CGFloat padding = 10;
    
    UIView *yellowView = [[UIView alloc] init];
    yellowView.backgroundColor = [UIColor yellowColor];
    [self.view addSubview:yellowView];

    UIView *pinkView = [[UIView alloc] init];
    pinkView.backgroundColor = [UIColor systemPinkColor];
    [self.view addSubview:pinkView];

    UIView *greenView = [[UIView alloc] init];
    greenView.backgroundColor = [UIColor greenColor];
    [self.view addSubview:greenView];
//
//
//    [yellowView mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.top.equalTo(blueView.mas_bottom).offset(20);
//        make.centerX.equalTo(self.view.mas_centerX);
//        make.size.mas_equalTo(CGSizeMake(45, 45));
//    }];
//
//    [pinkView mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.trailing.equalTo(yellowView.mas_leading).offset(-padding);
//        make.top.equalTo(yellowView.mas_top);
//    }];
//
//    [greenView mas_makeConstraints:^(MASConstraintMaker *make) {
//        make.top.equalTo(yellowView.mas_top);
//        make.leading.equalTo(yellowView.mas_trailing).offset(padding);
//        make.height.equalTo(@[pinkView,yellowView]);
//        make.width.equalTo(@[pinkView,yellowView]);
//    }];
 
    [yellowView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(blueView.mas_bottom).offset(20);
        make.height.mas_equalTo(45);
    }];
    [pinkView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.view);
        make.trailing.equalTo(yellowView.mas_leading);
    }];
    [greenView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.equalTo(self.view);
        make.leading.equalTo(yellowView.mas_trailing);
       
        make.height.equalTo(@[pinkView,yellowView]);
        make.width.equalTo(@[pinkView,yellowView]);
        make.top.equalTo(@[yellowView,pinkView]);
    }];
    
}

@end
