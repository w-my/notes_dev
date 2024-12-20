//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNetworkBaseApi.h"

#import "NSCopying.h"

@class QNAsyncTaskWorkQueue, QNNetworkBaseApiImageSpeedFeedbackModel;

@interface QNImageLoaderApi : QNNetworkBaseApi <NSCopying>
{
    QNNetworkBaseApiImageSpeedFeedbackModel *_speedTestModel;
    QNAsyncTaskWorkQueue *_imageLoaderSericalQueue;
}

@property(retain, nonatomic) QNAsyncTaskWorkQueue *imageLoaderSericalQueue; // @synthesize imageLoaderSericalQueue=_imageLoaderSericalQueue;
@property(retain, nonatomic) QNNetworkBaseApiImageSpeedFeedbackModel *speedTestModel; // @synthesize speedTestModel=_speedTestModel;
- (void).cxx_destruct;
- (id)createSpeedTestModelWithApi:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithURL:(id)arg1 rewrite:(_Bool)arg2 downProgressBlock:(CDUnknownBlockType)arg3 isFirstLoadInDisk:(_Bool)arg4;
- (id)initWithURL:(id)arg1 rewrite:(_Bool)arg2 downProgressBlock:(CDUnknownBlockType)arg3;
- (void)startWithSuccess:(CDUnknownBlockType)arg1 fail:(CDUnknownBlockType)arg2;
- (Class)callbackResultClass;

@end

