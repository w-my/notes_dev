//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRootViewController.h"

@class UIImageView;

@interface QNListPreloadViewController : QNRootViewController
{
    _Bool _isLoadingMainViewController;
    _Bool _triggerPopToRootViewController;
    UIImageView *_launchAppImageView;
    long long _destChannelIndex;
}

+ (Class)rootViewControllerClassWithLaunchOptions:(id)arg1;
@property(nonatomic) long long destChannelIndex; // @synthesize destChannelIndex=_destChannelIndex;
@property(nonatomic) _Bool triggerPopToRootViewController; // @synthesize triggerPopToRootViewController=_triggerPopToRootViewController;
@property(nonatomic) _Bool isLoadingMainViewController; // @synthesize isLoadingMainViewController=_isLoadingMainViewController;
@property(retain, nonatomic) UIImageView *launchAppImageView; // @synthesize launchAppImageView=_launchAppImageView;
- (void).cxx_destruct;
- (void)p_loadViewControllerAnimated:(_Bool)arg1;
- (void)p_loadMainViewControllerForRemote;
- (void)p_loadMainViewController:(_Bool)arg1;
- (void)p_handleTapGesture:(id)arg1;
- (void)configBarButtons;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (void)loadView;
- (void)dealloc;
- (void)_handlePortraitVideoDetailVCUpToDownNotification:(id)arg1;
- (void)p_handleFromChannelPreviewToRoot:(id)arg1;
- (void)p_handlePopToRootViewController:(id)arg1;
- (void)p_handleDetailRecommendNotification:(id)arg1;
- (id)initWithParam:(id)arg1;

@end

