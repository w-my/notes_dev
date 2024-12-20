//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSString, QNMyMessageModel, UIImage;

@interface QNUserCenterCellEntity : QNBaseModelObject <NSCopying, NSCoding>
{
    _Bool _hasExposure;
    NSString *_entryType;
    NSString *_entryWeight;
    NSString *_switchType;
    NSString *_switchTitle;
    NSString *_h5Url;
    NSString *_switchDesc;
    NSString *_switchIconDay;
    NSString *_switchIconNight;
    NSString *_h5NeedLogin;
    NSString *_entityId;
    NSString *_h5SupportShare;
    NSString *_dynamicEntryType;
    NSString *_isWebCell;
    NSString *_upVer;
    UIImage *_localIconDay;
    UIImage *_localIconNight;
    QNMyMessageModel *_messageItem;
    unsigned long long _routeType;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(nonatomic) _Bool hasExposure; // @synthesize hasExposure=_hasExposure;
@property(nonatomic) unsigned long long routeType; // @synthesize routeType=_routeType;
@property(retain, nonatomic) QNMyMessageModel *messageItem; // @synthesize messageItem=_messageItem;
@property(retain, nonatomic) UIImage *localIconNight; // @synthesize localIconNight=_localIconNight;
@property(retain, nonatomic) UIImage *localIconDay; // @synthesize localIconDay=_localIconDay;
@property(copy, nonatomic) NSString *upVer; // @synthesize upVer=_upVer;
@property(copy, nonatomic) NSString *isWebCell; // @synthesize isWebCell=_isWebCell;
@property(copy, nonatomic) NSString *dynamicEntryType; // @synthesize dynamicEntryType=_dynamicEntryType;
@property(copy, nonatomic) NSString *h5SupportShare; // @synthesize h5SupportShare=_h5SupportShare;
@property(copy, nonatomic) NSString *entityId; // @synthesize entityId=_entityId;
@property(copy, nonatomic) NSString *h5NeedLogin; // @synthesize h5NeedLogin=_h5NeedLogin;
@property(copy, nonatomic) NSString *switchIconNight; // @synthesize switchIconNight=_switchIconNight;
@property(copy, nonatomic) NSString *switchIconDay; // @synthesize switchIconDay=_switchIconDay;
@property(copy, nonatomic) NSString *switchDesc; // @synthesize switchDesc=_switchDesc;
@property(copy, nonatomic) NSString *h5Url; // @synthesize h5Url=_h5Url;
@property(copy, nonatomic) NSString *switchTitle; // @synthesize switchTitle=_switchTitle;
@property(copy, nonatomic) NSString *switchType; // @synthesize switchType=_switchType;
@property(copy, nonatomic) NSString *entryWeight; // @synthesize entryWeight=_entryWeight;
@property(copy, nonatomic) NSString *entryType; // @synthesize entryType=_entryType;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (_Bool)isValid;
- (_Bool)hasNativeRouter;
- (unsigned long long)showBadgeRemindCount;
- (_Bool)needShowRedDotRemind;

@end

