//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "PBCoding.h"

@class NSMutableArray, NSString;

@interface WCSessionUBAConfigModel : MMObject <PBCoding>
{
    NSMutableArray *sessionUBAConfigs;
    NSString *originalJson;
}

+ (void)initialize;
@property(retain, nonatomic) NSString *originalJson; // @synthesize originalJson;
@property(retain, nonatomic) NSMutableArray *sessionUBAConfigs; // @synthesize sessionUBAConfigs;
- (void).cxx_destruct;
- (id)toString;
- (id)init;
- (const map_f8690629 *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

