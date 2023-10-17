//
//  XMGCallController.m
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/30.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import "XMGCallController.h"
#import <AVFoundation/AVFoundation.h>

@interface XMGCallController ()<EMCallManagerDelegate,AVCaptureVideoDataOutputSampleBufferDelegate>
{
    UInt8 *_imageDataBuffer;
}
/** 当前的绘画 */
@property (nonatomic, strong) AVCaptureSession *session;

@property (nonatomic,assign)int time;

/** 时间标签 */
@property (nonatomic, weak) UILabel *callTimeLbl;

/** timer */
@property (nonatomic, weak) NSTimer *timer;

/** 按钮等控件 */
@property (nonatomic, weak) UIView *content;

/** GLView20 */
@property (nonatomic, weak) OpenGLView20 *openGLView20;
@end

@implementation XMGCallController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.time = 0;
    
    // 初始化子控件
    [self setup];
    
    if (self.currentSession.type == eCallSessionTypeVideo) {
        //初始化摄像头
        [self _initCamera];
        // 开始会话
        [self.session startRunning];
        // 将按钮等控件移到屏幕的最前方
        [self.view bringSubviewToFront:self.content];
        // 视频时对方图像显示的区域
        self.currentSession.displayView = self.openGLView20;
    }
}

- (void)_initCamera
{
    // 大窗口
    OpenGLView20 *openGLView = [[OpenGLView20 alloc]init];
    openGLView.backgroundColor = [UIColor clearColor];
    openGLView.frame = CGRectMake(0, 0, self.view.width, self.view.height);
//    AVCaptureSessionPreset352x288
//    AVCaptureSessionPreset640x480
    openGLView.sessionPreset = AVCaptureSessionPreset352x288;
    [self.view addSubview:openGLView];
    
    self.openGLView20 = openGLView;
    
    // 小窗口
    UIView *smallView = [[UIView alloc]init];
    smallView.frame = CGRectMake(self.view.width - 90, kWeChatAllSubviewHeight, 80, 120);
    smallView.backgroundColor = [UIColor clearColor];
    [self.view addSubview:smallView];
    
    // 创建会话层
    self.session = [[AVCaptureSession alloc]init];
    [self.session setSessionPreset:openGLView.sessionPreset];
    
    // 输入
    AVCaptureDevice *device;
    NSArray *devices = [AVCaptureDevice devicesWithMediaType:AVMediaTypeVideo];
    for (AVCaptureDevice *temp in devices) {
        if (temp.position == AVCaptureDevicePositionFront) {
            device = temp;
            break;
        }
    }
    NSError *error = nil;
    AVCaptureDeviceInput *deviceInput = [AVCaptureDeviceInput deviceInputWithDevice:device error:&error];
    [self.session beginConfiguration];
    if (!error) {
        [self.session addInput:deviceInput];
    }
    
    // 输出
    AVCaptureVideoDataOutput *outPut = [[AVCaptureVideoDataOutput alloc]init];
    outPut = [[AVCaptureVideoDataOutput alloc] init];
    outPut.videoSettings = openGLView.outputSettings;
    outPut.minFrameDuration = CMTimeMake(1, 15);
    outPut.alwaysDiscardsLateVideoFrames = YES;
    dispatch_queue_t outQueue = dispatch_queue_create("com.gh.cecall", NULL);
    [outPut setSampleBufferDelegate:self queue:outQueue];
    [self.session addOutput:outPut];
    [self.session commitConfiguration];
    
    
    // 小窗口显示层
    AVCaptureVideoPreviewLayer *smallViewLayer = [[AVCaptureVideoPreviewLayer alloc]initWithSession:self.session];
    smallViewLayer.frame = CGRectMake(0, 0, smallView.width, smallView.height);
    smallViewLayer.videoGravity = AVLayerVideoGravityResizeAspectFill;
    [smallView.layer addSublayer:smallViewLayer];
    
}

-(void)captureOutput:(AVCaptureOutput *)captureOutput
didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer
      fromConnection:(AVCaptureConnection *)connection
{
    if (self.currentSession.status != eCallSessionStatusAccepted) {
        return;
    }
#warning 捕捉数据输出，根据自己需求可随意更改
    CVImageBufferRef imageBuffer = CMSampleBufferGetImageBuffer(sampleBuffer);
    if(CVPixelBufferLockBaseAddress(imageBuffer, 0) == kCVReturnSuccess)
    {
        UInt8 *bufferPtr = (UInt8 *)CVPixelBufferGetBaseAddressOfPlane(imageBuffer, 0);
        UInt8 *bufferPtr1 = (UInt8 *)CVPixelBufferGetBaseAddressOfPlane(imageBuffer, 1);
        
        size_t width = CVPixelBufferGetWidth(imageBuffer);
        size_t height = CVPixelBufferGetHeight(imageBuffer);
        size_t bytesrow0 = CVPixelBufferGetBytesPerRowOfPlane(imageBuffer, 0);
        size_t bytesrow1  = CVPixelBufferGetBytesPerRowOfPlane(imageBuffer, 1);
        
        if (_imageDataBuffer == nil) {
            _imageDataBuffer = (UInt8 *)malloc(width * height * 3 / 2);
        }
        UInt8 *pY = bufferPtr;
        UInt8 *pUV = bufferPtr1;
        UInt8 *pU = _imageDataBuffer + width * height;
        UInt8 *pV = pU + width * height / 4;
        for(int i =0; i < height; i++)
        {
            memcpy(_imageDataBuffer + i * width, pY + i * bytesrow0, width);
        }
        
        for(int j = 0; j < height / 2; j++)
        {
            for(int i = 0; i < width / 2; i++)
            {
                *(pU++) = pUV[i<<1];
                *(pV++) = pUV[(i<<1) + 1];
            }
            pUV += bytesrow1;
        }
        
        YUV420spRotate90(bufferPtr, _imageDataBuffer, width, height);
        [[EaseMob sharedInstance].callManager processPreviewData:(char *)bufferPtr width:width height:height];
        
        /*We unlock the buffer*/
        CVPixelBufferUnlockBaseAddress(imageBuffer, 0);
    }
}


//我们可以对摄像头采集的YUV420sp数据做很多的转换，这里直接使用环信的算法即可
void YUV420spRotate90(UInt8 *  dst, UInt8* src, size_t srcWidth, size_t srcHeight)
{
    size_t wh = srcWidth * srcHeight;
    size_t uvHeight = srcHeight >> 1;//uvHeight = height / 2
    size_t uvWidth = srcWidth>>1;
    size_t uvwh = wh>>2;
    //旋转Y
    int k = 0;
    for(int i = 0; i < srcWidth; i++) {
        int nPos = wh-srcWidth;
        for(int j = 0; j < srcHeight; j++) {
            dst[k] = src[nPos + i];
            k++;
            nPos -= srcWidth;
        }
    }
    for(int i = 0; i < uvWidth; i++) {
        int nPos = wh+uvwh-uvWidth;
        for(int j = 0; j < uvHeight; j++) {
            dst[k] = src[nPos + i];
            dst[k+uvwh] = src[nPos + i+uvwh];
            k++;
            nPos -= uvWidth;
        }
    }
}





- (void)setup
{
    // 1. 背景图片
    UIImageView *imgView = [[UIImageView alloc]init];
    imgView.frame = CGRectMake(0, 0, self.view.width, self.view.height);
    imgView.image = [UIImage imageNamed:@"callBg"];
    [self.view addSubview:imgView];
    
    // contentView
    UIView *contentView = [[UIView alloc]init];
    contentView.frame = CGRectMake(0, 0, self.view.width, self.view.height);
    contentView.backgroundColor = [UIColor clearColor];
    [self.view addSubview:contentView];
    self.content = contentView;
    
    // 2. 时间标签
    UILabel *timeLbl = [[UILabel alloc]init];
    timeLbl.frame = CGRectMake(0, kWeChatPadding, contentView.width, kWeChatAllSubviewHeight);
    timeLbl.textAlignment = NSTextAlignmentCenter;
    timeLbl.backgroundColor = [UIColor clearColor];
    [contentView addSubview:timeLbl];
    
    self.callTimeLbl = timeLbl;
    
    // 3. 同意按钮
    XMGNButton *acceptBtn = [XMGNButton createXMGButton];
    acceptBtn.frame = CGRectMake(kWeChatPadding*2, kWeChatScreenHeight - kWeChatAllSubviewHeight - kWeChatPadding, (kWeChatScreenWidth - (kWeChatPadding*2)*3)/2, kWeChatAllSubviewHeight);
    [acceptBtn setTitle:@"同意" forState:UIControlStateNormal];
    [contentView addSubview:acceptBtn];
    
    // 4. 拒绝按钮
    XMGNButton *cancelBtn = [XMGNButton createXMGButton];
    cancelBtn.frame = CGRectMake(acceptBtn.right + kWeChatPadding*2, kWeChatScreenHeight - kWeChatAllSubviewHeight - kWeChatPadding, (kWeChatScreenWidth - (kWeChatPadding*2)*3)/2, kWeChatAllSubviewHeight);
    [cancelBtn setTitle:@"退出" forState:UIControlStateNormal];
    [contentView addSubview:cancelBtn];
    
    
    // 按钮的点击事件
    acceptBtn.block = ^(XMGNButton *btn){
        [[EaseMob sharedInstance].callManager asyncAnswerCall:self.currentSession.sessionId];

    };
    
    
    cancelBtn.block = ^(XMGNButton *btn){
        // 停止timer
        [self.timer invalidate];
        [[EaseMob sharedInstance].callManager asyncEndCall:self.currentSession.sessionId reason:eCallReasonHangup];
        [self dismissViewControllerAnimated:YES completion:nil];
    };
    // 添加代理
    [[EaseMob sharedInstance].callManager addDelegate:self delegateQueue:nil];
}

#pragma mark - 实时通话的代理
- (void)callSessionStatusChanged:(EMCallSession *)callSession changeReason:(EMCallStatusChangedReason)reason error:(EMError *)error
{
    NSLog(@"callSessionStatusChanged  callSession = %@ reason = %ld type = %zd",callSession,reason,callSession.status);
    if (callSession.status == eCallSessionStatusAccepted) {
        self.timer = [NSTimer scheduledTimerWithTimeInterval:1.0f target:self selector:@selector(callTime) userInfo:nil repeats:YES];

    }

}

- (void)callTime
{
    NSLog(@"====%d",self.time);
    self.time ++;
    
//    0:0:01
    int hour = self.time/3600;
    int min = (self.time - hour*3600)/60;
    int sec = self.time - hour*3600 - min * 60;
    
    NSLog(@"%d %d %d",hour,min,sec);
    NSString *timeLblStr = nil;
    if (hour > 0) {
        timeLblStr = [NSString stringWithFormat:@"%d:%d:%d",hour,min,sec];
    }else if(min > 0){
        timeLblStr = [NSString stringWithFormat:@"0:%d:%02d",min,sec];
    }else{
        // 保证数字是两位  如果不满足两位 那么用0来填补
        timeLblStr = [NSString stringWithFormat:@"0:0:%02d",sec];

    }
    
    self.callTimeLbl.text = timeLblStr;
}


- (void)dealloc
{
    [[EaseMob sharedInstance].callManager removeDelegate:self];
}


@end
