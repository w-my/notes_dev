//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QNCache;

@interface QNRoseLiveRoomFragmentLayoutMetricCache : NSObject
{
    QNCache *_cache;
}

- (void).cxx_destruct;
- (id)p_cacheKeyForCommentItem:(id)arg1;
- (void)clearCachedLayoutMetricsForCommentItem:(id)arg1;
- (double)cachedFragmentHeightForCommentItem:(id)arg1 fragmentLevel:(long long)arg2 fragmentIndex:(long long)arg3 computeIfMissed:(CDUnknownBlockType)arg4;
- (id)init;

@end

