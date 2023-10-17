//
//  ViewController.m
//  CALayer寄宿图
//
//  Created by wtw on 2019/1/8.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()<CALayerDelegate>

@property (nonatomic,strong) UIView *greenView;
@property (nonatomic,strong) CALayer *blueLayer;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

#pragma mark - contents  属性
    
// self.view.layer.contents = (__bridge id _Nullable)([UIImage imageNamed:@"001.jpg"].CGImage);

#pragma mark - contenMode 属性
    
    UIView *blueView = [[UIView alloc] initWithFrame:CGRectMake(100, 100, 100, 100)];
    blueView.backgroundColor = [UIColor blueColor];
    [self.view addSubview:blueView];
    UIImage *img = [UIImage imageNamed:@"001.jpg"];
    blueView.layer.contents = (__bridge id _Nullable)img.CGImage;
    
    //UIView 中的contentMode
//   blueView.contentMode = UIViewContentModeScaleAspectFit;
    
    //Layer 中的 contentsGravity 和上面是等同效果
//    blueView.layer.contentsGravity = kCAGravityResizeAspect;
    
#pragma mark - contentsScale
    
    blueView.layer.contentsGravity = kCAGravityCenter;
    //当用代码的方式处理寄宿图的时候，一点要记住手动设置图层的contentsScale 否则图片再Retina 设备上就显示的不正确了
//    blueView.layer.contentsScale = 3.0;
//    blueView.layer.contentsScale = img.scale;
//    blueView.layer.contentsScale = [UIScreen mainScreen].scale;
    
    // NSLog(@"%f == %f",img.scale,[UIScreen mainScreen].scale);  // 1.0 3.0
    
#pragma mark - maskToBounds 裁剪（view 为 clipsToBounds）
    
    // blueView.clipsToBounds = YES;
    
    blueView.layer.masksToBounds = YES;
    
#pragma mark - contentsRect
    
    // 范围是 0 - 1
    // 默认的 contentsRect 是 (0,0,1,1) 意味着整个寄宿图整体可见
    // (0, 0, 0.5, 0.5) 为左上角的四分子一 其余的内容会被裁剪
    // 应用可以类似h5 的精灵图一样的效果 可以为负数也可以大于1
//    blueView.layer.contentsRect = CGRectMake(0, 0, 0.5, 0.5);
    
#pragma mark - contentsCenter
    
    // 与图片的位置没有关系 是一个 CGRect  定义了一个固定的边框和一个在图层上可拉伸的区域, 改变 contentsCenter 的值并不会影响到寄宿图的显示，除非这个图层大小改变了
    // 默认情况下 contentsCenter 是 {0,0,1,1} 意味着如果大小(cottensGravity)改变了,那么寄宿图将会均匀地拉伸开。但是如果增加原点的值并减少尺寸，会在图片的周围创造一个边框
    // 如果给的值为 CGRectMake(0.25, 0.25, 0.5, 0.5) 周围会有一个颜色的边框
    blueView.layer.contentsCenter = CGRectMake(0, 0, 0.5, 0.5);
    
//    blueView.layer.anchorPoint = CGPointMake(0, 0);
//    blueView.layer.geometryFlipped = YES;
//    greenView.layer.zPosition = 1.0f;
//    NSLog(@"%@",NSStringFromCGPoint(blueView.layer.position));
    
//    CALayer *blueLayer = [CALayer layer];
//    blueLayer.frame = CGRectMake(50, 50, 100, 100);
//    blueLayer.backgroundColor = [UIColor blueColor].CGColor;
//    [self.greenView.layer addSublayer:blueLayer];
//    self.blueLayer = blueLayer;
}


- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    //containsPoint 判断
//    CGPoint point = [[touches anyObject] locationInView:self.view];
//    NSLog(@"%@",NSStringFromCGPoint(point));
//    point = [self.greenView.layer convertPoint:point fromLayer:self.view.layer];
//    if ([self.greenView.layer containsPoint:point]) {
//        point = [self.blueLayer convertPoint:point fromLayer:self.greenView.layer];
//        if ([self.blueLayer containsPoint:point]) {
//            NSLog(@"在a蓝色范围内");
//        }
//    }
    
    CGPoint point = [[touches anyObject] locationInView:self.view];
    CALayer *layer = [self.greenView.layer hitTest:point];
    if (layer == self.blueLayer) {
        NSLog(@"在蓝色范围内");
    }
    
    NSLog(@"%@",NSStringFromCGPoint(point));
}

@end
