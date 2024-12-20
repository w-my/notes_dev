//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "WKNavigationDelegate.h"

@class NSIndexPath, NSString, QNCarItem, QNLoadingShimmerView, QNWebView, QNWebViewJSOpenAPI, UIButton;

@interface QNSearchCarWebView : QNThemableView <WKNavigationDelegate>
{
    _Bool _didFinishLoad;
    QNCarItem *_carItem;
    NSString *_queryWord;
    QNWebViewJSOpenAPI *_jsOpenApi;
    id <QNSearchControllerDelegate> _controllerDelegate;
    QNWebView *_webView;
    NSIndexPath *_indexPath;
    unsigned long long _realIndex;
    double _startTime;
    QNLoadingShimmerView *_loadingView;
    UIButton *_reloadBtnView;
}

@property(retain, nonatomic) UIButton *reloadBtnView; // @synthesize reloadBtnView=_reloadBtnView;
@property(retain, nonatomic) QNLoadingShimmerView *loadingView; // @synthesize loadingView=_loadingView;
@property(nonatomic) double startTime; // @synthesize startTime=_startTime;
@property(nonatomic) unsigned long long realIndex; // @synthesize realIndex=_realIndex;
@property(retain, nonatomic) NSIndexPath *indexPath; // @synthesize indexPath=_indexPath;
@property(retain, nonatomic) QNWebView *webView; // @synthesize webView=_webView;
@property(nonatomic) __weak id <QNSearchControllerDelegate> controllerDelegate; // @synthesize controllerDelegate=_controllerDelegate;
@property(retain, nonatomic) QNWebViewJSOpenAPI *jsOpenApi; // @synthesize jsOpenApi=_jsOpenApi;
@property(copy, nonatomic) NSString *queryWord; // @synthesize queryWord=_queryWord;
@property(retain, nonatomic) QNCarItem *carItem; // @synthesize carItem=_carItem;
@property(nonatomic) _Bool didFinishLoad; // @synthesize didFinishLoad=_didFinishLoad;
- (void).cxx_destruct;
- (void)p_reloadBtnClicked;
- (void)p_showReloadBtnView;
- (void)p_removeLoadingView;
- (void)p_showLoadingView;
- (void)p_handleFailWithError:(id)arg1;
- (void)webView:(id)arg1 didFailNavigation:(id)arg2 withError:(id)arg3;
- (void)webView:(id)arg1 didFailProvisionalNavigation:(id)arg2 withError:(id)arg3;
- (void)webView:(id)arg1 didFinishNavigation:(id)arg2;
- (void)webView:(id)arg1 didStartProvisionalNavigation:(id)arg2;
- (id)p_getValidUrlString:(id)arg1 realIndex:(unsigned long long)arg2;
- (void)layoutWithCarItem:(id)arg1 controllerDelegate:(id)arg2 indexPath:(id)arg3 realIndex:(unsigned long long)arg4 andQueryWord:(id)arg5;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

