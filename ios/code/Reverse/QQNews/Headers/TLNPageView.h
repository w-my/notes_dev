//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TLNComponentBase.h"

#import "UIScrollViewDelegate.h"

@class NSArray, NSString, UIImageView, UIScrollView;

@interface TLNPageView : TLNComponentBase <UIScrollViewDelegate>
{
    _Bool _reachEnd;
    _Bool _shouldShowNextTip;
    double _depth;
    UIScrollView *_innerScrollView;
    NSArray *_pageRanges;
    UIImageView *_nextTipView;
}

@property(nonatomic) _Bool shouldShowNextTip; // @synthesize shouldShowNextTip=_shouldShowNextTip;
@property(retain, nonatomic) UIImageView *nextTipView; // @synthesize nextTipView=_nextTipView;
@property(nonatomic) _Bool reachEnd; // @synthesize reachEnd=_reachEnd;
@property(retain, nonatomic) NSArray *pageRanges; // @synthesize pageRanges=_pageRanges;
@property(retain, nonatomic) UIScrollView *innerScrollView; // @synthesize innerScrollView=_innerScrollView;
@property(nonatomic) double depth; // @synthesize depth=_depth;
- (void).cxx_destruct;
- (long long)p_getPageEnd:(double)arg1;
- (_Bool)p_isRangeOverlap:(struct _NSRange)arg1;
- (_Bool)p_shouldStartPaging:(double)arg1;
- (_Bool)p_isDuringBouncing;
- (void)scrollViewWillEndDragging:(id)arg1 withVelocity:(struct CGPoint)arg2 targetContentOffset:(inout struct CGPoint *)arg3;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (void)scrollViewDidEndDragging:(id)arg1 willDecelerate:(_Bool)arg2;
- (void)scrollViewWillBeginDragging:(id)arg1;
- (struct CGPoint)nearestTargetOffsetForOffset:(struct CGPoint)arg1 direction:(_Bool)arg2;
- (void)snapToNearestItem:(id)arg1;
- (void)handleReachEnd;
- (void)scrollViewDidScroll:(id)arg1;
- (void)addNextTipAnimation;
- (void)layoutSubviews;
- (void)setupViews;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
