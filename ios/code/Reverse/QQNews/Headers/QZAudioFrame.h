//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSData;

@interface QZAudioFrame : NSObject
{
    unsigned int _timestamp;
    NSData *_samples;
}

@property(nonatomic) unsigned int timestamp; // @synthesize timestamp=_timestamp;
@property(retain, nonatomic) NSData *samples; // @synthesize samples=_samples;
- (void).cxx_destruct;

@end

