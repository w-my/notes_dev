//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CAShapeLayer.h"

@interface QNInnerShadowLayer : CAShapeLayer
{
    float _innerShadowOpacity;
    struct CGColor *_innerShadowColor;
    double _innerShadowRadius;
    struct CGSize _innerShadowOffset;
}

@property(nonatomic) float innerShadowOpacity; // @synthesize innerShadowOpacity=_innerShadowOpacity;
@property(nonatomic) double innerShadowRadius; // @synthesize innerShadowRadius=_innerShadowRadius;
@property(nonatomic) struct CGSize innerShadowOffset; // @synthesize innerShadowOffset=_innerShadowOffset;
@property(nonatomic) struct CGColor *innerShadowColor; // @synthesize innerShadowColor=_innerShadowColor;
- (void)drawInContext:(struct CGContext *)arg1;
- (id)init;

@end

