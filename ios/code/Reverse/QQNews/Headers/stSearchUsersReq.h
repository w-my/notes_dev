//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSString;

@interface stSearchUsersReq : JceObjectV2
{
    NSString *jcev2_p_0_r_search_query;
    NSString *jcev2_p_1_r_attach_info;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_attach_info, setter=setJce_attach_info:) NSString *jcev2_p_1_r_attach_info; // @synthesize jcev2_p_1_r_attach_info;
@property(retain, nonatomic, getter=jce_search_query, setter=setJce_search_query:) NSString *jcev2_p_0_r_search_query; // @synthesize jcev2_p_0_r_search_query;
- (void).cxx_destruct;
- (id)init;

@end

