//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, QNTVKMediaPlayer, TADLandingInfo;

@protocol QNTVKMediaPlayerDelegate <NSObject>

@optional
- (_Bool)shouldHideGPRSRemind;
- (void)mediaPlayer:(QNTVKMediaPlayer *)arg1 adLandingInfo:(TADLandingInfo *)arg2;
- (void)playFinshed;
- (void)playerStateChanged;
- (void)updateProgress:(double)arg1 bufferTime:(double)arg2 duration:(double)arg3;
- (_Bool)switchPlayerTypeToFullScreen:(_Bool)arg1 animation:(_Bool)arg2 isRotate:(_Bool)arg3 completeAnimation:(void (^)(void))arg4;
- (void)refreshDanmuWithArray:(NSArray *)arg1 isLive:(_Bool)arg2;
@end
