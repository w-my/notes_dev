//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WAJSEventHandler_BaseEvent.h"

#import "WAAppConfirmWindowDelegate.h"
#import "WAWebViewPlugin_ApiQueueProtocol.h"

@class NSDictionary, NSString, WAAppConfirmWindow;

@interface WAJSEventHandler_requestAuthUserAutoFillData : WAJSEventHandler_BaseEvent <WAWebViewPlugin_ApiQueueProtocol, WAAppConfirmWindowDelegate>
{
    WAAppConfirmWindow *_confirmWindow;
    NSDictionary *_dicInputParam;
}

@property(retain) NSDictionary *dicInputParam; // @synthesize dicInputParam=_dicInputParam;
- (void).cxx_destruct;
- (void)onCgiResponse:(id)arg1 forEvent:(unsigned int)arg2;
- (void)handleApiEventEnd;
- (void)requestAutoFillAuthorize:(id)arg1 allow:(_Bool)arg2 authStatus:(unsigned int)arg3;
- (void)closeConfirmWindow;
- (void)onClickLink;
- (void)onConfirm:(_Bool)arg1;
- (void)onHandleApiEvent:(id)arg1;
- (void)dealloc;
- (void)handleJSEvent:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

