//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRootViewController.h"

#import "QNListenNewsPlayerDelegate.h"
#import "QNNewsSubMenuViewDelegate.h"
#import "UICollectionViewDataSource.h"
#import "UICollectionViewDelegate.h"

@class NSString, QNListenNewsTopOpenView, QNNewsSubMenuView, UICollectionView;

@interface QNListenNewsViewController : QNRootViewController <QNNewsSubMenuViewDelegate, UICollectionViewDelegate, UICollectionViewDataSource, QNListenNewsPlayerDelegate>
{
    QNNewsSubMenuView *_subMenuView;
    UICollectionView *_collectionView;
    QNListenNewsTopOpenView *_topOpenView;
    long long _currentIndex;
    _Bool _isScrollToCell;
}

+ (void)pushToNavController:(id)arg1 formIconView:(id)arg2;
- (void).cxx_destruct;
- (void)listenNewsShowTimerNotification:(id)arg1;
- (void)listenNewsShowListNotification:(id)arg1;
- (void)listenNewsDataLoadFinishNotification:(id)arg1;
- (void)listenNewsPlayerStateChangedNotification:(id)arg1;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (void)scrollViewDidScroll:(id)arg1;
- (_Bool)qnNavigationController:(id)arg1 shouldInteractiveGestureRecognizerBegin:(id)arg2;
- (void)reportZhiyinExposureWithChannelID:(id)arg1;
- (void)reportCellExposureWithChannelID:(id)arg1;
- (id)currentCell;
- (void)checkMenuAnimation;
- (unsigned long long)indexOfChannelID:(id)arg1;
- (id)collectionView:(id)arg1 cellForItemAtIndexPath:(id)arg2;
- (void)collectionView:(id)arg1 didEndDisplayingCell:(id)arg2 forItemAtIndexPath:(id)arg3;
- (void)collectionView:(id)arg1 willDisplayCell:(id)arg2 forItemAtIndexPath:(id)arg3;
- (long long)collectionView:(id)arg1 numberOfItemsInSection:(long long)arg2;
- (void)currentChannelButtonDidClicked:(long long)arg1;
- (id)subChannelList;
- (void)newsSubMenuSelected:(id)arg1 lastSelected:(id)arg2;
- (void)pushWithParam:(id)arg1;
- (id)pageTypeForReport;
- (void)onBack:(id)arg1;
- (void)configBarButtons;
- (void)do_reloadData;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (id)initWithParam:(id)arg1;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
