//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class NSArray, NSAttributedString, NSMutableAttributedString, NSMutableDictionary, NSString, UIColor, UIFont;

@interface QNRichTextLabel : UIView
{
    double _lineHeight;
    struct __CTFont *_ctfont;
    NSString *_text;
    _Bool _needValidateSegments;
    UIFont *_font;
    UIColor *_textColor;
    UIColor *_shadowColor;
    long long _numberOfLines;
    double _kerning;
    double _paragraghSpace;
    double _lastLineRightSpace;
    long long _textAlignment;
    NSString *_emotPattern;
    id <QNRichTextLabelDelegate> _emotDelegate;
    NSAttributedString *_truncationString;
    NSString *_fontName;
    double _fontSize;
    NSArray *_segments;
    NSMutableAttributedString *_attributedText;
    NSMutableDictionary *_backgroundColorWithRanges;
    struct CGSize _shadowOffset;
    struct _NSRange _realDisplayRange;
    struct UIEdgeInsets _padding;
}

+ (struct CGSize)preComputeSize:(id)arg1 fontName:(id)arg2 fontSize:(double)arg3 kern:(double)arg4 lineHeight:(double)arg5 paragraghSpace:(double)arg6 constrainToSize:(struct CGSize)arg7 emotPattern:(id)arg8 emotDelegate:(id)arg9 truncated:(_Bool *)arg10;
+ (struct CGSize)preComputeSize:(id)arg1 fontName:(id)arg2 fontSize:(double)arg3 kern:(double)arg4 lineHeight:(double)arg5 paragraghSpace:(double)arg6 constrainToSize:(struct CGSize)arg7 emotPattern:(id)arg8 emotDelegate:(id)arg9 truncated:(_Bool *)arg10 padding:(struct UIEdgeInsets)arg11;
+ (_Bool)p_isEmotIconByName:(id)arg1 forDelegate:(id)arg2;
+ (id)p_segmentsForText:(id)arg1 emotPattern:(id)arg2 emotDelegate:(id)arg3;
@property(retain, nonatomic) NSMutableDictionary *backgroundColorWithRanges; // @synthesize backgroundColorWithRanges=_backgroundColorWithRanges;
@property(retain, nonatomic) NSMutableAttributedString *attributedText; // @synthesize attributedText=_attributedText;
@property(nonatomic) _Bool needValidateSegments; // @synthesize needValidateSegments=_needValidateSegments;
@property(retain, nonatomic) NSArray *segments; // @synthesize segments=_segments;
@property(nonatomic) double fontSize; // @synthesize fontSize=_fontSize;
@property(retain, nonatomic) NSString *fontName; // @synthesize fontName=_fontName;
@property(nonatomic) struct UIEdgeInsets padding; // @synthesize padding=_padding;
@property(nonatomic) struct _NSRange realDisplayRange; // @synthesize realDisplayRange=_realDisplayRange;
@property(copy, nonatomic) NSAttributedString *truncationString; // @synthesize truncationString=_truncationString;
@property(nonatomic) __weak id <QNRichTextLabelDelegate> emotDelegate; // @synthesize emotDelegate=_emotDelegate;
@property(copy, nonatomic) NSString *emotPattern; // @synthesize emotPattern=_emotPattern;
@property(nonatomic) long long textAlignment; // @synthesize textAlignment=_textAlignment;
@property(nonatomic) double lastLineRightSpace; // @synthesize lastLineRightSpace=_lastLineRightSpace;
@property(nonatomic) double paragraghSpace; // @synthesize paragraghSpace=_paragraghSpace;
@property(nonatomic) double kerning; // @synthesize kerning=_kerning;
@property(nonatomic) long long numberOfLines; // @synthesize numberOfLines=_numberOfLines;
@property(nonatomic) struct CGSize shadowOffset; // @synthesize shadowOffset=_shadowOffset;
@property(retain, nonatomic) UIColor *shadowColor; // @synthesize shadowColor=_shadowColor;
@property(retain, nonatomic) UIColor *textColor; // @synthesize textColor=_textColor;
@property(retain, nonatomic) UIFont *font; // @synthesize font=_font;
- (void).cxx_destruct;
- (void)drawRect:(struct CGRect)arg1;
- (struct CGSize)p_sizeForEmotName:(id)arg1;
- (id)p_imageForEmotName:(id)arg1;
- (_Bool)p_isEmotIconByName:(id)arg1;
- (id)rectFromTextRange:(struct _NSRange)arg1;
- (struct CGSize)sizeThatFits:(struct CGSize)arg1 truncated:(_Bool *)arg2;
- (struct CGSize)sizeThatFits:(struct CGSize)arg1;
@property(copy, nonatomic) NSString *text;
- (id)p_segmentsForText:(id)arg1;
- (void)setFrame:(struct CGRect)arg1;
- (void)setBackgroundColor:(id)arg1 forRange:(struct _NSRange)arg2;
- (void)setFont:(id)arg1 withRange:(struct _NSRange)arg2;
- (void)setTextColor:(id)arg1 withRange:(struct _NSRange)arg2;
- (id)p_attributedTextFromText:(id)arg1;
- (void)setFontWithName:(id)arg1 andSize:(double)arg2;
- (_Bool)p_doSetFontWithName:(id)arg1 andSize:(double)arg2;
@property(nonatomic) double lineHeight;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

@end
