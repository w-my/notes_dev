//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBasicListLoader.h"

@class QNAsyncSerialTask;

@interface QNListLoader : QNBasicListLoader
{
    QNAsyncSerialTask *_serialTask;
}

@property(retain, nonatomic) QNAsyncSerialTask *serialTask; // @synthesize serialTask=_serialTask;
- (void).cxx_destruct;
- (void)_updateArticlePage:(long long)arg1 toModuleList:(id)arg2;
- (void)_updateArticlePage:(long long)arg1 toListItems:(id)arg2;
- (id)_deleteListItemsWithRemoteResponse:(id)arg1 loadOption:(long long)arg2 direction:(unsigned long long)arg3;
- (id)_getNewListItemsWithRemoteResponse:(id)arg1 loadOption:(long long)arg2 deleteNewsIDsSet:(id)arg3 direction:(unsigned long long)arg4;
- (id)_aggregateTaskResults:(id)arg1 loadOption:(long long)arg2 direction:(unsigned long long)arg3 refError:(id *)arg4;
- (id)_listApiParamsWithUrlString:(id)arg1 direction:(unsigned long long)arg2 postParams:(id)arg3 queryParams:(id)arg4;
- (id)_taskForLoadRemoteServerData:(id)arg1 direction:(unsigned long long)arg2 postParams:(id)arg3 queryParams:(id)arg4;
- (_Bool)needLoadRemoteData:(unsigned long long)arg1;
- (_Bool)needLoadCacheData:(unsigned long long)arg1;
- (void)cancelRequest;
- (void)loadDataFromUrlString:(id)arg1 cachePolicy:(unsigned long long)arg2 direction:(unsigned long long)arg3 loadOption:(long long)arg4 postKeyValues:(id)arg5 queryKeyValues:(id)arg6 withFinished:(CDUnknownBlockType)arg7 failed:(CDUnknownBlockType)arg8;
- (void)dealloc;
- (id)initWithChannelID:(id)arg1 listDataManager:(id)arg2;

@end
