//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class CAShapeLayer;

@interface TLNLoadingView : UIView
{
    _Bool _loadingStopped;
    CAShapeLayer *_circleLayer;
}

@property(nonatomic) _Bool loadingStopped; // @synthesize loadingStopped=_loadingStopped;
@property(retain, nonatomic) CAShapeLayer *circleLayer; // @synthesize circleLayer=_circleLayer;
- (void).cxx_destruct;
- (void)p_addCircleAnimations;
- (void)stopAnim;
- (void)startAnim;
- (id)initWithFrame:(struct CGRect)arg1;

@end

