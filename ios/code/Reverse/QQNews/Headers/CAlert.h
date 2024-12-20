//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class NSMutableDictionary;

@interface CAlert : UIView
{
    double _lastNetworkErrorTime;
    double _lastAritcleLoadFailTime;
    double _lastPicsLoadFailTime;
    double _lastSpecialLoadFailTime;
    double _lastCommentClosedTime;
    NSMutableDictionary *_accessTimes;
}

+ (id)sharedCAlert;
- (void).cxx_destruct;
- (void)showBoutiqueLoadFailAlert;
- (void)showOfflineDownloadEndAlert;
- (void)showOfflineDownloadStartAlert;
- (void)showCommentClosedAlert;
- (void)showCleanFailAlert;
- (void)showSpecialLoadFailAlert;
- (void)showPicsLoadFailAlert;
- (void)showDataLoadFailAlert;
- (void)showAritcleLoadFailAlert;
- (void)showNoNetworkAlert;
- (void)showOOMDetectorAlert:(unsigned long long)arg1;
- (void)showCleanCacheSuccessAlert;
- (void)showSendMsgSucessAlert;
- (void)showSupportCommentFailAlert:(id)arg1;
- (void)showSupportCommentSucessAlert;
- (void)showBroadcastFailAlert;
- (void)showBroadcastSucessAlert;
- (void)showSendCommentFailAlert;
- (void)showSendCommentSucessAlert;
- (void)showLoginInvalid;
- (void)showLogoutSucessAlert;
- (void)showSavePhotoFailAlert;
- (void)showSavePhotoSucessAlert;
- (void)showLoginSuccessAlert;
- (void)showSentSuccessAlert;
- (void)showSentFailedAlert;
- (void)showNetworkAlert;
- (void)showFailedAlert:(id)arg1;
- (void)showSuccessAlert:(id)arg1;
- (void)showSimpleAlert:(id)arg1 image:(id)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

@end

