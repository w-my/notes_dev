//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBasicListViewModel.h"

#import "QNBasicListViewModelSubclassProtocol.h"

@class NSString;

@interface QNListViewModel : QNBasicListViewModel <QNBasicListViewModelSubclassProtocol>
{
    _Bool _isNewUser;
    NSString *_lastNewsId;
}

@property(nonatomic) _Bool isNewUser; // @synthesize isNewUser=_isNewUser;
@property(copy, nonatomic) NSString *lastNewsId; // @synthesize lastNewsId=_lastNewsId;
- (void).cxx_destruct;
- (void)_removePushDataWithListItems:(id)arg1 direction:(unsigned long long)arg2;
- (void)willAppendListItemsWithResponse:(id)arg1 direction:(unsigned long long)arg2;
- (void)willReplaceAllListItemsWithResponse:(id)arg1;
- (void)willLoadDataWithDirection:(unsigned long long)arg1 cachePolicy:(unsigned long long)arg2;
- (id)customListLoader;
- (id)customListModel;
- (id)customListDataManager;
- (void)p_addRecommendParamForDict:(id)arg1;
- (id)_getPicTypeStringFromBottom;
- (id)_getPicTypeStringFromTop;
- (void)p_addCommonParamsToDict:(id)arg1;
- (id)p_postKeyValuesForPullupToRefresh;
- (id)p_postKeyValuesForPulldownToRefresh;
- (id)p_postKeyValuesForRefreshAll;
- (id)loaderContextForPullupToRefresh;
- (id)loaderContextForPulldownToRefresh;
- (id)loaderContextForRefreshAll;
- (id)initWithChannelID:(id)arg1 parentChannelID:(id)arg2 refreshMode:(unsigned long long)arg3 delegate:(id)arg4;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

