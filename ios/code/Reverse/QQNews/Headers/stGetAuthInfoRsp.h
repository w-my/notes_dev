//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class stAuth;

@interface stGetAuthInfoRsp : JceObjectV2
{
    stAuth *jcev2_p_0_o_authInfo;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_authInfo, setter=setJce_authInfo:) stAuth *jcev2_p_0_o_authInfo; // @synthesize jcev2_p_0_o_authInfo;
- (void).cxx_destruct;
- (id)init;

@end

