//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "KBTableViewCell.h"

#import "WKNavigationDelegate.h"

@class KBListItem, KBTableViewCellLayoutContext, NSString, QNEnlargeHitTestButton, QNHttpBridge, QNListCellPackupTipView, QNSecureHTMLContentWebView, UIImageView, UIScrollView;

@interface CWebViewCell : KBTableViewCell <WKNavigationDelegate>
{
    QNHttpBridge *_httpBridge;
    NSString *_idStr;
    NSString *_url;
    UIImageView *_shortcut;
    _Bool _needValidateTheme;
    _Bool _needReloadWebView;
    _Bool _isWebViewReady;
    _Bool _isWebviewLoaded;
    _Bool _isCellError;
    _Bool _shouldUseSecureHTMLTransfer;
    _Bool _hasLayouted;
    UIScrollView *_scrollView;
    id <QNWebviewCellDelegate> _delegate;
    NSString *_channelID;
    QNSecureHTMLContentWebView *_webView;
    UIImageView *_bottomLine;
    QNEnlargeHitTestButton *_packupBtn;
    QNListCellPackupTipView *_packupTipView;
    KBListItem *_kbListItem;
    KBTableViewCellLayoutContext *_context;
}

+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
+ (id)reuseIdentifierForData:(id)arg1;
+ (id)do_reuseIdentifierForItem:(id)arg1;
@property(retain, nonatomic) KBTableViewCellLayoutContext *context; // @synthesize context=_context;
@property(retain, nonatomic) KBListItem *kbListItem; // @synthesize kbListItem=_kbListItem;
@property(retain, nonatomic) QNListCellPackupTipView *packupTipView; // @synthesize packupTipView=_packupTipView;
@property(retain, nonatomic) QNEnlargeHitTestButton *packupBtn; // @synthesize packupBtn=_packupBtn;
@property(retain, nonatomic) UIImageView *bottomLine; // @synthesize bottomLine=_bottomLine;
@property(nonatomic) _Bool hasLayouted; // @synthesize hasLayouted=_hasLayouted;
@property(nonatomic) _Bool shouldUseSecureHTMLTransfer; // @synthesize shouldUseSecureHTMLTransfer=_shouldUseSecureHTMLTransfer;
@property(retain, nonatomic) QNSecureHTMLContentWebView *webView; // @synthesize webView=_webView;
@property(retain, nonatomic) UIImageView *shortcut; // @synthesize shortcut=_shortcut;
@property(retain, nonatomic) QNHttpBridge *httpBridge; // @synthesize httpBridge=_httpBridge;
@property(copy, nonatomic) NSString *channelID; // @synthesize channelID=_channelID;
@property(copy, nonatomic) NSString *url; // @synthesize url=_url;
@property(copy, nonatomic) NSString *idStr; // @synthesize idStr=_idStr;
@property(nonatomic) __weak id <QNWebviewCellDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) UIScrollView *scrollView; // @synthesize scrollView=_scrollView;
- (void).cxx_destruct;
- (void)layoutWithData:(id)arg1 context:(id)arg2;
- (void)onWebCellReady;
- (void)cleanShortcut;
- (id)p_doSaveShortcut;
- (void)p_saveShortcut;
- (void)onWebCellError;
- (void)webView:(id)arg1 didFailProvisionalNavigation:(id)arg2 withError:(id)arg3;
- (void)webView:(id)arg1 didFinishNavigation:(id)arg2;
- (void)_onPackupBtnClicked:(id)arg1;
- (void)p_injectNativeJs;
- (void)p_loadWebViewContent:(id)arg1 context:(id)arg2;
- (void)p_tryReloadWebView;
- (void)p_doReloadWebView;
- (_Bool)p_showSnapshot:(id)arg1;
- (void)p_resetNeedReloadFlag;
- (id)p_getValidUrlString:(id)arg1;
- (_Bool)needLayoutForItem:(id)arg1;
- (void)themeChanged:(long long)arg1;
- (void)handelLoginStatusChanged:(id)arg1;
- (void)onStarSignDidChanged:(id)arg1;
- (void)handelChannelDidRefreshData:(id)arg1;
- (void)handelChannelDidDisappear:(id)arg1;
- (void)handelChannelDidAppear:(id)arg1;
- (void)willMoveToSuperview:(id)arg1;
- (void)dealloc;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
