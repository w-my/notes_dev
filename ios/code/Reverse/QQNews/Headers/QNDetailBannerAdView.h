//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "CSimpleImageViewDelegate.h"

@class CSimpleImageView, NSString, QNAdItem, QNBannerAdIcon;

@interface QNDetailBannerAdView : QNThemableView <CSimpleImageViewDelegate>
{
    CDUnknownBlockType _liveBannerAdOpenLandingView;
    CSimpleImageView *_bannerAdImageView;
    QNBannerAdIcon *_adIcon;
    QNAdItem *_bannerAd;
}

+ (double)_imageHeight:(id)arg1;
@property(retain, nonatomic) QNAdItem *bannerAd; // @synthesize bannerAd=_bannerAd;
@property(retain, nonatomic) QNBannerAdIcon *adIcon; // @synthesize adIcon=_adIcon;
@property(retain, nonatomic) CSimpleImageView *bannerAdImageView; // @synthesize bannerAdImageView=_bannerAdImageView;
@property(copy, nonatomic) CDUnknownBlockType liveBannerAdOpenLandingView; // @synthesize liveBannerAdOpenLandingView=_liveBannerAdOpenLandingView;
- (void).cxx_destruct;
- (void)setImageCompletedWithImageView:(id)arg1 image:(id)arg2;
- (struct CGSize)imageSize:(id)arg1;
- (void)bannerAdTapped:(id)arg1;
- (void)updateWithBannerAd:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

