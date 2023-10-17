//
//  ViewController.m
//  CAEmitterLayer
//
//  Created by wtw on 2019/1/29.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (nonatomic,strong) UIView *containerView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.view addSubview:self.containerView];
    
//    CAEmitterCell
    CAEmitterLayer *emitter = [CAEmitterLayer layer];
    emitter.frame = self.containerView.bounds;
    [self.containerView.layer addSublayer:emitter];
    
    emitter.renderMode = kCAEmitterLayerAdditive;
    emitter.emitterPosition = CGPointMake(emitter.frame.size.width / 2.0, emitter.frame.size.height / 2.0);
    
    CAEmitterCell *cell = [[CAEmitterCell alloc] init];
    cell.contents = (__bridge id)[UIImage imageNamed:@"Blue_star_16px_1193755_easyicon.net"].CGImage;
    cell.birthRate = 100;
    cell.lifetime = 5.0;
    cell.color = [UIColor colorWithRed:1 green:0.5 blue:0.1 alpha:1.0].CGColor;
    cell.alphaSpeed = - 0.4;
    cell.velocity = 50;
    cell.velocityRange = 50;
    cell.emissionRange = M_PI * 2.0;
    
    emitter.emitterCells = @[cell];
}


- (UIView *)containerView {
    if (!_containerView) {
        _containerView = [[UIView alloc] initWithFrame:CGRectMake(50, 50, 300, 400)];
    }
    return _containerView;
}

@end
