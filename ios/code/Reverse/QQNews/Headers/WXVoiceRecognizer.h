//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "VoiceDataPreProcessorDelegate.h"
#import "WXSpeechRecognizerRecorderDelegate.h"

@class NSString, VoiceDataPreProcessor, WXSpeechRecognizerConnection, WXSpeechRecognizerRecorder;

@interface WXVoiceRecognizer : NSObject <WXSpeechRecognizerRecorderDelegate, VoiceDataPreProcessorDelegate>
{
    WXSpeechRecognizerConnection *_connection;
    WXSpeechRecognizerRecorder *_recorder;
    VoiceDataPreProcessor *_voiceDataProcessor;
    _Bool _isStartRecord;
    _Bool _isStartProcess;
    _Bool _isProcessOnce;
    _Bool _isFinish;
    float _sampleRate;
    long long _maxResultCount;
    long long _resultType;
    long long _netType;
    float _outTime;
    long long _uselessLength;
    _Bool _needCallbackCancel;
    _Bool _isStartWithPcm;
    float _silTime;
    int _domain;
    id <WXVoiceDelegate> _delegate;
    id <WXRecorderDataDelegate> _recorderDataDelegate;
}

+ (void)releaseWXVoice;
+ (id)sharedWXVoice;
+ (id)allocWXVoice;
+ (id)alloc;
@property(nonatomic) id <WXRecorderDataDelegate> recorderDataDelegate; // @synthesize recorderDataDelegate=_recorderDataDelegate;
@property(nonatomic) float silTime; // @synthesize silTime=_silTime;
@property(nonatomic) id <WXVoiceDelegate> delegate; // @synthesize delegate=_delegate;
- (int)byteFromChar16:(BOOL)arg1;
- (_Bool)shouldSendData:(id)arg1 withUrlArgs:(id)arg2 delegate:(id)arg3;
- (void)voiceDataProcessNoData;
- (void)voiceDataProcessWaitForResult;
- (void)voiceInputVolumn:(float)arg1;
- (void)voiceDataProcessDidCancel;
- (void)voiceDataProcessResultArray:(id)arg1;
- (void)voiceDataProcessErrorCode:(long long)arg1 andHttpStatus:(long long)arg2;
- (void)voiceDataProcessResultData:(id)arg1;
- (void)voiceDataProcessResultJSonNSString:(id)arg1;
- (void)recorderRecordingBytes:(void *)arg1 length:(unsigned int)arg2;
- (void)cancelAll;
- (void)cancel;
- (void)finish;
- (void)canRecord;
- (_Bool)startRecord;
- (_Bool)startOnceWith16bitPCMData:(id)arg1 sampleRate:(int)arg2;
- (void)finishWith16bitPCMData;
- (_Bool)Add16bitPCMData:(id)arg1 sampleRate:(int)arg2 isEnd:(_Bool)arg3;
- (_Bool)Add16bitPCMData:(id)arg1 sampleRate:(int)arg2;
- (_Bool)startWith16bitPCMData;
- (_Bool)stopContinusMode;
- (_Bool)startContinusMode;
- (_Bool)startOnce;
- (_Bool)startOnceWithGrammarString:(id)arg1 andType:(int)arg2;
- (void)setResultType:(long long)arg1;
- (void)setMaxResultCount:(long long)arg1;
- (void)setLanguageType:(int)arg1;
- (void)setContinuousMode:(_Bool)arg1;
- (void)setAppID:(id)arg1;
- (void)returnRecorderData:(void *)arg1 length:(unsigned int)arg2;
- (void)returnRecorderData:(id)arg1;
- (id)autorelease;
- (oneway void)release;
- (unsigned long long)retainCount;
- (id)retain;
- (void)dealloc;
- (id)init;
@property(nonatomic) int domain; // @synthesize domain=_domain;
- (void)setAppendUrlParameterString:(id)arg1;
- (void)setAppendUrlString:(id)arg1;
- (void)setHostName:(id)arg1;
- (void)setServer:(id)arg1 andPort:(long long)arg2;
- (void)openAuth;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

