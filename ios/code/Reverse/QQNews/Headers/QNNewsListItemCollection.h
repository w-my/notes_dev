//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableDictionary, NSObject<QNNewsListIndexDataProtocol>, QNNewsListHasReadFlags;

@interface QNNewsListItemCollection : NSObject
{
    NSMutableDictionary *_items;
    int _lock;
    NSObject<QNNewsListIndexDataProtocol> *_indexApiData;
    QNNewsListHasReadFlags *_hasReadFlags;
}

@property(readonly, nonatomic) QNNewsListHasReadFlags *hasReadFlags; // @synthesize hasReadFlags=_hasReadFlags;
@property(readonly, nonatomic) NSObject<QNNewsListIndexDataProtocol> *indexApiData; // @synthesize indexApiData=_indexApiData;
- (void).cxx_destruct;
- (id)cachedIDs:(id)arg1 missedIDs:(id *)arg2;
- (id)itemsForNewsIDs:(id)arg1 missedIDs:(id *)arg2;
- (void)putNewsItems:(id)arg1;
- (id)initWithIndexApiData:(id)arg1;

@end
