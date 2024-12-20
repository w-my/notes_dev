//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class FMDatabaseQueue, NSMutableDictionary, NSObject<OS_dispatch_queue>;

@interface QNSubscribeInsterestDataStore : NSObject
{
    NSObject<OS_dispatch_queue> *_subscribeLikeTypeSerialQueue;
    FMDatabaseQueue *_dbQueue;
    NSMutableDictionary *_ariticleIdLikeTypeMap;
    NSMutableDictionary *_pendingAriticleIdLikeTypeMap;
}

+ (id)sharedInstance;
- (void).cxx_destruct;
- (void)p_flushPendingArticleIds;
- (void)p_asyncReadMapFromDB;
- (void)removeAllRecords;
- (void)p_removeOutDatedMarks;
- (void)p_UIApplicationWillResignActiveNotification:(id)arg1;
- (void)p_createTable;
- (id)p_dbPath;
- (void)modifyArticleLikeType:(long long)arg1 withArticleId:(id)arg2;
- (long long)articleLikeTypeWithArticleId:(id)arg1;
- (id)init;

@end

