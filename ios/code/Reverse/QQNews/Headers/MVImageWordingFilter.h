//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "FSImageWrapFilter.h"

@class GPUImageNormalBlendFilter, NSString;

@interface MVImageWordingFilter : FSImageWrapFilter
{
    struct CGSize contextSize;
    char *contextData;
    NSString *_blendType;
    id <MVImageWordingFilterDelegate> _delegate;
    GPUImageNormalBlendFilter *_normalBlendFilter;
}

@property(retain, nonatomic) GPUImageNormalBlendFilter *normalBlendFilter; // @synthesize normalBlendFilter=_normalBlendFilter;
@property(nonatomic) __weak id <MVImageWordingFilterDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (id)imageFromCurrentFramebuffer;
- (void)useNextFrameForImageCapture;
- (void)setFrameProcessingCompletionBlock:(CDUnknownBlockType)arg1;
- (void)removeAllTargets;
- (void)removeTarget:(id)arg1;
- (void)addTarget:(id)arg1;
- (void)newFrameReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (void)cleanFilter;
- (void)dealloc;
- (id)blendType;
- (id)initWithBitmapData:(char *)arg1 contextSize:(struct CGSize)arg2 blendType:(id)arg3;
- (id)initWithBitmapData:(char *)arg1 contextSize:(struct CGSize)arg2;

@end
