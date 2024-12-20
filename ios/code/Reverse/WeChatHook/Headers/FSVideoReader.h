//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class AVAsset, AVAssetImageGenerator, AVAssetReader, AVAssetReaderOutput, AVAssetTrack, FSVideoFrameBuffer, NSMutableArray, NSObject<OS_dispatch_queue>, NSURL;

@interface FSVideoReader : NSObject
{
    AVAssetReader *_reader;
    AVAssetTrack *_readerTrack;
    AVAssetReaderOutput *_readerVideoTrackOutput;
    AVAssetImageGenerator *imageGenerator;
    NSObject<OS_dispatch_queue> *_readQueue;
    CDStruct_e83c9415 _videoReadRangeMax;
    CDStruct_e83c9415 _videoReadRangeInternal;
    _Bool _prefetchFramesWhenPrepareFinished;
    _Bool _restartWhenComplete;
    _Bool _returnThLastBufferIfFinished;
    _Bool _randomAccess;
    int _videoReadStatus;
    long long _outputFormat;
    double _maxCorpSize;
    AVAsset *_asset;
    NSURL *_videoPath;
    FSVideoFrameBuffer *_lastFrameBuffer;
    unsigned long long _bufferPoolMaxCount;
    NSMutableArray *_bufferPool;
    CDStruct_1b6d18a9 _returnLastBufferIfFinishedTimeInterval;
    CDStruct_1b6d18a9 _currentTimeOff;
    CDStruct_1b6d18a9 _readTimeOffset;
    CDStruct_1b6d18a9 _minFrameDuration;
    CDStruct_1b6d18a9 _seekCurrentTime;
    CDStruct_e83c9415 _range;
}

+ (double)getVideoMaxLength;
+ (void)setVideoMaxLength:(double)arg1;
@property(nonatomic) CDStruct_1b6d18a9 seekCurrentTime; // @synthesize seekCurrentTime=_seekCurrentTime;
@property(nonatomic) int videoReadStatus; // @synthesize videoReadStatus=_videoReadStatus;
@property(retain, nonatomic) NSMutableArray *bufferPool; // @synthesize bufferPool=_bufferPool;
@property(nonatomic) unsigned long long bufferPoolMaxCount; // @synthesize bufferPoolMaxCount=_bufferPoolMaxCount;
@property(retain) FSVideoFrameBuffer *lastFrameBuffer; // @synthesize lastFrameBuffer=_lastFrameBuffer;
@property(nonatomic) CDStruct_1b6d18a9 minFrameDuration; // @synthesize minFrameDuration=_minFrameDuration;
@property(nonatomic) CDStruct_e83c9415 range; // @synthesize range=_range;
@property(nonatomic) CDStruct_1b6d18a9 readTimeOffset; // @synthesize readTimeOffset=_readTimeOffset;
@property(retain, nonatomic) NSURL *videoPath; // @synthesize videoPath=_videoPath;
@property(retain, nonatomic) AVAsset *asset; // @synthesize asset=_asset;
@property(nonatomic) CDStruct_1b6d18a9 currentTimeOff; // @synthesize currentTimeOff=_currentTimeOff;
@property(nonatomic) _Bool randomAccess; // @synthesize randomAccess=_randomAccess;
@property(nonatomic) CDStruct_1b6d18a9 returnLastBufferIfFinishedTimeInterval; // @synthesize returnLastBufferIfFinishedTimeInterval=_returnLastBufferIfFinishedTimeInterval;
@property(nonatomic) _Bool returnThLastBufferIfFinished; // @synthesize returnThLastBufferIfFinished=_returnThLastBufferIfFinished;
@property(nonatomic) _Bool restartWhenComplete; // @synthesize restartWhenComplete=_restartWhenComplete;
@property(nonatomic) _Bool prefetchFramesWhenPrepareFinished; // @synthesize prefetchFramesWhenPrepareFinished=_prefetchFramesWhenPrepareFinished;
@property(nonatomic) double maxCorpSize; // @synthesize maxCorpSize=_maxCorpSize;
@property(nonatomic) long long outputFormat; // @synthesize outputFormat=_outputFormat;
- (void).cxx_destruct;
- (id)readerVideoTrackOutput;
- (long long)readerStatus;
- (id)reader;
@property(readonly, nonatomic) CDStruct_1b6d18a9 duration;
- (void)sampleBufferWithTimeArray:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (struct CGImage *)copySampleBufferAtTime:(CDStruct_1b6d18a9)arg1 actualTime:(CDStruct_1b6d18a9 *)arg2 error:(id *)arg3;
- (id)createImageGenerator;
- (id)nextSampleBufferWithReaderStatus:(long long *)arg1 frameTime:(CDStruct_1b6d18a9)arg2 waitUntilFinish:(_Bool)arg3;
- (id)nextSampleBufferWithReaderStatus:(long long *)arg1 frameTime:(CDStruct_1b6d18a9)arg2;
- (id)nextSampleBufferWithReaderStatus:(long long *)arg1;
- (id)nextSampleBufferWithPreferFrameTime:(CDStruct_1b6d18a9)arg1 waitUntilFinish:(_Bool)arg2;
- (id)nextSampleBuffer;
- (id)checkReturnLastSampleBuffer:(CDStruct_1b6d18a9)arg1;
- (id)getNextBufferPreferFrameTime:(CDStruct_1b6d18a9 *)arg1 needAddToBufflePool:(out _Bool *)arg2;
- (struct opaqueCMSampleBuffer *)copyNextSampleBuffer;
- (id)imageFromBuffer:(struct opaqueCMSampleBuffer *)arg1;
- (CDStruct_e83c9415)setupVideoReadRangeWithSeekTime:(CDStruct_1b6d18a9)arg1;
- (void)setReaderTimeRangeWithStartTime:(CDStruct_1b6d18a9)arg1 setReaderTime:(_Bool)arg2;
- (void)setCurrentTime:(CDStruct_1b6d18a9)arg1;
- (void)seekTime:(CDStruct_1b6d18a9)arg1;
- (void)readAndCacheFrameBuffer:(CDStruct_1b6d18a9)arg1 async:(_Bool)arg2;
- (void)readAndCacheFrameBuffer;
- (void)clearCacheBuffer;
- (id)popFrameBuffer:(CDStruct_1b6d18a9)arg1;
- (id)pushFrameBuffer:(id)arg1;
- (_Bool)canPushFrameBuffer;
- (_Bool)_startRunning;
- (_Bool)beginReading;
- (_Bool)couldReadAsset;
- (void)endReading;
- (void)resetWithStartTime:(CDStruct_1b6d18a9)arg1 recreateReader:(_Bool)arg2 async:(_Bool)arg3;
- (void)resetWithStartTime:(CDStruct_1b6d18a9)arg1 recreateReader:(_Bool)arg2;
- (void)resetWithStartTime:(CDStruct_1b6d18a9)arg1 async:(_Bool)arg2;
- (void)resetWithStartTime:(CDStruct_1b6d18a9)arg1;
- (void)reset:(_Bool)arg1;
- (void)reset;
- (void)_clearAllReaderResource;
- (void)setTimeRange:(CDStruct_e83c9415)arg1;
- (id)createAssetReader;
- (void)prepareForReadingWaitUntilFinish:(_Bool)arg1 completion:(CDUnknownBlockType)arg2;
- (void)prepareForReadingWithCompletion:(CDUnknownBlockType)arg1;
- (void)prepareForReading;
- (void)dealloc;
- (id)description;
- (id)initWithVideoPath:(id)arg1 outputFormat:(long long)arg2;
- (id)initWithAsset:(id)arg1 outputFormat:(long long)arg2;
- (id)initWithVideoPath:(id)arg1;
- (id)init;
- (_Bool)checkThreadSafe;
- (void)runSyncBlock:(CDUnknownBlockType)arg1;
- (void)runAsyncBlock:(_Bool)arg1 block:(CDUnknownBlockType)arg2;
- (void)runAsyncBlock:(CDUnknownBlockType)arg1;
- (void)setReadQueue:(id)arg1;
- (id)readQueue;

@end

