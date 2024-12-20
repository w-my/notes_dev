//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "TVKNetworkCheckerDelegate.h"

@class NSObject<OS_dispatch_queue>, NSString, TVKATSHTTPRequest;

@interface TVKHLSKeyUtil : NSObject <TVKNetworkCheckerDelegate>
{
    NSObject<OS_dispatch_queue> *_tokenForCKeyQueue;
    _Bool _isDownload;
    _Bool _isRender;
    _Bool _shouldMatchWhenNetworkAvailable;
    NSString *_videoIDForCKey;
    NSString *_previd;
    NSString *_fdForCKey;
    double _timeSeverSystem;
    double _timeSendRequest;
    long long _retryCount;
    NSString *_validTokenForCKey;
    TVKATSHTTPRequest *_httpRequest;
    NSString *_randFlag;
}

+ (id)sharedInstance;
@property(retain) NSString *randFlag; // @synthesize randFlag=_randFlag;
@property(retain, nonatomic) TVKATSHTTPRequest *httpRequest; // @synthesize httpRequest=_httpRequest;
@property(retain) NSString *validTokenForCKey; // @synthesize validTokenForCKey=_validTokenForCKey;
@property _Bool shouldMatchWhenNetworkAvailable; // @synthesize shouldMatchWhenNetworkAvailable=_shouldMatchWhenNetworkAvailable;
@property long long retryCount; // @synthesize retryCount=_retryCount;
@property double timeSendRequest; // @synthesize timeSendRequest=_timeSendRequest;
@property double timeSeverSystem; // @synthesize timeSeverSystem=_timeSeverSystem;
@property(nonatomic) _Bool isRender; // @synthesize isRender=_isRender;
@property(nonatomic) _Bool isDownload; // @synthesize isDownload=_isDownload;
@property(retain, nonatomic) NSString *fdForCKey; // @synthesize fdForCKey=_fdForCKey;
@property(retain, nonatomic) NSString *previd; // @synthesize previd=_previd;
@property(retain, nonatomic) NSString *videoIDForCKey; // @synthesize videoIDForCKey=_videoIDForCKey;
- (id)previdMD5;
- (void)updateTokenNotify;
- (void)retryMatching;
- (void)sendMatchingRequest;
- (void)matchingSystemTimeAfterDelay:(double)arg1;
- (void)updateTokenForCKey;
- (id)getTokenForCKey;
- (void)onGetRandFlag:(id)arg1;
- (void)onGetCurrentServerTime:(double)arg1;
- (id)createCKeyUrl;
- (id)createCKey;
- (double)getCurrentSystemTimeInterval;
- (id)getCurrentSystemTime;
- (id)getEncryptVersion;
- (id)getPrivateKey;
- (id)getAppVersion;
- (id)getPlatform;
- (id)getSdtfrom;
- (id)getMagicNum;
- (void)appEnterForeground;
- (void)reachabilityChanged;
- (id)init;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

