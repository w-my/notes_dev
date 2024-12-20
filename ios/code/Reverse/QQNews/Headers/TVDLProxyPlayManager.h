//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface TVDLProxyPlayManager : NSObject
{
    id <TVDLProxyLogDelegate> _logDelegate;
    id <TVDLProxyReportDelegate> _reportDelegate;
}

+ (id)sharedInstance;
@property(nonatomic) __weak id <TVDLProxyReportDelegate> reportDelegate; // @synthesize reportDelegate=_reportDelegate;
@property(nonatomic) __weak id <TVDLProxyLogDelegate> logDelegate; // @synthesize logDelegate=_logDelegate;
- (void).cxx_destruct;
- (int)stopRequest:(int)arg1 withClipNo:(int)arg2 withRequestID:(int)arg3;
- (id)readRequestData:(int)arg1 withClipNo:(int)arg2 withRequestID:(int)arg3 withReadOffset:(long long)arg4;
- (id)getRequestContentType:(int)arg1 withClipNo:(int)arg2;
- (long long)getRequestFileSize:(int)arg1 withClipNo:(int)arg2;
- (int)createRequest:(int)arg1 withClipNo:(int)arg2 withRequestStart:(long long)arg3 withRequestEnd:(long long)arg4;
- (id)getRequestM3U8ForHLS:(int)arg1;
- (void)stopLivePlay:(int)arg1;
- (id)buildLivePlayUrl:(int)arg1;
- (int)startLivePlay:(id)arg1 withPlayID:(id)arg2 withUrls:(id)arg3 withType:(int)arg4 withVinfoJson:(id)arg5;
- (id)getOfflineLogoWithMD5:(id)arg1;
- (void)enableQuickPlay:(_Bool)arg1;
- (int)getAppCurrentSpeed;
- (int)getPlayCacheSizeKB:(id)arg1 withFormat:(id)arg2;
- (int)getPlayPropertyInfo:(int)arg1 withPropertyId:(int)arg2;
- (id)getPlayingInfo:(int)arg1;
- (id)getPlayErrorCodeStr:(int)arg1;
- (int)getPlayErrorCodeInt:(int)arg1;
- (id)getCurrentCDNPlayUrl:(int)arg1;
- (long long)getCurrentDownloadCanPlayDurationWithRecordID:(id)arg1;
- (long long)getTotalOffset:(int)arg1;
- (long long)getCurrentOffset:(int)arg1;
- (_Bool)isLocalVideo:(int)arg1;
- (id)getVersion;
- (void)setDLProxyConfig:(id)arg1;
- (void)setUserDataInt:(id)arg1 withValueInt:(int)arg2;
- (void)setUserDataString:(id)arg1 withValue:(id)arg2;
- (void)setCookie:(id)arg1;
- (void)setPlayCapacity:(int)arg1;
- (void)setPlayingState:(int)arg1 withPlayState:(int)arg2;
- (void)resumeDownloadOn3G;
- (void)pauseDownloadOn3G;
- (void)stopPlay:(int)arg1;
- (int)setNextVid:(id)arg1 withDltype:(int)arg2 withVID:(id)arg3 withFormat:(id)arg4 withCharge:(_Bool)arg5 withNew:(_Bool)arg6 withHotSpot:(_Bool)arg7 withStartTime:(int)arg8 withEndTime:(int)arg9 withExtraInfo:(id)arg10;
- (int)startOnlineOrOfflinePlay:(id)arg1 withDltype:(int)arg2 withCid:(id)arg3 withVid:(id)arg4 withFormat:(id)arg5 withIsCharge:(_Bool)arg6 withStartTime:(int)arg7 withEndTime:(int)arg8 withVinfoExtraInfo:(id)arg9 withExtraParams:(id)arg10 withPlayDelegate:(id)arg11;
- (_Bool)checkLocalServer;
- (void)deinit;
- (_Bool)initWithUserData:(id)arg1;

@end

