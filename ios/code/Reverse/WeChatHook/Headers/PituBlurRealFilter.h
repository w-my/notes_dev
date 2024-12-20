//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MultiFilterConnect.h"

@class MyCamGPUFilter;

@interface PituBlurRealFilter : MultiFilterConnect
{
    MyCamGPUFilter *horizontal;
    MyCamGPUFilter *vertical;
    MyCamGPUFilter *blurArea;
    _Bool _circle;
    double _ratio;
    double _angle;
    double _radius;
    struct CGPoint _center;
}

@property(nonatomic) double radius; // @synthesize radius=_radius;
@property(nonatomic) double angle; // @synthesize angle=_angle;
@property(nonatomic) struct CGPoint center; // @synthesize center=_center;
@property(nonatomic) double ratio; // @synthesize ratio=_ratio;
@property(nonatomic) _Bool circle; // @synthesize circle=_circle;
- (void).cxx_destruct;
- (void)setProperty:(id)arg1 value:(id)arg2;
- (void)setInputSize:(struct CGSize)arg1 atIndex:(long long)arg2;
- (void)setBlurRaidus:(double)arg1;
- (void)NewFilter;

@end

