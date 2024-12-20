//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CVerticalPluginViewBase.h"

#import "CMusicListItemViewDelegate.h"
#import "CQQMusicWebViewPlayControllerDelegate.h"

@class MiniQQMusicPlayEngine, NSMutableArray, NSString, NSTimer, QNBaseLabel, QNNavigationController, UIView;

@interface CMusicPlayerView : CVerticalPluginViewBase <CMusicListItemViewDelegate, CQQMusicWebViewPlayControllerDelegate>
{
    NSString *_idStr;
    _Bool _bfirststop;
    _Bool _bHasRegisterMusicNotification;
    _Bool _bNeedRestartUpdateTimer;
    long long _currPlayIndex;
    long long _lastPlayState;
    NSMutableArray *_musicListItemViewArray;
    NSTimer *_updateTimer;
    QNNavigationController *_navController;
    NSString *_musicKey;
    MiniQQMusicPlayEngine *_musicEngine;
    UIView *_tipView;
    UIView *_listViewContainer;
    QNBaseLabel *_musicTitle;
}

+ (double)p_getListViewHeightForMusicNode:(id)arg1;
+ (struct CGSize)getViewSizeForDataNode:(id)arg1;
+ (id)getMusicPlay:(struct CGRect)arg1 dataNode:(id)arg2 musicKey:(id)arg3;
@property(retain, nonatomic) QNBaseLabel *musicTitle; // @synthesize musicTitle=_musicTitle;
@property(retain, nonatomic) UIView *listViewContainer; // @synthesize listViewContainer=_listViewContainer;
@property(nonatomic) _Bool bfirststop; // @synthesize bfirststop=_bfirststop;
@property(copy, nonatomic) NSString *idStr; // @synthesize idStr=_idStr;
@property(retain, nonatomic) UIView *tipView; // @synthesize tipView=_tipView;
@property(retain, nonatomic) MiniQQMusicPlayEngine *musicEngine; // @synthesize musicEngine=_musicEngine;
@property(copy, nonatomic) NSString *musicKey; // @synthesize musicKey=_musicKey;
@property(nonatomic) __weak QNNavigationController *navController; // @synthesize navController=_navController;
@property(nonatomic) NSTimer *updateTimer; // @synthesize updateTimer=_updateTimer;
@property(retain, nonatomic) NSMutableArray *musicListItemViewArray; // @synthesize musicListItemViewArray=_musicListItemViewArray;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)layoutSubviews;
- (void)sendMediaPlayWillStartNotify;
- (void)handleMediaPlayWillStart:(id)arg1;
- (id)stringToHexString:(id)arg1;
- (void)CMusicListItemViewClicked:(id)arg1;
- (void)delayCheckPlayState;
- (void)handleMusicStateChanged:(id)arg1;
- (void)handleMusicPlayError:(id)arg1;
- (void)handleMusicPlayEnd:(id)arg1;
- (void)CQQMusicWebViewPlayControllerWillReturn:(id)arg1;
- (void)handleStopMovieNotify:(id)arg1;
- (void)handlePushStartHandleNotify:(id)arg1;
- (void)handlePushNotify:(id)arg1;
- (void)handlePlayBtnClickWithIndex:(long long)arg1;
- (void)Play;
- (void)openQQMusicHtmlPageWithMusicInfo:(id)arg1;
- (void)openQQMusicWithMusicInfo:(id)arg1;
- (void)updatePlaybackTimerHandler:(id)arg1;
- (void)pauseWhenViewDisappear;
- (void)pluginViewWillDisppear;
- (void)pluginViewWillRelease;
- (void)stopUpdateTimer;
- (void)resetUpdateTimer;
- (void)unRegisterMusicNotification;
- (void)registerMusicNotification;
- (void)noDelayStop;
- (void)stop;
- (void)registerCommonNotifications;
- (void)initViews;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1 dataNode:(id)arg2 musicKey:(id)arg3;
- (id)getCurrentMusicDesc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

