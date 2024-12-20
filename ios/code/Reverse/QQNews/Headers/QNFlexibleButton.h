//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNEnlargeHitTestButton.h"

@class NSMutableDictionary, UIFont;

@interface QNFlexibleButton : QNEnlargeHitTestButton
{
    NSMutableDictionary *_titleSizeCache;
    unsigned long long _imagePosition;
    double _titleImageSpace;
    UIFont *_titleFont;
}

@property(retain, nonatomic) UIFont *titleFont; // @synthesize titleFont=_titleFont;
@property(nonatomic) double titleImageSpace; // @synthesize titleImageSpace=_titleImageSpace;
@property(nonatomic) unsigned long long imagePosition; // @synthesize imagePosition=_imagePosition;
- (void).cxx_destruct;
- (struct CGSize)p_titleSizeForState:(unsigned long long)arg1;
- (struct CGRect)imageRectForContentRect:(struct CGRect)arg1;
- (struct CGRect)titleRectForContentRect:(struct CGRect)arg1;
- (struct CGRect)contentRectForBounds:(struct CGRect)arg1;
- (void)sizeToFit;
- (struct CGSize)sizeThatFits:(struct CGSize)arg1;
- (void)setImageEdgeInsets:(struct UIEdgeInsets)arg1;
- (void)setTitleEdgeInsets:(struct UIEdgeInsets)arg1;
- (void)setImage:(id)arg1 forState:(unsigned long long)arg2;
- (void)setTitle:(id)arg1 forState:(unsigned long long)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

@end

