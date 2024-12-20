//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WMElement.h"

@class NSMutableDictionary;

@interface WMImageElement : WMElement
{
    _Bool _premultipliedAlpha;
    NSMutableDictionary *_frameTextures;
    NSMutableDictionary *_frameBuffers;
}

@property(retain, nonatomic) NSMutableDictionary *frameBuffers; // @synthesize frameBuffers=_frameBuffers;
@property(retain, nonatomic) NSMutableDictionary *frameTextures; // @synthesize frameTextures=_frameTextures;
@property(nonatomic) _Bool premultipliedAlpha; // @synthesize premultipliedAlpha=_premultipliedAlpha;
- (void).cxx_destruct;
- (void)updateBuffer:(double)arg1;
- (void)dealloc;
- (id)initWithDictionary:(id)arg1 sid:(id)arg2 folder:(id)arg3;

@end

