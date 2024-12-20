//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIViewController.h"

#import "IMsgExt.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"
#import "WCDataSearchDelegate.h"
#import "WCFacadeExt.h"
#import "WCSearchDelegate.h"

@class MMTableView, NSMutableArray, NSMutableDictionary, NSMutableSet, NSString, WCDataSearcher;

@interface WCSelectContactViewController : MMUIViewController <WCSearchDelegate, WCDataSearchDelegate, UITableViewDelegate, UITableViewDataSource, IMsgExt, WCFacadeExt>
{
    MMTableView *m_tableView;
    NSMutableSet *m_setSelectedUsrName;
    NSMutableDictionary *m_dicLocalContactList;
    NSMutableArray *m_arrLocalContactList;
    NSMutableArray *m_arrRecommendContactList;
    NSMutableArray *m_arrSection;
    id <WCSelectContactDelegate> m_delSelect;
    NSMutableArray *m_arrFilterList;
    _Bool m_hasSelectCountLimit;
    unsigned int m_selectCountLimit;
    int _m_fromScene;
    WCDataSearcher *_searcher;
}

@property(retain, nonatomic) WCDataSearcher *searcher; // @synthesize searcher=_searcher;
@property(nonatomic) int m_fromScene; // @synthesize m_fromScene=_m_fromScene;
@property(nonatomic) unsigned int m_selectCountLimit; // @synthesize m_selectCountLimit;
@property(nonatomic) _Bool m_hasSelectCountLimit; // @synthesize m_hasSelectCountLimit;
@property(retain, nonatomic) NSMutableArray *m_arrFilterList; // @synthesize m_arrFilterList;
@property(nonatomic) __weak id <WCSelectContactDelegate> m_delSelect; // @synthesize m_delSelect;
@property(retain, nonatomic) NSMutableArray *m_arrSection; // @synthesize m_arrSection;
@property(retain, nonatomic) NSMutableArray *m_arrRecommendContactList; // @synthesize m_arrRecommendContactList;
@property(retain, nonatomic) NSMutableArray *m_arrLocalContactList; // @synthesize m_arrLocalContactList;
@property(retain, nonatomic) NSMutableDictionary *m_dicLocalContactList; // @synthesize m_dicLocalContactList;
@property(retain, nonatomic) NSMutableSet *m_setSelectedUsrName; // @synthesize m_setSelectedUsrName;
- (void).cxx_destruct;
- (void)wcsSearchBarCancelButtonClicked:(id)arg1;
- (void)wcsSearchBarTextDidBeginEditing:(id)arg1;
- (void)wcsSearchBar:(id)arg1 textDidChange:(id)arg2;
- (void)doSearch:(id)arg1;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 sectionForSectionIndexTitle:(id)arg2 atIndex:(long long)arg3;
- (id)sectionIndexTitlesForTableView:(id)arg1;
- (id)tableView:(id)arg1 viewForHeaderInSection:(long long)arg2;
- (id)tableView:(id)arg1 titleForHeaderInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForHeaderInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (void)makeCell:(id)arg1 tableCell:(id)arg2 section:(unsigned long long)arg3 row:(unsigned long long)arg4;
- (id)GetContactList:(unsigned int)arg1;
- (void)OnReturn;
- (void)onDone:(id)arg1;
- (void)SetSelectedUsrName:(id)arg1;
- (void)initSearchBar;
- (void)initView;
- (void)updateRightBarButton;
- (void)initData;
- (_Bool)IsInSelecteList:(id)arg1;
- (_Bool)IsInRecommendList:(id)arg1;
- (id)parseContactKey:(id)arg1;
- (void)processContact:(id)arg1;
- (void)viewDidLoad;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

