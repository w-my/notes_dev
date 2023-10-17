//
//  ViewController.m
//  CAReplicatorLayer
//
//  Created by wtw on 2019/1/28.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (nonatomic,strong) UIView *containerView;
@end

@implementation ViewController

//创建相似图层
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self.view addSubview:self.containerView];
    
    CAReplicatorLayer *repliLayer = [CAReplicatorLayer layer];
    repliLayer.frame = self.containerView.bounds;
    [self.containerView.layer addSublayer:repliLayer];
    
    repliLayer.instanceCount = 10;
    
    CATransform3D transform = CATransform3DIdentity;
    transform = CATransform3DTranslate(transform, 0, 200, 0);
    transform = CATransform3DRotate(transform, M_PI/5.0, 0, 0, 1);
    transform = CATransform3DTranslate(transform, 0, -200, 0);
    repliLayer.instanceTransform = transform;
    
    repliLayer.instanceBlueOffset = -0.1;
    repliLayer.instanceGreenOffset = -0.1;
    
    CALayer *layer = [CALayer layer];
    layer.frame = CGRectMake(100, 100, 100, 100);
    layer.backgroundColor = [UIColor whiteColor].CGColor;
    [repliLayer addSublayer:layer];
}
- (IBAction)changeColor {
}

- (UIView *)containerView {
    if (!_containerView) {
        _containerView = [[UIView alloc] initWithFrame:CGRectMake(100, 100, 200, 200)];
        _containerView.backgroundColor = [UIColor clearColor];
    }
    return _containerView;
}
- (IBAction)changeColor {
}
@end
