//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSString;

@interface stMetaSevenLoginNewUserItem : JceObjectV2
{
    int jcev2_p_0_o_loginstep;
    unsigned int jcev2_p_1_o_loginTimeStamp;
    NSString *jcev2_p_2_o_entrance;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_entrance, setter=setJce_entrance:) NSString *jcev2_p_2_o_entrance; // @synthesize jcev2_p_2_o_entrance;
@property(nonatomic, getter=jce_loginTimeStamp, setter=setJce_loginTimeStamp:) unsigned int jcev2_p_1_o_loginTimeStamp; // @synthesize jcev2_p_1_o_loginTimeStamp;
@property(nonatomic, getter=jce_loginstep, setter=setJce_loginstep:) int jcev2_p_0_o_loginstep; // @synthesize jcev2_p_0_o_loginstep;
- (void).cxx_destruct;
- (id)init;

@end
