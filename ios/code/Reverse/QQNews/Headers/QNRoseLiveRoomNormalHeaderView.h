//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class CAGradientLayer, QNPlayerCoverView, QNRoseLiveRoomGuestView, QNRoseLiveRoomViewerCountButton, UIImageView, UILabel;

@interface QNRoseLiveRoomNormalHeaderView : QNThemableView
{
    QNPlayerCoverView *_imageView;
    CDUnknownBlockType _playBlock;
    QNRoseLiveRoomViewerCountButton *_countView;
    QNRoseLiveRoomGuestView *_guestView;
    UILabel *_timeLabel;
    long long _type;
    CAGradientLayer *_gradientLayer;
    UIImageView *_flagImageView;
}

@property(retain, nonatomic) UIImageView *flagImageView; // @synthesize flagImageView=_flagImageView;
@property(retain, nonatomic) CAGradientLayer *gradientLayer; // @synthesize gradientLayer=_gradientLayer;
@property(nonatomic) long long type; // @synthesize type=_type;
@property(retain, nonatomic) UILabel *timeLabel; // @synthesize timeLabel=_timeLabel;
@property(retain, nonatomic) QNRoseLiveRoomGuestView *guestView; // @synthesize guestView=_guestView;
@property(retain, nonatomic) QNRoseLiveRoomViewerCountButton *countView; // @synthesize countView=_countView;
@property(copy, nonatomic) CDUnknownBlockType playBlock; // @synthesize playBlock=_playBlock;
@property(retain, nonatomic) QNPlayerCoverView *imageView; // @synthesize imageView=_imageView;
- (void).cxx_destruct;
- (void)p_videoPlayButtonClicked;
- (void)headerViewDidScroll:(double)arg1;
- (void)updateWithViewModel:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1 type:(long long)arg2;

@end

