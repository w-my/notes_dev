//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSString;

@interface UploadShakaPicReqInfo : JceObjectV2
{
    NSString *jcev2_p_0_r_imageData;
    NSString *jcev2_p_1_o_file_id;
    NSString *jcev2_p_2_o_check_key;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_check_key, setter=setJce_check_key:) NSString *jcev2_p_2_o_check_key; // @synthesize jcev2_p_2_o_check_key;
@property(retain, nonatomic, getter=jce_file_id, setter=setJce_file_id:) NSString *jcev2_p_1_o_file_id; // @synthesize jcev2_p_1_o_file_id;
@property(retain, nonatomic, getter=jce_imageData, setter=setJce_imageData:) NSString *jcev2_p_0_r_imageData; // @synthesize jcev2_p_0_r_imageData;
- (void).cxx_destruct;
- (id)init;

@end

