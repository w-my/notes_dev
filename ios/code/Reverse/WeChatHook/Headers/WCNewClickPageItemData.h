//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "PBCoding.h"

@class NSMutableDictionary, NSString;

@interface WCNewClickPageItemData : MMObject <PBCoding>
{
    int costTime;
    unsigned int count;
    unsigned int specialPV;
    NSString *pageID;
    NSMutableDictionary *dicWidgetDatas;
}

+ (void)initialize;
@property(retain, nonatomic) NSMutableDictionary *dicWidgetDatas; // @synthesize dicWidgetDatas;
@property(nonatomic) unsigned int specialPV; // @synthesize specialPV;
@property(nonatomic) unsigned int count; // @synthesize count;
@property(nonatomic) int costTime; // @synthesize costTime;
@property(retain, nonatomic) NSString *pageID; // @synthesize pageID;
- (void).cxx_destruct;
- (id)init;
- (const map_f8690629 *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

