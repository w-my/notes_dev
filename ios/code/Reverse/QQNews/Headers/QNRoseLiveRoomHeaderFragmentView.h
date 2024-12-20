//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRoseLiveRoomBaseFragmentView.h"

@class CIconButton, CSimpleImageView, UIButton, UILabel;

@interface QNRoseLiveRoomHeaderFragmentView : QNRoseLiveRoomBaseFragmentView
{
    _Bool _setUpListenUploadVideo;
    UILabel *_nickNameLabel;
    UILabel *_timeLabel;
    CSimpleImageView *_crownImageView;
    UILabel *_statusLabel;
    UIButton *_resendButton;
    CIconButton *_sendRoseButton;
}

+ (void)qnTriggerUserHeadTapAction:(id)arg1;
+ (double)expectFragmentViewHeight:(id)arg1 level:(long long)arg2 width:(double)arg3 context:(id)arg4;
+ (unsigned long long)dataType;
+ (_Bool)shouldDisplayCurrentFragmentView:(id)arg1 level:(long long)arg2 context:(id)arg3;
@property(retain, nonatomic) CIconButton *sendRoseButton; // @synthesize sendRoseButton=_sendRoseButton;
@property(nonatomic) _Bool setUpListenUploadVideo; // @synthesize setUpListenUploadVideo=_setUpListenUploadVideo;
@property(retain, nonatomic) UIButton *resendButton; // @synthesize resendButton=_resendButton;
@property(retain, nonatomic) UILabel *statusLabel; // @synthesize statusLabel=_statusLabel;
@property(retain, nonatomic) CSimpleImageView *crownImageView; // @synthesize crownImageView=_crownImageView;
@property(retain, nonatomic) UILabel *timeLabel; // @synthesize timeLabel=_timeLabel;
@property(retain, nonatomic) UILabel *nickNameLabel; // @synthesize nickNameLabel=_nickNameLabel;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)p_handleNotificationForUploadFail:(id)arg1;
- (void)p_startMonitorUploadFailNotification;
- (void)p_resendButtonAction;
- (void)p_resetNickNameBackgroundColor;
- (void)p_configVideoUploadFail;
- (double)p_nickNameMaxWidth;
- (void)touchesEnded:(id)arg1 withEvent:(id)arg2;
- (_Bool)pointInside:(struct CGPoint)arg1 withEvent:(id)arg2;
- (void)layoutSubviewsImmediately;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

@end

