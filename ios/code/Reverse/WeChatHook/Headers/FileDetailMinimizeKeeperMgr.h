//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "MMService.h"

@class NSMutableDictionary, NSRecursiveLock, NSString;

@interface FileDetailMinimizeKeeperMgr : MMService <MMService>
{
    NSRecursiveLock *_lock;
    NSMutableDictionary *_fileVcDic;
}

@property(retain, nonatomic) NSMutableDictionary *fileVcDic; // @synthesize fileVcDic=_fileVcDic;
@property(retain, nonatomic) NSRecursiveLock *lock; // @synthesize lock=_lock;
- (void).cxx_destruct;
- (void)onMemoryWarning:(id)arg1;
- (void)onServiceInit;
- (_Bool)hasAudioPlayingTask;
- (void)removeMinimizeViewControllerWithKey:(id)arg1;
- (void)addMinimizeViewController:(id)arg1 forKey:(id)arg2;
- (id)getMinimizeViewControllerWithKey:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

