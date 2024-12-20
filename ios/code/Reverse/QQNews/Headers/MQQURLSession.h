//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSURLSessionDataDelegate.h"
#import "NSURLSessionDelegate.h"
#import "NSURLSessionDownloadDelegate.h"
#import "NSURLSessionTaskDelegate.h"

@class NSLock, NSMutableArray, NSString, NSURLSession, NSURLSessionConfiguration;

@interface MQQURLSession : NSObject <NSURLSessionDelegate, NSURLSessionTaskDelegate, NSURLSessionDataDelegate, NSURLSessionDownloadDelegate>
{
    _Bool _unavailable;
    NSLock *_requestLock;
    NSMutableArray *_requestArray;
    NSURLSession *_session;
    CDUnknownBlockType _backgroundURLSessionCompletionHandler;
}

+ (id)unavailableSession;
+ (id)sessionWithConfiguration:(id)arg1;
+ (id)sharedSession;
+ (_Bool)supportsNSURLSession;
@property(copy, nonatomic) CDUnknownBlockType backgroundURLSessionCompletionHandler; // @synthesize backgroundURLSessionCompletionHandler=_backgroundURLSessionCompletionHandler;
@property(readonly, copy, nonatomic) NSURLSession *session; // @synthesize session=_session;
- (void)URLSession:(id)arg1 downloadTask:(id)arg2 didResumeAtOffset:(long long)arg3 expectedTotalBytes:(long long)arg4;
- (void)URLSession:(id)arg1 downloadTask:(id)arg2 didWriteData:(long long)arg3 totalBytesWritten:(long long)arg4 totalBytesExpectedToWrite:(long long)arg5;
- (void)URLSession:(id)arg1 downloadTask:(id)arg2 didFinishDownloadingToURL:(id)arg3;
- (void)URLSession:(id)arg1 dataTask:(id)arg2 didReceiveData:(id)arg3;
- (void)URLSession:(id)arg1 dataTask:(id)arg2 didReceiveResponse:(id)arg3 completionHandler:(CDUnknownBlockType)arg4;
- (void)URLSession:(id)arg1 task:(id)arg2 willPerformHTTPRedirection:(id)arg3 newRequest:(id)arg4 completionHandler:(CDUnknownBlockType)arg5;
- (void)URLSession:(id)arg1 task:(id)arg2 didCompleteWithError:(id)arg3;
- (void)URLSessionDidFinishEventsForBackgroundURLSession:(id)arg1;
- (void)invalidateAndCancel;
- (id)requestFromSessionTask:(id)arg1;
- (void)requestDidStop:(id)arg1;
- (id)requestWithURL:(id)arg1;
@property(readonly, copy, nonatomic) NSURLSessionConfiguration *configuration;
- (void)dealloc;
- (id)initUnavailableSession;
- (id)initWithConfiguration:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

