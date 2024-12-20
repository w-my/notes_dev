//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "MMService.h"

@class NSHashTable, NSObject<OS_dispatch_queue>, NSString;

@interface WCPlayerMgr : MMService <MMService>
{
    NSHashTable *_hashTable;
    NSObject<OS_dispatch_queue> *_audioSessionQueue;
}

@property(retain, nonatomic) NSObject<OS_dispatch_queue> *audioSessionQueue; // @synthesize audioSessionQueue=_audioSessionQueue;
@property(retain, nonatomic) NSHashTable *hashTable; // @synthesize hashTable=_hashTable;
- (void).cxx_destruct;
- (_Bool)hasAnyUnMutePlayingPlayer;
- (_Bool)hasAnyPlayerViewObj;
- (void)removePlayerObj:(id)arg1;
- (void)addPlayerObj:(id)arg1;
- (id)shareQueue;
- (void)onServiceInit;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

