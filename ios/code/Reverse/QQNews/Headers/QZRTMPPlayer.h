//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSFileHandle, NSObject<OS_dispatch_queue>, NSString, NSTimer, QZAACPlayer, QZH264Renderer, QZLiveStatistic, UIView;

@interface QZRTMPPlayer : NSObject
{
    NSString *_address;
    QZAACPlayer *_audioPlayer;
    QZH264Renderer *_h264Renderer;
    unsigned long long _status;
    long long _RTMPTimeout;
    long long _firstFrameType;
    unsigned int _videoStartTimestamp;
    unsigned int _audioStartTimestamp;
    unsigned int _previousVideoTimestamp;
    unsigned int _previousAudioTimestamp;
    unsigned int _videoLagCount;
    unsigned int _audioLagCount;
    UIView *_statusView;
    unsigned long long _downloadRate;
    NSTimer *_updateStatusTimer;
    unsigned long long _bytesReceived;
    unsigned int _videoPacketsReceived;
    unsigned int _audioPacketsReceived;
    double _startTime;
    double _bufferingStartTime;
    NSObject<OS_dispatch_queue> *_playingQueue;
    _Bool _closed;
    struct RTMPInputStream *_currentStream;
    NSFileHandle *_dumpFileHandle;
    long long _lagCount;
    _Bool _hasReceiveAudioPackage;
    _Bool _hasReceiveVideoPackage;
    double _noPacketTime;
    double _lastVideoPacketTime;
    double _lastAudioPacketTime;
    unsigned int _videoPacketsNum;
    unsigned int _audioPacketsNum;
    unsigned long long _lastCalcTime;
    int _videoKaPacketNum;
    int _showFps;
    unsigned int _videoLastTimeStamp;
    unsigned int _audioLastTimeStamp;
    _Bool _startVideoImmediately;
    QZLiveStatistic *_statistic;
    NSString *_dumpFilePath;
    long long _lagReportThreshold;
    double _reducePlayRate;
    CDUnknownBlockType _onConnectionError;
    double _bufferingCheckTime;
}

+ (void)load;
@property(nonatomic) double bufferingCheckTime; // @synthesize bufferingCheckTime=_bufferingCheckTime;
@property(copy, nonatomic) CDUnknownBlockType onConnectionError; // @synthesize onConnectionError=_onConnectionError;
@property(nonatomic) double reducePlayRate; // @synthesize reducePlayRate=_reducePlayRate;
@property(nonatomic) long long lagReportThreshold; // @synthesize lagReportThreshold=_lagReportThreshold;
@property(nonatomic) _Bool startVideoImmediately; // @synthesize startVideoImmediately=_startVideoImmediately;
@property(copy, nonatomic) NSString *dumpFilePath; // @synthesize dumpFilePath=_dumpFilePath;
@property(retain, nonatomic) QZLiveStatistic *statistic; // @synthesize statistic=_statistic;
- (void).cxx_destruct;
- (id)statusView;
- (void)CalcSendFps:(_Bool)arg1;
- (void)updateStatus;
- (id)videoSizeString;
- (id)NALUType:(char *)arg1;
- (void)setStatus:(unsigned long long)arg1;
- (void)notyifyStatusChange:(long long)arg1;
@property(readonly) unsigned long long status;
- (id)address;
- (_Bool)isShowed;
- (void)removeFromView:(id)arg1;
- (void)showInView:(id)arg1 defaultView:(id)arg2 isFullScreen:(_Bool)arg3;
- (void)showInView:(id)arg1 defaultImage:(id)arg2 isFullScreen:(_Bool)arg3;
- (void)handleVideoPacket:(struct RTMPPacket)arg1;
- (void)handleAudioPacket:(struct RTMPPacket)arg1;
- (void)handlePacket:(struct RTMPPacket)arg1;
@property(nonatomic) long long minLocalAudioCache;
@property(nonatomic) long long maxLocalAudioCache;
- (void)resumeVideo;
- (void)pauseVideo;
- (void)resumeAudio;
- (void)pauseAudio;
- (void)setCloseDataReport;
- (unsigned long long)getCurTime;
- (void)start;
- (void)prepare;
- (void)close;
- (void)setClosed:(_Bool)arg1;
@property(readonly) _Bool closed;
- (void)audioDidStart:(id)arg1;
- (void)audioDidPause:(id)arg1;
- (id)initWithAddress:(id)arg1 timeout:(long long)arg2 statistic:(id)arg3;
- (void)dealloc;

@end

