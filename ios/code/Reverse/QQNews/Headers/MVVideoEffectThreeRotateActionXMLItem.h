//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVVideoEffectActionXMLItem.h"

#import "NSCoding.h"

@class MVLayerRotateParameter;

@interface MVVideoEffectThreeRotateActionXMLItem : MVVideoEffectActionXMLItem <NSCoding>
{
    MVLayerRotateParameter *_layer_up;
    MVLayerRotateParameter *_layer_middle;
    MVLayerRotateParameter *_layer_down;
}

@property(retain, nonatomic) MVLayerRotateParameter *layer_down; // @synthesize layer_down=_layer_down;
@property(retain, nonatomic) MVLayerRotateParameter *layer_middle; // @synthesize layer_middle=_layer_middle;
@property(retain, nonatomic) MVLayerRotateParameter *layer_up; // @synthesize layer_up=_layer_up;
- (void).cxx_destruct;
- (id)initWithDictionary:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;

@end

