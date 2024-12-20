//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "MMImagePickerManagerDelegate.h"
#import "MMService.h"
#import "MMSightCameraViewControllerDelegate.h"
#import "MMUIViewControllerExt.h"
#import "WCStoryVideoEditViewControllerDelegate.h"

@class EditStoryImageAttr, NSString, WCStoryCameraViewController, WCStoryPublishReportObj;

@interface WCMyStoryCameraMgr : MMService <MMUIViewControllerExt, MMImagePickerManagerDelegate, WCStoryVideoEditViewControllerDelegate, MMSightCameraViewControllerDelegate, MMService>
{
    WCStoryCameraViewController *_cameraVC;
    CDUnknownBlockType _takenCompletion;
    WCStoryPublishReportObj *_publishReportObj;
    CDUnknownBlockType _willQuitBlock;
    unsigned long long _enterScene;
    EditStoryImageAttr *_storyAttr;
}

@property(retain, nonatomic) EditStoryImageAttr *storyAttr; // @synthesize storyAttr=_storyAttr;
@property(nonatomic) unsigned long long enterScene; // @synthesize enterScene=_enterScene;
@property(copy, nonatomic) CDUnknownBlockType willQuitBlock; // @synthesize willQuitBlock=_willQuitBlock;
@property(retain, nonatomic) WCStoryPublishReportObj *publishReportObj; // @synthesize publishReportObj=_publishReportObj;
@property(copy, nonatomic) CDUnknownBlockType takenCompletion; // @synthesize takenCompletion=_takenCompletion;
@property(nonatomic) __weak WCStoryCameraViewController *cameraVC; // @synthesize cameraVC=_cameraVC;
- (void).cxx_destruct;
- (id)createSightDraftWithVideoPath:(id)arg1 thumbImg:(id)arg2 editVideoAttr:(id)arg3;
- (void)storyVideoEditDidClickCancel:(id)arg1 editVideoAttr:(id)arg2;
- (void)storyVideoEditDidClickDone:(id)arg1 videoPath:(id)arg2 thumbImg:(id)arg3 editVideoAttr:(id)arg4;
- (void)MMImagePickerManager:(id)arg1 didFinishPickingImageWithInfo:(id)arg2;
- (void)createPhotoMovieWithPicker:(id)arg1 selectImageArray:(id)arg2;
- (id)genDataItemWithSightDraftItem:(id)arg1 thumbPath:(id)arg2;
- (void)postNewItemForSight:(id)arg1;
- (void)sendTakePhotoNotification;
- (void)MMImagePickerManagerDidCancel:(id)arg1;
- (void)MMImagePickerManager:(id)arg1 didFinishPickingSightWithInfo:(id)arg2;
- (void)onSightCameraClickRecordBtn;
- (void)onShortVideoTaken:(id)arg1 thumbImg:(id)arg2 sentImmediately:(_Bool)arg3 isMuted:(_Bool)arg4 editVideoAttr:(id)arg5;
- (void)onSightCameraCancel;
- (void)MMUIViewControllerDidBeRemoved:(id)arg1;
- (void)showCameraInViewController:(id)arg1 transitionAnimationType:(unsigned long long)arg2 startPoint:(struct CGPoint)arg3 resultRect:(struct CGRect)arg4 presentAnimate:(_Bool)arg5 presentCompletion:(CDUnknownBlockType)arg6;
- (void)doActionTraceWithType:(unsigned long long)arg1;
- (void)showCameraWithType:(unsigned long long)arg1 inViewController:(id)arg2 resultRect:(struct CGRect)arg3 completion:(CDUnknownBlockType)arg4;
- (void)showImagePicker;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

