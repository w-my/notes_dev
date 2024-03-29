//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSString, QSSportsMediaCameraHostInfo;

@interface QSSportsMediaCameraItem : QSModel
{
    _Bool _isVip;
    _Bool _isMain;
    _Bool _engSwitch;
    _Bool _isCurrentEnglish;
    _Bool _isFullView;
    _Bool _hasFullViewIcon;
    long long _type;
    NSString *_liveId;
    NSString *_title;
    NSString *_playerTitle;
    NSString *_engLiveId;
    QSSportsMediaCameraHostInfo *_hostInfo;
}

@property(nonatomic) _Bool hasFullViewIcon; // @synthesize hasFullViewIcon=_hasFullViewIcon;
@property(nonatomic) _Bool isFullView; // @synthesize isFullView=_isFullView;
@property(retain, nonatomic) QSSportsMediaCameraHostInfo *hostInfo; // @synthesize hostInfo=_hostInfo;
@property(nonatomic) _Bool isCurrentEnglish; // @synthesize isCurrentEnglish=_isCurrentEnglish;
@property(copy, nonatomic) NSString *engLiveId; // @synthesize engLiveId=_engLiveId;
@property(nonatomic) _Bool engSwitch; // @synthesize engSwitch=_engSwitch;
@property(nonatomic) _Bool isMain; // @synthesize isMain=_isMain;
@property(nonatomic) _Bool isVip; // @synthesize isVip=_isVip;
@property(copy, nonatomic) NSString *playerTitle; // @synthesize playerTitle=_playerTitle;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(copy, nonatomic) NSString *liveId; // @synthesize liveId=_liveId;
@property(nonatomic) long long type; // @synthesize type=_type;
- (void).cxx_destruct;
- (_Bool)isEqual:(id)arg1;

@end

