//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

@class NSString;

@interface TaskInfo : MMObject
{
    _Bool _bIsPresented;
    double taskAddTime;
    NSString *taskBizKey;
}

@property(nonatomic) _Bool bIsPresented; // @synthesize bIsPresented=_bIsPresented;
@property(retain, nonatomic) NSString *taskBizKey; // @synthesize taskBizKey;
@property(nonatomic) double taskAddTime; // @synthesize taskAddTime;
- (void).cxx_destruct;

@end
