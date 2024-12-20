//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"

@class NSString;

@interface CPortfolioStockData : NSObject <NSCoding>
{
    _Bool _isAlert;
    int _stockStatus;
    int _stockMarket;
    int _stockType;
    int _stockOrder;
    NSString *_stockCode;
    NSString *_stockName;
    NSString *_stockTypeStr;
    NSString *_typeStr;
    NSString *_marketStr;
    CDStruct_34c354e6 _amount;
    CDStruct_34c354e6 _turnover;
    CDStruct_34c354e6 _value;
    CDStruct_34c354e6 _volume;
    CDStruct_34c354e6 _change;
    CDStruct_34c354e6 _range;
    CDStruct_34c354e6 _price;
}

+ (id)parserPortfolioStockData:(id)arg1;
@property(nonatomic) CDStruct_34c354e6 price; // @synthesize price=_price;
@property(nonatomic) CDStruct_34c354e6 range; // @synthesize range=_range;
@property(nonatomic) CDStruct_34c354e6 change; // @synthesize change=_change;
@property(nonatomic) CDStruct_34c354e6 volume; // @synthesize volume=_volume;
@property(nonatomic) CDStruct_34c354e6 value; // @synthesize value=_value;
@property(nonatomic) CDStruct_34c354e6 turnover; // @synthesize turnover=_turnover;
@property(nonatomic) CDStruct_34c354e6 amount; // @synthesize amount=_amount;
@property(copy, nonatomic) NSString *marketStr; // @synthesize marketStr=_marketStr;
@property(copy, nonatomic) NSString *typeStr; // @synthesize typeStr=_typeStr;
@property(nonatomic) int stockOrder; // @synthesize stockOrder=_stockOrder;
@property(nonatomic) _Bool isAlert; // @synthesize isAlert=_isAlert;
@property(nonatomic) int stockType; // @synthesize stockType=_stockType;
@property(nonatomic) int stockMarket; // @synthesize stockMarket=_stockMarket;
@property(nonatomic) int stockStatus; // @synthesize stockStatus=_stockStatus;
@property(copy, nonatomic) NSString *stockTypeStr; // @synthesize stockTypeStr=_stockTypeStr;
@property(copy, nonatomic) NSString *stockName; // @synthesize stockName=_stockName;
@property(copy, nonatomic) NSString *stockCode; // @synthesize stockCode=_stockCode;
- (void)dealloc;
- (id)debugDescription;
- (id)description;
- (void)updateQuoteDataWithQuote:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithStockCode:(id)arg1 Notes:(id)arg2;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end

