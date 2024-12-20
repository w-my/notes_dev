//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSDictionary, NSMutableDictionary, NSURLSession, TLNModelManager, TLNPreloadManager;

@interface TADCanvasManager : NSObject
{
    TLNPreloadManager *_preloadManager;
    TLNModelManager *_modelManager;
    NSMutableDictionary *_legoDictMap;
    NSDictionary *_preloadPageConfig;
    NSURLSession *_session;
}

+ (id)sharedInstance;
@property(retain, nonatomic) NSURLSession *session; // @synthesize session=_session;
@property(retain, nonatomic) NSDictionary *preloadPageConfig; // @synthesize preloadPageConfig=_preloadPageConfig;
@property(retain, nonatomic) NSMutableDictionary *legoDictMap; // @synthesize legoDictMap=_legoDictMap;
@property(retain, nonatomic) TLNModelManager *modelManager; // @synthesize modelManager=_modelManager;
@property(retain, nonatomic) TLNPreloadManager *preloadManager; // @synthesize preloadManager=_preloadManager;
- (void).cxx_destruct;
- (void)cleanAllCaches;
- (void)reportWithUrl:(id)arg1 dict:(id)arg2 retryCount:(long long)arg3;
- (void)reportWithUrl:(id)arg1 dict:(id)arg2;
- (void)reportWithUrl:(id)arg1;
- (void)getLegoDictWithUrl:(id)arg1 completionBlock:(CDUnknownBlockType)arg2;
- (void)preloadForJSONUrl:(id)arg1 page:(unsigned long long)arg2 isWifi:(_Bool)arg3;
- (id)init;

@end

