//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CSubscribeNode.h"

#import "KBListItemInstancePotocol.h"
#import "NSCoding.h"
#import "NSCopying.h"
#import "QNSortableProtocol.h"
#import "QNSortableTimeProtocol.h"

@class NSArray, NSString;

@interface CSubscribeListItemNode : CSubscribeNode <NSCoding, NSCopying, QNSortableProtocol, QNSortableTimeProtocol, KBListItemInstancePotocol>
{
    _Bool _pushOpen;
    NSString *_sicon;
    NSString *_recommend;
    long long _unReadCount;
    double _updateTime;
    NSString *_articleTitle;
    long long _index;
    unsigned long long _subMenuSwitch;
    NSString *_surl;
    NSArray *_newsList;
}

+ (id)buildFromCardNode:(id)arg1;
@property(copy, nonatomic) NSArray *newsList; // @synthesize newsList=_newsList;
@property(nonatomic) _Bool pushOpen; // @synthesize pushOpen=_pushOpen;
@property(copy, nonatomic) NSString *surl; // @synthesize surl=_surl;
@property(nonatomic) unsigned long long subMenuSwitch; // @synthesize subMenuSwitch=_subMenuSwitch;
@property(nonatomic) long long index; // @synthesize index=_index;
@property(copy, nonatomic) NSString *articleTitle; // @synthesize articleTitle=_articleTitle;
@property(nonatomic) double updateTime; // @synthesize updateTime=_updateTime;
@property(nonatomic) long long unReadCount; // @synthesize unReadCount=_unReadCount;
@property(copy, nonatomic) NSString *recommend; // @synthesize recommend=_recommend;
@property(copy, nonatomic) NSString *sicon; // @synthesize sicon=_sicon;
- (void).cxx_destruct;
- (_Bool)isMyself;
- (_Bool)checkValid;
- (id)vipIconUrl;
- (id)initWithUserItem:(id)arg1;
- (id)initWithUserInfo:(id)arg1;
- (id)initWithInfo:(id)arg1;
@property(copy, nonatomic) NSString *idStr; // @dynamic idStr;
- (_Bool)isEqualTo:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
