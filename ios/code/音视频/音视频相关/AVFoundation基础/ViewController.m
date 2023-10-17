//
//  ViewController.m
//  AVFoundation入门
//
//  Created by WTW on 2020/3/17.
//  Copyright © 2020 WTW. All rights reserved.
//

/*
 算法基础
 核心动画
 GPUImage
 AVFoundation
 */

/**
 * AVPlayer
 *   一个用来播放基于时间的视听媒体的控制器对象
 *
 * AVPlayerLayer
 *
 * AVPlayerItem
 *
 */


#import "ViewController.h"
#import <AVFoundation/AVFoundation.h>

@interface ViewController ()

@property (nonatomic,strong) AVPlayer *player;

@end

@implementation ViewController

static const NSString *playerItemStatusContext;

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // 1、Define the asset URL
    NSURL *assetURL = [[NSBundle mainBundle] URLForResource:@"a" withExtension:@"mp4"];
    
    // 2、Create an instance of AVAsset
    AVAsset *asset = [AVAsset assetWithURL:assetURL];
    
    // 3、Create an AVPlayerItem with a pointer to the asset to play
    AVPlayerItem * playerItem = [AVPlayerItem playerItemWithAsset:asset];
    
    [playerItem addObserver:self
                 forKeyPath:@"status"
                    options:0
                    context:&playerItemStatusContext];
    
    // 4、Create an instance of AVPlayer with a pointer to the player item
    self.player = [AVPlayer playerWithPlayerItem:playerItem];
    
    // 5、Create a player layer to direct the video content
    AVPlayerLayer * playerLayer = [AVPlayerLayer playerLayerWithPlayer:self.player];
    
    // 6、Attach layer into layer hierarchy
    [self.view.layer addSublayer:playerLayer];
    
}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context {
    if (context == &playerItemStatusContext) {
        
        AVPlayerItem *playerItem = (AVPlayerItem *)object;
        if (playerItem.status == AVPlayerItemStatusReadyToPlay) {
         
            NSLog(@"=====");
            
            [self.player play];
        }
    }
}

@end
