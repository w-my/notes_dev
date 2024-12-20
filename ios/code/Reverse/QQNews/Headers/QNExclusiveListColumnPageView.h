//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "QNPageViewContentViewProtocol.h"
#import "QNReusableObject.h"

@class CAGradientLayer, NSString, UIImageView, UILabel, UIView;

@interface QNExclusiveListColumnPageView : QNThemableView <QNReusableObject, QNPageViewContentViewProtocol>
{
    unsigned long long _contentIndex;
    NSString *_reuseIdentifier;
    UIView *_coverImageViewBackgroundView;
    UIImageView *_coverImageView;
    UILabel *_titleLabel;
    UILabel *_descriptionLabel;
    UIView *_descriptionLabelBackgroundView;
    CAGradientLayer *_coverImageGradientLayer;
}

+ (id)identifier;
+ (struct CGSize)size;
+ (double)pageViewPaddingSpace;
@property(retain, nonatomic) CAGradientLayer *coverImageGradientLayer; // @synthesize coverImageGradientLayer=_coverImageGradientLayer;
@property(retain, nonatomic) UIView *descriptionLabelBackgroundView; // @synthesize descriptionLabelBackgroundView=_descriptionLabelBackgroundView;
@property(retain, nonatomic) UILabel *descriptionLabel; // @synthesize descriptionLabel=_descriptionLabel;
@property(retain, nonatomic) UILabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(retain, nonatomic) UIImageView *coverImageView; // @synthesize coverImageView=_coverImageView;
@property(retain, nonatomic) UIView *coverImageViewBackgroundView; // @synthesize coverImageViewBackgroundView=_coverImageViewBackgroundView;
@property(copy, nonatomic) NSString *reuseIdentifier; // @synthesize reuseIdentifier=_reuseIdentifier;
@property(nonatomic) unsigned long long contentIndex; // @synthesize contentIndex=_contentIndex;
- (void).cxx_destruct;
- (_Bool)p_isIn24Hours:(id)arg1;
- (void)layoutWithData:(id)arg1;
- (void)themeChanged:(long long)arg1;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

