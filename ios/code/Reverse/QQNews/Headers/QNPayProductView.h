//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class QNPayProduct, UIButton;

@interface QNPayProductView : QNThemableView
{
    UIButton *_productButton;
    UIButton *_costButton;
    QNPayProduct *_product;
}

@property(retain, nonatomic) QNPayProduct *product; // @synthesize product=_product;
@property(retain, nonatomic) UIButton *costButton; // @synthesize costButton=_costButton;
@property(retain, nonatomic) UIButton *productButton; // @synthesize productButton=_productButton;
- (void).cxx_destruct;
- (void)resetWithSelected:(_Bool)arg1;
- (void)updateWithProduct:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

