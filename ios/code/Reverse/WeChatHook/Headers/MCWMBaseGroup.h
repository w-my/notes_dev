//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface MCWMBaseGroup : NSObject
{
    double _particleWordUpdateInterval;
    long long _particleBufferUsedCount;
}

@property(nonatomic) long long particleBufferUsedCount; // @synthesize particleBufferUsedCount=_particleBufferUsedCount;
@property(nonatomic) double particleWordUpdateInterval; // @synthesize particleWordUpdateInterval=_particleWordUpdateInterval;
- (id)getCanvasFrameBuffer:(double)arg1;
- (id)initWithArray:(id)arg1 size:(struct CGSize)arg2 sid:(id)arg3;

@end

