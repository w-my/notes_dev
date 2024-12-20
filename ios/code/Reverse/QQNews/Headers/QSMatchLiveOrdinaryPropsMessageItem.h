//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSMatchLiveBasePropsMessageItem.h"

@class NSString;

@interface QSMatchLiveOrdinaryPropsMessageItem : QSMatchLiveBasePropsMessageItem
{
    NSString *_userid;
    NSString *_userNick;
    NSString *_userIcon;
    NSString *_propsid;
    NSString *_propsName;
    NSString *_propsIcon;
    NSString *_propsGifIcon;
    long long _buyNum;
    unsigned long long _hitBeginNum;
    NSString *_rank;
    NSString *_rankName;
    NSString *_targetCode;
    NSString *_targetName;
}

+ (id)propertyNameFromParsedKey:(id)arg1;
@property(copy, nonatomic) NSString *targetName; // @synthesize targetName=_targetName;
@property(copy, nonatomic) NSString *targetCode; // @synthesize targetCode=_targetCode;
@property(copy, nonatomic) NSString *rankName; // @synthesize rankName=_rankName;
@property(copy, nonatomic) NSString *rank; // @synthesize rank=_rank;
@property(nonatomic) unsigned long long hitBeginNum; // @synthesize hitBeginNum=_hitBeginNum;
@property(nonatomic) long long buyNum; // @synthesize buyNum=_buyNum;
@property(copy, nonatomic) NSString *propsGifIcon; // @synthesize propsGifIcon=_propsGifIcon;
@property(copy, nonatomic) NSString *propsIcon; // @synthesize propsIcon=_propsIcon;
@property(copy, nonatomic) NSString *propsName; // @synthesize propsName=_propsName;
@property(copy, nonatomic) NSString *propsid; // @synthesize propsid=_propsid;
@property(copy, nonatomic) NSString *userIcon; // @synthesize userIcon=_userIcon;
@property(copy, nonatomic) NSString *userNick; // @synthesize userNick=_userNick;
@property(copy, nonatomic) NSString *userid; // @synthesize userid=_userid;
- (void).cxx_destruct;

@end

