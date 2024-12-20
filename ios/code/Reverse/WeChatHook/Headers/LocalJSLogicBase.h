//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

@class NSMutableArray;

@interface LocalJSLogicBase : MMObject
{
    id <YYWebViewInterface> _webView;
    NSMutableArray *_authApiList;
}

- (void).cxx_destruct;
- (void)ackWithCallBackID:(id)arg1 errorMsg:(id)arg2;
- (void)ackWithCallBackID:(id)arg1 withParams:(id)arg2;
- (id)getNetworkInfo;
- (_Bool)isOnDawangEnv;
- (void)handleJSApiFuncOfGetNetworkType:(id)arg1 withCallBackID:(id)arg2;
- (void)functionCall:(id)arg1 withParams:(id)arg2 withCallbackID:(id)arg3;
- (void)reSetWebView:(id)arg1;
- (void)addAuthApiList:(id)arg1;
- (void)sendJSCBEventToJSBridge:(id)arg1 withCallBackID:(id)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)sendJSCBEventToJSBridge:(id)arg1 withCallBackID:(id)arg2;
- (void)handleJSApiDispatchMessage:(id)arg1;
- (void)sendEventToJSBridge:(id)arg1 params:(id)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)sendEventToJSBridge:(id)arg1 params:(id)arg2;
- (void)onJsEvaluateError:(id)arg1;
- (void)sendMessageToJSBridge:(id)arg1 completionBlock:(CDUnknownBlockType)arg2;
- (void)injectPluginJS;
- (void)injectWeixinJSBridge;
- (void)onSysBridgeCompleted;
- (void)tryInjectWeixinJSBridge:(id)arg1;
- (id)initWithWebView:(id)arg1;

@end

