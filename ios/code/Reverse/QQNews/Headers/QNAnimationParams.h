//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSString;

@interface QNAnimationParams : NSObject
{
    _Bool _repeat;
    long long _animationPathType;
    NSArray *_positionPoints;
    NSArray *_dimensionsPoints;
    NSArray *_movementPositions;
    NSArray *_opacityValues;
    NSArray *_angleValues;
    NSArray *_bounceDistances;
    double _duration;
    NSString *_animationKeyPath;
}

@property(copy, nonatomic) NSString *animationKeyPath; // @synthesize animationKeyPath=_animationKeyPath;
@property(nonatomic) _Bool repeat; // @synthesize repeat=_repeat;
@property(nonatomic) double duration; // @synthesize duration=_duration;
@property(copy, nonatomic) NSArray *bounceDistances; // @synthesize bounceDistances=_bounceDistances;
@property(copy, nonatomic) NSArray *angleValues; // @synthesize angleValues=_angleValues;
@property(copy, nonatomic) NSArray *opacityValues; // @synthesize opacityValues=_opacityValues;
@property(copy, nonatomic) NSArray *movementPositions; // @synthesize movementPositions=_movementPositions;
@property(copy, nonatomic) NSArray *dimensionsPoints; // @synthesize dimensionsPoints=_dimensionsPoints;
@property(copy, nonatomic) NSArray *positionPoints; // @synthesize positionPoints=_positionPoints;
@property(nonatomic) long long animationPathType; // @synthesize animationPathType=_animationPathType;
- (void).cxx_destruct;

@end

