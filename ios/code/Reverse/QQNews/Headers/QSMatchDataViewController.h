//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSMenuContainerViewController.h"

#import "QSBaseDataDelegate.h"

@class NSArray, NSString, QSMatchDataTabData;

@interface QSMatchDataViewController : QSMenuContainerViewController <QSBaseDataDelegate>
{
    QSMatchDataTabData *_tabData;
    NSArray *_menuViewChannelList;
}

+ (Class)menuViewClass;
@property(retain, nonatomic) NSArray *menuViewChannelList; // @synthesize menuViewChannelList=_menuViewChannelList;
@property(retain, nonatomic) QSMatchDataTabData *tabData; // @synthesize tabData=_tabData;
- (void).cxx_destruct;
- (id)viewControllerAtIndex:(long long)arg1;
- (void)data:(id)arg1 didFinishLoadWithError:(id)arg2;
- (void)dataWillStartLoad:(id)arg1;
- (void)backButtonClickedInMenu:(id)arg1;
- (_Bool)shouldShowMenuView;
- (void)refresh;
- (void)refreshContentData;
- (void)do_reloadData;
- (_Bool)isEmpty;
- (void)clickLeftNaviButton:(id)arg1;
- (void)didReceiveMemoryWarning;
- (Class)tabDataClass;
- (void)viewDidLoad;
- (void)initialSettings;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
