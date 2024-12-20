//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSString;

@interface QNUserInterestItem : QNBaseModelObject <NSCopying, NSCoding>
{
    _Bool _interest;
    _Bool _exposured;
    NSString *_idStr;
    NSString *_name;
    double _reportTime;
    long long _plusImageIndex;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
+ (_Bool)filterUserInterestItem:(id)arg1 inNewsId:(id)arg2;
+ (id)parseUserInterestItems:(id)arg1;
@property(nonatomic) long long plusImageIndex; // @synthesize plusImageIndex=_plusImageIndex;
@property(nonatomic) double reportTime; // @synthesize reportTime=_reportTime;
@property(nonatomic) _Bool exposured; // @synthesize exposured=_exposured;
@property(nonatomic) _Bool interest; // @synthesize interest=_interest;
@property(copy, nonatomic) NSString *name; // @synthesize name=_name;
@property(copy, nonatomic) NSString *idStr; // @synthesize idStr=_idStr;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (_Bool)isValid;

@end

