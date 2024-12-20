//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRootViewController.h"

#import "QNQualityCourseMoreListViewDelegate.h"
#import "UIScrollViewDelegate.h"

@class NSString, QNBarButton, QNDetailContentContainer, QNListNewsItem, QNLoadingShimmerView, QNQualityCourseAlbumBottomBar, QNQualityCourseAlbumViewModel, QNQualityCourseHeaderView, QNQualityCourseMoreListView;

@interface QNQualityCourseAlbumController : QNRootViewController <UIScrollViewDelegate, QNQualityCourseMoreListViewDelegate>
{
    _Bool _preventChangeNavBarAlpha;
    QNListNewsItem *_listItem;
    QNQualityCourseAlbumViewModel *_viewModel;
    QNQualityCourseHeaderView *_headerView;
    QNQualityCourseAlbumBottomBar *_bottomBar;
    QNQualityCourseMoreListView *_moreListView;
    QNBarButton *_backButton;
    QNLoadingShimmerView *_loadingShimmerView;
    QNDetailContentContainer *_contentContainer;
}

@property(retain, nonatomic) QNDetailContentContainer *contentContainer; // @synthesize contentContainer=_contentContainer;
@property(retain, nonatomic) QNLoadingShimmerView *loadingShimmerView; // @synthesize loadingShimmerView=_loadingShimmerView;
@property(nonatomic) _Bool preventChangeNavBarAlpha; // @synthesize preventChangeNavBarAlpha=_preventChangeNavBarAlpha;
@property(retain, nonatomic) QNBarButton *backButton; // @synthesize backButton=_backButton;
@property(retain, nonatomic) QNQualityCourseMoreListView *moreListView; // @synthesize moreListView=_moreListView;
@property(retain, nonatomic) QNQualityCourseAlbumBottomBar *bottomBar; // @synthesize bottomBar=_bottomBar;
@property(retain, nonatomic) QNQualityCourseHeaderView *headerView; // @synthesize headerView=_headerView;
@property(retain, nonatomic) QNQualityCourseAlbumViewModel *viewModel; // @synthesize viewModel=_viewModel;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
- (void).cxx_destruct;
- (void)scrollViewDidScroll:(id)arg1;
- (void)moreCourseListView:(id)arg1 didSelectedCourse:(id)arg2;
- (void)p_showBuyCourseAlert;
- (void)p_loginAndReload;
- (void)p_loadingFailed;
- (void)p_requestContentData;
- (void)p_layoutElementViews;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (void)configBarButtons;
- (void)onBack:(id)arg1;
- (id)initWithParam:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

