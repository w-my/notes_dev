//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "IFunctionMsgExt.h"
#import "MMKernelExt.h"
#import "MMService.h"
#import "PBMessageObserverDelegate.h"
#import "WSLocalWebViewControllerDelegate.h"

@class MMTimer, NSMutableArray, NSMutableDictionary, NSString, WSLocalWebViewController, WSRecommendColikeStorage, WSRecommendColikeTempModel, WSRecommendHomePageStat, WSRecommendSetting;

@interface WSRecommendMgr : MMService <WSLocalWebViewControllerDelegate, IFunctionMsgExt, MMKernelExt, PBMessageObserverDelegate, MMService>
{
    _Bool _isVisitingWebPage;
    _Bool _isAuthOK;
    _Bool _isRequestingOpenIdForOpenProfile;
    _Bool _hasRetryGetColikeBlockList;
    _Bool _hasRetryGetColikeHideList;
    _Bool _isRequestingGetColikeBlockList;
    _Bool _isRequestingGetColikeHideList;
    WSLocalWebViewController *_sharedPage;
    WSRecommendSetting *_setting;
    WSRecommendHomePageStat *_homePageStat;
    MMTimer *_timer;
    NSMutableDictionary *_dicWrdCache;
    NSMutableArray *_colikeHideList;
    NSMutableArray *_colikeBlockList;
    NSMutableArray *_colikeRequestList;
    NSMutableArray *_colikeSucList;
    NSMutableArray *_colikeFailList;
    NSMutableDictionary *_tempSaveDic;
    NSMutableDictionary *_tempVideoCacheTimeDic;
    WSRecommendColikeStorage *_colikeLocalStorage;
    WSRecommendColikeTempModel *_colikeHideTempModel;
    WSRecommendColikeTempModel *_colikeBlockTempModel;
}

+ (_Bool)IsSupportTopStoryPlugin;
@property(nonatomic) _Bool isRequestingGetColikeHideList; // @synthesize isRequestingGetColikeHideList=_isRequestingGetColikeHideList;
@property(nonatomic) _Bool isRequestingGetColikeBlockList; // @synthesize isRequestingGetColikeBlockList=_isRequestingGetColikeBlockList;
@property(nonatomic) _Bool hasRetryGetColikeHideList; // @synthesize hasRetryGetColikeHideList=_hasRetryGetColikeHideList;
@property(nonatomic) _Bool hasRetryGetColikeBlockList; // @synthesize hasRetryGetColikeBlockList=_hasRetryGetColikeBlockList;
@property(retain, nonatomic) WSRecommendColikeTempModel *colikeBlockTempModel; // @synthesize colikeBlockTempModel=_colikeBlockTempModel;
@property(retain, nonatomic) WSRecommendColikeTempModel *colikeHideTempModel; // @synthesize colikeHideTempModel=_colikeHideTempModel;
@property(retain, nonatomic) WSRecommendColikeStorage *colikeLocalStorage; // @synthesize colikeLocalStorage=_colikeLocalStorage;
@property(retain, nonatomic) NSMutableDictionary *tempVideoCacheTimeDic; // @synthesize tempVideoCacheTimeDic=_tempVideoCacheTimeDic;
@property(retain, nonatomic) NSMutableDictionary *tempSaveDic; // @synthesize tempSaveDic=_tempSaveDic;
@property(retain, nonatomic) NSMutableArray *colikeFailList; // @synthesize colikeFailList=_colikeFailList;
@property(retain, nonatomic) NSMutableArray *colikeSucList; // @synthesize colikeSucList=_colikeSucList;
@property(retain, nonatomic) NSMutableArray *colikeRequestList; // @synthesize colikeRequestList=_colikeRequestList;
@property(retain, nonatomic) NSMutableArray *colikeBlockList; // @synthesize colikeBlockList=_colikeBlockList;
@property(retain, nonatomic) NSMutableArray *colikeHideList; // @synthesize colikeHideList=_colikeHideList;
@property(nonatomic) _Bool isRequestingOpenIdForOpenProfile; // @synthesize isRequestingOpenIdForOpenProfile=_isRequestingOpenIdForOpenProfile;
@property(nonatomic) _Bool isAuthOK; // @synthesize isAuthOK=_isAuthOK;
@property(retain, nonatomic) NSMutableDictionary *dicWrdCache; // @synthesize dicWrdCache=_dicWrdCache;
@property(nonatomic) _Bool isVisitingWebPage; // @synthesize isVisitingWebPage=_isVisitingWebPage;
@property(retain, nonatomic) MMTimer *timer; // @synthesize timer=_timer;
@property(readonly, nonatomic) WSRecommendHomePageStat *homePageStat; // @synthesize homePageStat=_homePageStat;
@property(readonly, nonatomic) WSRecommendSetting *setting; // @synthesize setting=_setting;
@property(retain, nonatomic) WSLocalWebViewController *sharedPage; // @synthesize sharedPage=_sharedPage;
- (void).cxx_destruct;
- (void)handleColikePostCGI:(id)arg1;
- (void)handleSetCommentCGI:(id)arg1;
- (void)handlePostCommentCGI:(id)arg1;
- (void)outsideModLocalColikeDataWithType:(unsigned int)arg1 list:(id)arg2;
- (_Bool)isFirstTimeGetColikeListWithType:(unsigned int)arg1;
- (id)outsideGetWowBlockList;
- (id)outsideGetWowHideList;
- (void)handleColikeBlockCGI:(id)arg1;
- (void)mergeHideList;
- (void)mergeBlockList;
- (void)handleGetColikeHideListResp:(id)arg1 oriRequest:(id)arg2;
- (void)handleGetColikeBlockListResp:(id)arg1 oriRequest:(id)arg2;
- (void)handleGetColikeListCGI:(id)arg1;
- (void)gotoProfilePageWithUserName:(id)arg1;
- (void)webRecommendGetUserNameCgiResult:(id)arg1;
- (void)handleGetUserAttrByOpenIdCgi:(id)arg1;
- (void)MessageReturn:(id)arg1 Event:(unsigned int)arg2;
- (void)asyncRequestOpenIdToUsername:(id)arg1;
- (void)asyncRequestPostColikeToWow:(id)arg1 objectBuffer:(id)arg2 appInfo:(id)arg3;
- (id)devideAsyncColikeWithActionItems:(id)arg1;
- (void)asyncColikeWithActionItems:(id)arg1;
- (void)asyncStepGetWowBlackFriendListWith:(int)arg1 offset:(unsigned int)arg2 version:(unsigned long long)arg3;
- (void)onGetColikeListDataReturn:(_Bool)arg1 type:(unsigned int)arg2 list:(id)arg3;
- (void)asyncGetWowBlackFriendListWith:(int)arg1;
- (void)asyncGetWowBlockList;
- (void)asyncGetWowHideList;
- (void)asyncSetCommentWithDocId:(id)arg1 commentId:(id)arg2 opType:(unsigned int)arg3 requestId:(id)arg4 content:(id)arg5 scene:(unsigned int)arg6 subScene:(unsigned int)arg7 searchId:(id)arg8 vid:(id)arg9 byPass:(id)arg10 source:(unsigned int)arg11;
- (void)asyncPostCommentWithContent:(id)arg1 toDoc:(id)arg2 withReplyId:(id)arg3 subReplyId:(id)arg4 docUrl:(id)arg5 requestId:(id)arg6 title:(id)arg7 searchId:(id)arg8 scene:(unsigned int)arg9 subScene:(unsigned int)arg10 byPass:(id)arg11 source:(unsigned int)arg12;
- (_Bool)resetVideoGoodLookTipEducateToastFlag;
- (_Bool)confirmVideoGoodLookTipEducateToastFlag;
- (_Bool)resetVideoGoodLookEducateAlertFlag;
- (_Bool)confirmVideoGoodLookEducateAlertFlag;
- (_Bool)confirmFullDragTips;
- (_Bool)updateWSCacheByAddFilterId:(id)arg1 category:(unsigned int)arg2;
- (_Bool)removeFirstPageCacheForCategory:(unsigned int)arg1;
- (void)updateFirstPageCache:(id)arg1 directShowInterval:(unsigned int)arg2 autoRefreshInterval:(unsigned int)arg3 category:(unsigned int)arg4 docList:(id)arg5;
- (id)getValidFirstPageCacheForCategory:(unsigned int)arg1;
- (id)getValidMainTimeLineFirstPageCache;
- (_Bool)isSupportFirstPageCache;
- (_Bool)isFFWebRecommendOpenForGlobalSearch;
- (_Bool)isFFWebRecommendOpen;
- (void)logCacheInfo;
- (void)checkReportWebSearchTemplateVersion;
- (void)checkReportTopStoryTemplateVersion;
- (int)getHitTypeWhenEnterWithVCType:(int)arg1;
- (void)reportPreviewWebviewAction:(id)arg1;
- (void)onForbidCacheWSLocalWebView;
- (void)onWSLocalWebViewReturn:(id)arg1 cache:(_Bool)arg2;
- (_Bool)isPluginNotify;
- (_Bool)isPluginInstall;
- (void)onFunctionMsgResponse:(id)arg1 bussinessId:(id)arg2 functionMsgId:(id)arg3;
- (void)onFunctionMsgRequest:(id)arg1 bussinessId:(id)arg2 functionMsgId:(id)arg3;
- (id)generatePluginMsgRequestBuffer:(id)arg1;
- (_Bool)preloadSharedPageWebViewIfNeeded:(int)arg1;
- (void)onCloseSharedPageForTimeout;
- (void)beginLimitCacheSharePage;
- (void)unregisterSharedPage;
- (void)registerSharedPage:(id)arg1;
- (id)generatePushingSharedPage:(int)arg1 reddotId:(id)arg2 useLocalCache:(_Bool *)arg3 useParallel:(_Bool *)arg4;
- (id)generatePushingSharedPage:(int)arg1 useParallel:(_Bool *)arg2;
- (id)generateBaseSharedPage:(int)arg1;
- (void)cleanService;
- (void)onAuthOK;
- (unsigned int)outsideGetVideoCacheTimeFor:(id)arg1;
- (void)outsideSetVideoCacheTime:(unsigned int)arg1 forKey:(id)arg2;
- (id)outsideGetStringforKey:(id)arg1;
- (void)outsideSetString:(id)arg1 forKey:(id)arg2;
- (_Bool)saveSetting;
- (void)loadColikeCache;
- (_Bool)saveCache;
- (void)loadCache;
- (id)filePath;
- (id)settingPath;
- (id)fileDir;
- (void)onServiceClearData;
- (void)onServiceReloadData;
- (void)onServiceInit;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

