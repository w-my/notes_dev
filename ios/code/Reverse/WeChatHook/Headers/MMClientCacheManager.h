//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "ICdnComMgrExt.h"
#import "IMsgExt.h"
#import "MMKernelExt.h"
#import "MMService.h"

@class NSObject<OS_dispatch_queue>, NSString;

@interface MMClientCacheManager : MMService <IMsgExt, ICdnComMgrExt, MMService, MMKernelExt>
{
    NSObject<OS_dispatch_queue> *_queue;
    NSString *_curDownloadUrl;
}

- (void).cxx_destruct;
- (void)updateKey:(id)arg1;
- (void)doSSReport:(unsigned long long)arg1;
- (void)doDReport;
- (void)reportExtInfo:(id)arg1;
- (void)OnCdnDownload:(id)arg1;
- (void)onNewRegOK;
- (void)onManulLoginOK;
- (void)OnGetNewXmlMsg:(id)arg1 Type:(id)arg2 MsgWrap:(id)arg3;
- (void)onAuthOK;
- (void)onServiceTerminate;
- (void)onServiceEnterForeground;
- (void)onServiceEnterBackground;
- (id)getBasicData;
- (id)getInfoPath;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
