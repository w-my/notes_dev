//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CStockBaseData.h"

#import "NSCoding.h"

@interface CStockBasicData : CStockBaseData <NSCoding>
{
    CDStruct_34c354e6 _latestPrice;
    CDStruct_34c354e6 _priceUD;
    CDStruct_34c354e6 _priceUDPercent;
}

@property(nonatomic) CDStruct_34c354e6 priceUDPercent; // @synthesize priceUDPercent=_priceUDPercent;
@property(nonatomic) CDStruct_34c354e6 priceUD; // @synthesize priceUD=_priceUD;
@property(nonatomic) CDStruct_34c354e6 latestPrice; // @synthesize latestPrice=_latestPrice;
- (id)debugDescription;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)dealloc;

@end
