//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QSPaymentExchangeKbData;

@interface QSPaymentCenter : NSObject
{
    long long _kbCount;
    long long _diamondCount;
    long long _diamond2KbRate;
    QSPaymentExchangeKbData *_exchangeData;
}

+ (id)sharedInstance;
@property(retain, nonatomic) QSPaymentExchangeKbData *exchangeData; // @synthesize exchangeData=_exchangeData;
@property(nonatomic) long long diamond2KbRate; // @synthesize diamond2KbRate=_diamond2KbRate;
@property(nonatomic) long long diamondCount; // @synthesize diamondCount=_diamondCount;
@property(nonatomic) long long kbCount; // @synthesize kbCount=_kbCount;
- (void).cxx_destruct;
- (void)exchangeKCoin:(long long)arg1 title:(id)arg2 subtitleSuffix:(id)arg3 completion:(CDUnknownBlockType)arg4;
- (void)loginStatusChanged:(id)arg1;
- (void)dealloc;
- (id)init;

@end
