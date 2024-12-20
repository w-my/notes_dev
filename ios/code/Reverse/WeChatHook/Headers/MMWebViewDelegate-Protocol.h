//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WXCustomWebViewControllerDelegate.h"

@class DeepLinkDef, MMWebViewController, NSDictionary, NSError, NSHTTPURLResponse, NSString, NSURL, UIView<YYWebViewInterface>;

@protocol MMWebViewDelegate <WXCustomWebViewControllerDelegate>

@optional
- (NSDictionary *)onWebViewPassParams:(NSDictionary *)arg1 Webview:(MMWebViewController *)arg2;
- (void)onLeaveWebviewAndBackTo3rdApp;
- (void)onLeaveWebviewAndJumpToViewConroller;
- (void)accessDeepLink:(DeepLinkDef *)arg1 Url:(NSString *)arg2 Webview:(MMWebViewController *)arg3;
- (_Bool)canAccessDeepLink:(DeepLinkDef *)arg1 Url:(NSString *)arg2 Webview:(MMWebViewController *)arg3;
- (void)setCanShake:(_Bool)arg1;
- (void)onWebViewCloseAndGoNext:(NSDictionary *)arg1;
- (void)onWebViewWillClose:(NSDictionary *)arg1;
- (void)onWebViewDidRotateFromInterfaceOrientation:(long long)arg1;
- (void)onWebViewWillRotateToInterfaceOrientation:(long long)arg1;
- (void)onWebViewDidFinishLoad:(UIView<YYWebViewInterface> *)arg1;
- (void)onWebViewDidStartLoad:(UIView<YYWebViewInterface> *)arg1;
- (NSURL *)webViewFailToLoad:(UIView<YYWebViewInterface> *)arg1 Error:(NSError *)arg2;
- (void)onWebViewDidReceiveResponse:(UIView<YYWebViewInterface> *)arg1 Response:(NSHTTPURLResponse *)arg2;
- (void)webViewDidReturn:(MMWebViewController *)arg1;
- (void)webViewReturn:(MMWebViewController *)arg1;
@end

