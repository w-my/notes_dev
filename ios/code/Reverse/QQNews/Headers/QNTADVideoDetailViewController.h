//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRootViewController.h"

#import "QNShareActivityControllerDelegate.h"
#import "SKStoreProductViewControllerDelegate.h"
#import "TADImmerseVideoViewDelegate.h"
#import "TADTKVPlayerDelegate.h"
#import "UIGestureRecognizerDelegate.h"
#import "UIScrollViewDelegate.h"

@class NSString, QNAdItem, QNAdWebviewViewController, QNListNewsItem, TADImmerseVideoView, TADQNHalfScreenStoreViewController, UIPanGestureRecognizer;

@interface QNTADVideoDetailViewController : QNRootViewController <UIScrollViewDelegate, QNShareActivityControllerDelegate, TADTKVPlayerDelegate, SKStoreProductViewControllerDelegate, TADImmerseVideoViewDelegate, UIGestureRecognizerDelegate>
{
    _Bool _webViewStickOnTop;
    _Bool _preventChangeNavBarAlpha;
    _Bool _needAutoContinue;
    _Bool _hasShownPage;
    _Bool _trackingStarts;
    TADImmerseVideoView *_playerView;
    QNAdWebviewViewController *_webViewController;
    QNListNewsItem *_listItem;
    QNAdItem *_adItem;
    TADQNHalfScreenStoreViewController *_storeViewController;
    long long _scrollDirection;
    double _lastContentOffsetY;
    double _gestureLastContentOffsetY;
    UIPanGestureRecognizer *_panGestureRecongnizer;
}

@property(retain, nonatomic) UIPanGestureRecognizer *panGestureRecongnizer; // @synthesize panGestureRecongnizer=_panGestureRecongnizer;
@property(nonatomic) double gestureLastContentOffsetY; // @synthesize gestureLastContentOffsetY=_gestureLastContentOffsetY;
@property(nonatomic) _Bool trackingStarts; // @synthesize trackingStarts=_trackingStarts;
@property(nonatomic) double lastContentOffsetY; // @synthesize lastContentOffsetY=_lastContentOffsetY;
@property(nonatomic) long long scrollDirection; // @synthesize scrollDirection=_scrollDirection;
@property(retain, nonatomic) TADQNHalfScreenStoreViewController *storeViewController; // @synthesize storeViewController=_storeViewController;
@property(retain, nonatomic) QNAdItem *adItem; // @synthesize adItem=_adItem;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(nonatomic) _Bool hasShownPage; // @synthesize hasShownPage=_hasShownPage;
@property(nonatomic) _Bool needAutoContinue; // @synthesize needAutoContinue=_needAutoContinue;
@property(nonatomic) _Bool preventChangeNavBarAlpha; // @synthesize preventChangeNavBarAlpha=_preventChangeNavBarAlpha;
@property(nonatomic) _Bool webViewStickOnTop; // @synthesize webViewStickOnTop=_webViewStickOnTop;
@property(retain, nonatomic) QNAdWebviewViewController *webViewController; // @synthesize webViewController=_webViewController;
@property(retain, nonatomic) TADImmerseVideoView *playerView; // @synthesize playerView=_playerView;
- (void).cxx_destruct;
- (_Bool)qnNavigationController:(id)arg1 shouldInteractiveGestureRecognizerBegin:(id)arg2;
- (id)getCustomShareInfo;
- (void)onShare:(id)arg1;
- (void)_handleAppStoreVCDismiss;
- (void)closeStoreViewController;
- (void)willMoveToParentViewController:(id)arg1;
- (void)onBack:(id)arg1;
- (void)resetWithBeginContentOffsetY:(double)arg1;
- (void)p_doScrollPageWithTop:(double)arg1;
- (void)p_updateVideoViewTop:(double)arg1 animated:(_Bool)arg2;
- (void)endDragingWithScrollView:(id)arg1 autoScroll:(_Bool)arg2;
- (void)endDragingWithScrollView:(id)arg1;
- (void)p_updateVideoViewFollowingScrollView:(id)arg1 animated:(_Bool)arg2;
- (double)videoPosionThreshold;
- (_Bool)p_webViewBottomBouncing;
- (_Bool)p_webViewTopBouncing;
- (void)scrollViewDidEndScrollingAnimation:(id)arg1;
- (void)scrollViewDidEndDragging:(id)arg1 willDecelerate:(_Bool)arg2;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (void)scrollViewDidScroll:(id)arg1;
- (void)scrollViewWillBeginDragging:(id)arg1;
- (_Bool)gestureRecognizer:(id)arg1 shouldRecognizeSimultaneouslyWithGestureRecognizer:(id)arg2;
- (void)handlePanGesture:(id)arg1;
- (void)p_changeStageWithVideoTop:(double)arg1;
- (void)stickWebViewOnTop;
- (void)p_playerDidPlay;
- (void)p_onDetailClicked;
- (void)videoViewDetailBtnClicked;
- (void)videoViewFinishDetailBtnClicked;
- (void)videoViewResumePlaying;
- (void)videoViewStartPlaying;
- (void)productViewControllerDidFinish:(id)arg1;
- (void)loadHalfScreenAppStorePage;
- (void)loadFullScreenAppStorePage;
- (double)p_oriVideoTop;
- (double)p_maxVideoHideOffset;
- (double)p_videoHeight;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewWillAppear:(_Bool)arg1;
- (void)p_registeJSEventHandlers;
- (void)viewDidLoad;
- (void)dealloc;
- (id)initWithParam:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
