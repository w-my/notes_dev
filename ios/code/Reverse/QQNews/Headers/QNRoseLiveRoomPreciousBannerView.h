//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CSimpleImageView.h"

@class NSString, UIImageView, UILabel, UIView;

@interface QNRoseLiveRoomPreciousBannerView : CSimpleImageView
{
    NSString *_title;
    NSString *_intro;
    UILabel *_titleLabel;
    UILabel *_introLabel;
    double _titleOriginalWidth;
    UIImageView *_gradientView;
    UIView *_glassView;
    struct CGPoint _titleOriginalCenter;
    struct CGSize _lastBoundSize;
}

@property(retain, nonatomic) UIView *glassView; // @synthesize glassView=_glassView;
@property(nonatomic) struct CGSize lastBoundSize; // @synthesize lastBoundSize=_lastBoundSize;
@property(retain, nonatomic) UIImageView *gradientView; // @synthesize gradientView=_gradientView;
@property(nonatomic) double titleOriginalWidth; // @synthesize titleOriginalWidth=_titleOriginalWidth;
@property(nonatomic) struct CGPoint titleOriginalCenter; // @synthesize titleOriginalCenter=_titleOriginalCenter;
@property(retain, nonatomic) UILabel *introLabel; // @synthesize introLabel=_introLabel;
@property(retain, nonatomic) UILabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(copy, nonatomic) NSString *intro; // @synthesize intro=_intro;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
- (void).cxx_destruct;
- (void)updateTopPosition:(double)arg1 maxOffset:(double)arg2;
- (void)layoutSubviews;
- (void)_layoutUI;
- (void)_commonInit;
- (id)_gradientImage;
- (id)initWithFrame:(struct CGRect)arg1;

@end

