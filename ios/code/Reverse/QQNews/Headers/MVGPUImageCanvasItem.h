//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class GPUImageFramebuffer;

@interface MVGPUImageCanvasItem : NSObject
{
    GPUImageFramebuffer *_frameBuffer;
    struct CGRect _rect;
}

@property(retain, nonatomic) GPUImageFramebuffer *frameBuffer; // @synthesize frameBuffer=_frameBuffer;
@property(nonatomic) struct CGRect rect; // @synthesize rect=_rect;
- (void).cxx_destruct;
- (id)makeFrameBuffer;

@end

