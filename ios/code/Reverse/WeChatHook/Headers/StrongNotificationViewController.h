//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMWindowViewController.h"

@class AVAudioPlayer, CContact, MMTimer, MMUILabel, MMWebImageView, MultiTalkHDHeadView, NSString, StrongNotificationItemPB, UIButton, UIColor, UIImage, UIImageView, UIView;

@interface StrongNotificationViewController : MMWindowViewController
{
    UIImageView *m_backgroundView;
    MMUILabel *m_nameLabel;
    MultiTalkHDHeadView *m_headImageView;
    MMUILabel *m_titleLabel;
    UIView *m_separationView;
    AVAudioPlayer *m_player;
    MMTimer *_stopPlaySoundAndAppVibrationTimer;
    MMUILabel *m_logoNameLabel;
    UIImageView *m_logoImageView;
    MMWebImageView *m_headWebImageView;
    UIButton *m_iKnowBtn;
    UIImage *m_logoImage;
    NSString *m_logoNameStr;
    NSString *m_headNameStr;
    NSString *m_HeadWebImageUrlStr;
    NSString *m_titleStr;
    UIColor *m_iKnowBtnBkgColor;
    CContact *m_contact;
    id <StrongNotificationViewControllerDelegate> m_delegate;
    StrongNotificationItemPB *m_strongNotificationItem;
    NSString *_m_contentStr;
}

@property(retain, nonatomic) NSString *m_contentStr; // @synthesize m_contentStr=_m_contentStr;
@property(retain, nonatomic) StrongNotificationItemPB *m_strongNotificationItem; // @synthesize m_strongNotificationItem;
@property(nonatomic) __weak id <StrongNotificationViewControllerDelegate> m_delegate; // @synthesize m_delegate;
@property(retain, nonatomic) CContact *m_contact; // @synthesize m_contact;
- (void).cxx_destruct;
- (void)onEnterBackground;
- (void)stopPlaySound;
- (void)playSound:(id)arg1 OfType:(id)arg2 numberOfLoops:(long long)arg3;
- (void)asyncPlaySound;
- (void)stopPlaySoundAndAppVibration;
- (void)stopPlaySoundAndAppVibrationTimerAction;
- (void)startStopPlaySoundAndAppVibrationTimer;
- (void)doIKnow;
- (void)layoutIKnowBtn;
- (void)layoutTitleView;
- (void)layoutNameView;
- (void)layoutHeadView;
- (void)layoutLogoView;
- (void)layoutBackground;
- (void)relayoutView;
- (void)initView;
- (void)relayoutViewWithHeadNameStr:(id)arg1 andHeadWebImageUrlStr:(id)arg2;
- (void)reSetData;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewDidLayoutSubviews;
- (void)viewWillAppear:(_Bool)arg1;
- (void)dealloc;
- (void)viewDidLoad;

@end

