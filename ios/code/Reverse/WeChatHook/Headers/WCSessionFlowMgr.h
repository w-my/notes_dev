//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "MMService.h"
#import "WCSessionFlowListener.h"

@class MemoryMappedKV, NSString, WCSessionDSLExecuter, WCSessionFlowStatItem;

@interface WCSessionFlowMgr : MMService <MMService, WCSessionFlowListener>
{
    WCSessionFlowStatItem *sessionFlowStatItem;
    unsigned int pId;
    NSString *pName;
    NSString *prePage;
    NSString *currentPage;
    unsigned int viewHashCodeOffset;
    unsigned int tabHashCodeOffset;
    unsigned int pageHashCodeOffset;
    _Bool isContinueLastSession;
    _Bool isCallbackForeground;
    MemoryMappedKV *dataMapKv;
    MemoryMappedKV *configMapKv;
    unsigned long long reportSeq;
    NSString *userName;
    WCSessionDSLExecuter *sessionDSLExecuter;
    unsigned int businessIdSeq;
}

- (void).cxx_destruct;
- (id)getSidBySessionId:(id)arg1;
- (id)createSessionId:(id)arg1 withTime:(unsigned long long)arg2;
- (id)getSessionInfo:(id)arg1 withHashCode:(unsigned long long)arg2;
- (id)getCurrentValidSessionInfo;
- (id)getNowViewController;
- (id)obtainBusinessInfo:(id)arg1 withDataPathConfig:(id)arg2;
- (id)getMatchPagePathJsonString:(id)arg1;
- (id)getSessionMergePagePathJsonString:(id)arg1;
- (id)getSessionBusinessDataJsonString:(id)arg1;
- (id)getSessionUBAJsonString:(id)arg1;
- (id)getSessionFlowMergeJsonString:(id)arg1;
- (id)getSessionFlowSingleJsonString:(id)arg1;
- (id)getSessionFlowStatItemAttr:(id)arg1 withData:(id)arg2 withSubSeq:(unsigned long long)arg3 withSubSeqSum:(unsigned long long)arg4;
- (void)reportSessionFlowStat:(id)arg1 withMemoryKey:(id)arg2 withUserName:(id)arg3 withLogId:(unsigned int)arg4;
- (void)saveSessionFlowStat:(id)arg1 withMatchPagePaths:(id)arg2 withMemoryKey:(id)arg3 withUserName:(id)arg4;
- (void)saveSessionFlowStat:(id)arg1 withMemoryKey:(id)arg2 withUserName:(id)arg3;
- (void)handleSessionFlowDataMerge:(id)arg1;
- (void)filterSessionUBABusinessParam:(id)arg1;
- (void)checkAndFilterBusinessData:(id)arg1;
- (void)reportAndSave:(id)arg1 withUserName:(id)arg2 withReport:(_Bool)arg3;
- (void)reconstructOneReportItem:(unsigned long long)arg1;
- (void)overOneReportItem:(unsigned long long)arg1 withContinueLast:(_Bool)arg2 withReport:(_Bool)arg3;
- (id)getSessionConfigModel:(id)arg1 withVC:(id)arg2 withPrePage:(id)arg3;
- (void)onViewDismiss:(id)arg1 withName:(id)arg2;
- (void)onViewShow:(id)arg1 withName:(id)arg2;
- (void)onViewDismiss:(id)arg1;
- (void)onViewShow:(id)arg1;
- (void)onEnterForeground;
- (void)onEnterBackground;
- (void)putBizData:(id)arg1 withKey:(id)arg2;
- (void)putBizData:(id)arg1 withKey:(id)arg2 withBizId:(id)arg3;
- (id)requestBizId;
- (void)obtainSessionPagePathBusinessParams:(id)arg1 withPageName:(id)arg2 withObj:(id)arg3 withAction:(unsigned long long)arg4 withBlock:(CDUnknownBlockType)arg5;
- (void)getSessionPagePathBusinessParams:(id)arg1 withPageName:(id)arg2 withObj:(id)arg3 withAction:(unsigned long long)arg4 withBlock:(CDUnknownBlockType)arg5;
- (void)onDisappearPage:(id)arg1 withVC:(id)arg2 withHashCode:(unsigned long long)arg3;
- (void)onAppearPage:(id)arg1 withVC:(id)arg2 withHashCode:(unsigned long long)arg3;
- (id)getSessionPagePathMergeInfo:(id)arg1 withSid:(id)arg2 withPagePathId:(id)arg3;
- (id)getSessionFlowPageMergeInfo:(id)arg1 withSessionId:(id)arg2;
- (void)overIllegaSessionFlowPageInfo:(id)arg1 withTime:(unsigned long long)arg2;
- (void)overSessionFlowPageInfo:(id)arg1 withTime:(unsigned long long)arg2;
- (id)createIllegalSessionFlowPageInfo:(id)arg1 withTime:(unsigned long long)arg2 withHashCode:(unsigned long long)arg3 withPrePage:(id)arg4;
- (id)createSessionFlowPageInfo:(id)arg1 withTime:(unsigned long long)arg2 withHashCode:(unsigned long long)arg3 withPrePage:(id)arg4;
- (void)onQuitPage:(id)arg1 withVC:(id)arg2 withHashCode:(unsigned long long)arg3;
- (void)matchPagePathConfigModel:(id)arg1 withPageName:(id)arg2;
- (void)overSessionPagePathInfo:(id)arg1 withTime:(unsigned long long)arg2;
- (id)createSessionPagePathInfo:(id)arg1 withTime:(unsigned long long)arg2 withPageName:(id)arg3;
- (void)onEnterPage:(id)arg1 withVC:(id)arg2 withHashCode:(unsigned long long)arg3;
- (void)dealloc;
- (void)onSessionConfigUpdate;
- (void)onWillSuspend;
- (void)onServiceClearData;
- (void)onServiceReloadData;
- (void)onServiceInit;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

