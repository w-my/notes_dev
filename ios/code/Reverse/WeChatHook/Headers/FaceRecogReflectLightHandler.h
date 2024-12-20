//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "FaceRecogBaseHandler.h"

#import "FaceRecogCheckBrightnessLogicDelegate.h"
#import "FaceRecogGuideViewDelegate.h"
#import "FaceRecogReflectLightViewDelegate.h"

@class CameraReflectDevice, FaceRecogCheckBrightnessLogic, FaceRecogReflectGuideView, FaceRecogReflectLightView, FaceReflectLightHandle, MMTimer, NSString;

@interface FaceRecogReflectLightHandler : FaceRecogBaseHandler <FaceRecogGuideViewDelegate, FaceRecogReflectLightViewDelegate, FaceRecogCheckBrightnessLogicDelegate>
{
    MMTimer *_reflectTimer;
    long long _triggerTimes;
    double _oldScreenBrightness;
    FaceRecogReflectGuideView *_guideVc;
    _Bool _bChangeMode;
    FaceRecogCheckBrightnessLogic *_brightnessCheckLogic;
    FaceRecogReflectLightView *_verifyView;
    FaceReflectLightHandle *_detector;
    CameraReflectDevice *_lightDetector;
}

@property(retain, nonatomic) CameraReflectDevice *lightDetector; // @synthesize lightDetector=_lightDetector;
@property(retain, nonatomic) FaceReflectLightHandle *detector; // @synthesize detector=_detector;
@property(retain, nonatomic) FaceRecogReflectLightView *verifyView; // @synthesize verifyView=_verifyView;
@property(retain, nonatomic) FaceRecogCheckBrightnessLogic *brightnessCheckLogic; // @synthesize brightnessCheckLogic=_brightnessCheckLogic;
- (void).cxx_destruct;
- (void)onFaceRecogGuideFinished;
- (void)onDidCheckBrightnessDoneWithIsOK:(_Bool)arg1 brightnessValue:(float)arg2;
- (void)countTimerTriggered:(id)arg1;
- (void)countTimerTriggered_DelayCalc:(id)arg1;
- (void)DrawScreen;
- (void)finishStateAGLivenessDetect;
- (void)requestStop;
- (int)requestChangeMode;
- (void)setARGB:(unsigned int)arg1 screenLight:(double)arg2;
- (void)stopCountTimer;
- (void)faceRecogDidStartChangeMode;
- (void)procedureDidGotFrameResult:(unsigned long long)arg1 failedType:(long long)arg2;
- (void)doStartReflectLight;
- (void)didDetectFace;
- (void)doStartDetectFace;
- (void)didAccessConfig;
- (void)showView;
- (void)didAccessVideo;
- (void)initView;
- (void)initProcessor;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

