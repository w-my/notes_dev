//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCPayBaseViewController.h"

#import "WCPayLogicMgrExt.h"

@class MMUILabel, NSString, TenpayEditableBankNum, UIImage, UIImageView;

@interface WCPayCardNumberConfirmViewController : WCPayBaseViewController <WCPayLogicMgrExt>
{
    _Bool _didRenderViews;
    NSString *_origin3DESText;
    id <WCPayFillCardNumberViewControllerDelegate> _delegate;
    NSString *_encryptedCardNumStr;
    UIImage *_cardImage;
    MMUILabel *_label;
    TenpayEditableBankNum *_editBankNumView;
    UIImageView *_cardImageView;
}

@property(retain, nonatomic) UIImageView *cardImageView; // @synthesize cardImageView=_cardImageView;
@property(retain, nonatomic) TenpayEditableBankNum *editBankNumView; // @synthesize editBankNumView=_editBankNumView;
@property(retain, nonatomic) MMUILabel *label; // @synthesize label=_label;
@property(retain, nonatomic) UIImage *cardImage; // @synthesize cardImage=_cardImage;
@property(copy, nonatomic) NSString *encryptedCardNumStr; // @synthesize encryptedCardNumStr=_encryptedCardNumStr;
@property(nonatomic) __weak id <WCPayFillCardNumberViewControllerDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)nextAction:(id)arg1;
- (void)viewDidTransitionToNewSize;
- (void)viewDidLayoutSubviews;
- (id)getContainerView;
- (void)setupViewsIfNeed;
- (void)viewDidBePoped:(_Bool)arg1;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewWillAppear:(_Bool)arg1;
- (void)dealloc;
- (void)viewDidLoad;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

