//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSObject<OS_dispatch_queue>, TLNResourceCache, TLNResourceDownloader;

@interface TLNResourceManager : NSObject
{
    TLNResourceCache *_cache;
    TLNResourceDownloader *_downloader;
    NSObject<OS_dispatch_queue> *_loadQueue;
}

+ (id)sharedInstance;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *loadQueue; // @synthesize loadQueue=_loadQueue;
@property(retain, nonatomic) TLNResourceDownloader *downloader; // @synthesize downloader=_downloader;
@property(retain, nonatomic) TLNResourceCache *cache; // @synthesize cache=_cache;
- (void).cxx_destruct;
- (void)cleanAllCaches;
- (void)sendEventWithUrl:(id)arg1 key:(id)arg2;
- (void)sendEventWithImage:(id)arg1 key:(id)arg2;
- (void)loadUrl:(id)arg1 withReceiver:(id)arg2;
- (void)loadUrl:(id)arg1;
- (void)loadImgUrl:(id)arg1 withReceiver:(id)arg2;
- (void)loadImgUrl:(id)arg1;
- (id)init;

@end
