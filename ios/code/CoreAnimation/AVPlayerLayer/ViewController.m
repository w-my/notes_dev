//
//  ViewController.m
//  AVPlayerLayer
//
//  Created by wtw on 2019/1/29.
//  Copyright © 2019 wtw. All rights reserved.
//

/**
  不是 Core Animation 的一部分
  是  AVFoundation 提供的
**/

#import "ViewController.h"
#import <AVFoundation/AVFoundation.h>

@interface ViewController ()

@property (nonatomic,strong) UIView *containerView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.view addSubview:self.containerView];
    
    NSURL *url = [[NSBundle mainBundle] URLForResource:@"001.mp4" withExtension:nil];
    
    AVPlayer *player = [AVPlayer playerWithURL:url];
    AVPlayerLayer *playerLayer = [AVPlayerLayer playerLayerWithPlayer:player];
    
    playerLayer.frame = self.containerView.bounds;
    [self.containerView.layer addSublayer:playerLayer];
    
    //旋转添加边框和圆角
    CATransform3D transform = CATransform3DIdentity;
    transform.m34 = -1 / 500.0;
    transform = CATransform3DRotate(transform, -M_PI_4, 1, 1, 0);
    playerLayer.transform = transform;
    
    playerLayer.masksToBounds = YES;
    playerLayer.cornerRadius = 20.0;
    playerLayer.borderColor = [UIColor redColor].CGColor;
    playerLayer.borderWidth = 5.0;
    
    [player play];
}


- (UIView *)containerView {
    if (!_containerView) {
        _containerView = [[UIView alloc] initWithFrame:CGRectMake(50, 50, 300, 300)];
//        _containerView.backgroundColor = [UIColor blueColor];
    }
    return _containerView;
}

@end

