//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class UIImageView, UILabel;

@interface QSMatchDetailVersusResultView : UIView
{
    UIImageView *_resultView;
    UILabel *_winLabel;
    UILabel *_flatLabel;
    UILabel *_lossLabel;
}

+ (void)drawRightWithContext:(struct CGContext *)arg1 startX:(double)arg2 endX:(double)arg3 height:(double)arg4 color:(id)arg5;
+ (void)drawMiddleWithContext:(struct CGContext *)arg1 startX:(double)arg2 endX:(double)arg3 height:(double)arg4 color:(id)arg5;
+ (void)drawLeftWithContext:(struct CGContext *)arg1 startX:(double)arg2 endX:(double)arg3 height:(double)arg4 color:(id)arg5;
+ (void)drawAllWithContext:(struct CGContext *)arg1 startX:(double)arg2 endX:(double)arg3 height:(double)arg4 color:(id)arg5;
+ (id)resultImageWithSize:(struct CGSize)arg1 versusItem:(id)arg2 flatCenterXPos:(double *)arg3;
+ (double)fixedHeight;
@property(retain, nonatomic) UILabel *lossLabel; // @synthesize lossLabel=_lossLabel;
@property(retain, nonatomic) UILabel *flatLabel; // @synthesize flatLabel=_flatLabel;
@property(retain, nonatomic) UILabel *winLabel; // @synthesize winLabel=_winLabel;
@property(retain, nonatomic) UIImageView *resultView; // @synthesize resultView=_resultView;
- (void).cxx_destruct;
- (id)createLabel;
- (void)refreshWithDetailInfo:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end
