//
//  ViewController.m
//  语音转文字测试
//
//  Created by wtw on 2018/10/30.
//  Copyright © 2018 wtw. All rights reserved.
//

#import "ViewController.h"
#import <Speech/Speech.h>
#import <AVFoundation/AVFoundation.h>
#import "RCSingleton.h"
#import "RCRecorderTools.h"

#define ALPHA 0.02f                 // 音频振幅调解相对值 (越小振幅就越高)

@interface ViewController ()<SFSpeechRecognizerDelegate>
//录音引擎
@property (nonatomic,strong) AVAudioEngine *audioEngine;
//语音识别器
@property (nonatomic,strong) SFSpeechRecognizer *speechRecognizer;
//语音识别任务
@property (nonatomic,strong) SFSpeechRecognitionTask *recognitionTask;
//语音识别请求
@property (nonatomic,strong) SFSpeechAudioBufferRecognitionRequest *recognitionRequest;

//录音
@property (nonatomic,strong) AVAudioRecorder *audioRecorder;
@property (nonatomic,strong) NSTimer *timer;



@property (weak, nonatomic) IBOutlet UIButton *speechBtn;
@property (nonatomic,strong) UILabel *resultStringLable;

@end

@implementation ViewController

singleton_M(ViewController);

- (IBAction)startRecord {
//    if (self.audioEngine.isRunning) {
//        [self endRecording];
//        [self.speechBtn setTitle:@"正在停止" forState:UIControlStateDisabled];
//    }else {
//        [self startRecording];
//        [self.speechBtn setTitle:@"停止录音" forState:UIControlStateNormal];
//    }
    
    [[RCRecorderTools sharedRCRecorderTools] startRecordWithCallBack:^(BOOL availiable, NSString *formattedString) {
        NSLog(@"%@",formattedString);
    }];
}

- (void)endRecording {
    [self.audioEngine stop];
    [_audioRecorder stop]; //结束录音
    if (_recognitionRequest) {
        [_recognitionRequest endAudio];
    }
    if (_recognitionTask) {
        [_recognitionTask cancel];
        _recognitionTask = nil;
    }
    self.speechBtn.enabled = NO;
}

- (void)viewDidLoad {
    [super viewDidLoad];    
    //请求授权
    [self requestAuthorization];
    
    _resultStringLable = [[UILabel alloc] initWithFrame:CGRectMake(20, 40, 300, 300)];
    _resultStringLable.numberOfLines = 0;
    _resultStringLable.backgroundColor = [UIColor greenColor];
    _resultStringLable.text= @"123";
    [self.view addSubview:_resultStringLable];
}

//请求权限
- (void)requestAuthorization {
    /* 需要在info.plist 文件中添加权限
     <key>NSSpeechRecognitionUsageDescription</key>
     <string>请允许语音识别</string>
     <key>NSMicrophoneUsageDescription</key>
     <string>请打开麦克风</string>
     */
    //申请权限认证
    [SFSpeechRecognizer requestAuthorization:^(SFSpeechRecognizerAuthorizationStatus status) {
        dispatch_async(dispatch_get_main_queue(), ^{
            switch (status) {
                case SFSpeechRecognizerAuthorizationStatusNotDetermined:
                    NSLog(@"语音识别未授权");
                    break;
                case SFSpeechRecognizerAuthorizationStatusDenied:
                    NSLog(@"用户未授权使用语音识别");
                    break;
                case SFSpeechRecognizerAuthorizationStatusRestricted:
                    NSLog(@"语音识别在这台设备上受到限制");
                    break;
                case SFSpeechRecognizerAuthorizationStatusAuthorized:
                    NSLog(@"开始录音");
                    break;
                default:
                    break;
            }
        });
    }];
}

//开始识别语音
- (void)startRecording {
    if (_recognitionTask) {
        [_recognitionTask cancel];
        _recognitionTask = nil;
    }
    
    //获取session
    AVAudioSession *audioSession = [AVAudioSession sharedInstance];
    NSError *error;
    //设置类别 当开始录音时关闭其他的app session
    //返回值为BOOL 值，YES 为可用
    [audioSession setCategory:AVAudioSessionCategoryRecord error:&error];
    NSParameterAssert(!error);
    //设置模式 最小系统模式
    [audioSession setMode:AVAudioSessionModeMeasurement error:&error];
    NSParameterAssert(!error);
    //激活session 并设置解除激活后恢复其他app的session状态
    [audioSession setActive:YES withOptions:AVAudioSessionSetActiveOptionNotifyOthersOnDeactivation error:&error];
    NSParameterAssert(!error);
    
    
    //处理录音
    //录音存放位置
    NSString *documentDir = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
    NSString *cwFolderPath = [NSString stringWithFormat:@"%@/CWVoice",documentDir];
    NSURL *url = [NSURL URLWithString:cwFolderPath];
    //设置录音参数
    NSMutableDictionary *recordSettings = [NSMutableDictionary dictionary];
    //设置编码格式
    [recordSettings setValue:[NSNumber numberWithInt:kAudioFormatLinearPCM] forKey:AVFormatIDKey];
    //采样率
    [recordSettings setValue:[NSNumber numberWithFloat:11025.0] forKey:AVSampleRateKey];
    //通道数
    [recordSettings setValue:[NSNumber numberWithInt:1] forKey:AVNumberOfChannelsKey];
    //音频质量，采样质量
    [recordSettings setValue:[NSNumber numberWithFloat:AVAudioQualityMin] forKey:AVEncoderAudioQualityKey];
    //创建录音对象
    _audioRecorder = [[AVAudioRecorder alloc] initWithURL:url settings:recordSettings error:&error];
    NSAssert(_audioRecorder, @"录音对象创建失败");
    _audioRecorder.meteringEnabled = YES;
    
    //判断麦克风权限
    [self micPhonePermissions:^(BOOL isavailable) {
        if (isavailable) {
            //开始录音
            [_audioRecorder record];
        }else {
            //提示开启麦克风权限
        }
    }];
    
    //语音识别请求
    _recognitionRequest = [[SFSpeechAudioBufferRecognitionRequest alloc] init];
    AVAudioInputNode *inputNode = self.audioEngine.inputNode;
    NSAssert(inputNode, @"录入设备没有准备好");
    NSAssert(_recognitionRequest, @"请求初始化失败");
    //一有结果就返回
    _recognitionRequest.shouldReportPartialResults = YES;
    
    //开始识别任务
    __weak typeof(self) weakSelf = self;
    _recognitionTask = [self.speechRecognizer recognitionTaskWithRequest:_recognitionRequest resultHandler:^(SFSpeechRecognitionResult * _Nullable result, NSError * _Nullable error) {
        __strong typeof(weakSelf) strongSelf = weakSelf;
        NSLog(@"%@",result);
        BOOL isFinal = NO;
        if (result) {
            //语音转文字
            strongSelf.resultStringLable.text = result.bestTranscription.formattedString;
            isFinal = result.isFinal;
        }
        if (error || isFinal) {
            [self.audioEngine stop];
            [_timer invalidate];
            [inputNode removeTapOnBus:0];
            strongSelf.recognitionTask = nil;
            strongSelf.recognitionRequest = nil;
            
            strongSelf.speechBtn.enabled = YES;
            [strongSelf.speechBtn setTitle:@"开始录音" forState:UIControlStateNormal];
        }
    }];
    
    // 监听一个标识位并拼接流文件
    AVAudioFormat *recordingFormat = [inputNode outputFormatForBus:0];
    //添加之前先移除 不然会崩溃
    [inputNode removeTapOnBus:0];
    [inputNode installTapOnBus:0 bufferSize:1024 format:recordingFormat block:^(AVAudioPCMBuffer * _Nonnull buffer, AVAudioTime * _Nonnull when) {
        __strong typeof(weakSelf) strongSelf = weakSelf;
        if (strongSelf.recognitionRequest) {
            [strongSelf.recognitionRequest appendAudioPCMBuffer:buffer];
        }
    }];
    
    //准备并启动引擎
    [self.audioEngine prepare];
    [self.audioEngine startAndReturnError:&error];
    NSParameterAssert(!error);
    self.resultStringLable.text = @"123";
    
    //开启定时器
    _timer = [NSTimer scheduledTimerWithTimeInterval:1.0f repeats:YES block:^(NSTimer * _Nonnull timer) {
        NSLog(@"== levels ==   %f == ",[self levels]);
    }];
}

- (void)speechRecognizer:(SFSpeechRecognizer *)speechRecognizer availabilityDidChange:(BOOL)available {
    if (available) { //语音识别可用
        self.speechBtn.enabled = YES;
        [self.speechBtn setTitle:@"开始录音" forState:UIControlStateNormal];
    }else {  //语音识别不可用
        self.speechBtn.enabled = NO;
        [self.speechBtn setTitle:@"语音识别不可用" forState:UIControlStateDisabled];
    }
}

#pragma amrk - 录音相关
//判断麦克风权限
- (void)micPhonePermissions:(void(^)(BOOL isavailable)) available {
    __block BOOL ret = NO;
    AVAudioSession *session = [AVAudioSession sharedInstance];
    if ([session respondsToSelector:@selector(requestRecordPermission:)]) {
        [session requestRecordPermission:^(BOOL granted) {
            if (granted) {
                ret = YES;
                dispatch_async(dispatch_get_main_queue(), ^{
                    if (available) {
                        available(ret);
                    }
                });
            }
        }];
    }
}

//获取振幅
- (float)levels {
    [_audioRecorder updateMeters];
    double aveChannel = pow(10, (ALPHA * [self.audioRecorder averagePowerForChannel:0]));
    if (aveChannel <= 0.05f) aveChannel = 0.05f;
    
    if (aveChannel >= 1.0f) aveChannel = 1.0f;
    
    return aveChannel;
}

#pragma mark -

//创建语音识别器并设置语言
- (SFSpeechRecognizer *)speechRecognizer {
    if (!_speechRecognizer) {
        NSLocale *locale = [NSLocale localeWithLocaleIdentifier:@"zh-CN"];
        _speechRecognizer = [[SFSpeechRecognizer alloc] initWithLocale:locale];
        _speechRecognizer.delegate = self;
    }
    return _speechRecognizer;
}

//创建录音引擎
- (AVAudioEngine *)audioEngine {
    if (!_audioEngine) {
        _audioEngine = [[AVAudioEngine alloc] init];
    }
    return _audioEngine;
}

@end
