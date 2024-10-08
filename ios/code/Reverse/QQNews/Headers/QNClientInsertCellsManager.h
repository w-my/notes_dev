//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, QNListNewsItem;

@interface QNClientInsertCellsManager : NSObject
{
    NSString *_channelId;
    QNListNewsItem *_fakeListItem;
}

@property(retain, nonatomic) QNListNewsItem *fakeListItem; // @synthesize fakeListItem=_fakeListItem;
@property(copy, nonatomic) NSString *channelId; // @synthesize channelId=_channelId;
- (void).cxx_destruct;
- (_Bool)isPlaceHolderIdStr:(id)arg1;
- (void)cleanWatchItemsAndResetClientInsertCellData;
- (void)_resetFakeListItem;
- (void)_setFakeListItemWithItem:(id)arg1;
- (unsigned long long)prepareClientInsertCellData;
- (id)initWithChannel:(id)arg1;

@end

