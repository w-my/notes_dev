//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRootViewController.h"

#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class NSMutableDictionary, NSString, QNCityData, QNCityListLoader, UITableView, cityListLocationButton;

@interface QNCityListController : QNRootViewController <UITableViewDataSource, UITableViewDelegate>
{
    CDUnknownBlockType _actionAfterUserSelectCity;
    UITableView *_tableView;
    cityListLocationButton *_locationButton;
    QNCityListLoader *_loader;
    NSMutableDictionary *_sectionUnfoldStatus;
    unsigned long long _cityListControllerType;
    QNCityData *_locationCity;
}

@property(retain, nonatomic) QNCityData *locationCity; // @synthesize locationCity=_locationCity;
@property(nonatomic) unsigned long long cityListControllerType; // @synthesize cityListControllerType=_cityListControllerType;
@property(retain, nonatomic) NSMutableDictionary *sectionUnfoldStatus; // @synthesize sectionUnfoldStatus=_sectionUnfoldStatus;
@property(retain, nonatomic) QNCityListLoader *loader; // @synthesize loader=_loader;
@property(retain, nonatomic) cityListLocationButton *locationButton; // @synthesize locationButton=_locationButton;
@property(retain, nonatomic) UITableView *tableView; // @synthesize tableView=_tableView;
@property(copy, nonatomic) CDUnknownBlockType actionAfterUserSelectCity; // @synthesize actionAfterUserSelectCity=_actionAfterUserSelectCity;
- (void).cxx_destruct;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 viewForHeaderInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForHeaderInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (id)p_getCurrentCityName;
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forRowAtIndexPath:(id)arg3;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (void)p_setLocationButton;
- (void)p_locationItemSelected:(id)arg1;
- (void)onBack:(id)arg1;
- (void)configTitleView;
- (void)configBarButtons;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (void)dealloc;
- (id)initWithParam:(id)arg1 type:(unsigned long long)arg2;
- (id)initWithParam:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
