//
//  ViewController.m
//  CAGradientLayer
//
//  Created by wtw on 2019/1/28.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (nonatomic,strong) UIView *containerView;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Do any additional setup after loading the view, typically from a nib.
    [self.view addSubview:self.containerView];
    
    //基础渐变  红变蓝对角线渐变
    //stratPoint endPoint 决定了了渐变的方向
    CAGradientLayer *gradientLayer = [CAGradientLayer layer];
    gradientLayer.frame = self.containerView.bounds;
    [self.containerView.layer addSublayer:gradientLayer];
    
    //gradient colors  k
    //基础渐变
//    gradientLayer.colors = @[(__bridge id)[UIColor redColor].CGColor,(__bridge id)[UIColor blueColor].CGColor];
    //多重渐变
     gradientLayer.colors = @[(__bridge id)[UIColor redColor].CGColor,(__bridge id)[UIColor yellowColor].CGColor,(__bridge id)[UIColor blueColor].CGColor];
    
    
    //locations  并不是强制的 如果设置就一定要确保 数组locations大小 和 数组colors 大小一定要相同
    gradientLayer.locations = @[@0.0,@0.25,@0.5];

    
    
    //startPoint endPoint
    // 0.0 代表渐变的开始
    // 1.0 代表渐变的结束
    gradientLayer.startPoint = CGPointMake(0, 0);
    gradientLayer.endPoint = CGPointMake(1, 1);
}


- (UIView *)containerView {
    if (!_containerView) {
        _containerView = [[UIView alloc] initWithFrame:CGRectMake(100, 100, 200, 200)];
        _containerView.backgroundColor = [UIColor greenColor];
    }
    return _containerView;
}


@end
