//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIViewController.h"

#import "UIAlertViewDelegate.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"
#import "WCDataSearchDelegate.h"
#import "WCSearchDelegate.h"

@class MMLoadingView, MMTableView, NSObject<MemberDataLogicProtocol>, NSString, UILabel, UIView, WCDataSearcher;

@interface MemberListViewController : MMUIViewController <UITableViewDataSource, UITableViewDelegate, UIAlertViewDelegate, WCSearchDelegate, WCDataSearchDelegate>
{
    MMLoadingView *m_loadingView;
    MMTableView *m_tableView;
    UIView *m_viewLabel;
    UILabel *m_countLabel;
    NSObject<MemberDataLogicProtocol> *m_memberData;
    id <MemberDataDelegate> m_delegate;
    WCDataSearcher *_searcher;
    _Bool m_needIndexBar;
}

@property(nonatomic) _Bool needIndexBar; // @synthesize needIndexBar=m_needIndexBar;
- (void).cxx_destruct;
- (void)tableView:(id)arg1 commitEditingStyle:(long long)arg2 forRowAtIndexPath:(id)arg3;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 editingStyleForRowAtIndexPath:(id)arg2;
- (id)usrNameConvertToOContacts:(id)arg1;
- (void)cancelSearch;
- (void)doSearch:(id)arg1 Pre:(_Bool)arg2;
- (_Bool)hasNoSearchResult;
- (id)viewForFooterInSection:(long long)arg1 ForSearchViewTable:(id)arg2;
- (double)heightForFooterInSection:(long long)arg1 ForSearchViewTable:(id)arg2;
- (void)didSearchViewTableSelect:(id)arg1;
- (double)heightForSearchViewTable:(id)arg1;
- (id)cellForSearchViewTable:(id)arg1 index:(id)arg2;
- (id)cellForHandleVoiceSearchViewTable:(id)arg1 index:(id)arg2;
- (void)makeResultCell:(id)arg1 contact:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 viewForHeaderInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForHeaderInSection:(long long)arg2;
- (id)tableView:(id)arg1 titleForHeaderInSection:(long long)arg2;
- (id)sectionIndexTitlesForTableView:(id)arg1;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (double)cellHeight;
- (void)showContactInfoView:(id)arg1;
- (void)openContactInfoView:(int)arg1;
- (void)setDelegate:(id)arg1;
- (void)setMemberLogic:(id)arg1;
- (void)reloadTable;
- (void)initSearchBar;
- (_Bool)hasIndexBar;
- (void)initTableView;
- (void)initCountLabel:(id)arg1;
- (void)updateCount;
- (_Bool)isSeachActive;
- (void)viewDidLoad;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

