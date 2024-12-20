//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "GameHaowanUploadTaskDelegate.h"
#import "MMService.h"

@class GameHaowanPostInfo, GameHaowanUploadTask, NSString;

@interface GameHaowanPostMgr : MMService <MMService, GameHaowanUploadTaskDelegate>
{
    GameHaowanPostInfo *_postInfo;
    GameHaowanUploadTask *_uploadTask;
}

@property(retain, nonatomic) GameHaowanUploadTask *uploadTask; // @synthesize uploadTask=_uploadTask;
@property(retain, nonatomic) GameHaowanPostInfo *postInfo; // @synthesize postInfo=_postInfo;
- (void).cxx_destruct;
- (int)ssidForTrackEvent;
- (id)buildTrackEventProps;
- (id)reportObjWithAction:(int)arg1;
- (void)trackEventPostFailed:(long long)arg1;
- (void)trackEventPostSucceed:(unsigned int)arg1;
- (void)trackEventAddNewPost;
- (void)writePostInfo:(id)arg1;
- (id)readPostInfo;
- (void)clearPostInfo;
- (void)savePostInfo;
- (void)loadPostInfo;
- (void)tryResumePublish;
- (void)sendHaowanPostRequest:(id)arg1;
- (void)uploadTask:(id)arg1 didContinueDataUpdate:(id)arg2;
- (void)uploadTask:(id)arg1 didProgressChanged:(float)arg2;
- (void)uploadTask:(id)arg1 didFailedWithError:(id)arg2;
- (void)uploadTask:(id)arg1 didSucceedWithResIds:(id)arg2;
- (void)handlePostCanceled:(id)arg1;
- (void)handlePostProgress:(float)arg1;
- (void)handlePostSucceed;
- (void)handlePostFailed:(id)arg1 code:(long long)arg2;
- (id)generatePostId;
- (id)createUploadTask:(id)arg1;
- (void)startUpload;
- (void)startMediaPost:(id)arg1 onSucceed:(CDUnknownBlockType)arg2;
- (void)startTextPost:(id)arg1 onSucceed:(CDUnknownBlockType)arg2;
- (id)publishHaowanPost:(id)arg1;
- (id)getPost:(id)arg1;
- (id)getAllPost;
- (_Bool)cancelPost:(id)arg1;
- (_Bool)cancelAllPost;
- (void)onServiceReloadData;
- (void)onServiceInit;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

