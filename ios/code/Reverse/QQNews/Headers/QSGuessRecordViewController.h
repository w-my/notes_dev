//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRoseLiveRoomBaseChildController.h"

#import "QSMatchGuessWagerDelegate.h"
#import "QSStatedDataDelegate.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class NSString, QSMatchGuessRecordData;

@interface QSGuessRecordViewController : QNRoseLiveRoomBaseChildController <UITableViewDelegate, UITableViewDataSource, QSStatedDataDelegate, QSMatchGuessWagerDelegate>
{
    NSString *_matchId;
    QSMatchGuessRecordData *_listData;
}

@property(retain, nonatomic) QSMatchGuessRecordData *listData; // @synthesize listData=_listData;
@property(copy, nonatomic) NSString *matchId; // @synthesize matchId=_matchId;
- (void).cxx_destruct;
- (void)guessQuestionCell:(id)arg1 didSelectIndex:(long long)arg2;
- (void)scrollViewDidScroll:(id)arg1;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
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
