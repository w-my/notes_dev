//
//  ViewController.m
//  视频采集
//
//  Created by WTW on 2020/3/17.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "ViewController.h"
#import <AVFoundation/AVFoundation.h>

@interface ViewController ()<
AVCaptureVideoDataOutputSampleBufferDelegate,
AVCaptureAudioDataOutputSampleBufferDelegate,
AVCaptureFileOutputRecordingDelegate>

// 会话session
//管理了采集过程中的状态，当开始采集、停止采集、出现错误都会发起通知，可以监听 AVCaptureSession 的状态，也可调用属性获取当前的状态，相关的通知都是在主线程
@property (nonatomic,strong) AVCaptureSession *captureSession;

// 视频的输入源
@property (nonatomic,strong) AVCaptureDeviceInput *videoInput;
// 视频的输出源
@property (nonatomic,strong) AVCaptureVideoDataOutput *videoOutput;

// 文件输出(写入文件)
@property (nonatomic,strong) AVCaptureMovieFileOutput *fileOutput;

// 视频预览图层
@property (nonatomic,strong) AVCaptureVideoPreviewLayer *videoPreviewLayer;
// 用于在代理方法中区分音视频数据
@property (nonatomic,strong)  AVCaptureConnection *captureConnection;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
}

// 设置视频输入输出
- (void)setupVideoInputOutput {
    
    // 1、创建输入源
    // 1.1、 获取所有设备 (前置和后置摄像头)
    NSArray *devices = [AVCaptureDevice devicesWithMediaType:AVMediaTypeVideo];
    // 1.2、获取前置摄像头
   AVCaptureDevice *camera=  [[devices filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"position == %d", AVCaptureDevicePositionFront]] firstObject];
    // 1.3、通过前置摄像头创建输入设备
    NSError *error;
    self.videoInput = [AVCaptureDeviceInput deviceInputWithDevice:camera error:&error];
    if (error) {
        NSLog(@"Video输入设备创建失败");
        return;
    }
    
    // 2、创建输出源
    // 2.1 创建视频输出源
    self.videoOutput = [[AVCaptureVideoDataOutput alloc] init];
    // 2.2 设置代理，以及代理方法的执行队列(代理方法中拿到采集到的数据)
    dispatch_queue_t outputQueue = dispatch_queue_create("AVCaptureVideoDataOutputQueue", DISPATCH_QUEUE_SERIAL);
    [self.videoOutput setSampleBufferDelegate:self queue:outputQueue];
    
    // 丢弃延迟的帧
    self.videoOutput.alwaysDiscardsLateVideoFrames = YES;
    // 设置视频的数据格式 kCVPixelFormatType_420YpCbCr8BiPlanarFullRange YUV 数据格式
//    NSDictionary *videoSetting = [NSDictionary dictionaryWithObjectsAndKeys: [NSNumber numberWithInt:kCVPixelFormatType_420YpCbCr8BiPlanarFullRange], kCVPixelBufferPixelFormatTypeKey, nil];
//    [videoOutput setVideoSettings:videoSetting];
        
    // 3、添加输入输出源到会话中
    // 3.1、添加输入源到会话
    [self.captureSession beginConfiguration];
    if ([self.captureSession canAddInput:self.videoInput]) {
        [self.captureSession addInput:self.videoInput];
    }
    // 3.2、添加输出源到会话
    if ([self.captureSession canAddOutput:self.videoOutput]) {
        [self.captureSession addOutput:self.videoOutput];
    }
    [self.captureSession commitConfiguration];
    
    // 4、创建连接 (用于区分音视频)
    self.captureConnection = [self.videoOutput connectionWithMediaType:AVMediaTypeVideo];
    
    // 设置视频方向为竖屏方向
    self.captureConnection.videoOrientation = AVCaptureVideoOrientationPortrait;
    
    // 设置分辨率
    // 如果开启采集情况下需要修改分辨率或输入输出，需要用beginConfiguration和commitConfiguration
    // 把修改的代码包围起来。在调用beginConfiguration后，可以配置分辨率、输入输出等，直到调用commitConfiguration了才会被应用
    if ([self.captureSession canSetSessionPreset:AVCaptureSessionPreset1280x720]) {
        self.captureSession.sessionPreset = AVCaptureSessionPreset1280x720;
    }
    
    // 设置是否为镜像，前置摄像头采集到的数据本来就是翻转的，这里设置为镜像把画面转回来
    if (camera.position == AVCaptureDevicePositionFront && self.captureConnection.supportsVideoMirroring) {
        self.captureConnection.videoMirrored = YES;
    }
}

// 设置音频输入输出源
- (void)setupAudioInputOutput {
    
    // 1、创建音频输入
    AVCaptureDevice *device = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeAudio];
    NSError *error;
    AVCaptureDeviceInput *audioInput = [AVCaptureDeviceInput deviceInputWithDevice:device error:&error];
    if (error) {
        NSLog(@"Audio输入设备创建失败");
        return;
    }
    
    // 2、创建音频输出
    AVCaptureAudioDataOutput * audioOutput = [[AVCaptureAudioDataOutput alloc] init];
    // 设置代理，以及代理方法的执行队列(代理方法中拿到采集到的数据)
    dispatch_queue_t outputQueue = dispatch_queue_create("AVCaptureAudioDataOutputQueue", DISPATCH_QUEUE_SERIAL);
    [audioOutput setSampleBufferDelegate:self queue:outputQueue];
    
    // 3、添加音频输入输出源
    [self.captureSession beginConfiguration];
    if ([self.captureSession canAddInput:audioInput]) {
        [self.captureSession addInput:audioInput];
    }
    if ([self.captureSession canAddOutput:audioOutput]) {
        [self.captureSession addOutput:audioOutput];
    }
    [self.captureSession commitConfiguration];
}

// 添加预览图层
- (void)setupPreviewLayer {
    self.videoPreviewLayer = [AVCaptureVideoPreviewLayer layerWithSession:self.captureSession];
    self.videoPreviewLayer.frame = self.view.bounds;
    [self.view.layer insertSublayer:self.videoPreviewLayer atIndex:0];
//    self.videoPreviewLayer.videoGravity = AVLayerVideoGravityResizeAspectFill;
}

// 开始采集
- (IBAction)startCapture {
    
    // 先要判断摄像头和麦克风的权限是否拿到
    AVAuthorizationStatus videoAuthStatus = [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo];
    if (videoAuthStatus != AVAuthorizationStatusAuthorized)
    {
        NSLog(@"相机未授权");
        return;
    }
    
    // 1、创建捕捉会话
    self.captureSession = [[AVCaptureSession alloc] init];
    // 2、设置视频输入输出
    [self setupVideoInputOutput];
    // 3、设置音频输入输出
    [self setupAudioInputOutput];
    // 4、添加预览图层
    [self setupPreviewLayer];
    
    // 5、开始采集
    [self.captureSession startRunning];
    
    // 6、开始写入文件
    [self setupMovieFileOutput];
}

// 结束采集
- (IBAction)endCapture {
    [self.videoPreviewLayer removeFromSuperlayer];
    [self.captureSession stopRunning];
    self.captureSession = nil;
    
    // 停止写入文件
    [self.fileOutput stopRecording];
}

// 切换摄像头
- (IBAction)switchCamera {
    
    // 执行动画
    CATransition *animation = [CATransition animation];
    animation.type = @"oglFlip";
    animation.subtype = @"fromLeft";
    animation.duration = 0.5;
    [self.view.layer addAnimation:animation forKey:nil];
    
    // 获取所有摄像头
    NSArray *cameras= [AVCaptureDevice devicesWithMediaType:AVMediaTypeVideo];
    // 获取当前摄像头方向
    AVCaptureDevicePosition currentPosition = self.videoInput.device.position;
    AVCaptureDevicePosition toPosition = AVCaptureDevicePositionUnspecified;
    if (currentPosition == AVCaptureDevicePositionBack || currentPosition == AVCaptureDevicePositionUnspecified) {
        toPosition = AVCaptureDevicePositionFront;
    } else {
        toPosition = AVCaptureDevicePositionBack;
    }
    NSArray *captureDeviceArray = [cameras filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"position == %d", toPosition]];
    if (captureDeviceArray.count == 0){
        return;
    }
    NSError *error = nil;
    AVCaptureDevice *camera = captureDeviceArray.firstObject;
    
    // 开始配置
    [self.captureSession beginConfiguration];
    // 创建新的 input
    AVCaptureDeviceInput *newInput = [AVCaptureDeviceInput deviceInputWithDevice:camera error:&error];
    // 移除旧的输入，添加新的输入
    [self.captureSession removeInput:self.videoInput];
    if ([_captureSession canAddInput:newInput])
    {
        [_captureSession addInput:newInput];
        self.videoInput = newInput;// 保存新的输入
    }
    // 提交配置
    [self.captureSession commitConfiguration];

    // 重新获取连接并设置视频的方向、是否镜像
    self.captureConnection = [self.videoOutput connectionWithMediaType:AVMediaTypeVideo];
    self.captureConnection.videoOrientation = AVCaptureVideoOrientationPortrait;
    if (camera.position == AVCaptureDevicePositionFront && self.captureConnection.supportsVideoMirroring)
    {
        self.captureConnection.videoMirrored = YES;
    }
}

// 写入文件
- (void)setupMovieFileOutput {
    
    // 创建写入文件的输出
    self.fileOutput = [[AVCaptureMovieFileOutput alloc] init];
    [self.captureSession addOutput:self.fileOutput];
    // 获取视频的 connection
    AVCaptureConnection *connection = [self.fileOutput connectionWithMediaType:AVMediaTypeVideo];
    // 设置视频的稳定模式
    connection.preferredVideoStabilizationMode = AVCaptureVideoStabilizationModeAuto;
    
    // 开始写入视频
    NSString *path = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, true).firstObject stringByAppendingString:@"/xxx.mp4"];
    [self.fileOutput startRecordingToOutputFileURL:[NSURL fileURLWithPath:path] recordingDelegate:self];
}

#pragma mark - AVCaptureVideoDataOutputSampleBufferDelegate & AVCaptureAudioDataOutputSampleBufferDelegate

- (void)captureOutput:(AVCaptureOutput *)output didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer fromConnection:(AVCaptureConnection *)connection {
        
    if (connection == self.captureConnection) { // 视频数据回调
        NSLog(@"视频数据");
    }else { // 音频数据回调
        NSLog(@"音频数据");
    }
}

#pragma mark - AVCaptureFileOutputRecordingDelegate
// 开始写入文件
- (void)captureOutput:(AVCaptureFileOutput *)output didStartRecordingToOutputFileAtURL:(NSURL *)fileURL fromConnections:(NSArray<AVCaptureConnection *> *)connections {
    NSLog(@"开始写入文件");
}

// 文件写入完成
- (void)captureOutput:(AVCaptureFileOutput *)output didFinishRecordingToOutputFileAtURL:(NSURL *)fileURL fromConnections:(NSArray<AVCaptureConnection *> *)connections error:(nullable NSError *)error {
    NSLog(@"写入文件完成");
}

@end
