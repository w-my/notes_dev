//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

@class NSString, NSURL, UIImage;

@interface QNShareCardModel : QNBaseModelObject
{
    NSString *_avatarUrl;
    NSString *_userName;
    unsigned long long _userType;
    NSString *_vipDesc;
    UIImage *_vipIcon;
    NSURL *_vipIconUrl;
    NSString *_fansCount;
    NSString *_starCount;
    NSString *_pageCount;
    UIImage *_qrcodeImage;
}

+ (id)p_loadUserItem:(id)arg1 completion:(CDUnknownBlockType)arg2;
+ (id)placeholderCardModelAndLoadCardModelCompletion:(CDUnknownBlockType)arg1;
+ (id)modelWithUserItem:(id)arg1;
@property(retain, nonatomic) UIImage *qrcodeImage; // @synthesize qrcodeImage=_qrcodeImage;
@property(copy, nonatomic) NSString *pageCount; // @synthesize pageCount=_pageCount;
@property(copy, nonatomic) NSString *starCount; // @synthesize starCount=_starCount;
@property(copy, nonatomic) NSString *fansCount; // @synthesize fansCount=_fansCount;
@property(retain, nonatomic) NSURL *vipIconUrl; // @synthesize vipIconUrl=_vipIconUrl;
@property(retain, nonatomic) UIImage *vipIcon; // @synthesize vipIcon=_vipIcon;
@property(copy, nonatomic) NSString *vipDesc; // @synthesize vipDesc=_vipDesc;
@property(nonatomic) unsigned long long userType; // @synthesize userType=_userType;
@property(copy, nonatomic) NSString *userName; // @synthesize userName=_userName;
@property(copy, nonatomic) NSString *avatarUrl; // @synthesize avatarUrl=_avatarUrl;
- (void).cxx_destruct;
@property(readonly, nonatomic) _Bool isLoadCompleted; // @dynamic isLoadCompleted;

@end

