//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSStatedData.h"

@class NSString, QSMatchLivePropsBuyItem, QSMatchLivePropsListItem;

@interface QSMatchLivePropsBuyData : QSStatedData
{
    _Bool _isHitEnd;
    _Bool _isFirstBuy;
    _Bool _fullscreen;
    int _totalHits;
    NSString *_orderid;
    NSString *_mid;
    QSMatchLivePropsListItem *_propsItem;
}

+ (id)errorDescOfError:(id)arg1;
@property(nonatomic) _Bool fullscreen; // @synthesize fullscreen=_fullscreen;
@property(nonatomic) _Bool isFirstBuy; // @synthesize isFirstBuy=_isFirstBuy;
@property(nonatomic) int totalHits; // @synthesize totalHits=_totalHits;
@property(nonatomic) _Bool isHitEnd; // @synthesize isHitEnd=_isHitEnd;
@property(retain, nonatomic) QSMatchLivePropsListItem *propsItem; // @synthesize propsItem=_propsItem;
@property(copy, nonatomic) NSString *mid; // @synthesize mid=_mid;
@property(copy, nonatomic) NSString *orderid; // @synthesize orderid=_orderid;
- (void).cxx_destruct;
- (void)saveToFile;
@property(readonly, nonatomic) QSMatchLivePropsBuyItem *buyItem; // @dynamic buyItem;
- (void)resetWithResponseModel:(id)arg1;
- (id)httpURLComponents;
- (double)cacheExpireTime;

@end

