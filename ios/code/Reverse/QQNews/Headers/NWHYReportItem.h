//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableArray, NSString;

@interface NWHYReportItem : NSObject
{
    NSMutableArray *_reportValueArr;
    int _type;
    NSString *_bid;
    NSString *_tid;
    NSString *_opername;
    NSString *_module;
    NSString *_action;
}

@property(nonatomic) int type; // @synthesize type=_type;
@property(retain, nonatomic) NSString *action; // @synthesize action=_action;
@property(retain, nonatomic) NSString *module; // @synthesize module=_module;
@property(retain, nonatomic) NSString *opername; // @synthesize opername=_opername;
@property(retain, nonatomic) NSString *tid; // @synthesize tid=_tid;
@property(retain, nonatomic) NSString *bid; // @synthesize bid=_bid;
@property(retain, nonatomic) NSMutableArray *reportValueArr; // @synthesize reportValueArr=_reportValueArr;
- (void).cxx_destruct;
- (void)addStringValue:(id)arg1 withKey:(id)arg2;
- (void)addDoubleValue:(double)arg1 withKey:(id)arg2;
- (void)addUIntValue:(unsigned int)arg1 withKey:(id)arg2;
- (void)dealloc;
- (id)init;

@end
