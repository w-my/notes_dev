//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class NSString, UIImageView, UILabel;

@interface QSMatchLivePropsPriceFloatView : UIView
{
    UIImageView *_priceIcon;
    UILabel *_priceLabel;
}

@property(retain, nonatomic) UILabel *priceLabel; // @synthesize priceLabel=_priceLabel;
@property(retain, nonatomic) UIImageView *priceIcon; // @synthesize priceIcon=_priceIcon;
- (void).cxx_destruct;
@property(copy, nonatomic) NSString *price; // @dynamic price;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

@end

