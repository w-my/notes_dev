//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "MMWebViewDelegate.h"

@class MMWebViewController, MPLandingCommonSharePageExtParams, NSString;

@interface MPLandingCommonSharePageLogic : NSObject <MMWebViewDelegate>
{
    _Bool _isWebviewFastLoad;
    _Bool _isBackAdWebViewControllerReady;
    unsigned int _itemShowType;
    id <MPLandingCommonSharePageLogicDelegate> _delegate;
    MMWebViewController *_commonShareWebViewVC;
    NSString *_originalUrl;
    NSString *_bizUserName;
    MMWebViewController *_backAdWebViewController;
    MPLandingCommonSharePageExtParams *_extParams;
}

@property(retain, nonatomic) MPLandingCommonSharePageExtParams *extParams; // @synthesize extParams=_extParams;
@property(nonatomic) _Bool isBackAdWebViewControllerReady; // @synthesize isBackAdWebViewControllerReady=_isBackAdWebViewControllerReady;
@property(retain, nonatomic) MMWebViewController *backAdWebViewController; // @synthesize backAdWebViewController=_backAdWebViewController;
@property(nonatomic) _Bool isWebviewFastLoad; // @synthesize isWebviewFastLoad=_isWebviewFastLoad;
@property(nonatomic) unsigned int itemShowType; // @synthesize itemShowType=_itemShowType;
@property(copy, nonatomic) NSString *bizUserName; // @synthesize bizUserName=_bizUserName;
@property(copy, nonatomic) NSString *originalUrl; // @synthesize originalUrl=_originalUrl;
@property(retain, nonatomic) MMWebViewController *commonShareWebViewVC; // @synthesize commonShareWebViewVC=_commonShareWebViewVC;
@property(nonatomic) __weak id <MPLandingCommonSharePageLogicDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)resetCommonSharePage;
- (id)currentMPVideoPlayerStateDictionary;
- (id)errorWithCode:(long long)arg1 description:(id)arg2;
- (_Bool)tryCreateAdViewWithUrlString:(id)arg1 error:(id *)arg2;
- (void)sendMPPageData:(id)arg1 toWebVC:(id)arg2;
- (id)webViewFailToLoad:(id)arg1 Error:(id)arg2;
- (void)onWebViewDidFinishLoad:(id)arg1;
- (void)onWebViewDidStartLoad:(id)arg1;
- (id)onGetShareFuncFlag;
- (id)onSetWebviewBackground:(id)arg1 webviewController:(id)arg2;
- (id)onWebViewPassParams:(id)arg1 Webview:(id)arg2;
- (void)sendGetFuncFlagEvent:(id)arg1;
- (void)sendMPAdViewStateChangedEvent:(long long)arg1;
- (void)sendMPPlayerStateChangeEvent:(id)arg1 vid:(id)arg2 errMsg:(id)arg3;
- (void)deleteCommentMsgWithPersonalCommentId:(unsigned int)arg1 openId:(id)arg2;
- (void)sendHaokanResult:(_Bool)arg1 commentContent:(id)arg2 scene:(long long)arg3;
- (_Bool)isAddedToGookLook;
- (_Bool)shouldShowGoodLookItem;
- (void)closeWowRecommendCommentEditView;
- (void)destoryCommentEditView;
- (void)closeCommentEditView;
- (_Bool)isShowMPWowRecommendCommentEditView;
- (_Bool)isShowMPCommentEditView;
- (id)commonShareWebScrollView;
- (id)commonShareWebView;
- (id)commonShareWebViewController;
- (_Bool)isCommonShareFastLoaded;
- (void)tryInitWebViewFromPreloadPool;
- (id)commonShareFullPageUrl;
- (void)clearCommonShareLogic;
- (_Bool)goToOriginalUrl:(id)arg1 bizUserName:(id)arg2 extParams:(id)arg3;
- (id)initWithDelegate:(id)arg1 originalUrl:(id)arg2 itemShowType:(unsigned int)arg3 bizUserName:(id)arg4 extParams:(id)arg5;
- (void)clearAdView;
- (_Bool)isAdViewReady;
- (id)adWebViewController;
- (void)createAdView:(id)arg1;

@end

