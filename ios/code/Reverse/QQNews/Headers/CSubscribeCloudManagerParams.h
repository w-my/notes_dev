//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSString;

@interface CSubscribeCloudManagerParams : QNBaseModelObject <NSCopying, NSCoding>
{
    NSString *_uid;
    NSString *_version;
    NSString *_chlid;
    NSString *_add;
    NSString *_del;
    unsigned long long _subType;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(nonatomic) unsigned long long subType; // @synthesize subType=_subType;
@property(copy, nonatomic) NSString *del; // @synthesize del=_del;
@property(copy, nonatomic) NSString *add; // @synthesize add=_add;
@property(copy, nonatomic) NSString *chlid; // @synthesize chlid=_chlid;
@property(copy, nonatomic) NSString *version; // @synthesize version=_version;
@property(copy, nonatomic) NSString *uid; // @synthesize uid=_uid;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end
