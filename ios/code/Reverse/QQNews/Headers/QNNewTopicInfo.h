//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSArray;

@interface QNNewTopicInfo : QNBaseModelObject <NSCopying, NSCoding>
{
    NSArray *_lastTopic;
    long long _newCount;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(nonatomic) long long newCount; // @synthesize newCount=_newCount;
@property(copy, nonatomic) NSArray *lastTopic; // @synthesize lastTopic=_lastTopic;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end

