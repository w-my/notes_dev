//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAbstractModelBuilder.h"

@interface QNPortfolioParamBuilder : QNAbstractModelBuilder
{
}

+ (id)builderWithModelCopy:(id)arg1;
+ (id)builder;
- (id)setIsOffLineMode:(_Bool)arg1;
- (_Bool)isOffLineMode;
- (id)setPlateListMarketType:(long long)arg1;
- (long long)plateListMarketType;
- (id)setPlateListName:(id)arg1;
- (id)plateListName;
- (id)setPlateListCode:(id)arg1;
- (id)plateListCode;
- (id)setStockJump:(_Bool)arg1;
- (_Bool)stockJump;
- (id)setStockName:(id)arg1;
- (id)stockName;
- (id)setStockCode:(id)arg1;
- (id)stockCode;
- (id)build;
- (id)do_createModelObject;
- (id)initWithModelCopy:(id)arg1;
- (id)init;

@end
