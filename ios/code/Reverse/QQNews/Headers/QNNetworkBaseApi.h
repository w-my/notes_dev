//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNetworkRequest.h"

#import "NSCopying.h"

@class NSNumber, NSURL, QNAsyncSerialTask;

@interface QNNetworkBaseApi : QNNetworkRequest <NSCopying>
{
    _Bool _shouldAppendDefaultParameters;
    unsigned long long _headerCookieAccountType;
    unsigned long long _commonConfigureOption;
    unsigned long long _networkDisasterType;
    QNAsyncSerialTask *_serialTask;
    id <AspectToken> _do_startHook;
    id <AspectToken> _fireSuccessHook;
    id <AspectToken> _fireFailHook;
    double _createTime;
    NSURL *_qn_originBaseURL;
}

+ (id)defaultUserAgentString;
+ (id)networkTransportQueue;
@property(copy, nonatomic) NSURL *qn_originBaseURL; // @synthesize qn_originBaseURL=_qn_originBaseURL;
@property(nonatomic) double createTime; // @synthesize createTime=_createTime;
@property(retain, nonatomic) id <AspectToken> fireFailHook; // @synthesize fireFailHook=_fireFailHook;
@property(retain, nonatomic) id <AspectToken> fireSuccessHook; // @synthesize fireSuccessHook=_fireSuccessHook;
@property(retain, nonatomic) id <AspectToken> do_startHook; // @synthesize do_startHook=_do_startHook;
@property(retain, nonatomic) QNAsyncSerialTask *serialTask; // @synthesize serialTask=_serialTask;
@property(nonatomic) unsigned long long networkDisasterType; // @synthesize networkDisasterType=_networkDisasterType;
@property(nonatomic) unsigned long long commonConfigureOption; // @synthesize commonConfigureOption=_commonConfigureOption;
@property(nonatomic) unsigned long long headerCookieAccountType; // @synthesize headerCookieAccountType=_headerCookieAccountType;
@property(nonatomic) _Bool shouldAppendDefaultParameters; // @synthesize shouldAppendDefaultParameters=_shouldAppendDefaultParameters;
- (void).cxx_destruct;
- (void)stopMonitorNetworkResults;
- (void)startMonitorNetworkResults:(_Bool)arg1;
- (void)startMonitorNetworkResults;
- (void)do_markFinished;
- (void)do_cancel;
- (void)do_start;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)p_addLoginDataToContext:(id)arg1;
- (void)p_appendDefaultParametersToContext:(id)arg1;
- (void)p_appendDefaultHeadersToContext:(id)arg1;
- (id)initWithURLString:(id)arg1 baseURL:(id)arg2;
- (id)_retrieveIPDirectConnectURL:(_Bool *)arg1;

// Remaining properties
@property(readonly, nonatomic) NSNumber *isBelongToDisasterRecoverySerialTask; // @dynamic isBelongToDisasterRecoverySerialTask;

@end
