//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "ScanQRCodeUrlPrefixHandler.h"

#import "MMUseCaseCallback.h"
#import "WCBaseControlMgrExt.h"
#import "WCPayPayAuthNativeCgiDelegate.h"

@class NSString, WCPayPayAuthNativeCgi;

@interface ScanQRCodeBizUrlHandler : ScanQRCodeUrlPrefixHandler <WCBaseControlMgrExt, WCPayPayAuthNativeCgiDelegate, MMUseCaseCallback>
{
    unsigned int _m_sourceType;
    NSString *_m_sourceInfo;
    WCPayPayAuthNativeCgi *_m_payNativeCgi;
}

@property(retain, nonatomic) WCPayPayAuthNativeCgi *m_payNativeCgi; // @synthesize m_payNativeCgi=_m_payNativeCgi;
@property(retain, nonatomic) NSString *m_sourceInfo; // @synthesize m_sourceInfo=_m_sourceInfo;
@property(nonatomic) unsigned int m_sourceType; // @synthesize m_sourceType=_m_sourceType;
- (void).cxx_destruct;
- (void)onWCBaseLogicDidStop:(unsigned int)arg1;
- (void)onWCPayPayAuthNativeCgiWithResp:(id)arg1;
- (id)matchingPrefix;
- (void)call:(id)arg1;
- (void)handleUrl:(id)arg1;
- (void)reportCount;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

