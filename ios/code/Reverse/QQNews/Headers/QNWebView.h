//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNWebViewBase.h"

#import "QNDetailContentElementProtocol.h"
#import "WKNavigationDelegate.h"

@class NSMutableSet, NSString, QNDetailContentContainer, QNListNewsItem, UIImageView, WKWebViewJavascriptBridge;

@interface QNWebView : QNWebViewBase <QNDetailContentElementProtocol, WKNavigationDelegate>
{
    _Bool _didFinishLoad;
    _Bool _shadowEnabled;
    struct QNWebViewSettings _settings;
    QNListNewsItem *_listItem;
    QNDetailContentContainer *_parentContainer;
    WKWebViewJavascriptBridge *_jsBridge;
    NSMutableSet *_customCookieNameSet;
    UIImageView *_bottomShadow;
    NSString *_requestURLString;
}

@property(copy, nonatomic) NSString *requestURLString; // @synthesize requestURLString=_requestURLString;
@property(retain, nonatomic) UIImageView *bottomShadow; // @synthesize bottomShadow=_bottomShadow;
@property(retain, nonatomic) NSMutableSet *customCookieNameSet; // @synthesize customCookieNameSet=_customCookieNameSet;
@property(nonatomic) _Bool shadowEnabled; // @synthesize shadowEnabled=_shadowEnabled;
@property(nonatomic) _Bool didFinishLoad; // @synthesize didFinishLoad=_didFinishLoad;
@property(retain, nonatomic) WKWebViewJavascriptBridge *jsBridge; // @synthesize jsBridge=_jsBridge;
@property(nonatomic) __weak QNDetailContentContainer *parentContainer; // @synthesize parentContainer=_parentContainer;
@property(nonatomic) struct QNWebViewSettings settings; // @synthesize settings=_settings;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
- (void).cxx_destruct;
- (void)prepareForEnqueue;
- (void)prepareForReuse;
- (void)webView:(id)arg1 didFinishNavigation:(id)arg2;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)p_deleteCustomCookies;
- (void)injectCustomCookiesComplete:(CDUnknownBlockType)arg1;
- (id)p_cmsFontJSWithSizeType:(long long)arg1;
- (void)p_resetArticleFontSize:(id)arg1;
- (void)p_autoScroll2TopWhenTapStatusBar;
- (void)p_injectTencentJavascriptIntoWebView;
- (void)qn_stopEdting;
- (void)qn_refresh;
- (void)qn_goForward;
- (void)qn_goBack;
- (void)qn_loadRequestByURL:(id)arg1;
- (void)scroll2TopForWebview;
- (void)scroll2Top;
- (void)injectJSCompleted;
- (void)setWebViewDelegate:(id)arg1;
- (void)enableShadowImage;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1 configuration:(id)arg2;
- (id)initWithCoder:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1 type:(long long)arg2;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)init;
- (_Bool)canPerformAction:(SEL)arg1 withSender:(id)arg2;
- (_Bool)canBecomeFirstResponder;
- (id)p_applicationNavigationController;
- (void)p_reportAction:(id)arg1 withWord:(id)arg2;
- (id)p_processedText:(id)arg1;
- (void)p_uploadErrorWords;
- (void)qnErrorWordsReport:(id)arg1;
- (void)qnsearch:(id)arg1;
- (void)qnNewsSearch:(id)arg1;
@property(nonatomic) _Bool errorWordsItemHiden;
- (_Bool)shouldObserveOffsetChange;
- (void)didRemovedFromContentContainer:(id)arg1;
- (void)contentContainer:(id)arg1 ScrolledToPosition:(struct CGPoint)arg2;
- (void)p_reloadWithShowHeight:(double)arg1 foldHeight:(double)arg2;
- (void)tryFoldWebViewWithNewSize:(struct CGSize)arg1;
- (void)willBeAddedToContentContainer:(id)arg1;
- (id)contentScrollView;
- (double)heightOfElementView;
@property(nonatomic) double foldHeight;
@property(nonatomic) _Bool enableFold;
@property(nonatomic) _Bool invalid;
@property(nonatomic) _Bool completelyLoaded;
@property(nonatomic) double showHeight;
@property(nonatomic) __weak QNDetailContentContainer *contentContainer;
- (id)_jsForDocumentHeight;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
