//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSString;

@interface QNPortfolioParam : QNBaseModelObject <NSCopying, NSCoding>
{
    _Bool _stockJump;
    _Bool _isOffLineMode;
    NSString *_stockCode;
    NSString *_stockName;
    NSString *_plateListCode;
    NSString *_plateListName;
    long long _plateListMarketType;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(nonatomic) _Bool isOffLineMode; // @synthesize isOffLineMode=_isOffLineMode;
@property(nonatomic) long long plateListMarketType; // @synthesize plateListMarketType=_plateListMarketType;
@property(copy, nonatomic) NSString *plateListName; // @synthesize plateListName=_plateListName;
@property(copy, nonatomic) NSString *plateListCode; // @synthesize plateListCode=_plateListCode;
@property(nonatomic) _Bool stockJump; // @synthesize stockJump=_stockJump;
@property(copy, nonatomic) NSString *stockName; // @synthesize stockName=_stockName;
@property(copy, nonatomic) NSString *stockCode; // @synthesize stockCode=_stockCode;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end

