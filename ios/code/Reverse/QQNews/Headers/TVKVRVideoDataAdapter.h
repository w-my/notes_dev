//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface TVKVRVideoDataAdapter : NSObject
{
    struct __CVBuffer *_videoPixelBuffer;
    _Bool _isPixelBufferFilled;
}

- (_Bool)hasNewPixelBuffer;
- (struct __CVBuffer *)retrievePixelBufferToDraw;
- (void)updatePicture:(id)arg1;
- (void)dealloc;
- (id)initWithPixfmt:(long long)arg1;

@end

