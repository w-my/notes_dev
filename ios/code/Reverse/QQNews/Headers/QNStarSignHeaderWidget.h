//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNativeWidgetView.h"

@class UIImageView, UILabel;

@interface QNStarSignHeaderWidget : QNNativeWidgetView
{
    UIImageView *_icon;
    UILabel *_nameLabel;
    UILabel *_descLabel;
    UILabel *_timeLabel;
}

+ (struct CGSize)sizeForViewWithData:(id)arg1 width:(double)arg2 isNoPicMode:(_Bool)arg3;
@property(retain, nonatomic) UILabel *timeLabel; // @synthesize timeLabel=_timeLabel;
@property(retain, nonatomic) UILabel *descLabel; // @synthesize descLabel=_descLabel;
@property(retain, nonatomic) UILabel *nameLabel; // @synthesize nameLabel=_nameLabel;
@property(retain, nonatomic) UIImageView *icon; // @synthesize icon=_icon;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)p_starSignHeaderValidateTheme;
- (void)layoutViewWithData:(id)arg1;
- (long long)widgetViewType;
- (id)initWidget;
- (id)initWithFrame:(struct CGRect)arg1;

@end
