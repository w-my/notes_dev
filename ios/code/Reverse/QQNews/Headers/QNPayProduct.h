//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSString;

@interface QNPayProduct : QNBaseModelObject <NSCopying, NSCoding>
{
    NSString *_itemId;
    long long _diamond;
    long long _money;
    long long _kCoin;
    long long _payItem;
    NSString *_productId;
    long long _buyType;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(nonatomic) long long buyType; // @synthesize buyType=_buyType;
@property(copy, nonatomic) NSString *productId; // @synthesize productId=_productId;
@property(nonatomic) long long payItem; // @synthesize payItem=_payItem;
@property(nonatomic) long long kCoin; // @synthesize kCoin=_kCoin;
@property(nonatomic) long long money; // @synthesize money=_money;
@property(nonatomic) long long diamond; // @synthesize diamond=_diamond;
@property(copy, nonatomic) NSString *itemId; // @synthesize itemId=_itemId;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (_Bool)valid;

@end
