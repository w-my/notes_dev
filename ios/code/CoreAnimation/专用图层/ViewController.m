//
//  ViewController.m
//  专用图层
//
//  Created by wtw on 2019/1/10.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"
#import <CoreText/CoreText.h>

@interface ViewController ()

@property (nonatomic,strong) UIView *labelView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    //
    [self test4];
        
}

//绘制火柴人
- (void)test1 {
    //create path
    UIBezierPath *path = [[UIBezierPath alloc] init];
    [path moveToPoint:CGPointMake(175, 100)];
    
    [path addArcWithCenter:CGPointMake(150, 100) radius:25 startAngle:0 endAngle:M_PI*2 clockwise:YES];
    [path moveToPoint:CGPointMake(150, 125)];
    [path addLineToPoint:CGPointMake(150, 175)];
    [path addLineToPoint:CGPointMake(125, 225)];
    [path moveToPoint:CGPointMake(150, 175)];
    [path addLineToPoint:CGPointMake(175, 225)];
    [path moveToPoint:CGPointMake(100, 150)];
    [path addLineToPoint:CGPointMake(200, 150)];
    
    //create shape layer
    CAShapeLayer *shapeLayer = [CAShapeLayer layer];
    //设置描边色
    shapeLayer.strokeColor = [UIColor redColor].CGColor;
    //设置填充色
    shapeLayer.fillColor = [UIColor clearColor].CGColor;
    shapeLayer.lineWidth = 5;
    shapeLayer.lineJoin = kCALineJoinRound;
    shapeLayer.lineCap = kCALineCapRound;
    shapeLayer.path = path.CGPath;
    
    DrawingView *view = [[DrawingView alloc] initWithFrame:CGRectMake(0, 0, 300, 300)];
    [self.view addSubview:view];
    [self.view.layer addSublayer:shapeLayer];
}

// 绘制圆环
- (void)test2 {
    UIBezierPath *path = [UIBezierPath bezierPathWithOvalInRect:CGRectMake(375/2-100, 667/2-100, 200, 200)];
    
    CABasicAnimation *anima = [CABasicAnimation animationWithKeyPath:@"strokeEnd"];
    anima.duration = 3.0;
    anima.fromValue = @(0);
    anima.toValue = @(1);
    anima.repeatCount = 10;
    
    CAShapeLayer *layer = [CAShapeLayer layer];
    layer.fillColor = [UIColor clearColor].CGColor;
    layer.lineWidth = 20.;
    layer.strokeColor = [UIColor redColor].CGColor;
    layer.strokeStart = 0;
    layer.strokeEnd = 1;
    [layer addAnimation:anima forKey:@"strokeEnd"];
    layer.path = path.CGPath;
    
    DrawingView *view = [[DrawingView alloc] initWithFrame:CGRectMake(0, 0, 300, 300)];
    [self.view addSubview:view];
    [self.view.layer addSublayer:layer];
}

//绘制直线
- (void)test3 {
    UIBezierPath *path = [UIBezierPath bezierPath];
    [path moveToPoint:CGPointMake(50, 667/2)];
    [path addLineToPoint:CGPointMake(375/2, 667/2)];
    [path addLineToPoint:CGPointMake(300, 667/2)];
    
    CABasicAnimation *animation = [CABasicAnimation animationWithKeyPath:@"strokeEnd"];
    //每次动画的持续时间
    animation.duration = 5;
    //动画起始位置
    animation.fromValue = @(0);
    //动画结束位置
    animation.toValue = @(1);
    //动画重复次数
    animation.repeatCount = 100;
    
    CAShapeLayer *layer = [CAShapeLayer layer];
    layer.lineWidth = 2.0;
    layer.strokeColor = [UIColor redColor].CGColor;
    layer.path = path.CGPath;
    [layer addAnimation:animation forKey:@"strokeEndAnimation"];
    
    DrawingView *view = [[DrawingView alloc] initWithFrame:CGRectMake(0, 0, 300, 300)];
    [self.view addSubview:view];
    [self.view.layer addSublayer:layer];
}


//绘制曲线
- (void)test4{
    UIBezierPath *path = [UIBezierPath bezierPath];
    //起始点
    [path moveToPoint:CGPointMake(50, 667/2)];
    //结束点、两个控制点
    [path addCurveToPoint:CGPointMake(330, 667/2) controlPoint1:CGPointMake(125, 200) controlPoint2:CGPointMake(185, 450)];
    
    CABasicAnimation *animation = [CABasicAnimation animationWithKeyPath:@"strokeEnd"];
    animation.duration = 5;
    animation.fromValue = @(0);
    animation.toValue = @(1);
    animation.repeatCount = 100;
    
    CAShapeLayer *layer = [CAShapeLayer layer];
    layer.strokeColor = [UIColor redColor].CGColor;
    layer.fillColor = [UIColor clearColor].CGColor;
    layer.path = path.CGPath;
    layer.lineWidth = 2.0;
    [layer addAnimation:animation forKey:@"strokeEndAnimation"];
    
    DrawingView *view = [[DrawingView alloc] initWithFrame:CGRectMake(0, 0, 300, 300)];
    [self.view addSubview:view];
    [self.view.layer addSublayer:layer];
}


// 绘制局部圆角矩形
- (void)test5 {
    
    CGRect rect = CGRectMake(50, 50, 100, 100);
    CGSize redii = CGSizeMake(20, 20);
    UIRectCorner corners = UIRectCornerTopLeft | UIRectCornerTopRight | UIRectCornerBottomLeft;
    
    UIBezierPath *path = [UIBezierPath bezierPathWithRoundedRect:rect byRoundingCorners:corners cornerRadii:redii];
    
    CAShapeLayer *shapeLayer = [CAShapeLayer layer];
    //设置描边色
    shapeLayer.strokeColor = [UIColor redColor].CGColor;
    //设置填充色
    shapeLayer.fillColor = [UIColor clearColor].CGColor;
    shapeLayer.lineWidth = 5;
    shapeLayer.lineJoin = kCALineJoinRound;
    shapeLayer.lineCap = kCALineCapRound;
    shapeLayer.path = path.CGPath;
    [self.view.layer addSublayer:shapeLayer];
    
}

//绘制文字
- (void)test6 {
    self.labelView = [[UIView alloc] initWithFrame:CGRectMake(50, 100, 300, 300)];
    [self.view addSubview:self.labelView];
    
    //create a text layer
    CATextLayer *textLayer = [CATextLayer layer];
    textLayer.frame = self.labelView.bounds;
    [self.labelView.layer addSublayer:textLayer];
    
    //set text attributes
    textLayer.foregroundColor = [UIColor blackColor].CGColor;
    textLayer.alignmentMode = kCAAlignmentJustified;
    textLayer.wrapped = YES;
    
    //choose a font
    UIFont *font  = [UIFont systemFontOfSize:15];
    
    //set layer font
    CFStringRef fontName = (__bridge CFStringRef)(font.fontName);
    CGFontRef fontRef = CGFontCreateWithFontName(fontName);
    textLayer.font = fontRef;
    textLayer.fontSize = font.pointSize;
    CGFontRelease(fontRef);
    
    //设置scale 匹配分辨率
    textLayer.contentsScale = [UIScreen mainScreen].scale;
    
    //choose some text
    NSString *text = @"Lorem ipsum dolor sit amet, consectetur adipiscing \ elit. Quisque massa arcu, eleifend vel varius in, facilisis pulvinar \ leo. Nunc quis nunc at mauris pharetra condimentum ut ac neque. Nunc ele ut porttitor dictum, diam odio congue lacus, vel \ fringilla sapien diam at purus. Etiam suscipit pretium nunc sit amet \ lobortis";
    
    //set layer text
    textLayer.string = text;
    
}


@end

