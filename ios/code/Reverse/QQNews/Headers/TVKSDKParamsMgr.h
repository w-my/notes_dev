//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, TVKUserInfo;

@interface TVKSDKParamsMgr : NSObject
{
    _Bool _isExternalGuid;
    _Bool _disableQualityReport;
    TVKUserInfo *_userInfo;
    NSString *_platform;
    NSString *_sdtfrom;
    NSString *_adChannelId;
    NSString *_playerChannelId;
    NSString *_productChannelId;
    NSString *_playerConfigId;
    NSString *_uid;
    NSString *_flowId;
    NSString *_guid;
}

+ (id)sharedInstance;
@property(copy, nonatomic) NSString *guid; // @synthesize guid=_guid;
@property(nonatomic) _Bool disableQualityReport; // @synthesize disableQualityReport=_disableQualityReport;
@property(retain, nonatomic) NSString *flowId; // @synthesize flowId=_flowId;
@property(retain, nonatomic) NSString *uid; // @synthesize uid=_uid;
@property(nonatomic) _Bool isExternalGuid; // @synthesize isExternalGuid=_isExternalGuid;
@property(copy, nonatomic) NSString *playerConfigId; // @synthesize playerConfigId=_playerConfigId;
@property(copy, nonatomic) NSString *productChannelId; // @synthesize productChannelId=_productChannelId;
@property(copy, nonatomic) NSString *playerChannelId; // @synthesize playerChannelId=_playerChannelId;
@property(copy, nonatomic) NSString *adChannelId; // @synthesize adChannelId=_adChannelId;
@property(copy, nonatomic) NSString *sdtfrom; // @synthesize sdtfrom=_sdtfrom;
@property(copy, nonatomic) NSString *platform; // @synthesize platform=_platform;
@property(retain) TVKUserInfo *userInfo; // @synthesize userInfo=_userInfo;
- (void).cxx_destruct;
@property(readonly, nonatomic) NSString *userAgent;
- (void)setGuid:(id)arg1 external:(_Bool)arg2;

@end
