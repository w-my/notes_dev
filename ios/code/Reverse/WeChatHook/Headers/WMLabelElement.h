//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WMElement.h"

@class NSMutableArray, NSMutableDictionary, NSString, UIColor, UIImage, WMLabelGenerator;

@interface WMLabelElement : WMElement
{
    long long _textImageIndex;
    _Bool _fontFit;
    _Bool _fontBold;
    _Bool _fontItalics;
    _Bool _supportMultiRow;
    NSString *_fontName;
    double _fontSize;
    UIColor *_color;
    UIColor *_strokeColor;
    double _strokeSize;
    UIColor *_outerStrokeColor;
    double _outerStrokeSize;
    UIColor *_shadowColor;
    long long _vertical;
    long long _alignment;
    double _kern;
    NSString *_shaderBmp;
    NSString *_lastFrameBufferKey;
    WMLabelGenerator *_labelGenerator;
    NSMutableDictionary *_labelFonts;
    NSMutableArray *_textImageArray;
    UIImage *_textBgImage;
    struct CGSize _shadowOffset;
}

@property(retain, nonatomic) UIImage *textBgImage; // @synthesize textBgImage=_textBgImage;
@property(retain, nonatomic) NSMutableArray *textImageArray; // @synthesize textImageArray=_textImageArray;
@property(retain, nonatomic) NSMutableDictionary *labelFonts; // @synthesize labelFonts=_labelFonts;
@property(retain, nonatomic) WMLabelGenerator *labelGenerator; // @synthesize labelGenerator=_labelGenerator;
@property(copy, nonatomic) NSString *lastFrameBufferKey; // @synthesize lastFrameBufferKey=_lastFrameBufferKey;
@property(copy, nonatomic) NSString *shaderBmp; // @synthesize shaderBmp=_shaderBmp;
@property(nonatomic) _Bool supportMultiRow; // @synthesize supportMultiRow=_supportMultiRow;
@property(nonatomic) double kern; // @synthesize kern=_kern;
@property(nonatomic) long long alignment; // @synthesize alignment=_alignment;
@property(nonatomic) long long vertical; // @synthesize vertical=_vertical;
@property(nonatomic) struct CGSize shadowOffset; // @synthesize shadowOffset=_shadowOffset;
@property(retain, nonatomic) UIColor *shadowColor; // @synthesize shadowColor=_shadowColor;
@property(nonatomic) double outerStrokeSize; // @synthesize outerStrokeSize=_outerStrokeSize;
@property(retain, nonatomic) UIColor *outerStrokeColor; // @synthesize outerStrokeColor=_outerStrokeColor;
@property(nonatomic) double strokeSize; // @synthesize strokeSize=_strokeSize;
@property(retain, nonatomic) UIColor *strokeColor; // @synthesize strokeColor=_strokeColor;
@property(retain, nonatomic) UIColor *color; // @synthesize color=_color;
@property(nonatomic) _Bool fontItalics; // @synthesize fontItalics=_fontItalics;
@property(nonatomic) _Bool fontBold; // @synthesize fontBold=_fontBold;
@property(nonatomic) double fontSize; // @synthesize fontSize=_fontSize;
@property(copy, nonatomic) NSString *fontName; // @synthesize fontName=_fontName;
@property(nonatomic) _Bool fontFit; // @synthesize fontFit=_fontFit;
- (void).cxx_destruct;
- (id)getImage;
- (void)updateBuffer:(double)arg1;
- (void)dealloc;
- (void)preloadResources:(id)arg1;
- (id)initWithDictionary:(id)arg1 sid:(id)arg2 folder:(id)arg3;
- (id)colorARGBFromString:(id)arg1;
- (id)chineseDefaultName;

@end

