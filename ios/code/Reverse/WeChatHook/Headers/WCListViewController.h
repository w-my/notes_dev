//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIViewController.h"

#import "UINavigationControllerDelegate.h"
#import "WCActionSheetDelegate.h"
#import "WCFacadeExt.h"

@class CContact, NSMutableArray, NSString;

@interface WCListViewController : MMUIViewController <WCActionSheetDelegate, UINavigationControllerDelegate, WCFacadeExt>
{
    _Bool m_isMyWC;
    NSMutableArray *m_arrPhotoDatas;
    CContact *m_contact;
    _Bool m_isNoMoreData;
    id <WCListViewDelegate> m_view;
    unsigned int _startTime;
}

@property(retain, nonatomic) CContact *m_contact; // @synthesize m_contact;
- (void).cxx_destruct;
- (void)onNetworkActivityStatusChanged;
- (void)willDisshow;
- (void)willDisappear;
- (void)willShow;
- (void)willAppear;
- (void)refreshFooter;
- (void)refreshHeader;
- (void)forceReload;
- (void)onHomepageUpdate:(int)arg1 withAdded:(id)arg2 andChanged:(id)arg3 andDeleted:(id)arg4 andTip:(id)arg5;
- (void)reloadData;
- (void)initData:(_Bool)arg1;
- (void)viewDidLayoutSubviews;
- (void)didReceiveMemoryWarning;
- (void)dealloc;
- (void)viewDidLoad;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewDidAppear:(_Bool)arg1;
- (void)initBarItem;
- (void)onDissmiss;
- (void)onOperate:(id)arg1;
- (void)actionSheet:(id)arg1 clickedButtonAtIndex:(long long)arg2;
- (void)viewDidTransitionToNewSize;
- (void)reloadStyle;
- (void)updateNetworkStatus;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

