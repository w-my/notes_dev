//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSXMLParserDelegate.h"

@class NSString, QNAdviceApi;

@interface CSendAdvice : NSObject <NSXMLParserDelegate>
{
    _Bool _downloadError;
    QNAdviceApi *_adviceApi;
    id _object;
    SEL _errorHandler;
    SEL _completeHandler;
}

@property(nonatomic) SEL completeHandler; // @synthesize completeHandler=_completeHandler;
@property(nonatomic) SEL errorHandler; // @synthesize errorHandler=_errorHandler;
@property(nonatomic) __weak id object; // @synthesize object=_object;
@property(retain, nonatomic) QNAdviceApi *adviceApi; // @synthesize adviceApi=_adviceApi;
@property _Bool downloadError; // @synthesize downloadError=_downloadError;
- (void).cxx_destruct;
- (void)dealloc;
- (void)loadMultiDataStart:(id)arg1 postData:(id)arg2;
- (_Bool)isSending;
- (void)setHandler:(id)arg1 completeHandler:(SEL)arg2 errorHandler:(SEL)arg3;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
