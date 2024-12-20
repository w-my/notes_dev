//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSObject<OS_dispatch_queue>;

@interface ODKVOldStore : NSObject
{
    _Bool _hasOldData;
    unsigned int _cachedEventsNum;
    unsigned int _hasDeleteedCount;
    struct sqlite3 *_db;
    NSObject<OS_dispatch_queue> *_taskQueue;
}

+ (id)sharedStore;
@property unsigned int hasDeleteedCount; // @synthesize hasDeleteedCount=_hasDeleteedCount;
@property unsigned int cachedEventsNum; // @synthesize cachedEventsNum=_cachedEventsNum;
@property _Bool hasOldData; // @synthesize hasOldData=_hasOldData;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *taskQueue; // @synthesize taskQueue=_taskQueue;
@property(nonatomic) struct sqlite3 *db; // @synthesize db=_db;
- (void).cxx_destruct;
- (void)sendEvent;
- (void)storeEvents:(id)arg1;
- (void)deleteCachedEvents:(id)arg1;
- (void)deleteErrorEvents:(id)arg1;
- (void)readCachedEvents:(id)arg1;
- (void)updateEvents:(id)arg1 status:(unsigned int)arg2;
- (void)updateEventsStatus;
- (_Bool)executeUpdate:(id)arg1;
- (unsigned int)getCachedEventsNum;
- (_Bool)deleteOldEvent;
- (void)handleOldEvents;
- (void)deleteOldDatabaseFile;
- (_Bool)openDatabase:(id)arg1;
- (id)initUniqueInstance;

@end

