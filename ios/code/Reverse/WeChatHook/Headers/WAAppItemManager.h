//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "MMService.h"
#import "MMTipsViewControllerDelegate.h"
#import "WAAppOperateLogicDelegate.h"

@class NSString, WAAppOperateLogic;

@interface WAAppItemManager : MMService <WAAppOperateLogicDelegate, MMTipsViewControllerDelegate, MMService>
{
    WAAppOperateLogic *m_operateLogic;
    unsigned int m_localUpdateTimeOfLastVisibleItem;
    unsigned int m_updateTimeOfFirstVisibleItem;
    unsigned int m_remoteUpdateTimeOfLastVisibleItem;
    unsigned int m_biggestUpdateTimeOfStarItem;
    unsigned int m_showOutErrTime;
}

+ (unsigned long long)getAppUserStateByUsername:(id)arg1;
+ (unsigned long long)getAppUserStateByUsername:(id)arg1 appType:(unsigned int)arg2;
- (void).cxx_destruct;
- (void)saveShowOutInfoToLocal:(id)arg1;
- (id)getShowOutInfoFromLocal;
- (id)fetchLocalShowOutData;
- (void)onGetShowOutDataFromSvr:(id)arg1 errCode:(int)arg2;
- (void)getShowOutItemsFromSvrInScene:(unsigned int)arg1;
- (void)onClickTipsBtn:(id)arg1 Index:(long long)arg2 withText:(id)arg3 withTipsVC:(id)arg4;
- (void)showUserGuideWithSessionId:(id)arg1;
- (void)clearState;
- (id)getCurrentAppStarItemsInLimits:(unsigned int)arg1;
- (_Bool)deleteStarItemFromDatabaseWithAppItem:(id)arg1;
- (_Bool)deleteHistoryItemFromDatabaseWithAppItem:(id)arg1;
- (_Bool)updateStarItemToDatabaseWithItem:(id)arg1;
- (_Bool)updateHistoryItemToDatabaseWithItem:(id)arg1;
- (void)handleUnStarOperation:(id)arg1 errCode:(int)arg2;
- (void)handleStarOperation:(id)arg1 errCode:(int)arg2;
- (void)onOprationExcuted:(id)arg1 errCode:(int)arg2;
- (void)operateStarItemsForReason:(unsigned int)arg1;
- (double)calSortFactorWithPreItem:(id)arg1 nextItem:(id)arg2;
- (void)batchMoveStarItemsWithContext:(id)arg1;
- (void)moveStarItem:(id)arg1 toPositionWithPreItem:(id)arg2 nextItem:(id)arg3 inScene:(unsigned int)arg4;
- (void)unStarWeAppItem:(id)arg1 inScene:(unsigned int)arg2;
- (void)starWeAppItem:(id)arg1 toPositionWithPreItem:(id)arg2 nextItem:(id)arg3 inScene:(unsigned int)arg4;
- (void)showStarForbiddenTips;
- (_Bool)checkWeAppCanBeStared:(id)arg1;
- (unsigned int)getStarNumberLimitation;
- (_Bool)isReachStarCountLimit;
- (void)starWeAppItem:(id)arg1 inScene:(unsigned int)arg2;
- (void)saveEditStarResult:(id)arg1;
- (id)getAllAppStarItems;
- (_Bool)isItemStared:(id)arg1;
- (void)onDeleteWeAppItemSilently:(id)arg1;
- (void)onDeleteWeAppItem:(id)arg1;
- (void)onOpenWeAppItem:(id)arg1 scene:(unsigned long long)arg2 sessionId:(id)arg3 isAlreadyRunning:(_Bool)arg4 isUpdateMainFrameTask:(_Bool)arg5;
- (id)getLatestAppListItemWithMaxUpdateTime:(unsigned int)arg1 minUpdateTime:(unsigned int)arg2 includeStar:(_Bool)arg3;
- (id)getLatestAppListItemWithMaxUpdateTime:(unsigned int)arg1 minUpdateTime:(unsigned int)arg2;
- (id)getLatestAppListItemOverUpdateTime:(unsigned int)arg1 includeStar:(_Bool)arg2;
- (id)getLatestAppListItemOverUpdateTime:(unsigned int)arg1;
- (void)updateFirstVisibleItemUpdateTimeIfNeededWithListItems:(id)arg1;
- (id)getLatestAppListItemWithCount:(unsigned int)arg1 includeStar:(_Bool)arg2;
- (id)getLatestAppListItemWithCount:(unsigned int)arg1;
- (id)getAllAppListItemByUsername:(id)arg1;
- (id)getAllAppListItemsIsIncludeStar:(_Bool)arg1;
- (id)getAllAppListItems;
- (void)reverseArray:(id)arg1;
- (id)preCheckStarAppList:(id)arg1;
- (id)preCheckAppList:(id)arg1;
- (void)onGetLastestAppItemsFromSvrByRecordList:(id)arg1 scene:(unsigned int)arg2 hasMore:(_Bool)arg3 errCode:(int)arg4;
- (void)onGetLastestAppItemsFromSvrByStarList:(id)arg1 scene:(unsigned int)arg2 errCode:(int)arg3;
- (void)onAuthOK;
- (void)onServiceReloadData;
- (void)onServiceClearData;
- (void)onServiceInit;
- (void)getStarAppItemsFromSvrInScene:(unsigned int)arg1;
- (void)getLastestUsageAppItemsFromSvrInScene:(unsigned int)arg1;
- (void)getLastestUsageRecordInfoByUpdateTime:(unsigned int)arg1 inScene:(unsigned int)arg2;
- (void)getLastestUsageRecordInfoByUpdateTime:(unsigned int)arg1;
- (unsigned int)getValidStarBiggestUpdateTime;
- (unsigned int)getValidListTopUpdateTime;
- (void)dealloc;
- (id)init;
- (id)internalGetAllAppContactListItemsWithAppType:(unsigned int)arg1;
- (id)getAllAppContactListItemsWithAppType:(unsigned int)arg1;
- (id)getAllGameAppContactListItems;
- (id)getAllNormalAppContactListItems;
- (id)getAllAppContactListItems;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

