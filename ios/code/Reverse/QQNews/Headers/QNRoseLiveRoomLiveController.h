//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRoseLiveRoomBaseChildController.h"

#import "QNLiveVideoCountDownDelegate.h"
#import "QNShareActivityControllerDelegate.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class NSString, QNAdItem, QNDetailBannerAdView, QNLiveVideoInfoView, QNRoseLiveRoomFragmentContext, QNRoseLiveRoomLiveViewModel, TADLiveBannerAsyncLoader, TADReportManager;

@interface QNRoseLiveRoomLiveController : QNRoseLiveRoomBaseChildController <UITableViewDataSource, UITableViewDelegate, QNLiveVideoCountDownDelegate, QNShareActivityControllerDelegate>
{
    QNRoseLiveRoomFragmentContext *_fragmentContext;
    QNRoseLiveRoomLiveViewModel *_viewModel;
    QNLiveVideoInfoView *_videoInfoView;
    QNDetailBannerAdView *_bannerAdView;
    QNAdItem *_bannerAd;
    TADLiveBannerAsyncLoader *_bannerLoader;
    TADReportManager *_adManager;
}

@property(retain, nonatomic) TADReportManager *adManager; // @synthesize adManager=_adManager;
@property(retain, nonatomic) TADLiveBannerAsyncLoader *bannerLoader; // @synthesize bannerLoader=_bannerLoader;
@property(retain, nonatomic) QNAdItem *bannerAd; // @synthesize bannerAd=_bannerAd;
@property(retain, nonatomic) QNDetailBannerAdView *bannerAdView; // @synthesize bannerAdView=_bannerAdView;
@property(retain, nonatomic) QNLiveVideoInfoView *videoInfoView; // @synthesize videoInfoView=_videoInfoView;
@property(retain, nonatomic) QNRoseLiveRoomLiveViewModel *viewModel; // @synthesize viewModel=_viewModel;
@property(retain, nonatomic) QNRoseLiveRoomFragmentContext *fragmentContext; // @synthesize fragmentContext=_fragmentContext;
- (void).cxx_destruct;
- (void)loadLiveBannerAd;
- (void)themeChanged:(long long)arg1;
- (void)liveVideoDidStart:(id)arg1;
- (void)cleanupCompletely:(_Bool)arg1;
- (id)getContentScrollView;
- (void)scroll2Top;
- (void)do_selectedAsCurrentChannel:(id)arg1;
- (void)do_deselectedAsCurrentChannel:(id)arg1;
- (void)p_hideMenuView;
- (id)p_displayDataByIndexPath:(id)arg1;
- (long long)p_cellBubbleViewStyle:(id)arg1;
- (_Bool)p_shouldAutomaticallyDisplayNewData;
- (void)p_stopRefreshOrLoadMoreAnimation:(_Bool)arg1 loadType:(long long)arg2;
- (void)scrollViewDidScroll:(id)arg1;
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forRowAtIndexPath:(id)arg3;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (id)getShareToEmailInfo;
- (void)onAction:(id)arg1;
- (void)updateLiveVideoForecastView:(_Bool)arg1;
- (void)viewDidLoad;
- (void)loadView;
- (void)dealloc;
- (id)initWithParam:(id)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

