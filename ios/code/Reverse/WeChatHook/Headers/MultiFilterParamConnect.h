//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MultiFilterConnect.h"

@class NSMutableArray, NSString;

@interface MultiFilterParamConnect : MultiFilterConnect
{
    NSMutableArray *_baseFilters;
    NSMutableArray *_bridges;
    NSString *_bundlePath;
}

+ (id)createMultiFilterConnect:(id)arg1;
+ (_Bool)isMultiConnect:(long long)arg1;
+ (id)filterWithBaseFilters:(id)arg1 bridges:(id)arg2 bundlePath:(id)arg3;
@property(retain, nonatomic) NSString *bundlePath; // @synthesize bundlePath=_bundlePath;
@property(retain, nonatomic) NSMutableArray *bridges; // @synthesize bridges=_bridges;
@property(retain, nonatomic) NSMutableArray *baseFilters; // @synthesize baseFilters=_baseFilters;
- (void).cxx_destruct;
- (_Bool)parseString:(id)arg1 toFloatArray:(float *)arg2 slotCount:(int)arg3;
- (id)createBaseFilter:(id)arg1;
- (void)doNewFilter;
- (void)NewFilter;
- (id)createMultiFilterParamConnect;
- (id)init;
- (id)initWithBaseFilters:(id)arg1 bridges:(id)arg2 bundlePath:(id)arg3;

@end

