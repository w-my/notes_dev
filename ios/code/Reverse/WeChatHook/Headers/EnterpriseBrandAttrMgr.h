//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "MMService.h"
#import "PBMessageObserverDelegate.h"

@class BannerTips, EnterpriseBrandAttrDB, NSCache, NSString;

@interface EnterpriseBrandAttrMgr : MMService <PBMessageObserverDelegate, MMService>
{
    EnterpriseBrandAttrDB *_db;
    NSCache *_cache;
    BannerTips *_bannerTips;
}

- (void).cxx_destruct;
- (void)MessageReturn:(id)arg1 Event:(unsigned int)arg2;
- (void)handleSetBizEnterpriseAttrToSvr:(id)arg1;
- (void)updateAttrToSvr:(id)arg1 mask:(unsigned int)arg2;
- (void)updateBlockMsgFlagToSvr:(id)arg1 block:(_Bool)arg2;
- (id)getWeworkBannerTips:(long long)arg1;
- (id)handleBizEnterpriseAttr:(id)arg1;
- (void)handleGetBizEnterpriseAttrFromSvr:(id)arg1;
- (_Bool)forceUpdateAttrFromSvr:(id)arg1;
- (_Bool)updateAttrFromSvr:(id)arg1;
- (void)onEnterpriseBrandContactDeleted:(id)arg1;
- (_Bool)needUpdate:(id)arg1;
- (_Bool)setUpdateTimeToCache:(id)arg1;
- (_Bool)setAttrToCache:(id)arg1;
- (void)removeAttrCacheItem:(id)arg1;
- (id)getAttrCacheItem:(id)arg1;
- (void)deleteAttr:(id)arg1;
- (void)incWwExposeTime:(id)arg1;
- (void)setCloseHighLightWw:(id)arg1;
- (_Bool)setAttr:(id)arg1 onProperties:(const SyntaxList_7f15fe8c *)arg2;
- (_Bool)isHighLightWw:(id)arg1;
- (unsigned int)getWwEntryType:(id)arg1;
- (_Bool)isBrandBlockMsg:(id)arg1;
- (unsigned int)getQyUinByUserName:(id)arg1;
- (id)getOrCreateAttrByUserName:(id)arg1;
- (id)getAttrByUserName:(id)arg1;
- (void)dealloc;
- (void)onServiceInit;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

