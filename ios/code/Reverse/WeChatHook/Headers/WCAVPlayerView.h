//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCAVPlayerBaseView.h"

#import "WCPlayerResourceLoaderDelegate.h"

@class NSString, WCPlayerResourceLoader;

@interface WCAVPlayerView : WCAVPlayerBaseView <WCPlayerResourceLoaderDelegate>
{
    WCPlayerResourceLoader *_playerResourceLoader;
}

@property(retain, nonatomic) WCPlayerResourceLoader *playerResourceLoader; // @synthesize playerResourceLoader=_playerResourceLoader;
- (void).cxx_destruct;
- (void)onChangeVideoSource;
- (void)onVideoDownloadFail:(int)arg1;
- (void)onRecieveAllVideoData;
- (void)onRecievePreLoadData;
- (void)onResponseDataToResourceLoader;
- (void)onRecieveSeekLoadingRequest;
- (void)onSliderScrubbingDidEndAtTime:(double)arg1;
- (void)onStatusChange:(id)arg1;
- (void)checkStreamPlayerState;
- (void)requestNextBufferSec;
- (void)resetPlayerToLocalPlay;
- (void)resetPlayerToSystemPlay;
- (void)startBuffering;
- (void)stopVideoDowload;
- (void)startWithPlayerMode:(unsigned long long)arg1;
- (void)changeToDownloadFirstMode;
- (void)createAsset;
- (void)destoryResourceLoader;
- (id)createPlayerResourceLoader;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

