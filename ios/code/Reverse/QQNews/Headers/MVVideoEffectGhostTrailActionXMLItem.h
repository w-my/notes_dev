//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVVideoEffectActionXMLItem.h"

#import "NSCoding.h"

@class MVGhostTrailLayerParameter;

@interface MVVideoEffectGhostTrailActionXMLItem : MVVideoEffectActionXMLItem <NSCoding>
{
    int _frameCount;
    MVGhostTrailLayerParameter *_layer_parameter_0;
    MVGhostTrailLayerParameter *_layer_parameter_1;
    MVGhostTrailLayerParameter *_layer_parameter_2;
    MVGhostTrailLayerParameter *_layer_parameter_3;
}

@property(nonatomic) int frameCount; // @synthesize frameCount=_frameCount;
@property(retain, nonatomic) MVGhostTrailLayerParameter *layer_parameter_3; // @synthesize layer_parameter_3=_layer_parameter_3;
@property(retain, nonatomic) MVGhostTrailLayerParameter *layer_parameter_2; // @synthesize layer_parameter_2=_layer_parameter_2;
@property(retain, nonatomic) MVGhostTrailLayerParameter *layer_parameter_1; // @synthesize layer_parameter_1=_layer_parameter_1;
@property(retain, nonatomic) MVGhostTrailLayerParameter *layer_parameter_0; // @synthesize layer_parameter_0=_layer_parameter_0;
- (void).cxx_destruct;
- (id)initWithDictionary:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;

@end

