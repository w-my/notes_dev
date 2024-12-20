//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRoseLiveRoomPictureFragmentView.h"

@class CIconButton, CSimpleImageView, QNRoseLiveRoomPreciousPhotoWaterMarkView, UILabel;

@interface QNRoseLiveRoomPreciousPictureFragmentView : QNRoseLiveRoomPictureFragmentView
{
    _Bool _displaySupportButton;
    CIconButton *_supportButton;
    id <QNRoseLiveRoomFullScreenPictureDelegate> _fullScreenDelegate;
    long long _rank;
    QNRoseLiveRoomPreciousPhotoWaterMarkView *_waterMarkView;
    CSimpleImageView *_rankBgView;
    UILabel *_rankLabel;
}

+ (struct CGSize)imageNodeScale:(id)arg1 width:(double)arg2;
@property(retain, nonatomic) UILabel *rankLabel; // @synthesize rankLabel=_rankLabel;
@property(retain, nonatomic) CSimpleImageView *rankBgView; // @synthesize rankBgView=_rankBgView;
@property(retain, nonatomic) QNRoseLiveRoomPreciousPhotoWaterMarkView *waterMarkView; // @synthesize waterMarkView=_waterMarkView;
@property(nonatomic) long long rank; // @synthesize rank=_rank;
@property(nonatomic) __weak id <QNRoseLiveRoomFullScreenPictureDelegate> fullScreenDelegate; // @synthesize fullScreenDelegate=_fullScreenDelegate;
@property(retain, nonatomic) CIconButton *supportButton; // @synthesize supportButton=_supportButton;
@property(nonatomic) _Bool displaySupportButton; // @synthesize displaySupportButton=_displaySupportButton;
- (void).cxx_destruct;
- (void)touchesEnded:(id)arg1 withEvent:(id)arg2;
- (void)layoutRankView;
- (void)layoutSubviewsImmediately;
- (void)updateSupportButtonImage;
- (void)p_setupSupportButton;
- (id)initWithFrame:(struct CGRect)arg1;

@end

