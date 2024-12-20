//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class TVDLProxyReachability;

@interface TVDLProxyNetworkCheckerManager : NSObject
{
    TVDLProxyReachability *_hostReachability;
    TVDLProxyReachability *_internetReachability;
}

@property(readonly, nonatomic) TVDLProxyReachability *internetReachability; // @synthesize internetReachability=_internetReachability;
@property(readonly, nonatomic) TVDLProxyReachability *hostReachability; // @synthesize hostReachability=_hostReachability;
- (void).cxx_destruct;
- (void)setupReachability;
- (void)dealloc;
- (id)init;

@end

