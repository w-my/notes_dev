//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "PBMessageObserverDelegate.h"

@class NSMutableDictionary, NSString;

@interface WCGroupMgr : MMObject <PBMessageObserverDelegate>
{
    _Bool m_bMemCacheNeedReload;
    NSMutableDictionary *m_groups;
    id <WCGroupMgrExt> m_delegate;
    NSString *m_fromUsrName;
    NSString *m_initFromPath;
    unsigned int m_lastUpdateAllGroupsTime;
}

@property(nonatomic) unsigned int m_lastUpdateAllGroupsTime; // @synthesize m_lastUpdateAllGroupsTime;
@property(retain, nonatomic) NSString *m_initFromPath; // @synthesize m_initFromPath;
@property(retain, nonatomic) NSString *m_fromUsrName; // @synthesize m_fromUsrName;
@property(nonatomic) __weak id <WCGroupMgrExt> m_delegate; // @synthesize m_delegate;
- (void).cxx_destruct;
- (void)MessageReturn:(id)arg1 Event:(unsigned int)arg2;
- (void)onGroupListReturn:(id)arg1 Event:(unsigned int)arg2;
- (void)onGroupMemberOpReturn:(id)arg1 Event:(unsigned int)arg2;
- (void)onGroupOpReturn:(id)arg1 Event:(unsigned int)arg2;
- (void)doGroupListOp:(unsigned int)arg1 withMD5:(id)arg2;
- (void)doGroupMemberOp:(unsigned int)arg1 onGroup:(id)arg2 withGroupName:(id)arg3 withMemberList:(id)arg4 withScene:(int)arg5;
- (void)doGroupMemberOp:(unsigned int)arg1 onGroup:(id)arg2 withGroupName:(id)arg3 withMemberList:(id)arg4;
- (void)doGroupOp:(unsigned int)arg1 onGroup:(id)arg2 withGroupName:(id)arg3;
- (_Bool)tryFuzzDefaultGroup;
- (void)removeMembers:(id)arg1 fromGroup:(id)arg2 withScene:(int)arg3;
- (void)addMembers:(id)arg1 toGroup:(id)arg2 withScene:(int)arg3;
- (void)deleteGroup:(id)arg1;
- (void)localDeleteAllGroups;
- (_Bool)canUpdateAllGroups;
- (void)updateAllGroups;
- (id)getGroupByID:(id)arg1;
- (id)getAllGroups;
- (void)dealloc;
- (id)init;
- (void)clearMD5;
- (void)clearMemoryCache;
- (void)saveData;
- (void)tryLoadData;
- (id)pathForGroupData;

@end

