//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableDictionary;

@interface TVKWaterMarkFactory : NSObject
{
    NSMutableDictionary *_waterMarks;
}

@property(retain, nonatomic) NSMutableDictionary *waterMarks; // @synthesize waterMarks=_waterMarks;
- (void).cxx_destruct;
- (id)keyWithWaterMarkInfo:(id)arg1;
- (id)removeWaterMarkViewWithInfo:(id)arg1;
- (void)addWaterMark:(id)arg1 WaterMarkInfo:(id)arg2;
- (id)getWaterMarkView:(id)arg1;
- (id)queryWaterMarkView:(id)arg1;
- (id)createWaterMarkView:(id)arg1;

@end

