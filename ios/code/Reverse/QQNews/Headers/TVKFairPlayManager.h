//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class AVAssetResourceLoadingRequest, TVKATSHTTPRequest, TVKMediaPlayInfo;

@interface TVKFairPlayManager : NSObject
{
    int _retryTime;
    AVAssetResourceLoadingRequest *_loadingRequest;
    TVKATSHTTPRequest *_httpRequest;
    TVKMediaPlayInfo *_mediaPlayInfo;
}

@property(nonatomic) int retryTime; // @synthesize retryTime=_retryTime;
@property(retain, nonatomic) TVKMediaPlayInfo *mediaPlayInfo; // @synthesize mediaPlayInfo=_mediaPlayInfo;
@property(retain, nonatomic) TVKATSHTTPRequest *httpRequest; // @synthesize httpRequest=_httpRequest;
@property(retain, nonatomic) AVAssetResourceLoadingRequest *loadingRequest; // @synthesize loadingRequest=_loadingRequest;
- (void).cxx_destruct;
- (void)dealloc;
- (void)cancelRequset;
- (void)requestDidFinishWithData:(id)arg1 andError:(id)arg2;
- (void)requestContentKeyFromKeySecurityModuleWithSPCData:(id)arg1 andAssetID:(id)arg2;
- (id)requestApplicationCertificate;
- (void)startRequestCKCWithRequest:(id)arg1;
- (id)initWithMediaPlayInfo:(id)arg1;

@end
