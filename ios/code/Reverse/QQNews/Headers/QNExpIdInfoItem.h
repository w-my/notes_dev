//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSArray, NSString;

@interface QNExpIdInfoItem : QNBaseModelObject <NSCopying, NSCoding>
{
    NSString *_childNo;
    NSString *_child;
    NSString *_childName;
    NSArray *_expIdList;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(copy, nonatomic) NSArray *expIdList; // @synthesize expIdList=_expIdList;
@property(copy, nonatomic) NSString *childName; // @synthesize childName=_childName;
@property(copy, nonatomic) NSString *child; // @synthesize child=_child;
@property(copy, nonatomic) NSString *childNo; // @synthesize childNo=_childNo;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (_Bool)isValid;

@end

