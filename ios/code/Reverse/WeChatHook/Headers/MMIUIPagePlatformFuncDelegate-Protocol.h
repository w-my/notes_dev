//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MMVoidBoolI32Callback, MMVoidCallback, NSString;

@protocol MMIUIPagePlatformFuncDelegate <NSObject>
- (void)stopLoading;
- (void)startLoading:(NSString *)arg1 block:(_Bool)arg2;
- (void)endIgnoringInteractionEvents;
- (void)beginIgnoringInteractionEvents;
- (void)setKeyBoardShowCallbackImpl:(MMVoidBoolI32Callback *)arg1;
- (void)closeUI;
- (void)endEditing;
- (void)setBackgroundColor:(long long)arg1;
- (void)refreshNavigationBar;
- (void)setTopRightBtnTitle:(NSString *)arg1 color:(NSString *)arg2;
- (void)setTopRightBtnImage:(NSString *)arg1;
- (void)setTopRightCallbackImpl:(MMVoidCallback *)arg1;
- (void)setTopLeftBackBtnCallbackImpl:(MMVoidCallback *)arg1;
- (NSString *)getTitle;
- (void)setTitle:(NSString *)arg1;
@end
