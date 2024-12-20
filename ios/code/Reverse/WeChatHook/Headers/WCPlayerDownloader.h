//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "WCPlayerDownloaderExt.h"

@class NSObject<WCPlayerDownloadMgrInterface>, NSString, WCPlayerPlayArgs, WCPlayerPlaybackInfo, WCPlayerReporter;

@interface WCPlayerDownloader : NSObject <WCPlayerDownloaderExt>
{
    _Bool _bHadRecievedAllData;
    _Bool _bHadRecieveMoov;
    _Bool _bHadRecievePreLoadData;
    WCPlayerReporter *_reporter;
    WCPlayerPlayArgs *_playerArgs;
    WCPlayerPlaybackInfo *_playbackInfo;
    NSObject *_mediaWrap;
    NSObject<WCPlayerDownloadMgrInterface> *_downloadMgr;
    NSString *_clientMediaId;
    id <WCPlayerDownloaderDelegate> _delegate;
}

+ (id)generatePlayerDownloaderWithPlayerArgs:(id)arg1 PlaybackInfo:(id)arg2 Reporter:(id)arg3;
@property(nonatomic) id <WCPlayerDownloaderDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) NSString *clientMediaId; // @synthesize clientMediaId=_clientMediaId;
@property(nonatomic) _Bool bHadRecievePreLoadData; // @synthesize bHadRecievePreLoadData=_bHadRecievePreLoadData;
@property(nonatomic) _Bool bHadRecieveMoov; // @synthesize bHadRecieveMoov=_bHadRecieveMoov;
@property(nonatomic) _Bool bHadRecievedAllData; // @synthesize bHadRecievedAllData=_bHadRecievedAllData;
@property(retain, nonatomic) NSObject<WCPlayerDownloadMgrInterface> *downloadMgr; // @synthesize downloadMgr=_downloadMgr;
@property(retain, nonatomic) NSObject *mediaWrap; // @synthesize mediaWrap=_mediaWrap;
@property(retain, nonatomic) WCPlayerPlaybackInfo *playbackInfo; // @synthesize playbackInfo=_playbackInfo;
@property(retain, nonatomic) WCPlayerPlayArgs *playerArgs; // @synthesize playerArgs=_playerArgs;
@property(retain, nonatomic) WCPlayerReporter *reporter; // @synthesize reporter=_reporter;
- (void).cxx_destruct;
- (void)startDataPreload;
- (_Bool)isVideoDownloading;
- (void)stopDownloadVideo;
- (id)getPlayerMediaId;
- (void)startWithWithPlayerMode:(unsigned long long)arg1;
- (_Bool)isVideoDataAvailableInTmpPathWithRange:(struct _NSRange)arg1;
- (void)realNetRequestDataWithRange:(struct _NSRange)arg1 Sec:(unsigned int)arg2;
- (void)OnCdnDownloadInterrupt:(id)arg1 Result:(struct C2CDownloadResult)arg2;
- (void)OnCdnDownloadProgress:(id)arg1;
- (void)OnCdnDownloadError:(id)arg1;
- (void)OnCdnDownloadSuccess:(id)arg1;
- (void)OnHintLocalCache:(id)arg1;
- (void)OnCdnVideoDataAvaiable:(id)arg1;
- (void)OnCdnDownloadStart:(id)arg1;
- (void)OnCdnVideoMoovReady:(id)arg1 WaitTime:(unsigned int)arg2 Offset:(unsigned long long)arg3;
- (void)OnCdnUpdatePreloadInfo:(id)arg1;
- (void)getPreVideoData;
- (_Bool)isVideoDataAvailableWithRange:(struct _NSRange)arg1;
- (_Bool)requestDataWithRange:(struct _NSRange)arg1 Sec:(unsigned int)arg2;
- (id)getVideoDataWithRange:(struct _NSRange)arg1;
- (void)dealloc;
- (id)initWithPlayerArgs:(id)arg1 PlaybackInfo:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

