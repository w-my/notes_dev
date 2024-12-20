//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableArray;

@interface MCMagicPen : NSObject
{
    CDStruct_1fa2d530 srcImgSize;
    CDStruct_1fa2d530 patternImgSize;
    vector_b01f9d2a lineposList;
    struct {
        int x;
        int y;
    } touchBeginPos;
    float fDistanceBase;
    int startx;
    int starty;
    int endx;
    int endy;
    _Bool isTouchEnded;
    float patternSizeratio;
    float radius_coefficient;
    float srcimg_diag_len;
    NSMutableArray *_drawPoints;
}

@property(retain, nonatomic) NSMutableArray *drawPoints; // @synthesize drawPoints=_drawPoints;
- (id).cxx_construct;
- (void).cxx_destruct;
- (CDStruct_09df043f)intersect:(CDStruct_09df043f *)arg1 with:(CDStruct_09df043f *)arg2;
- (_Bool)FindPoint:(vector_b01f9d2a *)arg1 pos:(CDStruct_1ef3fb1f)arg2 diffmax:(float)arg3;
- (float)refineRadiusCoefficient:(float)arg1 disbase:(float)arg2 pos:(CDStruct_1ef3fb1f)arg3;
- (float)randomInRangeFloatFrom:(float)arg1 to:(float)arg2;
- (int)randomInRangeIntFrom:(int)arg1 to:(int)arg2;
- (float)getDistanceFrom:(CDStruct_1ef3fb1f)arg1 to:(CDStruct_1ef3fb1f)arg2;
- (void)createLightPenAtEx:(CDStruct_1ef3fb1f)arg1;
- (void)drawFireworksUnitAt:(CDStruct_1ef3fb1f)arg1 withDensity:(int)arg2 alpha:(float)arg3 radius:(int)arg4;
- (void)createRayTo:(CDStruct_1ef3fb1f)arg1 withRmax:(int)arg2 lnum:(int)arg3 density:(int)arg4 stepSize:(int)arg5;
- (void)createDoubleRayTo:(CDStruct_1ef3fb1f)arg1 withRmax:(int)arg2 lnum:(int)arg3 density:(int)arg4 stepSize:(int)arg5 drawExternalRay:(_Bool)arg6;
- (void)createFireworksAt:(CDStruct_1ef3fb1f)arg1;
- (void)attachPatternAt:(CDStruct_1ef3fb1f)arg1 withType:(int)arg2 alpha:(float)arg3;
- (void)drawLineBresenhamForLightpenFrom:(CDStruct_1ef3fb1f)arg1 to:(CDStruct_1ef3fb1f)arg2;
- (void)drawLineBresenhamFrom:(CDStruct_1ef3fb1f)arg1 to:(CDStruct_1ef3fb1f)arg2 withType:(int)arg3 stepSize:(int)arg4;
- (void)paintLightpenFrom:(struct CGPoint)arg1 to:(struct CGPoint)arg2 ended:(_Bool)arg3 inCanvas:(struct CGSize)arg4 withPattern:(struct CGSize)arg5;
- (void)paintFireworksFrom:(struct CGPoint)arg1 to:(struct CGPoint)arg2 ended:(_Bool)arg3 inCanvas:(struct CGSize)arg4;
- (void)updatePatternImageSize:(struct CGSize)arg1;
- (void)updateSrcImageSize:(struct CGSize)arg1;
- (void)updateBrushRatio:(double)arg1;
- (void)touchEnded;
- (void)touchMoveFrom:(struct CGPoint)arg1 to:(struct CGPoint)arg2;
- (void)touchBegan:(struct CGPoint)arg1;
- (id)init;

@end

