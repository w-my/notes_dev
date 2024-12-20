//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@interface UIView (__QNCore)
+ (void)qn_invokeBlockWithoutAnimation:(CDUnknownBlockType)arg1;
+ (id)qn_invokeBlock:(CDUnknownBlockType)arg1 enableViewAnimation:(_Bool)arg2;
- (id)qn_firstSuperviewForClass:(Class)arg1;
- (id)qn_snapshotImageWithFrame:(struct CGRect)arg1 shouldTryiOS7Method:(_Bool)arg2;
- (id)qn_snapshotImageWithFrame:(struct CGRect)arg1;
- (id)qn_snapshotImage;
- (id)qn_filteredSubviewsUsingBlock:(CDUnknownBlockType)arg1;
- (id)qn_filteredSuperviewUsingBlock:(CDUnknownBlockType)arg1;
- (void)qn_layoutSubviewsImmediately;
- (void)qn_setFrameAndTriggerLayoutIfNeeded:(struct CGRect)arg1;
- (_Bool)p_invisibleInHierarchy;
@property(readonly, nonatomic) _Bool qn_visibleInHierarchy;
@property(readonly, nonatomic) double qn_boundsWidth;
@property(readonly, nonatomic) double qn_boundsHeight;
@property(nonatomic) struct CGSize qn_size;
@property(nonatomic) struct CGPoint qn_origin;
@property(nonatomic) double qn_height;
@property(nonatomic) double qn_width;
@property(readonly, nonatomic) struct CGPoint qn_innerCenter;
@property(nonatomic) double qn_centerY;
@property(nonatomic) double qn_centerX;
@property(nonatomic) double qn_bottom;
@property(nonatomic) double qn_right;
@property(nonatomic) double qn_top;
@property(nonatomic) double qn_left;
- (id)qn_subviewsOfClass:(Class)arg1;
- (void)qn_insertSubview:(id)arg1 belowSubview:(id)arg2;
- (void)qn_insertSubview:(id)arg1 aboveSubview:(id)arg2;
- (id)qn_snapshotView;
- (void)qn_traverseSuperViewWithBlock:(CDUnknownBlockType)arg1 depth:(int)arg2;
- (void)qn_traverseSuperViewWithBlock:(CDUnknownBlockType)arg1;
- (void)qn_traverseSubviewsWithBlock:(CDUnknownBlockType)arg1 depth:(int)arg2;
- (void)qn_traverseSubviewsWithBlock:(CDUnknownBlockType)arg1;
- (void)qn_removeAllSubviews;
@end

