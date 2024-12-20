//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MinimizeIconAndStateView.h"

@class NSMutableArray;

@interface MinimizeIconAndStateWithBorderView : MinimizeIconAndStateView
{
    _Bool _isRoundMaskPathAfterAnimation;
    NSMutableArray *_lineLayerList;
}

@property(retain, nonatomic) NSMutableArray *lineLayerList; // @synthesize lineLayerList=_lineLayerList;
@property(nonatomic) _Bool isRoundMaskPathAfterAnimation; // @synthesize isRoundMaskPathAfterAnimation=_isRoundMaskPathAfterAnimation;
- (void).cxx_destruct;
- (void)updateAllSublayerAnimated:(double)arg1 ViewPath:(id)arg2 Duration:(double)arg3;
- (void)resetIconViewSublayer:(double)arg1;
- (void)resetLineCircleOnIcon;
- (void)addLineCircleLayerOnIcon:(id)arg1 LinePath:(id)arg2;
- (void)removeLineCircleOnIcon;

@end

