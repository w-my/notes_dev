//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class AVAsset, AVAssetReader, AVAssetReaderAudioMixOutput, AVAssetWriter, AVAssetWriterInput, AVAudioMix, NSDictionary, NSError, NSObject<OS_dispatch_queue>, NSURL;

@interface MVAudioAssetExportSession : NSObject
{
    float _progress;
    float _lastProgress;
    AVAsset *_asset;
    NSURL *_outputURL;
    AVAudioMix *_audioMix;
    NSDictionary *_audioSettings;
    CDUnknownBlockType _didUpdateProgress;
    NSObject<OS_dispatch_queue> *_workQueue;
    AVAssetReaderAudioMixOutput *_audioOutput;
    AVAssetWriterInput *_audioInput;
    AVAssetReader *_reader;
    AVAssetWriter *_writer;
    CDUnknownBlockType _completionHandler;
    NSError *_error;
    long long _status;
    double _duration;
    CDStruct_e83c9415 _timeRange;
}

+ (id)exportSessionWithAsset:(id)arg1;
@property(nonatomic) double duration; // @synthesize duration=_duration;
@property(nonatomic) float lastProgress; // @synthesize lastProgress=_lastProgress;
@property(nonatomic) long long status; // @synthesize status=_status;
@property(retain, nonatomic) NSError *error; // @synthesize error=_error;
@property(copy, nonatomic) CDUnknownBlockType completionHandler; // @synthesize completionHandler=_completionHandler;
@property(retain, nonatomic) AVAssetWriter *writer; // @synthesize writer=_writer;
@property(retain, nonatomic) AVAssetReader *reader; // @synthesize reader=_reader;
@property(retain, nonatomic) AVAssetWriterInput *audioInput; // @synthesize audioInput=_audioInput;
@property(retain, nonatomic) AVAssetReaderAudioMixOutput *audioOutput; // @synthesize audioOutput=_audioOutput;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *workQueue; // @synthesize workQueue=_workQueue;
@property(readonly, nonatomic) float progress; // @synthesize progress=_progress;
@property(copy, nonatomic) CDUnknownBlockType didUpdateProgress; // @synthesize didUpdateProgress=_didUpdateProgress;
@property(copy, nonatomic) NSDictionary *audioSettings; // @synthesize audioSettings=_audioSettings;
@property(copy, nonatomic) AVAudioMix *audioMix; // @synthesize audioMix=_audioMix;
@property(copy, nonatomic) NSURL *outputURL; // @synthesize outputURL=_outputURL;
@property(nonatomic) CDStruct_e83c9415 timeRange; // @synthesize timeRange=_timeRange;
@property(readonly, nonatomic) AVAsset *asset; // @synthesize asset=_asset;
- (void).cxx_destruct;
- (void)cancelExport;
- (void)notifyComplete;
- (void)finish;
- (void)updateProgressWithCurrentFrameTime:(CDStruct_1b6d18a9)arg1;
- (_Bool)encodeSamplesFromOutput:(id)arg1 toInput:(id)arg2;
- (void)exportAsynchronouslyWithCompletionHandler:(CDUnknownBlockType)arg1;
- (id)initWithAsset:(id)arg1;

@end

