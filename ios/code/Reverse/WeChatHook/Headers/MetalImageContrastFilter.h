//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MetalImageFilter.h"

@interface MetalImageContrastFilter : MetalImageFilter
{
    float _contrast;
    id <MTLBuffer> _buffer;
}

@property(retain, nonatomic) id <MTLBuffer> buffer; // @synthesize buffer=_buffer;
@property(nonatomic) float contrast; // @synthesize contrast=_contrast;
- (void).cxx_destruct;
- (void)assembleRenderEncoder:(id)arg1;
- (void)dealloc;
- (id)init;

@end
