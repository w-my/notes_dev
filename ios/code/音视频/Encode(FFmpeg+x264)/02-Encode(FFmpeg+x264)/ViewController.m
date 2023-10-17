//
//  ViewController.m
//  02-Encode(FFmpeg+x264)
//
//  Created by apple on 16/12/15.
//  Copyright © 2016年 coderwhy. All rights reserved.
//

#import "ViewController.h"
#import "VideoCapture.h"

@interface ViewController ()

/** 视频捕捉对象 */
@property (nonatomic, strong) VideoCapture *videoCapture;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (IBAction)startCapture {
    [self.videoCapture startCapture:self.view];
}

- (IBAction)stopCapture {
    [self.videoCapture stopCapture];
}

- (VideoCapture *)videoCapture {
    if (_videoCapture == nil) {
        _videoCapture = [[VideoCapture alloc] init];
    }
    
    return _videoCapture;
}

@end
