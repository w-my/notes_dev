//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TLNViewBase.h"

#import "TLNEventHandlerProtocol.h"
#import "TLNPlayerViewDelegate.h"

@class NSString, TLNPlayerView, TLNVideoInfo;

@interface TLNVideoView : TLNViewBase <TLNEventHandlerProtocol, TLNPlayerViewDelegate>
{
    _Bool _isVisable;
    NSString *_vid;
    long long _videoType;
    long long _currentTime;
    long long _totalTime;
    long long _maxViewTime;
    double _videoLoadDuration;
    TLNViewBase *_pageView;
    TLNPlayerView *_playerView;
    TLNVideoInfo *_videoInfo;
    double _startTime;
    struct CGPoint _currentOffset;
}

@property(nonatomic) double startTime; // @synthesize startTime=_startTime;
@property(retain, nonatomic) TLNVideoInfo *videoInfo; // @synthesize videoInfo=_videoInfo;
@property(retain, nonatomic) TLNPlayerView *playerView; // @synthesize playerView=_playerView;
@property(nonatomic) _Bool isVisable; // @synthesize isVisable=_isVisable;
@property(nonatomic) __weak TLNViewBase *pageView; // @synthesize pageView=_pageView;
@property(nonatomic) struct CGPoint currentOffset; // @synthesize currentOffset=_currentOffset;
@property(nonatomic) double videoLoadDuration; // @synthesize videoLoadDuration=_videoLoadDuration;
@property(nonatomic) long long maxViewTime; // @synthesize maxViewTime=_maxViewTime;
@property(nonatomic) long long totalTime; // @synthesize totalTime=_totalTime;
@property(nonatomic) long long currentTime; // @synthesize currentTime=_currentTime;
@property(nonatomic) long long videoType; // @synthesize videoType=_videoType;
@property(copy, nonatomic) NSString *vid; // @synthesize vid=_vid;
- (void).cxx_destruct;
- (void)handleDisappear;
- (void)handleShowOnScreen;
- (void)sendPlayedEvent:(long long)arg1;
- (void)videoPlayAtTime:(long long)arg1 TotalTime:(long long)arg2;
- (void)appDidEnterPlayground;
- (void)appDidEnterBackground;
- (void)playOrPauseVideoWithOffset:(struct CGPoint)arg1 landscape:(_Bool)arg2;
- (void)didReceiveEvent:(id)arg1;
- (void)setupPlayerViewWithVideoInfo:(id)arg1;
- (void)layoutSubviews;
- (void)dealloc;
- (id)initWithModel:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
