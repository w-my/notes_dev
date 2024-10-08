//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class NSArray, NSAttributedString, NSDictionary, NSMutableArray, NSString, UIColor;

@interface QNSimpleCoreTextView : UIView
{
    _Bool _sameAttributedSubStringInNewLine;
    _Bool _textChanged;
    id <QNSimpleCoreTextViewDelegate> _delegate;
    UIColor *_highlightColor;
    NSString *_text;
    struct __CTFramesetter *_framesetter;
    NSAttributedString *_attributedString;
    NSArray *_rangesInAttributedString;
    NSMutableArray *_attributes;
    NSDictionary *_touchedData;
}

+ (unsigned long long)crc32Key:(id)arg1 attributes:(id)arg2 constrainedToSize:(struct CGSize)arg3 attributedSubStringInNewLine:(_Bool)arg4;
+ (void)purgeQNSimpleCoreTextCache;
+ (void)initialize;
@property(retain, nonatomic) NSDictionary *touchedData; // @synthesize touchedData=_touchedData;
@property(retain, nonatomic) NSMutableArray *attributes; // @synthesize attributes=_attributes;
@property(retain, nonatomic) NSArray *rangesInAttributedString; // @synthesize rangesInAttributedString=_rangesInAttributedString;
@property(nonatomic) _Bool textChanged; // @synthesize textChanged=_textChanged;
@property(retain, nonatomic) NSAttributedString *attributedString; // @synthesize attributedString=_attributedString;
@property(nonatomic) struct __CTFramesetter *framesetter; // @synthesize framesetter=_framesetter;
@property(copy, nonatomic) NSString *text; // @synthesize text=_text;
@property(nonatomic) _Bool sameAttributedSubStringInNewLine; // @synthesize sameAttributedSubStringInNewLine=_sameAttributedSubStringInNewLine;
@property(retain, nonatomic) UIColor *highlightColor; // @synthesize highlightColor=_highlightColor;
@property(nonatomic) __weak id <QNSimpleCoreTextViewDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)removeAllHighlightView;
- (void)touchesEnded:(id)arg1 withEvent:(id)arg2;
- (void)touchesCancelled:(id)arg1 withEvent:(id)arg2;
- (void)touchesMoved:(id)arg1 withEvent:(id)arg2;
- (void)touchesBegan:(id)arg1 withEvent:(id)arg2;
- (void)updateFramesetterIfNeeded;
- (void)fitToSuggestedHeight;
- (struct CGSize)suggestedSizeConstrainedToSize:(struct CGSize)arg1;
- (id)dataForPoint:(struct CGPoint)arg1 activeRects:(id *)arg2;
- (void)setText:(id)arg1 andAttributes:(id)arg2;
- (void)drawRect:(struct CGRect)arg1;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

@end

