//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSDate, NSString;

@interface QNWeixinLoginModel : NSObject
{
    _Bool _isKeychainData;
    NSString *_accessToken;
    NSString *_refreshToken;
    NSString *_openID;
    NSDate *_accessTokenExpireDate;
    NSString *_nickName;
    NSString *_nickIco;
    NSString *_unionID;
    long long _sex;
}

@property(nonatomic) _Bool isKeychainData; // @synthesize isKeychainData=_isKeychainData;
@property(nonatomic) long long sex; // @synthesize sex=_sex;
@property(copy, nonatomic) NSString *unionID; // @synthesize unionID=_unionID;
@property(copy, nonatomic) NSString *nickIco; // @synthesize nickIco=_nickIco;
@property(copy, nonatomic) NSString *nickName; // @synthesize nickName=_nickName;
@property(retain, nonatomic) NSDate *accessTokenExpireDate; // @synthesize accessTokenExpireDate=_accessTokenExpireDate;
@property(copy, nonatomic) NSString *openID; // @synthesize openID=_openID;
@property(copy, nonatomic) NSString *refreshToken; // @synthesize refreshToken=_refreshToken;
@property(copy, nonatomic) NSString *accessToken; // @synthesize accessToken=_accessToken;
- (void).cxx_destruct;
- (id)getCookies;
- (_Bool)authInfoIsValid;
- (id)getCookieHeader;

@end

