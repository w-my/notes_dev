//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class AVAsset, TVKPlayerSlice;

@protocol TVKMediaPlayerDelegate <NSObject>

@optional
- (void)notifyPlayerMsg:(id <TVKIMediaPlayer>)arg1 msgId:(long long)arg2;
- (AVAsset *)assembleAVAsset:(id <TVKIMediaPlayer>)arg1 descID:(long long)arg2 slice:(TVKPlayerSlice *)arg3 sliceIndex:(unsigned long long)arg4;
- (void)notifyPlayerMsg:(id <TVKIMediaPlayer>)arg1 msgType:(long long)arg2 descID:(long long)arg3 extra1:(id)arg4 extra2:(id)arg5;
@end

