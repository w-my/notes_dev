//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface TTMicBaseCameraBlendMaterial : NSObject
{
    int _blendMode;
    float _topX;
    float _topY;
    float _bottomX;
    float _bottomY;
    float _picRatio;
    float _randomHeight;
    int _rotateType;
    int _fillMode;
    NSString *_watermarkString;
}

@property(nonatomic) NSString *watermarkString; // @synthesize watermarkString=_watermarkString;
@property(nonatomic) int fillMode; // @synthesize fillMode=_fillMode;
@property(nonatomic) int rotateType; // @synthesize rotateType=_rotateType;
@property(nonatomic) float randomHeight; // @synthesize randomHeight=_randomHeight;
@property(nonatomic) float picRatio; // @synthesize picRatio=_picRatio;
@property(nonatomic) float bottomY; // @synthesize bottomY=_bottomY;
@property(nonatomic) float bottomX; // @synthesize bottomX=_bottomX;
@property(nonatomic) float topY; // @synthesize topY=_topY;
@property(nonatomic) float topX; // @synthesize topX=_topX;
@property(nonatomic) int blendMode; // @synthesize blendMode=_blendMode;
- (id)init;

@end

