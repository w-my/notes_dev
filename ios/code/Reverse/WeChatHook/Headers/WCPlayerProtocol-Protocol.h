//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class UIImage, UIView<WCPlayerControlProtocol>, WCPlayerPlayArgs;

@protocol WCPlayerProtocol <NSObject>
- (void)configWithPlayerInfo:(WCPlayerPlayArgs *)arg1 ControlView:(UIView<WCPlayerControlProtocol> *)arg2;

@optional
- (id)initPlayerWithFrame:(struct CGRect)arg1 PlayArgs:(WCPlayerPlayArgs *)arg2 ControlView:(UIView<WCPlayerControlProtocol> *)arg3;
- (void)changeToDownloadFirstWithDownloadMode:(unsigned long long)arg1;
- (void)stopVideoDowload;
- (void)startWithPlayerMode:(unsigned long long)arg1;
- (void)setThumbImageHidden:(_Bool)arg1;
- (void)setThumbImage:(UIImage *)arg1;
- (void)onSliderScrubbingDidEndAtTime:(double)arg1;
- (void)onScrubbedToTime:(double)arg1;
- (void)onSliderScrubbingDidStart;
- (void)setPlayerMaxBufferLength:(unsigned int)arg1;
- (void)setPlayerContentMode:(long long)arg1;
- (void)setPlayerToMuted:(_Bool)arg1;
- (void)setPlayBackRate:(float)arg1;
- (UIImage *)getThumbnailImageAtCurrentTime;
- (void)pauseVideo;
- (void)playVideo;
- (void)clearPlayer;
- (void)stopPlayer;
- (void)startPlayer;
- (void)preload;
@end
