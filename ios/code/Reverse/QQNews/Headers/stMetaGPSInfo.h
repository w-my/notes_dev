//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@interface stMetaGPSInfo : JceObjectV2
{
    int jcev2_p_0_o_type;
    float jcev2_p_1_o_latitude;
    float jcev2_p_2_o_longitude;
    float jcev2_p_3_o_altitude;
}

+ (id)jceType;
+ (void)initialize;
@property(nonatomic, getter=jce_altitude, setter=setJce_altitude:) float jcev2_p_3_o_altitude; // @synthesize jcev2_p_3_o_altitude;
@property(nonatomic, getter=jce_longitude, setter=setJce_longitude:) float jcev2_p_2_o_longitude; // @synthesize jcev2_p_2_o_longitude;
@property(nonatomic, getter=jce_latitude, setter=setJce_latitude:) float jcev2_p_1_o_latitude; // @synthesize jcev2_p_1_o_latitude;
@property(nonatomic, getter=jce_type, setter=setJce_type:) int jcev2_p_0_o_type; // @synthesize jcev2_p_0_o_type;
- (id)init;

@end

