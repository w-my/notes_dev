//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "FTSJSEventDelegate.h"
#import "WAWebSearchMgrDelegate.h"
#import "WCCanvasDynamicDataLoaderDelegate.h"
#import "WCCommentDetailViewControllerFBDelegate.h"
#import "WSActionSheetDelegate.h"
#import "WSMusicDelegate.h"

@class FTSWebSearchMgr, MMLoadingView, MMUIViewController, NSDictionary, NSString, WAWebSearchMgr, WCCanvasDynamicDataLoader, WSActionSheet;

@interface WSJSEventHandler : NSObject <WCCommentDetailViewControllerFBDelegate, WSMusicDelegate, WSActionSheetDelegate, WCCanvasDynamicDataLoaderDelegate, WAWebSearchMgrDelegate, FTSJSEventDelegate>
{
    MMUIViewController *_baseViewController;
    id <WSJSEventHandleDelegate> _delegate;
    FTSWebSearchMgr *_webSearchMgr;
    WSActionSheet *_actionSheet;
    MMLoadingView *_loadingView;
    WAWebSearchMgr *_waSearchMgr;
    WCCanvasDynamicDataLoader *_dataLoader;
    NSDictionary *_userInfo;
}

@property(retain, nonatomic) NSDictionary *userInfo; // @synthesize userInfo=_userInfo;
@property(retain, nonatomic) WCCanvasDynamicDataLoader *dataLoader; // @synthesize dataLoader=_dataLoader;
@property(retain, nonatomic) WAWebSearchMgr *waSearchMgr; // @synthesize waSearchMgr=_waSearchMgr;
@property(retain, nonatomic) MMLoadingView *loadingView; // @synthesize loadingView=_loadingView;
@property(retain, nonatomic) WSActionSheet *actionSheet; // @synthesize actionSheet=_actionSheet;
@property(retain, nonatomic) FTSWebSearchMgr *webSearchMgr; // @synthesize webSearchMgr=_webSearchMgr;
@property(nonatomic) __weak id <WSJSEventHandleDelegate> delegate; // @synthesize delegate=_delegate;
@property(nonatomic) __weak MMUIViewController *baseViewController; // @synthesize baseViewController=_baseViewController;
- (void).cxx_destruct;
- (void)onSearchUxOplogDataReady:(id)arg1;
- (void)onWebSearchDataFail:(_Bool)arg1;
- (void)onWebSearchDataChanged:(_Bool)arg1 isFromFuncQuery:(_Bool)arg2;
- (void)startMusicPlayer:(id)arg1;
- (void)notifyPageOfMusicStatusChanged:(id)arg1;
- (void)onDeleteData;
- (void)onCanvasDynamicXMLReturn:(id)arg1 error:(int)arg2 forCanvasId:(id)arg3;
- (void)actionSheet:(id)arg1 clickedButtonAtIndex:(long long)arg2;
- (void)onGotoEmoticonPad:(id)arg1;
- (void)onQuerySimilarPicSearch:(id)arg1;
- (void)onPreloadSearchWeapp:(id)arg1;
- (void)onUpdateNumReddot:(id)arg1;
- (void)onFetchNumReddot:(id)arg1;
- (void)onPostComments:(id)arg1;
- (void)onSetComments:(id)arg1;
- (void)onHideSearchLoading:(id)arg1;
- (void)onShowSearchLoading:(id)arg1;
- (void)onShowSearchToast:(id)arg1;
- (void)onOpenWowColikeSetting:(id)arg1;
- (void)onOpenProfileWithOpenId:(id)arg1;
- (void)onHideNavBarShadow:(id)arg1;
- (void)onShowNavBarShadow:(id)arg1;
- (void)onQueryCommCgi:(id)arg1;
- (void)onFetchReddot:(id)arg1;
- (void)onOpenProfilePage:(id)arg1;
- (void)onWebViewRenderFinish:(id)arg1;
- (void)onOpenWebRecommend:(id)arg1;
- (void)onGoToRecVideoList:(id)arg1;
- (void)onWidgetClearCrashProtectCount:(id)arg1;
- (void)onOpenWAWidgetLogViewWithParams:(id)arg1;
- (void)onOpenSearchCanvas:(id)arg1;
- (void)onOpenADCanvasPage:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)onReportWeAppSearchRealTime:(id)arg1;
- (void)onTapWAWidgetWithParams:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (id)onDoSearchOpLog:(id)arg1;
- (void)onCancelSearchActionSheet:(id)arg1;
- (id)onShowSearchActionSheet:(id)arg1;
- (void)onUpdateWAWidgetWithParams:(id)arg1;
- (void)onRemoveWAWidgetWithParams:(id)arg1;
- (id)onInsertWAWidgetWithParams:(id)arg1;
- (id)onGetWidgetCaptureImgUrl:(id)arg1;
- (id)onGetBaseViewController;
- (void)onInsertHistoryOperation:(id)arg1;
- (void)onOperateVideoPlayerWithParams:(id)arg1;
- (void)onUpdateVideoPlayerWithParams:(id)arg1;
- (void)onRemoveVideoPlayerWithParams:(id)arg1;
- (id)onInsertVideoPlayerWithParams:(id)arg1;
- (void)onSearchHotWord:(id)arg1;
- (void)onSwitchSearchContext:(id)arg1;
- (void)onClearHistoryOperation:(id)arg1;
- (void)onOpenEmotionPage:(id)arg1;
- (void)onOpenWeAppPage:(id)arg1;
- (void)onRequestLocalSuggestion:(id)arg1;
- (void)onClickRecmdWord:(id)arg1;
- (void)onOpenContact:(id)arg1;
- (void)onOpenSnsDetail:(id)arg1;
- (void)onOpenMsgSession:(id)arg1;
- (void)onOpenBrandContact:(id)arg1 withParams:(id)arg2;
- (_Bool)openMPVideoLandingPageWithUrlStr:(id)arg1 dicParams:(id)arg2;
- (void)onLaunchPage:(id)arg1 withParams:(id)arg2;
- (void)onLaunchDetailPageForWeApp:(id)arg1;
- (id)onGetSearchHistory:(id)arg1;
- (void)onDeleteSearchHistory:(id)arg1;
- (void)onViewTypeChange:(id)arg1;
- (void)onMakePhoneCall:(id)arg1;
- (void)onLaunchDetailPage:(id)arg1;
- (void)onPreSearch:(id)arg1 bizType:(unsigned long long)arg2;
- (_Bool)viewControllerHasNavController;
- (void)onWebViewTerminal:(id)arg1;
- (void)onTryForbidCacheVcWhenWebviewCauseError:(id)arg1;
- (void)onJsbridgeReady:(id)arg1;
- (void)didFinishLoadWebView:(id)arg1;
- (void)onSearchInputChanged:(id)arg1;
- (void)onFailReceiveJson;
- (void)onUpdateReddotTimeStamps:(id)arg1;
- (void)onOpenSearchFromSearchWithScene:(id)arg1;
- (void)onOpenSearchAssistance:(id)arg1;
- (void)onOpenVisitHistory:(id)arg1;
- (void)onImagePreview:(id)arg1;
- (void)onOpenLocation:(id)arg1;
- (void)onReceiveJson:(id)arg1;
- (void)enableSearchBar;
- (void)hideKeyboard;
- (void)registerWSMusicHandler;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

