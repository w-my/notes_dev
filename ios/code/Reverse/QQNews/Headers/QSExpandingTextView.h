//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

#import "UITextViewDelegate.h"

@class NSObject<QSExpandingTextViewDelegate>, NSString, UIColor, UIFont, UIImageView, UILabel, UITextView;

@interface QSExpandingTextView : UIView <UITextViewDelegate>
{
    UITextView *internalTextView;
    UIImageView *textViewBackgroundImage;
    int minimumHeight;
    int maximumHeight;
    int maxNumberOfLines;
    int minNumberOfLines;
    NSObject<QSExpandingTextViewDelegate> *delegate;
    NSString *text;
    UIFont *font;
    UIColor *textColor;
    long long textAlignment;
    struct _NSRange selectedRange;
    _Bool editable;
    unsigned long long dataDetectorTypes;
    long long returnKeyType;
    _Bool forceSizeUpdate;
    NSString *placeholder;
    UILabel *placeholderLabel;
    double currentHeight;
    double animationDuration;
    struct UIEdgeInsets contentInset;
    _Bool animateHeightChange;
    _Bool _notAutoAdjustContentOffset;
}

@property(nonatomic) _Bool notAutoAdjustContentOffset; // @synthesize notAutoAdjustContentOffset=_notAutoAdjustContentOffset;
@property double animationDuration; // @synthesize animationDuration;
@property(nonatomic) int maximumHeight; // @synthesize maximumHeight;
@property(retain, nonatomic) UILabel *placeholderLabel; // @synthesize placeholderLabel;
@property(copy, nonatomic) NSString *placeholder; // @synthesize placeholder;
@property(retain, nonatomic) UIImageView *textViewBackgroundImage; // @synthesize textViewBackgroundImage;
@property _Bool animateHeightChange; // @synthesize animateHeightChange;
@property __weak NSObject<QSExpandingTextViewDelegate> *delegate; // @synthesize delegate;
@property(retain, nonatomic) UITextView *internalTextView; // @synthesize internalTextView;
- (void).cxx_destruct;
- (void)textViewDidChangeSelection:(id)arg1;
- (_Bool)textView:(id)arg1 shouldChangeTextInRange:(struct _NSRange)arg2 replacementText:(id)arg3;
- (void)textViewDidEndEditing:(id)arg1;
- (void)textViewDidBeginEditing:(id)arg1;
- (_Bool)textViewShouldEndEditing:(id)arg1;
- (_Bool)textViewShouldBeginEditing:(id)arg1;
- (void)scrollRangeToVisible:(struct _NSRange)arg1;
- (_Bool)hasText;
@property(nonatomic) unsigned long long dataDetectorTypes; // @synthesize dataDetectorTypes;
- (_Bool)enablesReturnKeyAutomatically;
- (void)setEnablesReturnKeyAutomatically:(_Bool)arg1;
@property(nonatomic) long long returnKeyType; // @synthesize returnKeyType;
@property(nonatomic, getter=isEditable) _Bool editable; // @synthesize editable;
@property(nonatomic) _Bool isScrollable;
@property(nonatomic) struct _NSRange selectedRange; // @synthesize selectedRange;
@property(nonatomic) long long textAlignment; // @synthesize textAlignment;
- (id)backgroundColor;
- (void)setBackgroundColor:(id)arg1;
@property(nonatomic) __weak UIColor *textColor; // @synthesize textColor;
@property(nonatomic) __weak UIFont *font; // @synthesize font;
@property(nonatomic) __weak NSString *text; // @synthesize text;
- (_Bool)isFirstResponder;
- (_Bool)resignFirstResponder;
- (_Bool)becomeFirstResponder;
- (void)touchesEnded:(id)arg1 withEvent:(id)arg2;
- (void)growDidStop;
- (void)resizeTextView:(long long)arg1;
- (double)measureHeight;
- (void)refreshHeight;
- (void)textViewDidChange:(id)arg1;
- (void)setMinHeight:(int)arg1;
- (int)minNumberOfLines;
- (void)setMinNumberOfLines:(int)arg1;
- (void)setMaxHeight:(int)arg1;
@property(nonatomic) int maxNumberOfLines; // @synthesize maxNumberOfLines;
- (struct UIEdgeInsets)contentInset;
- (void)layoutSubviews;
- (void)clearText;
- (struct CGSize)sizeThatFits:(struct CGSize)arg1;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)dealloc;
- (void)hidePlaceholder;
- (void)showPlaceholder;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

