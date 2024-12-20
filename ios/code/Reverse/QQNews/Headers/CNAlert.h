//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class NSMutableOrderedSet, QNHUDAlertViewMessage, UIActivityIndicatorView, UIImageView, UITapGestureRecognizer;

@interface CNAlert : UIView
{
    UIView *_backView;
    UIImageView *_imageview;
    UIActivityIndicatorView *_indicator;
    _Bool _withKeyboard;
    NSMutableOrderedSet *_alertQueue;
    QNHUDAlertViewMessage *_currentMessage;
    UITapGestureRecognizer *_tapGesture;
}

+ (id)sharedCNAlert;
@property(retain, nonatomic) UITapGestureRecognizer *tapGesture; // @synthesize tapGesture=_tapGesture;
@property(retain, nonatomic) QNHUDAlertViewMessage *currentMessage; // @synthesize currentMessage=_currentMessage;
@property(retain, nonatomic) NSMutableOrderedSet *alertQueue; // @synthesize alertQueue=_alertQueue;
- (void).cxx_destruct;
- (struct CGAffineTransform)p_transformForOrientation:(long long)arg1;
- (void)p_dismissCurrentHUDView;
- (id)p_imageForMessage:(id)arg1 showIndicator:(_Bool)arg2;
- (void)p_displayHUDFromQueue;
- (void)p_clickedAlertView:(id)arg1;
- (void)p_tryDisplayAlertViewWithMessage:(id)arg1;
- (void)p_tryDisplayHUDWithMessage:(id)arg1 Style:(long long)arg2 duration:(double)arg3 animated:(_Bool)arg4 useDeviceOrientation:(_Bool)arg5 singleLine:(_Bool)arg6 customImage:(id)arg7;
- (void)p_tryDisplayHUDWithMessage:(id)arg1 Style:(long long)arg2 duration:(double)arg3 animated:(_Bool)arg4 useDeviceOrientation:(_Bool)arg5 singleLine:(_Bool)arg6;
- (void)p_tryDisplayHUDWithMessage:(id)arg1 Style:(long long)arg2 duration:(double)arg3 animated:(_Bool)arg4 useDeviceOrientation:(_Bool)arg5;
- (void)p_adjustImageViewCenter;
- (_Bool)p_isPortrait;
- (void)dismissCurrentHUDViewWithNoAnimation;
- (void)showAlertView:(id)arg1 customImage:(id)arg2 clickedCallback:(CDUnknownBlockType)arg3;
- (void)showFocusTeamAlertView;
- (void)showAlertViewWithDaWangCard;
- (void)showAlertView:(id)arg1 style:(long long)arg2 singleLine:(_Bool)arg3 duration:(double)arg4;
- (void)showAlertView:(id)arg1 style:(long long)arg2 singleLine:(_Bool)arg3;
- (void)showAlertView:(id)arg1 style:(long long)arg2;
- (void)closeLoadingActivity;
- (void)showLoadingActivityWithText:(id)arg1;
- (void)showImagePickerOverMaxCount:(long long)arg1;
- (void)showMyNewsUnlikeAlert;
- (void)showMyNewsLikeAlert;
- (void)showVideoDidDislikeAlert;
- (void)showVideoDidLikeAlert;
- (void)showVideoDislikeAlert;
- (void)showVideoAutoPlayAlert;
- (void)showVideoLikeAlertWhileLoginout;
- (void)showVideoLikeAlert;
- (void)showPlayIsMuteAlert;
- (void)showInvalidVideoAlert;
- (void)showNOShareChannelAlert;
- (void)showNoSubscribeAlert;
- (void)showOriginalImageDownloadFailAlert;
- (void)showAddMediaSucessedAlertView;
- (void)showPinnedCommentOverflowAlert;
- (void)showCancelPinnedCommentFailAlert;
- (void)showCancelPinnedCommentSuccessAlert;
- (void)showPinnedCommentFailAlert;
- (void)showPinnedCommentSuccessAlert;
- (void)showDeleteCommentFailAlert;
- (void)showDeleteCommentSuccessAlert;
- (void)showRemoveFavoriteSuccessAlertView;
- (void)showAddFavoriteSuccessAlertView;
- (void)showWinxinLowVersionAlertView:(_Bool)arg1;
- (void)showInvalidQZoneAlertView:(_Bool)arg1;
- (void)showInvalidTencentWeiBoAlertView:(_Bool)arg1;
- (void)showRequestPwdAlertView:(_Bool)arg1;
- (void)showRequestAccountAlertView:(_Bool)arg1;
- (void)showRequestAccountAndPwdAlertView:(_Bool)arg1;
- (void)showTokenExpireAlertView;
- (void)showNoTencentWeiboAlertView;
- (void)showSSOLoginFailedAlertView;
- (void)showLoginPicCodeInputErrorAlertView;
- (void)showLoginFailedAlertView;
- (void)showLoginWaitingAlertView;
- (void)showReportFailedAlertView;
- (void)showReportSucessedAlertView;
- (void)showSupportSucessedAlertView;
- (void)showShareFailedAlertView;
- (void)showShareSucessedAlertView;
- (void)showPublishFailedAlertView;
- (void)showPublishSucessedAlertView;
- (void)showLoginSucessedAlertView:(_Bool)arg1;
- (void)closeLoginWaitingAlertView;
- (void)showDownloadSucessedAlertViewAutoDirection;
- (void)showDownloadFailedAlertView;
- (void)showDownloadSucessedAlertView;
- (void)showCopyFailedAlertView;
- (void)showCopySucessedAlertView;
- (void)showSendFailedAlertView;
- (void)showSportMatchInfoFailAlertView;
- (void)showSendSucessedAlertView;
- (void)showSendingAlertView;
- (void)showChannelsRecommendAlertViewForFinishOrdering;
- (void)showLeastChannelsRecommendAlertView;
- (_Bool)pointInside:(struct CGPoint)arg1 withEvent:(id)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

@end

