//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CCarPanFloatViewBase.h"

#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class CCarCityItem, NSString, UILabel, UITableView;

@interface CCarCityListView : CCarPanFloatViewBase <UITableViewDelegate, UITableViewDataSource>
{
    UITableView *_tableView;
    UILabel *_capitalBigShow;
    CCarCityItem *_curSelectCityItem;
    id <CCarCityListViewDelegate> _delegateCityList;
}

@property(nonatomic) __weak id <CCarCityListViewDelegate> delegateCityList; // @synthesize delegateCityList=_delegateCityList;
- (void).cxx_destruct;
- (long long)tableView:(id)arg1 sectionForSectionIndexTitle:(id)arg2 atIndex:(long long)arg3;
- (id)sectionIndexTitlesForTableView:(id)arg1;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForHeaderInSection:(long long)arg2;
- (id)tableView:(id)arg1 viewForHeaderInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (id)getCityNameWithIndexPath:(id)arg1;
- (id)sectionTitleWithIndex:(long long)arg1;
- (id)sectionTitles;
- (long long)getDiscountCityCountWithSection:(long long)arg1;
- (void)captialShowAnimation;
- (void)buildCapitalBigShow;
- (void)buildTableView;
- (void)relaodData;
- (id)initWithFrame:(struct CGRect)arg1 selectCityItem:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

