//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIViewController.h"

#import "AVCaptureAudioDataOutputSampleBufferDelegate.h"
#import "AVCaptureVideoDataOutputSampleBufferDelegate.h"
#import "EditImageAnimatedDelegate.h"
#import "EmoticonCameraResultViewDelegate.h"
#import "EmoticonLensDynamicToolViewDelegate.h"
#import "IStreamVoiceInputExt.h"
#import "ISysCallCheckExt.h"
#import "MCDataOutputDelegate.h"
#import "MCFilterDelegate.h"
#import "MCFilterManagerDelegate.h"
#import "MMSightRecordHelperViewDelegate.h"
#import "MonoServiceLogicExt.h"

@class AVCaptureDevice, AVCaptureSession, AVCaptureStillImageOutput, AVCaptureVideoDataOutput, EditImageAnimatedTextTool, EditImageColor, EmoticonCameraFollowImageView, EmoticonCameraReportObject, EmoticonCameraResultView, EmoticonCameraToolBar, EmoticonLensDynamicTipView, EmoticonLensDynamicToolView, EmoticonLensItemPB, MCFilterManager, MMCircularProgressView, MMSightRecordHelperView, MMSightRecordView, MMUIButton, NSObject<OS_dispatch_queue>, NSString, SightPreviewViewF3, StreamVoiceInputLogic, UIImageView;

@interface EmoticonCameraViewController : MMUIViewController <AVCaptureVideoDataOutputSampleBufferDelegate, AVCaptureAudioDataOutputSampleBufferDelegate, MMSightRecordHelperViewDelegate, EmoticonCameraResultViewDelegate, EditImageAnimatedDelegate, IStreamVoiceInputExt, MonoServiceLogicExt, ISysCallCheckExt, MCFilterDelegate, MCDataOutputDelegate, MCFilterManagerDelegate, EmoticonLensDynamicToolViewDelegate>
{
    EmoticonCameraToolBar *m_toolBar;
    MMUIButton *m_hideBarBtn;
    MMUIButton *m_cameraSwitchBtn;
    MMUIButton *m_photoBtn;
    UIImageView *m_audioRecordView;
    MMSightRecordHelperView *m_recordHelperView;
    MMCircularProgressView *m_circleProgress;
    MMSightRecordView *m_recordButtonView;
    EmoticonCameraResultView *m_resultView;
    _Bool m_needFocusCenter;
    double m_lastScaleFactor;
    StreamVoiceInputLogic *m_inputLogic;
    unsigned long long m_currentInputId;
    NSString *m_lastVoiceInputResult;
    EmoticonCameraFollowImageView *m_followImageView;
    EditImageAnimatedTextTool *m_editImageTextView;
    EmoticonLensDynamicToolView *m_emoticonLensDynamicToolBar;
    EmoticonLensItemPB *m_currentSelectedEmoticonLens;
    EmoticonLensDynamicTipView *m_emoticonLensDynamicTip;
    EditImageColor *m_defaultCaptionColor;
    _Bool _isGPUFrozen;
    _Bool _enableNewYearPendant;
    id <EmoticonCameraDelegate> _delegate;
    NSString *_followMd5;
    NSString *_followCaption;
    NSString *_followCaptionColor;
    NSString *_followLensId;
    unsigned long long _scene;
    EmoticonCameraReportObject *_reportObject;
    MCFilterManager *_filterManager;
    SightPreviewViewF3 *_previewView;
    NSObject<OS_dispatch_queue> *_captureQueue;
    AVCaptureDevice *_cameraDevice;
    AVCaptureSession *_captureSession;
    AVCaptureVideoDataOutput *_videoDataOutput;
    AVCaptureStillImageOutput *_stillImageOutput;
    NSString *_caption;
    EditImageColor *_captionColor;
}

+ (id)imageWithView:(id)arg1;
@property(nonatomic) _Bool enableNewYearPendant; // @synthesize enableNewYearPendant=_enableNewYearPendant;
@property _Bool isGPUFrozen; // @synthesize isGPUFrozen=_isGPUFrozen;
@property(retain, nonatomic) EditImageColor *captionColor; // @synthesize captionColor=_captionColor;
@property(retain, nonatomic) NSString *caption; // @synthesize caption=_caption;
@property(retain, nonatomic) AVCaptureStillImageOutput *stillImageOutput; // @synthesize stillImageOutput=_stillImageOutput;
@property(retain, nonatomic) AVCaptureVideoDataOutput *videoDataOutput; // @synthesize videoDataOutput=_videoDataOutput;
@property(retain, nonatomic) AVCaptureSession *captureSession; // @synthesize captureSession=_captureSession;
@property(retain, nonatomic) AVCaptureDevice *cameraDevice; // @synthesize cameraDevice=_cameraDevice;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *captureQueue; // @synthesize captureQueue=_captureQueue;
@property(retain, nonatomic) SightPreviewViewF3 *previewView; // @synthesize previewView=_previewView;
@property(retain, nonatomic) MCFilterManager *filterManager; // @synthesize filterManager=_filterManager;
@property(retain, nonatomic) EmoticonCameraReportObject *reportObject; // @synthesize reportObject=_reportObject;
@property(nonatomic) unsigned long long scene; // @synthesize scene=_scene;
@property(retain, nonatomic) NSString *followLensId; // @synthesize followLensId=_followLensId;
@property(retain, nonatomic) NSString *followCaptionColor; // @synthesize followCaptionColor=_followCaptionColor;
@property(retain, nonatomic) NSString *followCaption; // @synthesize followCaption=_followCaption;
@property(retain, nonatomic) NSString *followMd5; // @synthesize followMd5=_followMd5;
@property(nonatomic) __weak id <EmoticonCameraDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)doSelectedEmoticonLens:(id)arg1;
- (void)onEmoticonLensSelected:(id)arg1;
- (void)EndInterruption;
- (void)BeginInterruption;
- (void)onMonoServiceDidEnd;
- (void)onMonoServiceWalkieTalkieWillStart;
- (void)onMonoServiceMultitalkWillStart;
- (void)onMonoServiceVoipWillStart;
- (void)adjustEditImageAnimatedWidgetTool:(id)arg1;
- (void)onVoiceSilentTooLong:(unsigned int)arg1;
- (void)OnVoiceTransEnd:(unsigned int)arg1;
- (void)OnError:(int)arg1 andInputId:(unsigned int)arg2;
- (void)onGetResultText:(id)arg1 andInputId:(unsigned int)arg2;
- (void)OnLevelMeter:(unsigned int)arg1 Peak:(float)arg2;
- (void)OnEndRecord;
- (void)OnStartRecord;
- (void)onResultViewClickDoneWithUploadInfo:(id)arg1;
- (void)onResultViewClickBack;
- (void)stopLoading;
- (void)onRecordHelperViewStartRecord:(id)arg1;
- (void)onRecordHelperViewTouchEnded:(id)arg1 shouldRecord:(_Bool)arg2;
- (void)onRecordHelperViewTouchMoved:(id)arg1 point:(struct CGPoint)arg2;
- (void)onRecordHelperViewTouchBegan:(id)arg1;
- (void)MCFilterNeedShowTips:(id)arg1 text:(id)arg2 withDuration:(double)arg3;
- (void)captureOutput:(id)arg1 didOutputSampleBuffer:(struct opaqueCMSampleBuffer *)arg2 fromConnection:(id)arg3;
- (void)refreshEditImageTextView;
- (id)privateCaptionColor;
- (id)privateCaption;
- (id)getPreset;
- (void)setupCameraDevice:(long long)arg1;
- (void)didBecomeActive;
- (void)didEnterBackground;
- (void)handlePinchGesture:(id)arg1;
- (void)handleDoubleTap:(id)arg1;
- (void)handleFocusTap:(id)arg1;
- (void)onEndInterruption;
- (void)interruptRecord;
- (void)focusCenter;
- (void)focusAtPoint:(struct CGPoint)arg1;
- (void)setZoomFactor:(double)arg1;
- (void)openKitChen:(id)arg1;
- (void)btnRelease;
- (void)openSelectPhoto;
- (void)cameraButtonPressed;
- (void)close;
- (void)showTips:(id)arg1;
- (float)sightCaptureMaxDuration;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewWillAppear:(_Bool)arg1;
- (void)updateCameraAccessibility;
- (void)configFollowImageView;
- (void)configEmoticonLensDynamicTool;
- (void)configToolBar;
- (void)configFilterSetting;
- (void)configGesture;
- (void)viewDidLoad;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
