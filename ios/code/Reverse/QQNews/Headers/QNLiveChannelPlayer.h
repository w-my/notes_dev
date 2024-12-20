//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNPlayer.h"

@class NSString, QNDanmuViewModel;

@interface QNLiveChannelPlayer : QNPlayer
{
    NSString *_videoId;
    QNDanmuViewModel *_danmuViewModel;
    NSString *_broadcastId;
    NSString *_latestPid;
}

@property(copy, nonatomic) NSString *latestPid; // @synthesize latestPid=_latestPid;
@property(copy, nonatomic) NSString *broadcastId; // @synthesize broadcastId=_broadcastId;
@property(retain, nonatomic) QNDanmuViewModel *danmuViewModel; // @synthesize danmuViewModel=_danmuViewModel;
@property(copy, nonatomic) NSString *videoId; // @synthesize videoId=_videoId;
- (void).cxx_destruct;
- (void)playerStateChanged;
- (id)getFullScreenContolView;
- (void)closeGuideMultiChannelView;
- (void)showGuideMultiChannelView;
- (_Bool)isCurrentPlayWithBrodCastNode:(id)arg1;
- (void)playMultiVideoWithid:(id)arg1 pid:(id)arg2 isMultiStream:(_Bool)arg3;
- (void)changeMultiChannel:(id)arg1 image:(id)arg2;
- (_Bool)changeMultiChannel:(id)arg1;
- (_Bool)currentBroadcastIsSupprotVR;
- (void)sendDanmu:(id)arg1;
- (void)setSupportsDanmaku:(_Bool)arg1;
- (void)refreshDanmuWithArray:(id)arg1 isLive:(_Bool)arg2;
- (void)setliveInfoViewModel:(id)arg1 likeItem:(id)arg2;
- (id)p_getCurrentBroadcaseWithId:(id)arg1;
- (void)beginPlay;
- (void)playNewItemIsFromRemind:(_Bool)arg1;
- (void)playNewItem;
- (void)setPlayerParamBeforePlay;
- (_Bool)isLandscapeVideo;
@property(nonatomic) _Bool isPortraitScreen;
- (void)play;
- (_Bool)isRoseLiveVideo;
- (void)loadVideoInfoWithListItem:(id)arg1 videoInfo:(id)arg2 param:(id)arg3;

@end

