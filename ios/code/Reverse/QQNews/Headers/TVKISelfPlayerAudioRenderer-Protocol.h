//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@protocol TVKISelfPlayerAudioRenderer <NSObject>
@property(nonatomic) float volume;
@property float rate;
- (void)stop;
- (void)pause;
- (void)start;
- (int)renderAudioWithData:(char *)arg1 size:(unsigned int)arg2 sampleRate:(unsigned int)arg3 channelLayout:(long long)arg4 format:(int)arg5;
@end

