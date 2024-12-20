//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "MMKJSEvent.h"

@class JSEvent, NSString, WAJSEventHandler_BaseEvent;

@interface KindaJSEvent : NSObject <MMKJSEvent>
{
    WAJSEventHandler_BaseEvent *_tinyAppEvent;
    JSEvent *_webEvent;
}

@property(retain, nonatomic) JSEvent *webEvent; // @synthesize webEvent=_webEvent;
@property(retain, nonatomic) WAJSEventHandler_BaseEvent *tinyAppEvent; // @synthesize tinyAppEvent=_tinyAppEvent;
- (void).cxx_destruct;
- (long long)kindaGetType;
- (void)kindaEndWithResult:(id)arg1 extraInfo:(id)arg2;
- (void)kindaCloseWebViewImpl:(_Bool)arg1 completion:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

