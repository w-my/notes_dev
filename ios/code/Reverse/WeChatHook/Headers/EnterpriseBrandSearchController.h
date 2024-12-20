//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "IEnterpriseBrandContactMgrExt.h"
#import "WCDataSearchDelegate.h"
#import "WCSearchDelegate.h"

@class NSArray, NSMutableArray, NSString;

@interface EnterpriseBrandSearchController : MMObject <IEnterpriseBrandContactMgrExt, WCSearchDelegate, WCDataSearchDelegate>
{
    NSString *_brandUserName;
    NSString *_searchText;
    NSMutableArray *_aryResult;
    NSArray *_arySubContact;
    _Bool _isActive;
    id <EnterpriseBrandSearchControllerDelegate> _delegate;
}

@property(nonatomic) __weak id <EnterpriseBrandSearchControllerDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (id)getViewController;
- (id)getMMSearchBar;
- (id)makeContactCell:(id)arg1 tableView:(id)arg2;
- (void)onEnterpriseBrandContactDeleted:(id)arg1;
- (void)onEnterpriseBrandContactChanged:(id)arg1;
- (void)wcsWillDismissSearch:(id)arg1;
- (void)wcsWillPresentSearch:(id)arg1;
- (void)didSearchViewTableSelect:(id)arg1;
- (double)heightForSearchViewTable:(id)arg1;
- (double)heightForHeaderInSection:(long long)arg1 ForSearchViewTable:(id)arg2;
- (long long)numberOfRowsInSection:(long long)arg1 ForSearchViewTable:(id)arg2;
- (long long)numberOfSectionsForSearchViewTable:(id)arg1;
- (id)cellForIndex:(id)arg1 ForSearchViewTable:(id)arg2;
- (void)doSearch:(id)arg1 Pre:(_Bool)arg2;
- (void)reloadSubContacts;
- (void)reloadTable;
- (void)initData;
- (void)dealloc;
- (id)initWithBrandUserName:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

