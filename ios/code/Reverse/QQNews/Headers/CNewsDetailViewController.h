//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CBaseDetailViewController.h"

#import "QNNewsDetailViewDelegate.h"
#import "UIGestureRecognizerDelegate.h"

@class CSubscribeListItemNode, NSString, QNDetailCommonHandler, QNDetailRelateNewsApi, QNNewsDetailLoader, QNNewsDetailViewModel, QNTopicItem;

@interface CNewsDetailViewController : CBaseDetailViewController <QNNewsDetailViewDelegate, UIGestureRecognizerDelegate>
{
    QNTopicItem *_topicItem;
    CSubscribeListItemNode *_node;
    _Bool _isHelpViewShowed;
    _Bool _isContentLoaded;
    _Bool _isViewAppeared;
    _Bool _hasLeftThisPage;
    QNNewsDetailViewModel *_viewModel;
    QNDetailCommonHandler *_articleViewHandler;
    QNDetailRelateNewsApi *_relateNewsApi;
}

@property(retain, nonatomic) QNDetailRelateNewsApi *relateNewsApi; // @synthesize relateNewsApi=_relateNewsApi;
@property(retain, nonatomic) QNDetailCommonHandler *articleViewHandler; // @synthesize articleViewHandler=_articleViewHandler;
@property(retain, nonatomic) QNNewsDetailViewModel *viewModel; // @synthesize viewModel=_viewModel;
- (void).cxx_destruct;
- (void)containerOffsetDidChange:(struct CGPoint)arg1;
- (void)newsContentLoadFail;
- (void)newsContentHasShow;
- (void)p_showFailed;
- (void)qn_newsDetailLoadFailed:(id)arg1;
- (void)qn_newsDetailLoadSuccess:(id)arg1;
- (void)qn_newsDetailWillLoadData;
- (id)qn_newsDetailLoaderRequestParams:(id)arg1;
- (void)qn_newsDetailConfigLoader:(id)arg1;
- (_Bool)isNeedEnterDetailPageAnimation;
- (void)didComeInThisControllWithFromContorller:(id)arg1 changeType:(long long)arg2;
- (void)willComeInThisControllWithFromContorller:(id)arg1 changeType:(long long)arg2;
- (void)willLeaveThisControllWithToContorller:(id)arg1 changeType:(long long)arg2;
- (void)updateBottomBarState:(long long)arg1;
- (void)commentNumChanged;
- (void)commentLoadStateChanged:(id)arg1 loadState:(long long)arg2;
- (id)newTotalCommentTipContainView:(id)arg1;
- (id)newTotalCommentLoadTip;
- (id)newTotalCommentLoadingAnimationTip;
- (void)totoalCommentLoadBtnClicked;
- (void)resetTotalCommentsView;
- (void)contentScrollViewDidScroll:(id)arg1;
- (void)onReturnAction;
- (void)commentBarDidClickExchangeButton;
- (void)commentBarDidClickWriteCommentButton;
- (void)p_handleRefreshTopComments:(id)arg1;
- (void)p_handleEnterBackgroundEvent;
- (void)p_handleImageBrowserFullscreen;
- (void)p_dealWithCommentLoadStateSuccessed:(id)arg1;
- (void)p_dealWithCommentLoadStateClosed;
- (void)p_writeCommentViewLayoutIfNeeded:(_Bool)arg1;
- (void)p_showTagLinkHelpView;
- (void)p_updateVideoNode:(id)arg1 withMultiStreams:(id)arg2;
- (void)do_onEnterContainCommentsCtrler;
- (void)didEnterArticleView;
- (void)didEnterCommentView;
- (void)do_didPresentCommentPage;
- (void)do_didPresentArticlePage;
@property(readonly, copy) NSString *description;
- (id)getCurrentPageID;
- (id)optinalShareData;
- (void)scroll2Top;
- (void)navigationTitleTapped;
- (void)onBack:(id)arg1;
- (void)willOnBack;
- (id)getContentScrollView;
- (void)configTitleView;
- (void)totalCommentsViewCreated;
- (void)reportTotalComments:(_Bool)arg1;
- (double)getTotalCommentsFirstSectionHeaderHeight;
- (void)do_scrollToTotalComments;
- (void)handleLeftSwipeFrom:(id)arg1;
- (_Bool)gestureRecognizerShouldBegin:(id)arg1;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewWillAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (void)dealloc;
- (id)pageTypeForReport;
- (id)initWithParam:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(retain, nonatomic) QNNewsDetailLoader *detailLoader;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

