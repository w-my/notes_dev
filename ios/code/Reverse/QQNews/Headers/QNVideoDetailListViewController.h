//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNVideoDetailListBaseViewController.h"

#import "QNVideoDetailListBaseViewCtrlerProtocol.h"
#import "TADVideoListAdLoaderProtocol.h"

@class NSMutableArray, NSString, QNImmerseSectionHeaderTableViewCell, QNListNewsItem, QNRootViewController, QNVideoCommendLoader, TADSSPImmerseAsyncLoader, TADVideoListReportManager, UIView;

@interface QNVideoDetailListViewController : QNVideoDetailListBaseViewController <TADVideoListAdLoaderProtocol, QNVideoDetailListBaseViewCtrlerProtocol>
{
    _Bool _isOnlyReloadTableOnLoadingFinished;
    _Bool _isToCommentTable;
    _Bool _hasUserAction;
    _Bool _hasLeftCurrentPage;
    NSString *_sourceTypeOfPassIn;
    NSString *_sourceIDofPassIn;
    long long _preRowForShow;
    QNRootViewController *_preViewController;
    double _myTopOfPreView;
    UIView *_playerSuperViewForAnimation;
    QNImmerseSectionHeaderTableViewCell *_sectionHeaderCell;
    QNVideoCommendLoader *_likeCommendLoader;
    long long _hasInsertedVideoNumber;
    QNListNewsItem *_lastInsertListItem;
    NSMutableArray *_loadedRecVideoIDS;
    TADSSPImmerseAsyncLoader *_adAsyncLoader;
    long long _videoInsertNum;
    NSString *_detailScheme;
    TADVideoListReportManager *_videoListAdReporter;
    struct CGRect _preCellMiddleViewFrameOfPreView;
}

@property(retain, nonatomic) TADVideoListReportManager *videoListAdReporter; // @synthesize videoListAdReporter=_videoListAdReporter;
@property(copy, nonatomic) NSString *detailScheme; // @synthesize detailScheme=_detailScheme;
@property(nonatomic) long long videoInsertNum; // @synthesize videoInsertNum=_videoInsertNum;
@property(retain, nonatomic) TADSSPImmerseAsyncLoader *adAsyncLoader; // @synthesize adAsyncLoader=_adAsyncLoader;
@property(retain, nonatomic) NSMutableArray *loadedRecVideoIDS; // @synthesize loadedRecVideoIDS=_loadedRecVideoIDS;
@property(nonatomic) _Bool hasLeftCurrentPage; // @synthesize hasLeftCurrentPage=_hasLeftCurrentPage;
@property(nonatomic) _Bool hasUserAction; // @synthesize hasUserAction=_hasUserAction;
@property(copy, nonatomic) QNListNewsItem *lastInsertListItem; // @synthesize lastInsertListItem=_lastInsertListItem;
@property(nonatomic) long long hasInsertedVideoNumber; // @synthesize hasInsertedVideoNumber=_hasInsertedVideoNumber;
@property(retain, nonatomic) QNVideoCommendLoader *likeCommendLoader; // @synthesize likeCommendLoader=_likeCommendLoader;
@property(retain, nonatomic) QNImmerseSectionHeaderTableViewCell *sectionHeaderCell; // @synthesize sectionHeaderCell=_sectionHeaderCell;
@property(nonatomic) _Bool isToCommentTable; // @synthesize isToCommentTable=_isToCommentTable;
@property(retain, nonatomic) UIView *playerSuperViewForAnimation; // @synthesize playerSuperViewForAnimation=_playerSuperViewForAnimation;
@property(nonatomic) double myTopOfPreView; // @synthesize myTopOfPreView=_myTopOfPreView;
@property(nonatomic) struct CGRect preCellMiddleViewFrameOfPreView; // @synthesize preCellMiddleViewFrameOfPreView=_preCellMiddleViewFrameOfPreView;
@property(nonatomic) __weak QNRootViewController *preViewController; // @synthesize preViewController=_preViewController;
@property(nonatomic) long long preRowForShow; // @synthesize preRowForShow=_preRowForShow;
@property(nonatomic) _Bool isOnlyReloadTableOnLoadingFinished; // @synthesize isOnlyReloadTableOnLoadingFinished=_isOnlyReloadTableOnLoadingFinished;
@property(copy, nonatomic) NSString *sourceIDofPassIn; // @synthesize sourceIDofPassIn=_sourceIDofPassIn;
@property(copy, nonatomic) NSString *sourceTypeOfPassIn; // @synthesize sourceTypeOfPassIn=_sourceTypeOfPassIn;
- (void).cxx_destruct;
- (void)videoListMoreAdLoadFinish:(id)arg1 loader:(id)arg2;
- (void)videoListTopAdLoadFinish:(id)arg1 loader:(id)arg2;
- (void)qnNavigationController:(id)arg1 interactionWillEnd:(_Bool)arg2;
- (id)currentPageTagId;
- (_Bool)needContinuePlayCurrentVideo:(long long)arg1;
- (_Bool)IsEffectiveClickedOfSubCtrlerWithCell:(id)arg1;
- (id)createMyDataAdapter;
- (id)createDetailListLoader;
- (id)createDetailListModel;
- (id)getRequestPostKeyValuesWithDirection:(unsigned long long)arg1;
- (_Bool)requestWithDirection:(unsigned long long)arg1;
- (void)currentChangedWithItem:(id)arg1 indexpath:(id)arg2;
- (void)executeMyPushOperatingWithFromCtrler:(id)arg1 tapToLoadText:(id)arg2;
- (_Bool)isDoEnterAnimationWithFromCtrler:(id)arg1;
- (_Bool)firstCellIsPlaying;
- (id)getFirstCell;
- (double)getFirstCellMiddleViewTopInMyView;
- (void)backAnimationWithView:(id)arg1;
- (void)onBack:(id)arg1;
- (_Bool)isToSmartViewOfCurrentPlayerForPreViewCtrler;
- (void)addMyViewWithAnimationAndPreController:(id)arg1 isDoEnterAnimation:(_Bool)arg2 completion:(CDUnknownBlockType)arg3;
- (void)p_loadSingleRecommendVideoWithListItem:(id)arg1 index:(unsigned long long)arg2 videoDetailItem:(id)arg3;
- (id)p_exposedids;
- (void)p_loadRecommendVideosWithListItem:(id)arg1 index:(unsigned long long)arg2 videoDetailItem:(id)arg3;
- (void)p_conifgForNewStyle;
- (void)p_handleEnterBackgroundEvent;
- (void)dealloc;
- (void)didReceiveMemoryWarning;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewWillAppear:(_Bool)arg1;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (id)initWithParam:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
