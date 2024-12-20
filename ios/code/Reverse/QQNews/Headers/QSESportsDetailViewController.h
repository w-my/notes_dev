//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSMenuContainerViewController.h"

#import "QSBaseDataDelegate.h"

@class NSArray, NSDictionary, NSString, QSESportsDetailTabData;

@interface QSESportsDetailViewController : QSMenuContainerViewController <QSBaseDataDelegate>
{
    NSDictionary *_sports_ext;
    NSArray *_menuViewChannelList;
    QSESportsDetailTabData *_tabData;
}

+ (Class)menuViewClass;
@property(retain, nonatomic) QSESportsDetailTabData *tabData; // @synthesize tabData=_tabData;
@property(retain, nonatomic) NSArray *menuViewChannelList; // @synthesize menuViewChannelList=_menuViewChannelList;
@property(retain, nonatomic) NSDictionary *sports_ext; // @synthesize sports_ext=_sports_ext;
- (void).cxx_destruct;
- (void)loadContentViewControllerAtIndex:(long long)arg1;
- (id)viewControllerAtIndex:(long long)arg1;
- (double)contentTopOffSet;
- (_Bool)shouldShowMenuView;
- (void)data:(id)arg1 didFinishLoadWithError:(id)arg2;
- (void)data:(id)arg1 didFinishFinallyWithError:(id)arg2;
- (void)dataWillStartLoad:(id)arg1;
- (void)refresh;
- (void)refreshContentData;
- (void)do_reloadData;
- (_Bool)isEmpty;
- (void)clickLeftNaviButton:(id)arg1;
- (void)didReceiveMemoryWarning;
- (void)viewDidLoad;
- (void)configBarButtons;
- (void)configTitleView;
- (void)initialSettings;
- (id)tagName;
- (id)columnId;
- (long long)gameType;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

