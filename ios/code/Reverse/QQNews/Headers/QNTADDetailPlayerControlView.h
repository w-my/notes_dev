//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNPlayerControlViewBase.h"

#import "QNTKVPlayerViewDelegate.h"
#import "QNTVKProgressControlDelegate.h"
#import "TADTKVPlayerTopViewDelegate.h"
#import "TADTKVProgressControlDelegate.h"

@class NSString, TADRouter, TADTKVPlayerControlView;

@interface QNTADDetailPlayerControlView : QNPlayerControlViewBase <TADTKVProgressControlDelegate, QNTKVPlayerViewDelegate, TADTKVPlayerTopViewDelegate, QNTVKProgressControlDelegate>
{
    id <QNTADDetailPlayerControlViewDelegate> _delegate;
    TADTKVPlayerControlView *_controlView;
    TADRouter *_router;
}

@property(retain, nonatomic) TADRouter *router; // @synthesize router=_router;
@property(retain, nonatomic) TADTKVPlayerControlView *controlView; // @synthesize controlView=_controlView;
@property(nonatomic) __weak id <QNTADDetailPlayerControlViewDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)progressControlProgress:(double)arg1;
- (void)p_doSwitchPlayerScreen:(_Bool)arg1;
- (void)progressControlZoomOut;
- (void)updateToolBar;
- (void)rotateToPortrait;
- (void)playerViewPauseAd;
- (void)playerViewPlayManually:(_Bool)arg1;
- (void)playerViewTapped;
- (void)playerViewDetailButtonClicked;
- (void)progressControlUnMute;
- (void)progressControlMute;
- (void)updatePlayState:(_Bool)arg1;
- (void)updateProgress:(double)arg1 bufferTime:(double)arg2 duration:(double)arg3;
- (void)layoutSubviews;
- (void)dealloc;
- (void)playerStateChangeTo:(long long)arg1;
- (void)createSubViews;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
