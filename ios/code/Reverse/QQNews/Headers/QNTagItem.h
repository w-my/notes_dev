//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSString;

@interface QNTagItem : QNBaseModelObject <NSCopying, NSCoding>
{
    NSString *_tagName;
    NSString *_tagId;
    NSString *_tagIcon;
    long long _subCount;
    NSString *_stockCode;
    NSString *_kk_tagId;
    NSString *_kk_tagType;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
+ (id)buildWithKKTagItem:(id)arg1;
@property(copy, nonatomic) NSString *kk_tagType; // @synthesize kk_tagType=_kk_tagType;
@property(copy, nonatomic) NSString *kk_tagId; // @synthesize kk_tagId=_kk_tagId;
@property(copy, nonatomic) NSString *stockCode; // @synthesize stockCode=_stockCode;
@property(nonatomic) long long subCount; // @synthesize subCount=_subCount;
@property(copy, nonatomic) NSString *tagIcon; // @synthesize tagIcon=_tagIcon;
@property(copy, nonatomic) NSString *tagId; // @synthesize tagId=_tagId;
@property(copy, nonatomic) NSString *tagName; // @synthesize tagName=_tagName;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (unsigned long long)hash;
- (_Bool)isEqual:(id)arg1;
- (_Bool)isValid;
@property(nonatomic) _Bool isSportType;

@end
