//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WebviewJSEventHandlerBase.h"

@interface WebviewJSEventHandler_handleMPPageAction : WebviewJSEventHandlerBase
{
}

- (void)childMode_onSetWebviewBackground:(id)arg1 MPActionEvent:(id)arg2;
- (void)childMode_onSwitchVideo:(id)arg1 MPActionEvent:(id)arg2;
- (void)childMode_onGetMPVideoState:(id)arg1 MPActionEvent:(id)arg2;
- (void)childMode_onSendMPPageData:(id)arg1 MPActionEvent:(id)arg2;
- (void)childMode_onAdWebviewReady:(id)arg1 MPActionEvent:(id)arg2;
- (void)childMode_onCloseAdWebView:(id)arg1 MPActionEvent:(id)arg2;
- (void)childMode_onCreateAdWebView:(id)arg1 MPActionEvent:(id)arg2;
- (void)chideMode_onWriteComment:(id)arg1 MPActionEvent:(id)arg2;
- (void)onGetFuncFlag:(id)arg1 MPActionEvent:(id)arg2;
- (void)childMode_onGetFuncFlag:(id)arg1 MPActionEvent:(id)arg2;
- (void)onShare:(id)arg1 MPActionEvent:(id)arg2;
- (void)childMode_onShare:(id)arg1 MPActionEvent:(id)arg2;
- (void)onShowToast:(id)arg1 MPActionEvent:(id)arg2;
- (id)mpPageActionInstance;
- (void)doAction:(id)arg1 paramters:(id)arg2 event:(id)arg3;
- (void)childMode_doAction:(id)arg1 paramters:(id)arg2 event:(id)arg3;
- (void)handleJSEvent:(id)arg1 HandlerFacade:(id)arg2 ExtraData:(id)arg3;

@end

