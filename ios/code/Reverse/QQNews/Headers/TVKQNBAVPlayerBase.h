//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, TVKQNBAVVideo;

@interface TVKQNBAVPlayerBase : NSObject
{
    _Bool _isPlayInPIP;
    _Bool _enableLoopback;
    _Bool _enableResourceLoader;
    _Bool _enableVRMode;
    _Bool _isAudioMode;
    _Bool _isDolbyVision;
    float _rate;
    float _volume;
    unsigned long long _coreType;
    double _duration;
    double _currentTime;
    double _currentLoadedTime;
    id _avPlayer;
    TVKQNBAVVideo *_video;
    long long _numberOfBytesTransferred;
    double _loadingTime;
    id <TVKQNBAVPlayerDelegate> _playerDelegate;
}

@property(nonatomic) __weak id <TVKQNBAVPlayerDelegate> playerDelegate; // @synthesize playerDelegate=_playerDelegate;
@property(nonatomic) _Bool isDolbyVision; // @synthesize isDolbyVision=_isDolbyVision;
@property(nonatomic) _Bool isAudioMode; // @synthesize isAudioMode=_isAudioMode;
@property(nonatomic) _Bool enableVRMode; // @synthesize enableVRMode=_enableVRMode;
@property(nonatomic) _Bool enableResourceLoader; // @synthesize enableResourceLoader=_enableResourceLoader;
@property(nonatomic) _Bool enableLoopback; // @synthesize enableLoopback=_enableLoopback;
@property(nonatomic) float volume; // @synthesize volume=_volume;
@property(nonatomic) float rate; // @synthesize rate=_rate;
@property(nonatomic) _Bool isPlayInPIP; // @synthesize isPlayInPIP=_isPlayInPIP;
@property(readonly, nonatomic) double loadingTime; // @synthesize loadingTime=_loadingTime;
@property(readonly, nonatomic) long long numberOfBytesTransferred; // @synthesize numberOfBytesTransferred=_numberOfBytesTransferred;
@property(readonly, nonatomic) TVKQNBAVVideo *video; // @synthesize video=_video;
@property(readonly, nonatomic) id avPlayer; // @synthesize avPlayer=_avPlayer;
@property(nonatomic) double currentLoadedTime; // @synthesize currentLoadedTime=_currentLoadedTime;
@property(nonatomic) double currentTime; // @synthesize currentTime=_currentTime;
@property(nonatomic) double duration; // @synthesize duration=_duration;
@property(readonly, nonatomic) unsigned long long coreType; // @synthesize coreType=_coreType;
- (void).cxx_destruct;
- (void)resumeOutputFrame;
- (void)pauseOutputFrame;
- (void)stopOutputFrame;
- (void)startOutputFrame:(double)arg1;
- (id)snapshot;
- (void)updateVideo:(id)arg1;
@property(copy, nonatomic) NSString *externalPlaybackVideoGravity; // @dynamic externalPlaybackVideoGravity;
@property(nonatomic) _Bool usesExternalPlaybackWhileExternalScreenIsActive; // @dynamic usesExternalPlaybackWhileExternalScreenIsActive;
@property(nonatomic) _Bool allowsExternalPlayback; // @dynamic allowsExternalPlayback;
@property(readonly, nonatomic) _Bool airPlayModel; // @dynamic airPlayModel;
@property(readonly, nonatomic) _Bool playing; // @dynamic playing;
@property(readonly, nonatomic) _Bool buffering; // @dynamic buffering;
@property(readonly, nonatomic) _Bool loaded; // @dynamic loaded;
@property(readonly, nonatomic) unsigned long long state;
- (void)stop;
- (void)seekTime:(double)arg1;
- (void)pause;
- (void)play;
- (_Bool)start:(int)arg1;
- (void)loadVideo:(id)arg1;
- (id)errorLog;
- (id)initWithCoreType:(unsigned long long)arg1;

// Remaining properties
@property(readonly, nonatomic) double reportCurrentTime; // @dynamic reportCurrentTime;

@end

