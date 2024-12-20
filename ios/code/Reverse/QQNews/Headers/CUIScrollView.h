//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIScrollView.h"

#import "CUIScrollViewSubClassProtocol.h"
#import "UIGestureRecognizerDelegate.h"

@class NSMutableSet, NSString;

@interface CUIScrollView : UIScrollView <UIGestureRecognizerDelegate, CUIScrollViewSubClassProtocol>
{
    _Bool _setContentWidthEqualToBoundsWidth;
    _Bool _setContentHeightEqualToBoundsHeight;
    NSMutableSet *_classesOfViewsToDisableCancel;
}

@property(retain, nonatomic) NSMutableSet *classesOfViewsToDisableCancel; // @synthesize classesOfViewsToDisableCancel=_classesOfViewsToDisableCancel;
@property(nonatomic) _Bool setContentHeightEqualToBoundsHeight; // @synthesize setContentHeightEqualToBoundsHeight=_setContentHeightEqualToBoundsHeight;
@property(nonatomic) _Bool setContentWidthEqualToBoundsWidth; // @synthesize setContentWidthEqualToBoundsWidth=_setContentWidthEqualToBoundsWidth;
- (void).cxx_destruct;
- (_Bool)p_checkTouchView:(id)arg1;
- (_Bool)gestureRecognizer:(id)arg1 shouldReceiveTouch:(id)arg2;
- (_Bool)touchesShouldCancelInContentView:(id)arg1;
- (void)setFrame:(struct CGRect)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

