//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MatrixIssue, NSString;

@protocol MatrixPluginProtocol <NSObject>
+ (NSString *)getTag;
- (void)reportIssueCompleteWithIssue:(MatrixIssue *)arg1 success:(_Bool)arg2;
- (void)reportIssue:(MatrixIssue *)arg1;
- (void)setupPluginListener:(id <MatrixPluginListenerDelegate>)arg1;
- (void)destroy;
- (void)stop;
- (void)start;
@end

