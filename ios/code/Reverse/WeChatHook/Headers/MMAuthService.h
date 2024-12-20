//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "MMAxAuthLogicDelegate.h"
#import "MMConfigMgrExt.h"
#import "MMService.h"

@class MMAuthInfo, NSData, NSMutableDictionary, NSSet, NSString;

@interface MMAuthService : MMService <MMConfigMgrExt, MMAxAuthLogicDelegate, MMService>
{
    _Bool m_useAesGcmSessionKey;
    NSSet *_useAesGcmSessionKeyCgis;
    MMAuthInfo *_oriAuthInfo;
    MMAuthInfo *_mainAuthInfo;
    NSMutableDictionary *_axAuthWrapDic;
    NSMutableDictionary *_axAuthWrapFromHostDic;
}

@property(retain) NSMutableDictionary *axAuthWrapFromHostDic; // @synthesize axAuthWrapFromHostDic=_axAuthWrapFromHostDic;
@property(retain) NSMutableDictionary *axAuthWrapDic; // @synthesize axAuthWrapDic=_axAuthWrapDic;
@property(retain) MMAuthInfo *mainAuthInfo; // @synthesize mainAuthInfo=_mainAuthInfo;
@property(retain) MMAuthInfo *oriAuthInfo; // @synthesize oriAuthInfo=_oriAuthInfo;
@property(retain) NSSet *useAesGcmSessionKeyCgis; // @synthesize useAesGcmSessionKeyCgis=_useAesGcmSessionKeyCgis;
- (void).cxx_destruct;
- (void)onMMDynamicConfigUpdated;
- (void)onAxAuthLogicFailed:(id)arg1;
- (void)onAxAuthLogicSuccess:(id)arg1 clientSessionKey:(id)arg2 serverSessionKey:(id)arg3;
- (void)loadUseAesGcmSessionKeyConfig;
- (_Bool)isMainHostCgi:(unsigned int)arg1;
- (unsigned long long)checkAxAuthStateForHost:(id)arg1;
- (id)mainHostAuthInfoForEncryptAlgo:(int)arg1;
- (id)authInfoForCgi:(unsigned int)arg1 host:(id)arg2;
- (void)updateAxAuthSecRespList:(id)arg1;
- (void)updateServerId:(id)arg1 forCgi:(unsigned int)arg2;
@property(retain, nonatomic) NSData *mainHostServerId; // @dynamic mainHostServerId;
- (void)updateMainHostClientSessionKey:(id)arg1 serverSessionKey:(id)arg2;
@property(retain, nonatomic) NSData *oriSessionKey; // @dynamic oriSessionKey;
- (void)onServiceReloadData;
- (void)onServiceInit;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

