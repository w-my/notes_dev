//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIView.h"

#import "WASubscriptionMessagePageSheetContentViewProtocol.h"
#import "WASubscriptionMessagePageSheetFooterViewDelegate.h"
#import "WASubscriptionMessagePageSheetListStyleContentViewDelegate.h"

@class NSString, UIScrollView, WASubscriptionMessagePageSheetFooterView, WASubscriptionMessagePageSheetHeaderView, WASubscriptionMessagePageSheetListStyleContentView, WASubscriptionMessagePageSheetViewModel;

@interface WASubscriptionMessagePageSheetListStyleView : MMUIView <WASubscriptionMessagePageSheetListStyleContentViewDelegate, WASubscriptionMessagePageSheetFooterViewDelegate, WASubscriptionMessagePageSheetContentViewProtocol>
{
    id <WASubscriptionMessagePageSheetContentViewDelegate> contentViewDelegate;
    WASubscriptionMessagePageSheetViewModel *_viewModel;
    WASubscriptionMessagePageSheetHeaderView *_headerView;
    WASubscriptionMessagePageSheetListStyleContentView *_temporaryContentView;
    WASubscriptionMessagePageSheetFooterView *_footerView;
    UIScrollView *_scrollView;
}

@property(retain, nonatomic) UIScrollView *scrollView; // @synthesize scrollView=_scrollView;
@property(retain, nonatomic) WASubscriptionMessagePageSheetFooterView *footerView; // @synthesize footerView=_footerView;
@property(retain, nonatomic) WASubscriptionMessagePageSheetListStyleContentView *temporaryContentView; // @synthesize temporaryContentView=_temporaryContentView;
@property(retain, nonatomic) WASubscriptionMessagePageSheetHeaderView *headerView; // @synthesize headerView=_headerView;
@property(retain, nonatomic) WASubscriptionMessagePageSheetViewModel *viewModel; // @synthesize viewModel=_viewModel;
@property(nonatomic) __weak id <WASubscriptionMessagePageSheetContentViewDelegate> contentViewDelegate; // @synthesize contentViewDelegate;
- (void).cxx_destruct;
- (void)onInfoButtonClickedAtIndex:(unsigned long long)arg1;
- (void)selectedStatusDidChanged:(id)arg1;
- (void)onFooterViewDeclineButtonClicked:(id)arg1;
- (void)onFooterViewCancelButtonClicked:(id)arg1;
- (void)onFooterViewConfirmButtonClicked:(id)arg1;
- (void)addSubviews:(id)arg1;
- (void)loadAllSubviews;
- (double)calculateContentHeight:(double)arg1 height:(double)arg2;
- (double)calculateMaxContentViewHeight;
- (void)layoutSubviews;
- (double)calculateHeight:(double)arg1;
- (id)initWithViewModel:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
