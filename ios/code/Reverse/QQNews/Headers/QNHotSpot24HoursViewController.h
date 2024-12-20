//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "KBAbstractListController.h"

#import "KBListControllerSubclassProtocol.h"
#import "QNListVideoAssistorDelegate.h"
#import "QNShareActivityControllerDelegate.h"

@class NSString, QNHotSpot24HoursNavigationView, QNHotSpotHeaderView, QNListLoaderSuccessResponse, QNListModuleItem, QNListNewsItem, QNListTopTipsView, QNListVideoAssistor, UIButton;

@interface QNHotSpot24HoursViewController : KBAbstractListController <KBListControllerSubclassProtocol, QNListVideoAssistorDelegate, QNShareActivityControllerDelegate>
{
    _Bool _isPlayerControl;
    _Bool _hasLoadedSuccessfully;
    unsigned long long _hotSpotListType;
    QNListVideoAssistor *_videoAssistor;
    QNHotSpotHeaderView *_tblHeaderView;
    QNHotSpot24HoursNavigationView *_navigationView;
    QNListModuleItem *_moduleItem;
    QNListNewsItem *_originalItem;
    QNListLoaderSuccessResponse *_lastResponse;
    QNListTopTipsView *_topTipView;
    UIButton *_bottomBtn;
    struct CGSize _headViewImageSize;
}

@property(retain, nonatomic) UIButton *bottomBtn; // @synthesize bottomBtn=_bottomBtn;
@property(nonatomic) _Bool hasLoadedSuccessfully; // @synthesize hasLoadedSuccessfully=_hasLoadedSuccessfully;
@property(retain, nonatomic) QNListTopTipsView *topTipView; // @synthesize topTipView=_topTipView;
@property(retain, nonatomic) QNListLoaderSuccessResponse *lastResponse; // @synthesize lastResponse=_lastResponse;
@property(nonatomic) struct CGSize headViewImageSize; // @synthesize headViewImageSize=_headViewImageSize;
@property(nonatomic) _Bool isPlayerControl; // @synthesize isPlayerControl=_isPlayerControl;
@property(retain, nonatomic) QNListNewsItem *originalItem; // @synthesize originalItem=_originalItem;
@property(retain, nonatomic) QNListModuleItem *moduleItem; // @synthesize moduleItem=_moduleItem;
@property(retain, nonatomic) QNHotSpot24HoursNavigationView *navigationView; // @synthesize navigationView=_navigationView;
@property(retain, nonatomic) QNHotSpotHeaderView *tblHeaderView; // @synthesize tblHeaderView=_tblHeaderView;
@property(readonly, nonatomic) QNListVideoAssistor *videoAssistor; // @synthesize videoAssistor=_videoAssistor;
@property(nonatomic) unsigned long long hotSpotListType; // @synthesize hotSpotListType=_hotSpotListType;
- (void).cxx_destruct;
- (double)bottomInsetforMiniPlayerView;
- (_Bool)supportAttachMiniPlayerView;
- (void)didComeInThisControllWithFromContorller:(id)arg1 changeType:(long long)arg2;
- (_Bool)needContinuePlayCurrentVideo:(long long)arg1;
- (void)didLeaveThisControllWithToContorller:(id)arg1 changeType:(long long)arg2;
- (void)willComeInThisControllWithFromContorller:(id)arg1 changeType:(long long)arg2;
- (void)willLeaveThisControllWithToContorller:(id)arg1 changeType:(long long)arg2;
- (double)adjustedBottomSpaceForScroll;
- (double)adjustedTopSpaceForScroll;
- (_Bool)canPlayVideoWithListVideoAssistor:(id)arg1;
- (id)getShareToEmailInfo;
- (_Bool)_shouldAutoPlayVideo;
- (void)_startVideoPreLoadWithVideoList:(id)arg1;
- (void)p_prefetchVideoData;
- (void)p_scrollViewDidEndScrolling:(id)arg1;
- (void)scrollViewDidEndDragging:(id)arg1 willDecelerate:(_Bool)arg2;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (void)scrollViewDidScroll:(id)arg1;
- (void)triggerInfiniteScrolling;
- (void)_initVideoAssistor;
- (void)p_tryReportCellTimeConsume;
- (void)p_enterNewsChannel;
- (void)p_channelBtnClick;
- (_Bool)p_openModuleMorePageView:(id)arg1;
- (void)openHotSpotNewsAtIndexPath:(id)arg1;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forRowAtIndexPath:(id)arg3;
- (void)tableView:(id)arg1 didEndDisplayingCell:(id)arg2 forRowAtIndexPath:(id)arg3;
- (void)additionalOperationsAfterLoadModelSuccess:(id)arg1;
- (long long)customTableViewStyle;
- (id)customListDataAdapter;
- (id)customViewModel;
- (_Bool)canShowJumpToRecommendListTip;
- (void)p_updateStatusBarStyle:(long long)arg1;
- (void)p_updateStatusBarStyleWithNaviAlpha:(double)arg1;
- (void)_reportArticleExposureWithKBListItem:(id)arg1 index:(id)arg2;
- (id)p_cellId;
- (double)p_headerFocusViewHeight;
- (id)getCustomShareInfo;
- (id)headerView;
- (void)p_showTopTipsView:(id)arg1;
- (void)refreshViewPackUpFinish:(_Bool)arg1;
- (void)refreshViewPackUpBegin:(_Bool)arg1;
- (void)didEnterBackground:(id)arg1;
- (id)pageTypeForReport;
- (void)onBack:(id)arg1;
- (void)p_addNavigationViewAndFocusViewAfterDataLoadingCompleted;
- (void)viewDidLoad;
- (id)initWithParam:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

