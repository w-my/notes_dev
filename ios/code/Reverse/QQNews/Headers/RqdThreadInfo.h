//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSString;

@interface RqdThreadInfo : NSObject
{
    _Bool isCrashThread;
    int threadIndex;
    NSString *threadName;
    NSArray *threadStacks;
    NSArray *threadTrace;
}

@property(copy, nonatomic) NSArray *threadTrace; // @synthesize threadTrace;
@property(copy, nonatomic) NSArray *threadStacks; // @synthesize threadStacks;
@property(nonatomic) _Bool isCrashThread; // @synthesize isCrashThread;
@property(retain, nonatomic) NSString *threadName; // @synthesize threadName;
@property(nonatomic) int threadIndex; // @synthesize threadIndex;
- (void).cxx_destruct;
- (id)debugDescription;
- (id)description;
- (id)getCurrThreadStackLines;
- (id)getCurrThreadUUID;
- (id)getAllShortNames;

@end

