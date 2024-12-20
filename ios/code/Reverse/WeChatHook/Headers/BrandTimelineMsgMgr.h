//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "IContactMgrExt.h"
#import "IMMNewSessionMgrExt.h"
#import "IMMNewSessionMgrFilterExt.h"
#import "IMsgExt.h"
#import "MMImageLoaderObserver.h"
#import "MMKernelExt.h"
#import "MMService.h"
#import "MMSessionRefreshExt.h"
#import "MMTipsViewControllerDelegate.h"
#import "PBMessageObserverDelegate.h"
#import "WXGImportMessageNotification.h"

@class BTOftenReadBizCache, BrandSessionCache, BrandTimelineMsgDB, MMBaseSessionStorage, MemoryMappedKV, NSData, NSMutableArray, NSObject<OS_dispatch_queue>, NSString;

@interface BrandTimelineMsgMgr : MMService <IMMNewSessionMgrFilterExt, WXGImportMessageNotification, MMSessionRefreshExt, IMsgExt, IMMNewSessionMgrExt, IContactMgrExt, MMKernelExt, PBMessageObserverDelegate, MMTipsViewControllerDelegate, MMService, MMImageLoaderObserver>
{
    _Bool _isMigratingData;
    _Bool _needUpdateMainSession;
    _Bool _isOftenReadRankByServer;
    _Bool _isTimelinePageActive;
    _Bool _hasShowFirstGuideLine;
    unsigned int _oftenReadNewMsgTime;
    MemoryMappedKV *_mappedKV;
    BrandTimelineMsgDB *_brandMsgDB;
    MMBaseSessionStorage *_sessionStorage;
    BrandSessionCache *_mainSessionCache;
    NSData *_oldSessionCacheData;
    NSObject<OS_dispatch_queue> *_m_workerThread;
    NSMutableArray *_arrTmpToAddMsg;
    BTOftenReadBizCache *_oftenReadBizCache;
    NSData *_oldOftenReadBizCacheData;
}

@property(nonatomic) _Bool hasShowFirstGuideLine; // @synthesize hasShowFirstGuideLine=_hasShowFirstGuideLine;
@property(nonatomic) _Bool isTimelinePageActive; // @synthesize isTimelinePageActive=_isTimelinePageActive;
@property(nonatomic) unsigned int oftenReadNewMsgTime; // @synthesize oftenReadNewMsgTime=_oftenReadNewMsgTime;
@property(nonatomic) _Bool isOftenReadRankByServer; // @synthesize isOftenReadRankByServer=_isOftenReadRankByServer;
@property(retain, nonatomic) NSData *oldOftenReadBizCacheData; // @synthesize oldOftenReadBizCacheData=_oldOftenReadBizCacheData;
@property(retain, nonatomic) BTOftenReadBizCache *oftenReadBizCache; // @synthesize oftenReadBizCache=_oftenReadBizCache;
@property(retain, nonatomic) NSMutableArray *arrTmpToAddMsg; // @synthesize arrTmpToAddMsg=_arrTmpToAddMsg;
@property(nonatomic) _Bool needUpdateMainSession; // @synthesize needUpdateMainSession=_needUpdateMainSession;
@property(nonatomic) _Bool isMigratingData; // @synthesize isMigratingData=_isMigratingData;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *m_workerThread; // @synthesize m_workerThread=_m_workerThread;
@property(retain, nonatomic) NSData *oldSessionCacheData; // @synthesize oldSessionCacheData=_oldSessionCacheData;
@property(retain, nonatomic) BrandSessionCache *mainSessionCache; // @synthesize mainSessionCache=_mainSessionCache;
@property(retain, nonatomic) MMBaseSessionStorage *sessionStorage; // @synthesize sessionStorage=_sessionStorage;
@property(retain, nonatomic) BrandTimelineMsgDB *brandMsgDB; // @synthesize brandMsgDB=_brandMsgDB;
@property(retain, nonatomic) MemoryMappedKV *mappedKV; // @synthesize mappedKV=_mappedKV;
- (void).cxx_destruct;
- (void)onDeleteSessionOfUser:(id)arg1;
- (void)MessageReturn:(id)arg1 Event:(unsigned int)arg2;
- (void)onModifyContact:(id)arg1;
- (void)onDeleteContact:(id)arg1;
- (void)onFinishMigrate;
- (void)OnDelMsg:(id)arg1 DelAll:(_Bool)arg2;
- (void)OnDelMsg:(id)arg1 MsgWrap:(id)arg2;
- (void)OnGetNewXmlMsg:(id)arg1 Type:(id)arg2 MsgWrap:(id)arg3;
- (void)OnAddMsg:(id)arg1 MsgWrap:(id)arg2;
- (void)onMsgDBInitFinish;
- (void)setDisplayMode:(unsigned int)arg1;
- (unsigned int)getDisplayMode;
- (_Bool)isBrandTimelineOpen;
- (_Bool)isABTestOpen;
- (void)checkIfNeedHandleMsg;
- (void)checkIfNeedMigrate;
- (void)onServiceClearData;
- (void)onMainControllStart;
- (void)onServiceReloadData;
- (void)onServiceInit;
- (void)dealloc;
- (void)clearBrandTimelineData;
- (void)migrateBrandSessionAndMsg2Timeline;
- (_Bool)isFinishMigrateBrandMsg;
- (void)setMigrateFinishFlag:(_Bool)arg1;
- (void)OnUnReadCountChange:(id)arg1;
- (void)clearAllNotificationUnreadStatus;
- (_Bool)setNotificationDelFlag:(id)arg1 msgWrap:(id)arg2;
- (void)deleteUnreadNotificationForSession:(id)arg1;
- (_Bool)deleteNotification:(id)arg1;
- (id)getNotificationFromCreateTime:(unsigned int)arg1 limit:(unsigned int)arg2;
- (id)getUnreadNotificationFromCreateTime:(unsigned int)arg1 limit:(unsigned int)arg2;
- (unsigned int)getNotificationUnreadCountByUserName:(id)arg1;
- (unsigned int)getNotificationUnreadCount;
- (id)getLastUnreadNotification;
- (void)handleNewNotification:(id)arg1;
- (void)ImageDidFail:(id)arg1;
- (void)ImageDidLoadWithData:(id)arg1 Url:(id)arg2;
- (void)downloadReaderWrapsListCoverImageIfNeed:(id)arg1;
- (void)downloadReaderWrapsCoverImageIfNeed:(id)arg1;
- (_Bool)isOpenAdvancedDownloadCover;
- (void)handleNewMsgByTimeline:(id)arg1;
- (_Bool)isListMsgClearUnread;
- (void)setListMsgClearUnread:(_Bool)arg1;
- (void)setStarContactMsgUnreadStatus:(id)arg1;
- (void)clearStarContactMsgUnreadStatus:(id)arg1;
- (void)clearAllTimelineMsgUnreadStatus;
- (unsigned int)getTimelineUnreadMsgCount;
- (unsigned int)getStarUnreadMsgCount;
- (unsigned long long)getDividingLineSequenceId;
- (void)setDividingLineSequenceId:(unsigned long long)arg1;
- (void)setTimelinePageActive:(_Bool)arg1;
- (void)setTimelineMsgBrowsed:(id)arg1;
- (void)setTimelineMsgRead:(id)arg1;
- (void)setTimelineMsgWrap:(id)arg1 unfold:(_Bool)arg2;
- (void)setTimelineMsgWrapExpand:(id)arg1;
- (void)deleteBrandMsg:(id)arg1 msgWrap:(id)arg2;
- (void)deleteBrandSession:(id)arg1;
- (id)getTimelineMsgFromSequenceId:(unsigned long long)arg1 toCreateTime:(unsigned int)arg2 limit:(unsigned int)arg3;
- (id)getTimelineMsgFromSequenceId:(unsigned long long)arg1 toSequenceId:(unsigned long long)arg2 limit:(unsigned int)arg3;
- (id)getTimelineMsgToSequenceId:(unsigned long long)arg1 limit:(unsigned int)arg2;
- (id)getTimelineMsgFromSequenceId:(unsigned long long)arg1 limit:(unsigned int)arg2;
- (id)getNewestTimelineMsgByUserName:(id)arg1;
- (id)getNewestTimelineMsgByUserName:(id)arg1 changeForDisplay:(_Bool)arg2;
- (id)getNewestTimelineMsg;
- (id)getFirstTimelineMsg;
- (id)getFirstStarMsg;
- (id)getLastMsg;
- (_Bool)isContactHasMsgInTime:(unsigned int)arg1 contact:(id)arg2;
- (void)handleDeleteOftenReadContact:(id)arg1;
- (void)handleDeleteOftenReadMsg:(id)arg1;
- (void)handleFetchOftenReadResp:(id)arg1;
- (void)updateOftenReadContactByClickMsg:(id)arg1;
- (void)updateOftenReadContactByEnterSession:(id)arg1;
- (void)updateOftenReadByNewMsg:(id)arg1 userName:(id)arg2;
- (_Bool)isContactOftenRead:(id)arg1;
- (void)fetchOftenReadBizFromSvr;
- (void)asyncUpdateOftenReadContactByLastMsgTime;
- (void)updateOftenReadContactByLastMsgTime;
- (id)getOftenReadBizContactCache:(_Bool)arg1;
- (void)tryLoadOftenReadFromCache;
- (void)saveOftenReadBizCache;
- (id)pathForOftenReadBizCache;
- (void)refreshServiceTriggerToRefresh:(id)arg1;
- (id)isUserHasSpecalSessionInfo:(id)arg1;
- (_Bool)isMessageShouldHandled:(id)arg1;
- (_Bool)isUserShouldHandled:(id)arg1;
- (void)onTimelineAbtestChange:(_Bool)arg1;
- (void)onImportMessageSuccess;
- (void)onRebuildSessionStorage;
- (void)addBrandSessionHolderToSessionList;
- (void)getBrandNotificationPrefixNameFromMsgContent:(id)arg1 getNickName:(id *)arg2 getNewContent:(id *)arg3;
- (id)genMainFrameSessionInfo;
- (_Bool)needShowUnreadCountOnMainSession;
- (void)clearMainSessionCacheRedDot;
- (void)updateMainSessionLatestMsg;
- (void)updateMainSessionCache;
- (void)rebuildMainSessionCacheFromDB;
- (void)tryLoadMainSessionCache;
- (void)saveMainSessionCache;
- (id)lastMessageFromMainSessionCache;
- (id)pathForMainSessionCache;
- (_Bool)isMainSessionCacheValid;
- (void)onUpdateMainSessionByFinishMigration;
- (void)onUpdateMainSessionByDelMsg:(id)arg1 msgWrap:(id)arg2;
- (void)onUpdateMainSessionByDelBrandSession:(id)arg1;
- (void)onUpdateMainSessionByModifyContactIfNeed:(id)arg1;
- (void)onUpdateMainSession;
- (void)innerNotifyDeletedMainSessionCache;
- (void)clearMainSessionRedDot;
- (void)__preProcessRejectRecommendMsg:(id)arg1;
- (void)handleRejectRecommendMsg:(id)arg1;
- (void)handleFetchMsgItemInfoResp:(id)arg1;
- (void)fetchTimelineMsgItemInfo:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

