//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class QNAudioBannerItemView, UIView;

@interface QNAudioChannelBanner : QNThemableView
{
    QNAudioBannerItemView *_managerItemView;
    QNAudioBannerItemView *_downloadItemView;
    QNAudioBannerItemView *_settingItemView;
    UIView *_bottomLine;
}

@property(retain, nonatomic) UIView *bottomLine; // @synthesize bottomLine=_bottomLine;
@property(retain, nonatomic) QNAudioBannerItemView *settingItemView; // @synthesize settingItemView=_settingItemView;
@property(retain, nonatomic) QNAudioBannerItemView *downloadItemView; // @synthesize downloadItemView=_downloadItemView;
@property(retain, nonatomic) QNAudioBannerItemView *managerItemView; // @synthesize managerItemView=_managerItemView;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end
