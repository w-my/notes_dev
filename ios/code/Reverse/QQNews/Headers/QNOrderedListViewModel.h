//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBasicListViewModel.h"

#import "QNBasicListViewModelSubclassProtocol.h"

@class NSString;

@interface QNOrderedListViewModel : QNBasicListViewModel <QNBasicListViewModelSubclassProtocol>
{
}

+ (id)loadMoreCgiNameForChannelID:(id)arg1;
+ (id)loadIndexCgiNameForChannelID:(id)arg1;
- (id)customListModel;
- (id)customListDataManager;
- (id)customListLoader;
- (void)p_addCommonParamsToDict:(id)arg1;
- (id)p_postKeyValuesForPullupToRefresh;
- (id)p_postKeyValuesForRefreshAll;
- (id)loaderContextForPullupToRefresh;
- (id)loaderContextForPulldownToRefresh;
- (id)loaderContextForRefreshAll;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

