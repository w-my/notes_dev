//
//  GPUImageVideoCameraController.m
//  GPUImage使用
//
//  Created by WTW on 2020/3/19.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "GPUImageVideoCameraController.h"
#import <GPUImage/GPUImage.h>
#import <AssetsLibrary/AssetsLibrary.h>

#define K_WIDTH [UIScreen mainScreen].bounds.size.width

/*
 录制视频(实时画面，视频流)
 1、创建相机 (GPUImageStillCamera)
 2、创建滤镜添加滤镜
 3、创建预览视图
 4、开始实时采集画面
 5、写入缓存
 
 */

@interface GPUImageVideoCameraController ()<GPUImageVideoCameraDelegate>

// 实时画面
@property (nonatomic,strong) GPUImageVideoCamera *videoCamera;
// 实时滤镜
@property (nonatomic,strong) GPUImageSepiaFilter *sepialFilter;
// 写入沙盒
@property (nonatomic,strong) GPUImageMovieWriter * movieWriter;
// 写入的地址
@property (nonatomic,strong) NSURL *movieURL;

@end

@implementation GPUImageVideoCameraController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //1、创建相机
    self.videoCamera = [[GPUImageVideoCamera alloc] initWithSessionPreset:AVCaptureSessionPresetHigh cameraPosition:AVCaptureDevicePositionFront];
    self.videoCamera.outputImageOrientation = UIInterfaceOrientationPortrait;
    self.videoCamera.horizontallyMirrorFrontFacingCamera = YES;
    self.videoCamera.delegate = self;

    // 2、添加滤镜
    // GPUImageBilateralFilter  磨皮
    // GPUImageExposureFilter  曝光
    // GPUImageSaturationFilter 饱和度
    // GPUImageBrightnessFilter 美白
    self.sepialFilter = [[GPUImageSepiaFilter alloc] init];
    [self.videoCamera addTarget:self.sepialFilter];

    // 3、创建显示实时画面的View
    GPUImageView *imageView = [[GPUImageView alloc] initWithFrame:self.view.bounds];
    [self.sepialFilter addTarget:imageView];
    [self.view addSubview:imageView];

//    GPUImageView *filterView = (GPUImageView *)self.view;
//    [self.sepialFilter addTarget:filterView];

    // 4、开始实时采集画面
    [self.videoCamera startCameraCapture];

    // 5、写入到沙盒
    NSString *pathToMovie = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents/LiveMovied.m4v"];
    self.movieURL = [NSURL fileURLWithPath:pathToMovie];
    self.movieWriter = [[GPUImageMovieWriter alloc] initWithMovieURL:self.movieURL size:self.view.bounds.size];

    // 设置为liveVideo 进行编码
    self.movieWriter.encodingLiveVideo = YES;
    [self.sepialFilter addTarget:self.movieWriter];

    // 设置声音
    self.videoCamera.audioEncodingTarget = self.movieWriter;
    
    // 延迟2秒开始
    [self performSelector:@selector(starWrite) withObject:nil afterDelay:2];
//
//    // 延迟20秒结束
//    [self performSelector:@selector(stopWrite) withObject:nil afterDelay:20];
    
}

- (void)starWrite{
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.movieWriter startRecording];
    });
}

- (void)stopWrite{
    dispatch_async(dispatch_get_main_queue(), ^{

        self.videoCamera.audioEncodingTarget = nil;
        [self.sepialFilter removeTarget:self.movieWriter];
        [self.movieWriter finishRecording];

        ALAssetsLibrary *library = [[ALAssetsLibrary alloc] init];
        if ([library videoAtPathIsCompatibleWithSavedPhotosAlbum:self.movieURL])
        {
            [library writeVideoAtPathToSavedPhotosAlbum:self.movieURL completionBlock:^(NSURL *assetURL, NSError *error)
             {
                 dispatch_async(dispatch_get_main_queue(), ^{

                     if (error) {
                         NSLog(@"写入到相册失败");
                     } else {
                         NSLog(@"写入到相册成功");
                     }
                 });
             }];
        }
    });
}

// 切换滤镜
- (void)changeFilter{
    [self.videoCamera removeAllTargets];
    GPUImageSobelEdgeDetectionFilter *filter = [[GPUImageSobelEdgeDetectionFilter alloc]init];
    [self.videoCamera addTarget:filter];
    GPUImageView *filterView = (GPUImageView *)self.view;
    [filter addTarget:filterView];
    [filter addTarget:self.movieWriter];
}

#pragma mark - GPUImageVideoCameraDelegate
- (void)willOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer {
    // 采集到画面
    NSLog(@"采集到画面");
}

@end
