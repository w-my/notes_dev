//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GPUImageView.h"

@class GPUImageFramebuffer, MVGPUImageSnapshotFilter, UIImage;

@interface MVGPUImageView : GPUImageView
{
    _Bool _snapshotEnabled;
    MVGPUImageSnapshotFilter *_filter;
    GPUImageFramebuffer *_lastFrameBuffer;
}

@property(retain, nonatomic) GPUImageFramebuffer *lastFrameBuffer; // @synthesize lastFrameBuffer=_lastFrameBuffer;
@property(retain, nonatomic) MVGPUImageSnapshotFilter *filter; // @synthesize filter=_filter;
@property(nonatomic) _Bool snapshotEnabled; // @synthesize snapshotEnabled=_snapshotEnabled;
- (void).cxx_destruct;
@property(readonly, nonatomic) UIImage *currentImage;
- (void)setInputFramebuffer:(id)arg1 atIndex:(long long)arg2;
- (void)dealloc;

@end

