//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNVideoDetailListBaseViewController.h"

#import "QNVideoDetailListBaseViewCtrlerProtocol.h"
#import "TADVideoListAdLoaderProtocol.h"

@class CArticleContentVideoAlbumNodeType, NSString, QNSubscribeNavigationView, QNVideoVerticalAlbumAdapter, TADVideoListReportManager, UILabel, UITableView, UIView;

@interface QNVideoAlbumDetailListViewController : QNVideoDetailListBaseViewController <TADVideoListAdLoaderProtocol, QNVideoDetailListBaseViewCtrlerProtocol>
{
    _Bool _isHideAnimating;
    _Bool _hasUserAction;
    long long _coutVideoOfAlbum;
    long long _preRowForShow;
    NSString *_vidForFirstPlay;
    UIView *_emptyView;
    UIView *_titleBGView;
    double _titleBGImgViewBaseHeight;
    CArticleContentVideoAlbumNodeType *_preVideoAlbumNode;
    UIView *_albumTitleView;
    UILabel *_albumTitleLabel;
    UITableView *_albumTableView;
    QNSubscribeNavigationView *_navigationView;
    QNVideoVerticalAlbumAdapter *_verticalAlbumAdapter;
    TADVideoListReportManager *_videoListAdReportManager;
    long long _showVideoAlbumNum;
    NSString *_detailScheme;
}

@property(copy, nonatomic) NSString *detailScheme; // @synthesize detailScheme=_detailScheme;
@property(nonatomic) long long showVideoAlbumNum; // @synthesize showVideoAlbumNum=_showVideoAlbumNum;
@property(retain, nonatomic) TADVideoListReportManager *videoListAdReportManager; // @synthesize videoListAdReportManager=_videoListAdReportManager;
@property(retain, nonatomic) QNVideoVerticalAlbumAdapter *verticalAlbumAdapter; // @synthesize verticalAlbumAdapter=_verticalAlbumAdapter;
@property(retain, nonatomic) QNSubscribeNavigationView *navigationView; // @synthesize navigationView=_navigationView;
@property(nonatomic) _Bool hasUserAction; // @synthesize hasUserAction=_hasUserAction;
@property(retain, nonatomic) UITableView *albumTableView; // @synthesize albumTableView=_albumTableView;
@property(retain, nonatomic) UILabel *albumTitleLabel; // @synthesize albumTitleLabel=_albumTitleLabel;
@property(retain, nonatomic) UIView *albumTitleView; // @synthesize albumTitleView=_albumTitleView;
@property(nonatomic) _Bool isHideAnimating; // @synthesize isHideAnimating=_isHideAnimating;
@property(retain, nonatomic) CArticleContentVideoAlbumNodeType *preVideoAlbumNode; // @synthesize preVideoAlbumNode=_preVideoAlbumNode;
@property(nonatomic) double titleBGImgViewBaseHeight; // @synthesize titleBGImgViewBaseHeight=_titleBGImgViewBaseHeight;
@property(retain, nonatomic) UIView *titleBGView; // @synthesize titleBGView=_titleBGView;
@property(retain, nonatomic) UIView *emptyView; // @synthesize emptyView=_emptyView;
@property(copy, nonatomic) NSString *vidForFirstPlay; // @synthesize vidForFirstPlay=_vidForFirstPlay;
@property(nonatomic) long long preRowForShow; // @synthesize preRowForShow=_preRowForShow;
@property(nonatomic) long long coutVideoOfAlbum; // @synthesize coutVideoOfAlbum=_coutVideoOfAlbum;
- (void).cxx_destruct;
- (void)videoListMoreAdLoadFinish:(id)arg1 loader:(id)arg2;
- (void)videoListTopAdLoadFinish:(id)arg1 loader:(id)arg2;
- (void)p_handleEnterBackgroundEvent;
- (void)didPlayWithItem:(id)arg1 indexPath:(id)arg2;
- (_Bool)IsEffectiveClickedOfSubCtrlerWithCell:(id)arg1;
- (id)createMyDataAdapter;
- (id)createDetailListLoader;
- (id)createDetailListModel;
- (_Bool)refreshListModels;
- (_Bool)requestWithDirection:(unsigned long long)arg1;
- (id)getRequestPostKeyValuesWithDirection:(unsigned long long)arg1;
- (void)titleViewHideAnimated:(_Bool)arg1;
- (void)titleViewShowAnimated:(_Bool)arg1;
- (void)p_updateTitleViewWithContentOffset:(double)arg1 upSwipe:(_Bool)arg2;
- (void)didScroll;
- (void)setTitleBGViewHeightWithCellHeight:(double)arg1;
- (void)currentChangedWithItem:(id)arg1 indexpath:(id)arg2;
- (_Bool)isWillShowingLoadingView;
- (id)currentPageTagId;
- (void)didComeInThisControllWithFromContorller:(id)arg1 changeType:(long long)arg2;
- (_Bool)needContinuePlayCurrentVideo:(long long)arg1;
- (void)removeEmptyView;
- (void)hideEmptyView;
- (void)showEmptyView;
- (void)refreshListModelsFromEmptyView;
- (void)updateAlbumTitleView;
- (void)createAndAddAlbumTitleView;
- (void)showLoading:(_Bool)arg1 animated:(_Bool)arg2;
- (id)loadingView;
- (void)onBack:(id)arg1;
- (void)onAction:(id)arg1;
- (void)configBarButtons;
- (void)didReceiveMemoryWarning;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewWillAppear:(_Bool)arg1;
- (void)viewDidAppear:(_Bool)arg1;
- (void)p_configForNewStyle;
- (void)p_initAdapter;
- (void)do_initAdapter;
- (void)viewDidLoad;
- (void)dealloc;
- (id)initWithParam:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
