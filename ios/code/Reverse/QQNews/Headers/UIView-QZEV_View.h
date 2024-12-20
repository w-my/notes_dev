//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@interface UIView (QZEV_View)
- (id)mv_viewController;
- (void)mv_removeAllSubviews;
- (id)mv_addHorizontalLineWithTop:(double)arg1 color:(id)arg2;
- (id)mv_addCheckBoxWithFrame:(struct CGRect)arg1 title:(id)arg2 selected:(_Bool)arg3;
- (id)mv_addDotViewAtPoint:(struct CGPoint)arg1 color:(id)arg2;
- (void)addShadowWithColor:(id)arg1 shadowOffset:(struct CGSize)arg2 shadowOpacity:(double)arg3 shadowRadius:(double)arg4;
- (void)addDefaultShadow;
- (void)addWSShadowEffect;
- (id)mv_addDebugGestureWithTarget:(id)arg1 action:(SEL)arg2;
- (id)mv_addVerticalGradientViewWithFrame:(struct CGRect)arg1 beginColor:(id)arg2 endColor:(id)arg3;
- (id)mv_addBlackVerticalGradientViewWithFrame:(struct CGRect)arg1 beginAlpha:(double)arg2 endAlpha:(double)arg3;
- (id)mv_addCollectionViewWithFrame:(struct CGRect)arg1 layout:(id)arg2 delegate:(id)arg3;
- (id)mv_addButtonWithFrame:(struct CGRect)arg1 target:(id)arg2 action:(SEL)arg3;
- (id)mv_addControlWithFrame:(struct CGRect)arg1 target:(id)arg2 action:(SEL)arg3;
- (id)mv_addImageViewWithFrame:(struct CGRect)arg1 image:(id)arg2;
- (id)mv_addImageViewWithFrame:(struct CGRect)arg1 imageName:(id)arg2;
- (id)mv_addLabelWithFrame:(struct CGRect)arg1 fontSize:(double)arg2 textColor:(id)arg3;
- (id)mv_addLabelWithFrame:(struct CGRect)arg1 fontSize:(double)arg2;
- (id)mv_addLabelWithFrame:(struct CGRect)arg1;
- (id)mv_addQZImageViewWithFrame:(struct CGRect)arg1;
- (id)mv_addViewWithFrame:(struct CGRect)arg1;
@end

