//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "MMCleanCacheMgrExt.h"

@class NSMutableDictionary, NSString;

@interface YYQBWebViewProcessPoolMgr : MMObject <MMCleanCacheMgrExt>
{
    NSMutableDictionary *_dicUsrName2Pool;
}

+ (id)shareInstance;
- (void).cxx_destruct;
- (void)onCacheMgrCleanCacheWarning;
- (void)removeAllProcessPool;
- (void)removeProcessPoolForCurrentUser;
- (id)processPool;
- (id)init;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

