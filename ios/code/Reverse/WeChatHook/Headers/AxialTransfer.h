//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface AxialTransfer : NSObject
{
    struct _IplImage *srcImage;
    struct _IplImage *blurImage;
    int _blurType;
    float _strength;
}

@property(nonatomic) float strength; // @synthesize strength=_strength;
@property(nonatomic) int blurType; // @synthesize blurType=_blurType;
- (id)blurEllipseWithA:(float)arg1 andX:(float)arg2 andY:(float)arg3 andTheta:(float)arg4 andInnerRadius:(int)arg5 andOuterRadius:(int)arg6;
- (id)blurParallelWithX:(float)arg1 andY:(float)arg2 andTheta:(float)arg3 andInnerRadius:(int)arg4 andOuterRadius:(int)arg5;
- (id)blurRoundWithCenterX:(float)arg1 andCenterY:(float)arg2 andInnerRadius:(int)arg3 andOuterRadius:(int)arg4;
- (void)setImage:(id)arg1;
- (void)updateBlurImage;
- (void)dealloc;
- (id)initWithImage:(id)arg1;

@end

