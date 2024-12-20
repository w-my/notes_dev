//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIResponder.h"

@class AVPlayer, QNDeDaoCourseModel, QNDeDaoMiniPlayerView, QNListNewsItem, QNWeakArray;

@interface QNDeDaoPlayer : UIResponder
{
    QNListNewsItem *_listItem;
    QNDeDaoCourseModel *_course;
    unsigned long long _currentIndex;
    unsigned long long _status;
    QNDeDaoMiniPlayerView *_playerView;
    AVPlayer *_player;
    id _timeObserver;
    QNWeakArray *_externalObservers;
    double _lastSaveProgressTime;
    double _startPlayTime;
}

+ (_Bool)isSingletonDisposed;
+ (void)dispose;
+ (id)sharedInstance;
@property(nonatomic) double startPlayTime; // @synthesize startPlayTime=_startPlayTime;
@property(nonatomic) double lastSaveProgressTime; // @synthesize lastSaveProgressTime=_lastSaveProgressTime;
@property(readonly, nonatomic) QNWeakArray *externalObservers; // @synthesize externalObservers=_externalObservers;
@property(retain, nonatomic) id timeObserver; // @synthesize timeObserver=_timeObserver;
@property(retain, nonatomic) AVPlayer *player; // @synthesize player=_player;
@property(retain, nonatomic) QNDeDaoMiniPlayerView *playerView; // @synthesize playerView=_playerView;
@property(nonatomic) unsigned long long status; // @synthesize status=_status;
@property(nonatomic) unsigned long long currentIndex; // @synthesize currentIndex=_currentIndex;
@property(retain, nonatomic) QNDeDaoCourseModel *course; // @synthesize course=_course;
@property(readonly, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
- (void).cxx_destruct;
- (void)p_onListenPlayerPlay;
- (_Bool)canBecomeFirstResponder;
- (void)p_updateNowPlayingInfoCenter:(_Bool)arg1;
- (void)p_removeRemoteCommands;
- (void)p_addRemoteCommands;
- (void)p_applicationDidBecomeActive:(id)arg1;
- (void)p_applicationWillResignActive:(id)arg1;
- (void)p_reportPlayAction:(id)arg1;
- (void)p_reportPlayDuration;
- (void)p_playFailed;
- (void)p_willPresentActivityController;
- (void)p_imageBrowserWillShow;
- (void)p_showPlayFailedAlert;
- (void)p_audioSessionRouteChanged:(id)arg1;
- (void)p_audioSessionInterruptted:(id)arg1;
- (void)p_otherMusicStartPlay:(id)arg1;
- (void)p_didFailPlayToEnd:(id)arg1;
- (void)p_didPlayToEnd:(id)arg1;
- (void)p_updatePlayerViewProgress:(double)arg1 animated:(_Bool)arg2;
- (void)p_resetPlayerViewWithStatus:(unsigned long long)arg1;
- (void)p_resetPlayer;
- (void)p_removeMiniPlayer;
- (void)p_removeItemStatusObserver;
- (void)p_addItemStatusObserver;
- (void)p_removeTimeObserver;
- (void)p_addTimeObserver;
- (void)p_startPlay;
- (void)p_resume;
- (void)p_pause;
- (void)p_playCurrentLesson;
- (void)finishPlayAndDispose;
- (void)togglePlay:(_Bool)arg1;
- (void)playAtProgress:(double)arg1;
- (void)playNextLesson;
- (void)playPreLesson;
- (void)updatePlayerCourseItem:(id)arg1;
- (void)playWithCourseItem:(id)arg1 startIndex:(long long)arg2;
- (void)playWithCourseItem:(id)arg1;
- (void)attachExternalObserver:(id)arg1;
- (void)showMiniPlayer:(_Bool)arg1 pause:(_Bool)arg2;
- (void)showMiniPlayer:(_Bool)arg1;
- (void)detachCurrentScrollView;
- (void)adjustMiniPlayerWithBottomInset:(double)arg1;
- (void)attachMiniPlayerToScrollView:(id)arg1 bottomInset:(double)arg2;
- (void)dealloc;
- (id)init;

@end

