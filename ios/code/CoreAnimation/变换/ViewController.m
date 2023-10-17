//
//  ViewController.m
//  变换
//
//  Created by wtw on 2019/1/9.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (nonatomic,weak) UIImageView *imageView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    UIImageView *imageView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"ic_home_shuimian"]];
    imageView.frame = CGRectMake(100, 100, 100, 100);
    [self.view addSubview:imageView];
    self.imageView = imageView;
    
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
    /*
     一些基础变换
     CGAffineTransformMakeRotation(CGFloat angle)
     CGAffineTransformMakeScale(CGFloat sx, CGFloat sy)
     CGAffineTransformMakeTranslation(CGFloat tx, CGFloat ty)
     */
    
    //旋转变换
//    CGAffineTransform transform = CGAffineTransformMakeRotation(M_PI_4);
//   self.imageView.transform = transform;
    
    //缩放变换
//    CGAffineTransform transform = CGAffineTransformMakeScale(1.0, 0.5);
//    self.imageView.transform = transform;
    
    //平移变换
//    CGAffineTransform transform = CGAffineTransformMakeTranslation(50, 0);
//    self.imageView.transform = transform;
     //UIView 中的transform 在 CALayer 中对应的是 affineTransform
//    self.imageView.layer.affineTransform = transform;
    
    /*
     混合变换
     CGAffineTransformRotate(CGAffineTransform t, CGFloat angle)
     CGAffineTransformScale(CGAffineTransform t, CGFloat sx, CGFloat sy)
     CGAffineTransformTranslate(CGAffineTransform t, CGFloat tx, CGFloat ty)
     CGAffineTransformIdentity  //什么都不做的变换 常用于初始值
     两个变换的基础上创建一个新的变换
     CGAffineTransformConcat(CGAffineTransform t1, CGAffineTransform t2);
     */

    //先缩小50% 再旋转30度 再向右移动200个像素
//    CGAffineTransform transform = CGAffineTransformIdentity;
//    transform = CGAffineTransformScale(transform, 0.5, 0.5);
//    transform = CGAffineTransformRotate(transform, M_PI/180.0*30.0);
//    transform = CGAffineTransformTranslate(transform, 200, 0);
//    self.imageView.layer.affineTransform = transform;

    
    /*
     CGAffineTransform 属于 Core Graphics 严格意义上是一个2D 绘图的API
     3D 变换
     CATransform3DMakeRotation(CGFloat angle, CGFloat x, CGFloat y, CGFloat z)
     CATransform3DMakeScale(CGFloat sx, CGFloat sy, CGFloat sz)
     CATransform3DMakeTranslation(Gloat tx, CGFloat ty, CGFloat tz)
     */
    
    //旋转
//    CATransform3D transform = CATransform3DMakeRotation(M_PI_4, 0, 1, 0);
//    self.imageView.layer.transform = transform;
    
    //透视投影
    CATransform3D transform = CATransform3DIdentity;
    transform.m34 = -1.0 / 500.0;
    transform = CATransform3DRotate(self.imageView.layer.transform, M_PI_4, 0, 1, 0);
    self.imageView.layer.transform = transform;
    
    
    // 灭点
    
    
}


@end
