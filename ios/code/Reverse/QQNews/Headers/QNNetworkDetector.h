//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface QNNetworkDetector : NSObject
{
}

+ (id)createDetectTaskWithURLString:(id)arg1 domain:(id)arg2;
+ (void)_handleParallelResponse:(id)arg1 domain:(id)arg2 comletionBlock:(CDUnknownBlockType)arg3;
+ (void)asyncDetectWithDomain:(id)arg1 ip:(id)arg2 comletionBlock:(CDUnknownBlockType)arg3;
+ (void)asyncDetectWithDomain:(id)arg1 ip:(id)arg2;
+ (void)cancelAllTasks;
+ (void)configDetectingContext;
+ (void)asyncDetectNetworkConnectivity:(CDUnknownBlockType)arg1;

@end
