//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class UIToolbar, UIVisualEffectView;

@interface QSTranslucentView : UIView
{
    UIToolbar *_toolBar;
    UIVisualEffectView *_visualEffectView;
}

+ (id)darkTranslucentViewWithFrame:(struct CGRect)arg1;
+ (id)translucentViewWithFrame:(struct CGRect)arg1;
@property(retain, nonatomic) UIVisualEffectView *visualEffectView; // @synthesize visualEffectView=_visualEffectView;
@property(retain, nonatomic) UIToolbar *toolBar; // @synthesize toolBar=_toolBar;
- (void).cxx_destruct;
- (id)init;
- (id)initWithFrame:(struct CGRect)arg1;

@end
