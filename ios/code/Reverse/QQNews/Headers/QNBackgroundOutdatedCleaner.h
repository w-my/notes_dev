//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface QNBackgroundOutdatedCleaner : NSObject
{
    unsigned long long _cleanExpiredTask;
    unsigned long long _cleanExpiredVideoTask;
}

+ (id)sharedInstance;
@property(nonatomic) unsigned long long cleanExpiredVideoTask; // @synthesize cleanExpiredVideoTask=_cleanExpiredVideoTask;
@property(nonatomic) unsigned long long cleanExpiredTask; // @synthesize cleanExpiredTask=_cleanExpiredTask;
- (void)p_removeOutDatedFilesWithOutDate:(id)arg1 dirPath:(id)arg2 limitInSeconds:(double)arg3 deletedFileNames:(id *)arg4 runningTime:(double *)arg5;
- (void)p_removeOutDatedVideosWithLimitInSeconds:(double)arg1 deletedFileNames:(id *)arg2 runningTime:(double *)arg3;
- (double)p_cleanWebViewCacheWithTimeLimit:(double)arg1;
- (double)p_cleanOutDateArticlesWithTimeLimit:(double)arg1;
- (double)p_cleanOutDateImagesWithTimeLimit:(double)arg1;
- (void)p_cleanOutDateVideosWithTimeLimit:(double)arg1;
- (void)p_cleanOutDateImageArticlesWithTimeLimit:(double)arg1;
- (void)p_cleanOutDateVideoItems:(_Bool)arg1;
- (void)p_cleanOutDateImageArticleItems:(_Bool)arg1;
- (void)stopCleanOutDateItems;
- (void)cleanOutDateItems:(_Bool)arg1;

@end
