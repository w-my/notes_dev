//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRootViewController.h"

#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class NSArray, NSString, QNGuestMainParam, QNLayoutTableView, QNNewTopicInfo, QNSubscribeFixPosHeaderView, QNSubscribeParam, UIView;

@interface QNSubscribeListController : QNRootViewController <UITableViewDataSource, UITableViewDelegate>
{
    _Bool _isPersonal;
    QNLayoutTableView *_tableView;
    NSArray *_topicIds;
    NSArray *_subIds;
    NSArray *_topicList;
    NSArray *_hotTopicList;
    NSArray *_subscribeList;
    UIView *_emptyView;
    QNNewTopicInfo *_topicInfo;
    unsigned long long _qaCount;
    unsigned long long _topicListShowCount;
    unsigned long long _pageIndex;
    QNGuestMainParam *_guestMainParam;
    QNSubscribeParam *_subscribeViewParam;
    QNSubscribeFixPosHeaderView *_fixSectionHeader;
    double _sectionTitleOffset2;
    double _sectionTitleOffset3;
    NSString *_sectionTitle2;
    NSString *_sectionTitle3;
}

@property(copy, nonatomic) NSString *sectionTitle3; // @synthesize sectionTitle3=_sectionTitle3;
@property(copy, nonatomic) NSString *sectionTitle2; // @synthesize sectionTitle2=_sectionTitle2;
@property(nonatomic) double sectionTitleOffset3; // @synthesize sectionTitleOffset3=_sectionTitleOffset3;
@property(nonatomic) double sectionTitleOffset2; // @synthesize sectionTitleOffset2=_sectionTitleOffset2;
@property(retain, nonatomic) QNSubscribeFixPosHeaderView *fixSectionHeader; // @synthesize fixSectionHeader=_fixSectionHeader;
@property(retain, nonatomic) QNSubscribeParam *subscribeViewParam; // @synthesize subscribeViewParam=_subscribeViewParam;
@property(retain, nonatomic) QNGuestMainParam *guestMainParam; // @synthesize guestMainParam=_guestMainParam;
@property(nonatomic) _Bool isPersonal; // @synthesize isPersonal=_isPersonal;
@property(nonatomic) unsigned long long pageIndex; // @synthesize pageIndex=_pageIndex;
@property(nonatomic) unsigned long long topicListShowCount; // @synthesize topicListShowCount=_topicListShowCount;
@property(nonatomic) unsigned long long qaCount; // @synthesize qaCount=_qaCount;
@property(retain, nonatomic) QNNewTopicInfo *topicInfo; // @synthesize topicInfo=_topicInfo;
@property(retain, nonatomic) UIView *emptyView; // @synthesize emptyView=_emptyView;
@property(copy, nonatomic) NSArray *subscribeList; // @synthesize subscribeList=_subscribeList;
@property(copy, nonatomic) NSArray *hotTopicList; // @synthesize hotTopicList=_hotTopicList;
@property(copy, nonatomic) NSArray *topicList; // @synthesize topicList=_topicList;
@property(copy, nonatomic) NSArray *subIds; // @synthesize subIds=_subIds;
@property(copy, nonatomic) NSArray *topicIds; // @synthesize topicIds=_topicIds;
@property(retain, nonatomic) QNLayoutTableView *tableView; // @synthesize tableView=_tableView;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)scrollViewDidScroll:(id)arg1;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForFooterInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForHeaderInSection:(long long)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 willDisplayFooterView:(id)arg2 forSection:(long long)arg3;
- (void)tableView:(id)arg1 willDisplayHeaderView:(id)arg2 forSection:(long long)arg3;
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forRowAtIndexPath:(id)arg3;
- (id)tableView:(id)arg1 viewForFooterInSection:(long long)arg2;
- (id)tableView:(id)arg1 viewForHeaderInSection:(long long)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (unsigned long long)getSubscribeTopicShowType;
- (id)p_cachePath;
- (void)p_writeTopicInfo;
- (void)p_loadTopicInfo;
- (id)buildListItemsFromArray:(id)arg1;
- (void)p_handleSubListResponseData:(id)arg1;
- (void)p_handleTopicMoreResponseData:(id)arg1;
- (id)p_sortedArrayWithSubNodes;
- (id)p_sortedArrayWithRecommandTopic:(id)arg1;
- (id)p_sortedArrayWithTopics;
- (void)p_loadDataWithPageIndex:(unsigned long long)arg1;
- (void)p_loadTopicWithTopicIds:(id)arg1;
- (void)p_dismissWaitingView;
- (void)p_showWaitingView;
- (id)getContentScrollView;
- (void)scroll2Top;
- (void)configBarButtons;
- (void)viewDidLoad;
- (void)viewWillAppear:(_Bool)arg1;
- (void)dealloc;
- (id)initWithParam:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
