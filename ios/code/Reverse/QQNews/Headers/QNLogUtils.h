//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface QNLogUtils : NSObject
{
}

+ (void)addCustomLogger:(id)arg1;
+ (void)setCustomLogFlags:(int)arg1 block:(CDUnknownBlockType)arg2;
+ (id)shortPathString:(const char *)arg1;
+ (void)assert:(_Bool)arg1 statement:(const char *)arg2 filename:(const char *)arg3 lineNumber:(int)arg4 method:(const char *)arg5 messageFormat:(id)arg6;
+ (void)log:(unsigned long long)arg1 messageFormat:(id)arg2;
+ (void)log:(unsigned long long)arg1 filename:(const char *)arg2 lineNumber:(int)arg3 method:(const char *)arg4 messageFormat:(id)arg5;
+ (id)logFilesPaths;
+ (id)logFileLocation;
+ (void)setupLoggers;
+ (void)initialize;

@end
