//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVMediaInternalAction.h"

@interface MVMediaTimelineControlAction : MVMediaInternalAction
{
    long long _type;
}

+ (id)seekActionWithStartTime:(double)arg1 endTime:(double)arg2;
+ (id)actionWithStartTime:(double)arg1 endTime:(double)arg2;
@property(nonatomic) long long type; // @synthesize type=_type;

@end

