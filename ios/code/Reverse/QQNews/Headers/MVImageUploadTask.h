//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVUploadTask.h"

@class NSString;

@interface MVImageUploadTask : MVUploadTask
{
    NSString *_imagePath;
    NSString *_imageURL;
}

@property(retain) NSString *imageURL; // @synthesize imageURL=_imageURL;
@property(retain) NSString *imagePath; // @synthesize imagePath=_imagePath;
- (void).cxx_destruct;
- (void)qzUpload:(long long)arg1 taskDetail:(id)arg2 sucess:(id)arg3;
- (void)start;
- (id)uploadImage;
- (id)initWithFile:(id)arg1 absolutely:(_Bool)arg2;

@end
