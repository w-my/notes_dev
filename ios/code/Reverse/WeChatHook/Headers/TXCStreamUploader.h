//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TXCModule.h"

#import "IntelligentRouteDelegate.h"
#import "TXIUploader.h"

@class NSLock, NSMutableArray, NSObject<OS_dispatch_source>, NSString, TXCIntelligentRoute, TXSUploadParam, UploadQualityReport, UploadStats;

@interface TXCStreamUploader : TXCModule <IntelligentRouteDelegate, TXIUploader>
{
    struct CTXRtmpSendThread *_pusher;
    struct CTXRtmpRecvMsgThread *_recvMsgThread;
    struct shared_ptr<CTXRtmpProxy> _rtmpProxy;
    struct RtmpProxyParam _proxyParam;
    _Bool _enableProxy;
    NSMutableArray *_proxyIpList;
    long long _proxyCurIpIndex;
    _Bool _audioMuted;
    NSLock *_pusherLock;
    _Bool _pushing;
    NSObject<OS_dispatch_source> *_timer;
    _Bool _isCollecting;
    long long _lastTimestamp;
    UploadStats *_lastUploadStats;
    NSMutableArray *_arrayPendingNAL;
    int _connectCountQuic;
    int _connectCountTcp;
    UploadQualityReport *_uploadQualityReport;
    _Bool _quicChannel;
    id <TXINotifyDelegate> _notifyDelegate;
    NSString *_pushUrl;
    TXSUploadParam *_param;
    NSMutableArray *_ipList;
    long long _currentIPRecordIndex;
    long long _networkType;
    NSString *_realUrl;
    TXCIntelligentRoute *_ir;
    long long _retryCount;
    long long _connectSuccessTimeStamp;
    long long _goodPushTime;
}

@property(nonatomic) long long goodPushTime; // @synthesize goodPushTime=_goodPushTime;
@property(nonatomic) long long connectSuccessTimeStamp; // @synthesize connectSuccessTimeStamp=_connectSuccessTimeStamp;
@property(nonatomic) long long retryCount; // @synthesize retryCount=_retryCount;
@property(retain, nonatomic) TXCIntelligentRoute *ir; // @synthesize ir=_ir;
@property(nonatomic) _Bool quicChannel; // @synthesize quicChannel=_quicChannel;
@property(retain, nonatomic) NSString *realUrl; // @synthesize realUrl=_realUrl;
@property(nonatomic) long long networkType; // @synthesize networkType=_networkType;
@property(nonatomic) long long currentIPRecordIndex; // @synthesize currentIPRecordIndex=_currentIPRecordIndex;
@property(retain, nonatomic) NSMutableArray *ipList; // @synthesize ipList=_ipList;
@property(retain, nonatomic) TXSUploadParam *param; // @synthesize param=_param;
@property(retain, nonatomic) NSString *pushUrl; // @synthesize pushUrl=_pushUrl;
@property(nonatomic) __weak id <TXINotifyDelegate> notifyDelegate; // @synthesize notifyDelegate=_notifyDelegate;
- (id).cxx_construct;
- (void).cxx_destruct;
- (long long)getSpeed:(long long)arg1 currValue:(long long)arg2 interval:(long long)arg3;
- (void)collectStatus;
- (void)stopCollectStatus;
- (void)startCollectStatus;
- (id)getDNSServers;
- (_Bool)isIpV6;
- (id)getAddressFromUrl:(id)arg1;
- (id)getRealRtmpUrlInfo;
- (_Bool)nextRecordIdx:(_Bool)arg1;
- (void)sendProxyHeartbeat;
- (void)startProxyThread;
- (void)stopPushTask;
- (void)startPushTask:(id)arg1 QuicChannel:(_Bool)arg2 Delay:(double)arg3;
- (id)getConfusionIP:(id)arg1;
- (void)onFetchDone:(long long)arg1 IpList:(id)arg2;
- (void)reconnect:(_Bool)arg1;
- (void)sendNotifyEvent:(int)arg1;
- (void)sendNotifyEvent:(int)arg1 msg:(id)arg2;
- (void)applyVideoDropParams;
- (void)setDropEnable:(_Bool)arg1;
- (id)getUploadStats;
- (void)setSendStrategy:(_Bool)arg1 sendAudioFirst:(_Bool)arg2;
- (void)setVideoDropParams:(_Bool)arg1 maxVideoCount:(int)arg2 maxVideoCacheTime:(int)arg3;
- (void)setReconnectCount:(int)arg1 reconnectInterval:(int)arg2;
- (void)setAudioMute:(_Bool)arg1;
- (void)internalPushNAL:(id)arg1;
- (void)pushNAL:(id)arg1;
- (void)pushAAC:(id)arg1 timestamp:(unsigned long long)arg2;
- (void)tryResetRetryCount;
- (void)stop;
- (id)dictionaryFromQuery:(id)arg1 usingEncoding:(unsigned long long)arg2;
- (unsigned int)getIPAddress;
- (_Bool)getNextProxyIP;
- (_Bool)parseProxyInfo:(id)arg1;
- (id)start:(id)arg1;
- (id)initWithParam:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
