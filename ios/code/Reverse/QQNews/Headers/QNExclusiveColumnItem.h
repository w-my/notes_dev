//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSString;

@interface QNExclusiveColumnItem : QNBaseModelObject <NSCopying, NSCoding>
{
    _Bool _isFollow;
    NSString *_chlname;
    NSString *_chlid;
    NSString *_desc;
    NSString *_icon;
    NSString *_uin;
    NSString *_intro;
    NSString *_lastArtUpdate;
    NSString *_subCount;
    NSString *_thumbnail;
    long long _msgEntry;
    NSString *_updateFrequency;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
+ (id)parseSelectedItemsFromArray:(id)arg1;
@property(nonatomic) _Bool isFollow; // @synthesize isFollow=_isFollow;
@property(copy, nonatomic) NSString *updateFrequency; // @synthesize updateFrequency=_updateFrequency;
@property(nonatomic) long long msgEntry; // @synthesize msgEntry=_msgEntry;
@property(copy, nonatomic) NSString *thumbnail; // @synthesize thumbnail=_thumbnail;
@property(copy, nonatomic) NSString *subCount; // @synthesize subCount=_subCount;
@property(copy, nonatomic) NSString *lastArtUpdate; // @synthesize lastArtUpdate=_lastArtUpdate;
@property(copy, nonatomic) NSString *intro; // @synthesize intro=_intro;
@property(copy, nonatomic) NSString *uin; // @synthesize uin=_uin;
@property(copy, nonatomic) NSString *icon; // @synthesize icon=_icon;
@property(copy, nonatomic) NSString *desc; // @synthesize desc=_desc;
@property(copy, nonatomic) NSString *chlid; // @synthesize chlid=_chlid;
@property(copy, nonatomic) NSString *chlname; // @synthesize chlname=_chlname;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (id)convertToCSubscribeListItemNode;

@end
