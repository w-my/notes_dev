//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "KBListModelDelegate.h"
#import "UITableViewDataSource.h"

@class KBBasicListModel, KBTableViewCellFactory, NSString, QNReportParam, UITableView;

@interface QNGuessLikeDataAdapter : NSObject <UITableViewDataSource, KBListModelDelegate>
{
    KBTableViewCellFactory *_tableViewCellFactory;
    QNReportParam *_reportParam;
    UITableView *_tableView;
    KBBasicListModel *_listModel;
    long long _type;
}

+ (Class)p_classForListItem:(id)arg1 context:(id)arg2;
@property(nonatomic) long long type; // @synthesize type=_type;
@property(retain, nonatomic) KBBasicListModel *listModel; // @synthesize listModel=_listModel;
@property(retain, nonatomic) UITableView *tableView; // @synthesize tableView=_tableView;
@property(retain, nonatomic) QNReportParam *reportParam; // @synthesize reportParam=_reportParam;
@property(retain, nonatomic) KBTableViewCellFactory *tableViewCellFactory; // @synthesize tableViewCellFactory=_tableViewCellFactory;
- (void).cxx_destruct;
- (id)tableViewCellLayoutContext:(id)arg1 indexPath:(id)arg2;
- (void)listModel:(id)arg1 didInsertItemsAtIndexes:(id)arg2;
- (void)listModel:(id)arg1 didDeleteItemsAtIndexes:(id)arg2;
- (void)listModeldidReplaceAllItems:(id)arg1 animated:(_Bool)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (void)p_initCellFactory;
- (id)initWithListModel:(id)arg1 tableView:(id)arg2 type:(long long)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
