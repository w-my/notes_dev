//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class CAGradientLayer, QNBaseLabel, UIScrollView;

@interface QNRoseLiveRoomGuestView : QNThemableView
{
    QNBaseLabel *_topLabel;
    QNBaseLabel *_bottomLabel;
    UIScrollView *_scrollView;
    CAGradientLayer *_gradientLayer;
}

@property(retain, nonatomic) CAGradientLayer *gradientLayer; // @synthesize gradientLayer=_gradientLayer;
@property(retain, nonatomic) UIScrollView *scrollView; // @synthesize scrollView=_scrollView;
@property(retain, nonatomic) QNBaseLabel *bottomLabel; // @synthesize bottomLabel=_bottomLabel;
@property(retain, nonatomic) QNBaseLabel *topLabel; // @synthesize topLabel=_topLabel;
- (void).cxx_destruct;
- (void)layoutWithGuestViewModel:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

