//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "MMResInfoMgr.h"

@class NSString, WCTDatabase, WCTTable;

@interface MMResInfoMgr : NSObject <MMResInfoMgr>
{
    NSString *_dbPath;
    WCTDatabase *_db;
    WCTTable *_tableResInfo;
    WCTTable *_tableResDownloadInfo;
}

@property(retain) WCTTable *tableResDownloadInfo; // @synthesize tableResDownloadInfo=_tableResDownloadInfo;
@property(retain) WCTTable *tableResInfo; // @synthesize tableResInfo=_tableResInfo;
@property(retain) WCTDatabase *db; // @synthesize db=_db;
- (void).cxx_destruct;
- (void)dealloc;
- (_Bool)deleteResDownloadInfo:(unsigned int)arg1 WithSubtype:(unsigned int)arg2 WithEid:(unsigned int)arg3;
- (_Bool)deleteResDownloadInfo:(unsigned int)arg1;
- (_Bool)deleteTestResDownloadInfo:(unsigned int)arg1 WithSubtype:(unsigned int)arg2;
- (_Bool)deleteResDownloadInfo:(unsigned int)arg1 WithSubtype:(unsigned int)arg2;
- (_Bool)updateResDownloadInfo:(id)arg1;
- (id)getResDownloadInfo:(unsigned int)arg1 WithSubtype:(unsigned int)arg2 WithEid:(unsigned int)arg3;
- (id)getResDownloadInfo:(unsigned int)arg1 WithSubtype:(unsigned int)arg2;
- (id)getABTestResDownloadInfo:(unsigned int)arg1;
- (id)getResDownloadInfo:(unsigned int)arg1;
- (_Bool)insertNewResDownloadInfo:(id)arg1;
- (_Bool)updateResInfo:(id)arg1;
- (_Bool)deleteResInfo:(unsigned int)arg1 WithSubResType:(unsigned int)arg2 WithEid:(unsigned int)arg3;
- (_Bool)deleteTestResInfo:(unsigned int)arg1 WithSubResType:(unsigned int)arg2;
- (_Bool)deleteResInfo:(unsigned int)arg1 WithSubResType:(unsigned int)arg2;
- (_Bool)deleteResInfo:(unsigned int)arg1;
- (id)getResInfo:(unsigned int)arg1;
- (id)getResInfo:(unsigned int)arg1 WithSubRestype:(unsigned int)arg2 WithEid:(unsigned int)arg3;
- (id)getTestResInfo:(unsigned int)arg1 WithSubRestype:(unsigned int)arg2;
- (id)getResInfo:(unsigned int)arg1 WithSubRestype:(unsigned int)arg2;
- (_Bool)insertNewResInfo:(id)arg1;
- (void)didRecoverDatabase;
- (void)closeDB;
- (void)createTables;
- (void)openDB;
- (id)initWithDBPath:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

