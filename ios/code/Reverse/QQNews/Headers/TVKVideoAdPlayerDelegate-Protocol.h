//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSError, TVKVideoAdPlayer;

@protocol TVKVideoAdPlayerDelegate <NSObject>
- (void)onVideoAdPlayer:(TVKVideoAdPlayer *)arg1 stateChanged:(int)arg2 error:(NSError *)arg3;

@optional
- (void)onVideoAdPlayer:(TVKVideoAdPlayer *)arg1 itemDidPlayToEnd:(long long)arg2;
- (void)onVideoAdPlayer:(TVKVideoAdPlayer *)arg1 eventChanged:(int)arg2;
@end

