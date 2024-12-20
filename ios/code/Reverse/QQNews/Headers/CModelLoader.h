//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "CModelLoaderProtocol.h"

@class NSData, NSDictionary, NSError, NSOperationQueue, NSString, QNModelLoaderApi;

@interface CModelLoader : NSObject <CModelLoaderProtocol>
{
    id <CModelLoaderDelegate> _delegate;
    NSString *_idStr;
    long long _priority;
    NSDictionary *_params;
    long long _retryCount;
    id _responseData;
    _Bool _needCache;
    _Bool _isOffline;
    _Bool _isForceFromeNet;
    NSOperationQueue *_opQueue;
    NSString *_speedTestName;
    NSString *_speedTestValue;
    NSData *_preAssignedData;
    _Bool _isInOfflineBox;
    _Bool _isLoading;
    _Bool _isFinished;
    _Bool _isFromDisk;
    _Bool _isInFavorite;
    QNModelLoaderApi *_requestApi;
    CDUnknownBlockType _startedBlock;
    CDUnknownBlockType _finishedBlock;
    CDUnknownBlockType _failedBlock;
    NSError *_loaderError;
    double _timeoutSeconds;
}

@property(nonatomic) double timeoutSeconds; // @synthesize timeoutSeconds=_timeoutSeconds;
@property(retain, nonatomic) NSError *loaderError; // @synthesize loaderError=_loaderError;
@property(nonatomic) _Bool isInOfflineBox; // @synthesize isInOfflineBox=_isInOfflineBox;
@property(retain, nonatomic) NSData *preAssignedData; // @synthesize preAssignedData=_preAssignedData;
@property(retain, nonatomic) NSString *speedTestValue; // @synthesize speedTestValue=_speedTestValue;
@property(retain, nonatomic) NSString *speedTestName; // @synthesize speedTestName=_speedTestName;
@property(copy, nonatomic) CDUnknownBlockType failedBlock; // @synthesize failedBlock=_failedBlock;
@property(copy, nonatomic) CDUnknownBlockType finishedBlock; // @synthesize finishedBlock=_finishedBlock;
@property(copy, nonatomic) CDUnknownBlockType startedBlock; // @synthesize startedBlock=_startedBlock;
@property(nonatomic) _Bool isInFavorite; // @synthesize isInFavorite=_isInFavorite;
@property(readonly, nonatomic) _Bool isFromDisk; // @synthesize isFromDisk=_isFromDisk;
@property(nonatomic) _Bool isFinished; // @synthesize isFinished=_isFinished;
@property(nonatomic) _Bool isLoading; // @synthesize isLoading=_isLoading;
@property(nonatomic) _Bool isForceFromeNet; // @synthesize isForceFromeNet=_isForceFromeNet;
@property(nonatomic) _Bool needCache; // @synthesize needCache=_needCache;
@property(retain) id responseData; // @synthesize responseData=_responseData;
@property(nonatomic) long long retryCount; // @synthesize retryCount=_retryCount;
@property(retain) NSDictionary *params; // @synthesize params=_params;
@property(copy, nonatomic) NSString *idStr; // @synthesize idStr=_idStr;
@property(nonatomic) __weak id <CModelLoaderDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) QNModelLoaderApi *requestApi; // @synthesize requestApi=_requestApi;
- (void).cxx_destruct;
- (void)dealloc;
- (void)cancel;
- (void)modelFail;
- (void)modelSuccess;
- (void)modelStart;
- (void)requestFailed;
- (void)requestCompletion:(id)arg1;
- (void)requestStarted;
- (void)writeDataToDisk:(id)arg1;
- (void)loadDataFromDisk:(id)arg1 complete:(CDUnknownBlockType)arg2;
- (_Bool)checkCacheExist:(id)arg1;
- (id)parseContent:(id)arg1 params:(id)arg2;
- (void)startRequest;
- (void)startLoadFromCache;
- (id)createLoadUrl:(id)arg1;
- (void)loadDataFromUrl:(id)arg1 params:(id)arg2 priority:(long long)arg3 offline:(_Bool)arg4 checkCache:(_Bool)arg5;
- (void)loadDataFromUrl:(id)arg1 params:(id)arg2 priority:(long long)arg3 offline:(_Bool)arg4;
- (void)loadDataFromUrl:(id)arg1 params:(id)arg2 priority:(long long)arg3;
- (void)loadDataFromUrl:(id)arg1 params:(id)arg2 checkCache:(_Bool)arg3;
- (void)loadDataFromUrl:(id)arg1 params:(id)arg2 offline:(_Bool)arg3;
- (void)loadDataFromUrl:(id)arg1 params:(id)arg2;
- (void)loadDataFromUrl:(id)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

