//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNListViewController.h"

#import "CDataLoaderDelegate.h"

@class CDataLoader, CListDataType, NSMutableDictionary, NSString;

@interface CRootViewController : QNListViewController <CDataLoaderDelegate>
{
    _Bool _hasNextPage;
    CDataLoader *_dataLoader;
    NSMutableDictionary *_webCellDict;
}

@property(nonatomic) _Bool hasNextPage; // @synthesize hasNextPage=_hasNextPage;
@property(retain, nonatomic) NSMutableDictionary *webCellDict; // @synthesize webCellDict=_webCellDict;
@property(retain, nonatomic) CDataLoader *dataLoader; // @synthesize dataLoader=_dataLoader;
- (void).cxx_destruct;
- (id)mergeAds:(id)arg1;
- (_Bool)do_shouldReloadChangeInfo;
- (void)dealloc;
- (void)refreshCurrentChannel;
- (void)showSecondLevelCompleted;
- (_Bool)shouldNeedUpdateData;
- (_Bool)isLastUpdateInvalidated;
- (void)didEnterBackground:(id)arg1;
- (void)didReplaceListItems;
- (void)CDataLoaderDownloadListComplete:(id)arg1;
- (long long)do_numberOfExtraItems;
- (void)CDataLoaderDownloadIndexFailed:(id)arg1;
- (void)CDataLoaderDownloadIndexComplete:(id)arg1;
- (id)configCDataLoaderPostValues:(id)arg1;
- (void)updateData:(id)arg1;
- (id)makeDataLoader;
- (void)doUpdateDataWork:(id)arg1;
- (long long)_getPreloadState;
- (void)dismissWaitingView;
- (void)do_loadingFailed;
- (void)showWaitingView;
- (void)doRefreshListData;
- (void)impGetMore;
- (void)handleDidCleanCacheNotification:(id)arg1;
- (void)cleanupCompletely:(_Bool)arg1;
- (void)_initDataLoader;
- (void)viewDidLoad;
- (id)initWithID:(id)arg1;
@property(readonly, nonatomic) CListDataType *listDataImp; // @dynamic listDataImp;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
