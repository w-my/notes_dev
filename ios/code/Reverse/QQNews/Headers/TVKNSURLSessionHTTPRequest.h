//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TVKHTTPRequest.h"

#import "NSURLSessionDataDelegate.h"

@class NSString, NSURLSession, NSURLSessionDataTask;

@interface TVKNSURLSessionHTTPRequest : TVKHTTPRequest <NSURLSessionDataDelegate>
{
    NSURLSessionDataTask *_task;
    NSURLSession *_session;
}

@property(retain, nonatomic) NSURLSession *session; // @synthesize session=_session;
@property __weak NSURLSessionDataTask *task; // @synthesize task=_task;
- (void).cxx_destruct;
- (void)URLSession:(id)arg1 task:(id)arg2 didCompleteWithError:(id)arg3;
- (void)URLSession:(id)arg1 dataTask:(id)arg2 didReceiveData:(id)arg3;
- (void)URLSession:(id)arg1 dataTask:(id)arg2 didReceiveResponse:(id)arg3 completionHandler:(CDUnknownBlockType)arg4;
- (void)finishTasksAndInvalidate;
- (void)cancelRequest;
- (void)postRequest:(id)arg1 requestHeaders:(id)arg2 postData:(id)arg3 timeoutInterval:(double)arg4;
- (void)getRequest:(id)arg1 requestHeaders:(id)arg2 timeoutInterval:(double)arg3;
- (void)dealloc;
@property(readonly, copy) NSString *description;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
