//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIImageView.h"

@class UILabel;

@interface CCarSliderIndicator : UIImageView
{
    UILabel *_labelIndicator;
    long long _indicatorValue;
}

@property(readonly, nonatomic) long long indicatorValue; // @synthesize indicatorValue=_indicatorValue;
- (void).cxx_destruct;
- (void)setIndicatorValue:(long long)arg1 limitMaxValue:(long long)arg2;
- (id)init;

@end

