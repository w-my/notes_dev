//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSString;

@interface QNExclusiveListItem : QNBaseModelObject <NSCopying, NSCoding>
{
    _Bool _isCover;
    NSString *_coverPictureUrl;
    NSString *_articleSource;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(nonatomic) _Bool isCover; // @synthesize isCover=_isCover;
@property(copy, nonatomic) NSString *articleSource; // @synthesize articleSource=_articleSource;
@property(copy, nonatomic) NSString *coverPictureUrl; // @synthesize coverPictureUrl=_coverPictureUrl;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end
