//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSArray;

@interface QNPushHistoryResponse : QNBaseModelObject <NSCopying, NSCoding>
{
    _Bool _hasNext;
    double _serverTime;
    NSArray *_newsList;
    NSArray *_countArray;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(copy, nonatomic) NSArray *countArray; // @synthesize countArray=_countArray;
@property(copy, nonatomic) NSArray *newsList; // @synthesize newsList=_newsList;
@property(nonatomic) _Bool hasNext; // @synthesize hasNext=_hasNext;
@property(nonatomic) double serverTime; // @synthesize serverTime=_serverTime;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end
