//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface TVKVRPosition : NSObject
{
    float mCurrentRotation[16];
    float _x;
    float _y;
    float _z;
    float _angelX;
    float _angelY;
    float _angelZ;
    float _pitch;
    float _yaw;
    float _roll;
}

+ (id)getOriginalPos;
+ (id)newInstance;
@property(nonatomic) float roll; // @synthesize roll=_roll;
@property(nonatomic) float yaw; // @synthesize yaw=_yaw;
@property(nonatomic) float pitch; // @synthesize pitch=_pitch;
@property(nonatomic) float angelZ; // @synthesize angelZ=_angelZ;
@property(nonatomic) float angelY; // @synthesize angelY=_angelY;
@property(nonatomic) float angelX; // @synthesize angelX=_angelX;
@property(nonatomic) float z; // @synthesize z=_z;
@property(nonatomic) float y; // @synthesize y=_y;
@property(nonatomic) float x; // @synthesize x=_x;
- (float *)getMatrix;
- (void)update;
- (id)init;

@end
