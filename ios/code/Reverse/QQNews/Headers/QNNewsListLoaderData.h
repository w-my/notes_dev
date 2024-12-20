//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSArray, NSDictionary, QNLiveVideoForcastItem, QNNewsListHasReadFlags, QNNewsListIndexMetadata;

@interface QNNewsListLoaderData : QNBaseModelObject <NSCopying, NSCoding>
{
    _Bool _morePage;
    _Bool _isCacheData;
    QNLiveVideoForcastItem *_liveVideoForecastItem;
    QNNewsListIndexMetadata *_indexMetadata;
    NSArray *_newsItems;
    QNNewsListHasReadFlags *_hasReadFlags;
    unsigned long long _dataType;
    NSDictionary *_extras;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(copy, nonatomic) NSDictionary *extras; // @synthesize extras=_extras;
@property(nonatomic) unsigned long long dataType; // @synthesize dataType=_dataType;
@property(nonatomic) _Bool isCacheData; // @synthesize isCacheData=_isCacheData;
@property(nonatomic) _Bool morePage; // @synthesize morePage=_morePage;
@property(retain, nonatomic) QNNewsListHasReadFlags *hasReadFlags; // @synthesize hasReadFlags=_hasReadFlags;
@property(copy, nonatomic) NSArray *newsItems; // @synthesize newsItems=_newsItems;
@property(retain, nonatomic) QNNewsListIndexMetadata *indexMetadata; // @synthesize indexMetadata=_indexMetadata;
@property(retain, nonatomic) QNLiveVideoForcastItem *liveVideoForecastItem; // @synthesize liveVideoForecastItem=_liveVideoForecastItem;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (_Bool)hasRead:(id)arg1;
- (_Bool)isDataValid;

@end

