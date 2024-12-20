//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface TXCCombineFrame : NSObject
{
    struct opaqueCMSampleBuffer *_sampleBuffer;
    long long _rotation;
    double _xRotate;
    double _yRotate;
    double _zRotate;
    double _xTranslate;
    double _yTranslate;
    double _alpha;
    double _scale;
    struct CGRect _crop;
    struct CGRect _position;
}

@property(nonatomic) double scale; // @synthesize scale=_scale;
@property(nonatomic) double alpha; // @synthesize alpha=_alpha;
@property(nonatomic) double yTranslate; // @synthesize yTranslate=_yTranslate;
@property(nonatomic) double xTranslate; // @synthesize xTranslate=_xTranslate;
@property(nonatomic) double zRotate; // @synthesize zRotate=_zRotate;
@property(nonatomic) double yRotate; // @synthesize yRotate=_yRotate;
@property(nonatomic) double xRotate; // @synthesize xRotate=_xRotate;
@property(nonatomic) struct CGRect position; // @synthesize position=_position;
@property(nonatomic) struct CGRect crop; // @synthesize crop=_crop;
@property(nonatomic) long long rotation; // @synthesize rotation=_rotation;
@property(nonatomic) struct opaqueCMSampleBuffer *sampleBuffer; // @synthesize sampleBuffer=_sampleBuffer;
- (id)init;

@end

