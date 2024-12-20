//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSString, QSMatchAdItem, QSMatchItem, QSMatchRoseShareItem;

@interface QSEntranceMatchItem : QSModel
{
    _Bool _isPay;
    NSString *_liveId;
    QSMatchRoseShareItem *_roseShareItem;
    NSString *_matchDescEx;
    QSMatchItem *_matchInfo;
    QSMatchAdItem *_ad;
    NSString *_isVip;
    NSString *_vipUrl;
    NSString *_leftBg;
    NSString *_leftBgNight;
    NSString *_rightBg;
    NSString *_rightBgNight;
}

@property(retain, nonatomic) NSString *rightBgNight; // @synthesize rightBgNight=_rightBgNight;
@property(retain, nonatomic) NSString *rightBg; // @synthesize rightBg=_rightBg;
@property(retain, nonatomic) NSString *leftBgNight; // @synthesize leftBgNight=_leftBgNight;
@property(retain, nonatomic) NSString *leftBg; // @synthesize leftBg=_leftBg;
@property(nonatomic) _Bool isPay; // @synthesize isPay=_isPay;
@property(retain, nonatomic) NSString *vipUrl; // @synthesize vipUrl=_vipUrl;
@property(retain, nonatomic) NSString *isVip; // @synthesize isVip=_isVip;
@property(retain, nonatomic) QSMatchAdItem *ad; // @synthesize ad=_ad;
@property(retain, nonatomic) QSMatchItem *matchInfo; // @synthesize matchInfo=_matchInfo;
@property(copy, nonatomic) NSString *matchDescEx; // @synthesize matchDescEx=_matchDescEx;
@property(retain, nonatomic) QSMatchRoseShareItem *roseShareItem; // @synthesize roseShareItem=_roseShareItem;
@property(retain, nonatomic) NSString *liveId; // @synthesize liveId=_liveId;
- (void).cxx_destruct;
- (_Bool)manualSetValue:(id)arg1 forKey:(id)arg2;

@end

