//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MultiFilterConnect.h"

@class MVGPUImageLookUpFilter, NSString;

@interface MVLoopUpFilter : MultiFilterConnect
{
    NSString *_name;
    double _intensity;
    MVGPUImageLookUpFilter *_filter;
}

@property(retain, nonatomic) MVGPUImageLookUpFilter *filter; // @synthesize filter=_filter;
@property(nonatomic) double intensity; // @synthesize intensity=_intensity;
@property(retain, nonatomic) NSString *name; // @synthesize name=_name;
- (void).cxx_destruct;
- (void)NewFilter;
- (id)initWithName:(id)arg1 intensity:(double)arg2;

@end

