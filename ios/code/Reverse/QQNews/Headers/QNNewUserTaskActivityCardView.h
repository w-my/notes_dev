//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

#import "QNNewUserTaskActivityTaskUnitDelegate.h"

@class NSString, QNBaseLabel, QNEnlargeHitTestButton, QNLoadingShimmerView, QNNewUserTaskActivityContent, QNNewUserTaskActivityFooter, QNNewUserTaskActivityProgress, QNTaskActivityModel;

@interface QNNewUserTaskActivityCardView : UIView <QNNewUserTaskActivityTaskUnitDelegate>
{
    id <QNNewUserTaskActivityDelegate> _delegate;
    QNTaskActivityModel *_activityModel;
    UIView *_headerBackgroundView;
    QNBaseLabel *_titleLbl;
    QNNewUserTaskActivityProgress *_activityProgress;
    QNBaseLabel *_sevenDayCompleteHeaderLbl;
    QNBaseLabel *_todayDescLbl;
    QNNewUserTaskActivityContent *_activityContent;
    QNNewUserTaskActivityFooter *_activityFooter;
    QNLoadingShimmerView *_loadingView;
    QNEnlargeHitTestButton *_closeButton;
}

@property(retain, nonatomic) QNEnlargeHitTestButton *closeButton; // @synthesize closeButton=_closeButton;
@property(retain, nonatomic) QNLoadingShimmerView *loadingView; // @synthesize loadingView=_loadingView;
@property(retain, nonatomic) QNNewUserTaskActivityFooter *activityFooter; // @synthesize activityFooter=_activityFooter;
@property(retain, nonatomic) QNNewUserTaskActivityContent *activityContent; // @synthesize activityContent=_activityContent;
@property(retain, nonatomic) QNBaseLabel *todayDescLbl; // @synthesize todayDescLbl=_todayDescLbl;
@property(retain, nonatomic) QNBaseLabel *sevenDayCompleteHeaderLbl; // @synthesize sevenDayCompleteHeaderLbl=_sevenDayCompleteHeaderLbl;
@property(retain, nonatomic) QNNewUserTaskActivityProgress *activityProgress; // @synthesize activityProgress=_activityProgress;
@property(retain, nonatomic) QNBaseLabel *titleLbl; // @synthesize titleLbl=_titleLbl;
@property(retain, nonatomic) UIView *headerBackgroundView; // @synthesize headerBackgroundView=_headerBackgroundView;
@property(retain, nonatomic) QNTaskActivityModel *activityModel; // @synthesize activityModel=_activityModel;
@property(nonatomic) __weak id <QNNewUserTaskActivityDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (_Bool)p_isLastDayAndFinishTask;
- (void)p_buttonActionWithType:(unsigned long long)arg1;
- (void)p_closeButtonClickAction:(id)arg1;
- (void)p_obtainButtonClickAction:(id)arg1;
- (void)p_moreButtonClickAction:(id)arg1;
- (void)p_rightButtonClickAction:(id)arg1;
- (void)p_leftButtonClickAction:(id)arg1;
- (void)p_mainButtonClickAction:(id)arg1;
- (id)hitTest:(struct CGPoint)arg1 withEvent:(id)arg2;
- (void)endLoadingAnimation;
- (void)startLoadingAnimation;
- (void)setSelectedModel:(id)arg1 select:(_Bool)arg2;
- (void)layoutCardViewWith:(id)arg1;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
