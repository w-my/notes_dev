//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNListViewController.h"

#import "CModelLoaderDelegate.h"

@class CEmptyView, CSubscribeIndexData, NSMutableSet, NSString, QNArrayDataSource, QNSubscribeListLoader;

@interface CSubscribeIndexViewController : QNListViewController <CModelLoaderDelegate>
{
    QNSubscribeListLoader *_listLoader;
    QNArrayDataSource *_tableViewDataSource;
    NSString *_entranceName;
    NSMutableSet *_requestIdsSet;
    CEmptyView *_emptyView;
}

@property(retain, nonatomic) CEmptyView *emptyView; // @synthesize emptyView=_emptyView;
@property(retain, nonatomic) NSMutableSet *requestIdsSet; // @synthesize requestIdsSet=_requestIdsSet;
@property(retain, nonatomic) NSString *entranceName; // @synthesize entranceName=_entranceName;
@property(retain, nonatomic) QNArrayDataSource *tableViewDataSource; // @synthesize tableViewDataSource=_tableViewDataSource;
@property(retain, nonatomic) QNSubscribeListLoader *listLoader; // @synthesize listLoader=_listLoader;
- (void).cxx_destruct;
- (void)dealloc;
- (void)willEnterforeground;
- (void)didEnterBackground:(id)arg1;
- (void)themeChanged:(long long)arg1;
- (void)removeEmptyView;
- (void)showEmptyView;
- (void)showFailedContent;
- (void)showContent;
- (_Bool)modelDataHandler:(id)arg1;
- (void)modelDidFailed:(id)arg1;
- (void)modelDidFinish:(id)arg1;
- (void)startLoadModel;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (void)do_worksBeforeReloadTableView;
- (void)do_handleDidCleanCacheNotification:(id)arg1;
- (void)do_prepareSpecialDataStruct;
- (long long)do_itemCountInSection:(long long)arg1;
- (void)do_configTableViewDataSource;
- (void)doRefreshListData;
- (void)impGetMore;
- (void)onBack:(id)arg1;
@property(readonly, nonatomic) CSubscribeIndexData *listDataImp;
- (void)configBarButtons;
- (void)viewWillAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (id)initWithParam:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

