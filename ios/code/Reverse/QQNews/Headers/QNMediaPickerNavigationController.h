//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNavigationController.h"

#import "UIImagePickerControllerDelegate.h"
#import "UINavigationControllerDelegate.h"

@class NSArray, NSString, QNAlbumListViewController, QNMediaPickerControllerParam, QNMediaPickerViewController, UIImagePickerController;

@interface QNMediaPickerNavigationController : QNNavigationController <UINavigationControllerDelegate, UIImagePickerControllerDelegate>
{
    _Bool _didPushImagePickerVC;
    NSArray *_selectedModels;
    CDUnknownBlockType _videoClickBlock;
    CDUnknownBlockType _finishBlock;
    CDUnknownBlockType _cancelBlock;
    QNAlbumListViewController *_albumListVC;
    QNMediaPickerViewController *_mediaPickerVC;
    UIImagePickerController *_imagePickerController;
    QNMediaPickerControllerParam *_mediaPickerParam;
}

+ (void)p_cameraRequestAuthorizeWithCompletionHandler:(CDUnknownBlockType)arg1;
+ (long long)p_cameraAuthorizationStatus;
+ (void)p_showMediaPickerForbiddenAlert:(id)arg1 cancelBlock:(CDUnknownBlockType)arg2 sourceType:(long long)arg3;
+ (void)p_pushSystemImagePickerWithController:(id)arg1 sourceType:(long long)arg2 finishBlock:(CDUnknownBlockType)arg3 cancelBlock:(CDUnknownBlockType)arg4;
+ (void)p_pushImagePickerWithController:(id)arg1 mediaPickerParam:(id)arg2 selectedModels:(id)arg3 videoClickBlock:(CDUnknownBlockType)arg4 finishBlock:(CDUnknownBlockType)arg5 cancelBlock:(CDUnknownBlockType)arg6;
+ (void)p_presentSystemInController:(id)arg1 sourceType:(long long)arg2 finishBlock:(CDUnknownBlockType)arg3 cancelBlock:(CDUnknownBlockType)arg4;
+ (void)presentSystemWithController:(id)arg1 sourceType:(long long)arg2 finishBlock:(CDUnknownBlockType)arg3 cancelBlock:(CDUnknownBlockType)arg4;
+ (void)presentWithController:(id)arg1 mediaPickerParam:(id)arg2 selectedModels:(id)arg3 videoClickBlock:(CDUnknownBlockType)arg4 finishBlock:(CDUnknownBlockType)arg5 cancelBlock:(CDUnknownBlockType)arg6;
+ (void)presentWithController:(id)arg1 mediaPickerParam:(id)arg2 videoClickBlock:(CDUnknownBlockType)arg3;
+ (void)presentWithController:(id)arg1 mediaPickerParam:(id)arg2 finishBlock:(CDUnknownBlockType)arg3 cancelBlock:(CDUnknownBlockType)arg4;
@property(retain, nonatomic) QNMediaPickerControllerParam *mediaPickerParam; // @synthesize mediaPickerParam=_mediaPickerParam;
@property(nonatomic) _Bool didPushImagePickerVC; // @synthesize didPushImagePickerVC=_didPushImagePickerVC;
@property(retain, nonatomic) UIImagePickerController *imagePickerController; // @synthesize imagePickerController=_imagePickerController;
@property(retain, nonatomic) QNMediaPickerViewController *mediaPickerVC; // @synthesize mediaPickerVC=_mediaPickerVC;
@property(retain, nonatomic) QNAlbumListViewController *albumListVC; // @synthesize albumListVC=_albumListVC;
@property(copy, nonatomic) CDUnknownBlockType cancelBlock; // @synthesize cancelBlock=_cancelBlock;
@property(copy, nonatomic) CDUnknownBlockType finishBlock; // @synthesize finishBlock=_finishBlock;
@property(copy, nonatomic) CDUnknownBlockType videoClickBlock; // @synthesize videoClickBlock=_videoClickBlock;
@property(copy, nonatomic) NSArray *selectedModels; // @synthesize selectedModels=_selectedModels;
- (void).cxx_destruct;
- (void)imagePickerControllerDidCancel:(id)arg1;
- (void)imagePickerController:(id)arg1 didFinishPickingMediaWithInfo:(id)arg2;
- (void)cancelButtonClick;
- (void)didReceiveMemoryWarning;
- (void)viewDidLoad;
- (id)initWithParams:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
