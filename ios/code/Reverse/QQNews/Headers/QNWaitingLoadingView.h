//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class NSTimer, UIImageView, UILabel;

@interface QNWaitingLoadingView : UIView
{
    UIImageView *_loadingView;
    UILabel *_speedLabel;
    UILabel *_defaultLabel;
    NSTimer *_updateTimer;
    double _speed;
    double _lastMesureTime;
    unsigned long long _lastMesureBytes;
    unsigned long long _currentWWANBytes;
}

@property(nonatomic) unsigned long long currentWWANBytes; // @synthesize currentWWANBytes=_currentWWANBytes;
@property(nonatomic) unsigned long long lastMesureBytes; // @synthesize lastMesureBytes=_lastMesureBytes;
@property(nonatomic) double lastMesureTime; // @synthesize lastMesureTime=_lastMesureTime;
@property(nonatomic) double speed; // @synthesize speed=_speed;
@property(retain, nonatomic) NSTimer *updateTimer; // @synthesize updateTimer=_updateTimer;
@property(retain, nonatomic) UILabel *defaultLabel; // @synthesize defaultLabel=_defaultLabel;
@property(retain, nonatomic) UILabel *speedLabel; // @synthesize speedLabel=_speedLabel;
@property(retain, nonatomic) UIImageView *loadingView; // @synthesize loadingView=_loadingView;
- (void).cxx_destruct;
- (_Bool)networkIsReachable;
- (_Bool)isString:(const char *)arg1 hasPrefix:(const char *)arg2 preLen:(int)arg3;
- (_Bool)getDataCounters:(unsigned long long *)arg1:(unsigned long long *)arg2:(unsigned long long *)arg3:(unsigned long long *)arg4;
- (void)networkSpeedUpdate:(id)arg1;
- (void)loadingViewAnimation:(_Bool)arg1;
- (_Bool)layerHasAnimation;
- (void)stopAnimation;
- (void)stopUpdate;
- (void)startAnimation;
- (void)setHidden:(_Bool)arg1;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

@end
