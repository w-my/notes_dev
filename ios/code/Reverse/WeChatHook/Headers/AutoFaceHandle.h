//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class FaceDetectorFeature, HFUIImage, NSDictionary, UIImage;

@interface AutoFaceHandle : NSObject
{
    struct AutoFaceProcessor *processor;
    HFUIImage *resultImage;
    _Bool _aboveIPhone4;
    int _filterQuality;
    FaceDetectorFeature *_feature;
    NSDictionary *_filterInfo;
    double _filterAlpha;
}

@property(nonatomic) double filterAlpha; // @synthesize filterAlpha=_filterAlpha;
@property(nonatomic) int filterQuality; // @synthesize filterQuality=_filterQuality;
@property(retain, nonatomic) NSDictionary *filterInfo; // @synthesize filterInfo=_filterInfo;
@property(nonatomic) _Bool aboveIPhone4; // @synthesize aboveIPhone4=_aboveIPhone4;
@property(retain, nonatomic) FaceDetectorFeature *feature; // @synthesize feature=_feature;
- (void).cxx_destruct;
- (void)applyFaceStyle:(id)arg1;
- (void)validateFeature;
- (struct _Rect)MRectFromCGRect:(struct CGRect)arg1;
- (void)loadGlobalResource;
- (struct _Image *)createLipsMask:(struct _Rect *)arg1;
- (struct _Image *)createEyeMask;
- (struct _Image *)createPouchMask;
- (struct _Image *)createFaceMask;
- (id)resultImage;
- (void)processImage;
- (void)setAutoParam:(float)arg1 ofType:(int)arg2;
- (float)autoParamOfType:(int)arg1;
@property(retain, nonatomic) UIImage *image;
- (void)dealloc;
- (id)init;

@end

