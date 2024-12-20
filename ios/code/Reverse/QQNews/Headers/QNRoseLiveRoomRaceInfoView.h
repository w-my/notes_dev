//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class QNBaseLabel, QNRoseLiveRoomSportRaceInfoModel, UIButton, UIImageView;

@interface QNRoseLiveRoomRaceInfoView : QNThemableView
{
    UIImageView *_flagIcon;
    UIImageView *_imageView;
    UIButton *_countView;
    QNBaseLabel *_htNick;
    QNBaseLabel *_htScore;
    UIImageView *_htLogo;
    QNBaseLabel *_atNick;
    QNBaseLabel *_atScore;
    UIImageView *_atLogo;
    QNBaseLabel *_vs;
    QNBaseLabel *_matchTime;
    _Bool _isInitialized;
    QNRoseLiveRoomSportRaceInfoModel *_raceInfo;
}

- (void).cxx_destruct;
- (void)showTitleViewWithAnimation:(_Bool)arg1;
- (void)hideTitleViewWithAnimation:(_Bool)arg1;
- (void)refreshViews:(id)arg1 offsetY:(float)arg2;
- (void)translateFrameWithOffsetY:(float)arg1;
- (void)p_setFrameByPercent:(float)arg1;
- (void)p_setBackgroundUrl:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

