//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface CPortfolioListData : NSObject
{
    _Bool _isAlert;
    NSString *_stockCode;
    double _avgBuyPrice;
    double _avgBuyCount;
    NSString *_stockType;
    NSString *_stockComment;
    double _totalBuyCount;
}

@property(nonatomic) _Bool isAlert; // @synthesize isAlert=_isAlert;
@property(nonatomic) double totalBuyCount; // @synthesize totalBuyCount=_totalBuyCount;
@property(copy, nonatomic) NSString *stockComment; // @synthesize stockComment=_stockComment;
@property(copy, nonatomic) NSString *stockType; // @synthesize stockType=_stockType;
@property(nonatomic) double avgBuyCount; // @synthesize avgBuyCount=_avgBuyCount;
@property(nonatomic) double avgBuyPrice; // @synthesize avgBuyPrice=_avgBuyPrice;
@property(copy, nonatomic) NSString *stockCode; // @synthesize stockCode=_stockCode;
- (void)dealloc;
- (id)init;

@end

