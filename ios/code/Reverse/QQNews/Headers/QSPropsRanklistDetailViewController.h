//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRootViewController.h"

#import "QSPropsRanklistDetailCellDelegate.h"
#import "QSPropsRanklistKickOffDataDelegate.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class NSString, QSMatchItem, QSPropsRanklistDetailRankListItem, QSPropsRanklistDetailRankListRankItem, QSPropsRanklistNormalKickOffData, UITableView;

@interface QSPropsRanklistDetailViewController : QNRootViewController <UITableViewDelegate, UITableViewDataSource, QSPropsRanklistDetailCellDelegate, QSPropsRanklistKickOffDataDelegate>
{
    _Bool _beatAble;
    _Bool _showSegmentedControl;
    _Bool _hasScroll;
    QSMatchItem *_matchItem;
    NSString *_mid;
    NSString *_targetCode;
    QSPropsRanklistDetailRankListItem *_propsRanklistDetailRankListItem;
    NSString *_scrollToUserId;
    UITableView *_tableView;
    QSPropsRanklistNormalKickOffData *_propsRanklistKickOffData;
    QSPropsRanklistDetailRankListRankItem *_kickedOffRankItem;
}

@property(nonatomic) _Bool hasScroll; // @synthesize hasScroll=_hasScroll;
@property(retain, nonatomic) QSPropsRanklistDetailRankListRankItem *kickedOffRankItem; // @synthesize kickedOffRankItem=_kickedOffRankItem;
@property(retain, nonatomic) QSPropsRanklistNormalKickOffData *propsRanklistKickOffData; // @synthesize propsRanklistKickOffData=_propsRanklistKickOffData;
@property(retain, nonatomic) UITableView *tableView; // @synthesize tableView=_tableView;
@property(copy, nonatomic) NSString *scrollToUserId; // @synthesize scrollToUserId=_scrollToUserId;
@property(nonatomic) _Bool showSegmentedControl; // @synthesize showSegmentedControl=_showSegmentedControl;
@property(nonatomic) _Bool beatAble; // @synthesize beatAble=_beatAble;
@property(retain, nonatomic) QSPropsRanklistDetailRankListItem *propsRanklistDetailRankListItem; // @synthesize propsRanklistDetailRankListItem=_propsRanklistDetailRankListItem;
@property(copy, nonatomic) NSString *targetCode; // @synthesize targetCode=_targetCode;
@property(copy, nonatomic) NSString *mid; // @synthesize mid=_mid;
@property(retain, nonatomic) QSMatchItem *matchItem; // @synthesize matchItem=_matchItem;
- (void).cxx_destruct;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (void)reorderRanklistWithKickedOffUserId:(id)arg1 kickOffInfo:(id)arg2;
- (void)propsRanklistKickOffDataDidDismissSuccessAnimation:(id)arg1;
- (void)propsRanklistKickOffData:(id)arg1 didFinishWithError:(id)arg2;
- (void)kickOffButtonDidTapInPropsRanklistDetailCell:(id)arg1;
- (void)refreshFinish;
- (void)viewDidLoad;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (id)initWithParam:(id)arg1;
- (void)initialSettings;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(nonatomic) __weak id <QSPropsRanklistDetailViewControllerDelegate> delegate; // @dynamic delegate;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

