//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class EAGLContext, NSObject<OS_dispatch_queue>;

@interface TXCOpenGLContext : NSObject
{
    int _refCnt;
    struct _opaque_pthread_mutex_t _refCntMutex;
    _Bool _isSync;
    EAGLContext *_glContext;
    NSObject<OS_dispatch_queue> *_renderQueue;
    struct __CVOpenGLESTextureCache *_coreVideoTextureCache;
}

+ (_Bool)supportsFastTextureUpload;
+ (id)sharedInstance;
@property(nonatomic) struct __CVOpenGLESTextureCache *coreVideoTextureCache; // @synthesize coreVideoTextureCache=_coreVideoTextureCache;
@property(nonatomic) _Bool isSync; // @synthesize isSync=_isSync;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *renderQueue; // @synthesize renderQueue=_renderQueue;
@property(retain, nonatomic) EAGLContext *glContext; // @synthesize glContext=_glContext;
- (void).cxx_destruct;
- (void)decreaseReference;
- (void)increaseReference;
- (void)runAsyncOnRenderQueue:(CDUnknownBlockType)arg1;
- (void)runSyncOnRenderQueue:(CDUnknownBlockType)arg1;
- (id)openGLContext;
- (void)setupGLContext;
- (void)dealloc;
- (id)init;

@end

