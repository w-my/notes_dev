//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableDictionary;

@interface QNNonstandardAdManager : NSObject
{
    NSMutableDictionary *_adDislikeDic;
}

+ (id)sharedInstance;
- (void).cxx_destruct;
- (void)appWillResignActiveNotification:(id)arg1;
- (id)p_getExpiredTime:(long long)arg1 startDate:(id)arg2;
- (void)unlikeAdItemId:(id)arg1;
- (_Bool)isNonstandardAdUnliked:(id)arg1;
- (void)clearData;
- (void)p_writeDataToDisk;
- (void)p_readDataFromDisk;
- (id)getFilePath;
- (void)dealloc;
- (id)init;

@end

