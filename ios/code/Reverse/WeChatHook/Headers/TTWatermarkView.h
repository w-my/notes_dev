//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class NSMutableAttributedString, UIImage, WMLabelElement;

@interface TTWatermarkView : UIView
{
    WMLabelElement *_element;
    NSMutableAttributedString *_attString;
    UIImage *_textImage;
    struct CGSize _elementSize;
}

@property(retain, nonatomic) UIImage *textImage; // @synthesize textImage=_textImage;
@property(nonatomic) struct CGSize elementSize; // @synthesize elementSize=_elementSize;
@property(retain, nonatomic) NSMutableAttributedString *attString; // @synthesize attString=_attString;
@property(retain, nonatomic) WMLabelElement *element; // @synthesize element=_element;
- (void).cxx_destruct;
- (id)getImageWithBmp:(id)arg1;
- (void)drawInContext:(struct CGContext *)arg1;
- (struct CGSize)getAttributedStringHeightWithString:(id)arg1 widthValue:(double)arg2;
- (struct CGSize)getAttributedStringHeightWithString:(id)arg1 widthValue:(double)arg2 heightValue:(double)arg3;
- (CDStruct_912cb5d2)getRangeWithFontSize:(double)arg1 Path:(struct CGPath *)arg2;
- (struct __CTFont *)createFontWithName:(id)arg1 fontSize:(double)arg2 isBold:(_Bool)arg3;
- (id)getAttributedString:(id)arg1;
- (_Bool)isValidateString:(id)arg1;
- (id)initWithElement:(id)arg1;

@end
