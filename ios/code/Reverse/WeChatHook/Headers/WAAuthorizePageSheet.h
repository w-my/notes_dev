//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WAPageSheet.h"

@class MMWebImageView, UIButton, UILabel, WAAuthorizeSheetInfo;

@interface WAAuthorizePageSheet : WAPageSheet
{
    MMWebImageView *_iconView;
    UILabel *_appNameLabel;
    UILabel *_applyLabel;
    UILabel *_privacyLabel;
    UIButton *_acceptButton;
    UIButton *_rejectButton;
    id <WAAuthorizePageSheetDelegate> _authorizeSheetdelegate;
    WAAuthorizeSheetInfo *_info;
}

@property(retain, nonatomic) WAAuthorizeSheetInfo *info; // @synthesize info=_info;
@property(nonatomic) __weak id <WAAuthorizePageSheetDelegate> authorizeSheetdelegate; // @synthesize authorizeSheetdelegate=_authorizeSheetdelegate;
@property(retain, nonatomic) UIButton *rejectButton; // @synthesize rejectButton=_rejectButton;
@property(retain, nonatomic) UIButton *acceptButton; // @synthesize acceptButton=_acceptButton;
@property(retain, nonatomic) UILabel *privacyLabel; // @synthesize privacyLabel=_privacyLabel;
@property(retain, nonatomic) UILabel *applyLabel; // @synthesize applyLabel=_applyLabel;
@property(retain, nonatomic) UILabel *appNameLabel; // @synthesize appNameLabel=_appNameLabel;
@property(retain, nonatomic) MMWebImageView *iconView; // @synthesize iconView=_iconView;
- (void).cxx_destruct;
- (void)onRejectBtnClick:(id)arg1;
- (void)onAcceptBtnClick:(id)arg1;
- (void)layoutSubViews;
- (void)tryAdjustViewSizeWhenKnownContentWidth;
- (void)loadSubviewsWithInfo;
- (double)contentHeight;
- (id)initWithInfo:(id)arg1;

@end
