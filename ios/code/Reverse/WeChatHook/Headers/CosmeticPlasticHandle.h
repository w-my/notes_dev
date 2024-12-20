//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class FaceDetectorFeature, GPUImagePicture, GPUImageView, MCBeautyEyeLightenFilter, MCBilateralSmootherFilter, MCFaceAdjustTotalFilter, MCTeethWhitenFilter, MyCamGPUFilter, NSMutableDictionary, UIImage;

@interface CosmeticPlasticHandle : NSObject
{
    NSMutableDictionary *_plasticDict;
    GPUImageView *_gpuImageView;
    UIImage *_teethImage;
    UIImage *_internImage;
    FaceDetectorFeature *_feature;
    GPUImagePicture *_picture;
    GPUImagePicture *_teethPicture;
    MCTeethWhitenFilter *_teethFilter;
    MyCamGPUFilter *_teeth2Filter;
    MCFaceAdjustTotalFilter *_totalFilter;
    MCBilateralSmootherFilter *_eyePunchFilter;
    MCBeautyEyeLightenFilter *_eyeLightenFilter;
}

@property(retain, nonatomic) MCBeautyEyeLightenFilter *eyeLightenFilter; // @synthesize eyeLightenFilter=_eyeLightenFilter;
@property(retain, nonatomic) MCBilateralSmootherFilter *eyePunchFilter; // @synthesize eyePunchFilter=_eyePunchFilter;
@property(retain, nonatomic) MCFaceAdjustTotalFilter *totalFilter; // @synthesize totalFilter=_totalFilter;
@property(retain, nonatomic) MyCamGPUFilter *teeth2Filter; // @synthesize teeth2Filter=_teeth2Filter;
@property(retain, nonatomic) MCTeethWhitenFilter *teethFilter; // @synthesize teethFilter=_teethFilter;
@property(retain, nonatomic) GPUImagePicture *teethPicture; // @synthesize teethPicture=_teethPicture;
@property(retain, nonatomic) GPUImagePicture *picture; // @synthesize picture=_picture;
@property(retain, nonatomic) FaceDetectorFeature *feature; // @synthesize feature=_feature;
@property(retain, nonatomic) UIImage *internImage; // @synthesize internImage=_internImage;
@property(retain, nonatomic) UIImage *teethImage; // @synthesize teethImage=_teethImage;
@property(retain, nonatomic) GPUImageView *gpuImageView; // @synthesize gpuImageView=_gpuImageView;
@property(retain, nonatomic) NSMutableDictionary *plasticDict; // @synthesize plasticDict=_plasticDict;
- (void).cxx_destruct;
- (id)resultImage;
- (void)applyPlastic;
- (void)adjustPlasticDict:(id)arg1;
- (id)initWithImage:(id)arg1 feature:(id)arg2 teethImage:(id)arg3;

@end

