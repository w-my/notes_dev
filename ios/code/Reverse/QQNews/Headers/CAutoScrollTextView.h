//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class NSMutableArray;

@interface CAutoScrollTextView : UIView
{
    _Bool _bIsAutoScrolling;
    _Bool _bNeedAutoScroll;
    double _itemMargin;
    NSMutableArray *_labelArray;
    UIView *_scrollContainer;
}

@property(nonatomic) _Bool bNeedAutoScroll; // @synthesize bNeedAutoScroll=_bNeedAutoScroll;
@property(retain, nonatomic) UIView *scrollContainer; // @synthesize scrollContainer=_scrollContainer;
@property(retain, nonatomic) NSMutableArray *labelArray; // @synthesize labelArray=_labelArray;
@property(nonatomic) double itemMargin; // @synthesize itemMargin=_itemMargin;
- (_Bool)checkNeedAutoScroll:(struct CGRect)arg1;
- (void)autoScrollLayout;
- (void)normalLayout;
- (void)stopAutoScroll;
- (void)startAutoScroll;
- (void)prepare;
- (void)setFrame:(struct CGRect)arg1;
- (void)clearTextLabels;
- (void)addTextLabel:(id)arg1;
- (void)didMoveToWindow;
- (void)applicationDidBecomeActive;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

@end

