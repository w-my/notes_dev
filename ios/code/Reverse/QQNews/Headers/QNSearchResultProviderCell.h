//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNSearchResultCellBase.h"

#import "CSimpleImageViewDelegate.h"

@class CSimpleImageView, NSString;

@interface QNSearchResultProviderCell : QNSearchResultCellBase <CSimpleImageViewDelegate>
{
    CSimpleImageView *_providerView;
}

@property(retain, nonatomic) CSimpleImageView *providerView; // @synthesize providerView=_providerView;
- (void).cxx_destruct;
- (void)qn_layoutSubviews;
- (void)downloadImageCompleteWithImageView:(id)arg1;
- (void)layoutWithCell;
- (void)layoutWithSearchItem:(id)arg1 withKeyWords:(id)arg2;
- (void)themeChanged:(long long)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
