//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "SocketNetworkAdapterProtocol.h"
#import "UIAlertViewDelegate.h"

@class NSMutableDictionary, NSObject<OS_dispatch_queue>, NSString, SocketNetworkAdapter, WloginPkgHead;

@interface WloginProtocol : NSObject <SocketNetworkAdapterProtocol, UIAlertViewDelegate>
{
    WloginPkgHead *pkgHead;
    unsigned char cReplyCode;
    int replyCodeActionType;
    NSMutableDictionary *basicInfoTlvList;
    NSMutableDictionary *transInfoTlvList;
    unsigned int dwSrcSigAppid;
    unsigned int dwSrcSigSubAppid;
    unsigned int dwDstSigAppid;
    unsigned int dwDstSigSubAppid;
    NSMutableDictionary *reslutSigTlvList;
    SocketNetworkAdapter *socketAdapter;
    double timeOut;
    char sKey[16];
    char A1_Key[16];
    id protocolDelegate;
    NSObject<OS_dispatch_queue> *processQueue;
    id retryPara;
    id retryPara2;
    unsigned short retryTimes;
    BOOL cRetryFlag;
    int nowFunction;
    NSString *nowHost;
    unsigned short nowPort;
    struct timeval startTime;
    CDStruct_7a5a57b9 stInfo;
    _Bool haveGetNoticeInfo;
    id globalProtocolDet;
}

@property _Bool haveGetNoticeInfo; // @synthesize haveGetNoticeInfo;
@property(readonly) int replyCodeActionType; // @synthesize replyCodeActionType;
@property(readonly) NSMutableDictionary *reslutSigTlvList; // @synthesize reslutSigTlvList;
@property BOOL cRetryFlag; // @synthesize cRetryFlag;
@property(readonly) unsigned char cReplyCode; // @synthesize cReplyCode;
- (void)printAppid;
- (void)doNothing;
- (void)setProtocolDispatchQueue:(id)arg1;
- (void)setOtherAppidList:(id)arg1 andBitmap:(unsigned int)arg2;
- (void)setOtherAppidList:(unsigned int *)arg1 andOtherAppidNum:(unsigned int)arg2 andBitmap:(unsigned int)arg3;
- (unsigned int)pkgHeadUin;
- (void)setPkgHeadUin:(unsigned int)arg1;
- (id)sigTlvDictByTag:(unsigned short)arg1;
- (id)basicTlvByTag:(unsigned short)arg1;
- (void)onSocket:(id)arg1 didConnectToHost:(id)arg2 port:(unsigned short)arg3;
- (void)onSocketDidDisconnect:(id)arg1;
- (void)onSocket:(id)arg1 didDisconnectWithError:(id)arg2;
- (_Bool)addTransTlv:(id)arg1;
- (_Bool)addBasicTlv:(id)arg1;
- (void)onSocket:(id)arg1 didReadData:(id)arg2 withTag:(long long)arg3;
- (int)canGetNoticeInfo;
- (void)noticeInfoAdd0x200:(id)arg1 isTimeout:(int)arg2 andErrorCode:(unsigned int)arg3;
- (void)noticeInfoAdd0x2:(id)arg1;
- (void)noticeInfoAdd0x8:(id)arg1;
- (_Bool)onDevLockSmsCheck:(id)arg1;
- (void)updateIPList;
- (void)recvPkgFailRetry:(id)arg1;
- (void)recvPkgError:(id)arg1;
- (void)networkInfoReport:(short)arg1 andErrorStr:(id)arg2;
- (_Bool)decodeTlvList:(const char *)arg1 andLeftLen:(int *)arg2;
- (int)checkPtSig;
- (int)negotiateSecGUID;
- (int)refreshSmsVerifyLoginCode;
- (int)checkSmsVerifyLoginCode;
- (int)checkSmsVerifyLoginAccount;
- (int)quickLogin:(id)arg1 withNoPicSig:(id)arg2;
- (int)checkChallenge:(unsigned int)arg1;
- (int)exchangeSig:(id)arg1 byD2:(id)arg2;
- (int)exchangeSig:(id)arg1 withNoPicSig:(id)arg2;
- (int)exchangeSig:(id)arg1;
- (int)nameToUin;
- (int)refreshSmsCode;
- (int)checkSmsCode;
- (int)refreshPic;
- (int)checkPic;
- (int)loginWithPasswd:(id)arg1 withNoPicSig:(id)arg2 andLoginFlag:(unsigned char)arg3;
- (int)geneECDHReqPkg:(id)arg1 withSendPkg:(id)arg2;
- (int)genSTKeyReqPkg:(id)arg1 withST:(id)arg2 withSendPkg:(id)arg3;
- (_Bool)genEncryptBody_0x144:(id)arg1 subCmd:(unsigned short)arg2;
- (_Bool)addEcdhBackSig;
- (_Bool)genTGTGTbyPasswd:(const char *)arg1 andUin:(unsigned long long)arg2 andFlag:(int)arg3 outTGTGT:(id)arg4 andSigSrc:(unsigned int)arg5 andMUin:(unsigned long long)arg6 andName:(id)arg7;
- (_Bool)genTGTGTbyPasswd:(const char *)arg1 andUin:(unsigned long long)arg2 andFlag:(int)arg3 outTGTGT:(id)arg4 andSigSrc:(unsigned int)arg5 andMUin:(unsigned long long)arg6;
- (void)disconnect;
- (int)connectToRemortServer;
- (void)setSrcAppid:(unsigned int)arg1 andSrcSubAppid:(unsigned int)arg2 andDstAppid:(unsigned int)arg3 andDstSubAppid:(unsigned int)arg4;
- (_Bool)setServerIp:(id)arg1 andPort:(unsigned short)arg2;
- (void)dealloc;
- (_Bool)resetProtocol;
- (id)initWithClientVer:(unsigned short)arg1 andPubNo:(unsigned int)arg2 andClientType:(unsigned int)arg3 andDelegate:(id)arg4;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

