//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class CAShapeLayer;

@interface QNStampDashedBorderView : UIView
{
    _Bool _marching;
    CAShapeLayer *_borderLayer;
}

@property(nonatomic) _Bool marching; // @synthesize marching=_marching;
@property(retain, nonatomic) CAShapeLayer *borderLayer; // @synthesize borderLayer=_borderLayer;
- (void).cxx_destruct;
- (void)p_setAnimating:(_Bool)arg1;
- (void)didMoveToWindow;
- (void)setFrame:(struct CGRect)arg1;
- (void)p_handleAppDidBecomeActive:(id)arg1;
- (void)p_handleAppDidEnterBackground:(id)arg1;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

@end
