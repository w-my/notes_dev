//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "CPContentLayoutManager.h"
#import "CorePlayerFeature.h"

@class AVURLAsset, CPContentView, CPInterruption, CPModuleManager, CPPlayer, CPPlayerItem, CPPlayerView, NSArray;

@interface CorePlayer : NSObject <CPContentLayoutManager, CorePlayerFeature>
{
    struct {
        unsigned int keep:1;
        unsigned int rate:1;
        unsigned int duration:1;
        unsigned int status:1;
        unsigned int item:1;
        unsigned int meta:1;
        unsigned int loaded:1;
        unsigned int airplay:1;
        unsigned int presentation:1;
    } keyobserver;
    struct {
        unsigned int state:3;
        unsigned int lastplay:1;
        unsigned int seeking:1;
        unsigned int play:1;
        unsigned int pending:1;
        unsigned int airplay:1;
        unsigned int dpause:1;
        unsigned int readyplay:1;
        unsigned int seekhead:1;
    } playerstate;
    CPModuleManager *_moduleManager;
    _Bool _allowAirPlay;
    _Bool _scaleFill;
    CPContentView *_view;
    CPPlayerView *_playerView;
    CPPlayerItem *_playerItem;
    AVURLAsset *_playerAsset;
    CPPlayer *_player;
    CPPlayer *_backPlayer;
    CPPlayerView *_backView;
    id _playedObserver;
    NSArray *_cpus;
    unsigned long long _cpi;
    CPInterruption *_interruption;
}

@property(retain, nonatomic) CPInterruption *interruption; // @synthesize interruption=_interruption;
@property(nonatomic) unsigned long long cpi; // @synthesize cpi=_cpi;
@property(copy, nonatomic) NSArray *cpus; // @synthesize cpus=_cpus;
@property(retain, nonatomic) id playedObserver; // @synthesize playedObserver=_playedObserver;
@property(retain, nonatomic) CPPlayerView *backView; // @synthesize backView=_backView;
@property(retain, nonatomic) CPPlayer *backPlayer; // @synthesize backPlayer=_backPlayer;
@property(retain, nonatomic) CPPlayer *player; // @synthesize player=_player;
@property(retain, nonatomic) AVURLAsset *playerAsset; // @synthesize playerAsset=_playerAsset;
@property(retain, nonatomic) CPPlayerItem *playerItem; // @synthesize playerItem=_playerItem;
@property(retain, nonatomic) CPPlayerView *playerView; // @synthesize playerView=_playerView;
@property(retain, nonatomic) CPContentView *view; // @synthesize view=_view;
@property(nonatomic) _Bool scaleFill; // @synthesize scaleFill=_scaleFill;
- (void).cxx_destruct;
- (void)interrupt:(int)arg1;
- (void)play;
- (void)setdpause:(_Bool)arg1;
- (void)dpause;
- (void)pause;
- (_Bool)isDirectPause;
- (void)deinit;
- (void)stop;
- (_Bool)isFinish;
- (_Bool)isAirplaying;
- (_Bool)isPlaying;
- (_Bool)isSeeking;
- (_Bool)isSeekHeading;
- (_Bool)isPending;
- (long long)playstate;
- (id)cpu;
- (double)playable;
- (double)played;
- (double)duration;
- (void)seekToEnd;
- (void)endSeek:(double)arg1;
- (void)seekTo:(double)arg1;
- (void)beginSeek:(double)arg1;
@property(nonatomic) _Bool allowAirPlay; // @synthesize allowAirPlay=_allowAirPlay;
- (void)stopLoading;
- (void)startLoading;
- (void)stopPending;
- (void)startPending;
- (void)stopPause;
- (void)startPause;
- (void)appBecomeActive:(id)arg1;
- (void)appResignActive:(id)arg1;
- (void)stopPlaybackSession;
- (long long)durationSpan;
- (void)handlePlayEnd;
- (void)handleError:(int)arg1;
- (void)playEnded:(_Bool)arg1;
- (void)playerItemDidReachEnd:(id)arg1;
- (void)playerItemDidFailed:(id)arg1;
- (void)readyToPlay;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)loadNext;
- (void)playURLs:(id)arg1;
- (void)playURL:(id)arg1;
- (void)appendURLs:(id)arg1;
- (void)appendURL:(id)arg1;
- (void)deregisterPlayerEvent;
- (void)deregisterRate;
- (void)registerPlayerEvent;
- (void)deregisterPlayerItemEvent;
- (void)registerPlayerItemEvent;
- (void)unobservePlayed;
- (void)observePlayed;
- (void)contentsTouchesCancelled:(id)arg1 withEvent:(id)arg2;
- (void)contentsTouchesMoved:(id)arg1 withEvent:(id)arg2;
- (void)contentsTouchesEnded:(id)arg1 withEvent:(id)arg2;
- (void)contentsTouchesBegan:(id)arg1 withEvent:(id)arg2;
- (void)contentsLayout:(id)arg1;
- (id)AVPlayer;
- (id)moduleManager;
- (id)init;
- (id)initWithModuleManager:(Class)arg1;
- (void)dealloc;

@end

