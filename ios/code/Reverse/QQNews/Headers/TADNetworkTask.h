//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSURLSessionTaskDelegate.h"

@class NSArray, NSData, NSDictionary, NSMutableDictionary, NSString, NSURLSessionTask, TADRequestTask;

@interface TADNetworkTask : NSObject <NSURLSessionTaskDelegate>
{
    _Bool _requestWithDelegate;
    _Bool _ignoreCache;
    NSString *_urlString;
    NSString *_requestID;
    double _timeout;
    long long _retryCount;
    long long _contentType;
    NSDictionary *_userInfo;
    NSData *_postData;
    NSArray *_cookie;
    long long _taskError;
    NSURLSessionTask *_sessionTask;
    TADRequestTask *_protocolTask;
    long long _failedCount;
    long long _tadState;
    NSMutableDictionary *_httpHeaderFields;
}

@property(retain, nonatomic) NSMutableDictionary *httpHeaderFields; // @synthesize httpHeaderFields=_httpHeaderFields;
@property(nonatomic) long long tadState; // @synthesize tadState=_tadState;
@property(nonatomic) long long failedCount; // @synthesize failedCount=_failedCount;
@property(retain) TADRequestTask *protocolTask; // @synthesize protocolTask=_protocolTask;
@property(retain) NSURLSessionTask *sessionTask; // @synthesize sessionTask=_sessionTask;
@property(nonatomic) long long taskError; // @synthesize taskError=_taskError;
@property(retain, nonatomic) NSArray *cookie; // @synthesize cookie=_cookie;
@property(retain, nonatomic) NSData *postData; // @synthesize postData=_postData;
@property(retain, nonatomic) NSDictionary *userInfo; // @synthesize userInfo=_userInfo;
@property(nonatomic) long long contentType; // @synthesize contentType=_contentType;
@property(nonatomic) _Bool ignoreCache; // @synthesize ignoreCache=_ignoreCache;
@property(nonatomic) long long retryCount; // @synthesize retryCount=_retryCount;
@property(nonatomic) double timeout; // @synthesize timeout=_timeout;
@property(nonatomic) _Bool requestWithDelegate; // @synthesize requestWithDelegate=_requestWithDelegate;
@property(retain, nonatomic) NSString *requestID; // @synthesize requestID=_requestID;
@property(retain, nonatomic) NSString *urlString; // @synthesize urlString=_urlString;
- (void).cxx_destruct;
- (void)fillHttpHeaderForJSONData;
- (void)setValue:(id)arg1 forHTTPHeaderField:(id)arg2;
- (void)cancel;
- (id)initWithURL:(id)arg1 JSONData:(id)arg2;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

