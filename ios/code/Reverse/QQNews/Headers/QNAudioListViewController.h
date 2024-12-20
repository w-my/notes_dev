//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNCommonListController.h"

@class NSArray, NSTimer, QNAudioChannelBanner, QNAudioPlayView, QNWifiManagerRecommendEnterView;

@interface QNAudioListViewController : QNCommonListController
{
    _Bool _animating;
    _Bool _playLatest;
    _Bool _shouldAutoPlayNext;
    _Bool _isWifiEnterExplosure;
    QNAudioChannelBanner *_dwnBannerView;
    QNAudioPlayView *_bannerPlayView;
    long long _defaultPlayIndex;
    NSArray *_audioInfoList;
    NSTimer *_liveAudioTimer;
    QNWifiManagerRecommendEnterView *_wifiManagerEnterView;
    struct CGPoint _lastOffset;
}

@property(nonatomic) _Bool isWifiEnterExplosure; // @synthesize isWifiEnterExplosure=_isWifiEnterExplosure;
@property(retain, nonatomic) QNWifiManagerRecommendEnterView *wifiManagerEnterView; // @synthesize wifiManagerEnterView=_wifiManagerEnterView;
@property(retain, nonatomic) NSTimer *liveAudioTimer; // @synthesize liveAudioTimer=_liveAudioTimer;
@property(retain, nonatomic) NSArray *audioInfoList; // @synthesize audioInfoList=_audioInfoList;
@property(nonatomic) _Bool shouldAutoPlayNext; // @synthesize shouldAutoPlayNext=_shouldAutoPlayNext;
@property(nonatomic) long long defaultPlayIndex; // @synthesize defaultPlayIndex=_defaultPlayIndex;
@property(nonatomic) _Bool playLatest; // @synthesize playLatest=_playLatest;
@property(retain, nonatomic) QNAudioPlayView *bannerPlayView; // @synthesize bannerPlayView=_bannerPlayView;
@property(nonatomic) _Bool animating; // @synthesize animating=_animating;
@property(nonatomic) struct CGPoint lastOffset; // @synthesize lastOffset=_lastOffset;
@property(retain, nonatomic) QNAudioChannelBanner *dwnBannerView; // @synthesize dwnBannerView=_dwnBannerView;
- (void).cxx_destruct;
- (void)didComeInCurrentController:(id)arg1 fromController:(id)arg2;
- (_Bool)_hasLatest;
- (void)_playLatestAudio;
- (void)additionalOperationsAfterLoadModelSuccess:(id)arg1;
- (void)_doAddFavorite:(long long)arg1;
- (void)_addFaoriteLoginCallback:(long long)arg1;
- (void)_favoriteItemWithIndex:(long long)arg1;
- (void)_shareItemWithIndex:(long long)arg1;
- (void)_liveAudioProcessTimerInvoke;
- (void)_setTopCellSelected;
- (void)_initializeListeners;
- (void)_initializeAudioPlayManager;
- (void)_updateListItems;
- (void)_initializeLiveAudioTimer;
- (void)_stopAtTop;
- (void)_stopBannerPlayVew;
- (void)_pauseBannerPlayView;
- (void)_palyBannerPlayView:(id)arg1;
- (void)do_deselectedAsCurrentChannel:(id)arg1;
- (void)do_selectedAsCurrentChannel:(id)arg1;
- (void)dismissBannerView:(_Bool)arg1;
- (void)showBannerView:(_Bool)arg1;
- (void)scrollViewDidScroll:(id)arg1;
- (void)p_wifiManagerExplosureStaticDuplicated:(_Bool)arg1;
- (void)p_wifiManagerExplosureStatic;
- (void)_resetBannerViewPosition;
- (void)themeChanged:(long long)arg1;
- (void)refreshViewPackUpFinish:(_Bool)arg1;
- (void)refreshViewPackUpBegin:(_Bool)arg1;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forRowAtIndexPath:(id)arg3;
- (void)waitingTaskesReceived:(id)arg1;
- (void)stopedNotifactionReceived:(id)arg1;
- (void)taskCountChangedNotifactionReceived:(id)arg1;
- (void)playNextNotifactionReceived:(id)arg1;
- (void)downloadNextNotifactionReceived:(id)arg1;
- (void)updateDownloadNewBtnState;
- (void)updateCellPlayStatus;
- (void)updateCellDownloadStatus;
- (void)dwnNewBtnClicked:(id)arg1;
- (void)dwnManagementBtnClicked:(id)arg1;
- (void)_initializeBannerPlayView;
- (void)viewDidLayoutSubviews;
- (void)viewDidDisappear:(_Bool)arg1;
- (void)viewDidAppear:(_Bool)arg1;
- (id)customListDataAdapter;
- (void)dealloc;
- (void)viewDidLoad;
- (id)initWithID:(id)arg1;

@end

