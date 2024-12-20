//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@interface QNWalletBalance : QNBaseModelObject <NSCopying, NSCoding>
{
    long long _diamond;
    long long _kCoin;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(nonatomic) long long kCoin; // @synthesize kCoin=_kCoin;
@property(nonatomic) long long diamond; // @synthesize diamond=_diamond;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end

