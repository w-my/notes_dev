//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSMatchLiveBasePropsMessageItem.h"

@class NSString, QSMatchLivePropsMessageLinkItem;

@interface QSMatchLiveAdPropsMessageItem : QSMatchLiveBasePropsMessageItem
{
    NSString *_logo;
    NSString *_adword1;
    NSString *_adword2;
    NSString *_pic;
    QSMatchLivePropsMessageLinkItem *_param;
}

@property(retain, nonatomic) QSMatchLivePropsMessageLinkItem *param; // @synthesize param=_param;
@property(copy, nonatomic) NSString *pic; // @synthesize pic=_pic;
@property(copy, nonatomic) NSString *adword2; // @synthesize adword2=_adword2;
@property(copy, nonatomic) NSString *adword1; // @synthesize adword1=_adword1;
@property(copy, nonatomic) NSString *logo; // @synthesize logo=_logo;
- (void).cxx_destruct;

@end

