//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class CALayer, UIImageView, UILabel;

@interface QNBrightnessView : UIView
{
    UIImageView *_processImageView;
    UIImageView *_lightIcon;
    UILabel *_lightLable;
    CALayer *_processMaskLayer;
}

@property(retain, nonatomic) CALayer *processMaskLayer; // @synthesize processMaskLayer=_processMaskLayer;
@property(retain, nonatomic) UILabel *lightLable; // @synthesize lightLable=_lightLable;
@property(retain, nonatomic) UIImageView *lightIcon; // @synthesize lightIcon=_lightIcon;
@property(retain, nonatomic) UIImageView *processImageView; // @synthesize processImageView=_processImageView;
- (void).cxx_destruct;
- (void)setBrightness:(double)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end
