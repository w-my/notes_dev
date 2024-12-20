//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "IExptServiceExt.h"
#import "MMService.h"

@class MemoryMappedKV, NSString, WCSessionFlowConfigModel, WCSessionPageConfigModel, WCSessionUBAConfigModel;

@interface WCSessionFlowConfig : MMService <MMService, IExptServiceExt>
{
    _Bool _isNeedReportSingle;
    _Bool _isNeedCollectSessionUBA;
    WCSessionFlowConfigModel *_sessionFlowConfigModel;
    WCSessionPageConfigModel *_sessionPageConfigModel;
    WCSessionUBAConfigModel *_sessionUBAConfigModel;
    MemoryMappedKV *_configMapKv;
}

@property(retain, nonatomic) MemoryMappedKV *configMapKv; // @synthesize configMapKv=_configMapKv;
@property(nonatomic) _Bool isNeedCollectSessionUBA; // @synthesize isNeedCollectSessionUBA=_isNeedCollectSessionUBA;
@property(nonatomic) _Bool isNeedReportSingle; // @synthesize isNeedReportSingle=_isNeedReportSingle;
@property(retain, nonatomic) WCSessionUBAConfigModel *sessionUBAConfigModel; // @synthesize sessionUBAConfigModel=_sessionUBAConfigModel;
@property(retain, nonatomic) WCSessionPageConfigModel *sessionPageConfigModel; // @synthesize sessionPageConfigModel=_sessionPageConfigModel;
@property(retain, nonatomic) WCSessionFlowConfigModel *sessionFlowConfigModel; // @synthesize sessionFlowConfigModel=_sessionFlowConfigModel;
- (void).cxx_destruct;
- (_Bool)isSessionUBAMonitorSwitch;
- (_Bool)isSessionMonitorSwitch;
- (_Bool)isNeedReportSingleSwitch;
- (void)onSessionUBAConfigChange:(id)arg1 isDel:(_Bool)arg2;
- (void)onSessionPageConfigChange:(id)arg1 isDel:(_Bool)arg2 andSessionPageId:(unsigned int)arg3 needReport:(_Bool)arg4;
- (void)onSessionConfigChange:(id)arg1 isDel:(_Bool)arg2 needReport:(_Bool)arg3;
- (_Bool)isFilterPage:(id)arg1;
- (_Bool)isMainTabPage:(id)arg1;
- (_Bool)isBlackListPage:(id)arg1;
- (id)getSessionUBAUnitConfigModel:(id)arg1;
- (id)getPagePathConfigModels:(id)arg1;
- (id)getPagePathConfigModel:(id)arg1;
- (id)getSessionFlowSidByPageName:(id)arg1 withPrePage:(id)arg2 withSessionParamExpects:(id)arg3;
- (id)getSessionFlowPageNameBySessionId:(id)arg1;
- (id)getSessionFlowConfigBySid:(id)arg1;
- (id)getSessionFlowConfigBySessionId:(id)arg1;
- (id)getSessionFlowConfigByPageName:(id)arg1 withPrePage:(id)arg2 withSessionParamExpects:(id)arg3;
- (id)getSessionFlowConfigsByPageName:(id)arg1 withPrePage:(id)arg2;
- (void)dealloc;
- (void)initSessionUBA;
- (void)initSessionPageConfig;
- (void)initSessionFlowConfig;
- (void)onServiceClearData;
- (void)onServiceReloadData;
- (void)onServiceInit;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

