//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface TBRegionChangeDistributor : NSObject
{
    _Bool _animated;
    _Bool _byGestured;
    _Bool _isChanging;
    id <TBRegionChangeDistributorDelegate> _delegate;
    long long _zoomCount;
    long long _centerCount;
    long long _rotationCount;
    long long _overlookingCount;
    long long _centerOffsetCount;
}

@property(nonatomic) _Bool isChanging; // @synthesize isChanging=_isChanging;
@property(nonatomic) long long centerOffsetCount; // @synthesize centerOffsetCount=_centerOffsetCount;
@property(nonatomic) long long overlookingCount; // @synthesize overlookingCount=_overlookingCount;
@property(nonatomic) long long rotationCount; // @synthesize rotationCount=_rotationCount;
@property(nonatomic) long long centerCount; // @synthesize centerCount=_centerCount;
@property(nonatomic) long long zoomCount; // @synthesize zoomCount=_zoomCount;
@property(nonatomic) _Bool byGestured; // @synthesize byGestured=_byGestured;
@property(nonatomic) _Bool animated; // @synthesize animated=_animated;
@property(nonatomic) __weak id <TBRegionChangeDistributorDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (id)init;
- (void)reset;
- (void)completeOption:(unsigned long long)arg1;
- (void)registerOption:(unsigned long long)arg1 animated:(_Bool)arg2 byGesture:(_Bool)arg3;
@property(readonly, nonatomic) _Bool isDuringChange;
- (void)notifyRegionDidChangeAnimated:(_Bool)arg1 byGesture:(_Bool)arg2;
- (void)notifyRegionWillChangeAnimated:(_Bool)arg1 byGesture:(_Bool)arg2;
- (_Bool)matchStatic;

@end

