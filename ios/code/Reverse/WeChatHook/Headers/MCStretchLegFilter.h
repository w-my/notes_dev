//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MCBaseFilter.h"

@class StretchLegParameters;

@interface MCStretchLegFilter : MCBaseFilter
{
    int y0Uniform;
    int stretchRatioUniform;
    int showMarkUniform;
    _Bool _enable;
    _Bool _showMark;
    float _strength;
    float _y0;
    StretchLegParameters *_params;
}

@property(nonatomic) float y0; // @synthesize y0=_y0;
@property(retain, nonatomic) StretchLegParameters *params; // @synthesize params=_params;
@property(nonatomic) float strength; // @synthesize strength=_strength;
@property(nonatomic) _Bool showMark; // @synthesize showMark=_showMark;
@property(nonatomic) _Bool enable; // @synthesize enable=_enable;
- (void).cxx_destruct;
- (void)renderToTextureWithVertices:(const float *)arg1 textureCoordinates:(const float *)arg2;
- (id)init;

@end

