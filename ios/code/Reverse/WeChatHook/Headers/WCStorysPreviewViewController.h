//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCDragToCloseViewController.h"

#import "IExtraDeviceLoginMgrExt.h"
#import "UIViewControllerTransitioningDelegate.h"
#import "WCFacadeExt.h"
#import "WCStoryFacadeExt.h"
#import "WCStoryPreivewPageCollectionControllerDelegate.h"
#import "WCStoryPreviewPageViewDelegate.h"

@class MMUIButton, NSString, WCStoryPageControl, WCStoryPreivewPageCollectionController, WCStoryPreviewReportObj;

@interface WCStorysPreviewViewController : WCDragToCloseViewController <UIViewControllerTransitioningDelegate, WCStoryPreivewPageCollectionControllerDelegate, WCStoryPreviewPageViewDelegate, WCFacadeExt, WCStoryFacadeExt, IExtraDeviceLoginMgrExt>
{
    WCStoryPreivewPageCollectionController *m_collectionController;
    WCStoryPageControl *pageControl;
    MMUIButton *m_closeBtn;
    _Bool _disableResumeMusic;
    _Bool _hidePageControl;
    _Bool _canDeleteMyOwnStory;
    _Bool _scrollEnabled;
    id <WCStorysPreviewViewControllerDelegate> _delegate;
    WCStoryPreviewReportObj *_previewReportObj;
    unsigned long long _statusChangePreviewType;
    MMUIButton *_moreActionBtn;
    struct CGRect _originFrame;
}

@property(nonatomic) __weak MMUIButton *moreActionBtn; // @synthesize moreActionBtn=_moreActionBtn;
@property(nonatomic) unsigned long long statusChangePreviewType; // @synthesize statusChangePreviewType=_statusChangePreviewType;
@property(retain, nonatomic) WCStoryPreviewReportObj *previewReportObj; // @synthesize previewReportObj=_previewReportObj;
@property(nonatomic) __weak id <WCStorysPreviewViewControllerDelegate> delegate; // @synthesize delegate=_delegate;
@property(nonatomic) _Bool scrollEnabled; // @synthesize scrollEnabled=_scrollEnabled;
@property(nonatomic) _Bool canDeleteMyOwnStory; // @synthesize canDeleteMyOwnStory=_canDeleteMyOwnStory;
@property(nonatomic) _Bool hidePageControl; // @synthesize hidePageControl=_hidePageControl;
@property(nonatomic) _Bool disableResumeMusic; // @synthesize disableResumeMusic=_disableResumeMusic;
@property(nonatomic) struct CGRect originFrame; // @synthesize originFrame=_originFrame;
- (void).cxx_destruct;
- (void)onExtraDeviceLoginClose;
- (void)onCommentListView:(id)arg1 show:(_Bool)arg2;
- (void)onClickPageView:(id)arg1 toHideUIElement:(_Bool)arg2;
- (void)onLongPressToDeletePageView:(id)arg1;
- (void)onStoryPageCollectionControllerChangePage:(id)arg1 pageView:(id)arg2 lastIndexPath:(id)arg3;
- (void)onNetworkActivityStatusChanged;
- (void)willShow;
- (void)updateNetworkStatus;
- (id)getPreloadMediaItems;
- (void)reportChangeFeaturedOrHiddenStatusWithTid:(id)arg1 videoType:(unsigned long long)arg2;
- (void)onLongPressToHidePageView:(id)arg1;
- (void)onReverseDataItemPrivateWithTid:(id)arg1 isInvisible:(_Bool)arg2;
- (id)updateItemOfDataUnitWithTid:(id)arg1;
- (void)onStoryDeleteSuccessWithDataTid:(id)arg1;
- (void)onUserRelatedCommentReadWithTid:(id)arg1;
- (void)onDataItemAllCommentMakeRead:(id)arg1;
- (void)onGetStoryComentDelete:(id)arg1;
- (void)onGetStoryUnReadComment:(id)arg1;
- (void)clickMoreAction;
- (void)hideSelf;
- (void)pageAction;
- (void)dragUPGestureReceived:(id)arg1;
- (void)markCommentRead:(unsigned long long)arg1;
- (void)reloadPageControl;
- (void)initTopButton;
- (void)initCollectionView;
- (void)initCollectionController;
- (void)tryToShowCommentList;
- (void)voiceOverElementEnable:(_Bool)arg1;
- (void)onFullScreenItemDragEnd;
- (void)onFullScreenItemDragBegin;
- (void)onFullScreenItemDragToClose;
- (void)hideVCAnimation;
- (void)reloadWithDataUnit:(id)arg1;
- (void)reloadWithDataItems:(id)arg1;
- (void)reportExitPreview;
- (void)markUserStoryHasRead:(id)arg1 lastIndexPath:(id)arg2;
- (void)scrollToIndex:(unsigned long long)arg1;
- (void)jumpToFirstUnreadCommentPage;
- (void)pause;
- (void)playInMute:(_Bool)arg1;
- (unsigned long long)dataItemCount;
- (_Bool)useTransparentNavibar;
- (void)didAppear;
- (void)willDisshow;
- (void)didDisshow;
- (void)willDisappear;
- (void)viewDidBePoped:(_Bool)arg1;
- (void)viewDidDisappear:(_Bool)arg1;
- (void)viewDidAppear:(_Bool)arg1;
- (void)willAppear;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewWillAppear:(_Bool)arg1;
- (void)viewDidTransitionToNewSize;
- (void)viewDidLoad;
- (_Bool)useBlackStatusbar;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

