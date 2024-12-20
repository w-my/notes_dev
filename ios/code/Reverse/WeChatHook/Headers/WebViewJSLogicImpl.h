//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "JSEventHandler.h"
#import "WebviewJSEventHandlerBaseDelegate.h"

@class NSMutableArray, NSMutableDictionary, NSString, UIView<YYWebViewInterface>, WebviewJSEventHandlerFacade;

@interface WebViewJSLogicImpl : MMObject <JSEventHandler, WebviewJSEventHandlerBaseDelegate>
{
    NSMutableDictionary *_jsCallbackHooks;
    NSMutableDictionary *_jsUrlHooks;
    NSMutableArray *_jsEvents;
    WebviewJSEventHandlerFacade *_jsEventHandlerFacade;
    UIView<YYWebViewInterface> *_webView;
    id <WebViewJSLogicDelegate> _delegate;
    NSString *_curRandomUUID;
    NSString *_curContextUUID;
    _Bool _isUseMd5ForJSAPI;
    _Bool _canPreinject;
    _Bool _bInjectJSFailed;
}

@property(nonatomic) _Bool bInjectJSFailed; // @synthesize bInjectJSFailed=_bInjectJSFailed;
@property(retain, nonatomic) UIView<YYWebViewInterface> *webView; // @synthesize webView=_webView;
@property(nonatomic) __weak id <WebViewJSLogicDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)reportIDKeyForJsApiCall:(id)arg1;
- (void)reportIDKeyForInjectJS;
- (id)sha1:(id)arg1;
- (void)sendEventToJSBridge:(id)arg1 params:(id)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)sendMessageToJSBridge:(id)arg1 completionBlock:(CDUnknownBlockType)arg2;
- (void)injectWeixinJSBridge;
- (void)sendGetA8KeyUrlOrCookieEvent:(id)arg1 HasCookie:(_Bool)arg2;
- (void)markPageWebCached;
- (id)getWeixinJSBridgeAndPluginStr;
- (id)genPreinjectWxjsByScript:(id)arg1;
- (void)sysInitDocument:(id)arg1;
- (void)resetSysInitMarkIfNeeded;
- (void)tryInjectWeixinJSBridge:(id)arg1;
- (id)isExistJSApis:(id)arg1;
- (id)webviewController;
- (id)GetCurrentWebviewViewController;
- (void)jsHandlerHandle:(id)arg1;
- (void)onEndEvent:(id)arg1 withResult:(id)arg2;
- (id)wxShareCSK;
- (void)wxShareFunCall:(id)arg1 params:(id)arg2 withCallbackID:(id)arg3;
- (void)setJSAPIFunctionMap:(id)arg1;
- (id)funcDefByName:(id)arg1;
- (void)webviewWillAnimateRotationToInterfaceOrientation:(long long)arg1 duration:(double)arg2;
- (id)extraDataForNextJSEventCalled:(id)arg1;
- (void)recoverJSAPIEventDelegateWithBackup;
- (void)cleanJSAPIDelegate;
- (void)handleMonitorMessage:(id)arg1;
- (void)handleJSApiDispatchMessage:(id)arg1;
- (void)functionCall:(id)arg1 withParams:(id)arg2 withCallbackID:(id)arg3;
- (id)jsEventWithFunction:(id)arg1 params:(id)arg2 callBackID:(id)arg3;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

