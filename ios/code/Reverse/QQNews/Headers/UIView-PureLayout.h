//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@interface UIView (PureLayout)
+ (void)al_applyGlobalStateToConstraint:(id)arg1;
+ (void)autoSetIdentifier:(id)arg1 forConstraints:(CDUnknownBlockType)arg2;
+ (id)al_currentGlobalConstraintIdentifier;
+ (id)al_globalConstraintIdentifiers;
+ (void)autoSetPriority:(float)arg1 forConstraints:(CDUnknownBlockType)arg2;
+ (_Bool)al_isExecutingPriorityConstraintsBlock;
+ (float)al_currentGlobalConstraintPriority;
+ (id)al_globalConstraintPriorities;
+ (id)autoCreateConstraintsWithoutInstalling:(CDUnknownBlockType)arg1;
+ (_Bool)al_preventAutomaticConstraintInstallation;
+ (id)al_currentArrayOfCreatedConstraints;
+ (id)al_arraysOfCreatedConstraints;
+ (id)newAutoLayoutView;
- (id)al_alignAttribute:(long long)arg1 toView:(id)arg2 forAxis:(long long)arg3;
- (id)al_commonSuperviewWithView:(id)arg1;
- (void)al_addConstraint:(id)arg1;
- (void)autoRemoveConstraintsAffectingViewAndSubviewsIncludingImplicitConstraints:(_Bool)arg1;
- (void)autoRemoveConstraintsAffectingViewAndSubviews;
- (void)autoRemoveConstraintsAffectingViewIncludingImplicitConstraints:(_Bool)arg1;
- (void)autoRemoveConstraintsAffectingView;
- (id)autoPinToBottomLayoutGuideOfViewController:(id)arg1 withInset:(double)arg2 relation:(long long)arg3;
- (id)autoPinToBottomLayoutGuideOfViewController:(id)arg1 withInset:(double)arg2;
- (id)autoPinToTopLayoutGuideOfViewController:(id)arg1 withInset:(double)arg2 relation:(long long)arg3;
- (id)autoPinToTopLayoutGuideOfViewController:(id)arg1 withInset:(double)arg2;
- (id)autoConstrainAttribute:(long long)arg1 toAttribute:(long long)arg2 ofView:(id)arg3 withMultiplier:(double)arg4 relation:(long long)arg5;
- (id)autoConstrainAttribute:(long long)arg1 toAttribute:(long long)arg2 ofView:(id)arg3 withMultiplier:(double)arg4;
- (id)autoConstrainAttribute:(long long)arg1 toAttribute:(long long)arg2 ofView:(id)arg3 withOffset:(double)arg4 relation:(long long)arg5;
- (id)autoConstrainAttribute:(long long)arg1 toAttribute:(long long)arg2 ofView:(id)arg3 withOffset:(double)arg4;
- (id)autoConstrainAttribute:(long long)arg1 toAttribute:(long long)arg2 ofView:(id)arg3;
- (void)autoSetContentHuggingPriorityForAxis:(long long)arg1;
- (void)autoSetContentCompressionResistancePriorityForAxis:(long long)arg1;
- (id)autoSetDimension:(long long)arg1 toSize:(double)arg2 relation:(long long)arg3;
- (id)autoSetDimension:(long long)arg1 toSize:(double)arg2;
- (id)autoSetDimensionsToSize:(struct CGSize)arg1;
- (id)autoMatchDimension:(long long)arg1 toDimension:(long long)arg2 ofView:(id)arg3 withMultiplier:(double)arg4 relation:(long long)arg5;
- (id)autoMatchDimension:(long long)arg1 toDimension:(long long)arg2 ofView:(id)arg3 withMultiplier:(double)arg4;
- (id)autoMatchDimension:(long long)arg1 toDimension:(long long)arg2 ofView:(id)arg3 withOffset:(double)arg4 relation:(long long)arg5;
- (id)autoMatchDimension:(long long)arg1 toDimension:(long long)arg2 ofView:(id)arg3 withOffset:(double)arg4;
- (id)autoMatchDimension:(long long)arg1 toDimension:(long long)arg2 ofView:(id)arg3;
- (id)autoAlignAxis:(long long)arg1 toSameAxisOfView:(id)arg2 withOffset:(double)arg3;
- (id)autoAlignAxis:(long long)arg1 toSameAxisOfView:(id)arg2;
- (id)autoPinEdge:(long long)arg1 toEdge:(long long)arg2 ofView:(id)arg3 withOffset:(double)arg4 relation:(long long)arg5;
- (id)autoPinEdge:(long long)arg1 toEdge:(long long)arg2 ofView:(id)arg3 withOffset:(double)arg4;
- (id)autoPinEdge:(long long)arg1 toEdge:(long long)arg2 ofView:(id)arg3;
- (id)autoPinEdgesToSuperviewMarginsExcludingEdge:(long long)arg1;
- (id)autoPinEdgesToSuperviewMargins;
- (id)autoPinEdgeToSuperviewMargin:(long long)arg1 relation:(long long)arg2;
- (id)autoPinEdgeToSuperviewMargin:(long long)arg1;
- (id)autoPinEdgesToSuperviewEdgesWithInsets:(struct UIEdgeInsets)arg1 excludingEdge:(long long)arg2;
- (id)autoPinEdgesToSuperviewEdgesWithInsets:(struct UIEdgeInsets)arg1;
- (id)autoPinEdgeToSuperviewEdge:(long long)arg1 withInset:(double)arg2 relation:(long long)arg3;
- (id)autoPinEdgeToSuperviewEdge:(long long)arg1 withInset:(double)arg2;
- (id)autoPinEdgeToSuperviewEdge:(long long)arg1;
- (id)autoAlignAxisToSuperviewMarginAxis:(long long)arg1;
- (id)autoCenterInSuperviewMargins;
- (id)autoAlignAxisToSuperviewAxis:(long long)arg1;
- (id)autoCenterInSuperview;
- (id)initForAutoLayout;
@end

