//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSString, TVKPlayerVideo, UIImage;

@protocol TVKIPlayerBase <NSObject>
@property(readonly, nonatomic, getter=isPictureInPictureActive) _Bool pictureInPictureActive;
@property(readonly, nonatomic, getter=isPictureInPicturePossible) _Bool pictureInPicturePossible;
@property(nonatomic) _Bool enableResourceLoader;
@property(nonatomic) long long externalPlaybackVideoGravity;
@property(nonatomic) _Bool usesExternalPlaybackWhileExternalScreenIsActive;
@property(readonly, nonatomic, getter=isExternalPlaybackActive) _Bool externalPlaybackActive;
@property(nonatomic) _Bool allowsExternalPlayback;
@property(retain, nonatomic) id <TVKIPlayerViewBase> view;
@property(nonatomic) __weak id <TVKPlayerDelegate> delegate;
@property(readonly) long long state;
@property(readonly, nonatomic) unsigned long long videoHeight;
@property(readonly, nonatomic) unsigned long long videoWidth;
@property(readonly, nonatomic) long long bufferedDuration;
@property(readonly, nonatomic) long long position;
@property(readonly, nonatomic) long long duration;
@property(nonatomic) float rate;
@property(nonatomic) float volume;
- (void)stopPictureInPicture;
- (void)startPictureInPicture;
- (UIImage *)snapshot;
- (void)setLoopBack:(_Bool)arg1 startPos:(long long)arg2 endPos:(long long)arg3;
- (void)setExtraParameters:(long long)arg1 param1:(long long)arg2 param2:(long long)arg3 context:(void *)arg4;
- (void)seekToNextClip;
- (void)seekTo:(long long)arg1 mode:(long long)arg2;
- (void)stop;
- (void)pause;
- (void)start;
- (void)switchDefinitionWithVideo:(TVKPlayerVideo *)arg1 bakVideos:(NSArray *)arg2;
- (_Bool)supportSeamlesslySwitchDefinition:(long long)arg1 videoCodec:(long long)arg2;
- (_Bool)supportSeamlesslySwitchDefinition;
- (void)updateVideo:(TVKPlayerVideo *)arg1;
- (void)openPlayerWithVideo:(TVKPlayerVideo *)arg1 bakVideos:(NSArray *)arg2;
- (void)switchDefinitionWithURL:(NSString *)arg1 bakURLs:(NSArray *)arg2;
- (void)openPlayerWithURL:(NSString *)arg1 bakURLs:(NSArray *)arg2 startPos:(long long)arg3 skipEndPos:(long long)arg4;
@end
