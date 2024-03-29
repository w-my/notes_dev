//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVVideoSourceChannel.h"

@class MVAudioPlayAction, MVVideoPlayOptimizer;

@interface MVVideoPlayChannel : MVVideoSourceChannel
{
    _Bool _onlyOriginalAudio;
    _Bool _optimizesForPlaying;
    _Bool _needsReloadActionsForOptimizing;
    MVAudioPlayAction *_recordedAudioAction;
    MVAudioPlayAction *_bgmAudioAction;
    MVVideoPlayOptimizer *_videoPlayOptimizer;
}

@property(retain, nonatomic) MVVideoPlayOptimizer *videoPlayOptimizer; // @synthesize videoPlayOptimizer=_videoPlayOptimizer;
@property(retain, nonatomic) MVAudioPlayAction *bgmAudioAction; // @synthesize bgmAudioAction=_bgmAudioAction;
@property(retain, nonatomic) MVAudioPlayAction *recordedAudioAction; // @synthesize recordedAudioAction=_recordedAudioAction;
@property(nonatomic) _Bool needsReloadActionsForOptimizing; // @synthesize needsReloadActionsForOptimizing=_needsReloadActionsForOptimizing;
@property(nonatomic) _Bool optimizesForPlaying; // @synthesize optimizesForPlaying=_optimizesForPlaying;
@property(nonatomic) _Bool onlyOriginalAudio; // @synthesize onlyOriginalAudio=_onlyOriginalAudio;
- (void).cxx_destruct;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)restartVideoPlayOptimizerIfNeeded;
- (void)updateAudioVolume;
- (id)makeBGMAudioAction;
- (id)makeRecordedAudioAction;
- (id)makeVideoSourceAction;
- (id)makeVideoAsset;
- (void)updateBGMAudioAction;
- (void)updateRecordedAudioAction;
- (void)updateVideoSourceAction;
- (void)reloadMusicActions;
- (void)reloadActions;
- (void)unobserveMedia;
- (void)observeMedia;
- (void)setTimelineReference:(id)arg1;
- (void)dealloc;

@end

