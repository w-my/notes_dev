//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSIndexPath, NSString;

@interface QNListExtendCellInfo : QNBaseModelObject <NSCopying, NSCoding>
{
    NSIndexPath *_indexPath;
    NSString *_idStr;
    long long _picShowType;
    long long _articleType;
    struct CGRect _cellFrame;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(nonatomic) long long articleType; // @synthesize articleType=_articleType;
@property(nonatomic) long long picShowType; // @synthesize picShowType=_picShowType;
@property(copy, nonatomic) NSString *idStr; // @synthesize idStr=_idStr;
@property(retain, nonatomic) NSIndexPath *indexPath; // @synthesize indexPath=_indexPath;
@property(nonatomic) struct CGRect cellFrame; // @synthesize cellFrame=_cellFrame;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (id)description;

@end
