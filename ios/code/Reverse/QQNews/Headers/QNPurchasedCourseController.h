//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRootViewController.h"

#import "QNContentPurchasedCheckAllCoursesViewActionDelegate.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class NSString, QNContentPurchasedCheckAllCoursesView, QNContentPurchasedViewModel, QNListTopTipsView, QNLoadingShimmerView, UITableView;

@interface QNPurchasedCourseController : QNRootViewController <UITableViewDelegate, UITableViewDataSource, QNContentPurchasedCheckAllCoursesViewActionDelegate>
{
    QNListTopTipsView *_topTipsView;
    UITableView *_tableView;
    QNContentPurchasedViewModel *_viewModel;
    QNContentPurchasedCheckAllCoursesView *_checkAllCoursesView;
}

@property(retain, nonatomic) QNContentPurchasedCheckAllCoursesView *checkAllCoursesView; // @synthesize checkAllCoursesView=_checkAllCoursesView;
@property(retain, nonatomic) QNContentPurchasedViewModel *viewModel; // @synthesize viewModel=_viewModel;
@property(retain, nonatomic) UITableView *tableView; // @synthesize tableView=_tableView;
@property(retain, nonatomic) QNListTopTipsView *topTipsView; // @synthesize topTipsView=_topTipsView;
- (void).cxx_destruct;
- (void)checkAllCoursesViewDidTapped;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (void)p_setNotification;
- (void)p_jumpToAllCoursesView;
- (void)p_dismissLoadingView;
- (void)p_showLoadingView;
- (void)p_loadDataWithType:(unsigned long long)arg1;
- (void)p_buildSubviews;
- (void)p_buildLoadAction;
- (void)p_setFooterView;
- (id)getContentScrollView;
- (void)dealloc;
- (void)didReceiveMemoryWarning;
- (void)viewDidLoad;
- (void)viewWillAppear:(_Bool)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(retain, nonatomic) QNLoadingShimmerView *loadingView;
@property(readonly) Class superclass;

@end
