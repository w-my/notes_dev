//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIViewController.h"

#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class NSString, UILabel, UITableView, UIView, WAAppAuthorizationDetailViewModel;

@interface WAAppAuthorizationLocationDetailViewController : MMUIViewController <UITableViewDataSource, UITableViewDelegate>
{
    id <WAAppAuthorizationDetailViewControllerDelegate> _delegate;
    WAAppAuthorizationDetailViewModel *_viewModel;
    UITableView *_authOptionTableView;
    UIView *_headerView;
    UILabel *_detailLabel;
    unsigned long long _authType;
    unsigned long long _userChooseState;
}

@property(nonatomic) unsigned long long userChooseState; // @synthesize userChooseState=_userChooseState;
@property(nonatomic) unsigned long long authType; // @synthesize authType=_authType;
@property(retain, nonatomic) UILabel *detailLabel; // @synthesize detailLabel=_detailLabel;
@property(retain, nonatomic) UIView *headerView; // @synthesize headerView=_headerView;
@property(retain, nonatomic) UITableView *authOptionTableView; // @synthesize authOptionTableView=_authOptionTableView;
@property(retain, nonatomic) WAAppAuthorizationDetailViewModel *viewModel; // @synthesize viewModel=_viewModel;
@property(nonatomic) __weak id <WAAppAuthorizationDetailViewControllerDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (id)makeHeaderView;
- (void)fillWithViewModel:(id)arg1;
- (void)onReturn;
- (void)initCustomNavigationBar;
- (void)viewDidBePoped:(_Bool)arg1;
- (void)viewDidLayoutSubviews;
- (void)initSubViews;
- (void)viewDidLoad;
- (id)initWithAuthType:(unsigned long long)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
