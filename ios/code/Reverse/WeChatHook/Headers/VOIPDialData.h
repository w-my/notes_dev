//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class CContact, NSData, NSMutableArray, NSString;

@interface VOIPDialData : NSObject
{
    int mStrategy;
    int mRoomId;
    int mRoomMemberId;
    int mLinkDisconnectHbInterval;
    int mLinkDisconnectHbCnt;
    int mEncryptLength;
    int mARQStrategy;
    int mARQCacheLen;
    int mARQRttThreshold;
    int mARQUsedRateThreshold;
    int mARQRespRateThreshold;
    int mEncryptStrategy;
    int mRedirectReqThreshold;
    int mBothSideGeneralSwitch;
    int mQosStrategyVideo;
    int mQosStrategyAudio;
    int mQosStrategyLink;
    int mCSTcpStartCnt;
    int mFECSvrCtr;
    int _mDataChannelType;
    NSData *mLocalPid;
    NSData *mLocalCapInfo;
    NSData *mRemotePid;
    NSData *mRemoteCapInfo;
    unsigned long long mRoomId64;
    long long mRoomKey;
    CContact *mContact;
    NSString *mCaller;
    NSData *mClientSigns;
    NSData *mRemoteDirectInfo;
    NSData *mEncryptKey;
    NSData *mBothSideGeneralStrategy;
    NSData *mGeneralStrategy;
    NSMutableArray *mRelaySvrIp;
    NSMutableArray *mRelaySvrIpStr;
    NSMutableArray *mRelaySvrPort;
    NSMutableArray *mPunchSvrIp;
    NSMutableArray *mPunchSvrPort;
    NSMutableArray *mTcpSvrIp;
    NSMutableArray *mTcpSvrPort;
    NSMutableArray *mTcpSvrIpStr;
    NSMutableArray *mNatSvrAddr;
    NSMutableArray *mCSSvrIp;
    NSMutableArray *mCSSvrPort;
    NSMutableArray *mCSTcpSvrIp;
    NSMutableArray *mCSTcpSvrPort;
    NSData *mFECKeyPara1;
    NSData *mFECKeyPara2;
    CDStruct_c3c0afbc *mAudioSvrParams;
    NSMutableArray *mCSVoipMember;
    NSMutableArray *_mPunchSvrIpStr;
}

@property(nonatomic) int mDataChannelType; // @synthesize mDataChannelType=_mDataChannelType;
@property(retain, nonatomic) NSMutableArray *mPunchSvrIpStr; // @synthesize mPunchSvrIpStr=_mPunchSvrIpStr;
@property(retain, nonatomic) NSMutableArray *mCSVoipMember; // @synthesize mCSVoipMember;
@property(nonatomic) CDStruct_c3c0afbc *mAudioSvrParams; // @synthesize mAudioSvrParams;
@property(retain, nonatomic) NSData *mFECKeyPara2; // @synthesize mFECKeyPara2;
@property(retain, nonatomic) NSData *mFECKeyPara1; // @synthesize mFECKeyPara1;
@property(nonatomic) int mFECSvrCtr; // @synthesize mFECSvrCtr;
@property(nonatomic) int mCSTcpStartCnt; // @synthesize mCSTcpStartCnt;
@property(retain, nonatomic) NSMutableArray *mCSTcpSvrPort; // @synthesize mCSTcpSvrPort;
@property(retain, nonatomic) NSMutableArray *mCSTcpSvrIp; // @synthesize mCSTcpSvrIp;
@property(retain, nonatomic) NSMutableArray *mCSSvrPort; // @synthesize mCSSvrPort;
@property(retain, nonatomic) NSMutableArray *mCSSvrIp; // @synthesize mCSSvrIp;
@property(retain, nonatomic) NSMutableArray *mNatSvrAddr; // @synthesize mNatSvrAddr;
@property(retain, nonatomic) NSMutableArray *mTcpSvrIpStr; // @synthesize mTcpSvrIpStr;
@property(retain, nonatomic) NSMutableArray *mTcpSvrPort; // @synthesize mTcpSvrPort;
@property(retain, nonatomic) NSMutableArray *mTcpSvrIp; // @synthesize mTcpSvrIp;
@property(retain, nonatomic) NSMutableArray *mPunchSvrPort; // @synthesize mPunchSvrPort;
@property(retain, nonatomic) NSMutableArray *mPunchSvrIp; // @synthesize mPunchSvrIp;
@property(retain, nonatomic) NSMutableArray *mRelaySvrPort; // @synthesize mRelaySvrPort;
@property(retain, nonatomic) NSMutableArray *mRelaySvrIpStr; // @synthesize mRelaySvrIpStr;
@property(retain, nonatomic) NSMutableArray *mRelaySvrIp; // @synthesize mRelaySvrIp;
@property(nonatomic) int mQosStrategyLink; // @synthesize mQosStrategyLink;
@property(nonatomic) int mQosStrategyAudio; // @synthesize mQosStrategyAudio;
@property(nonatomic) int mQosStrategyVideo; // @synthesize mQosStrategyVideo;
@property(retain, nonatomic) NSData *mGeneralStrategy; // @synthesize mGeneralStrategy;
@property(retain, nonatomic) NSData *mBothSideGeneralStrategy; // @synthesize mBothSideGeneralStrategy;
@property(nonatomic) int mBothSideGeneralSwitch; // @synthesize mBothSideGeneralSwitch;
@property(nonatomic) int mRedirectReqThreshold; // @synthesize mRedirectReqThreshold;
@property(retain, nonatomic) NSData *mEncryptKey; // @synthesize mEncryptKey;
@property(nonatomic) int mEncryptStrategy; // @synthesize mEncryptStrategy;
@property(nonatomic) int mARQRespRateThreshold; // @synthesize mARQRespRateThreshold;
@property(nonatomic) int mARQUsedRateThreshold; // @synthesize mARQUsedRateThreshold;
@property(nonatomic) int mARQRttThreshold; // @synthesize mARQRttThreshold;
@property(nonatomic) int mARQCacheLen; // @synthesize mARQCacheLen;
@property(nonatomic) int mARQStrategy; // @synthesize mARQStrategy;
@property(retain, nonatomic) NSData *mRemoteDirectInfo; // @synthesize mRemoteDirectInfo;
@property(retain, nonatomic) NSData *mClientSigns; // @synthesize mClientSigns;
@property(nonatomic) int mEncryptLength; // @synthesize mEncryptLength;
@property(nonatomic) int mLinkDisconnectHbCnt; // @synthesize mLinkDisconnectHbCnt;
@property(nonatomic) int mLinkDisconnectHbInterval; // @synthesize mLinkDisconnectHbInterval;
@property(retain, nonatomic) NSString *mCaller; // @synthesize mCaller;
@property(retain, nonatomic) CContact *mContact; // @synthesize mContact;
@property(nonatomic) long long mRoomKey; // @synthesize mRoomKey;
@property(nonatomic) int mRoomMemberId; // @synthesize mRoomMemberId;
@property(nonatomic) unsigned long long mRoomId64; // @synthesize mRoomId64;
@property(nonatomic) int mRoomId; // @synthesize mRoomId;
@property(nonatomic) int mStrategy; // @synthesize mStrategy;
@property(retain, nonatomic) NSData *mRemoteCapInfo; // @synthesize mRemoteCapInfo;
@property(retain, nonatomic) NSData *mRemotePid; // @synthesize mRemotePid;
@property(retain, nonatomic) NSData *mLocalCapInfo; // @synthesize mLocalCapInfo;
@property(retain, nonatomic) NSData *mLocalPid; // @synthesize mLocalPid;
- (void).cxx_destruct;
- (void)UpdateCSVoipMemberInfo:(id)arg1;
- (void)AddCSVoipMemberInfo:(id)arg1;
- (id)GetCSVoipMemberInfo:(unsigned int)arg1;
- (_Bool)isValidKey;
- (void)reset;
- (void)SetRoomId64:(unsigned long long)arg1;
- (void)SetRoomKey:(long long)arg1;
- (void)SetRoomMemberId:(int)arg1;
- (void)SetRoomId:(int)arg1;
- (void)dealloc;
- (id)init;

@end
