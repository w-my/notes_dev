//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIViewController.h"

#import "TADMediaConnectionDelegate.h"
#import "TADMediaViewControllerDelegate.h"
#import "UIAlertViewDelegate.h"
#import "UIGestureRecognizerDelegate.h"

@class NSArray, NSString, NSTimer, TADMediaConnection, TADMediaViewController, TADRequestInfo, UIView;

@interface TADVideoAdController : UIViewController <TADMediaViewControllerDelegate, TADMediaConnectionDelegate, UIGestureRecognizerDelegate, UIAlertViewDelegate>
{
    NSTimer *_playerTimer;
    _Bool _isCallerToStop;
    _Bool _isPlayerMute;
    _Bool _isPlayerReady;
    _Bool _isViewAppear;
    _Bool _isAppActive;
    _Bool _isRichMediaActive;
    _Bool _isPlayingCachedAd;
    _Bool _isAdPlaying;
    _Bool _isAdStartToPlay;
    _Bool _isFullscreen;
    _Bool _isOfflinePlay;
    _Bool _isLandingViewPresented;
    id <TADVideoAdControllerDelegate> _delegate;
    TADRequestInfo *_requestInfo;
    TADMediaConnection *_connection;
    NSArray *_mediaItems;
    double _totalDuration;
    double _playedDuration;
    TADMediaViewController *_mediaViewController;
    UIView *_touchView;
    long long _preAdPlayState;
}

@property(nonatomic) _Bool isLandingViewPresented; // @synthesize isLandingViewPresented=_isLandingViewPresented;
@property(nonatomic) long long preAdPlayState; // @synthesize preAdPlayState=_preAdPlayState;
@property(nonatomic) _Bool isOfflinePlay; // @synthesize isOfflinePlay=_isOfflinePlay;
@property(retain, nonatomic) UIView *touchView; // @synthesize touchView=_touchView;
@property(retain, nonatomic) TADMediaViewController *mediaViewController; // @synthesize mediaViewController=_mediaViewController;
@property(nonatomic) _Bool isFullscreen; // @synthesize isFullscreen=_isFullscreen;
@property(nonatomic) _Bool isAdStartToPlay; // @synthesize isAdStartToPlay=_isAdStartToPlay;
@property(nonatomic) _Bool isAdPlaying; // @synthesize isAdPlaying=_isAdPlaying;
@property(nonatomic) _Bool isPlayingCachedAd; // @synthesize isPlayingCachedAd=_isPlayingCachedAd;
@property(nonatomic) _Bool isRichMediaActive; // @synthesize isRichMediaActive=_isRichMediaActive;
@property(nonatomic) _Bool isAppActive; // @synthesize isAppActive=_isAppActive;
@property(nonatomic) _Bool isViewAppear; // @synthesize isViewAppear=_isViewAppear;
@property(nonatomic) _Bool isPlayerReady; // @synthesize isPlayerReady=_isPlayerReady;
@property(nonatomic) double playedDuration; // @synthesize playedDuration=_playedDuration;
@property(nonatomic) double totalDuration; // @synthesize totalDuration=_totalDuration;
@property(retain, nonatomic) NSArray *mediaItems; // @synthesize mediaItems=_mediaItems;
@property(retain, nonatomic) TADMediaConnection *connection; // @synthesize connection=_connection;
@property(retain, nonatomic) TADRequestInfo *requestInfo; // @synthesize requestInfo=_requestInfo;
@property(nonatomic) _Bool isPlayerMute; // @synthesize isPlayerMute=_isPlayerMute;
@property(nonatomic) _Bool isCallerToStop; // @synthesize isCallerToStop=_isCallerToStop;
@property(nonatomic) __weak id <TADVideoAdControllerDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (id)landingPresentVC;
- (void)checkStateAndPlay;
- (void)appWillResignActive:(id)arg1;
- (void)appDidBecomeActive:(id)arg1;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewDidAppear:(_Bool)arg1;
- (void)setPlayerMuted:(_Bool)arg1;
- (void)skipCurrentAd;
- (void)skipAdPlay;
- (void)continueAdPlay;
- (void)pauseAdPlay;
- (void)hollywoodBtnClicked;
- (void)adLandingViewDidDismiss;
- (void)adLandingViewWillDismiss;
- (void)adLandingViewDidPresent;
- (void)adLandingViewWillPresent;
- (_Bool)adLandingViewShouldPresent;
- (void)detailBtnClicked:(id)arg1;
- (void)adMediaViewWillTurnVolume:(_Bool)arg1;
- (void)adMediaViewWillShrink;
- (void)adMediaViewWillExpand:(_Bool)arg1;
- (void)adMediaViewWillSkipAd;
- (void)adMediaViewDidPresent;
- (id)getBreakPoints:(id)arg1 adType:(long long)arg2;
- (void)connetionDidReceiveWatchBuyPoints:(id)arg1;
- (void)connetionDidReceiveCornerAdPoints:(id)arg1;
- (void)connetionDidReceiveIVBPoints:(id)arg1;
- (void)connetionDidReceiveBreakPoints:(id)arg1;
- (void)connectionDidFailedWithError:(id)arg1 type:(long long)arg2;
- (void)connetionDidReceiveMedias:(id)arg1;
- (void)updatePlayerTime:(id)arg1;
- (void)timerInvalidate;
- (void)timerStart;
- (void)didSingleTap:(id)arg1;
- (void)alertView:(id)arg1 clickedButtonAtIndex:(long long)arg2;
- (void)cleanPlayerView;
- (void)prerollAdInit;
- (void)showAdPlayView;
- (void)resize16_9View:(id)arg1;
- (void)viewDidLayoutSubviews;
- (void)informPlayerDidLayout:(long long)arg1;
- (void)informPlayerWillLayout:(long long)arg1;
- (_Bool)enableAdPlay;
- (void)cancelAd:(long long)arg1;
- (void)informAdItemPlayFinish:(long long)arg1;
- (void)informAdPlayStatus:(long long)arg1;
- (void)requestWithAdInfo:(id)arg1;
- (void)cleanConnection;
- (void)cleanMediaViewController;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
