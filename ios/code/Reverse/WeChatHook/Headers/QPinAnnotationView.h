//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QAnnotationView.h"

#import "CAAnimationDelegate.h"

@class NSString, UIImageView;

@interface QPinAnnotationView : QAnnotationView <CAAnimationDelegate>
{
    _Bool _animatesDrop;
    int _pinColor;
    UIImageView *_shadowImageView;
    struct CGRect _validRect;
}

@property(nonatomic) struct CGRect validRect; // @synthesize validRect=_validRect;
@property(nonatomic) _Bool animatesDrop; // @synthesize animatesDrop=_animatesDrop;
@property(retain, nonatomic) UIImageView *shadowImageView; // @synthesize shadowImageView=_shadowImageView;
@property(nonatomic) int pinColor; // @synthesize pinColor=_pinColor;
- (void).cxx_destruct;
- (id)initWithAnnotation:(id)arg1 reuseIdentifier:(id)arg2;
- (void)setDragState:(int)arg1 animated:(_Bool)arg2;
- (void)willMoveToSuperview:(id)arg1;
- (_Bool)pointInside:(struct CGPoint)arg1 withEvent:(id)arg2;
- (void)animationDidStop:(id)arg1 finished:(_Bool)arg2;
- (void)changeToLift:(_Bool)arg1;
- (id)dropAnimationWithFromPoint:(struct CGPoint)arg1 completion:(CDUnknownBlockType)arg2;
- (id)shadowAnimationFromPoint:(struct CGPoint *)arg1 toPoint:(struct CGPoint *)arg2 duration:(double)arg3 completion:(CDUnknownBlockType)arg4;
- (id)liftImageForPinColor:(int)arg1;
- (id)imageForPinColor:(int)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
