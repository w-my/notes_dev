//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

#import "SBControlCenterObserver.h"

@class NSString, SBControlCenterContentView, _UIBackdropView;

@interface SBControlCenterContentContainerView : UIView <SBControlCenterObserver>
{
    UIView *_accessibilityBackgroundView;
    UIView *_lighteningView;
    _UIBackdropView *_backdropView;
    SBControlCenterContentView *_contentView;
    double _contentHeight;
}

@property double contentHeight; // @synthesize contentHeight=_contentHeight;
@property(retain, nonatomic) SBControlCenterContentView *contentView; // @synthesize contentView=_contentView;
@property(retain, nonatomic) _UIBackdropView *backdropView; // @synthesize backdropView=_backdropView;
- (void).cxx_destruct;
- (void)_accessibilityBackgroundContrastDidChange:(id)arg1;
- (void)_updateBackground;
- (void)controlCenterDidFinishTransition;
- (void)controlCenterWillBeginTransition;
- (void)controlCenterDidDismiss;
- (void)controlCenterWillPresent;
- (void)layoutSubviews;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
