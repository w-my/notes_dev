//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class MMTimer, UIColor, UIImageView;

@interface SightIconView : UIView
{
    UIColor *m_color;
    double m_radius;
    int m_iconType;
    int m_targetIconType;
    double m_animIntermediate;
    double m_animIntermediate2;
    double m_progress;
    double m_targetProgress;
    double m_progressStep;
    double m_forceStep;
    MMTimer *m_timer;
    UIImageView *m_playIconView;
    id <SightIconViewDelegate> m_delegate;
    _Bool _useBigIconForPlay;
    UIColor *_barColor;
}

@property(nonatomic) _Bool useBigIconForPlay; // @synthesize useBigIconForPlay=_useBigIconForPlay;
@property(nonatomic) UIColor *barColor; // @synthesize barColor=_barColor;
@property(nonatomic) __weak id <SightIconViewDelegate> delegate; // @synthesize delegate=m_delegate;
@property(nonatomic) double radius; // @synthesize radius=m_radius;
@property(nonatomic) int iconType; // @synthesize iconType=m_targetIconType;
@property(nonatomic) double progressStep; // @synthesize progressStep=m_progressStep;
@property(nonatomic) double progress; // @synthesize progress=m_targetProgress;
- (void).cxx_destruct;
- (void)drawNonAnimIcon:(struct CGContext *)arg1 alpha:(double)arg2;
- (void)drawRect:(struct CGRect)arg1;
- (void)drawRoundBackground:(struct CGContext *)arg1 radius:(double)arg2;
- (void)drawWheel:(struct CGContext *)arg1 radius:(double)arg2 percentage:(double)arg3;
- (void)drawProgress:(struct CGContext *)arg1 radius:(double)arg2 progress:(double)arg3;
- (void)drawDownload:(struct CGContext *)arg1 radius:(double)arg2 alpha:(double)arg3;
- (void)drawTriangle:(struct CGContext *)arg1 radius:(double)arg2 alpha:(double)arg3;
- (void)drawExcla:(struct CGContext *)arg1 radius:(double)arg2 alpha:(double)arg3;
- (void)updateAnimation;
- (double)getCurrentProgressValue;
- (void)forceSetProgressInCommonModesFrom:(double)arg1 toProgress:(double)arg2;
- (void)forceSetProgressFrom:(double)arg1 toProgress:(double)arg2;
- (void)stopTimer;
- (void)startTimer;
- (void)fullRunWithTime:(double)arg1;
- (void)dealloc;
- (void)setFrame:(struct CGRect)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

