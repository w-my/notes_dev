//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class FMDatabaseQueue;

@interface DBManager : NSObject
{
    FMDatabaseQueue *_fmdb;
}

+ (id)mainDBManager;
@property(retain, nonatomic) FMDatabaseQueue *fmdb; // @synthesize fmdb=_fmdb;
- (void).cxx_destruct;
- (id)getReadRecordByComicId:(long long)arg1;
- (id)getAllUnsyncRecords;
- (id)getAllReadRecords;
- (_Bool)delAllReadRecords;
- (_Bool)batchDeleteRecordByComicIds:(id)arg1;
- (_Bool)delReadRecordByComicId:(long long)arg1;
- (_Bool)updateAllReadRecords;
- (_Bool)updateRecordStateByComicId:(long long)arg1;
- (_Bool)addReadRecord:(id)arg1;
- (void)createTables;
- (void)delTables;
- (void)createDB;
- (id)init;

@end
