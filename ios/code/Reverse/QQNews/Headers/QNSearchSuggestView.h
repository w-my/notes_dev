//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "UIScrollViewDelegate.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class NSArray, NSString, QNLayoutTableView;

@interface QNSearchSuggestView : QNThemableView <UITableViewDelegate, UITableViewDataSource, UIScrollViewDelegate>
{
    id <QNSearchSuggestViewDelegate> _delegate;
    QNLayoutTableView *_tableView;
    NSArray *_searchSuggestList;
    NSString *_searchValidWord;
}

@property(copy, nonatomic) NSString *searchValidWord; // @synthesize searchValidWord=_searchValidWord;
@property(copy, nonatomic) NSArray *searchSuggestList; // @synthesize searchSuggestList=_searchSuggestList;
@property(retain, nonatomic) QNLayoutTableView *tableView; // @synthesize tableView=_tableView;
@property(nonatomic) __weak id <QNSearchSuggestViewDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)p_showKeyboard:(_Bool)arg1;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (void)scrollViewWillBeginDragging:(id)arg1;
- (void)updateSearchValidWord:(id)arg1;
- (void)updateSearchSuggestList:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
