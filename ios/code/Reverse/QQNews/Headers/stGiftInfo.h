//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class stMetaPerson;

@interface stGiftInfo : JceObjectV2
{
    int jcev2_p_1_o_num;
    stMetaPerson *jcev2_p_0_o_sender;
}

+ (id)jceType;
+ (void)initialize;
@property(nonatomic, getter=jce_num, setter=setJce_num:) int jcev2_p_1_o_num; // @synthesize jcev2_p_1_o_num;
@property(retain, nonatomic, getter=jce_sender, setter=setJce_sender:) stMetaPerson *jcev2_p_0_o_sender; // @synthesize jcev2_p_0_o_sender;
- (void).cxx_destruct;
- (id)init;

@end
