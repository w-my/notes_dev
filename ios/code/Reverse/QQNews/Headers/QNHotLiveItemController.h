//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRootViewController.h"

#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class NSArray, NSIndexPath, NSString, QNHotLiveItemsApi, QNLayoutTableView, QNLoadingShimmerView;

@interface QNHotLiveItemController : QNRootViewController <UITableViewDelegate, UITableViewDataSource>
{
    CDUnknownBlockType _scrollBlock;
    NSString *_type;
    QNLayoutTableView *_tableView;
    QNHotLiveItemsApi *_request;
    QNLoadingShimmerView *_loadingShimmerView;
    NSArray *_topicItems;
    NSIndexPath *_lastSelectedIndexPath;
}

@property(retain, nonatomic) NSIndexPath *lastSelectedIndexPath; // @synthesize lastSelectedIndexPath=_lastSelectedIndexPath;
@property(copy, nonatomic) NSArray *topicItems; // @synthesize topicItems=_topicItems;
@property(retain, nonatomic) QNLoadingShimmerView *loadingShimmerView; // @synthesize loadingShimmerView=_loadingShimmerView;
@property(retain, nonatomic) QNHotLiveItemsApi *request; // @synthesize request=_request;
@property(retain, nonatomic) QNLayoutTableView *tableView; // @synthesize tableView=_tableView;
@property(copy, nonatomic) NSString *type; // @synthesize type=_type;
@property(copy, nonatomic) CDUnknownBlockType scrollBlock; // @synthesize scrollBlock=_scrollBlock;
- (void).cxx_destruct;
- (void)p_navigateToControllerWithTopicItem:(id)arg1;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forRowAtIndexPath:(id)arg3;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (void)scrollViewDidScroll:(id)arg1;
- (void)updateTableViewOffset:(struct CGPoint)arg1;
- (void)p_configureCellRankIcon:(id)arg1 atIndexPath:(id)arg2;
- (void)p_loadingSuccess;
- (void)p_loadingFailed;
- (void)p_loadTopicItems;
- (void)p_initTableView;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (id)initWithParam:(id)arg1;
- (id)initWithParam:(id)arg1 type:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

