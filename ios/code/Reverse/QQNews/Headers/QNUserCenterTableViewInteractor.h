//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNUserCenterCellDelegate.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class NSString, QNMineTableView, QNRootViewController, QNUserCenterRouter, QNUserCenterViewModel;

@interface QNUserCenterTableViewInteractor : NSObject <QNUserCenterCellDelegate, UITableViewDelegate, UITableViewDataSource>
{
    QNRootViewController *_controller;
    QNMineTableView *_tableView;
    QNUserCenterViewModel *_viewModel;
    QNUserCenterRouter *_router;
}

+ (id)interactorWithController:(id)arg1 tableView:(id)arg2;
@property(retain, nonatomic) QNUserCenterRouter *router; // @synthesize router=_router;
@property(retain, nonatomic) QNUserCenterViewModel *viewModel; // @synthesize viewModel=_viewModel;
@property(nonatomic) __weak QNMineTableView *tableView; // @synthesize tableView=_tableView;
@property(nonatomic) __weak QNRootViewController *controller; // @synthesize controller=_controller;
- (void).cxx_destruct;
- (void)userCenterCell:(id)arg1 needsReloadCell:(id)arg2 inSection:(id)arg3;
- (void)userCenterCell:(id)arg1 willShowCell:(id)arg2 withEntity:(id)arg3;
- (void)userCenterCell:(id)arg1 willShowRemindRedPointForEntity:(id)arg2;
- (void)userCenterCell:(id)arg1 didRequestRouteEntity:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForFooterInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForHeaderInSection:(long long)arg2;
- (void)userCenterModelDidChange;
- (void)dealloc;
- (void)registerCells;
- (id)initWithController:(id)arg1 tableView:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
