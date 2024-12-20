//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSArray, NSString;

@interface KBChannelListIndexData : QNBaseModelObject <NSCopying, NSCoding>
{
    NSString *_channel;
    double _timeStamp;
    double _remoteTimestamp;
    NSArray *_indexItems;
    NSArray *_allIndexItems;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(copy, nonatomic) NSArray *allIndexItems; // @synthesize allIndexItems=_allIndexItems;
@property(copy) NSArray *indexItems; // @synthesize indexItems=_indexItems;
@property(nonatomic) double remoteTimestamp; // @synthesize remoteTimestamp=_remoteTimestamp;
@property(nonatomic) double timeStamp; // @synthesize timeStamp=_timeStamp;
@property(copy, nonatomic) NSString *channel; // @synthesize channel=_channel;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (void)insertIndexItem:(id)arg1 atIndex:(unsigned long long)arg2;
- (unsigned long long)removeIndexItemWithValidFilter:(CDUnknownBlockType)arg1;
- (id)nextPageIdsWithCurrentIds:(id)arg1 count:(unsigned long long)arg2;
- (id)allIndexInfos;
- (id)allFocusArticleIds;
- (id)allListItemIDsForIndexMode;
- (id)allListItemIDS;

@end

