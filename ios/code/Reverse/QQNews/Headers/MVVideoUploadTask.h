//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVUploadTask.h"

@class NSString;

@interface MVVideoUploadTask : MVUploadTask
{
    NSString *_videoPath;
    NSString *_vid;
    NSString *_sha1;
}

@property(retain) NSString *sha1; // @synthesize sha1=_sha1;
@property(retain) NSString *vid; // @synthesize vid=_vid;
@property(retain) NSString *videoPath; // @synthesize videoPath=_videoPath;
- (void).cxx_destruct;
- (void)qzUpload:(long long)arg1 taskDetail:(id)arg2 sucess:(id)arg3;
- (void)start;
- (id)uploadVideo;
- (id)initWidthVideoFile:(id)arg1;

@end
