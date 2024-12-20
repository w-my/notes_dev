//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRootViewController.h"

#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class NSMutableArray, NSString, QNLayoutTableView, QNLoadingShimmerView, QNQualityCourseMoreViewModel, UIView;

@interface QNQualityCourseListController : QNRootViewController <UITableViewDelegate, UITableViewDataSource>
{
    QNQualityCourseMoreViewModel *_viewModel;
    QNLayoutTableView *_tableView;
    QNLoadingShimmerView *_loadingShimmerView;
    UIView *_tipView;
    NSMutableArray *_reportedItem;
}

@property(retain, nonatomic) NSMutableArray *reportedItem; // @synthesize reportedItem=_reportedItem;
@property(retain, nonatomic) UIView *tipView; // @synthesize tipView=_tipView;
@property(retain, nonatomic) QNLoadingShimmerView *loadingShimmerView; // @synthesize loadingShimmerView=_loadingShimmerView;
@property(retain, nonatomic) QNLayoutTableView *tableView; // @synthesize tableView=_tableView;
@property(retain, nonatomic) QNQualityCourseMoreViewModel *viewModel; // @synthesize viewModel=_viewModel;
- (void).cxx_destruct;
- (void)scrollViewDidScroll:(id)arg1;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (void)scrollViewDidEndDragging:(id)arg1 willDecelerate:(_Bool)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (void)p_exposureReport;
- (void)p_showTipView;
- (void)p_loadingSuccess;
- (void)p_loadingFailed;
- (void)p_requestData;
- (id)getContentScrollView;
- (void)configTitleView;
- (void)configBarButtons;
- (void)onBack:(id)arg1;
- (void)viewDidLoad;
- (id)initWithParam:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

