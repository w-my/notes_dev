//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "LKTouchThroughView.h"

@class MVGradientView, UIButton, UIView;

@interface MVEditTopBar : LKTouchThroughView
{
    UIButton *_backButton;
    UIButton *_rightButton;
    UIButton *_centerButton;
    UIView *_progressView;
    UIView *_indicatorView;
    UIView *_progressBGView;
    long long _style;
    double _progress;
    CDUnknownBlockType _willCancelEditing;
    CDUnknownBlockType _willFinishEditing;
    CDUnknownBlockType _willSaveDraft;
    CDUnknownBlockType _willResumeRecording;
    MVGradientView *_gradientView;
}

+ (double)preferredHeight;
@property(nonatomic) __weak MVGradientView *gradientView; // @synthesize gradientView=_gradientView;
@property(copy, nonatomic) CDUnknownBlockType willResumeRecording; // @synthesize willResumeRecording=_willResumeRecording;
@property(copy, nonatomic) CDUnknownBlockType willSaveDraft; // @synthesize willSaveDraft=_willSaveDraft;
@property(copy, nonatomic) CDUnknownBlockType willFinishEditing; // @synthesize willFinishEditing=_willFinishEditing;
@property(copy, nonatomic) CDUnknownBlockType willCancelEditing; // @synthesize willCancelEditing=_willCancelEditing;
@property(nonatomic) double progress; // @synthesize progress=_progress;
@property(nonatomic) long long style; // @synthesize style=_style;
@property(readonly, nonatomic) __weak UIView *progressBGView; // @synthesize progressBGView=_progressBGView;
@property(readonly, nonatomic) __weak UIView *indicatorView; // @synthesize indicatorView=_indicatorView;
@property(readonly, nonatomic) __weak UIView *progressView; // @synthesize progressView=_progressView;
@property(readonly, nonatomic) __weak UIButton *centerButton; // @synthesize centerButton=_centerButton;
@property(readonly, nonatomic) __weak UIButton *rightButton; // @synthesize rightButton=_rightButton;
@property(readonly, nonatomic) __weak UIButton *backButton; // @synthesize backButton=_backButton;
- (void).cxx_destruct;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)centerButtonClicked;
- (void)rightButtonClicked;
- (void)backButtonClicked;
- (void)initUI;

@end
