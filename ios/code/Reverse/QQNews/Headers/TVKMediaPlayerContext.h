//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class TVKEventCenter, TVKMediaInfo, TVKMediaPlayer, TVKMediaPlayerInfoEventSender, TVKVideoView;

@interface TVKMediaPlayerContext : NSObject
{
    TVKMediaInfo *_mediaInfo;
    TVKMediaPlayer *_mediaPlayer;
    TVKVideoView *_videoView;
    TVKMediaPlayerInfoEventSender *_eventSender;
    TVKEventCenter *_pluginEventCenter;
}

@property(retain, nonatomic) TVKEventCenter *pluginEventCenter; // @synthesize pluginEventCenter=_pluginEventCenter;
@property(retain, nonatomic) TVKMediaPlayerInfoEventSender *eventSender; // @synthesize eventSender=_eventSender;
@property(nonatomic) __weak TVKVideoView *videoView; // @synthesize videoView=_videoView;
@property(nonatomic) __weak TVKMediaPlayer *mediaPlayer; // @synthesize mediaPlayer=_mediaPlayer;
@property(retain, nonatomic) TVKMediaInfo *mediaInfo; // @synthesize mediaInfo=_mediaInfo;
- (void).cxx_destruct;

@end
