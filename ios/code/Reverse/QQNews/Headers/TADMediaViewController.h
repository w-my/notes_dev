//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIViewController.h"

#import "TADMediaAdViewDelegate.h"

@class NSArray, NSDate, NSDictionary, NSMutableArray, NSString, TADMediaAdView, TADMediaItem, TADMediaLog, TADQLMediaPing, TADReportDP3, TADReportMediaItemList, TADReportSingleMediaItem, TADUserInfo, UIAlertView;

@interface TADMediaViewController : UIViewController <TADMediaAdViewDelegate>
{
    _Bool _detailButtonVisible;
    _Bool _expandButtonVisible;
    _Bool _forbidAdUserToTouch;
    _Bool _vipSkipVisible;
    _Bool _isVideoMute;
    _Bool _adSkippable;
    _Bool _isVideoPaused;
    _Bool _isAdVideoPaused;
    _Bool _presented;
    _Bool _needDetailButton;
    _Bool _allowDetailButton;
    _Bool _detailButtonInTime;
    _Bool _isLandingViewPresenting;
    _Bool _isLandingViewBeingPresented;
    _Bool _isLandingViewDismissing;
    _Bool _appInteractivePopEnabled;
    _Bool _isSelfPaused;
    _Bool _isAdFailed;
    _Bool _isLoginPageShow;
    _Bool _isHollywoodBtnClicked;
    id <TADMediaViewControllerDelegate> _delegate;
    TADMediaItem *_currentMediaItem;
    NSArray *_mediaItemArray;
    NSDictionary *_clientCtrlParams;
    TADMediaAdView *_mediaAdView;
    double _adPlaybackTimeLastRefreshed;
    double _adTotalDuration;
    double _adTotalDurationComplete;
    double _wkTotalDuration;
    double _adMediaItemDurationFinished;
    NSDate *_dateOfCurrentMediaItemStartToPlay;
    NSDate *_dateOfAdStartToFirstBuffer;
    NSDate *_dateOfAdPlaybackLastStartToPause;
    double _durationOfAdPlaybackPaused;
    NSDate *_dateOfLandingViewLastBeingOpened;
    double _durationOfLandingViewPresented;
    double _timeOfLandingViewStartLoad;
    double _durationOfLandingViewLoading;
    TADReportSingleMediaItem *_mediaViewStat;
    TADReportMediaItemList *_mediaItemListReport;
    TADUserInfo *_userReport;
    TADReportDP3 *_dp3Report;
    TADMediaLog *_logService;
    TADQLMediaPing *_pingService;
    NSMutableArray *_emptyArray;
    UIAlertView *_alertView;
}

@property(retain, nonatomic) UIAlertView *alertView; // @synthesize alertView=_alertView;
@property(nonatomic) _Bool isHollywoodBtnClicked; // @synthesize isHollywoodBtnClicked=_isHollywoodBtnClicked;
@property(nonatomic) _Bool isLoginPageShow; // @synthesize isLoginPageShow=_isLoginPageShow;
@property(retain, nonatomic) NSMutableArray *emptyArray; // @synthesize emptyArray=_emptyArray;
@property(retain, nonatomic) TADQLMediaPing *pingService; // @synthesize pingService=_pingService;
@property(retain, nonatomic) TADMediaLog *logService; // @synthesize logService=_logService;
@property(nonatomic) _Bool isAdFailed; // @synthesize isAdFailed=_isAdFailed;
@property(nonatomic) _Bool isSelfPaused; // @synthesize isSelfPaused=_isSelfPaused;
@property(retain, nonatomic) TADReportDP3 *dp3Report; // @synthesize dp3Report=_dp3Report;
@property(retain, nonatomic) TADUserInfo *userReport; // @synthesize userReport=_userReport;
@property(retain, nonatomic) TADReportMediaItemList *mediaItemListReport; // @synthesize mediaItemListReport=_mediaItemListReport;
@property(retain, nonatomic) TADReportSingleMediaItem *mediaViewStat; // @synthesize mediaViewStat=_mediaViewStat;
@property(nonatomic) double durationOfLandingViewLoading; // @synthesize durationOfLandingViewLoading=_durationOfLandingViewLoading;
@property(nonatomic) double timeOfLandingViewStartLoad; // @synthesize timeOfLandingViewStartLoad=_timeOfLandingViewStartLoad;
@property(nonatomic) double durationOfLandingViewPresented; // @synthesize durationOfLandingViewPresented=_durationOfLandingViewPresented;
@property(retain, nonatomic) NSDate *dateOfLandingViewLastBeingOpened; // @synthesize dateOfLandingViewLastBeingOpened=_dateOfLandingViewLastBeingOpened;
@property(nonatomic) double durationOfAdPlaybackPaused; // @synthesize durationOfAdPlaybackPaused=_durationOfAdPlaybackPaused;
@property(retain, nonatomic) NSDate *dateOfAdPlaybackLastStartToPause; // @synthesize dateOfAdPlaybackLastStartToPause=_dateOfAdPlaybackLastStartToPause;
@property(retain, nonatomic) NSDate *dateOfAdStartToFirstBuffer; // @synthesize dateOfAdStartToFirstBuffer=_dateOfAdStartToFirstBuffer;
@property(retain, nonatomic) NSDate *dateOfCurrentMediaItemStartToPlay; // @synthesize dateOfCurrentMediaItemStartToPlay=_dateOfCurrentMediaItemStartToPlay;
@property(nonatomic) double adMediaItemDurationFinished; // @synthesize adMediaItemDurationFinished=_adMediaItemDurationFinished;
@property(nonatomic) double wkTotalDuration; // @synthesize wkTotalDuration=_wkTotalDuration;
@property(nonatomic) double adTotalDurationComplete; // @synthesize adTotalDurationComplete=_adTotalDurationComplete;
@property(nonatomic) double adTotalDuration; // @synthesize adTotalDuration=_adTotalDuration;
@property(nonatomic) double adPlaybackTimeLastRefreshed; // @synthesize adPlaybackTimeLastRefreshed=_adPlaybackTimeLastRefreshed;
@property(nonatomic) _Bool appInteractivePopEnabled; // @synthesize appInteractivePopEnabled=_appInteractivePopEnabled;
@property(nonatomic) _Bool isLandingViewDismissing; // @synthesize isLandingViewDismissing=_isLandingViewDismissing;
@property(nonatomic) _Bool isLandingViewBeingPresented; // @synthesize isLandingViewBeingPresented=_isLandingViewBeingPresented;
@property(nonatomic) _Bool isLandingViewPresenting; // @synthesize isLandingViewPresenting=_isLandingViewPresenting;
@property(nonatomic) _Bool detailButtonInTime; // @synthesize detailButtonInTime=_detailButtonInTime;
@property(nonatomic) _Bool allowDetailButton; // @synthesize allowDetailButton=_allowDetailButton;
@property(nonatomic) _Bool needDetailButton; // @synthesize needDetailButton=_needDetailButton;
@property(nonatomic) _Bool presented; // @synthesize presented=_presented;
@property(nonatomic) _Bool isAdVideoPaused; // @synthesize isAdVideoPaused=_isAdVideoPaused;
@property(nonatomic) _Bool isVideoPaused; // @synthesize isVideoPaused=_isVideoPaused;
@property(nonatomic) _Bool adSkippable; // @synthesize adSkippable=_adSkippable;
@property(retain, nonatomic) TADMediaAdView *mediaAdView; // @synthesize mediaAdView=_mediaAdView;
@property(nonatomic) _Bool isVideoMute; // @synthesize isVideoMute=_isVideoMute;
@property(retain, nonatomic) NSDictionary *clientCtrlParams; // @synthesize clientCtrlParams=_clientCtrlParams;
@property(nonatomic) _Bool vipSkipVisible; // @synthesize vipSkipVisible=_vipSkipVisible;
@property(nonatomic) _Bool forbidAdUserToTouch; // @synthesize forbidAdUserToTouch=_forbidAdUserToTouch;
@property(nonatomic) _Bool expandButtonVisible; // @synthesize expandButtonVisible=_expandButtonVisible;
@property(nonatomic) _Bool detailButtonVisible; // @synthesize detailButtonVisible=_detailButtonVisible;
@property(retain, nonatomic) NSArray *mediaItemArray; // @synthesize mediaItemArray=_mediaItemArray;
@property(retain, nonatomic) TADMediaItem *currentMediaItem; // @synthesize currentMediaItem=_currentMediaItem;
@property(nonatomic) __weak id <TADMediaViewControllerDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)skipCurrentAd;
- (_Bool)canShowFullscreenClickTips;
- (_Bool)canShowSportsVipTips;
- (_Bool)canShowTrueView;
- (void)reportCacheHits;
- (_Bool)isMuted;
- (_Bool)isOfflinePlayWithoutConnection;
- (void)hideDetailButton;
- (void)showDetailButtonAnimated:(_Bool)arg1;
- (void)willRemoveFromClient:(_Bool)arg1;
- (_Bool)shouldLandingInBrowser;
- (void)willAnimateRotationToInterfaceOrientation:(long long)arg1 duration:(double)arg2;
- (_Bool)shouldAutorotateToInterfaceOrientation:(long long)arg1;
- (unsigned long long)supportedInterfaceOrientations;
- (_Bool)shouldAutorotate;
- (void)mediaAdViewUserDidSkipVipAd:(id)arg1;
- (void)mediaAdViewUserDidSkipVipRecommendAd:(id)arg1;
- (void)mediaAdViewUserDidClickDetailView:(id)arg1;
- (void)mediaAdView:(id)arg1 userDidTurnVolume:(_Bool)arg2;
- (void)mediaAdView:(id)arg1 userDidFullScreen:(_Bool)arg2;
- (void)mediaAdViewUserDidClickExpandButton:(id)arg1;
- (void)mediaAdViewUserDidClickedHollywood:(id)arg1;
- (void)mediaAdViewUserDidSkipAd:(id)arg1;
- (void)mediaAdViewUserDidCloseAd:(id)arg1;
- (void)doClickReport;
- (void)adUserDidTouch:(id)arg1;
- (id)guessMediaItemByPlayedTime:(double)arg1;
- (void)refreshWithPlaybackState:(id)arg1 atTime:(double)arg2;
- (void)adMediaItemPlaybackDidFinish:(id)arg1;
- (void)resetControlUI;
- (void)adMediaItemIsPreparedToPlay:(id)arg1;
- (void)setNoAdForContinuedPlay;
- (void)adPlaybackDidFinish:(id)arg1;
- (void)adPlaybackDidFail:(id)arg1;
- (void)adPlaybackDidSkip:(id)arg1;
- (void)adIsPreparedToPlay:(id)arg1;
- (void)adPlayDidContinued:(id)arg1;
- (void)adPlayDidPaused:(id)arg1;
- (void)adBufferingDidFinish:(id)arg1;
- (void)adBufferingDidFail:(id)arg1;
- (void)adBufferingDidStart:(id)arg1;
- (void)appDidBecomeActive:(id)arg1;
- (void)appWillResignActive:(id)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (_Bool)isHBOorWB;
- (_Bool)isVIPRecommendationAd;
- (id)cacheHitReport;
- (void)showRemainView;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewWillLayoutSubviews;
- (void)viewDidLoad;
- (void)loadView;
- (void)dealloc;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
