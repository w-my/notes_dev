//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TVDLProxyCGITaskDelegate.h"

@class TVDLProxyCGIGetvinfoTask, TVDLProxyCGIVideoInfo;

@protocol TVDLProxyCGIGetvinfoTaskDelegate <TVDLProxyCGITaskDelegate>
- (void)onGetvinfoError:(TVDLProxyCGIGetvinfoTask *)arg1 withErrorCode:(int)arg2 withDetailErrorCode:(int)arg3;
- (void)onGetvinfoSuccess:(TVDLProxyCGIGetvinfoTask *)arg1 withVideoInfo:(TVDLProxyCGIVideoInfo *)arg2;
@end
