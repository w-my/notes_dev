//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNListItemDBManager.h"

#import "QNListItemDBManagerSubClassProtocol.h"

@class NSString;

@interface QNIndexListItemDBManager : QNListItemDBManager <QNListItemDBManagerSubClassProtocol>
{
}

- (id)getFirstPageNews;
- (void)appendListIndexDataWithListItems:(id)arg1 direction:(unsigned long long)arg2;
- (id)getNextPageListItems:(id)arg1;
- (void)saveListIndexData:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

