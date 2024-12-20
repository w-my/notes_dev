//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

@class NSMutableArray, NSMutableDictionary;

@interface WAAppOperateLogic : MMObject
{
    NSMutableDictionary *m_operationInfo;
    NSMutableArray *m_starOperations;
    id <WAAppOperateLogicDelegate> _delegate;
}

@property(nonatomic) __weak id <WAAppOperateLogicDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) NSMutableArray *m_starOperations; // @synthesize m_starOperations;
@property(retain, nonatomic) NSMutableDictionary *m_operationInfo; // @synthesize m_operationInfo;
- (void).cxx_destruct;
- (int)transferUpdateWxaRecordReasonFromOperationSyncReason:(unsigned int)arg1;
- (void)operateStarItemsForTransferedReason:(int)arg1;
- (void)operateStarItemsForReason:(unsigned int)arg1;
- (void)operateStarItem:(id)arg1 positionWithPreItem:(id)arg2 nextItem:(id)arg3 actionType:(unsigned int)arg4 inScene:(unsigned int)arg5;
- (void)moveStaredItem:(id)arg1 toPositionWithPreItem:(id)arg2 nextItem:(id)arg3 inScene:(unsigned int)arg4;
- (void)unStarItem:(id)arg1 inScene:(unsigned int)arg2;
- (void)starItem:(id)arg1 toPositionWithPreItem:(id)arg2 nextItem:(id)arg3 inScene:(unsigned int)arg4;
- (void)getShowOutDataFromSvrInScene:(unsigned int)arg1;
- (id)convertShowOutItem2ShowOutItem:(id)arg1;
- (id)convertWxaAppItem2AppItemData:(id)arg1;
- (void)sendRequest:(id)arg1 Retry:(unsigned int)arg2;
- (void)dealloc;
- (void)handleUpdateStarRecord:(id)arg1;
- (void)handleReportRecommendWxa:(id)arg1;
- (void)handleFaildUpdateUsageOperationAsync:(id)arg1;
- (void)handleGetShowOutItemData:(id)arg1;
- (void)handleUpdateWeAppUsageRecord:(id)arg1;
- (void)handleGetWeAppUsageRecord:(id)arg1;
- (void)onCgiResponse:(id)arg1 forEvent:(unsigned int)arg2;
- (void)updateAppUsageToSvrWithOpration:(id)arg1;
- (void)getStarAppItemsFromSvrInScene:(unsigned int)arg1;
- (void)getLastestUsageAppItemsFromSvrInScene:(unsigned int)arg1;
- (void)getLastestAppItemsFormSvrByUpdateTime:(unsigned int)arg1 inScene:(unsigned int)arg2;
- (void)excuteOpration:(id)arg1;
- (void)runAllOperation;
- (void)addAppOperationInRetryQueue:(id)arg1;
- (void)saveStarData;
- (void)saveData;
- (void)fetchData;

@end

