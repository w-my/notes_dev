//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "MVMediaMakerControllerDelegate.h"
#import "MVMediaPickerControllerDelegate.h"

@class MVMediaMakerController, NSString, UIViewController;

@interface QNMicrovisionManager : NSObject <MVMediaMakerControllerDelegate, MVMediaPickerControllerDelegate>
{
    id <QNMicrovisionVideoHandleable> _currentHandler;
    MVMediaMakerController *_presentedController;
    UIViewController *_fromController;
}

+ (void)initialize;
+ (id)sharedInstance;
@property(nonatomic) __weak UIViewController *fromController; // @synthesize fromController=_fromController;
@property(nonatomic) __weak MVMediaMakerController *presentedController; // @synthesize presentedController=_presentedController;
@property(readonly, nonatomic) id <QNMicrovisionVideoHandleable> currentHandler; // @synthesize currentHandler=_currentHandler;
- (void).cxx_destruct;
- (void)p_showForbiddenAlert:(id)arg1 message:(id)arg2;
- (void)p_showCameraAudioForbiddenAlert;
- (void)p_showCameraVideoForbiddenAlert;
- (void)p_checkAuthorization;
- (id)p_mvOptionsWithQNOptions:(id)arg1;
- (void)createModelWithAssets:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)p_dismissMakerController:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)mediaPickerControllerDidCancel:(id)arg1;
- (void)mediaPickerController:(id)arg1 didFinishPickingMediaAssets:(id)arg2;
- (void)mediaMakerController:(id)arg1 didFinishWithMedia:(id)arg2 info:(id)arg3;
- (void)mediaMakerControllerWillPickMedia:(id)arg1;
- (void)mediaMakerController:(id)arg1 didExitWithMedia:(id)arg2;
- (void)presentMVMakerControllerFrom:(id)arg1 videoHandler:(id)arg2 withOptions:(id)arg3;
- (void)presentMVMakerControllerFrom:(id)arg1 videoHandler:(id)arg2;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

