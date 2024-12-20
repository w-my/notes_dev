//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseDetailViewController.h"

#import "QNNavigationControllerInteractiveGestureDelegate.h"

@class CArticleContainerView, NSString, QNBaseDetailParam, QNNewsDetailLoader;

@interface CBaseDetailViewController : QNBaseDetailViewController <QNNavigationControllerInteractiveGestureDelegate>
{
    QNBaseDetailParam *_baseDetailParam;
    _Bool _isViewedComment;
    _Bool _inCommentPage;
    _Bool _isToCommentCtrlerWhenDidAppear;
    _Bool _isShowKeyboard;
    _Bool _scrollToCommentOfOriginalValue;
    CArticleContainerView *_containerView;
    unsigned long long _commentLocation;
}

@property(nonatomic) _Bool scrollToCommentOfOriginalValue; // @synthesize scrollToCommentOfOriginalValue=_scrollToCommentOfOriginalValue;
@property(nonatomic) unsigned long long commentLocation; // @synthesize commentLocation=_commentLocation;
@property(nonatomic) _Bool isShowKeyboard; // @synthesize isShowKeyboard=_isShowKeyboard;
@property(nonatomic) _Bool inCommentPage; // @synthesize inCommentPage=_inCommentPage;
@property(retain, nonatomic) CArticleContainerView *containerView; // @synthesize containerView=_containerView;
- (void).cxx_destruct;
- (void)do_detailContentDidFailLoad;
- (void)do_detailContentDidShow;
- (void)contentScrollViewDidEndScrolling:(id)arg1;
- (void)contentScrollViewWillBeginDragging:(id)arg1;
- (void)contentScrollViewDidScroll:(id)arg1;
- (void)updateBottomBarState:(long long)arg1;
- (void)qnNavigationController:(id)arg1 interactionWillBegin:(_Bool)arg2;
- (_Bool)qnNavigationController:(id)arg1 shouldInteractiveGestureRecognizerBegin:(id)arg2;
- (void)commentShowKeyboard;
- (void)commentBarDidClickExchangeButton;
- (void)p_togglePagesByPush:(_Bool)arg1 showKeyboard:(_Bool)arg2;
- (unsigned long long)p_commentViewPage;
- (void)didEnterArticleView;
- (void)didEnterCommentView;
- (void)do_newsSwitchToComment;
- (void)do_commentSwitchToNews;
- (void)do_didPresentArticlePage;
- (void)do_didPresentCommentPage;
- (void)showFailed;
- (void)do_onEnterContainCommentsCtrler;
- (void)showContent;
- (void)restoreViewState:(id)arg1;
- (void)saveViewState:(id)arg1;
- (void)cleanupCompletely:(_Bool)arg1;
- (void)scroll2Top;
- (_Bool)isReallyOnBack;
- (_Bool)onBackBtnClick:(id)arg1;
- (void)onBack:(id)arg1;
- (void)willOnBack;
- (void)addDeleteArticleView;
- (void)loadContainerView;
- (void)dealloc;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewWillAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (void)do_layoutSubviews;
- (id)initWithParam:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly, nonatomic) QNNewsDetailLoader *detailLoader;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

