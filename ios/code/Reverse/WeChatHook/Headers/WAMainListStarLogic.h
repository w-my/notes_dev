//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "WAAppItemManagerExtension.h"

@class NSMutableArray, NSMutableSet, NSString;

@interface WAMainListStarLogic : MMObject <WAAppItemManagerExtension>
{
    NSMutableArray *_starItems;
    id <WAMainListStarLogicDelegate> _delegate;
    NSMutableSet *_starSet;
}

@property(retain, nonatomic) NSMutableSet *starSet; // @synthesize starSet=_starSet;
@property(nonatomic) __weak id <WAMainListStarLogicDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) NSMutableArray *starItems; // @synthesize starItems=_starItems;
- (void).cxx_destruct;
- (void)reloadStarItemsAndNotify;
- (void)onWeAppItemMoved:(id)arg1 toPreItem:(id)arg2 nextItem:(id)arg3;
- (void)onWeAppItemUnStared:(id)arg1;
- (void)onWeAppItemStared:(id)arg1;
- (void)onWeAppItemUnStared:(id)arg1 errCode:(int)arg2;
- (void)onWeAppItemStared:(id)arg1 errCode:(int)arg2;
- (void)onWeAppStaredItemsInfoUpdated:(id)arg1 scene:(unsigned int)arg2;
- (_Bool)isItemStaredInLocal:(id)arg1;
- (id)sortStarItems:(id)arg1;
- (void)removeStarItemWithoutCheck:(id)arg1;
- (void)insertStarItemWithoutCheck:(id)arg1 atIndex:(unsigned long long)arg2;
- (_Bool)insertStarItem:(id)arg1 atIndex:(unsigned long long)arg2;
- (unsigned long long)removeStarItem:(id)arg1;
- (_Bool)batchMoveStarItemsWithContext:(id)arg1;
- (_Bool)moveStarItem:(id)arg1 fromIndex:(unsigned long long)arg2 toIndex:(unsigned long long)arg3 inScene:(unsigned int)arg4;
- (_Bool)deleteStarItem:(id)arg1 inScene:(unsigned int)arg2;
- (_Bool)unstarItem:(id)arg1 inScene:(unsigned int)arg2;
- (id)starItem:(id)arg1 toPosition:(unsigned long long)arg2 inScene:(unsigned int)arg3;
- (id)starItem:(id)arg1 inScene:(unsigned int)arg2;
- (_Bool)hasStarData;
- (unsigned int)getStarNumberLimitation;
- (_Bool)isReachStarCountLimit;
- (_Bool)isItemStared:(id)arg1;
- (void)saveEditResult;
- (void)fetchRemoteStarDataWithScene:(unsigned int)arg1;
- (void)fetchLocalStarData;
- (void)unregisterExtensions;
- (void)registerExtensions;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
