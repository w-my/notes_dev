//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSError, QNAdItem;

@protocol TADTKVPlayerDelegate <NSObject>

@optional
- (void)playerOnSeekTo:(float)arg1;
- (void)playerOnMuted:(_Bool)arg1;
- (void)playerOnError:(NSError *)arg1;
- (void)playerProgressUpdated:(double)arg1 duration:(double)arg2;
- (void)playerDidFinish;
- (void)playerDidPlayed;
- (void)playerWillManuallyPlayed;
- (void)playerWillAutoPlayed;
- (void)playerDidPause;
- (void)playerGotoVideoLandingView;
- (void)playerGotoLandingView;
- (void)playerDidStop:(QNAdItem *)arg1;
@end
