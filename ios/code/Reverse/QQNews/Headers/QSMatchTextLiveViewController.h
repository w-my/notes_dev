//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRoseLiveRoomBaseChildController.h"

#import "QNImageBrowserDelegate.h"
#import "QSIndexedDataDelegate.h"
#import "QSTextLiveContentCellDelegate.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class NSString, QSTextLiveListData, QSTextLiveLiveSourceListView, UIView;

@interface QSMatchTextLiveViewController : QNRoseLiveRoomBaseChildController <UITableViewDelegate, UITableViewDataSource, QSIndexedDataDelegate, QSTextLiveContentCellDelegate, QNImageBrowserDelegate>
{
    UIView *_vLine;
    _Bool _imageBrowserPresenting;
    _Bool _didReportBossInfo;
    NSString *_matchId;
    QSTextLiveListData *_listData;
    QSTextLiveLiveSourceListView *_liveSourceListView;
}

@property(nonatomic) _Bool didReportBossInfo; // @synthesize didReportBossInfo=_didReportBossInfo;
@property(retain, nonatomic) QSTextLiveLiveSourceListView *liveSourceListView; // @synthesize liveSourceListView=_liveSourceListView;
@property(retain, nonatomic) QSTextLiveListData *listData; // @synthesize listData=_listData;
@property(copy, nonatomic) NSString *matchId; // @synthesize matchId=_matchId;
- (void).cxx_destruct;
- (void)p_setGIFAnimating:(_Bool)arg1;
- (struct CGRect)imageBrowserWillDismissAtImageItem:(id)arg1;
- (void)scrollViewDidScroll:(id)arg1;
- (double)tableView:(id)arg1 heightForHeaderInSection:(long long)arg2;
- (id)tableView:(id)arg1 viewForHeaderInSection:(long long)arg2;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (void)textLiveContentCellDidPressPlayerCard:(id)arg1;
- (void)textLiveContentCellDidPressPage:(id)arg1;
- (void)textLiveContentCellDidPressVideo:(id)arg1 newsId:(id)arg2;
- (void)textLiveContentCellDidPressImage:(id)arg1 withAllImages:(id)arg2 imageView:(id)arg3;
- (_Bool)indexedDataNeedsContinueUpdateWhileNewIndexesComing:(id)arg1;
- (void)clickedLiveSourceList:(id)arg1;
- (void)data:(id)arg1 didFinishLoadWithError:(id)arg2;
- (void)dataWillStartLoad:(id)arg1;
- (void)refreshContentData;
- (_Bool)isEmpty;
- (void)didReceiveMemoryWarning;
- (void)viewDidDisappear:(_Bool)arg1;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (void)loadView;
- (id)initWithParam:(id)arg1;
- (void)dealloc;
- (void)p_hideMenuView;
- (void)scroll2Top;
- (id)getContentScrollView;
- (void)do_deselectedAsCurrentChannel:(id)arg1;
- (void)do_selectedAsCurrentChannel:(id)arg1;
- (void)themeChanged:(long long)arg1;
- (id)viewModel;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

