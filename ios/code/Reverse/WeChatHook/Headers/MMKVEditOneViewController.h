//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIViewController.h"

#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class MMTableView, NSString, UITextField;

@interface MMKVEditOneViewController : MMUIViewController <UITableViewDelegate, UITableViewDataSource>
{
    MMTableView *m_tableView;
    UITextField *m_textField;
    int _valueType;
    id <IMMKVEditorExt> _delegate;
    NSString *_mmapID;
    NSString *_key;
    NSString *_readableValue;
}

@property(retain, nonatomic) NSString *readableValue; // @synthesize readableValue=_readableValue;
@property(retain, nonatomic) NSString *key; // @synthesize key=_key;
@property(retain, nonatomic) NSString *mmapID; // @synthesize mmapID=_mmapID;
@property(nonatomic) int valueType; // @synthesize valueType=_valueType;
@property(nonatomic) __weak id <IMMKVEditorExt> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (void)makeCell:(id)arg1 tableCell:(id)arg2 section:(unsigned long long)arg3 row:(unsigned long long)arg4;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (void)initTableView;
- (void)updateWordCount:(id)arg1;
- (void)onSaveText;
- (void)viewDidLoad;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
