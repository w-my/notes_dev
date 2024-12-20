//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNListModel.h"

@class NSString;

@interface CListDataType : QNListModel
{
    _Bool _isChannel;
    NSString *_key;
}

+ (id)mergrListItemWithIndex:(id)arg1 listItems:(id)arg2;
@property _Bool isChannel; // @synthesize isChannel=_isChannel;
@property(copy) NSString *key; // @synthesize key=_key;
- (void).cxx_destruct;
- (void)dealloc;
- (id)getIndexFromListItems;
- (id)getAllListThumbURLs:(long long)arg1;
- (id)getAllIDs:(long long)arg1;
- (void)setArticleReadFlagWithID:(id)arg1;
- (void)setItemAsRead:(id)arg1;
- (void)cleanReadFlag:(id)arg1;
- (void)popReadFlag:(id)arg1;
- (void)pushReadFlag:(id)arg1;
- (id)listDataFilePath;
- (id)initWithKey:(id)arg1 isChannel:(_Bool)arg2;

@end

