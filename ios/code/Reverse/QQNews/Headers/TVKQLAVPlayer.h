//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "AVPlayer.h"

@interface TVKQLAVPlayer : AVPlayer
{
    _Bool startedCache;
    _Bool cachedScuss;
    _Bool isPlaying;
    _Bool didStartCachedNextFile;
    _Bool cachedFinished;
    _Bool wasPreparedToPlay;
    _Bool itemReachEnd;
    _Bool didManualStartPlay;
    _Bool addedObserver;
    long long mediaFileIndex;
    long long checkedNums;
    long long checkedCachedFinishedNums;
    double ableDuration;
    double _iDownloadSpeed;
    double _startTime;
    double _endTime;
}

@property(nonatomic) double endTime; // @synthesize endTime=_endTime;
@property(nonatomic) double startTime; // @synthesize startTime=_startTime;
@property(nonatomic) double iDownloadSpeed; // @synthesize iDownloadSpeed=_iDownloadSpeed;
@property(nonatomic) _Bool addedObserver; // @synthesize addedObserver;
@property(nonatomic) _Bool didManualStartPlay; // @synthesize didManualStartPlay;
@property(nonatomic) _Bool itemReachEnd; // @synthesize itemReachEnd;
@property(nonatomic) double ableDuration; // @synthesize ableDuration;
@property(nonatomic) _Bool wasPreparedToPlay; // @synthesize wasPreparedToPlay;
@property(nonatomic) long long checkedCachedFinishedNums; // @synthesize checkedCachedFinishedNums;
@property(nonatomic) long long checkedNums; // @synthesize checkedNums;
@property(nonatomic) _Bool cachedFinished; // @synthesize cachedFinished;
@property(nonatomic) _Bool didStartCachedNextFile; // @synthesize didStartCachedNextFile;
@property(nonatomic) _Bool isPlaying; // @synthesize isPlaying;
@property(nonatomic) _Bool cachedScuss; // @synthesize cachedScuss;
@property(nonatomic) _Bool startedCache; // @synthesize startedCache;
@property(nonatomic) long long mediaFileIndex; // @synthesize mediaFileIndex;
- (void)playWithRate:(double)arg1;
- (double)itemDownloadSpeed;
- (void)endCache;
- (void)startCache;
- (_Bool)videoIsVisual;
- (void)replaceCurrentItemWithPlayerItem:(id)arg1;
- (id)initWithPlayerItem:(id)arg1;

@end

