//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WALoadingViewController.h"

@class DotLoadingView, MMTimer, MMUILabel, MMWebImageView, NSString, UIView;

@interface WANavLoadingViewController : WALoadingViewController
{
    unsigned long long _initTime;
    unsigned long long _appearTime;
    UIView *m_menuView;
    MMWebImageView *m_logoView;
    MMUILabel *m_titleLabel;
    DotLoadingView *m_loadingView;
    NSString *m_weappColorStr;
    int m_weappNavMode;
    NSString *m_weappBackgroundColorStr;
    MMTimer *m_waitTipsTimer;
    MMUILabel *m_tipsLabel;
}

- (void).cxx_destruct;
- (void)reportLoadingStayTime;
- (id)fakeMenuView;
- (void)showTipsLabel;
- (void)initTipslabel;
- (void)startEnterAppAnimation;
- (void)showDownloadingProgressView;
- (void)initRightMenu;
- (void)initLoadingView;
- (void)updateContactTitleWithNavMode:(int)arg1;
- (void)initContactTitle;
- (void)initLogoView;
- (void)updateViewBaseOnWeAppViewConfig;
- (void)initView;
- (void)setupNavMode;
- (void)configUI;
- (void)onReturn;
- (void)dealloc;
- (void)resetSubviewOrigin;
- (void)viewDidLayoutSubviews;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (id)initWithContact:(id)arg1 pagePath:(id)arg2;

@end

