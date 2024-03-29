//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "MVPkgDownloadTaskProtocol.h"

@class NSString, NSURL;

@interface MVPackageDownloadTask : NSObject <MVPkgDownloadTaskProtocol>
{
    _Bool _isDownloading;
    NSURL *_packageURL;
    NSString *_packageID;
    NSString *_unzipDir;
    CDUnknownBlockType _successBlock;
    CDUnknownBlockType _failureBlock;
    CDUnknownBlockType _progressBlock;
}

@property(nonatomic) _Bool isDownloading; // @synthesize isDownloading=_isDownloading;
@property(copy, nonatomic) CDUnknownBlockType progressBlock; // @synthesize progressBlock=_progressBlock;
@property(copy, nonatomic) CDUnknownBlockType failureBlock; // @synthesize failureBlock=_failureBlock;
@property(copy, nonatomic) CDUnknownBlockType successBlock; // @synthesize successBlock=_successBlock;
@property(retain, nonatomic) NSString *unzipDir; // @synthesize unzipDir=_unzipDir;
@property(retain, nonatomic) NSString *packageID; // @synthesize packageID=_packageID;
@property(retain, nonatomic) NSURL *packageURL; // @synthesize packageURL=_packageURL;
- (void).cxx_destruct;
- (void)cancel;
- (_Bool)unzipFile:(id)arg1 toTargetPath:(id)arg2;
- (void)start;
- (id)initWithPackageID:(id)arg1 packageURL:(id)arg2 unzipDir:(id)arg3 success:(CDUnknownBlockType)arg4 failure:(CDUnknownBlockType)arg5 progress:(CDUnknownBlockType)arg6;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

