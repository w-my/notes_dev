//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CRootViewController.h"

#import "QNExplosureReportDelegate.h"
#import "SVPullToRefreshViewDelegate.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class CNewsViewControllerParam, NSMutableDictionary, NSString, QNClientInsertCellsManager, QNListShowVerticalCellTipView, QNListTopTipsView, QNListTopToolBar, UIButton;

@interface CNewsViewController : CRootViewController <SVPullToRefreshViewDelegate, UITableViewDelegate, UITableViewDataSource, QNExplosureReportDelegate>
{
    _Bool _enableShowTabBarNewsTabHelpView;
    _Bool _hasVerticalCell;
    _Bool _hideVerticalCell;
    _Bool _canShowTip;
    _Bool _isMyCellClicked;
    _Bool _needConcernOverlayTipAfterRefresh;
    _Bool _bActive;
    _Bool _hasAddSurplusCell;
    _Bool _topToolBarNeedAutoScroll;
    _Bool _isVideoStyleB;
    _Bool _isVideoAlbumStyleB;
    _Bool _isPlayerControl;
    _Bool _shouldDoubleCheck;
    unsigned long long _channelRefreshMode;
    long long _firstCellScrollPage;
    QNListTopTipsView *_tipView;
    UIButton *_jumpToRecommendListButton;
    long long _network;
    NSMutableDictionary *_depthCellReports;
    NSString *_lastShowWatchInfoId;
    unsigned long long _clientInsertCellType;
    QNClientInsertCellsManager *_clientInsertCellsManager;
    QNListTopToolBar *_topToolBar;
    NSString *_currentCityID;
    NSString *_parentChannelID;
    CNewsViewControllerParam *_cNewsViewParam;
    QNListShowVerticalCellTipView *_showVerticalTipView;
}

+ (id)_realChannelIDForCurrentChannelID:(id)arg1;
+ (_Bool)getHideVerticalCellInChannelID:(id)arg1;
+ (void)saveHideVerticalCell:(_Bool)arg1 channelID:(id)arg2;
+ (id)_keyForHideVerticalCell:(id)arg1;
@property(retain, nonatomic) QNListShowVerticalCellTipView *showVerticalTipView; // @synthesize showVerticalTipView=_showVerticalTipView;
@property(nonatomic) _Bool shouldDoubleCheck; // @synthesize shouldDoubleCheck=_shouldDoubleCheck;
@property(nonatomic) _Bool isPlayerControl; // @synthesize isPlayerControl=_isPlayerControl;
@property(nonatomic) _Bool isVideoAlbumStyleB; // @synthesize isVideoAlbumStyleB=_isVideoAlbumStyleB;
@property(nonatomic) _Bool isVideoStyleB; // @synthesize isVideoStyleB=_isVideoStyleB;
@property(retain, nonatomic) CNewsViewControllerParam *cNewsViewParam; // @synthesize cNewsViewParam=_cNewsViewParam;
@property(copy, nonatomic) NSString *parentChannelID; // @synthesize parentChannelID=_parentChannelID;
@property(copy, nonatomic) NSString *currentCityID; // @synthesize currentCityID=_currentCityID;
@property(nonatomic) _Bool topToolBarNeedAutoScroll; // @synthesize topToolBarNeedAutoScroll=_topToolBarNeedAutoScroll;
@property(retain, nonatomic) QNListTopToolBar *topToolBar; // @synthesize topToolBar=_topToolBar;
@property(retain, nonatomic) QNClientInsertCellsManager *clientInsertCellsManager; // @synthesize clientInsertCellsManager=_clientInsertCellsManager;
@property(nonatomic) unsigned long long clientInsertCellType; // @synthesize clientInsertCellType=_clientInsertCellType;
@property(retain, nonatomic) NSString *lastShowWatchInfoId; // @synthesize lastShowWatchInfoId=_lastShowWatchInfoId;
@property(nonatomic) _Bool hasAddSurplusCell; // @synthesize hasAddSurplusCell=_hasAddSurplusCell;
@property(retain, nonatomic) NSMutableDictionary *depthCellReports; // @synthesize depthCellReports=_depthCellReports;
@property(nonatomic) _Bool bActive; // @synthesize bActive=_bActive;
@property(nonatomic) long long network; // @synthesize network=_network;
@property(nonatomic) _Bool needConcernOverlayTipAfterRefresh; // @synthesize needConcernOverlayTipAfterRefresh=_needConcernOverlayTipAfterRefresh;
@property(nonatomic) _Bool isMyCellClicked; // @synthesize isMyCellClicked=_isMyCellClicked;
@property(nonatomic) _Bool canShowTip; // @synthesize canShowTip=_canShowTip;
@property(retain, nonatomic) UIButton *jumpToRecommendListButton; // @synthesize jumpToRecommendListButton=_jumpToRecommendListButton;
@property(retain, nonatomic) QNListTopTipsView *tipView; // @synthesize tipView=_tipView;
@property long long firstCellScrollPage; // @synthesize firstCellScrollPage=_firstCellScrollPage;
@property(nonatomic) _Bool hideVerticalCell; // @synthesize hideVerticalCell=_hideVerticalCell;
@property(nonatomic) _Bool hasVerticalCell; // @synthesize hasVerticalCell=_hasVerticalCell;
@property(nonatomic) unsigned long long channelRefreshMode; // @synthesize channelRefreshMode=_channelRefreshMode;
@property(nonatomic) _Bool enableShowTabBarNewsTabHelpView; // @synthesize enableShowTabBarNewsTabHelpView=_enableShowTabBarNewsTabHelpView;
- (void).cxx_destruct;
- (void)checkInfoForReport;
- (void)_cleanChannelDataAndRefresh;
- (void)_updateCityDataIfNeed;
- (void)_checkCurrentCity;
- (void)_checkCurrentChannelWithCityItem:(id)arg1;
- (void)_handleCityRemoteConfChecked:(id)arg1;
- (void)_handleCityDataUpdate:(id)arg1;
- (void)_handleChangeCity:(id)arg1;
- (void)updateCurrentChannelIDIfNeed:(id)arg1;
- (void)_handleVerticalCellNotAutoHideNotification;
- (void)configTableViewCellLayoutContext:(id)arg1 forData:(id)arg2 indexPath:(id)arg3;
- (void)themeChanged:(long long)arg1;
- (void)_checkTopToolBarForHidden;
- (void)_showPackupVerticalCellBtn:(_Bool)arg1 animation:(_Bool)arg2 checkHidden:(_Bool)arg3;
- (void)_checkTopToolBarState;
- (void)_initTopToolBar;
- (void)_reloadCell:(id)arg1;
- (void)_jumpToRecommendList;
- (void)_handleWillEnterForegroundNotification:(id)arg1;
- (void)_packupVerticalCell:(_Bool)arg1 indexPath:(id)arg2 position:(id)arg3 isAuto:(_Bool)arg4;
- (void)_checkExplosureCellForReport;
- (void)verticalCellDataUpdateFinished:(id)arg1;
- (void)webviewCell:(id)arg1 isReady:(_Bool)arg2;
- (void)commonListContollerRefreshCell:(id)arg1 listItem:(id)arg2 animation:(long long)arg3;
- (void)commonListContollerPackupCell:(id)arg1 packup:(_Bool)arg2 listItem:(id)arg3;
- (_Bool)qnNavigationController:(id)arg1 shouldInteractiveGestureRecognizerBegin:(id)arg2;
- (void)_delayPackUpSearchBar:(id)arg1;
- (long long)do_numberOfExtraItems;
- (_Bool)do_shouldShowTopDateView;
- (_Bool)do_shouldAddSurplusCell;
- (void)p_reloadClientInsertCell;
- (long long)_getClientInsertCellIndex;
- (void)p_reloadClientInsertCellsData;
- (void)p_initSurplusCell;
- (void)scrollViewDidScrollToTop:(id)arg1;
- (void)scrollViewWillBeginDragging:(id)arg1;
- (void)scrollViewDidEndDragging:(id)arg1 willDecelerate:(_Bool)arg2;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (void)scrollViewDidScroll:(id)arg1;
- (void)p_tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 willSelectRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (void)_postLogicOnCellDidLoad:(id)arg1 indexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (void)_reportArticleExposureWithListItem:(id)arg1 tableViewCellIdentifier:(id)arg2;
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forRowAtIndexPath:(id)arg3;
- (_Bool)do_canShowTip;
- (void)refreshViewPackUpFinish:(_Bool)arg1;
- (void)refreshViewPackUpBegin:(_Bool)arg1;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (id)listItemWriteFilter:(id)arg1;
- (id)listItemLoadFilter:(id)arg1;
- (_Bool)do_shouldReloadChangeInfo;
- (void)p_triggleRefreshChannelFromBottomButton:(id)arg1;
- (void)doneLoadingTableViewData:(_Bool)arg1;
- (void)p_newsViewControllerNavigate:(id)arg1 indexPath:(id)arg2;
- (void)refreshCurrentChannel;
- (void)doRefreshListData;
- (void)CDataLoaderDownloadListComplete:(id)arg1;
- (id)organisedItemListForList:(id)arg1;
- (id)configCDataLoaderPostValues:(id)arg1;
- (void)doUpdateDataWork:(id)arg1;
- (_Bool)scrollViewShouldScrollToTop:(id)arg1;
- (void)onStatusBarWindowTapEnd:(id)arg1;
- (void)do_selectedAsCurrentChannel:(id)arg1;
- (void)do_deselectedAsCurrentChannel:(id)arg1;
- (_Bool)shouldAutorotateToInterfaceOrientation:(long long)arg1;
- (void)viewDidDisappear:(_Bool)arg1;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (void)viewWillAppear:(_Bool)arg1;
- (void)dealloc;
- (void)_addNotificationsObserver;
- (id)initWithParam:(id)arg1;
- (id)initWithID:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
