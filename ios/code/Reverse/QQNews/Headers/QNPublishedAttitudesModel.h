//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSString;

@interface QNPublishedAttitudesModel : NSObject
{
    _Bool _hasPublishedAttitudesParms;
    NSArray *_list;
    NSString *_cArticleId;
    long long _lastSetType;
    long long _supportCount;
}

@property(nonatomic) _Bool hasPublishedAttitudesParms; // @synthesize hasPublishedAttitudesParms=_hasPublishedAttitudesParms;
@property(nonatomic) long long supportCount; // @synthesize supportCount=_supportCount;
@property(nonatomic) long long lastSetType; // @synthesize lastSetType=_lastSetType;
@property(copy, nonatomic) NSString *cArticleId; // @synthesize cArticleId=_cArticleId;
@property(retain, nonatomic) NSArray *list; // @synthesize list=_list;
- (void).cxx_destruct;
- (id)init;

@end

