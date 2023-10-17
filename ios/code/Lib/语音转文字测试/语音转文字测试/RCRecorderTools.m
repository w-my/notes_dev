//
//  RCRecorderTools.m
//  语音转文字测试
//
//  Created by wtw on 2018/11/8.
//  Copyright © 2018 wtw. All rights reserved.
//

#import "RCRecorderTools.h"
#import <Speech/Speech.h>
#import <AVFoundation/AVFoundation.h>

#define ALPHA 0.02f  // 音频振幅调解相对值 (越小振幅就越高)

@interface RCRecorderTools ()<SFSpeechRecognizerDelegate>

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

@end

@implementation RCRecorderTools

singleton_M(RCRecorderTools);

#pragma mark -
- (void)startRecordWithCallBack:(void (^)(BOOL availiable,NSString *formattedString))block {
    //获取麦克风权限
    __weak typeof(self) weakself = self;
    [self micPhonePermissions:^(BOOL availiable) {
        __strong typeof(weakself) strongSelf = weakself;
        if (availiable) {
            //获取语音识别权限
            [strongSelf requestSpeecAuthorization:^(BOOL availiable) {
                if (availiable) {
                    if (![strongSelf initAudioRecord]) {
                        //录音创建失败
                        return ;
                    }else {
                     //开始录音
                        if ([strongSelf.audioRecorder isRecording]) {
                            [strongSelf.audioRecorder stop];
                        }
                        [strongSelf.audioRecorder record];
                        //开始语音识别
                        if (strongSelf.audioEngine.isRunning) {
                            [strongSelf endRecord];
                        }
                        [strongSelf initSpeechWithCallback:^(NSString *value) {
                            if (block) {
                                block(YES,value);
                            }
                        }];
                    }
                }else {
                    return;
                    //提示开启权限
                }
            }];
        }else {
            return;
           //提示开启权限
        }
    }];
}

#pragma mark -
- (void)endRecord{
    //停止录音
    [_audioRecorder stop];
    //删除录音文件
    [_audioRecorder deleteRecording];
    //停止语音识别
    [_audioEngine stop];
    if (_recognitionTask) {
        [_recognitionTask cancel];
        _recognitionTask = nil;
    }
    if (_recognitionRequest) {
        [_recognitionRequest endAudio];
    }
}

#pragma mark -
- (float)levels {
    if (_audioRecorder) {
        [_audioRecorder updateMeters];
        double aveChannel = pow(10, (ALPHA * [_audioRecorder averagePowerForChannel:0]));
        if (aveChannel <= 0.05f) aveChannel = 0.05f;
        
        if (aveChannel >= 1.0f) aveChannel = 1.0f;
        
        return aveChannel;
    }
    return 0;
}

//判断麦克风权限
- (void)micPhonePermissions:(void(^)(BOOL availiable)) block {
    __block BOOL ret = NO;
    AVAudioSession *session = [AVAudioSession sharedInstance];
    if ([session respondsToSelector:@selector(requestRecordPermission:)]) {
        [session requestRecordPermission:^(BOOL granted) {
            if (granted) {
                ret = YES;
                dispatch_async(dispatch_get_main_queue(), ^{
                    if (block) {
                        block(ret);
                    }
                });
            }
        }];
    }
}

//判断语音识别权限
- (void)requestSpeecAuthorization:(void(^)(BOOL availiable))block {
    //申请权限认证
    [SFSpeechRecognizer requestAuthorization:^(SFSpeechRecognizerAuthorizationStatus status) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if (status == SFSpeechRecognizerAuthorizationStatusAuthorized) {
                if(block){
                    block(YES);
                }
            }else {
                if (block) {
                    block(NO);
                }
            }
        });
    }];
}

//录音初始化配置
- (BOOL)initAudioRecord {
    //录音文件存放路径
    NSString *documentDir = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
    NSString *rcvoiceFolderPath = [NSString stringWithFormat:@"%@/rcVoice",documentDir];
    NSURL *url = [NSURL URLWithString:rcvoiceFolderPath];
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
    NSError *error = nil;
    _audioRecorder = [[AVAudioRecorder alloc] initWithURL:url settings:recordSettings error:&error];
    _audioRecorder.meteringEnabled = YES;
    return !error;
}

//语音识别初始化 并返回识别结果
- (void)initSpeechWithCallback:(void(^)(NSString *value))block {
    if (_recognitionTask) {
        [_recognitionTask cancel];
        _recognitionTask = nil;
    }
    NSError *error;
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
            //回调语音转文字结果
            if (block) {
                block(result.bestTranscription.formattedString);
            }
            isFinal = result.isFinal;
        }
        if (error || isFinal) {
            [strongSelf.audioEngine stop];
            [strongSelf.audioRecorder stop];
            [inputNode removeTapOnBus:0];
            strongSelf.recognitionTask = nil;
            strongSelf.recognitionRequest = nil;
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
}

- (void)speechRecognizer:(SFSpeechRecognizer *)speechRecognizer availabilityDidChange:(BOOL)available {
    if (available) { //语音识别可用
       
    }else {  //语音识别不可用
        
    }
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
