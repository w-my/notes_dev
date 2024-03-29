//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSDictionary, NSError, TADMediaConnection;

@protocol TADMediaConnectionDelegate <NSObject>
- (void)connectionDidFailedWithError:(NSError *)arg1 type:(long long)arg2;
- (void)connetionDidReceiveMedias:(NSArray *)arg1;

@optional
- (void)connetionDidReceiveIVBPoints:(NSArray *)arg1;
- (void)connetionDidReceiveBreakPoints:(NSArray *)arg1;
- (void)connetionDidUpdateOfflineAds:(NSArray *)arg1 indexDict:(NSDictionary *)arg2;
- (void)connetion:(TADMediaConnection *)arg1 DidReceiveIvbMedias:(NSArray *)arg2;
- (void)connetionDidFailedWithError:(NSError *)arg1;
@end

