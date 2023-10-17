//
//  ViewController.m
//  隐式动画
//
//  Created by wtw on 2019/1/29.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIView *layerView;
@property (nonatomic,strong) CALayer *colorLayer;
@end

@implementation ViewController

//所谓的隐式动画就是没有指定任何的动画类型 仅仅改变了一个属性，然后Core Animation来决定如何并且何时去做动画”
- (void)viewDidLoad {
    [super viewDidLoad];
    
    //create sublayer
    self.colorLayer = [CALayer layer];
    self.colorLayer.frame = CGRectMake(50.0f, 50.0f, 100.0f, 100.0f);
    self.colorLayer.backgroundColor = [UIColor blueColor].CGColor;
    //add it to our view
    [self.layerView.layer addSublayer:self.colorLayer];
    
}

- (IBAction)changeColor {
    
//    //事务是通过 CATransaction 类来管理的
//    //开启一个事务
//    [CATransaction begin];
//    [CATransaction setAnimationDuration:2.0];
//
//    // +setCompletionBlock: 类似UIView 的Block 动画结束后提供的一个完成的动作
//    [CATransaction setCompletionBlock:^{
//        CGAffineTransform transform = self.colorLayer.affineTransform;
//        transform = CGAffineTransformRotate(transform, M_PI_2);
//        self.colorLayer.affineTransform = transform;
//    }];
//
//    //randomize the layer background color
//    CGFloat red = arc4random() / (CGFloat)INT_MAX;
//    CGFloat green = arc4random() / (CGFloat)INT_MAX;
//    CGFloat blue = arc4random() / (CGFloat)INT_MAX;
//    self.colorLayer.backgroundColor = [UIColor colorWithRed:red green:green blue:blue alpha:1.0].CGColor;
//
//    [CATransaction commit];
    
    //UIView 关联的图层禁用了隐式动画
    [CATransaction begin];
    [CATransaction setAnimationDuration:1.0];
    CGFloat red = arc4random() / (CGFloat)INT_MAX;
    CGFloat green = arc4random() / (CGFloat)INT_MAX;
    CGFloat blue = arc4random() / (CGFloat)INT_MAX;
    self.layerView.backgroundColor = [UIColor colorWithRed:red green:green blue:blue alpha:1.0];
    [CATransaction commit];
}
@end
