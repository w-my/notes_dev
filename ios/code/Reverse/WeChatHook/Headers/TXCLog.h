//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface TXCLog : NSObject
{
}

+ (id)getLogFilePath;
+ (void)setLogCompressEnable:(_Bool)arg1;
+ (id)getLogPath;
+ (void)setLogPath:(id)arg1;
+ (void)setLogHook:(CDUnknownFunctionPointerType)arg1;
+ (void)setConsoleEnabled:(_Bool)arg1;
+ (int)getLevel;
+ (void)setLevel:(int)arg1;
+ (void)init;
- (void)onAppDidBecomeActive:(id)arg1;
- (void)onAppWillResignActive:(id)arg1;

@end
