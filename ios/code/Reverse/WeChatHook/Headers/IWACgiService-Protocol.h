//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class WACgiRequest;

@protocol IWACgiService <NSObject>
+ (void)invalidateAllRequest;
+ (void)cancelCgiRequest:(unsigned int)arg1;
+ (unsigned int)sendCgi:(WACgiRequest *)arg1 completion:(void (^)(WACgiResponse *, unsigned int))arg2;
@end

