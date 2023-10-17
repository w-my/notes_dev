//
//  ViewController.m
//  显示动画
//
//  Created by wtw on 2019/1/29.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()<CAAnimationDelegate>
@property (nonatomic,strong) CALayer *colorLayer;
@property (weak, nonatomic) IBOutlet UIView *layerView;
@end

//属性动画
//动画组
//过渡
//在动画过程中取消动画

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.colorLayer = [CALayer layer];
    self.colorLayer.frame = CGRectMake(50.f, 50.f, 100.f, 100.f);
    self.colorLayer.backgroundColor = [UIColor blueColor].CGColor;
    
    [self.layerView.layer addSublayer:self.colorLayer];
}

- (IBAction)touchMechangeColor {
    //create a new random color
    CGFloat red = arc4random() / (CGFloat)INT_MAX;
    CGFloat green = arc4random() / (CGFloat)INT_MAX;
    CGFloat blue = arc4random() / (CGFloat)INT_MAX;
    UIColor *color = [UIColor colorWithRed:red green:green blue:blue alpha:1.0];
    //create a basic animation
    CABasicAnimation *animation = [CABasicAnimation animation];
    animation.keyPath = @"backgroundColor";
    animation.toValue = (__bridge id)color.CGColor;
    animation.delegate = self;
    //apply animation to layer
    [self.colorLayer addAnimation:animation forKey:nil];
}

- (void)animationDidStop:(CABasicAnimation *)anim finished:(BOOL)flag {
    [CATransaction begin];
    [CATransaction setDisableActions:YES];
    self.colorLayer.backgroundColor = (__bridge CGColorRef)anim.toValue;
    [CATransaction commit];
}

@end
