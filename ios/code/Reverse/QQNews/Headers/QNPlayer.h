//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIViewController.h"

#import "QNTVKMediaPlayerDelegate.h"
#import "TADVideoPlayerProtocol.h"

@class CAlertView, CArticleContentVideoExtendNode, NSDictionary, NSString, QNAdItem, QNContinuePlayFor3GView, QNListNewsItem, QNPlayerControlViewManager, QNPlayerLandscapeController, QNTVKMediaPlayer, QNVideoPlayParam, TADVideoPlayerReporter, UIImageView, UIView;

@interface QNPlayer : UIViewController <TADVideoPlayerProtocol, QNTVKMediaPlayerDelegate>
{
    _Bool _isRotating;
    _Bool _isUserPause;
    _Bool _isInFloatingView;
    _Bool _isToTwoEyeState;
    _Bool _isReallyMute;
    _Bool _landscapeModeForTopController;
    _Bool _beginClosing;
    _Bool _isBackgroundState;
    _Bool _isTADPlaying;
    long long _currentPlayerType;
    QNListNewsItem *_listItem;
    CArticleContentVideoExtendNode *_videoInfo;
    QNVideoPlayParam *_currentPlayerInfo;
    QNPlayerLandscapeController *_fullScreenController;
    QNTVKMediaPlayer *_player;
    long long _lastOrientation;
    double _isRotationInAngel;
    long long _currentStatusBarStyle;
    NSString *_mediaDefinition;
    CAlertView *_alertView;
    QNPlayerControlViewManager *_controlViewManager;
    long long _lastType;
    UIImageView *_videoCutImageView;
    QNContinuePlayFor3GView *_playFor3GView;
    NSDictionary *_reportDictForSDK;
    NSDictionary *_reportDict;
    QNAdItem *_adItem;
    TADVideoPlayerReporter *_adReporter;
}

@property(retain, nonatomic) TADVideoPlayerReporter *adReporter; // @synthesize adReporter=_adReporter;
@property(retain, nonatomic) QNAdItem *adItem; // @synthesize adItem=_adItem;
@property(nonatomic) _Bool isTADPlaying; // @synthesize isTADPlaying=_isTADPlaying;
@property(nonatomic) _Bool isBackgroundState; // @synthesize isBackgroundState=_isBackgroundState;
@property(retain, nonatomic) NSDictionary *reportDict; // @synthesize reportDict=_reportDict;
@property(retain, nonatomic) NSDictionary *reportDictForSDK; // @synthesize reportDictForSDK=_reportDictForSDK;
@property(nonatomic) _Bool beginClosing; // @synthesize beginClosing=_beginClosing;
@property(retain, nonatomic) QNContinuePlayFor3GView *playFor3GView; // @synthesize playFor3GView=_playFor3GView;
@property(retain, nonatomic) UIImageView *videoCutImageView; // @synthesize videoCutImageView=_videoCutImageView;
@property(nonatomic) _Bool landscapeModeForTopController; // @synthesize landscapeModeForTopController=_landscapeModeForTopController;
@property(nonatomic) long long lastType; // @synthesize lastType=_lastType;
@property(retain, nonatomic) QNPlayerControlViewManager *controlViewManager; // @synthesize controlViewManager=_controlViewManager;
@property(retain, nonatomic) CAlertView *alertView; // @synthesize alertView=_alertView;
@property(copy, nonatomic) NSString *mediaDefinition; // @synthesize mediaDefinition=_mediaDefinition;
@property(nonatomic) long long currentStatusBarStyle; // @synthesize currentStatusBarStyle=_currentStatusBarStyle;
@property(nonatomic) double isRotationInAngel; // @synthesize isRotationInAngel=_isRotationInAngel;
@property(nonatomic) long long lastOrientation; // @synthesize lastOrientation=_lastOrientation;
@property(nonatomic) _Bool isReallyMute; // @synthesize isReallyMute=_isReallyMute;
@property(nonatomic) _Bool isToTwoEyeState; // @synthesize isToTwoEyeState=_isToTwoEyeState;
@property(nonatomic) _Bool isInFloatingView; // @synthesize isInFloatingView=_isInFloatingView;
@property(nonatomic) _Bool isUserPause; // @synthesize isUserPause=_isUserPause;
@property(retain, nonatomic) QNTVKMediaPlayer *player; // @synthesize player=_player;
@property(nonatomic) _Bool isRotating; // @synthesize isRotating=_isRotating;
@property(retain, nonatomic) QNPlayerLandscapeController *fullScreenController; // @synthesize fullScreenController=_fullScreenController;
@property(retain, nonatomic) QNVideoPlayParam *currentPlayerInfo; // @synthesize currentPlayerInfo=_currentPlayerInfo;
@property(retain, nonatomic) CArticleContentVideoExtendNode *videoInfo; // @synthesize videoInfo=_videoInfo;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(nonatomic) long long currentPlayerType; // @synthesize currentPlayerType=_currentPlayerType;
- (void).cxx_destruct;
- (void)playFailedWithError:(id)arg1;
- (void)playStarted;
- (_Bool)p_reportForTADPlayWithType:(unsigned long long)arg1 info:(id)arg2;
- (void)p_initAdInfo;
- (void)updateVideoInfo:(id)arg1;
- (void)fitPlayerToFrame;
- (void)changeViewFrame:(struct CGRect)arg1;
- (_Bool)isFullScreenOfCurrentType;
- (void)changeControlView:(id)arg1;
- (void)updateControlView;
- (void)setPlayerParamAfterPlay;
- (void)setPlayerParamBeforePlay;
- (void)beginPlayToReport;
- (_Bool)shouldHideGPRSRemind;
- (void)playerStateChanged;
- (void)skipAdertisement;
- (void)pause;
- (void)closeTVKPlayer;
- (void)removeTVKPlayer;
- (void)saveHistoryPlay;
- (void)seekTo:(double)arg1;
- (void)play;
- (void)enterVRTwoEyesState;
- (void)playNewItemIsFromRemind:(_Bool)arg1;
- (void)playNewItem;
- (_Bool)isPlayingSameItemWithListItem:(id)arg1 videoInfo:(id)arg2 param:(id)arg3;
- (void)loadVideoInfoWithListItem:(id)arg1 videoInfo:(id)arg2 param:(id)arg3;
- (_Bool)currentVideoIsLandscapeFullPlay;
- (void)updateProgress:(double)arg1 bufferTime:(double)arg2 duration:(double)arg3;
- (void)playFinshed;
- (double)currentPlaybackTime;
- (void)setLoadingImage:(id)arg1;
- (void)changeMuteMode:(_Bool)arg1;
- (void)showGPRSRemind;
@property(readonly, nonatomic) _Bool isShow3GRemind;
- (void)netWorkChangedToShowRemind;
- (_Bool)closePlayerWithAnimation:(_Bool)arg1 completeAnimation:(CDUnknownBlockType)arg2;
- (_Bool)closePlayer;
- (_Bool)isShowWifiRemindFromRemind:(_Bool)arg1;
- (id)p_getFreeRemindData;
- (void)p_saveShowFreeRemindDate;
- (void)playVideoWithid:(id)arg1 pid:(id)arg2;
- (void)changeVideoControlViewWithType:(long long)arg1 frame:(struct CGRect)arg2;
- (void)playWebViewMode;
- (void)attatchPlayer;
- (void)createPlayer;
- (void)reportToAPPAndMTA:(id)arg1 listItem:(id)arg2;
- (void)updateMediaDefinition:(id)arg1;
- (id)nameForMediaDefinition:(id)arg1 mustReturnAName:(_Bool)arg2;
- (id)mediaDefinitionList;
- (_Bool)isPlayingADState;
- (void)changePlayerLoadingImage:(id)arg1;
- (_Bool)isHaveOwner;
- (_Bool)fullScreenIsTopController;
- (id)currentControlView;
@property(readonly, nonatomic) _Bool isLandscapeVideo;
@property(readonly, nonatomic) _Bool isPortraitScreen;
@property(readonly, nonatomic) long long currentStatus;
- (void)p_willChangeVideoState;
- (void)switchControlView:(id)arg1 isImmediately:(_Bool)arg2;
- (id)getCurrentControlViewObjectWithType:(long long)arg1;
- (void)p_handlePauseVideoNotification:(id)arg1;
- (void)p_handlePlayVideoNotification:(id)arg1;
- (void)p_handleDidTakeScreenShot:(id)arg1;
- (void)p_handleWillTakeScreenShot:(id)arg1;
- (void)p_handleNetworkChanged;
- (void)p_handleEnterForegroundNotification;
- (void)p_handleEnterBackgroundNotification;
- (void)rotateToOrientation:(long long)arg1;
- (void)p_handleOrientationChange;
- (void)dealloc;
- (id)init;
- (void)p_rotateToFullScreenWithAnimation:(_Bool)arg1 beforeAnimation:(CDUnknownBlockType)arg2 complete:(CDUnknownBlockType)arg3;
- (void)p_portraitPlayerViewToFull;
- (void)p_normalToPortraitFullScreenWithAnimation:(_Bool)arg1 beforeAnimation:(CDUnknownBlockType)arg2 complete:(CDUnknownBlockType)arg3;
- (void)setTVKPlayerPropertyWithNormallToFull;
- (void)p_rotateFullScreenToPortraitWithAnimation:(_Bool)arg1 beforeAnimation:(CDUnknownBlockType)arg2 complete:(CDUnknownBlockType)arg3;
- (void)rotateFullToNormalWithoutAnimationComplete:(CDUnknownBlockType)arg1;
- (void)p_portraitFullToNormalWithAnimation:(_Bool)arg1 beforeAnimation:(CDUnknownBlockType)arg2 complete:(CDUnknownBlockType)arg3;
- (void)setTVKPlayerPropertyWithFullToNormal;
- (void)p_rotatePlayerViewToSmall;
- (void)p_rotatePlayerViewToFull;
- (_Bool)reattachNewView:(id)arg1 withFrame:(struct CGRect)arg2;
- (void)changeToNomalView:(id)arg1 withFrame:(struct CGRect)arg2;
- (_Bool)canManualRotateFromType:(long long)arg1 toType:(long long)arg2;
- (_Bool)canAutoRotate;
- (_Bool)switchPlayerTypeToFullScreen:(_Bool)arg1 animation:(_Bool)arg2 isRotate:(_Bool)arg3 completeAnimation:(CDUnknownBlockType)arg4;
- (void)changeToFloatingTypeWithParentView:(id)arg1;
- (void)remove;
- (void)mute:(_Bool)arg1;
- (void)stop;
- (void)resume;
@property(readonly, nonatomic) UIView *playerView;
@property(readonly, nonatomic) int playStatus;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
