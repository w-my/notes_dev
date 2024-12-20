//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UITableViewController.h"

@class MVMusicCategory;

@interface MVMusicPickerController : UITableViewController
{
    id <MVMusicPickerControllerDelegate> _delegate;
    MVMusicCategory *_category;
}

@property(retain, nonatomic) MVMusicCategory *category; // @synthesize category=_category;
@property(nonatomic) __weak id <MVMusicPickerControllerDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (void)searchMusicItem:(id)arg1;
- (void)resetMusicItem:(id)arg1;
- (void)dismissController:(id)arg1;
- (void)viewDidLoad;
- (id)loadingView;
- (void)setLoadingView:(id)arg1;
- (void)p_popMusicPickerController;
- (void)endRefreshAnimation;
- (void)startRefreshAnimation;
- (void)fetchMusicDatas;
- (void)setupLoadingView;
- (void)setupNaviViews;
- (void)viewDidLoad;

@end

