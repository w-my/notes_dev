//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class NSString, NSTimer, QNAudioProgressView, QNCycleScrollView, UIButton, UIView;

@interface QNAudioOverlayControlView : QNThemableView
{
    long long _style;
    UIButton *_playBtn;
    UIButton *_closeBtn;
    QNAudioProgressView *_progressView;
    UIView *_backgroundView;
    NSTimer *_timer;
    NSString *_imgUrlString;
    QNCycleScrollView *_cycleScrollView;
}

@property(retain, nonatomic) QNCycleScrollView *cycleScrollView; // @synthesize cycleScrollView=_cycleScrollView;
@property(copy, nonatomic) NSString *imgUrlString; // @synthesize imgUrlString=_imgUrlString;
@property(retain, nonatomic) NSTimer *timer; // @synthesize timer=_timer;
@property(retain, nonatomic) UIView *backgroundView; // @synthesize backgroundView=_backgroundView;
@property(retain, nonatomic) QNAudioProgressView *progressView; // @synthesize progressView=_progressView;
@property(retain, nonatomic) UIButton *closeBtn; // @synthesize closeBtn=_closeBtn;
@property(retain, nonatomic) UIButton *playBtn; // @synthesize playBtn=_playBtn;
@property(nonatomic) long long style; // @synthesize style=_style;
- (void).cxx_destruct;
- (_Bool)pointInside:(struct CGPoint)arg1 withEvent:(id)arg2;
- (void)pause;
- (void)play;
- (void)playScrollViewTitle:(id)arg1;
- (void)p_themeChanged:(id)arg1;
- (void)showBigWindowStyle;
- (void)showSmallWindowStyle;
- (void)timerUpdate:(id)arg1;
- (void)invalidTimer;
- (void)initTimer;
- (void)updatePlayBtnState:(_Bool)arg1 rate:(double)arg2;
- (void)updateViewStyle:(long long)arg1;
- (void)loadCoverImage:(id)arg1;
- (void)closeBtnClicked:(id)arg1;
- (void)playBtnClicked:(id)arg1;
- (double)playProcess;
- (_Bool)isPlaying;
- (void)updateProgress:(double)arg1;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

@end
