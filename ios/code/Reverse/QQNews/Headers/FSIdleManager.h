//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface FSIdleManager : NSObject
{
    long long _activityCount;
}

+ (id)sharedManager;
@property(nonatomic) long long activityCount; // @synthesize activityCount=_activityCount;
- (void)decrementActivityCount;
- (void)incrementActivityCount;
- (void)updateNetworkActivityIndicatorVisibility;
- (_Bool)isNetworkActivityIndicatorVisible;
- (void)updateNetworkActivityIndicatorVisibilityDelayed;
- (void)dealloc;
- (id)init;

@end

