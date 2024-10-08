//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSMutableArray;

@interface MVMediaCompositionSegment : NSObject
{
    double _startTime;
    double _endTime;
    NSMutableArray *_allActions;
    NSMutableArray *_allCompositions;
}

+ (id)segmentWithAction:(id)arg1;
+ (id)segmentWithStartTime:(double)arg1 endTime:(double)arg2;
@property(retain, nonatomic) NSMutableArray *allCompositions; // @synthesize allCompositions=_allCompositions;
@property(retain, nonatomic) NSMutableArray *allActions; // @synthesize allActions=_allActions;
@property(nonatomic) double endTime; // @synthesize endTime=_endTime;
@property(nonatomic) double startTime; // @synthesize startTime=_startTime;
- (void).cxx_destruct;
- (id)description;
- (_Bool)mergeWithSegment:(id)arg1;
@property(readonly, nonatomic) _Bool isEmpty;
- (id)copy;
@property(readonly, nonatomic) NSArray *compositions;
@property(readonly, nonatomic) NSArray *actions;
- (id)init;
- (void)removeAction:(id)arg1;
- (void)addAction:(id)arg1;

@end

