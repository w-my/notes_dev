//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray;

@interface TVKActionWaterMarkScene : NSObject
{
    int _inTime;
    int _outTime;
    int _start;
    int _end;
    NSArray *_waterMarkInfos;
}

@property(retain, nonatomic) NSArray *waterMarkInfos; // @synthesize waterMarkInfos=_waterMarkInfos;
@property(nonatomic) int end; // @synthesize end=_end;
@property(nonatomic) int start; // @synthesize start=_start;
@property(nonatomic) int outTime; // @synthesize outTime=_outTime;
@property(nonatomic) int inTime; // @synthesize inTime=_inTime;
- (void).cxx_destruct;

@end

