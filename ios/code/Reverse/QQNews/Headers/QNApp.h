//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"

@class NSData, NSString;

@interface QNApp : NSObject <NSCoding>
{
    NSString *_appName;
    NSString *_appUrl;
    NSString *_appDesc;
    NSString *_iconUrl;
    NSString *_appSize;
    NSString *_version;
    NSString *_appID;
    NSString *_realID;
    NSData *_icon;
}

@property(copy, nonatomic) NSData *icon; // @synthesize icon=_icon;
@property(copy, nonatomic) NSString *realID; // @synthesize realID=_realID;
@property(copy, nonatomic) NSString *appID; // @synthesize appID=_appID;
@property(copy, nonatomic) NSString *version; // @synthesize version=_version;
@property(copy, nonatomic) NSString *appSize; // @synthesize appSize=_appSize;
@property(copy, nonatomic) NSString *iconUrl; // @synthesize iconUrl=_iconUrl;
@property(copy, nonatomic) NSString *appDesc; // @synthesize appDesc=_appDesc;
@property(copy, nonatomic) NSString *appUrl; // @synthesize appUrl=_appUrl;
@property(copy, nonatomic) NSString *appName; // @synthesize appName=_appName;
- (void).cxx_destruct;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;

@end

