//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, VideoSetting;

@interface FaceHandle : NSObject
{
    _Bool LooseMode;
    struct Mat BestImg;
    struct SS AG;
    double _timerInterval;
    float eps;
    long long _triggerTimes;
    _Bool FirstISOFrame;
    struct vector<UIImage *, std::__1::allocator<UIImage *>> RawImgVec;
    vector_92f4729b landmarksVec;
    VideoSetting *_setting;
    NSString *_dir_path;
    NSString *_curUserNameFolder;
}

+ (id)sharedInstance;
@property(retain, nonatomic) NSString *curUserNameFolder; // @synthesize curUserNameFolder=_curUserNameFolder;
@property(retain, nonatomic) NSString *dir_path; // @synthesize dir_path=_dir_path;
@property(retain, nonatomic) VideoSetting *setting; // @synthesize setting=_setting;
- (id).cxx_construct;
- (void).cxx_destruct;
- (id)imageFromSampleBuffer:(struct opaqueCMSampleBuffer *)arg1;
- (void)GetImgSequence_buffer:(struct opaqueCMSampleBuffer *)arg1 withDeviceISO:(double)arg2;
- (_Bool)GetImgSequence:(id)arg1 withDeviceISO:(double)arg2;
- (void)getFaces:(CDUnknownBlockType)arg1;
- (void)prepareStartCountTimer:(double)arg1 withMinISO:(double)arg2 withCB:(CDUnknownBlockType)arg3;
- (void)procesDrawScreen:(long long)arg1 withLux:(double)arg2 withSetARGB:(CDUnknownBlockType)arg3 withStopCB:(CDUnknownBlockType)arg4;
- (int)processImgSequence:(CDUnknownBlockType)arg1;
- (struct Mat)FindBestImg;
- (float)get_face_sharp_score:(struct Mat)arg1;
- (long long)GenDataPack;
- (double)getTimeIntercal;
- (id)getDirPath;
- (double)Get_ISObackup;
- (void)setCurUserName:(id)arg1;
- (struct Mat)getBestImg;
- (struct FullPack)getFullPack;
- (struct DataPack)getAGInDataPack;
- (int)getSafety;
- (void)setSafety:(int)arg1;
- (int)getAGLabelShowing;
- (void)setAGLabelShowing:(int)arg1;
- (void)clearAG;
- (long long)initAG:(_Bool)arg1 CAPTCHA:(basic_string_90719d97)arg2;
- (int)initHandle:(id)arg1 CAPTCHA:(const struct CAPTCHA *)arg2;
- (id)init;

@end

