//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CWebViewController.h"

#import "QNShareActivityControllerDelegate.h"

@class CCarHomeEntryItem, NSString, QNThemeMaskView, UISwipeGestureRecognizer;

@interface CCarCommonWebViewController : CWebViewController <QNShareActivityControllerDelegate>
{
    QNThemeMaskView *_maskView;
    CCarHomeEntryItem *_entryItem;
    UISwipeGestureRecognizer *_swipteGesture;
}

@property(retain, nonatomic) UISwipeGestureRecognizer *swipteGesture; // @synthesize swipteGesture=_swipteGesture;
@property(retain, nonatomic) CCarHomeEntryItem *entryItem; // @synthesize entryItem=_entryItem;
- (void).cxx_destruct;
- (void)webView:(id)arg1 didFailNavigation:(id)arg2 withError:(id)arg3;
- (void)webView:(id)arg1 didFailProvisionalNavigation:(id)arg2 withError:(id)arg3;
- (void)webView:(id)arg1 didFinishNavigation:(id)arg2;
- (long long)do_webView:(id)arg1 decidedPolicyForNavigationAction:(id)arg2;
- (void)refreshCurrentPage;
- (id)getShareToEmailInfo;
- (id)getCustomDeletedShareItems;
- (id)listItemForShare;
- (void)loadWebViewFromURL;
- (void)configTitleView;
- (void)onBack:(id)arg1;
- (void)onAction:(id)arg1;
- (void)configBarButtons;
- (void)handleErrorViewTap:(id)arg1;
- (void)didReceiveMemoryWarning;
- (void)viewDidLoad;
- (id)initCarLoan:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(copy, nonatomic) NSString *requestUrl;
@property(readonly) Class superclass;

@end

