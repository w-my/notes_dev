//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "UIGestureRecognizerDelegate.h"
#import "WKNavigationDelegate.h"

@class CPortfolioDetailController, NSString, QNSimpleWebView, UIButton, UIImageView, UIView;

@interface CPortfolioDetailView : QNThemableView <WKNavigationDelegate, UIGestureRecognizerDelegate>
{
    _Bool isExposureOpenButton;
    _Bool _bJump;
    NSString *_stockCode;
    CPortfolioDetailController *_myController;
    QNSimpleWebView *_webView;
    NSString *_detailUrlStr;
    UIView *_retryView;
}

@property(retain, nonatomic) UIView *retryView; // @synthesize retryView=_retryView;
@property(nonatomic) _Bool bJump; // @synthesize bJump=_bJump;
@property(copy, nonatomic) NSString *detailUrlStr; // @synthesize detailUrlStr=_detailUrlStr;
@property(retain, nonatomic) QNSimpleWebView *webView; // @synthesize webView=_webView;
@property(nonatomic) CPortfolioDetailController *myController; // @synthesize myController=_myController;
@property(retain, nonatomic) NSString *stockCode; // @synthesize stockCode=_stockCode;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (_Bool)gestureRecognizer:(id)arg1 shouldReceiveTouch:(id)arg2;
- (_Bool)gestureRecognizer:(id)arg1 shouldRecognizeSimultaneouslyWithGestureRecognizer:(id)arg2;
- (_Bool)gestureRecognizerShouldBegin:(id)arg1;
- (void)scrolltoTop;
- (void)retryLoadContent:(id)arg1;
- (void)failLoadContent;
- (void)showWebView;
- (void)showErrorView:(id)arg1;
- (void)webViewWebContentProcessDidTerminate:(id)arg1;
- (void)webView:(id)arg1 didFailProvisionalNavigation:(id)arg2 withError:(id)arg3;
- (void)webView:(id)arg1 didFinishNavigation:(id)arg2;
- (void)openURL:(id)arg1;
- (void)webView:(id)arg1 decidePolicyForNavigationAction:(id)arg2 decisionHandler:(CDUnknownBlockType)arg3;
- (void)loadWebViewInBackground:(id)arg1;
- (void)loadWebContent;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1 stockCode:(id)arg2;
@property(nonatomic) UIButton *retryButtonView; // @dynamic retryButtonView;
@property(nonatomic) UIImageView *logoView; // @dynamic logoView;
@property(readonly, nonatomic) UIView *emptyView;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

