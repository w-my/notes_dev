//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIViewController.h"

#import "UISearchResultsUpdating.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"
#import "WCSearchDelegate.h"

@class NSMutableArray, NSString, UISearchBar, UISearchController, UITableView, UITableViewController, UIView, WCSearcher;

@interface WCSearchDemoImplViewController : MMUIViewController <UITableViewDelegate, UITableViewDataSource, UISearchResultsUpdating, WCSearchDelegate>
{
    _Bool _islastVCNavBarHidden;
    unsigned int _mode;
    WCSearcher *_searcher;
    NSMutableArray *_arrSourceItems;
    NSMutableArray *_arrResultItems;
    UITableView *_tableView;
    UITableViewController *_resultViewController;
    UISearchController *_sysSearchController;
    UIView *_customGuideView;
}

@property(nonatomic) _Bool islastVCNavBarHidden; // @synthesize islastVCNavBarHidden=_islastVCNavBarHidden;
@property(retain, nonatomic) UIView *customGuideView; // @synthesize customGuideView=_customGuideView;
@property(retain, nonatomic) UISearchController *sysSearchController; // @synthesize sysSearchController=_sysSearchController;
@property(retain, nonatomic) UITableViewController *resultViewController; // @synthesize resultViewController=_resultViewController;
@property(retain, nonatomic) UITableView *tableView; // @synthesize tableView=_tableView;
@property(retain, nonatomic) NSMutableArray *arrResultItems; // @synthesize arrResultItems=_arrResultItems;
@property(retain, nonatomic) NSMutableArray *arrSourceItems; // @synthesize arrSourceItems=_arrSourceItems;
@property(retain, nonatomic) WCSearcher *searcher; // @synthesize searcher=_searcher;
@property(nonatomic) unsigned int mode; // @synthesize mode=_mode;
- (void).cxx_destruct;
- (void)updateSearchResultsForSearchController:(id)arg1;
- (void)wcsSearchBarCancelButtonClicked:(id)arg1;
- (void)wcsSearchBar:(id)arg1 textDidChange:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (void)viewDidPopOrDismiss:(_Bool)arg1;
- (void)viewWillPopOrDismiss:(_Bool)arg1;
- (void)viewDidBePoped:(_Bool)arg1;
- (void)viewWillBePoped:(_Bool)arg1;
- (void)viewDidLoad;
@property(readonly, nonatomic) UISearchBar *searchBar;
- (void)configActiveSearch1;
- (void)initGuideView;
- (void)initSearchBar;
- (void)initTableView;
- (void)filter:(id)arg1;
- (void)initSourceItems;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
