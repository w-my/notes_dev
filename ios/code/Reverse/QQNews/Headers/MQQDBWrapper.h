//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MQQDatabase, NSDate, NSObject<OS_dispatch_queue>, NSString;

@interface MQQDBWrapper : NSObject
{
    MQQDatabase *_mDB;
    NSObject<OS_dispatch_queue> *_queue;
    long long _journalMode;
    unsigned long long _walAutoCheckPointLogPages;
    _Bool _isCachedStatements;
    NSString *_dbPath;
    NSDate *_lastWalCheckDate;
}

+ (id)databaseWrapperWithPath:(id)arg1;
@property(nonatomic) _Bool isCachedStatements; // @synthesize isCachedStatements=_isCachedStatements;
@property(retain, nonatomic) NSDate *lastWalCheckDate; // @synthesize lastWalCheckDate=_lastWalCheckDate;
@property(copy, nonatomic) NSString *dbPath; // @synthesize dbPath=_dbPath;
@property(nonatomic) unsigned long long walAutoCheckPointLogPages; // @synthesize walAutoCheckPointLogPages=_walAutoCheckPointLogPages;
- (void)inTransaction:(CDUnknownBlockType)arg1;
- (void)inDatabase:(CDUnknownBlockType)arg1;
- (long long)journalMode;
- (void)setJournalMode:(long long)arg1;
- (_Bool)walCheckPoint;
- (id)database;
- (long long)__journalMode;
- (void)dispatchDBQueueWithBlock:(CDUnknownBlockType)arg1;
- (void)dealloc;
- (id)initWithPath:(id)arg1;

@end

