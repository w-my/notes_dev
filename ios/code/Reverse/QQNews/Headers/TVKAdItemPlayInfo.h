//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSError, NSString;

@interface TVKAdItemPlayInfo : NSObject
{
    double _totalPlayDuration;
    double _duration;
    long long _format;
    NSError *_error;
    NSString *_vid;
    double _startPosition;
    double _endPosition;
}

@property(nonatomic) double endPosition; // @synthesize endPosition=_endPosition;
@property(nonatomic) double startPosition; // @synthesize startPosition=_startPosition;
@property(copy, nonatomic) NSString *vid; // @synthesize vid=_vid;
@property(retain, nonatomic) NSError *error; // @synthesize error=_error;
@property(nonatomic) long long format; // @synthesize format=_format;
@property(nonatomic) double duration; // @synthesize duration=_duration;
@property(nonatomic) double totalPlayDuration; // @synthesize totalPlayDuration=_totalPlayDuration;
- (void).cxx_destruct;

@end

