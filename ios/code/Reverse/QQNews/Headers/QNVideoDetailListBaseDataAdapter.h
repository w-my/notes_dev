//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNVideoDetailListModelDelegate.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class NSIndexPath, NSMutableDictionary, NSMutableSet, NSString, QNExclusiveNewsDetailCardCell, QNLayoutTableView, QNVideoAlbumPageViewCell, QNVideoDetailItem, QNVideoDetailListBaseModel, QNVideoPlayerSetting, TADVideoListReportManager, UIButton, UIImageView, UILabel, UITableViewCell<QNImmerseCellProtocol>;

@interface QNVideoDetailListBaseDataAdapter : NSObject <UITableViewDataSource, UITableViewDelegate, QNVideoDetailListModelDelegate>
{
    _Bool _isAllowReattachPlayerViewOrAutoPlay;
    _Bool _isShowingOnTop;
    _Bool _isScrollForPlay;
    _Bool _isClickPlayView;
    _Bool _isPlayedRelatedVideo;
    _Bool _isShowAdjustableCell;
    _Bool _ctrlerIsOnBacked;
    _Bool _isContinueOfPlayer;
    _Bool _isFirstCheckNetwork;
    _Bool _isReportGuidenceView;
    _Bool _isReportExpandCell;
    _Bool _isTADLandingViewPresented;
    _Bool _hasAutoDeleteAndPlayed;
    _Bool _hasInsertedRecommendVideo;
    _Bool _hasReplacedTopVideoByPageView;
    id <QNVideoDetailListBaseViewCtrlerInterface><QNVideoDetaillmmerseCellHandle> _ctrlerInterface;
    NSString *_pageInfo;
    NSString *_vidForFirstPlay;
    NSString *_channelID;
    UITableViewCell<QNImmerseCellProtocol> *_currentCell;
    TADVideoListReportManager *_adManager;
    QNVideoDetailListBaseModel *_detailListModel;
    long long _listViewType;
    long long _playerType;
    QNLayoutTableView *_tableView;
    QNVideoDetailItem *_playedItem;
    double _visibleTop;
    CDUnknownBlockType _recommendBlock;
    CDUnknownBlockType _userActionBlock;
    unsigned long long _from;
    QNVideoPlayerSetting *_videoPlayerSetting;
    NSMutableDictionary *_headerCellMap;
    QNExclusiveNewsDetailCardCell *_cardCellOfHeader;
    UIButton *_autoPlayNextView;
    UILabel *_countDownLabel;
    UIImageView *_rotateImageView;
    UITableViewCell<QNImmerseCellProtocol> *_mainImmerseTableViewCell;
    QNVideoAlbumPageViewCell *_singleAlbumPageViewCell;
    NSIndexPath *_singleAlbumPageViewCellIndexPath;
    NSMutableSet *_exposureVideoSet;
    double _prePlayerTimerForCheckUI;
}

@property(nonatomic) double prePlayerTimerForCheckUI; // @synthesize prePlayerTimerForCheckUI=_prePlayerTimerForCheckUI;
@property(retain, nonatomic) NSMutableSet *exposureVideoSet; // @synthesize exposureVideoSet=_exposureVideoSet;
@property(nonatomic) _Bool hasReplacedTopVideoByPageView; // @synthesize hasReplacedTopVideoByPageView=_hasReplacedTopVideoByPageView;
@property(nonatomic) _Bool hasInsertedRecommendVideo; // @synthesize hasInsertedRecommendVideo=_hasInsertedRecommendVideo;
@property(retain, nonatomic) NSIndexPath *singleAlbumPageViewCellIndexPath; // @synthesize singleAlbumPageViewCellIndexPath=_singleAlbumPageViewCellIndexPath;
@property(retain, nonatomic) QNVideoAlbumPageViewCell *singleAlbumPageViewCell; // @synthesize singleAlbumPageViewCell=_singleAlbumPageViewCell;
@property(nonatomic) _Bool hasAutoDeleteAndPlayed; // @synthesize hasAutoDeleteAndPlayed=_hasAutoDeleteAndPlayed;
@property(retain, nonatomic) UITableViewCell<QNImmerseCellProtocol> *mainImmerseTableViewCell; // @synthesize mainImmerseTableViewCell=_mainImmerseTableViewCell;
@property(nonatomic) _Bool isTADLandingViewPresented; // @synthesize isTADLandingViewPresented=_isTADLandingViewPresented;
@property(nonatomic) _Bool isReportExpandCell; // @synthesize isReportExpandCell=_isReportExpandCell;
@property(nonatomic) _Bool isReportGuidenceView; // @synthesize isReportGuidenceView=_isReportGuidenceView;
@property(nonatomic) _Bool isFirstCheckNetwork; // @synthesize isFirstCheckNetwork=_isFirstCheckNetwork;
@property(nonatomic) _Bool isContinueOfPlayer; // @synthesize isContinueOfPlayer=_isContinueOfPlayer;
@property(retain, nonatomic) UIImageView *rotateImageView; // @synthesize rotateImageView=_rotateImageView;
@property(retain, nonatomic) UILabel *countDownLabel; // @synthesize countDownLabel=_countDownLabel;
@property(retain, nonatomic) UIButton *autoPlayNextView; // @synthesize autoPlayNextView=_autoPlayNextView;
@property(retain, nonatomic) QNExclusiveNewsDetailCardCell *cardCellOfHeader; // @synthesize cardCellOfHeader=_cardCellOfHeader;
@property(retain, nonatomic) NSMutableDictionary *headerCellMap; // @synthesize headerCellMap=_headerCellMap;
@property(nonatomic) _Bool ctrlerIsOnBacked; // @synthesize ctrlerIsOnBacked=_ctrlerIsOnBacked;
@property(retain, nonatomic) QNVideoPlayerSetting *videoPlayerSetting; // @synthesize videoPlayerSetting=_videoPlayerSetting;
@property(nonatomic) unsigned long long from; // @synthesize from=_from;
@property(copy, nonatomic) CDUnknownBlockType userActionBlock; // @synthesize userActionBlock=_userActionBlock;
@property(copy, nonatomic) CDUnknownBlockType recommendBlock; // @synthesize recommendBlock=_recommendBlock;
@property(nonatomic) double visibleTop; // @synthesize visibleTop=_visibleTop;
@property(retain, nonatomic) QNVideoDetailItem *playedItem; // @synthesize playedItem=_playedItem;
@property(retain, nonatomic) QNLayoutTableView *tableView; // @synthesize tableView=_tableView;
@property(nonatomic) _Bool isShowAdjustableCell; // @synthesize isShowAdjustableCell=_isShowAdjustableCell;
@property(nonatomic) long long playerType; // @synthesize playerType=_playerType;
@property(nonatomic) _Bool isPlayedRelatedVideo; // @synthesize isPlayedRelatedVideo=_isPlayedRelatedVideo;
@property(nonatomic) _Bool isClickPlayView; // @synthesize isClickPlayView=_isClickPlayView;
@property(nonatomic) _Bool isScrollForPlay; // @synthesize isScrollForPlay=_isScrollForPlay;
@property(nonatomic) _Bool isShowingOnTop; // @synthesize isShowingOnTop=_isShowingOnTop;
@property(nonatomic) _Bool isAllowReattachPlayerViewOrAutoPlay; // @synthesize isAllowReattachPlayerViewOrAutoPlay=_isAllowReattachPlayerViewOrAutoPlay;
@property(nonatomic) long long listViewType; // @synthesize listViewType=_listViewType;
@property(nonatomic) __weak QNVideoDetailListBaseModel *detailListModel; // @synthesize detailListModel=_detailListModel;
@property(nonatomic) __weak TADVideoListReportManager *adManager; // @synthesize adManager=_adManager;
@property(nonatomic) __weak UITableViewCell<QNImmerseCellProtocol> *currentCell; // @synthesize currentCell=_currentCell;
@property(copy, nonatomic) NSString *channelID; // @synthesize channelID=_channelID;
@property(copy, nonatomic) NSString *vidForFirstPlay; // @synthesize vidForFirstPlay=_vidForFirstPlay;
@property(copy, nonatomic) NSString *pageInfo; // @synthesize pageInfo=_pageInfo;
@property(nonatomic) __weak id <QNVideoDetailListBaseViewCtrlerInterface><QNVideoDetaillmmerseCellHandle> ctrlerInterface; // @synthesize ctrlerInterface=_ctrlerInterface;
- (void).cxx_destruct;
- (id)getControlViewClassByItem:(id)arg1;
- (void)removeItem:(id)arg1 atIndex:(long long)arg2;
- (void)complaintAdItem:(id)arg1;
- (void)hideAdUnlikeTipsViewWithDetailItem:(id)arg1;
- (id)preloadArray;
- (void)startVideoPreLoadWithArray:(id)arg1;
- (void)qn_delayVideoPreLoad;
- (void)preloadData;
- (_Bool)isNeedReportClickEventOfVideoRecommendWithDetailItem:(id)arg1;
- (void)resetShowAllCellsWhenModelLoadFinishedWithLoadDirection:(unsigned long long)arg1;
- (void)modelLoadFinishedWithCurPlayCell:(id)arg1 loadDirection:(unsigned long long)arg2;
- (void)listModeldidDeleteTwoInsertOneFinished:(id)arg1 fromIndex:(unsigned long long)arg2;
- (void)listModeldidDeleteTwoFinished:(id)arg1 fromIndex:(unsigned long long)arg2;
- (void)listModeldidLoadInsertTwoFinished:(id)arg1 fromIndex:(unsigned long long)arg2;
- (void)listModeldidLoadDeleteFinished:(id)arg1 index:(unsigned long long)arg2;
- (void)listModeldidLoadInsertFinished:(id)arg1 index:(unsigned long long)arg2;
- (void)listModeldidLoadFinished:(id)arg1 direction:(unsigned long long)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forRowAtIndexPath:(id)arg3;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (void)p_openVideoChannelGuidance;
- (void)p_expandShrinkedVideoItemsAtPosition:(long long)arg1;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (double)getVideoDetailImmerseTableViewCellHeightWithDetailitem:(id)arg1;
- (void)p_checkAutoDeleteAndPlay;
- (void)scrollViewDidScroll:(id)arg1;
- (void)scrollViewDidScrollToTop:(id)arg1;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (void)scrollViewDidEndDragging:(id)arg1 willDecelerate:(_Bool)arg2;
- (void)scrollViewWillBeginDragging:(id)arg1;
- (void)autoPlayVideo;
- (void)laterAutoPlayVideoWhenScrolled;
- (void)do_autoDarkVisibleCellsExceptCenter;
- (id)getHeaderTableViewCellOfPreCurCell:(id)arg1;
- (id)getHeaderTableViewCellWithRow:(long long)arg1;
- (id)getNextCellFromCurIndexPath:(id)arg1;
- (id)getPreCellFromCurIndexPath:(id)arg1;
- (id)getPreAdCellFromCell:(id)arg1;
- (id)getPreAlbumTitleTableViewCellFromCell:(id)arg1;
- (id)getPreExclusiveNewsDetailCardCellFromCell:(id)arg1;
- (id)getListItemFromCurIndex:(long long)arg1;
- (void)animatedAndbrightCell:(id)arg1;
- (void)halfDarkCell:(id)arg1;
- (void)cell:(id)arg1 switchState:(int)arg2;
- (void)hideCenterCellAnimated;
- (void)hideNavBar;
- (void)showNavBar;
- (void)autoPlayNextBtnClicked;
- (void)hideAutoPlayNextViewAnimated:(_Bool)arg1;
- (void)showAutoPlayNextView;
- (CDUnknownBlockType)finshedPlayBlock;
- (CDUnknownBlockType)listItemForPlayNextBlock;
- (void)p_doPlayerProgress:(double)arg1 bufTime:(double)arg2 duration:(double)arg3;
- (CDUnknownBlockType)getDoProgressBlock;
- (void)subscribeObservers;
- (void)scrollToItemForFirstPlay;
- (_Bool)isInCenterSpaceOfCell:(id)arg1 visibleSpace:(struct CGRect)arg2;
- (struct CGRect)myTableVisibleRect;
- (void)pauseAndRemovePlayer;
- (id)getNextCellOfPlayerCell;
- (id)indexPathOfCurrentPlayerCell;
- (_Bool)currentFullPlayerIsMine;
- (_Bool)isShowingCommentView;
- (_Bool)isShowShareActCtrler;
- (id)listItemForPlayNext;
- (_Bool)isNotAllowContinuePlay;
- (void)p_checkAndLoadMoreListWithItem:(id)arg1;
- (void)p_reportPlayButtonWithListItem:(id)arg1;
- (void)p_animateForPlayDetailItem:(id)arg1 indexPath:(id)arg2;
- (_Bool)playMainVideoWithListItem:(id)arg1 isContinuousPlay:(_Bool)arg2;
- (_Bool)playVideoWithListItem:(id)arg1 isContinuousPlay:(_Bool)arg2;
- (id)getCellWithDetailItem:(id)arg1;
- (id)listItemForPlayNextVideoWithDetailItem:(id)arg1;
- (void)brightCell:(id)arg1;
- (void)darkCell:(id)arg1;
- (void)hideCenterCell;
- (void)brightCenterCell;
- (void)hideCenterCellAnimatedWithDelay:(double)arg1;
- (void)resetPlayerBlockAboutAdapter;
- (_Bool)playNextVideo;
- (void)closePlayer;
- (_Bool)p_isAllowedToAutoplayInAlbumList;
- (_Bool)autoPlayVideoWhenScrolled:(id)arg1 isJumpConfiguration:(_Bool)arg2;
- (void)tryToPlayVideoOnCommentView;
- (_Bool)checkPlayerInCenterCell;
- (id)getCenterCell;
- (id)castImmerseCell:(id)arg1;
- (id)getCellIndexPathAtBasePos;
- (id)getNeedShowTopIndexPathFromCurIndexPath:(id)arg1;
- (id)cellIndexPathWithDetailItem:(id)arg1;
- (void)handlePlayerIntoCenterCell;
- (void)syncOMSubscribEvent:(id)arg1;
- (void)dealloc;
- (void)p_handleEnterResignActive;
- (id)initWithTableView:(id)arg1 listModel:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

