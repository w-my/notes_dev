//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSURLSessionDownloadTask;

@interface TLNResourceDownloaderTask : NSObject
{
    NSURLSessionDownloadTask *_downloadTask;
    CDUnknownBlockType _completionBlock;
}

@property(copy, nonatomic) CDUnknownBlockType completionBlock; // @synthesize completionBlock=_completionBlock;
@property(retain, nonatomic) NSURLSessionDownloadTask *downloadTask; // @synthesize downloadTask=_downloadTask;
- (void).cxx_destruct;
- (id)initWithTask:(id)arg1 completionBlock:(CDUnknownBlockType)arg2;

@end

