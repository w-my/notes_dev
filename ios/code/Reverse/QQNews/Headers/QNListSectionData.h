//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class KBChannelListIndexData, NSArray, NSString;

@interface QNListSectionData : QNBaseModelObject <NSCopying, NSCoding>
{
    NSString *_idStr;
    NSString *_sectionName;
    KBChannelListIndexData *_indexData;
    NSArray *_listItems;
    long long _column;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(nonatomic) long long column; // @synthesize column=_column;
@property(copy, nonatomic) NSArray *listItems; // @synthesize listItems=_listItems;
@property(retain, nonatomic) KBChannelListIndexData *indexData; // @synthesize indexData=_indexData;
@property(copy, nonatomic) NSString *sectionName; // @synthesize sectionName=_sectionName;
@property(copy, nonatomic) NSString *idStr; // @synthesize idStr=_idStr;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end
