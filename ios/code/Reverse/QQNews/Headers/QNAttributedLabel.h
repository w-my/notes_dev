//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class CALayer, NSAttributedString, NSMutableArray, NSMutableAttributedString, NSParagraphStyle, NSTextCheckingResult, QNAttributedLableConfig, UIColor;

@interface QNAttributedLabel : UIView
{
    _Bool _isObserving;
    struct __CTTypesetter *_typesetterRef;
    NSParagraphStyle *_paragraphStyle;
    _Bool _shouldNeedsDisplay;
    NSTextCheckingResult *_touchedLink;
    NSTextCheckingResult *_originalTouchedLink;
    QNAttributedLableConfig *_config;
    _Bool _autoDetectLinks;
    _Bool _linkHaveUnderLines;
    _Bool _detectingLinks;
    _Bool _linksHaveBeenDetected;
    id <QNAttributedLabelLinkDectectDelegate> _detectLinkDelegate;
    UIColor *_shadowColor;
    unsigned long long _detectLinkTypes;
    UIColor *_linkColor;
    UIColor *_highlightedLinkBackgroundColor;
    long long _lineBreakMode;
    unsigned long long _lineBoundsOption;
    NSMutableArray *_lines;
    CALayer *_endingIconLayer;
    NSMutableAttributedString *_mutableAttributedString;
    NSMutableArray *_detectedLinks;
    struct CGSize _shadowOffset;
}

@property(nonatomic) _Bool linksHaveBeenDetected; // @synthesize linksHaveBeenDetected=_linksHaveBeenDetected;
@property(retain, nonatomic) NSMutableArray *detectedLinks; // @synthesize detectedLinks=_detectedLinks;
@property(retain, nonatomic) NSMutableAttributedString *mutableAttributedString; // @synthesize mutableAttributedString=_mutableAttributedString;
@property(nonatomic) _Bool detectingLinks; // @synthesize detectingLinks=_detectingLinks;
@property(retain, nonatomic) CALayer *endingIconLayer; // @synthesize endingIconLayer=_endingIconLayer;
@property(retain, nonatomic) NSMutableArray *lines; // @synthesize lines=_lines;
@property(nonatomic) unsigned long long lineBoundsOption; // @synthesize lineBoundsOption=_lineBoundsOption;
@property(nonatomic) long long lineBreakMode; // @synthesize lineBreakMode=_lineBreakMode;
@property(retain, nonatomic) UIColor *highlightedLinkBackgroundColor; // @synthesize highlightedLinkBackgroundColor=_highlightedLinkBackgroundColor;
@property(retain, nonatomic) UIColor *linkColor; // @synthesize linkColor=_linkColor;
@property(nonatomic) unsigned long long detectLinkTypes; // @synthesize detectLinkTypes=_detectLinkTypes;
@property(nonatomic) _Bool linkHaveUnderLines; // @synthesize linkHaveUnderLines=_linkHaveUnderLines;
@property(nonatomic) _Bool autoDetectLinks; // @synthesize autoDetectLinks=_autoDetectLinks;
@property(nonatomic) struct CGSize shadowOffset; // @synthesize shadowOffset=_shadowOffset;
@property(retain, nonatomic) UIColor *shadowColor; // @synthesize shadowColor=_shadowColor;
@property(nonatomic) __weak id <QNAttributedLabelLinkDectectDelegate> detectLinkDelegate; // @synthesize detectLinkDelegate=_detectLinkDelegate;
- (void).cxx_destruct;
- (void)p_clearHightlightTextBackground;
- (void)touchesEnded:(id)arg1 withEvent:(id)arg2;
- (void)touchesCancelled:(id)arg1 withEvent:(id)arg2;
- (void)touchesMoved:(id)arg1 withEvent:(id)arg2;
- (void)touchesBegan:(id)arg1 withEvent:(id)arg2;
- (_Bool)p_isPoint:(struct CGPoint)arg1 nearLink:(id)arg2;
- (id)p_linkAtPoint:(struct CGPoint)arg1;
- (void)p_removeObservers;
- (void)p_addObservers;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (id)mutableAttributedStringWithAdditions;
@property(copy, nonatomic) NSAttributedString *attributedString; // @dynamic attributedString;
- (void)sizeToFit;
- (struct CGSize)sizeThatFits:(struct CGSize)arg1;
- (void)drawRect:(struct CGRect)arg1;
- (struct _NSRange)displayAttributedStringRange;
- (void)p_highlightedLinkBackground:(struct CGContext *)arg1;
- (struct CGRect)_boxRectOfLine:(struct __CTLine *)arg1;
- (void)configAttributedLine:(id)arg1;
- (Class)classForAttributedLine;
- (void)p_resetTypesetter;
- (id)_currentConfig;
- (void)p_detectLinks;
- (double)p_contentWidth:(_Bool)arg1;
- (void)forceDisplay;
- (void)p_attributedStringDidChange;
- (void)dealloc;
- (void)p_commonInit;
- (void)awakeFromNib;
- (id)initWithCoder:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)resetAndRecycleEmoji;
- (void)stopEmojiAnimation;
- (void)startEmojiAnimation;

@end

