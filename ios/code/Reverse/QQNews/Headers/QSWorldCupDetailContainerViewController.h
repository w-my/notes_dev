//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSMenuContainerViewController.h"

#import "QSStatedDataDelegate.h"
#import "QSWorldCupDetailContainerShareDelegate.h"

@class NSArray, NSString, QSWorldCupDetailTabData;

@interface QSWorldCupDetailContainerViewController : QSMenuContainerViewController <QSStatedDataDelegate, QSWorldCupDetailContainerShareDelegate>
{
    _Bool _didScrollToTabType;
    NSString *_columId;
    NSString *_tabType;
    NSArray *_menuViewChannelList;
    QSWorldCupDetailTabData *_tabData;
}

+ (Class)menuViewClass;
@property(nonatomic) _Bool didScrollToTabType; // @synthesize didScrollToTabType=_didScrollToTabType;
@property(retain, nonatomic) QSWorldCupDetailTabData *tabData; // @synthesize tabData=_tabData;
@property(retain, nonatomic) NSArray *menuViewChannelList; // @synthesize menuViewChannelList=_menuViewChannelList;
@property(copy, nonatomic) NSString *tabType; // @synthesize tabType=_tabType;
@property(copy, nonatomic) NSString *columId; // @synthesize columId=_columId;
- (void).cxx_destruct;
- (void)showShareButton;
- (void)updateContentViewControllerSinceScrollDidFinish;
- (id)viewControllerAtIndex:(long long)arg1;
- (long long)defaultContentViewControllerIndex;
- (double)contentTopOffSet;
- (double)itemSpaceForMenuView;
- (_Bool)shouldMakeSpaceForLeftButton;
- (_Bool)shouldShowMenuView;
- (void)data:(id)arg1 didFinishLoadWithError:(id)arg2;
- (void)data:(id)arg1 didFinishFinallyWithError:(id)arg2;
- (void)dataWillStartLoad:(id)arg1;
- (void)refresh;
- (void)refreshContentData;
- (void)do_reloadData;
- (_Bool)isEmpty;
- (void)clickRightNaviButton:(id)arg1;
- (void)clickLeftNaviButton:(id)arg1;
- (void)viewDidLoad;
- (void)initialSettings;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
