//
//  ViewController.m
//  CALayer处理点击事件
//
//  Created by wtw on 2019/3/4.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (nonatomic,strong) CALayer *redLayer;
@property (nonatomic,strong) CALayer *greenLayer;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.redLayer = [CALayer layer];
    self.redLayer.frame = CGRectMake(100, 100, 100, 100);
    self.redLayer.backgroundColor = [UIColor redColor].CGColor;
    [self.view.layer addSublayer:self.redLayer];
    
    self.greenLayer = [CALayer layer];
    self.greenLayer.frame = CGRectMake(100, 300, 100, 100);
    self.greenLayer.backgroundColor = [UIColor greenColor].CGColor;
    [self.view.layer addSublayer:self.greenLayer];
    
}



/*
 // 将像素point由point所在视图转换到目标视图view中，返回在目标视图view中的像素值
 - (CGPoint)convertPoint:(CGPoint)point toView:(UIView *)view;

 // 将像素point从view中转换到当前视图中，返回在当前视图中的像素值
 - (CGPoint)convertPoint:(CGPoint)point fromView:(UIView *)view;
 */
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    CGPoint point = [[touches anyObject] locationInView:self.view];

#pragma mark - 通过 convertPoint 处理 CALayer 的点击事件
//    CGPoint redPoint = [self.redLayer convertPoint:point fromLayer:self.view.layer];
//    CGPoint greenPoint = [self.greenLayer convertPoint:point fromLayer:self.view.layer];
//
//    if ([self.redLayer containsPoint:redPoint]) {
//        NSLog(@"点击了红色");
//    }
//    if ([self.greenLayer containsPoint:greenPoint]) {
//        NSLog(@"点击了绿色");
//    }
//    NSLog(@"%@",NSStringFromCGPoint(point));
//    NSLog(@"%@",NSStringFromCGPoint(redPoint));
//    NSLog(@"%@",NSStringFromCGPoint(greenPoint));
    
#pragma mark -
   CALayer *layer = [self.view.layer hitTest:point];
    if (layer == self.redLayer) {
        NSLog(@"点击了红色");
    }else if (layer == self.greenLayer) {
        NSLog(@"点击了绿色");
    }
    
}


@end
