//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@protocol TVKSelfPlayerWrapperCallback <NSObject>
- (_Bool)isSupportVideoDecode:(int)arg1 codecID:(int)arg2 width:(int)arg3 height:(int)arg4;
- (void)onSubtitleData:(char *)arg1 size:(unsigned int)arg2 type:(unsigned int)arg3 attr:(char *)arg4 attrLen:(unsigned int)arg5 format:(int)arg6;
- (void)onAudioData:(char *)arg1 size:(unsigned int)arg2 sampleRate:(int)arg3 channelLayout:(long long)arg4 format:(int)arg5;
- (void)onVideoPixelBuffer:(struct __CVBuffer *)arg1 width:(unsigned int)arg2 height:(unsigned int)arg3 rotation:(int)arg4 pixfmt:(int)arg5;
- (void)onVideoData:(char **)arg1 linesize:(unsigned int *)arg2 width:(unsigned int)arg3 height:(unsigned int)arg4 rotation:(int)arg5 pixfmt:(int)arg6;
- (void)onVideoData:(char *)arg1 width:(unsigned int)arg2 height:(unsigned int)arg3 rotation:(int)arg4 pixfmt:(int)arg5;
- (void)notifyPlayerMsg:(int)arg1 position:(long long)arg2 param:(long long)arg3 context:(void *)arg4 size:(int)arg5;
@end
