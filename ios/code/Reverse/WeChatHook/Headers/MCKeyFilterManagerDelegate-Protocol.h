//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class GPUImageOutput<GPUImageInput>, MCKeyFilterManager, NSArray, NSString;

@protocol MCKeyFilterManagerDelegate <NSObject>

@optional
- (void)MCKeyFilterManager:(MCKeyFilterManager *)arg1 unsupportedMotionTmpl:(double)arg2 andMinCPULevel:(long long)arg3;
- (void)MCKeyFilterManager:(MCKeyFilterManager *)arg1 handFeatureUpdated:(NSArray *)arg2;
- (void)MCKeyFilterManager:(MCKeyFilterManager *)arg1 faceFeatureUpdated:(NSArray *)arg2;
- (void)MCKeyFilterManagerUpdateFilterChainInQueue:(MCKeyFilterManager *)arg1;
- (GPUImageOutput<GPUImageInput> *)MCKeyFilterManager:(MCKeyFilterManager *)arg1 motionTmplMultiOutputFilter:(NSString *)arg2;
- (void)MCKeyFilterManagerMotionTmplUnSpecifiedFilter:(MCKeyFilterManager *)arg1;
- (void)MCKeyFilterManager:(MCKeyFilterManager *)arg1 motionTmplSelectFilter:(NSString *)arg2;
@end
