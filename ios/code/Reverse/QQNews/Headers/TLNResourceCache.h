//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSCache, NSFileManager, NSObject<OS_dispatch_queue>, NSString;

@interface TLNResourceCache : NSObject
{
    NSCache *_memCache;
    NSFileManager *_fileManager;
    NSString *_diskCachePath;
    NSObject<OS_dispatch_queue> *_ioQueue;
}

@property(retain, nonatomic) NSObject<OS_dispatch_queue> *ioQueue; // @synthesize ioQueue=_ioQueue;
@property(copy, nonatomic) NSString *diskCachePath; // @synthesize diskCachePath=_diskCachePath;
@property(retain, nonatomic) NSFileManager *fileManager; // @synthesize fileManager=_fileManager;
@property(retain, nonatomic) NSCache *memCache; // @synthesize memCache=_memCache;
- (void).cxx_destruct;
- (void)cleanAllCaches;
- (long long)directorySizeAtPath:(id)arg1;
- (void)cleanDiskCache;
- (void)appDidEnterBackground:(id)arg1;
- (id)defaultCachePathForKey:(id)arg1;
- (id)cachePathForKey:(id)arg1 inPath:(id)arg2;
- (id)makeDiskCachePath:(id)arg1;
- (id)localUrlForKey:(id)arg1;
- (void)storeData:(id)arg1 forKey:(id)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)storeData:(id)arg1 forKey:(id)arg2;
- (id)imageForKey:(id)arg1;
- (void)setImage:(id)arg1 data:(id)arg2 forKey:(id)arg3 cost:(unsigned long long)arg4;
- (id)init;

@end
