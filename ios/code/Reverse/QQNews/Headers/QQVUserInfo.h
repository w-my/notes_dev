//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSNumber, NSString;

@interface QQVUserInfo : NSObject
{
    NSString *_skey;
    NSNumber *_uin;
    NSString *_openId;
}

+ (id)buildCookieStringWithOpenId:(id)arg1 accessToken:(id)arg2 appId:(id)arg3 mainLogin:(id)arg4;
@property(retain, nonatomic) NSString *openId; // @synthesize openId=_openId;
@property(retain, nonatomic) NSNumber *uin; // @synthesize uin=_uin;
@property(retain, nonatomic) NSString *skey; // @synthesize skey=_skey;
- (void).cxx_destruct;
- (_Bool)isValid;

@end

