//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MatrixBaseModel.h"

@class NSString;

@interface MSThreadInfo : MatrixBaseModel
{
    NSString *_threadName;
    unsigned long long _allocSize;
}

@property(nonatomic) unsigned long long allocSize; // @synthesize allocSize=_allocSize;
@property(retain, nonatomic) NSString *threadName; // @synthesize threadName=_threadName;
- (void).cxx_destruct;

@end

