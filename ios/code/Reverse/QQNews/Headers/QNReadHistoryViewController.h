//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNFavoriteHistoryBaseController.h"

@class NSArray, NSMutableArray;

@interface QNReadHistoryViewController : QNFavoriteHistoryBaseController
{
    NSMutableArray *_showListData;
}

@property(retain, nonatomic) NSMutableArray *showListData; // @synthesize showListData=_showListData;
- (void).cxx_destruct;
- (void)do_selectedAsCurrentChannel:(id)arg1;
- (void)lastinEditIndexPathEnd;
- (void)tableView:(id)arg1 didEndEditingRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 willBeginEditingRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 editingStyleForRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forRowAtIndexPath:(id)arg3;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (void)themeChanged:(long long)arg1;
- (void)hideHelpImage;
- (void)showHelpImage;
- (void)selectAllItem;
- (void)deleteSelectItems;
- (_Bool)isEmpty;
- (void)onCancelEdit;
- (void)onEdit;
- (_Bool)isToday:(id)arg1;
- (void)buildData;
- (void)didReceiveMemoryWarning;
- (id)getContentScrollView;
- (void)viewWillAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (id)initWithParam:(id)arg1;

// Remaining properties
@property(retain, nonatomic) NSArray *listItems;

@end

