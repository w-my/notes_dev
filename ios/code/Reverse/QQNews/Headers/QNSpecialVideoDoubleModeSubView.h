//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableControl.h"

@class CSimpleImageView, QNLabel, QNListNewsItem, UIImageView, UIView;

@interface QNSpecialVideoDoubleModeSubView : QNThemableControl
{
    CSimpleImageView *_vImage;
    QNLabel *_vLabel;
    UIImageView *_videoIcon;
    UIImageView *_flagImage;
    UIView *_blackCover;
    QNListNewsItem *_listItem;
}

+ (id)currentSelectedView;
+ (void)setCurrentSelectedView:(id)arg1;
- (void).cxx_destruct;
- (void)showContent:(id)arg1;
- (void)onCellTouchUp;
- (void)onCellTouchDown;
- (void)reLayoutViews;
- (void)themeChanged:(long long)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

