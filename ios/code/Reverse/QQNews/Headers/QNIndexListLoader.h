//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBasicListLoader.h"

#import "QNIndexListLoaderSubClassProtocol.h"

@class NSString, QNAsyncSerialTask;

@interface QNIndexListLoader : QNBasicListLoader <QNIndexListLoaderSubClassProtocol>
{
    id <QNIndexListLoaderSubClassProtocol> _subClassInstance;
    QNAsyncSerialTask *_serialTask;
}

@property(retain, nonatomic) QNAsyncSerialTask *serialTask; // @synthesize serialTask=_serialTask;
@property(nonatomic) __weak id <QNIndexListLoaderSubClassProtocol> subClassInstance; // @synthesize subClassInstance=_subClassInstance;
- (void).cxx_destruct;
- (id)_aggregateTaskResults:(id)arg1 loadOption:(long long)arg2 direction:(unsigned long long)arg3 refError:(id *)arg4;
- (id)_listApiParamsWithUrlString:(id)arg1 direction:(unsigned long long)arg2 postParams:(id)arg3 queryParams:(id)arg4;
- (id)_taskForLoadRemoteServerData:(id)arg1 direction:(unsigned long long)arg2 postParams:(id)arg3 queryParams:(id)arg4;
- (void)loadDataFromUrlString:(id)arg1 cachePolicy:(unsigned long long)arg2 direction:(unsigned long long)arg3 loadOption:(long long)arg4 postKeyValues:(id)arg5 queryKeyValues:(id)arg6 withFinished:(CDUnknownBlockType)arg7 failed:(CDUnknownBlockType)arg8;
- (_Bool)needLoadRemoteData:(unsigned long long)arg1;
- (_Bool)needLoadCacheData:(unsigned long long)arg1;
- (void)_loadFinished;
- (void)cancelRequest;
- (void)dealloc;
- (id)initWithChannelID:(id)arg1 listDataManager:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

