//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class MMUIButton, MMUILabel, UIImageView;

@interface MPLandingVideoErrView : UIView
{
    id <MPLandingVideoErrViewDelegate> _delegate;
    UIImageView *_errImageView;
    MMUILabel *_errMsgLabel;
    MMUIButton *_retryBtn;
    UIView *_containerView;
}

@property(retain, nonatomic) UIView *containerView; // @synthesize containerView=_containerView;
@property(retain, nonatomic) MMUIButton *retryBtn; // @synthesize retryBtn=_retryBtn;
@property(retain, nonatomic) MMUILabel *errMsgLabel; // @synthesize errMsgLabel=_errMsgLabel;
@property(retain, nonatomic) UIImageView *errImageView; // @synthesize errImageView=_errImageView;
@property(nonatomic) __weak id <MPLandingVideoErrViewDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)onErrViewRetryBtnClicked;
- (void)layoutSubviews;
- (void)updateWithErrMsg:(id)arg1 canRetry:(_Bool)arg2;
- (void)initSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

@end
