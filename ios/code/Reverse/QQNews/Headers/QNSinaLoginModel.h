//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface QNSinaLoginModel : NSObject
{
    NSString *_accessAocken;
    NSString *_userID;
    NSString *_profileImageUrl;
    NSString *_name;
}

@property(retain, nonatomic) NSString *name; // @synthesize name=_name;
@property(retain, nonatomic) NSString *profileImageUrl; // @synthesize profileImageUrl=_profileImageUrl;
@property(retain, nonatomic) NSString *userID; // @synthesize userID=_userID;
@property(retain, nonatomic) NSString *accessAocken; // @synthesize accessAocken=_accessAocken;
- (void).cxx_destruct;
- (id)getCookies;
- (_Bool)isValid;
- (id)getCookieHeader;

@end
