//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class stWealthInfo, stWealthRunRecord;

@interface stReportGainRsp : JceObjectV2
{
    stWealthInfo *jcev2_p_0_o_left_wealth;
    stWealthRunRecord *jcev2_p_1_o_record;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_record, setter=setJce_record:) stWealthRunRecord *jcev2_p_1_o_record; // @synthesize jcev2_p_1_o_record;
@property(retain, nonatomic, getter=jce_left_wealth, setter=setJce_left_wealth:) stWealthInfo *jcev2_p_0_o_left_wealth; // @synthesize jcev2_p_0_o_left_wealth;
- (void).cxx_destruct;
- (id)init;

@end

