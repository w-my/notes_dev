//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface QNAMRRecorder : NSObject
{
    unsigned long long _startTime;
    double mFileDuration;
    struct __sFILE *_amrFile;
    int *_encoderState;
    struct __CFString *_fileNameRef;
    struct OpaqueAudioQueue *_queue;
    struct AudioQueueBuffer *_bufferRefs[3];
    struct OpaqueAudioFileID *_recordFileID;
    long long _recordPacket;
    struct CAStreamBasicDescription _recordFormat;
    _Bool _recording;
    long long _state;
    id <QNAMRRecorderDelegate> _delegate;
    double _currentTime;
    NSString *_targetFilePath;
    double _duration;
}

@property(nonatomic) double duration; // @synthesize duration=_duration;
@property(retain, nonatomic) NSString *targetFilePath; // @synthesize targetFilePath=_targetFilePath;
@property(readonly) double currentTime; // @synthesize currentTime=_currentTime;
@property(readonly, getter=isRecording) _Bool recording; // @synthesize recording=_recording;
@property(nonatomic) __weak id <QNAMRRecorderDelegate> delegate; // @synthesize delegate=_delegate;
@property(readonly, nonatomic) long long state; // @synthesize state=_state;
- (id).cxx_construct;
- (void).cxx_destruct;
- (void)updateCurrentTime;
- (void)updateRecordPacket:(unsigned int)arg1;
- (void)encodeBuffer:(short *)arg1 length:(int)arg2;
- (void)copyEncoderCookieToFile;
- (int)computeRecordBufferSize:(const struct AudioStreamBasicDescription *)arg1 seconds:(float)arg2;
- (void)setupAudioFormat:(unsigned int)arg1;
- (_Bool)p_stopAudioQueue;
- (id)filePath;
- (_Bool)deleteRecording;
- (_Bool)stop;
- (_Bool)pause;
- (_Bool)recordAtTime:(double)arg1 forDuration:(double)arg2;
- (_Bool)recordForDuration:(double)arg1;
- (_Bool)record;
- (_Bool)prepareToRecord;
- (void)dealloc;
- (id)init;
- (id)initWithFilePath:(id)arg1;

@end
