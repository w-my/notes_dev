//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNCommonListController.h"

#import "QNListTopicCellDelegate.h"

@class NSString, QNMySubTagTopicListApi, QNMySubscribeHeaderView, QNMySubscribeSmallEmptyHeaderView, QNRecommendSectionHeaderView;

@interface QNRecommendListController : QNCommonListController <QNListTopicCellDelegate>
{
    _Bool _pageHasGotData;
    _Bool _shouldCheckRefresh;
    _Bool _lastLoginState;
    QNRecommendSectionHeaderView *_sectionHeaderView;
    QNMySubscribeHeaderView *_subscribeView;
    QNMySubTagTopicListApi *_refreshSubListRequest;
    QNMySubscribeSmallEmptyHeaderView *_smallEmptyHeaderView;
}

@property(retain, nonatomic) QNMySubscribeSmallEmptyHeaderView *smallEmptyHeaderView; // @synthesize smallEmptyHeaderView=_smallEmptyHeaderView;
@property(retain, nonatomic) QNMySubTagTopicListApi *refreshSubListRequest; // @synthesize refreshSubListRequest=_refreshSubListRequest;
@property(nonatomic) _Bool lastLoginState; // @synthesize lastLoginState=_lastLoginState;
@property(retain, nonatomic) QNMySubscribeHeaderView *subscribeView; // @synthesize subscribeView=_subscribeView;
@property(retain, nonatomic) QNRecommendSectionHeaderView *sectionHeaderView; // @synthesize sectionHeaderView=_sectionHeaderView;
@property(nonatomic) _Bool shouldCheckRefresh; // @synthesize shouldCheckRefresh=_shouldCheckRefresh;
- (void).cxx_destruct;
- (void)mySubscribeHeaderViewDidTapped:(id)arg1;
- (void)p_triggerRefreshSubList;
- (void)_showLoginTip;
- (void)_checkLoginHeaderViewState;
- (void)_checkLoginState;
- (void)scrollViewDidEndDragging:(id)arg1 willDecelerate:(_Bool)arg2;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (void)_packupTableViewHeader:(id)arg1;
- (void)refreshAnimationEnd:(id)arg1;
- (void)refreshAnimationBegin:(id)arg1;
- (void)p_shrinkSubscribeViewAnimated:(_Bool)arg1;
- (void)p_stretchSubscribeViewAnimated:(_Bool)arg1;
- (void)p_showSubscribeView:(id)arg1;
- (void)listTopicCell:(id)arg1 subscribe:(_Bool)arg2;
- (id)tableView:(id)arg1 viewForHeaderInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForHeaderInSection:(long long)arg2;
- (void)openNewsAtIndexPath:(id)arg1;
- (_Bool)p_sortedArrayWithSubNodesAndTopics;
- (id)headerView;
- (void)refreshCurrentChannel;
- (_Bool)_refreshCurrentChannelIfAddedTopic;
- (void)showTopTipsView:(id)arg1;
- (_Bool)canShowJumpToRecommendListTip;
- (void)additionalOperationsAfterLoadModelSuccess:(id)arg1;
- (id)customViewModel;
- (id)customListDataAdapter;
- (id)getContentScrollView;
- (void)p_helpViewShowLogic;
- (void)viewWillAppear:(_Bool)arg1;
- (void)dealloc;
- (id)initWithID:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
