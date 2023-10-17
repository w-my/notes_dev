//
//  ViewController.m
//  CATransformLayer
//
//  Created by wtw on 2019/1/28.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (nonatomic,strong) UIView *containerView;

@end

@implementation ViewController

- (CALayer *)faceWithTransform:(CATransform3D)transform {
    CALayer *face = [CALayer layer];
    face.frame = CGRectMake(-50, -50, 100, 100);
    
    CGFloat red = (rand()/(double)INT_MAX);
    CGFloat green = (rand()/(double)INT_MAX);
    CGFloat blue = (rand()/(double)INT_MAX);
    
    face.backgroundColor = [UIColor colorWithRed:red green:green blue:blue alpha:1.0].CGColor;
    face.transform = transform;
    return face;
}

- (CALayer *)cubeWithTransform:(CATransform3D)transform {
    
    CATransformLayer *cube = [CATransformLayer layer];
    
    //face 1
    CATransform3D ct = CATransform3DMakeTranslation(0, 0, 50);
    [cube addSublayer:[self faceWithTransform:ct]];
    
    //face 2
    ct = CATransform3DMakeTranslation(50, 0, 0);
    ct = CATransform3DRotate(ct, M_PI_2, 0, 1, 0);
    [cube addSublayer:[self faceWithTransform:ct]];
    
    //face 3
    ct = CATransform3DMakeTranslation(0, -50, 0);
    ct = CATransform3DRotate(ct, M_PI_2, 1, 0, 0);
    [cube addSublayer:[self faceWithTransform:ct]];
    
    //face 4
    ct = CATransform3DMakeTranslation(0, 50, 0);
    ct = CATransform3DRotate(ct, -M_PI_2, 1, 0, 0);
    [cube addSublayer:[self faceWithTransform:ct]];
    
    //face 5
    ct = CATransform3DMakeTranslation(-50, 0, 0);
    ct = CATransform3DRotate(ct, -M_PI_2, 0, 1, 0);
    [cube addSublayer:[self faceWithTransform:ct]];
    
    //face 6
    ct = CATransform3DMakeTranslation(0, 0, -50);
    ct = CATransform3DRotate(ct, M_PI, 0, 1, 0);
    [cube addSublayer:[self faceWithTransform:ct]];
    
    CGSize containterSize = self.containerView.bounds.size;
    cube.position = CGPointMake(containterSize.width / 2.0, containterSize.height / 2.0);
    
    cube.transform = transform;
    
    return cube;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.view addSubview:self.containerView];
    
    CATransform3D pt = CATransform3DIdentity;
    pt.m34 = -1 / 500.0;
    self.containerView.layer.sublayerTransform = pt;
    
    CATransform3D ct1 = CATransform3DIdentity;
    ct1 = CATransform3DTranslate(ct1, -100, 0, 0);
    CALayer *cube1 = [self cubeWithTransform:ct1];
    [self.containerView.layer addSublayer:cube1];
    
    CATransform3D ct2 = CATransform3DIdentity;
    ct2 = CATransform3DTranslate(ct2, 100, 0, 0);
    ct2 = CATransform3DRotate(ct2, -M_PI_4, 1, 0, 0);
    ct2 = CATransform3DRotate(ct2, -M_PI_4, 0, 1, 0);
    CALayer *cube2 = [self cubeWithTransform:ct2];
    [self.containerView.layer addSublayer:cube2];
    
}

- (UIView *)containerView {
    if (!_containerView) {
        _containerView = [[UIView alloc] initWithFrame:CGRectMake(100, 200, 200, 200)];
        _containerView.backgroundColor = [UIColor greenColor];
    }
    return _containerView;
}

@end
