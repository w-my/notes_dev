//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MVCameraTopBar, UIButton;

@protocol MVCameraTopBarDelegate <NSObject>
- (void)topBar:(MVCameraTopBar *)arg1 onTapCountDownBtn:(UIButton *)arg2;
- (void)topBar:(MVCameraTopBar *)arg1 onTapTorchBtn:(UIButton *)arg2;
- (void)topBar:(MVCameraTopBar *)arg1 onTapSwitchCameraBtn:(UIButton *)arg2;
- (void)topBar:(MVCameraTopBar *)arg1 onTapBackBtn:(UIButton *)arg2;
@end

