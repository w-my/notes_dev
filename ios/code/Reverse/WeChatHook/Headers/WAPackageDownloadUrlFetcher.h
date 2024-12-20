//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "MMService.h"

@class NSMutableArray, NSString;

@interface WAPackageDownloadUrlFetcher : MMService <MMService>
{
    NSMutableArray *_arrFetching;
    NSMutableArray *_arrWaiting;
}

- (void).cxx_destruct;
- (void)handleGetRemoteCDNPkgDownloadUrl:(id)arg1;
- (void)onCgiResponse:(id)arg1 forEvent:(unsigned int)arg2;
- (_Bool)requestDownloadUrl:(id)arg1;
- (void)checkWaitingQueue;
- (void)removeInfoDataTask:(id)arg1;
- (_Bool)checkIsInQueue:(id)arg1 withInfoData:(id)arg2;
- (_Bool)checkIsInWaitingQueue:(id)arg1;
- (_Bool)checkIsInFetchQueue:(id)arg1;
- (void)mainThread_getRemoteCDNPkgDownloadUrlWithAppInfoData:(id)arg1;
- (void)getRemoteCDNPkgDownloadUrlWithAppInfoData:(id)arg1;
- (void)onServiceClearData;
- (void)onServiceReloadData;
- (void)onServiceInit;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

