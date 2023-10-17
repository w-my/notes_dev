//
//  BeautyCameraController.m
//  GPUImage使用
//
//  Created by WTW on 2020/3/19.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "BeautyCameraController.h"
#import <GPUImage/GPUImage.h>
#import <AVKit/AVKit.h>

@interface BeautyCameraController ()<GPUImageVideoCameraDelegate>

// 视频源
@property (nonatomic,strong) GPUImageVideoCamera *videoCamera;
// 预览视图
@property (nonatomic,strong) GPUImageView *preView;

// 滤镜
@property (nonatomic,strong) GPUImageBilateralFilter *bilateralFilter;  // 磨皮
@property (nonatomic,strong) GPUImageExposureFilter  *exposureFilter;  // 曝光
@property (nonatomic,strong) GPUImageBrightnessFilter *brightnessFilter;  // 美白
@property (nonatomic,strong) GPUImageSaturationFilter *saturationFilter;  // 饱和度

// 写入对象
@property (nonatomic,strong) GPUImageMovieWriter *movieWriter;
@property (nonatomic,strong) NSURL *fileUrl;

@end

@implementation BeautyCameraController

- (GPUImageBilateralFilter *)bilateralFilter {
    if (!_bilateralFilter) {
        _bilateralFilter = [[GPUImageBilateralFilter alloc] init];
    }
    return _bilateralFilter;
}

- (GPUImageExposureFilter *)exposureFilter {
    if (!_exposureFilter) {
        _exposureFilter = [[GPUImageExposureFilter alloc] init];
    }
    return _exposureFilter;
}

- (GPUImageBrightnessFilter *)brightnessFilter {
    if (!_brightnessFilter) {
        _brightnessFilter = [[GPUImageBrightnessFilter alloc] init];
    }
    return _brightnessFilter;
}

- (GPUImageSaturationFilter *)saturationFilter {
    if (!_saturationFilter) {
        _saturationFilter = [[GPUImageSaturationFilter alloc] init];
    }
    return _saturationFilter;
}


- (GPUImageVideoCamera *)videoCamera {
    if (!_videoCamera) {
        _videoCamera = [[GPUImageVideoCamera alloc] initWithSessionPreset:AVCaptureSessionPresetHigh cameraPosition:AVCaptureDevicePositionFront];
    }
    return _videoCamera;
}

- (GPUImageView *)preView {
    if (!_preView) {
        _preView = [[GPUImageView alloc] initWithFrame:self.view.bounds];
    }
    return _preView;
}

- (GPUImageMovieWriter *)movieWriter {
    if (!_movieWriter) {
        NSLog(@"%@",self.fileUrl);
        _movieWriter = [[GPUImageMovieWriter alloc] initWithMovieURL:self.fileUrl size:self.view.bounds.size];
    }
    return _movieWriter;
}

- (NSURL *)fileUrl {
    if (!_fileUrl) {
        NSString *path = [NSHomeDirectory() stringByAppendingString:@"Documents/123.mp4"];
        _fileUrl = [NSURL fileURLWithPath:path];
    }
    return _fileUrl;
}

- (void)viewDidLoad {
    [super viewDidLoad];
   
    // 1、创建视频源
    self.videoCamera.outputImageOrientation =  UIInterfaceOrientationPortrait;
    self.videoCamera.horizontallyMirrorFrontFacingCamera = YES;
    self.videoCamera.delegate = self;
    
    // 2、创建预览视图
    [self.view insertSubview:self.preView atIndex:0];
    
    // 3、创建滤镜(组)
    GPUImageFilterGroup *filterGroup = [self getGroupFilters];
    
    // 4、设置 GPUImage 的响应链
    [self.videoCamera addTarget:filterGroup];
    [filterGroup addTarget:self.preView];
    
    // 5、开始采集视频
    [self.videoCamera startCameraCapture];
    
    // 6、设置 writer 属性
    // 是否对视频进行编码
    self.movieWriter.encodingLiveVideo = YES;
    self.movieWriter.shouldPassthroughAudio = YES;
    // 将 writer 设置为 filter 的target
    [filterGroup addTarget:self.movieWriter];
    
    // 7、设置camerade 编码
    self.videoCamera.audioEncodingTarget = self.movieWriter;
 
#warning - startRecording 崩溃的bug 还不知道怎么处理
    //8、开始写入
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        dispatch_async(dispatch_get_main_queue(), ^{
            [self.movieWriter startRecording];
        });
    });
}

// 播放视频
- (IBAction)playVideo {

    AVPlayerViewController *playerVc = [[AVPlayerViewController alloc] init];
    playerVc.player = [[AVPlayer alloc] initWithURL:self.fileUrl];
    [self.navigationController presentViewController:playerVc animated:YES completion:nil];
}

// 结束直播
- (IBAction)stopRecording {
    [self.videoCamera stopCameraCapture];
    [self.preView removeFromSuperview];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.videoCamera.audioEncodingTarget = nil;
        [self.movieWriter finishRecording];
    });
}

#pragma mark - GPUImageVideoCameraDelegate
- (void)willOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer {
    NSLog(@"采集到画面");
}

// 获取滤镜组
- (GPUImageFilterGroup *)getGroupFilters {
    // 创建滤镜组 (用于存放各种滤镜)
    GPUImageFilterGroup *filterGroup = [[GPUImageFilterGroup alloc] init];
    
    // 创建滤镜(设置引用关系)
    [self.bilateralFilter addTarget:self.brightnessFilter];
    [self.brightnessFilter addTarget:self.exposureFilter];
    [self.exposureFilter addTarget:self.saturationFilter];
    
    // 设置滤镜组链初始和结束
    [filterGroup setInitialFilters:@[self.bilateralFilter]];
    [filterGroup setTerminalFilter:self.saturationFilter];
    
    return filterGroup;
}

// 饱和度
- (IBAction)changeSatureation:(UISlider *)sender {
    self.saturationFilter.saturation = sender.value * 2;
}
// 美白
- (IBAction)changeBrightness:(UISlider *)sender {
    self.brightnessFilter.brightness = sender.value * 2 -1;
}
// 曝光
- (IBAction)changeExposure:(UISlider *)sender {
    self.exposureFilter.exposure = sender.value * 20 - 10;
}
// 磨皮
- (IBAction)changeBilateral:(UISlider *)sender {
    self.bilateralFilter.distanceNormalizationFactor = sender.value * 8;
}

// 反转摄像头
- (IBAction)rotateCamera {
    [self.videoCamera rotateCamera];
}

// 美颜开关
- (IBAction)switchBeautyEffect:(UISwitch *)sender {
    
    if (sender.isOn) {
        [self.videoCamera removeAllTargets];
        GPUImageFilterGroup *group = [self getGroupFilters];
        [self.videoCamera addTarget:group];
        [group addTarget:self.preView];
    }else {
        [self.videoCamera removeAllTargets];
        [self.videoCamera addTarget:self.preView];
    }
}
@end
