//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, UIButton;

@protocol MMMusicPageViewDelegate <NSObject>

@optional
- (UIButton *)getPlayButton;
- (void)onBack2FirstPage;
- (void)onShowSecondPage;
- (void)onFollowArrayUpToShowSecondPage;
- (void)onUpdateBottomBtnColor:(NSString *)arg1;
- (_Bool)isBottomViewHidden;
- (void)showOrHideTopBottomView;
@end

