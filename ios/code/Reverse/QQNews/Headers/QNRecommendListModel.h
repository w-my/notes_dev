//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "KBBasicListModel.h"

#import "KBSubClassBasicModelProtocol.h"

@class NSString;

@interface QNRecommendListModel : KBBasicListModel <KBSubClassBasicModelProtocol>
{
    unsigned long long _refreshSeparatorStyle;
}

@property(nonatomic) unsigned long long refreshSeparatorStyle; // @synthesize refreshSeparatorStyle=_refreshSeparatorStyle;
- (id)_getRealNeedToDelIndexsWithDelIndexes:(id)arg1;
- (void)_reSortStickedArticles:(_Bool)arg1 isInFirstPage:(_Bool)arg2;
- (void)_removeUnStickedNonstandardAds;
- (void)_removeSeparatorItemsInArray:(id)arg1;
- (void)_mergeTopicDataToListItems:(id)arg1 extendData:(id)arg2 replaceAll:(_Bool)arg3;
- (void)_removeTopicData;
- (void)tryToAddTopicNewsWithTopicItem:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (unsigned long long)indexOfInsertHead;
- (void)didDeleteItems:(id)arg1 atIndexPaths:(id)arg2 callBack:(CDUnknownBlockType)arg3;
- (void)willDeleteItemAtIndexPaths:(id)arg1;
- (void)p_updateFirstNewsState;
- (void)didAppendListItemsAtHeadOrTail:(_Bool)arg1 extendData:(id)arg2;
- (void)willAppendListItemsAtHeadOrTail:(_Bool)arg1 newListItems:(id)arg2 extendData:(id)arg3;
- (void)didReplaceAllListItemsWithExtendData:(id)arg1;
- (void)willReplaceAllListItems:(id)arg1 extendData:(id)arg2;
- (id)initWithChannelId:(id)arg1 refreshModel:(unsigned long long)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
