//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "BrandProfileMessageBaseCell.h"

#import "ILinkEventExt.h"

@class BrandProfileMessageTextViewModel, MMUIButton, NSString;

@interface BrandProfileMessageTextCell : BrandProfileMessageBaseCell <ILinkEventExt>
{
    MMUIButton *m_bottomButton;
}

- (void).cxx_destruct;
- (void)layoutSubviewsNormalItem;
- (void)layoutSubviewsTopItem;
- (void)onUpdateViewModel;
- (void)onBottomButtonClicked;
- (void)initBottomButton;
- (void)initNormalReaderItem;
- (void)initTopReaderItem;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;
@property(readonly, nonatomic) BrandProfileMessageTextViewModel *viewModel; // @dynamic viewModel;

@end

