//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

#import "MinimizeDetailTaskListViewInterface.h"

@class MinimizeAnimateStateBaseView, MinimizeTaskData, NSString, UIButton, UILabel;

@interface MinimizeTaskStateView : UIView <MinimizeDetailTaskListViewInterface>
{
    unsigned int _taskState;
    id <MinimizeTaskStateViewDelegate> _m_delegate;
    MinimizeTaskData *_taskData;
    UILabel *_titleLabel;
    unsigned long long _positionType;
    UIButton *_closeBtn;
    MinimizeAnimateStateBaseView *_stateView;
}

@property(retain, nonatomic) MinimizeAnimateStateBaseView *stateView; // @synthesize stateView=_stateView;
@property(retain, nonatomic) UIButton *closeBtn; // @synthesize closeBtn=_closeBtn;
@property(nonatomic) unsigned long long positionType; // @synthesize positionType=_positionType;
@property(retain, nonatomic) UILabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(nonatomic) unsigned int taskState; // @synthesize taskState=_taskState;
@property(retain, nonatomic) MinimizeTaskData *taskData; // @synthesize taskData=_taskData;
@property(nonatomic) __weak id <MinimizeTaskStateViewDelegate> m_delegate; // @synthesize m_delegate=_m_delegate;
- (void).cxx_destruct;
- (void)onCloseBtnClicked:(id)arg1;
- (void)setCloseBtnVisible:(_Bool)arg1;
- (double)closeBtnRightMargin;
- (void)updateTitle:(id)arg1;
- (void)resetAllView;
- (void)addCloseButton;
- (id)getDefaultClipPath:(struct CGRect)arg1 positionType:(unsigned long long)arg2;
- (void)updateMask:(_Bool)arg1 Duration:(double)arg2;
- (void)updatePositionType:(unsigned long long)arg1;
- (unsigned long long)getPositionType:(struct CGRect)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

