//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSString;

@interface stGetMaterialDetailReq : JceObjectV2
{
    int jcev2_p_2_o_request_type;
    NSString *jcev2_p_0_o_material_id;
    NSString *jcev2_p_1_o_attach_info;
}

+ (id)jceType;
+ (void)initialize;
@property(nonatomic, getter=jce_request_type, setter=setJce_request_type:) int jcev2_p_2_o_request_type; // @synthesize jcev2_p_2_o_request_type;
@property(retain, nonatomic, getter=jce_attach_info, setter=setJce_attach_info:) NSString *jcev2_p_1_o_attach_info; // @synthesize jcev2_p_1_o_attach_info;
@property(retain, nonatomic, getter=jce_material_id, setter=setJce_material_id:) NSString *jcev2_p_0_o_material_id; // @synthesize jcev2_p_0_o_material_id;
- (void).cxx_destruct;
- (id)init;

@end
