//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "AVAudioPlayerDelegate.h"
#import "MCFilterDelegate.h"
#import "MVCaptureManagerDelegate.h"
#import "MVFilterManagerDelegate.h"

@class CMMotionManager, GPUImageFilter, GPUImageView, MCFilterProvider, MCTmplItem, MVAudioPlayer, MVCaptureManager, MVFilterItem, MVFilterManager, MVModel, MVMusicItem, NSArray, NSMutableArray, NSObject<OS_dispatch_queue>, NSString, NSTimer, UIImage;

@interface MVRecordEngine : NSObject <MVCaptureManagerDelegate, MVFilterManagerDelegate, MCFilterDelegate, AVAudioPlayerDelegate>
{
    _Bool _isRecording;
    _Bool _motionMuted;
    _Bool _needOriginSound;
    _Bool _hasFocusedAtFifthFrame;
    _Bool _hasFocusedAtFace;
    _Bool _enableDenoise;
    _Bool _enableLowLight;
    _Bool _needPlayBGM;
    id <MVRecordEngineDelegate> _delegate;
    MVModel *_recordModel;
    GPUImageFilter *_customFilter;
    GPUImageView *_previewView;
    MCTmplItem *_motionItem;
    MVFilterItem *_filterItem;
    MVMusicItem *_musicItem;
    double _recordSpeed;
    double _maxRecordDuration;
    double _minSectionDuration;
    double _curSectionDuration;
    MCFilterProvider *_filterProvider;
    MVCaptureManager *_inputMgr;
    MVAudioPlayer *_audioPlayer;
    MVFilterManager *_filterManager;
    double _recordedTime;
    NSString *_motionTmpl;
    long long _engineState;
    CMMotionManager *_motionMgr;
    NSMutableArray *_recordItems;
    NSTimer *_timer;
    long long _orientation;
    double _filterIntensity;
    long long _stuckCount;
    double _maxStuckDuration;
    double _lastFrameTime;
    NSObject<OS_dispatch_queue> *_workQueue;
    unsigned long long _itemType;
    struct CGSize _renderSize;
    struct CGPoint _touchPos;
}

+ (void)deviceHasMediaPrivilege:(id)arg1 completion:(CDUnknownBlockType)arg2;
+ (void)requestMicrophonePermission:(CDUnknownBlockType)arg1;
+ (void)requestCameraPermission:(CDUnknownBlockType)arg1;
@property(nonatomic) unsigned long long itemType; // @synthesize itemType=_itemType;
@property(nonatomic) _Bool needPlayBGM; // @synthesize needPlayBGM=_needPlayBGM;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *workQueue; // @synthesize workQueue=_workQueue;
@property(nonatomic) double lastFrameTime; // @synthesize lastFrameTime=_lastFrameTime;
@property(nonatomic) double maxStuckDuration; // @synthesize maxStuckDuration=_maxStuckDuration;
@property(nonatomic) long long stuckCount; // @synthesize stuckCount=_stuckCount;
@property(nonatomic) double filterIntensity; // @synthesize filterIntensity=_filterIntensity;
@property(nonatomic) _Bool enableLowLight; // @synthesize enableLowLight=_enableLowLight;
@property(nonatomic) _Bool enableDenoise; // @synthesize enableDenoise=_enableDenoise;
@property(nonatomic) long long orientation; // @synthesize orientation=_orientation;
@property(nonatomic) _Bool hasFocusedAtFace; // @synthesize hasFocusedAtFace=_hasFocusedAtFace;
@property(nonatomic) _Bool hasFocusedAtFifthFrame; // @synthesize hasFocusedAtFifthFrame=_hasFocusedAtFifthFrame;
@property(nonatomic) struct CGPoint touchPos; // @synthesize touchPos=_touchPos;
@property(retain, nonatomic) NSTimer *timer; // @synthesize timer=_timer;
@property(nonatomic) _Bool needOriginSound; // @synthesize needOriginSound=_needOriginSound;
@property(retain, nonatomic) NSMutableArray *recordItems; // @synthesize recordItems=_recordItems;
@property(retain, nonatomic) CMMotionManager *motionMgr; // @synthesize motionMgr=_motionMgr;
@property(nonatomic) long long engineState; // @synthesize engineState=_engineState;
@property(retain, nonatomic) NSString *motionTmpl; // @synthesize motionTmpl=_motionTmpl;
@property(nonatomic) double recordedTime; // @synthesize recordedTime=_recordedTime;
@property(retain, nonatomic) MVFilterManager *filterManager; // @synthesize filterManager=_filterManager;
@property(retain, nonatomic) MVAudioPlayer *audioPlayer; // @synthesize audioPlayer=_audioPlayer;
@property(retain, nonatomic) MVCaptureManager *inputMgr; // @synthesize inputMgr=_inputMgr;
@property(nonatomic) _Bool motionMuted; // @synthesize motionMuted=_motionMuted;
@property(readonly, nonatomic) struct CGSize renderSize; // @synthesize renderSize=_renderSize;
@property(readonly, nonatomic) MCFilterProvider *filterProvider; // @synthesize filterProvider=_filterProvider;
@property(nonatomic) double curSectionDuration; // @synthesize curSectionDuration=_curSectionDuration;
@property(nonatomic) _Bool isRecording; // @synthesize isRecording=_isRecording;
@property(readonly, nonatomic) double minSectionDuration; // @synthesize minSectionDuration=_minSectionDuration;
@property(readonly, nonatomic) double maxRecordDuration; // @synthesize maxRecordDuration=_maxRecordDuration;
@property(nonatomic) double recordSpeed; // @synthesize recordSpeed=_recordSpeed;
@property(retain, nonatomic) MVMusicItem *musicItem; // @synthesize musicItem=_musicItem;
@property(retain, nonatomic) MVFilterItem *filterItem; // @synthesize filterItem=_filterItem;
@property(retain, nonatomic) MCTmplItem *motionItem; // @synthesize motionItem=_motionItem;
@property(retain, nonatomic) GPUImageView *previewView; // @synthesize previewView=_previewView;
@property(retain, nonatomic) GPUImageFilter *customFilter; // @synthesize customFilter=_customFilter;
@property(retain, nonatomic) MVModel *recordModel; // @synthesize recordModel=_recordModel;
@property(nonatomic) __weak id <MVRecordEngineDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)reportRecordWithVideoItem:(id)arg1;
- (double)audioPlayerCurrentTime;
- (void)switchTorchState;
- (void)useRecordModel:(id)arg1 complete:(CDUnknownBlockType)arg2;
- (void)useFreshRecordModel:(id)arg1;
- (void)filterManager:(id)arg1 didFinishCrop:(id)arg2;
- (void)MCFilterNeedUpdateGuideStauteWithTmplItem:(id)arg1 faceCount:(long long)arg2;
- (void)MCFilterNeedHideTips:(id)arg1;
- (void)MCFilterNeedShowTips:(id)arg1 text:(id)arg2 withDuration:(double)arg3;
- (_Bool)filterManager:(id)arg1 motionTmplSelectFilter:(id)arg2;
- (void)filterManager:(id)arg1 updateRecordingTimeSeconds:(double)arg2;
- (void)setupFilterManager;
- (void)autoFocusIfNeed;
- (void)setNeedAutoFocus;
@property(readonly, nonatomic) UIImage *currentResultImage;
- (struct CGSize)preferedVideoSize;
- (void)capturePhotoWithComplete:(CDUnknownBlockType)arg1;
- (void)captureManger:(id)arg1 didChangeToMode:(unsigned long long)arg2;
- (void)captureManger:(id)arg1 didOutputAudioSampleBuffer:(struct opaqueCMSampleBuffer *)arg2;
- (void)updateARRenderSize:(struct CGSize)arg1;
- (void)captureManger:(id)arg1 didOutputVideoSampleBuffer:(struct opaqueCMSampleBuffer *)arg2;
@property(readonly, nonatomic) NSArray *videoItems;
- (void)setupGestureForItemType:(unsigned long long)arg1;
@property(nonatomic) float forceRatio;
@property(readonly, nonatomic) double recordedDuration;
- (void)updateRecordTime;
- (void)updateDeviceOrientationWithGravity:(CDStruct_39925896)arg1;
- (void)updateDeviceOrientationForRecordIfNeed;
- (void)clearRecordModel;
- (void)saveRecordModel;
- (void)removeLastVideoItem;
- (void)addRecordItem:(id)arg1;
- (id)videoPathOfSection:(long long)arg1;
- (void)notifyRecordFailedAtSection:(long long)arg1 error:(id)arg2;
- (void)notifyRecordFinishAtSecion:(long long)arg1;
@property(readonly, nonatomic) _Bool isReady;
- (void)finishCurrentSection:(CDUnknownBlockType)arg1;
- (void)cancelRecord;
- (void)finishRecord;
- (void)startRecord;
- (void)stopPreview:(_Bool)arg1;
- (void)startPreview;
- (void)resetRecordState;
- (void)pauseBGM;
- (void)syncBgmTime;
- (void)playBGM;
- (void)setupAudioPlayer;
- (void)onAudioStateChanged;
- (void)switchCameraPositionWithComplete:(CDUnknownBlockType)arg1;
- (void)dealloc;
- (void)setupRecordEngine;
- (id)init;
- (void)setBeautyStrength:(double)arg1 forType:(unsigned long long)arg2;
- (double)getBeautyStrengthWithType:(unsigned long long)arg1;
- (void)setDisableBeauty:(_Bool)arg1;
@property(nonatomic) long long torchMode;
@property(readonly, nonatomic) _Bool hasTorch;
@property(readonly, nonatomic) long long cameraPosition;
@property(readonly, nonatomic) _Bool supportZoom;
@property(readonly, nonatomic) double maxZoomFactor;
@property(nonatomic) double zoomFactor;
@property(nonatomic) struct CGPoint exposurePoint;
@property(nonatomic) struct CGPoint focusPoint;
- (_Bool)screenPan:(id)arg1;
- (_Bool)handleDoublePanGesture:(id)arg1;
- (_Bool)handleSinglePanGesture:(id)arg1;
- (_Bool)handlePinchGesture:(id)arg1;
- (_Bool)handleDoubleTapGesture:(id)arg1;
- (_Bool)handleSingleTapGesture:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
