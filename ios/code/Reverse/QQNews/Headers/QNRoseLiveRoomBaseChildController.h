//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNScrollViewDelegateRelayViewController.h"

#import "QNImageBrowserDelegate.h"
#import "QNRoseLiveRoomCellDelegate.h"
#import "UIActionSheetDelegate.h"

@class NSArray, NSString, QNNativeWidgetCache, QNRoseLiveRoomFragmentContext, QNRoseLiveRoomMessageTipsView, QNRoseLiveRoomNode, UITableView;

@interface QNRoseLiveRoomBaseChildController : QNScrollViewDelegateRelayViewController <QNImageBrowserDelegate, UIActionSheetDelegate, QNRoseLiveRoomCellDelegate>
{
    UITableView *_tableView;
    _Bool _shouldDisplayFakeMessage;
    QNNativeWidgetCache *_widgetCache;
    QNRoseLiveRoomFragmentContext *_context;
    QNRoseLiveRoomMessageTipsView *_tipsView;
    NSArray *_photoBrowserItems;
    QNRoseLiveRoomNode *_replyedNode;
}

@property(retain, nonatomic) QNRoseLiveRoomNode *replyedNode; // @synthesize replyedNode=_replyedNode;
@property(retain, nonatomic) NSArray *photoBrowserItems; // @synthesize photoBrowserItems=_photoBrowserItems;
@property(retain, nonatomic) QNRoseLiveRoomMessageTipsView *tipsView; // @synthesize tipsView=_tipsView;
@property(retain, nonatomic) QNRoseLiveRoomFragmentContext *context; // @synthesize context=_context;
@property(nonatomic) _Bool shouldDisplayFakeMessage; // @synthesize shouldDisplayFakeMessage=_shouldDisplayFakeMessage;
@property(retain, nonatomic) UITableView *tableView; // @synthesize tableView=_tableView;
@property(readonly, nonatomic) QNNativeWidgetCache *widgetCache; // @synthesize widgetCache=_widgetCache;
- (void).cxx_destruct;
- (id)viewModel;
- (void)hideTipsAnimated:(_Bool)arg1;
- (void)showTipsAnimated:(_Bool)arg1;
- (void)do_presentCommentActivity:(id)arg1;
- (void)actionSheet:(id)arg1 clickedButtonAtIndex:(long long)arg2;
- (id)fragmentViewContext;
- (_Bool)isCurrentViewControllerSelected;
- (double)_fakeMessageCellTotalHeight;
- (void)reloadContentScrollViewData;
- (void)reloadFakeMessageWithoutContentMove;
- (id)contentScrollView;
- (void)do_selectedAsCurrentChannel:(id)arg1;
@property(readonly, copy) NSString *description;
- (void)scrollViewDidScroll:(id)arg1;
- (struct CGRect)imageBrowserWillDismissAtImageItem:(id)arg1;
- (void)resendMessage:(id)arg1;
- (void)hideMenuView;
- (void)fullScreenLayoutRoseLiveSingleImage:(id)arg1 imageView:(id)arg2;
- (void)fullScreenLayoutRoseLiveImage:(id)arg1 imageView:(id)arg2;
- (id)currentQNNavigationController;
- (id)serverDeliveredResources;
- (id)shareWidgetCache;
- (void)performMenuAction:(SEL)arg1 item:(id)arg2;
- (_Bool)canPerformMenuAction:(SEL)arg1 item:(id)arg2;
- (void)reloadAllVisibleRoseLiveRoomCells;
- (void)reloadVisibleRoseLiveRoomCell:(id)arg1;
- (void)updateCommentViews:(id)arg1;
- (_Bool)shouldUpdateCommentViews:(id)arg1;
- (void)clearCachedLayoutMetricsForMessage:(id)arg1;
- (id)roseLiveRoomController;
- (_Bool)supportAudioPlay;
- (_Bool)supportAttachMiniPlayerView;
- (void)dealloc;
- (void)viewDidLoad;
- (id)initWithParam:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

