//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSString;

@interface stPersonUpdateInfo : JceObjectV2
{
    int jcev2_p_0_o_flag;
    int jcev2_p_2_o_num;
    NSString *jcev2_p_1_o_tip;
}

+ (id)jceType;
+ (void)initialize;
@property(nonatomic, getter=jce_num, setter=setJce_num:) int jcev2_p_2_o_num; // @synthesize jcev2_p_2_o_num;
@property(retain, nonatomic, getter=jce_tip, setter=setJce_tip:) NSString *jcev2_p_1_o_tip; // @synthesize jcev2_p_1_o_tip;
@property(nonatomic, getter=jce_flag, setter=setJce_flag:) int jcev2_p_0_o_flag; // @synthesize jcev2_p_0_o_flag;
- (void).cxx_destruct;
- (id)init;

@end

