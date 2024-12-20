//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVMediaDirector.h"

@class MVModel, NSArray, NSMutableDictionary;

@interface MVEffectDirector : MVMediaDirector
{
    _Bool _resumesWhenAppBecomeActive;
    _Bool _canResumeWhenAppBecomeActive;
    MVModel *_model;
    long long _mediaContentMode;
    CDUnknownBlockType _didChangeState;
    NSMutableDictionary *_channelMap;
    NSArray *_readyObservingChannelTypes;
}

@property(nonatomic) _Bool canResumeWhenAppBecomeActive; // @synthesize canResumeWhenAppBecomeActive=_canResumeWhenAppBecomeActive;
@property(retain, nonatomic) NSArray *readyObservingChannelTypes; // @synthesize readyObservingChannelTypes=_readyObservingChannelTypes;
@property(retain, nonatomic) NSMutableDictionary *channelMap; // @synthesize channelMap=_channelMap;
@property(copy, nonatomic) CDUnknownBlockType didChangeState; // @synthesize didChangeState=_didChangeState;
@property(nonatomic) _Bool resumesWhenAppBecomeActive; // @synthesize resumesWhenAppBecomeActive=_resumesWhenAppBecomeActive;
@property(nonatomic) long long mediaContentMode; // @synthesize mediaContentMode=_mediaContentMode;
@property(retain, nonatomic) MVModel *model; // @synthesize model=_model;
- (void).cxx_destruct;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)unobserveReadyStateForChannels;
- (void)observeReadyStateForChannels;
- (void)observeReadyState:(_Bool)arg1 forChangeWithType:(long long)arg2;
- (void)enumerateReadyStateForChannelsWithOperation:(CDUnknownBlockType)arg1;
- (void)applicationDidBecomeActive;
- (void)applicationWillResignActive;
- (void)registerNotifications;
- (void)stop;
- (void)pause;
- (void)start;
- (void)channelsDidChangeReadyState;
- (void)observeReadyStateForChannelsWithTypes:(id)arg1;
- (void)setAccessableTimeRangesWithCMTimeRanges:(id)arg1;
- (void)removeChannelForType:(long long)arg1;
- (void)addChannel:(id)arg1 forType:(long long)arg2;
- (id)channelWithType:(long long)arg1;
@property(readonly, nonatomic) _Bool isPlaying;
- (void)dealloc;
- (id)init;

@end

