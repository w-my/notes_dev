//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRootViewController.h"

#import "QSBaseDataDelegate.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class NSString, QSPlayerRanklistData, UITableView;

@interface QSPlayerMatchDataTabViewController : QNRootViewController <QSBaseDataDelegate, UITableViewDelegate, UITableViewDataSource>
{
    _Bool _isNBA;
    NSString *_tabType;
    NSString *_columnId;
    long long _category;
    QSPlayerRanklistData *_ranklistData;
    UITableView *_tableView;
}

@property(retain, nonatomic) UITableView *tableView; // @synthesize tableView=_tableView;
@property(retain, nonatomic) QSPlayerRanklistData *ranklistData; // @synthesize ranklistData=_ranklistData;
@property(nonatomic) _Bool isNBA; // @synthesize isNBA=_isNBA;
@property(nonatomic) long long category; // @synthesize category=_category;
@property(copy, nonatomic) NSString *columnId; // @synthesize columnId=_columnId;
@property(copy, nonatomic) NSString *tabType; // @synthesize tabType=_tabType;
- (void).cxx_destruct;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForFooterInSection:(long long)arg2;
- (id)tableView:(id)arg1 viewForFooterInSection:(long long)arg2;
- (id)tableView:(id)arg1 viewForHeaderInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForHeaderInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (void)data:(id)arg1 didFinishLoadWithError:(id)arg2;
- (void)dataWillStartLoad:(id)arg1;
- (void)refresh;
- (void)refreshContentData;
- (void)do_reloadData;
- (_Bool)isEmpty;
- (void)viewDidLoad;
- (void)viewWillAppear:(_Bool)arg1;
- (void)commonInit;
- (void)showNavigationBarWhenInit;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

