//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

#import "CCarBrandSerialListViewDelegate.h"
#import "CCarHotBrandCellDelegate.h"
#import "CCarPanFloatViewBaseDelegate.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class CCarBrandListItem, CCarBrandSerialListView, NSString, UILabel, UITableView;

@interface CCarBrandListView : UIView <UITableViewDataSource, UITableViewDelegate, CCarHotBrandCellDelegate, CCarBrandSerialListViewDelegate, CCarPanFloatViewBaseDelegate>
{
    UITableView *_tableView;
    CCarBrandSerialListView *_serialListView;
    id <CCarBrandListViewDelegate> _delegate;
    CCarBrandListItem *_brandListData;
    UIView *_maskView;
    UILabel *_capitalBigShow;
}

@property(retain, nonatomic) UILabel *capitalBigShow; // @synthesize capitalBigShow=_capitalBigShow;
@property(retain, nonatomic) UIView *maskView; // @synthesize maskView=_maskView;
@property(retain, nonatomic) CCarBrandListItem *brandListData; // @synthesize brandListData=_brandListData;
@property(nonatomic) __weak id <CCarBrandListViewDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) CCarBrandSerialListView *serialListView; // @synthesize serialListView=_serialListView;
@property(retain, nonatomic) UITableView *tableView; // @synthesize tableView=_tableView;
- (void).cxx_destruct;
- (void)panView:(id)arg1 endWithXoffset:(double)arg2;
- (void)panView:(id)arg1 translateXoffset:(double)arg2;
- (void)didSelectSerialItem:(id)arg1;
- (void)didClickWithBrandItem:(id)arg1;
- (id)sectionIndexTitlesForTableView:(id)arg1;
- (long long)tableView:(id)arg1 sectionForSectionIndexTitle:(id)arg2 atIndex:(long long)arg3;
- (id)tableView:(id)arg1 viewForHeaderInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForHeaderInSection:(long long)arg2;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (void)tapMaskViewAction:(id)arg1;
- (void)showSerilaListView:(_Bool)arg1;
- (void)captialShowAnimation;
- (void)initCapitalBigShow;
- (id)initWithFrame:(struct CGRect)arg1 andDataList:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

